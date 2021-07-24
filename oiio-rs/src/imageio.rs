use crate::cppstd::{
    CppString, CppVectorString, CppVectorStringRef, CppVectorTypeDesc,
    CppVectorTypeDescRef,
};
use crate::error::Error;
use crate::filesystem::IOProxy;
use crate::refptr::{OpaquePtr, Ref, RefMut};
use crate::string_view::StringView;
use crate::traits::{AttributeMetadata, Pixel};
use crate::typedesc::TypeDesc;

use oiio_sys as sys;
use std::ffi::CStr;
use std::marker::PhantomData;
use std::os::raw::c_void;
use std::path::Path;

type Result<T, E = Error> = std::result::Result<T, E>;

#[repr(transparent)]
pub struct Stride(i64);

impl Stride {
    pub const AUTO: Stride = Stride(std::i64::MIN);
}

#[repr(transparent)]
pub struct ImageSize(u64);
impl ImageSize {
    pub const MAX: ImageSize = ImageSize(std::u64::MAX);
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

    /// Origin (upper-left corner) of the data window
    ///
    pub fn x(&self) -> i32 {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_x(self.0, &mut ptr);
            *ptr
        }
    }

    /// Origin (upper-left corner) of the data window
    ///
    pub fn set_x(&mut self, value: i32) {
        unsafe {
            sys::OIIO_ImageSpec_set_x(self.0, &value);
        }
    }

    /// Origin (upper-left corner) of the data window
    ///
    pub fn y(&self) -> i32 {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_y(self.0, &mut ptr);
            *ptr
        }
    }

    /// Origin (upper-left corner) of the data window
    ///
    pub fn set_y(&mut self, value: i32) {
        unsafe {
            sys::OIIO_ImageSpec_set_y(self.0, &value);
        }
    }

    /// Origin (upper-left corner) of the data window
    ///
    pub fn z(&self) -> i32 {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_z(self.0, &mut ptr);
            *ptr
        }
    }

    /// Origin (upper-left corner) of the data window
    ///
    pub fn set_z(&mut self, value: i32) {
        unsafe {
            sys::OIIO_ImageSpec_set_y(self.0, &value);
        }
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

    /// Width of the pixel data window
    ///
    pub fn set_width(&mut self, value: i32) {
        unsafe {
            sys::OIIO_ImageSpec_set_width(self.0, &value);
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

    /// Height of the pixel data window
    ///
    pub fn set_height(&mut self, value: i32) {
        unsafe {
            sys::OIIO_ImageSpec_set_height(self.0, &value);
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

    /// Depth of the pixel data window
    ///
    pub fn set_depth(&mut self, value: i32) {
        unsafe {
            sys::OIIO_ImageSpec_set_depth(self.0, &value);
        }
    }

    /// Origin (upper-left corner) of the display window
    ///
    pub fn full_x(&self) -> i32 {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_full_x(self.0, &mut ptr);
            *ptr
        }
    }

    /// Origin (upper-left corner) of the display window
    ///
    pub fn set_full_x(&mut self, value: i32) {
        unsafe {
            sys::OIIO_ImageSpec_set_full_x(self.0, &value);
        }
    }

    /// Origin (upper-left corner) of the display window
    ///
    pub fn full_y(&self) -> i32 {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_full_y(self.0, &mut ptr);
            *ptr
        }
    }

    /// Origin (upper-left corner) of the display window
    ///
    pub fn set_full_y(&mut self, value: i32) {
        unsafe {
            sys::OIIO_ImageSpec_set_full_y(self.0, &value);
        }
    }

    /// Origin (upper-left corner) of the display window
    ///
    pub fn full_z(&self) -> i32 {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_full_z(self.0, &mut ptr);
            *ptr
        }
    }

    /// Origin (upper-left corner) of the display window
    ///
    pub fn set_full_z(&mut self, value: i32) {
        unsafe {
            sys::OIIO_ImageSpec_set_full_z(self.0, &value);
        }
    }

    /// Width of the display window
    ///
    pub fn full_width(&self) -> i32 {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_full_width(self.0, &mut ptr);
            *ptr
        }
    }

    /// Width of the display window
    ///
    pub fn set_full_width(&mut self, value: i32) {
        unsafe {
            sys::OIIO_ImageSpec_set_full_width(self.0, &value);
        }
    }

    /// Height of the display window
    ///
    pub fn full_height(&self) -> i32 {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_full_height(self.0, &mut ptr);
            *ptr
        }
    }

    /// Height of the display window
    ///
    pub fn set_full_height(&mut self, value: i32) {
        unsafe {
            sys::OIIO_ImageSpec_set_full_height(self.0, &value);
        }
    }

    /// Depth of the display window
    ///
    pub fn full_depth(&self) -> i32 {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_full_depth(self.0, &mut ptr);
            *ptr
        }
    }

    /// Depth of the display window
    ///
    pub fn set_full_depth(&mut self, value: i32) {
        unsafe {
            sys::OIIO_ImageSpec_set_full_depth(self.0, &value);
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

    /// Width of a tile (0 if this is a scanline image)
    ///
    pub fn set_tile_width(&mut self, value: i32) {
        unsafe {
            sys::OIIO_ImageSpec_set_tile_width(self.0, &value);
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

    /// Height of a tile (0 if this is a scanline image)    
    ///
    pub fn set_tile_height(&mut self, value: i32) {
        unsafe {
            sys::OIIO_ImageSpec_set_tile_height(self.0, &value);
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

    /// Depth of a tile (0 if this is a scanline image)    
    ///
    pub fn set_tile_depth(&mut self, value: i32) {
        unsafe {
            sys::OIIO_ImageSpec_set_tile_depth(self.0, &value);
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

    /// Number of image channels, e.g. 4 for RGBA
    ///
    pub fn set_nchannels(&mut self, value: i32) {
        unsafe {
            sys::OIIO_ImageSpec_set_nchannels(self.0, &value);
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

    /// Data format of the channels
    ///
    /// Describes the native format of the pixel data values
    /// themselves, as a [`TypeDesc`].  Typical values would be
    /// [`TypeDesc::Uint8`] for 8-bit unsigned values, [`TypeDesc::Float`]
    /// for 32-bit floating-point values, etc.
    ///
    pub fn format(&self) -> TypeDesc {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_format(self.0, &mut ptr);
            // Safety - this is OK because we ensure that the layout of TypeDesc
            // and OIIO_TypeDesc_t are the same.
            *(ptr as *const TypeDesc)
        }
    }

    /// Data format of the channels
    ///
    /// Describes the native format of the pixel data values
    /// themselves, as a [`TypeDesc`].  Typical values would be
    /// [`TypeDesc::Uint8`] for 8-bit unsigned values, [`TypeDesc::Float`]
    /// for 32-bit floating-point values, etc.
    ///
    pub fn set_format(&mut self, value: &TypeDesc) {
        unsafe {
            sys::OIIO_ImageSpec_set_format(
                self.0,
                value as *const TypeDesc as *const sys::OIIO_TypeDesc_t,
            );
        }
    }

    /// Optional per-channel data formats.
    ///
    /// If all channels of the image have the same data format, that will be
    /// described by `format` and `channelformats` will be empty (zero
    /// length). If there are different data formats for each channel, they
    /// will be described in the `channelformats` vector, and the `format`
    /// field will indicate a single default data format for applications that
    /// don't wish to support per-channel formats (usually this will be
    /// the format of the channel that has the most precision).
    ///
    pub fn channelformats(&self) -> CppVectorTypeDescRef {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_channelformats(self.0, &mut ptr);
        }
        CppVectorTypeDescRef::new(ptr)
    }

    /// Optional per-channel data formats.
    ///
    /// If all channels of the image have the same data format, that will be
    /// described by `format` and `channelformats` will be empty (zero
    /// length). If there are different data formats for each channel, they
    /// will be described in the `channelformats` vector, and the `format`
    /// field will indicate a single default data format for applications that
    /// don't wish to support per-channel formats (usually this will be
    /// the format of the channel that has the most precision).
    ///
    pub fn set_channelformats(&mut self, value: &[TypeDesc]) {
        unsafe {
            let vec = CppVectorTypeDesc::from_slice(value);
            sys::OIIO_ImageSpec_set_channelformats(self.0, vec.0);
        }
    }

    /// The names of each channel, in order. Typically this will be "R",
    /// "G", "B", "A" (alpha), "Z" (depth), or other arbitrary names.
    ///
    pub fn channelnames(&self) -> CppVectorStringRef {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_channelnames(self.0, &mut ptr);
        }
        CppVectorStringRef::new(ptr)
    }

    /// The names of each channel, in order. Typically this will be "R",
    /// "G", "B", "A" (alpha), "Z" (depth), or other arbitrary names.
    ///
    pub fn set_channelnames<S: AsRef<str>>(&mut self, value: &[S]) {
        unsafe {
            let vec = CppVectorString::from_slice(value);
            sys::OIIO_ImageSpec_set_channelnames(self.0, vec.0);
        }
    }

    /// The index of the channel that represents `alpha` (pixel
    /// coverage and/or transparency).  
    ///
    /// Returns None is there is no alpha channel in the image, or if the alpha
    /// channel could not be determined.
    ///
    pub fn alpha_channel(&self) -> Option<i32> {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_nchannels(self.0, &mut ptr);
            // "None" is represented by -1 on the C++ side
            if *ptr == -1 {
                None
            } else {
                Some(*ptr)
            }
        }
    }

    /// The index of the channel that represents `alpha` (pixel
    /// coverage and/or transparency).  
    ///
    /// Pass None if there is no alpha channel in the image
    ///
    pub fn set_alpha_channel(&mut self, value: Option<i32>) {
        // "None" is represented by -1 on the C++ side
        let value = if let Some(value) = value { value } else { -1 };
        unsafe {
            sys::OIIO_ImageSpec_set_alpha_channel(self.0, &value);
        }
    }

    /// The index of the channel that represents `z`
    ///
    /// Returns None is there is no z channel in the image, or if the z
    /// channel could not be determined.
    ///
    pub fn z_channel(&self) -> Option<i32> {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_nchannels(self.0, &mut ptr);
            // "None" is represented by -1 on the C++ side
            if *ptr == -1 {
                None
            } else {
                Some(*ptr)
            }
        }
    }

    /// The index of the channel that represents `z` (depth)
    ///
    /// Pass None if there is no z channel in the image
    ///
    pub fn set_z_channel(&mut self, value: Option<i32>) {
        // "None" is represented by -1 on the C++ side
        let value = if let Some(value) = value { value } else { -1 };
        unsafe {
            sys::OIIO_ImageSpec_set_z_channel(self.0, &value);
        }
    }

    /// True if this image is a deep image.
    ///
    /// Deep images contain multiple samples per-pixel, whereas "flat" (regular)
    /// images contain a single sample per pixel.
    ///
    pub fn deep(&self) -> bool {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_deep(self.0, &mut ptr);
            *ptr
        }
    }

    /// True if this image is a deep image.
    ///
    /// Deep images contain multiple samples per-pixel, whereas "flat" (regular)
    /// images contain a single sample per pixel.
    ///
    pub fn set_deep(&mut self, value: bool) {
        unsafe {
            sys::OIIO_ImageSpec_set_deep(self.0, &value);
        }
    }

    /// Sets the `channelnames` to reasonable defaults for the number of
    /// channels.  
    ///
    /// Specifically, channel names are set to "R", "G", "B,"
    /// and "A" (up to and including 4 channels, beyond that they are named
    /// "channel*n*".
    ///
    pub fn set_default_channel_names(&mut self) {
        unsafe {
            sys::OIIO_ImageSpec_default_channel_names(self.0);
        }
    }

    /// Returns the number of bytes comprising each channel of each pixel
    ///
    /// (i.e., the size of a single value of the type described by the
    /// `format` field).
    ///
    pub fn channel_bytes(&self) -> usize {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageSpec_channel_bytes(self.0, &mut value);
            value as usize
        }
    }

    /// Return the number of bytes needed for the single specified
    /// channel.  
    ///
    /// If `native` is false, compute the size of one
    /// channel of [`ImageSpec::format()`], but if `native` is true, compute the size
    /// of the channel in terms of the "native" data format of that
    /// channel as stored in the file.
    ///
    pub fn channel_bytes_for_channel(&self, index: i32, native: bool) -> usize {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageSpec_channel_bytes_for_channel(
                self.0, &mut value, index, native,
            );
            value as usize
        }
    }

    /// Return the number of bytes for each pixel (counting all channels).
    ///
    /// If `native` is false, assume all channels are in [`ImageSpec::format()`],
    /// but if `native` is true, compute the size of a pixel in the "native" data
    /// format of the file (these may differ in the case of per-channel formats).
    ///
    pub fn pixel_bytes(&self, native: bool) -> usize {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageSpec_pixel_bytes(self.0, &mut value, native);
            value as usize
        }
    }

    /// Return the number of bytes for just the subset of channels in each
    /// pixel described by [chbegin,chend).
    ///
    /// If `native` is false, assume all channels are in [`ImageSpec::format()`],
    /// but if `native` is true, compute the size of a pixel in the "native" data
    /// format of the file (these may differ in the case of per-channel formats).
    ///
    pub fn pixel_bytes_for_channels(
        &self,
        chbegin: i32,
        chend: i32,
        native: bool,
    ) -> usize {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageSpec_pixel_bytes_for_channels(
                self.0, &mut value, chbegin, chend, native,
            );
            value as usize
        }
    }

    /// Returns the number of bytes comprising each scanline.
    ///
    /// i.e., `pixel_bytes(native) * width` This will return
    /// None in the event of an overflow where it's not representable in an
    /// `ImageSize`.
    pub fn scanline_bytes(&self, native: bool) -> Option<ImageSize> {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageSpec_scanline_bytes(self.0, &mut value, native);
            if value == std::u64::MAX {
                None
            } else {
                Some(ImageSize(value))
            }
        }
    }

    /// Return the number of pixels comprising a tile, or 0 if it is not a
    /// tiled image.  
    ///
    /// This will return None in the event of an overflow where it's not
    /// representable in an `ImageSize`
    ///
    pub fn tile_pixels(&self) -> Option<ImageSize> {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageSpec_tile_pixels(self.0, &mut value);
            if value == std::u64::MAX {
                None
            } else {
                Some(ImageSize(value))
            }
        }
    }

    /// Returns the number of bytes comprising each tile, or 0 if this is not
    /// a tiled image.
    ///
    /// This will return None in the event of an overflow where it's not
    /// representable in an `ImageSize`
    ///
    /// If `native` is false, assume all channels are in [`ImageSpec::format()`],
    /// but if `native` is true, compute the size of a pixel in the "native" data
    /// format of the file (these may differ in the case of per-channel formats).
    ///
    pub fn tile_bytes(&self, native: bool) -> Option<ImageSize> {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageSpec_tile_bytes(self.0, &mut value, native);
            if value == std::u64::MAX {
                None
            } else {
                Some(ImageSize(value))
            }
        }
    }

    /// Return the number of pixels comprising the whole image.
    ///
    /// This will return None in the event of an overflow where it's not
    /// representable in an `ImageSize`
    ///
    pub fn image_pixels(&self) -> Option<ImageSize> {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageSpec_image_pixels(self.0, &mut value);
            if value == std::u64::MAX {
                None
            } else {
                Some(ImageSize(value))
            }
        }
    }

    /// Returns the number of bytes comprising the whole image
    ///
    /// This will return None in the event of an overflow where it's not
    /// representable in an `ImageSize`
    ///
    /// If `native` is false, assume all channels are in [`ImageSpec::format()`],
    /// but if `native` is true, compute the size of a pixel in the "native" data
    /// format of the file (these may differ in the case of per-channel formats).
    ///
    pub fn image_bytes(&self, native: bool) -> Option<ImageSize> {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageSpec_image_bytes(self.0, &mut value, native);
            if value == std::u64::MAX {
                None
            } else {
                Some(ImageSize(value))
            }
        }
    }

    /// Verify that on this platform, a `usize` is big enough to hold the
    /// number of bytes (and pixels) in a scanline, a tile, and the
    /// whole image.  If this returns false, the image is much too big
    /// to allocate and read all at once, so client apps beware and check
    /// these routines for overflows!
    ///
    pub fn is_usize_safe(&self) -> bool {
        let mut value = false;
        unsafe {
            sys::OIIO_ImageSpec_size_t_safe(self.0, &mut value);
        }
        value
    }

    /// Add a metadata attribute to `extra_attribs`, with the given name and
    /// data type.
    ///
    pub fn set_attribute<S: AsRef<str>, A: AttributeMetadata>(
        &mut self,
        name: S,
        attribute: &A,
    ) {
        unsafe {
            let sv = StringView::from(name.as_ref());
            sys::OIIO_ImageSpec_attribute(
                self.0,
                sv.0,
                A::TYPE.into(),
                attribute.ptr(),
            );
        }
    }

    /// Searches `extra_attribs` for any attributes matching `name` (as a
    /// regular expression), removing them entirely from `extra_attribs`.
    ///
    /// If `searchtype` is anything other than `TypeDesc::UNKNOWN`, matches
    /// will be restricted only to attributes with the given type. The name
    /// comparison will be case-sensitive if `casesensitive` is true,
    /// otherwise in a case-insensitive manner.
    ///
    pub fn erase_attribute_of_type<S: AsRef<str>>(
        &mut self,
        name: S,
        search_type: TypeDesc,
        casesensitive: bool,
    ) {
        unsafe {
            let sv = StringView::from(name.as_ref());
            sys::OIIO_ImageSpec_erase_attribute(
                self.0,
                sv.0,
                search_type.into(),
                casesensitive,
            );
        }
    }

    /// Searches `extra_attribs` for any attributes matching `name` (as a
    /// regular expression), removing them entirely from `extra_attribs`.
    ///
    /// The namecomparison will be case-sensitive if `casesensitive` is true,
    /// otherwise in a case-insensitive manner.
    ///
    pub fn erase_attribute<S: AsRef<str>>(
        &mut self,
        name: S,
        casesensitive: bool,
    ) {
        self.erase_attribute_of_type(name, TypeDesc::UNKNOWN, casesensitive);
    }
}

impl Drop for ImageSpec {
    fn drop(&mut self) {
        unsafe {
            sys::OIIO_ImageSpec_dtor(self.0);
        }
    }
}

impl Clone for ImageSpec {
    fn clone(&self) -> Self {
        let mut spec = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageSpec_copy(&mut spec, self.0);
        }
        ImageSpec(spec)
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

    /// Return the name of the format implemented opened by this input
    ///
    pub fn format_name(&self) -> &str {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageInput_format_name(self.ptr, &mut ptr);
            CStr::from_ptr(ptr).to_str().expect(
                "Failed to convert string from OIIO_ImageInput_format_name",
            )
        }
    }

    /// Given the name of a "feature", return whether this ImageInput
    /// supports output of images with the given properties. Most queries
    /// will simply return 0 for "doesn't support" and 1 for "supports it,"
    /// but it is acceptable to have queries return other nonzero integers
    /// to indicate varying degrees of support or limits (but should be
    /// clearly documented as such).
    ///
    /// Feature names that ImageInput implementations are expected to
    /// recognize include:
    ///
    /// - `"arbitrary_metadata"` : Does this format allow metadata with
    ///       arbitrary names and types?
    ///
    /// - `"exif"` :
    ///       Can this format store Exif camera data?
    ///
    /// - `"iptc"` :
    ///       Can this format store IPTC data?
    ///
    /// - `"procedural"` :
    ///       Can this format create images without reading from a disk
    ///       file?
    ///
    /// - `"ioproxy"` :
    ///       Does this format reader support reading from an `IOProxy`?
    ///
    /// This list of queries may be extended in future releases. Since this
    /// can be done simply by recognizing new query strings, and does not
    /// require any new API entry points, addition of support for new
    /// queries does not break ``link compatibility'' with
    /// previously-compiled plugins.
    ///
    pub fn supports(&self, feature: &str) -> i32 {
        let mut value = 0;
        unsafe {
            let sv_feature = StringView::from(feature);
            sys::OIIO_ImageInput_supports(self.ptr, &mut value, sv_feature.0);
        }
        value
    }

    /// Return true if the `filename` names a file of the type for this
    /// ImageInput.  
    ///
    /// The implementation will try to determine this as
    /// efficiently as possible, in most cases much less expensively than
    /// doing a full `open()`.  Note that there can be false positives: a
    /// file can appear to be of the right type (i.e., `valid_file()`
    /// returning `true`) but still fail a subsequent call to `open()`, such
    /// as if the contents of the file are truncated, nonsensical, or
    /// otherwise corrupted.
    ///
    pub fn valid_file<P: AsRef<Path>>(&self, filename: P) -> bool {
        let s_filename =
            CppString::new(filename.as_ref().as_os_str().to_str().unwrap());
        let mut result = false;
        unsafe {
            sys::OIIO_ImageInput_valid_file(
                self.ptr,
                &mut result,
                s_filename.0,
            );
        }
        result
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

    /// Return a copy to the image specification of the given subimage and MIP level.  
    ///
    /// This method is thread-safe, but it is potentially
    /// expensive, due to the work that needs to be done to fully copy an
    /// ImageSpec if there is lots of named metadata to allocate and copy.
    /// See also the less expensive `spec_dimensions()`.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - in case any error occurs, such as requesting a
    /// non-existent subimage
    ///
    pub fn spec_for_subimage(
        &self,
        subimage: i32,
        miplevel: i32,
    ) -> Result<ImageSpec> {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageInput_spec_for_subimage(
                self.ptr, &mut ptr, subimage, miplevel,
            );
            if ptr.is_null() {
                panic!("OIIO_ImageInput_spec_for_subimage returned nullptr");
            }
        }

        let spec = ImageSpec(ptr);
        if spec.format() == TypeDesc::UNKNOWN {
            Err(Error::Oiio(self.get_error(true)))
        } else {
            Ok(ImageSpec(ptr))
        }
    }

    /// Return a copy of the ImageSpec of the designated subimage and
    /// miplevel, but only the dimension and type fields.
    ///
    /// Just as with a call to `ImageSpec::copy_dimensions()`, neither the channel names
    /// nor any of the arbitrary named metadata will be copied, thus this is
    /// a relatively inexpensive operation if you don't need that
    /// information. It is guaranteed to be thread-safe.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - in case any error occurs, such as requesting a
    /// non-existent subimage
    ///
    pub fn spec_dimensions(
        &self,
        subimage: i32,
        miplevel: i32,
    ) -> Result<ImageSpec> {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageInput_spec_dimensions(
                self.ptr, &mut ptr, subimage, miplevel,
            );
            if ptr.is_null() {
                panic!("OIIO_ImageInput_spec_dimensions returned nullptr");
            }
        }

        let spec = ImageSpec(ptr);
        if spec.format() == TypeDesc::UNKNOWN {
            Err(Error::Oiio(self.get_error(true)))
        } else {
            Ok(ImageSpec(ptr))
        }
    }

    /// Returns the index of the subimage that is currently being read.
    /// The first subimage (or the only subimage, if there is just one)
    /// is number 0.
    ///
    pub fn current_subimage(&self) -> i32 {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageInput_current_subimage(self.ptr, &mut value);
        }
        value
    }

    /// Returns the index of the MIPmap image that is currently being read.
    /// The highest-res MIP level (or the only level, if there is just
    /// one) is number 0.
    ///
    pub fn current_miplevel(&self) -> i32 {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageInput_current_miplevel(self.ptr, &mut value);
        }
        value
    }

    /// Return the text of all pending error messages issued against this
    /// ImageInput by the calling thread, and clear the pending error
    /// message unless `clear` is false. If no error message is pending, it
    /// will return an empty string.
    ///
    pub fn get_error(&self, clear: bool) -> String {
        let mut msg = CppString::new("");
        unsafe {
            sys::OIIO_ImageInput_geterror(self.ptr, &mut msg.0, clear);
            msg.as_str().to_string()
        }
    }

    /// Retrieve the current thread-spawning policy.
    ///
    /// The default of 0 means that the global
    /// `attribute("threads")` value should be used (which itself defaults
    /// to using as many threads as cores; see Section `Global Attributes`_).
    ///
    pub fn threads(&self) -> i32 {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageInput_threads_const(self.ptr, &mut value);
        }
        value
    }

    /// Set the threading policy for this ImageInput, controlling the
    /// maximum amount of parallelizing thread "fan-out" that might occur
    /// during large read operations. The default of 0 means that the global
    /// `attribute("threads")` value should be used (which itself defaults
    /// to using as many threads as cores; see Section `Global Attributes`_).
    ///
    /// The main reason to change this value is to set it to 1 to indicate
    /// that the calling thread should do all the work rather than spawning
    /// new threads. That is probably the desired behavior in situations
    /// where the calling application has already spawned multiple worker
    /// threads.
    ///
    pub fn set_threads(&self, threads: i32) {
        unsafe {
            sys::OIIO_ImageInput_threads(self.ptr, threads);
        }
    }

    /// Read the entire image of `spec.width x spec.height x spec.depth`
    /// pixels into a buffer with the given strides and in the desired
    /// data format.
    ///
    /// Depending on the spec, this will read either all tiles or all
    /// scanlines. Assume that data points to a layout in row-major order.
    ///
    /// This version of read_image, because it passes explicit subimage and
    /// miplevel, does not require a separate call to seek_subimage, and is
    /// guaranteed to be thread-safe against other concurrent calls to any
    /// of the read_* methods that take an explicit subimage/miplevel (but
    /// not against any other ImageInput methods).
    ///
    /// Because this may be an expensive operation, a progress callback
    /// may be passed.  Periodically, it will be called as follows:
    ///
    /// `progress_callback (progress_callback_data, done)`;
    ///
    /// where `done: f32` gives the portion of the image (between 0.0 and 1.0)
    /// that has been written thus far.
    ///
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

#[repr(transparent)]
pub(crate) struct ImageOutputPtr(pub(crate) sys::std_ImageOutputPtr_t);

impl Drop for ImageOutputPtr {
    fn drop(&mut self) {
        unsafe {
            sys::std_ImageOutputPtr_dtor(&mut self.0);
        }
    }
}

pub struct ImageOutputBase<S: ImageOutputState> {
    pub(crate) uptr: ImageOutputPtr,
    pub(crate) ptr: *mut sys::OIIO_ImageOutput_t,
    marker: PhantomData<S>,
}

pub trait ImageOutputState {}

pub enum ImageOutputStateClosed {}
pub enum ImageOutputStateOpened {}

impl ImageOutputState for ImageOutputStateClosed {}
impl ImageOutputState for ImageOutputStateOpened {}

pub type ImageOutput = ImageOutputBase<ImageOutputStateClosed>;
pub type ImageOuputOpened = ImageOutputBase<ImageOutputStateOpened>;

impl<S> ImageOutputBase<S>
where
    S: ImageOutputState,
{
    /// Create an `ImageOutput` that can be used to write an image file.
    /// The type of image file (and hence, the particular subclass of
    /// `ImageOutput` returned, and the plugin that contains its methods) is
    /// inferred from the name, if it appears to be a full filename, or it
    /// may also name the format.
    ///
    /// # Parameters
    /// * `filename` - The name of the file format (e.g., "openexr"), a file
    /// extension (e.g., "exr"), or a filename from which the the
    /// file format can be inferred from its extension (e.g.,
    /// "hawaii.exr").
    ///
    /// * `plugin_searchpath` - An optional colon-separated list of directories to search
    /// for OpenImageIO plugin DSO/DLL's.
    ///
    /// * `ioproxy` - Optional pointer to an [`IOProxy`] to use (not supported by all
    /// formats, see `supports("ioproxy")`). The caller retains ownership of the proxy.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - If any error occurs
    ///
    pub fn create<P: AsRef<Path>>(
        filename: P,
        ioproxy: Option<&IOProxy>,
        plugin_search_path: Option<&str>,
    ) -> Result<ImageOutputBase<ImageOutputStateClosed>> {
        let sv_filename = StringView::from(
            filename
                .as_ref()
                .as_os_str()
                .to_str()
                .expect("filename string could not be converted"),
        );

        let c_plugin_search_path = if let Some(s) = plugin_search_path {
            StringView::from(s)
        } else {
            StringView::from("")
        };

        let mut uptr = sys::std_ImageOutputPtr_t::default();
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageOutput_create(
                &mut uptr,
                sv_filename.0,
                if let Some(ioproxy) = ioproxy {
                    ioproxy.0
                } else {
                    std::ptr::null_mut()
                },
                c_plugin_search_path.0,
            );

            sys::std_ImageOutputPtr_get(&uptr, &mut ptr);
            if ptr.is_null() {
                let mut error_string = CppString::new("");
                sys::OIIO_geterror(&mut error_string.0, true);
                return Err(Error::Oiio(error_string.as_str().to_string()));
            }
        }

        Ok(ImageOutputBase {
            uptr: ImageOutputPtr(uptr),
            ptr,
            marker: PhantomData,
        })
    }

    pub fn open<P: AsRef<Path>>(
        self,
        filename: P,
        spec: &ImageSpec,
        mode: OpenMode,
    ) -> Result<ImageOutputBase<ImageOutputStateOpened>> {
        let c_filename = CppString::new(
            filename
                .as_ref()
                .to_str()
                .expect("Could not convert filename"),
        );
        let mut result = false;
        unsafe {
            sys::OIIO_ImageOutput_open(
                self.ptr,
                &mut result,
                c_filename.0,
                spec.0,
                mode.into(),
            );
        }

        if result {
            Ok(ImageOutputBase::<ImageOutputStateOpened> {
                uptr: self.uptr,
                ptr: self.ptr,
                marker: PhantomData,
            })
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }

    pub fn new<P: AsRef<Path>>(
        filename: P,
        spec: &ImageSpec,
        mode: OpenMode,
        ioproxy: Option<&IOProxy>,
        plugin_search_path: Option<&str>,
    ) -> Result<ImageOutputBase<ImageOutputStateOpened>> {
        let io = ImageOutputBase::<S>::create(
            filename.as_ref(),
            ioproxy,
            plugin_search_path,
        )?;
        io.open(filename, spec, mode)
    }

    /// Return the name of the format implemented opened by this output type
    ///
    pub fn format_name(&self) -> &str {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageOutput_format_name(self.ptr, &mut ptr);
            CStr::from_ptr(ptr).to_str().expect(
                "Failed to convert string from OIIO_ImageOutput_format_name",
            )
        }
    }

    /// Given the name of a "feature", return whether this ImageOutput
    /// supports output of images with the given properties. Most queries
    /// will simply return 0 for "doesn't support" and 1 for "supports it,"
    /// but it is acceptable to have queries return other nonzero integers
    /// to indicate varying degrees of support or limits (but should be
    /// clearly documented as such).
    ///
    /// Feature names that ImageOutput implementations are expected to
    /// recognize include:
    ///
    ///  - `"tiles"` :
    ///         Is this format writer able to write tiled images?
    ///
    ///  - `"rectangles"` :
    ///         Does this writer accept arbitrary rectangular pixel regions
    ///         (via `write_rectangle()`)?  Returning 0 indicates that
    ///         pixels must be transmitted via `write_scanline()` (if
    ///         scanline-oriented) or `write_tile()` (if tile-oriented, and
    ///         only if `supports("tiles")` returns true).
    ///
    ///  - `"random_access"` :
    ///         May tiles or scanlines be written in any order (0 indicates
    ///         that they *must* be in successive order)?
    ///
    ///  - `"multiimage"` :
    ///         Does this format support multiple subimages within a file?
    ///
    ///  - `"appendsubimage"` :
    ///         Does this format support multiple subimages that can be
    ///         successively appended at will via
    ///         `open(name,spec,AppendSubimage)`? A value of 0 means that
    ///         the format requires pre-declaring the number and
    ///         specifications of the subimages when the file is first
    ///         opened, with `open(name,subimages,specs)`.
    ///
    ///  - `"mipmap"` :
    ///         Does this format support multiple resolutions for an
    ///         image/subimage?
    ///
    ///  - `"volumes"` :
    ///         Does this format support "3D" pixel arrays (a.k.a. volume
    ///         images)?
    ///
    ///  - `"alpha"` :
    ///         Can this format support an alpha channel?
    ///
    ///  - `"nchannels"` :
    ///         Can this format support arbitrary number of channels (beyond RGBA)?
    ///
    ///  - `"rewrite"` :
    ///         May the same scanline or tile be sent more than once?
    ///         Generally, this is true for plugins that implement
    ///         interactive display, rather than a saved image file.
    ///
    ///  - `"empty"` :
    ///         Does this plugin support passing a NULL data pointer to the
    ///         various `write` routines to indicate that the entire data
    ///         block is composed of pixels with value zero?  Plugins that
    ///         support this achieve a speedup when passing blank scanlines
    ///         or tiles (since no actual data needs to be transmitted or
    ///         converted).
    ///
    ///  - `"channelformats"` :
    ///         Does this format writer support per-channel data formats,
    ///         respecting the ImageSpec's `channelformats` field? If not,
    ///         it only accepts a single data format for all channels and
    ///         will ignore the `channelformats` field of the spec.
    ///
    ///  - `"displaywindow"` :
    ///         Does the format support display ("full") windows distinct
    ///         from the pixel data window?
    ///
    ///  - `"origin"` :
    ///         Does the image format support specifying a pixel window
    ///         origin (i.e., nonzero ImageSpec `x`, `y`, `z`)?
    ///
    ///  - `"negativeorigin"` :
    ///         Does the image format allow data and display window origins
    ///         (i.e., ImageSpec `x`, `y`, `z`, `full_x`, `full_y`, `full_z`)
    ///         to have negative values?
    ///
    ///  - `"deepdata"` :
    ///        Does the image format allow "deep" data consisting of
    ///        multiple values per pixel (and potentially a differing number
    ///        of values from pixel to pixel)?
    ///
    ///  - `"arbitrary_metadata"` :
    ///         Does the image file format allow metadata with arbitrary
    ///         names (and either arbitrary, or a reasonable set of, data
    ///         types)? (Versus the file format supporting only a fixed list
    ///         of specific metadata names/values.)
    ///
    ///  - `"exif"`
    ///         Does the image file format support Exif camera data (either
    ///         specifically, or via arbitrary named metadata)?
    ///
    ///  - `"iptc"`
    ///         Does the image file format support IPTC data (either
    ///         specifically, or via arbitrary named metadata)?
    ///
    ///  - `"ioproxy"`
    ///         Does the image file format support writing to an `IOProxy`?
    ///
    /// - `"procedural"` :
    ///       Is this a purely procedural output that doesn't write an
    ///       actual file?
    ///
    /// This list of queries may be extended in future releases. Since this
    /// can be done simply by recognizing new query strings, and does not
    /// require any new API entry points, addition of support for new
    /// queries does not break ``link compatibility'' with
    /// previously-compiled plugins.
    ///
    pub fn supports(&self, feature: &str) -> i32 {
        let mut value = 0;
        unsafe {
            let sv_feature = StringView::from(feature);
            sys::OIIO_ImageOutput_supports(self.ptr, &mut value, sv_feature.0);
        }
        value
    }

    /// Return the text of all pending error messages issued against this
    /// ImageOutput by the calling thread, and clear the pending error
    /// message unless `clear` is false. If no error message is pending, it
    /// will return an empty string.
    ///
    pub fn get_error(&self, clear: bool) -> String {
        let mut msg = CppString::new("");
        unsafe {
            sys::OIIO_ImageOutput_geterror(self.ptr, &mut msg.0, clear);
            msg.as_str().to_string()
        }
    }

    /// Retrieve the current thread-spawning policy.
    ///
    /// The default of 0 means that the global
    /// `attribute("threads")` value should be used (which itself defaults
    /// to using as many threads as cores; see Section `Global Attributes`_).
    ///
    pub fn threads(&self) -> i32 {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageOutput_threads_const(self.ptr, &mut value);
        }
        value
    }

    /// Set the threading policy for this ImageOutput, controlling the
    /// maximum amount of parallelizing thread "fan-out" that might occur
    /// during large read operations. The default of 0 means that the global
    /// `attribute("threads")` value should be used (which itself defaults
    /// to using as many threads as cores; see Section `Global Attributes`_).
    ///
    /// The main reason to change this value is to set it to 1 to indicate
    /// that the calling thread should do all the work rather than spawning
    /// new threads. That is probably the desired behavior in situations
    /// where the calling application has already spawned multiple worker
    /// threads.
    ///
    pub fn set_threads(&self, threads: i32) {
        unsafe {
            sys::OIIO_ImageOutput_threads(self.ptr, threads);
        }
    }
}

impl ImageOutputBase<ImageOutputStateOpened> {
    /// Write the entire image of `spec.width x spec.height x spec.depth`
    /// pixels, from a buffer with the given strides and in the desired
    /// format.
    ///
    /// Depending on the spec, this will write either all tiles or all
    /// scanlines. Assume that data points to a layout in row-major order.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if any error occurs
    ///
    pub fn write_image<T: Pixel>(
        &mut self,
        pixels: &[T],
        write_options: WriteOptions,
    ) -> Result<()> {
        let mut result = false;
        // FIXME: do checking on the length of the buffer based on spec and
        // strides
        unsafe {
            sys::OIIO_ImageOutput_write_image(
                self.ptr,
                &mut result,
                T::FORMAT.into(),
                pixels.as_ptr() as *const c_void,
                write_options.x_stride.0,
                write_options.y_stride.0,
                write_options.z_stride.0,
                std::mem::transmute::<
                    *const (),
                    extern "C" fn(*mut std::os::raw::c_void, f32) -> bool,
                >(std::ptr::null()),
                std::ptr::null_mut(),
            );
        }

        if result {
            Ok(())
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }
}

#[repr(C)]
#[derive(Debug, Copy, Clone, PartialEq, PartialOrd)]
pub enum OpenMode {
    Create,
    AppendSubimage,
    AppendMIPLevel,
}

impl From<OpenMode> for sys::OIIO_ImageOutput_OpenMode {
    fn from(m: OpenMode) -> Self {
        match m {
            OpenMode::Create => sys::OIIO_ImageOutput_OpenMode_Create,
            OpenMode::AppendSubimage => {
                sys::OIIO_ImageOutput_OpenMode_AppendSubimage
            }
            OpenMode::AppendMIPLevel => {
                sys::OIIO_ImageOutput_OpenMode_AppendMIPLevel
            }
        }
    }
}

pub struct WriteOptions {
    pub x_stride: Stride,
    pub y_stride: Stride,
    pub z_stride: Stride,
}

impl Default for WriteOptions {
    fn default() -> Self {
        Self {
            x_stride: Stride::AUTO,
            y_stride: Stride::AUTO,
            z_stride: Stride::AUTO,
        }
    }
}

#[cfg(test)]
mod test {
    use crate as oiio;
    use oiio::error::Error;
    use oiio::imageio::{
        ImageInput, ImageOutput, OpenMode, ReadOptions, WriteOptions,
    };
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

    #[test]
    fn write_image() -> Result<(), Error> {
        let path = Path::new(
            &std::env::var("CARGO_MANIFEST_DIR")
                .expect("CARGO_MANIFEST_DIR not set"),
        )
        .join("images")
        .join("ferris.png");

        let mut ii = ImageInput::open(&path, None, None)?;
        let spec = ii.spec().clone();

        assert_eq!(spec.width(), 1200);
        assert_eq!(spec.height(), 800);
        assert_eq!(spec.nchannels(), 4);

        let mut pixels = vec![
            0u8;
            (spec.width() * spec.height() * spec.nchannels())
                as usize
        ];

        ii.read_image(&mut pixels, ReadOptions::default())?;

        let mut io = ImageOutput::new(
            "ferris.exr",
            &spec,
            OpenMode::Create,
            None,
            None,
        )?;
        io.write_image(&pixels, WriteOptions::default())?;

        Ok(())
    }
}
