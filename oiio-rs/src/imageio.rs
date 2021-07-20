use crate::cppstd::CppString;
use crate::error::Error;
use crate::filesystem::IOProxy;
use crate::refptr::{OpaquePtr, Ref, RefMut};
use crate::traits::Pixel;
use crate::typedesc::TypeDesc;

use oiio_sys as sys;
use std::ffi::{CStr, CString};
use std::os::raw::c_void;
use std::path::Path;

type Result<T, E = Error> = std::result::Result<T, E>;

#[repr(transparent)]
pub struct Stride(i64);

impl Stride {
    pub const AUTO: Stride = Stride(std::i64::MIN);
}

/// ROI is a small helper struct describing a rectangular region of interest
/// in an image. The region is [xbegin,xend) x [begin,yend) x [zbegin,zend),
/// with the "end" designators signifying one past the last pixel in each
/// dimension, a la STL style.
///
pub use sys::OIIO_ROI_t as Roi;

#[repr(transparent)]
pub struct ImageSpec(pub(crate) *mut sys::OIIO_ImageSpec_t);

unsafe impl OpaquePtr for ImageSpec {
    type SysPointee = sys::OIIO_ImageSpec_t;
    type Pointee = ImageSpec;
}

pub type ImageSpecRef<'a, P = ImageSpec> = Ref<'a, P>;
pub type ImageSpecRefMut<'a, P = ImageSpec> = RefMut<'a, P>;

impl ImageSpec {
    /// Given just the data format, set all other fields to something reasonable.
    ///
    pub fn from_typedesc(format: TypeDesc) -> ImageSpec {
        let mut inner = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageSpec_from_typedesc(&mut inner, format.into());
        }

        ImageSpec(inner)
    }

    /// Constructs an `ImageSpec` with the given x and y resolution, number
    /// of channels, and pixel data format.
    ///
    /// All other fields are set to the obvious defaults -- the image is an
    /// ordinary 2D image (not a volume), the image is not offset or a crop
    /// of a bigger image, the image is scanline-oriented (not tiled),
    /// channel names are "R", "G", "B"' and "A" (up to and including 4
    /// channels, beyond that they are named "channel *n*"), the fourth
    /// channel (if it exists) is assumed to be alpha.
    ///
    pub fn from_dimensions(
        xres: i32,
        yres: i32,
        nchans: i32,
        format: TypeDesc,
    ) -> Self {
        let mut inner = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageSpec_from_dimensions(
                &mut inner,
                xres,
                yres,
                nchans,
                format.into(),
            );
        }

        ImageSpec(inner)
    }

    /// Construct an `ImageSpec` whose dimensions (both data and "full") and
    /// number of channels are given by the `ROI`, pixel data type by `fmt`,
    /// and other fields are set to their default values.
    ///
    pub fn from_roi(roi: &Roi, format: TypeDesc) -> Self {
        let mut inner = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageSpec_from_roi(&mut inner, roi, format.into());
        }

        ImageSpec(inner)
    }

    /// Width of the pixel data window
    ///
    pub fn width(&self) -> i32 {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_width(self.0, &mut ptr);
            *ptr
        }
    }

    /// Height of the pixel data window
    ///
    pub fn height(&self) -> i32 {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_height(self.0, &mut ptr);
            *ptr
        }
    }

    /// Depth of the pixel data window
    ///
    pub fn depth(&self) -> i32 {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_depth(self.0, &mut ptr);
            *ptr
        }
    }

    /// Number of image channels, e.g. 4 for RGBA
    ///
    pub fn nchannels(&self) -> i32 {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_nchannels(self.0, &mut ptr);
            *ptr
        }
    }

    /// Width of a tile (0 if this is a scanline image)
    ///
    pub fn tile_width(&self) -> i32 {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_tile_width(self.0, &mut ptr);
            *ptr
        }
    }

    /// Height of a tile (0 if this is a scanline image)    
    ///
    pub fn tile_height(&self) -> i32 {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_tile_height(self.0, &mut ptr);
            *ptr
        }
    }

    /// Depth of a tile (0 if this is a scanline image)    
    ///
    pub fn tile_depth(&self) -> i32 {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_tile_depth(self.0, &mut ptr);
            *ptr
        }
    }

    /// Is this file a scanline image?
    ///
    pub fn is_scanline(&self) -> bool {
        self.tile_width() == 0
    }

    /// Is this file a tiled image?
    ///
    pub fn is_tiled(&self) -> bool {
        self.tile_width() != 0
    }
}

impl Drop for ImageSpec {
    fn drop(&mut self) {
        unsafe {
            sys::OIIO_ImageSpec_dtor(self.0);
        }
    }
}

pub struct ImageInput {
    pub(crate) uptr: sys::std_ImageInputPtr_t,
    pub(crate) ptr: *mut sys::OIIO_ImageInput_t,
}

impl ImageInput {
    /// Create an ImageInput subclass instance that is able to read the
    /// given file and open it.
    ///
    /// The `config`, if provided, should be an [`ImageSpec`] giving hints,
    /// requests, or special instructions.  ImageInput implementations are
    /// free to not respond to any such requests, so the default
    /// implementation is just to ignore `config`.
    ///
    /// `open()` will first try to make an ImageInput corresponding to
    /// the format implied by the file extension (for example, `"foo.tif"`
    /// will try the TIFF plugin), but if one is not found or if the
    /// inferred one does not open the file, every known ImageInput type
    /// will be tried until one is found that will open the file.
    ///
    /// # Parameters
    /// * `filename` - The name of the file to open.
    /// * `config` - Optional ImageSpec whose metadata contains "configuration hints."
    /// * `ioproxy` - Optional [`IOProxy`](crate::filesystem::IOProxy) to use
    /// (not supported by all formats, see `supports("ioproxy")`). The caller
    /// retains ownership of the proxy.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - If any error occurs
    ///
    /// # Examples
    /// ```no_run
    /// use oiio::prelude::*;
    /// # use oiio::Error;
    /// # fn read_image() -> Result<(), Error> {
    /// #    use std::path::Path;
    /// #    let path = Path::new(
    /// #        &std::env::var("CARGO_MANIFEST_DIR")
    /// #            .expect("CARGO_MANIFEST_DIR not set"),
    /// #    )
    /// #    .join("images")
    /// #    .join("ferris.png");
    ///
    /// // Open the image at the given path. It will be closed automatically
    /// // when `ii` is dropped.
    /// let mut ii = ImageInput::open(&path, None, None)?;
    ///
    /// // Get a ref to the ImageSpec that holds details of the image
    /// let spec = ii.spec();
    ///
    /// // Allocate enough storage to hold the full image
    /// let mut pixels = vec![
    ///     0u8;
    ///     (spec.width() * spec.height() * spec.nchannels())
    ///         as usize
    /// ];
    ///
    /// // Read the image into the storage
    /// ii.read_image(&mut pixels, ReadOptions::default())?;
    ///
    /// #    Ok(())
    /// # }
    /// ```
    ///
    pub fn open<P: AsRef<Path>>(
        filename: P,
        config: Option<&ImageSpec>,
        ioproxy: Option<&IOProxy>,
    ) -> Result<ImageInput> {
        let s_filename =
            CppString::new(filename.as_ref().as_os_str().to_str().unwrap());

        let mut uptr = sys::std_ImageInputPtr_t::default();
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageInput_open(
                &mut uptr,
                s_filename.0,
                if let Some(config) = config {
                    config.0
                } else {
                    std::ptr::null()
                },
                if let Some(ioproxy) = ioproxy {
                    ioproxy.0
                } else {
                    std::ptr::null_mut()
                },
            );

            sys::std_ImageInputPtr_get(&uptr, &mut ptr);
            if ptr.is_null() {
                let mut error_string = CppString::new("");
                sys::OIIO_geterror(&mut error_string.0, true);
                return Err(Error::Oiio(error_string.as_str().to_string()));
            }
        }

        Ok(ImageInput { uptr, ptr })
    }

    /// Return a reference to the image specification of the current
    /// subimage/MIPlevel.  
    ///
    /// Note that the contents of the spec are invalid before `open()` or after
    /// `close()`, and may change with a call to `seek_subimage()`.
    ///
    /// It is thus not thread-safe, since the spec may change if another thread
    /// calls `seek_subimage`, or any of the `read_*()` functions that take
    /// explicit subimage/miplevel.
    ///
    /// FIXME: encode this^^^
    ///
    pub fn spec(&self) -> ImageSpecRef {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageInput_spec(self.ptr, &mut ptr);
            if ptr.is_null() {
                panic!("OIIO_ImageInput_spec returned nullptr");
            }
        }

        ImageSpecRef::new(ptr)
    }

    pub fn read_image<T: Pixel>(
        &mut self,
        pixels: &mut [T],
        read_options: ReadOptions,
    ) -> Result<()> {
        let spec = self.spec();
        let chend = read_options
            .chend
            .clamp(read_options.chbegin + 1, spec.nchannels());
        let nchannels = chend - read_options.chbegin;
        let num_pixels = spec.width() * spec.height() * nchannels;

        if pixels.len() < num_pixels as usize {
            return Err(Error::BufferTooSmall);
        }

        unsafe {
            let mut result = false;
            sys::OIIO_ImageInput_read_image(
                self.ptr,
                &mut result,
                read_options.subimage,
                read_options.miplevel,
                read_options.chbegin,
                chend,
                T::FORMAT.into(),
                pixels.as_mut_ptr() as *mut std::os::raw::c_void,
                read_options.x_stride.0,
                read_options.y_stride.0,
                read_options.z_stride.0,
                std::mem::transmute::<
                    *const (),
                    extern "C" fn(*mut std::os::raw::c_void, f32) -> bool,
                >(std::ptr::null()),
                std::ptr::null_mut(),
            );

            if !result {
                let mut msg = CppString::new("");
                sys::OIIO_ImageInput_geterror(self.ptr, &mut msg.0, true);
                return Err(Error::Oiio(msg.as_str().to_string()));
            }
        }

        Ok(())
    }
}

pub type ProgressCallback = extern "C" fn(*mut c_void, f32) -> bool;

pub struct ReadOptions {
    pub subimage: i32,
    pub miplevel: i32,
    pub chbegin: i32,
    pub chend: i32,
    pub x_stride: Stride,
    pub y_stride: Stride,
    pub z_stride: Stride,
}

impl Default for ReadOptions {
    fn default() -> Self {
        Self {
            subimage: 0,
            miplevel: 0,
            chbegin: 0,
            chend: std::i32::MAX,
            x_stride: Stride::AUTO,
            y_stride: Stride::AUTO,
            z_stride: Stride::AUTO,
        }
    }
}

impl Drop for ImageInput {
    fn drop(&mut self) {
        unsafe {
            sys::std_ImageInputPtr_dtor(&mut self.uptr);
        }
    }
}

#[cfg(test)]
mod test {
    use crate as oiio;
    use oiio::error::Error;
    use oiio::imageio::{ImageInput, ReadOptions};
    use std::path::Path;

    #[test]
    fn read_image() -> Result<(), Error> {
        let path = Path::new(
            &std::env::var("CARGO_MANIFEST_DIR")
                .expect("CARGO_MANIFEST_DIR not set"),
        )
        .join("images")
        .join("ferris.png");

        let mut ii = ImageInput::open(&path, None, None)?;
        let spec = ii.spec();

        assert_eq!(spec.width(), 1200);
        assert_eq!(spec.height(), 800);
        assert_eq!(spec.nchannels(), 4);

        let mut pixels = vec![
            0u8;
            (spec.width() * spec.height() * spec.nchannels())
                as usize
        ];

        ii.read_image(&mut pixels, ReadOptions::default())?;

        Ok(())
    }
}
