use crate::cppstd::CppString;
use crate::error::Error;
use crate::filesystem::IOProxy;
use crate::imagecache::ImageCache;
use crate::imageio::{
    get_trampoline, progress_tramp, ImageSpec, ProgressCallback, Stride,
};
use crate::typedesc::TypeDesc;

use crate::string_view::StringView;
use crate::traits::{AttributeMetadata, Pixel};

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

pub enum ImageBufStorage {
    Uninitialized,
    LocalBuffer,
    AppBuffer,
    ImageCache,
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
}

impl Drop for ImageBuf {
    fn drop(&mut self) {
        unsafe {
            sys::OIIO_ImageBuf_dtor(self.ptr);
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
