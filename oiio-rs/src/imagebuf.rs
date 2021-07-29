use crate::cppstd::CppString;
use crate::error::Error;
use crate::filesystem::IOProxy;
use crate::imagecache::ImageCache;
use crate::imageio::{
    get_trampoline, ImageOutputOpened, ImageSpec, ImageSpecRef,
    ProgressCallback, Roi, Stride, Strides
};
use crate::typedesc::TypeDesc;

use crate::string_view::StringView;
use crate::traits::Pixel;

use oiio_sys as sys;

use std::os::raw::c_void;
use std::path::Path;

type Result<T, E = Error> = std::result::Result<T, E>;

/// An ImageBuf is a simple in-memory representation of a 2D image.  It uses
/// ImageInput and ImageOutput underneath for its file I/O, and has simple
/// routines for setting and getting individual pixels, that hides most of
/// the details of memory layout and data representation (translating
/// to/from float automatically).
///
/// ImageBuf makes an important simplification: all channels are just one
/// data type. For example, if an image file on disk has a mix of `half` and
/// `float` channels, the in-memory ImageBuf representation will be entirely
/// `float` (for mixed data types, it will try to pick one that can best
/// represent all channels without a loss of precision or range). However,
/// by using the `set_write_format()` method, it is still possible to write
/// an ImageBuf to a file with mixed channel types.
///
/// Most of the time, ImageBuf data is read lazily (I/O only happens when
/// you first call methods that actually need metadata or pixel data).
/// Explicit calls to `read()` are therefore optional and are only needed
/// if you want to specify non-default arguments (such as choosing something
/// other than the first subimage of the file, or forcing the read to
/// translate into a different data format than appears in the file).
///
/// ImageBuf data coming from disk files is backed by ImageCache. That is,
/// especially for tiled files, specific regions of the image will only
/// be read if and when they are needed, and if there are many large
/// ImageBuf's, memory holding pixels not recently accesssed will be
/// automatically freed. Thus, performance of ImageBuf on very large images
/// (or if there are many ImageBuf's simultaneously in use) can be sensitive
/// to choices of the ImageCache parameters such as "autotile". It may be
/// wise for maximum performance to explicitly `read()` (with `force=true`)
/// small images into memory rather than using the ImageCache, in cases
/// where your application has no need for the ImageCache features that
/// limit memory footprint (such as if you know for sure that your app will
/// only read a small number of images, of reasonable size, and will need
/// to access all the pixels of all the images it reads).
///
/// Writeable ImageBufs are always stored entirely in memory, and do not use
/// the ImageCache or any other clever schemes to limit memory. If you have
/// enough simultaneous writeable large ImageBuf's, you can run out of RAM.
/// Note that if an ImageBuf starts as readable (backed by ImageCache), any
/// alterations to its pixels (for example, via `setpixel()` or traversing
/// it with a non-const `Iterator`) will cause it to be read entirely into
/// memory and remain in memory thereafter for the rest of the life of that
/// ImageBuf.
///
/// Notes about ImageBuf thread safety:
///
/// * The various read-only methods for accessing the spec or the pixels,
///   including `init_spec()`, `read()`, `spec()`, all the getpixel flavors
///   and `ConstIterator` over the pixels, and other informational methods
///   such as `roi()`, all are thread-safe and may be called concurrently
///   with any of the other thread-safe methods.
/// * Methods that alter pixel values, such as all the setpixel flavors,
///   and (non-const) `Iterator` over the pixels, and the `write()` method
///   are "thread safe" in the sense that you won't crash your app by doing
///   these concurrently with each other or with the reading functionality,
///   but on the other hand, if two threads are changing the same pixels
///   simultaneously or one is writing while others are reading, you may end
///   up with an inconsistent resulting image.
/// * Construction and destruction, `reset()`, and anything that alters
///   image metadata (such as writes through `specmod()`) are NOT THREAD
///   SAFE and you should ensure that you are not doing any of these calls
///   simultaneously with any other operations on the same ImageBuf.
///
#[repr(transparent)]
pub struct ImageBuf {
    pub(crate) ptr: *mut sys::OIIO_ImageBuf_t,
}

/// Describes the backing storage for an [`ImageBuf`]
#[derive(Debug, Copy, Clone, PartialEq, PartialOrd)]
pub enum Storage {
    /// The ImageBuf hasn't been initialized yet so there is no storage
    Uninitialized,
    /// The ImageBuf has allocated and owns the memory
    LocalBuffer,
    /// The ImageBuf is wrapping a user-provided storage buffer
    AppBuffer,
    /// The ImageBuf is backed by an ImageCache
    ImageCache,
}

impl From<sys::OIIO_ImageBuf_IBStorage> for Storage {
    fn from(s: sys::OIIO_ImageBuf_IBStorage) -> Storage {
        match s {
            sys::OIIO_ImageBuf_IBStorage_UNINITIALIZED => {
                Storage::Uninitialized
            }
            sys::OIIO_ImageBuf_IBStorage_LOCALBUFFER => Storage::LocalBuffer,
            sys::OIIO_ImageBuf_IBStorage_APPBUFFER => Storage::AppBuffer,
            sys::OIIO_ImageBuf_IBStorage_IMAGECACHE => Storage::ImageCache,
            _ => panic!("bad value '{}' converting IBStorage", s.0),
        }
    }
}

impl ImageBuf {
    //! # Constructors

    /// Return the text of all pending error messages issued against this
    /// ImageBuf by the calling thread, and clear the pending error
    /// message unless `clear` is false. If no error message is pending, it
    /// will return an empty string.
    ///
    pub fn get_error(&self, clear: bool) -> String {
        let mut msg = CppString::new("");
        unsafe {
            sys::OIIO_ImageBuf_geterror(self.ptr, &mut msg.0, clear);
            msg.as_str().to_string()
        }
    }

    /// Construct a read-only ImageBuf that will be used to read the named
    /// file (at the given subimage and MIP-level, defaulting to the first
    /// in the file).  But don't read it yet!  The image will actually be
    /// read lazily, only when other methods need to access the spec and/or
    /// pixels, or when an explicit call to `init_spec()` or `read()` is
    /// made, whichever comes first.
    ///
    /// The implementation may end up either reading the entire image
    /// internally owned memory (if so, the storage will be `LOCALBUFFER`),
    /// or it may rely on being backed by an ImageCache (in this case, the
    /// storage will be `IMAGECACHE`) -- depending on the image size and
    /// other factors.
    ///
    pub fn open<P: AsRef<Path>>(
        name: P,
        subimage: i32,
        miplevel: i32,
        imagecache: Option<&ImageCache>,
        config: Option<&ImageSpec>,
        ioproxy: Option<&IOProxy>,
    ) -> Result<ImageBuf> {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageBuf_ctor(
                &mut ptr,
                StringView::from(
                    name.as_ref()
                        .to_str()
                        .expect("could not convert name path to string"),
                )
                .into(),
                subimage,
                miplevel,
                if let Some(ic) = imagecache {
                    ic.0
                } else {
                    std::ptr::null_mut()
                },
                if let Some(s) = config {
                    s.0
                } else {
                    std::ptr::null_mut()
                },
                if let Some(p) = ioproxy {
                    p.0
                } else {
                    std::ptr::null_mut()
                },
            );

            let mut has_error = false;
            sys::OIIO_ImageBuf_has_error(ptr, &mut has_error);
            let mut s_ptr = std::ptr::null_mut();
            sys::OIIO_ImageBuf_geterror(ptr, &mut s_ptr, true);
            if has_error {
                Err(Error::Oiio(CppString(s_ptr).as_str().to_string()))
            } else {
                Ok(ImageBuf { ptr })
            }
        }
    }

    /// Construct a writable ImageBuf with the given specification
    /// (including resolution, data type, metadata, etc.). The ImageBuf will
    /// allocate and own its own pixel memory and will free that memory
    /// automatically upon destruction, clear(), or reset().
    ///
    pub fn new_writable(
        spec: &ImageSpec,
        zero_initialize: bool,
    ) -> Result<ImageBuf> {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageBuf_ctor_initialized(
                &mut ptr,
                spec.0,
                if zero_initialize {
                    sys::OIIO_InitializePixels_Yes
                } else {
                    sys::OIIO_InitializePixels_No
                },
            );

            let mut has_error = false;
            sys::OIIO_ImageBuf_has_error(ptr, &mut has_error);
            let mut s_ptr = std::ptr::null_mut();
            sys::OIIO_ImageBuf_geterror(ptr, &mut s_ptr, true);
            if has_error {
                return Err(Error::Oiio(CppString(s_ptr).as_str().to_string()));
            }

            // If the buffer has storage UNINITIALIZED, then the spec wasn't
            // valid and this buffer is also invalid.
            let mut storage = sys::OIIO_ImageBuf_IBStorage_UNINITIALIZED;
            sys::OIIO_ImageBuf_storage(ptr, &mut storage);
            if storage == sys::OIIO_ImageBuf_IBStorage_UNINITIALIZED {
                return Err(Error::InvalidSpec);
            }

            Ok(ImageBuf { ptr })
        }
    }
}

impl ImageBuf {
    //! # Reading and writing disk images
    //!
    //! In general, the various `read()` methods will try not to do any I/O at the time of the
    //! `read()` call, but rather to have the ImageBuf "backed" by an
    //! ImageCache, which will do the file I/O on demand, as pixel values
    //! are needed, and in that case the ImageBuf doesn't actually allocate
    //! memory for the pixels (the data lives in the ImageCache).  However,
    //! there are several conditions for which the ImageCache will be
    //! bypassed, the ImageBuf will allocate "local" memory, and the disk
    //! file will be read directly into allocated buffer at the time of the
    //! `read()` call: (a) if the `force` parameter is `true`; (b) if the
    //! `convert` parameter requests a data format conversion to a type that
    //! is not the native file type and also is not one of the internal
    //! types supported by the ImageCache (specifically, `float` and
    //! `UINT8`); (c) if the ImageBuf already has local pixel memory
    //! allocated, or "wraps" an application buffer.
    //!
    //! Note that `read()` is not strictly necessary. If you are happy with
    //! the filename, subimage and MIP level specified by the ImageBuf
    //! constructor (or the last call to `reset()`), and you want the
    //! storage to be backed by the ImageCache (including storing the
    //! pixels in whatever data format that implies), then the file contents
    //! will be automatically read the first time you make any other
    //! ImageBuf API call that requires the spec or pixel values.  The only
    //! reason to call `read()` yourself is if you are changing the
    //! filename, subimage, or MIP level, or if you want to use `force =
    //! true` or a specific `convert` value to force data format conversion.

    /// Read the particular subimage and MIP level of the image.  Generally,
    /// this will skip the expensive read if the file has already been read
    /// into the ImageBuf (at the specified subimage and MIP level).  It
    /// will clear and re-allocate memory if the previously allocated space
    /// was not appropriate for the size or data type of the image being
    /// read.
    ///
    /// # Parameters
    /// * `subimage` - the subimage to read
    /// * `miplevel` - the mip level to read
    /// * `force` - if `true` will force an immediate read into memory. Otherwise,
    /// the implementation may decide whether to use the image cache (if one was
    /// provided to the constructor).
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if any error occurs
    ///
    pub fn read(
        &self,
        subimage: i32,
        miplevel: i32,
        force: bool,
        convert: Option<TypeDesc>,
    ) -> Result<()> {
        let mut result = false;
        unsafe {
            sys::OIIO_ImageBuf_read(
                self.ptr,
                &mut result,
                subimage,
                miplevel,
                force,
                if let Some(td) = convert {
                    td.into()
                } else {
                    TypeDesc::UNKNOWN.into()
                },
                std::mem::transmute::<*const (), ProgressCallback>(
                    std::ptr::null(),
                ),
                std::ptr::null_mut(),
            );
            if !result {
                let mut msg = CppString::new("");
                sys::OIIO_ImageBuf_geterror(self.ptr, &mut msg.0, true);
                return Err(Error::Oiio(msg.as_str().to_string()));
            }

            Ok(())
        }
    }

    /// Read the particular subimage and MIP level of the image.  Generally,
    /// this will skip the expensive read if the file has already been read
    /// into the ImageBuf (at the specified subimage and MIP level).  It
    /// will clear and re-allocate memory if the previously allocated space
    /// was not appropriate for the size or data type of the image being
    /// read.
    ///
    /// # Parameters
    /// * `subimage` - the subimage to read
    /// * `miplevel` - the mip level to read
    /// * `force` - if `true` will force an immediate read into memory. Otherwise,
    /// the implementation may decide whether to use the image cache (if one was
    /// provided to the constructor).
    /// * `progress_callback` - a closure that will be called to report progress
    /// in the range `[0, 1]`. Returning `true` from the closure stops the read
    /// operation.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if any error occurs
    ///
    pub fn read_image_with_progress<F>(
        &self,
        subimage: i32,
        miplevel: i32,
        force: bool,
        convert: Option<TypeDesc>,
        progress_callback: F,
    ) -> Result<()>
    where
        F: FnMut(f32) -> bool,
    {
        let mut result = false;
        let mut progress_callback = progress_callback;
        let trampoline = get_trampoline(&progress_callback);

        unsafe {
            sys::OIIO_ImageBuf_read(
                self.ptr,
                &mut result,
                subimage,
                miplevel,
                force,
                if let Some(td) = convert {
                    td.into()
                } else {
                    TypeDesc::UNKNOWN.into()
                },
                trampoline,
                &mut progress_callback as *mut _ as *mut c_void,
            );

            if !result {
                let mut msg = CppString::new("");
                sys::OIIO_ImageBuf_geterror(self.ptr, &mut msg.0, true);
                return Err(Error::Oiio(msg.as_str().to_string()));
            }

            Ok(())
        }
    }

    /// Read the particular subimage and MIP level of the image, reading only the channels in the
    /// range `[chbegin, chend)` if possible.
    ///
    /// Generally,
    /// this will skip the expensive read if the file has already been read
    /// into the ImageBuf (at the specified subimage and MIP level).  It
    /// will clear and re-allocate memory if the previously allocated space
    /// was not appropriate for the size or data type of the image being
    /// read.
    ///
    /// # Parameters
    /// * `subimage` - the subimage to read
    /// * `miplevel` - the mip level to read
    /// * `chbegin` - the first channel to read
    /// * `chend` - the last channel to read
    /// * `force` - if `true` will force an immediate read into memory. Otherwise,
    /// the implementation may decide whether to use the image cache (if one was
    /// provided to the constructor).
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if any error occurs
    ///
    pub fn read_channels(
        &self,
        subimage: i32,
        miplevel: i32,
        chbegin: i32,
        chend: i32,
        force: bool,
        convert: Option<TypeDesc>,
    ) -> Result<()> {
        let mut result = false;
        unsafe {
            sys::OIIO_ImageBuf_read_channels(
                self.ptr,
                &mut result,
                subimage,
                miplevel,
                chbegin,
                chend,
                force,
                if let Some(td) = convert {
                    td.into()
                } else {
                    TypeDesc::UNKNOWN.into()
                },
                std::mem::transmute::<*const (), ProgressCallback>(
                    std::ptr::null(),
                ),
                std::ptr::null_mut(),
            );
            if !result {
                let mut msg = CppString::new("");
                sys::OIIO_ImageBuf_geterror(self.ptr, &mut msg.0, true);
                return Err(Error::Oiio(msg.as_str().to_string()));
            }

            Ok(())
        }
    }

    /// Read the particular subimage and MIP level of the image, reading only the channels in the
    /// range `[chbegin, chend)` if possible.
    ///
    /// Generally,
    /// this will skip the expensive read if the file has already been read
    /// into the ImageBuf (at the specified subimage and MIP level).  It
    /// will clear and re-allocate memory if the previously allocated space
    /// was not appropriate for the size or data type of the image being
    /// read.
    ///
    /// # Parameters
    /// * `subimage` - the subimage to read
    /// * `miplevel` - the mip level to read
    /// * `chbegin` - the first channel to read
    /// * `chend` - the last channel to read
    /// * `force` - if `true` will force an immediate read into memory. Otherwise,
    /// the implementation may decide whether to use the image cache (if one was
    /// provided to the constructor).
    /// * `progress_callback` - a closure that will be called to report progress
    /// in the range `[0, 1]`. Returning `true` from the closure stops the read
    /// operation.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if any error occurs
    ///
    pub fn read_channels_with_progress<F>(
        &self,
        subimage: i32,
        miplevel: i32,
        chbegin: i32,
        chend: i32,
        force: bool,
        convert: Option<TypeDesc>,
        progress_callback: F,
    ) -> Result<()>
    where
        F: FnMut(f32) -> bool,
    {
        let mut result = false;
        let mut progress_callback = progress_callback;
        let trampoline = get_trampoline(&progress_callback);

        unsafe {
            sys::OIIO_ImageBuf_read_channels(
                self.ptr,
                &mut result,
                subimage,
                miplevel,
                chbegin,
                chend,
                force,
                if let Some(td) = convert {
                    td.into()
                } else {
                    TypeDesc::UNKNOWN.into()
                },
                trampoline,
                &mut progress_callback as *mut _ as *mut c_void,
            );

            if !result {
                let mut msg = CppString::new("");
                sys::OIIO_ImageBuf_geterror(self.ptr, &mut msg.0, true);
                return Err(Error::Oiio(msg.as_str().to_string()));
            }

            Ok(())
        }
    }

    /// Write the image to the named file.
    ///
    /// By default, it will always try to write a scanline-oriented file,
    /// unless the `set_write_tiles()` method has been used to override
    /// this.
    ///
    /// # Parameters
    /// * `dtype` - If provided will attempt to convert the image to the given data type when
    /// writing.
    /// * `file_format` - If provided will override the format to write to. If None, the format
    /// will be inferred from the filename extension.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if any error occurs.
    ///
    pub fn write<P: AsRef<Path>>(
        &mut self,
        filename: P,
        dtype: Option<TypeDesc>,
        file_format: Option<&str>,
    ) -> Result<()> {
        let sv_filename = StringView::from(
            filename
                .as_ref()
                .as_os_str()
                .to_str()
                .expect("filename string could not be converted"),
        );

        let sv_format = if let Some(format) = file_format {
            StringView::from(format)
        } else {
            StringView::from("")
        };

        let mut result = false;
        unsafe {
            sys::OIIO_ImageBuf_write(
                self.ptr,
                &mut result,
                sv_filename.0,
                if let Some(dt) = dtype {
                    dt.into()
                } else {
                    TypeDesc::UNKNOWN.into()
                },
                sv_format.0,
                std::mem::transmute::<*const (), ProgressCallback>(
                    std::ptr::null(),
                ),
                std::ptr::null_mut(),
            );
        }
        if !result {
            return Err(Error::Oiio(self.get_error(true)));
        }

        Ok(())
    }

    /// Write the image to the named file, with a progress callback.
    ///
    /// By default, it will always try to write a scanline-oriented file,
    /// unless the `set_write_tiles()` method has been used to override
    /// this.
    ///
    /// # Parameters
    /// * `dtype` - If provided will attempt to convert the image to the given data type when
    /// writing.
    /// * `file_format` - If provided will override the format to write to. If None, the format
    /// will be inferred from the filename extension.
    /// * `progress_callback` - a closure that will be called to report progress
    /// in the range `[0, 1]`. Returning `true` from the closure stops the read
    /// operation.
    ///
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if any error occurs.
    ///
    pub fn write_with_progress<P: AsRef<Path>, F>(
        &mut self,
        filename: P,
        dtype: Option<TypeDesc>,
        file_format: Option<&str>,
        progress_callback: F,
    ) -> Result<()>
    where
        F: FnMut(f32) -> bool,
    {
        let sv_filename = StringView::from(
            filename
                .as_ref()
                .as_os_str()
                .to_str()
                .expect("filename string could not be converted"),
        );

        let sv_format = if let Some(format) = file_format {
            StringView::from(format)
        } else {
            StringView::from("")
        };

        let mut progress_callback = progress_callback;
        let trampoline = get_trampoline(&progress_callback);

        let mut result = false;
        unsafe {
            sys::OIIO_ImageBuf_write(
                self.ptr,
                &mut result,
                sv_filename.0,
                if let Some(dt) = dtype {
                    dt.into()
                } else {
                    TypeDesc::UNKNOWN.into()
                },
                sv_format.0,
                trampoline,
                &mut progress_callback as *mut _ as *mut c_void,
            );
        }
        if !result {
            return Err(Error::Oiio(self.get_error(true)));
        }

        Ok(())
    }

    /// Write the pixels of the ImageBuf to an [`ImageOutputOpened`]. The
    /// ImageOutput must have already been opened with a spec that indicates
    /// a resolution identical to that of this ImageBuf (but it may have
    /// specified a different pixel data type, in which case data
    /// conversions will happen automatically). This method does NOT close
    /// the file when it's done (and so may be called in a loop to write a
    /// multi-image file).
    ///
    /// Note that since this uses an already-opened `ImageOutput`, which is
    /// too late to change how it was opened, it does not honor any prior
    /// calls to `set_write_format` or `set_write_tiles`.
    ///
    /// The main application of this method is to allow an ImageBuf (which
    /// by design may hold only a *single* image) to be used for the output
    /// of one image of a multi-subimage and/or MIP-mapped image file.
    ///
    pub fn write_to(&mut self, io: &mut ImageOutputOpened) -> Result<()> {
        let mut result = false;
        unsafe {
            sys::OIIO_ImageBuf_write_to_imageoutput(
                self.ptr,
                &mut result,
                io.ptr,
                std::mem::transmute::<*const (), ProgressCallback>(
                    std::ptr::null(),
                ),
                std::ptr::null_mut(),
            );
        }

        if !result {
            return Err(Error::Oiio(self.get_error(true)));
        }

        Ok(())
    }

    /// Set the pixel data format that will be used for subsequent `write()`
    /// calls that do not themselves request a specific data type request.
    ///
    /// Note that this does not affect the variety of `write()` that takes
    /// an open `ImageOutput*` as a parameter.
    ///
    pub fn set_write_format(&mut self, format: TypeDesc) {
        unsafe {
            sys::OIIO_ImageBuf_set_write_format(self.ptr, format.into());
        }
    }

    /// Set the per-channel pixel data format that will be used for
    /// subsequent `write()` calls that do not themselves request a specific
    /// data type request.
    ///
    /// # Parameters
    /// *`formats` - The type of each channel (in order). Any channel's
    /// format specified as [`TypeDesc::UNKNOWN`] will default to be
    /// whatever type is described in the ImageSpec of the
    /// buffer.
    ///
    pub fn set_channel_write_formats(&mut self, formats: &[TypeDesc]) {
        unsafe {
            let mut s = sys::OIIO_cspan_TypeDesc_t::default();
            sys::OIIO_cspan_TypeDesc_from_ptr(
                &mut s,
                formats.as_ptr() as *const sys::OIIO_TypeDesc_t,
                formats.len() as i64,
            );
            sys::OIIO_ImageBuf_set_write_format_per_channel(self.ptr, s);
        }
    }

    /// Override the tile sizing for subsequent calls to the `write()`
    /// method (the variety that does not take an open `ImageOutput*`).
    /// Setting all three dimensions to 0 indicates that the output should
    /// be a scanline-oriented file.
    ///
    /// This lets you write a tiled file from an ImageBuf that may have been
    /// read originally from a scanline file, or change the dimensions of a
    /// tiled file, or to force the file written to be scanline even if it
    /// was originally read from a tiled file.
    ///
    /// In all cases, if the file format ultimately written does not support
    /// tiling, or the tile dimensions requested, a suitable supported
    /// tiling choice will be made automatically.
    ///
    pub fn set_write_tiles(&mut self, width: i32, height: i32, depth: i32) {
        unsafe {
            sys::OIIO_ImageBuf_set_write_tiles(self.ptr, width, height, depth);
        }
    }

    /// Supply an IOProxy to use for a subsequent call to `write()`.
    ///
    /// If a proxy is set but it later turns out that the file format
    /// selected does not support write proxies, then `write()` will fail
    /// with an error.
    ///
    pub fn set_write_proxy(&mut self, ioproxy: IOProxy) {
        unsafe {
            sys::OIIO_ImageBuf_set_write_ioproxy(self.ptr, ioproxy.0);
        }
    }
}

impl ImageBuf {
    //! # Copying

    /// Copy all the metadata from `src` to `self` (except for pixel data
    /// resolution, channel types and names, and data format).
    ///
    pub fn copy_metadata(&mut self, src: &ImageBuf) {
        unsafe {
            sys::OIIO_ImageBuf_copy_metadata(self.ptr, src.ptr);
        }
    }

    /// Copy the pixel data from `src` to `self`, automatically converting
    /// to the existing data format of `self`.  It only copies pixels in
    /// the overlap regions (and channels) of the two images; pixel data in
    /// `self` that do exist in `src` will be set to 0, and pixel data in
    /// `src` that do not exist in `self` will not be copied.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if any error occurs
    ///
    pub fn copy_pixels(&mut self, src: &ImageBuf) -> Result<()> {
        let mut result = false;
        unsafe {
            sys::OIIO_ImageBuf_copy_pixels(self.ptr, &mut result, src.ptr);
        }

        if !result {
            return Err(Error::Oiio(self.get_error(true)));
        }

        Ok(())
    }

    /// Return a clone of this ImageBuf, converting the pixel type to `convert`
    ///
    pub fn clone_convert(&self, convert: TypeDesc) -> ImageBuf {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageBuf_clone(self.ptr, &mut ptr, convert.into());
        }

        ImageBuf { ptr }
    }
}

impl ImageBuf {
    //! # Getting and setting pixel values

    /// Retrieve a single channel of one pixel.
    ///
    /// Retrieves channel `c` of pixel with corrdinates `[x, y, z]` and returns
    /// its value as a f32. `mode` determines the behviour if the pixel coordinate
    /// outside the data window.
    ///
    pub fn get_channel(
        &self,
        x: i32,
        y: i32,
        z: i32,
        c: i32,
        mode: WrapMode,
    ) -> f32 {
        let mut result = 0.0f32;
        unsafe {
            sys::OIIO_ImageBuf_getchannel(
                self.ptr,
                &mut result,
                x,
                y,
                z,
                c,
                mode.into(),
            );
        }
        result
    }

    /// Retrieve the pixel value at coordinates `[x, y, z]`, placing its
    /// contents in `pixel[0..n-1]` where `n` is the smaller of
    /// `maxchannels` and the actual number of channels stored in the buffer.
    ///
    /// # Panics
    /// * if `pixel` is not long enough to hold the requested number of channels
    ///
    pub fn get_pixel(
        &self,
        x: i32,
        y: i32,
        z: i32,
        pixel: &mut [f32],
        maxchannels: Option<i32>,
        mode: WrapMode,
    ) {
        let maxchannels = if let Some(maxchannels) = maxchannels {
            maxchannels
        } else {
            std::i32::MAX
        };
        let n = self.num_channels().min(maxchannels);
        if pixel.len() < n as usize {
            panic!("getpixel called with slice of length {} but requested {} channels", pixel.len(), n);
        }

        unsafe {
            sys::OIIO_ImageBuf_getpixel_3d(
                self.ptr,
                x,
                y,
                z,
                pixel.as_mut_ptr(),
                maxchannels,
                mode.into(),
            );
        }
    }

    /// Sample the image plane at pixel coordinates `(x,y)`, using linear
    /// interpolation between pixels, placing the result in `pixel[]`.
    ///
    /// # Panics
    /// * if `pixel` is not long enough to hold all the channels.
    ///
    pub fn interp_pixel(
        &self,
        x: f32,
        y: f32,
        pixel: &mut [f32],
        mode: WrapMode,
    ) {
        if pixel.len() < self.num_channels() as usize {
            panic!("getpixel called with slice of length {} but requested {} channels", pixel.len(), self.num_channels());
        }

        unsafe {
            sys::OIIO_ImageBuf_interppixel(
                self.ptr,
                x,
                y,
                pixel.as_mut_ptr(),
                mode.into(),
            );
        }
    }

    /// Sample the image plane at NDC coordinates `(s,t)`, using linear
    /// interpolation between pixels, placing the result in `pixel[]`.
    ///
    /// In NDC coordinates, `(0, 0)` is the upper-left corner of the display
    /// window, and `(1, 1)` the lower-right.
    ///
    /// # Panics
    /// * if `pixel` is not long enough to hold all the channels.
    ///
    pub fn interp_pixel_ndc(
        &self,
        s: f32,
        t: f32,
        pixel: &mut [f32],
        mode: WrapMode,
    ) {
        if pixel.len() < self.num_channels() as usize {
            panic!("getpixel called with slice of length {} but requested {} channels", pixel.len(), self.num_channels());
        }

        unsafe {
            sys::OIIO_ImageBuf_interppixel(
                self.ptr,
                s,
                t,
                pixel.as_mut_ptr(),
                mode.into(),
            );
        }
    }

    /// Sample the image plane at pixel coordinates `(x,y)`, using bicubic
    /// interpolation between pixels, placing the result in `pixel[]`.
    ///
    /// # Panics
    /// * if `pixel` is not long enough to hold all the channels.
    ///
    pub fn interp_pixel_bicubic(
        &self,
        x: f32,
        y: f32,
        pixel: &mut [f32],
        mode: WrapMode,
    ) {
        if pixel.len() < self.num_channels() as usize {
            panic!("getpixel called with slice of length {} but requested {} channels", pixel.len(), self.num_channels());
        }

        unsafe {
            sys::OIIO_ImageBuf_interppixel_bicubic(
                self.ptr,
                x,
                y,
                pixel.as_mut_ptr(),
                mode.into(),
            );
        }
    }

    /// Sample the image plane at NDC coordinates `(s,t)`, using bicubic
    /// interpolation between pixels, placing the result in `pixel[]`.
    ///
    /// In NDC coordinates, `(0, 0)` is the upper-left corner of the display
    /// window, and `(1, 1)` the lower-right.
    ///
    /// # Panics
    /// * if `pixel` is not long enough to hold all the channels.
    ///
    pub fn interp_pixel_bicubic_ndc(
        &self,
        s: f32,
        t: f32,
        pixel: &mut [f32],
        mode: WrapMode,
    ) {
        if pixel.len() < self.num_channels() as usize {
            panic!("getpixel called with slice of length {} but requested {} channels", pixel.len(), self.num_channels());
        }

        unsafe {
            sys::OIIO_ImageBuf_interppixel_bicubic_NDC(
                self.ptr,
                s,
                t,
                pixel.as_mut_ptr(),
                mode.into(),
            );
        }
    }

    /// Set the pixel with coordinates (x,y,z) to have the values in
    /// `pixel`.  
    ///
    /// The number of channels copied, is the minimum of `pixel.len()` and the
    /// actual number of channels in the image.
    ///
    pub fn set_pixel(&mut self, x: i32, y: i32, z: i32, pixel: &[f32]) {
        unsafe {
            sys::OIIO_ImageBuf_setpixel_3d(
                self.ptr,
                x,
                y,
                z,
                pixel.as_ptr(),
                pixel.len() as i32,
            );
        }
    }

    /// Retrieve the rectangle of pixels spanning the ROI (including
    /// channels) at the current subimage and MIP-map level, storing the
    /// pixel values in `pixels`, laid out by the given strides, and converting to
    /// the type of the `pixels` slice if necessary.
    ///
    /// # Errors
    /// * [`Error::BufferTooSmall`] - if the calculated buffer size given by `roi`
    /// and `strides` is larger than `pixels`
    /// * [`Error::Oiio`] - if any other error occurs
    ///
    pub unsafe fn get_pixels<T: Pixel>(
        &self,
        roi: Roi,
        pixels: &mut [T],
        strides: Strides,
    ) -> Result<()> {
        let x_stride = if strides.x_stride == Stride::AUTO {
            roi.num_channels() as usize * std::mem::size_of::<T>()
        } else {
            strides.x_stride.0 as usize
        };

        let y_stride = if strides.y_stride == Stride::AUTO {
            roi.width() as usize * x_stride
        } else {
            strides.y_stride.0 as usize
        };

        let z_stride = if strides.z_stride == Stride::AUTO {
            roi.height() as usize * y_stride
        } else {
            strides.z_stride.0 as usize
        };

        let roi_bytes = z_stride * roi.depth() as usize;
        let slice_bytes = pixels.len() * std::mem::size_of::<T>();
        if slice_bytes < roi_bytes {
            return Err(Error::BufferTooSmall);
        }

        let mut result = false;
        sys::OIIO_ImageBuf_get_pixels(
            self.ptr,
            &mut result,
            roi.into(),
            T::FORMAT.into(),
            pixels.as_mut_ptr() as *mut c_void,
            strides.x_stride.0,
            strides.y_stride.0,
            strides.z_stride.0,
        );

        if !result {
            return Err(Error::Oiio(self.get_error(true)));
        }

        Ok(())
    }

    /// Copy the data into the given ROI of the ImageBuf.
    ///
    /// The `pixels` slice contains values with layout detailed by the stride
    /// values (in bytes, with AutoStride indicating "contiguous" layout).
    ///
    /// # Errors
    /// * [`Error::BufferTooSmall`] - if the calculated buffer size given by `roi`
    /// and `strides` is larger than `pixels`
    /// * [`Error::Oiio`] - if any other error occurs
    ///
    pub unsafe fn set_pixels<T: Pixel>(
        &mut self,
        roi: Roi,
        pixels: &[T],
        strides: Strides,
    ) -> Result<()> {
        let x_stride = if strides.x_stride == Stride::AUTO {
            roi.num_channels() as usize * std::mem::size_of::<T>()
        } else {
            strides.x_stride.0 as usize
        };

        let y_stride = if strides.y_stride == Stride::AUTO {
            roi.width() as usize * x_stride
        } else {
            strides.y_stride.0 as usize
        };

        let z_stride = if strides.z_stride == Stride::AUTO {
            roi.height() as usize * y_stride
        } else {
            strides.z_stride.0 as usize
        };

        let roi_bytes = z_stride * roi.depth() as usize;
        let slice_bytes = pixels.len() * std::mem::size_of::<T>();
        if slice_bytes < roi_bytes {
            return Err(Error::BufferTooSmall);
        }

        let mut result = false;
        sys::OIIO_ImageBuf_set_pixels(
            self.ptr,
            &mut result,
            roi.into(),
            T::FORMAT.into(),
            pixels.as_ptr() as *const c_void,
            strides.x_stride.0,
            strides.y_stride.0,
            strides.z_stride.0,
        );

        if !result {
            return Err(Error::Oiio(self.get_error(true)));
        }

        Ok(())
    }
}

impl ImageBuf {
    //! Getting and setting information

    /// Has the ImageBuf been initialized yet?
    ///
    pub fn initialized(&self) -> bool {
        let mut result = false;
        unsafe {
            sys::OIIO_ImageBuf_initialized(self.ptr, &mut result);
        }
        result
    }

    /// Return the number of color channels in the image. This is equivalent
    /// to `spec().nchannels()`.
    ///
    pub fn num_channels(&self) -> i32 {
        let mut result = 0;
        unsafe {
            sys::OIIO_ImageBuf_nchannels(self.ptr, &mut result);
        }
        result
    }

    /// Returns the type of [`Storage`] being used by this ImageBuf
    ///
    pub fn storage(&self) -> Storage {
        let mut s = sys::OIIO_ImageBuf_IBStorage_UNINITIALIZED;
        unsafe {
            sys::OIIO_ImageBuf_storage(self.ptr, &mut s);
        }
        s.into()
    }

    /// Get a reference to the [`ImageSpec`] that defines the buffer
    ///
    pub fn spec(&self) -> ImageSpecRef {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageBuf_spec(self.ptr, &mut ptr);
        }
        ImageSpecRef::new(ptr)
    }

    /// Get a reference to the "native" [`ImageSpec`] that defines the file this
    /// ImageBuf refers to.
    ///
    /// This may be slightly different from that returned by [`spec()`](ImageBuf::spec),
    /// particularly if this ImageBuf is backed by an [`ImageCache`] that imposes
    /// limits on data formats and tile sizes.
    ///
    pub fn native_spec(&self) -> ImageSpecRef {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageBuf_nativespec(self.ptr, &mut ptr);
        }
        ImageSpecRef::new(ptr)
    }

    /// Returns the name of the buffer (name of the file, for an ImageBuf
    /// read from disk).
    pub fn name(&self) -> &str {
        let mut sv = sys::OIIO_string_view_t::default();
        unsafe {
            sys::OIIO_ImageBuf_name(self.ptr, &mut sv);

            let mut ptr = std::ptr::null();
            let mut len = 0;
            sys::OIIO_string_view_c_str(&sv, &mut ptr);
            sys::OIIO_string_view_size(&sv, &mut len);
            let s = std::slice::from_raw_parts(ptr as *const u8, len as usize);
            std::str::from_utf8(s).expect("invalid utf-8 in ImageBuf name")
        }
    }

    /// Returns the name of the buffer (name of the file, for an ImageBuf
    /// read from disk).
    pub fn file_format_name(&self) -> &str {
        let mut sv = sys::OIIO_string_view_t::default();
        unsafe {
            sys::OIIO_ImageBuf_file_format_name(self.ptr, &mut sv);

            let mut ptr = std::ptr::null();
            let mut len = 0;
            sys::OIIO_string_view_c_str(&sv, &mut ptr);
            sys::OIIO_string_view_size(&sv, &mut len);
            let s = std::slice::from_raw_parts(ptr as *const u8, len as usize);
            std::str::from_utf8(s).expect("invalid utf-8 in ImageBuf name")
        }
    }

    /// Return the index of the subimage within the file that the ImageBuf
    /// refers to. This will always be 0 for an ImageBuf that was not
    /// constructed as a direct reference to a file, or if the file
    /// contained only one image.
    ///
    pub fn subimage(&self) -> i32 {
        let mut result = 0;
        unsafe {
            sys::OIIO_ImageBuf_subimage(self.ptr, &mut result);
        }
        result
    }

    /// Return the number of subimages in the file this ImageBuf refers to.
    /// This will always be 1 for an ImageBuf that was not constructed as a
    /// direct reference to a file.
    ///
    pub fn num_subimages(&self) -> i32 {
        let mut result = 0;
        unsafe {
            sys::OIIO_ImageBuf_nsubimages(self.ptr, &mut result);
        }
        result
    }

    /// Return the index of the miplevel with a file's subimage that the
    /// ImageBuf is currently holding. This will always be 0 for an ImageBuf
    /// that was not constructed as a direct reference to a file, or if the
    /// subimage within that file was not MIP-mapped.
    ///
    pub fn miplevel(&self) -> i32 {
        let mut result = 0;
        unsafe {
            sys::OIIO_ImageBuf_miplevel(self.ptr, &mut result);
        }
        result
    }

    /// Return the number of MIP levels of the current subimage within the
    /// file this ImageBuf refers to. This will always be 1 for an ImageBuf
    /// that was not constructed as a direct reference to a file, or if this
    /// subimage within the file was not MIP-mapped.
    ///
    pub fn num_miplevels(&self) -> i32 {
        let mut result = 0;
        unsafe {
            sys::OIIO_ImageBuf_nmiplevels(self.ptr, &mut result);
        }
        result
    }
}

impl ImageBuf {
    //! Deep data

    /// Does this ImageBuf store deep data? Returns `true` if the ImageBuf
    /// holds a "deep" image, `false` if the ImageBuf holds an ordinary
    /// pixel-based image.
    ///
    pub fn is_deep(&self) -> bool {
        let mut result = false;
        unsafe {
            sys::OIIO_ImageBuf_deep(self.ptr, &mut result);
        }
        result
    }

    /// Retrieve the number of deep data samples corresponding to pixel
    /// (x,y,z).  Return 0 if not a deep image, or if the pixel is outside
    /// of the data window, or if the designated pixel has no deep samples.
    ///
    pub fn num_deep_samples(&self, x: i32, y: i32, z: i32) -> i32 {
        let mut result = 0;
        unsafe {
            sys::OIIO_ImageBuf_deep_samples(self.ptr, &mut result, x, y, z);
        }
        result
    }

    // FIXME: finish deep stuff
}

impl Clone for ImageBuf {
    fn clone(&self) -> ImageBuf {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageBuf_clone(
                self.ptr,
                &mut ptr,
                TypeDesc::UNKNOWN.into(),
            );
        }

        ImageBuf { ptr }
    }
}

impl Drop for ImageBuf {
    fn drop(&mut self) {
        unsafe {
            sys::OIIO_ImageBuf_dtor(self.ptr);
        }
    }
}

/// Describes what happens when an iterator points to
/// a value outside the usual data range of an image.
///
#[derive(Debug, Copy, Clone, PartialEq, PartialOrd)]
pub enum WrapMode {
    Default,
    Black,
    Clamp,
    Periodic,
    Mirror,
}

impl From<WrapMode> for sys::OIIO_ImageBuf_WrapMode {
    fn from(m: WrapMode) -> Self {
        match m {
            WrapMode::Default => sys::OIIO_ImageBuf_WrapMode_WrapDefault,
            WrapMode::Black => sys::OIIO_ImageBuf_WrapMode_WrapBlack,
            WrapMode::Clamp => sys::OIIO_ImageBuf_WrapMode_WrapClamp,
            WrapMode::Periodic => sys::OIIO_ImageBuf_WrapMode_WrapPeriodic,
            WrapMode::Mirror => sys::OIIO_ImageBuf_WrapMode_WrapMirror,
        }
    }
}

// Thread-safety for read-only methods guaranteed by OIIO
unsafe impl Send for ImageBuf {}
unsafe impl Sync for ImageBuf {}

pub struct AppImageBuf<T: Pixel> {
    imagebuf: ImageBuf,
    data: Vec<T>,
}

impl<T> AppImageBuf<T>
where
    T: Pixel,
{
    pub fn new(
        data: Vec<T>,
        spec: &ImageSpec,
        x_stride: Stride,
        y_stride: Stride,
        z_stride: Stride,
    ) -> Result<AppImageBuf<T>> {
        let mut ptr = std::ptr::null_mut();
        let mut data = data;

        unsafe {
            sys::OIIO_ImageBuf_wrap_buffer(
                &mut ptr,
                spec.0,
                data.as_mut_ptr() as *mut c_void,
                x_stride.0,
                y_stride.0,
                z_stride.0,
            );

            let mut has_error = false;
            sys::OIIO_ImageBuf_has_error(ptr, &mut has_error);
            let mut s_ptr = std::ptr::null_mut();
            sys::OIIO_ImageBuf_geterror(ptr, &mut s_ptr, true);
            if has_error {
                return Err(Error::Oiio(CppString(s_ptr).as_str().to_string()));
            }

            // If the buffer has storage UNINITIALIZED, then the spec wasn't
            // valid and this buffer is also invalid.
            let mut storage = sys::OIIO_ImageBuf_IBStorage_UNINITIALIZED;
            sys::OIIO_ImageBuf_storage(ptr, &mut storage);
            if storage == sys::OIIO_ImageBuf_IBStorage_UNINITIALIZED {
                return Err(Error::InvalidSpec);
            }

            Ok(AppImageBuf::<T> {
                imagebuf: ImageBuf { ptr },
                data,
            })
        }
    }

    /// Consumes this AppImageBuf and returns the contained Vec.
    ///
    pub fn into_vec(self) -> Vec<T> {
        self.data
    }
}

#[cfg(test)]
mod tests {
    use crate as oiio;

    #[test]
    fn imagebuf_read_new() -> Result<(), oiio::Error> {
        use oiio::imagebuf::ImageBuf;
        use std::path::Path;

        let path = Path::new(
            &std::env::var("CARGO_MANIFEST_DIR")
                .expect("CARGO_MANIFEST_DIR not set"),
        )
        .join("images")
        .join("ferris.png");

        let ib = ImageBuf::open(path, 0, 0, None, None, None)?;

        Ok(())
    }
}
