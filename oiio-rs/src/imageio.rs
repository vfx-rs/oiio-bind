#[doc=include_str!("imageio.md")]
use crate::cppstd::{
    CppString, CppVectorString, CppVectorStringRef, CppVectorTypeDesc,
    CppVectorTypeDescRef,
};
use crate::error::Error;
use crate::filesystem::IOProxy;
use crate::param_list::ParamValue;
use crate::refptr::{OpaquePtr, Ref, RefMut};
use crate::string_view::StringView;
use crate::traits::{AttributeMetadata, Pixel};
use crate::typedesc::TypeDesc;

use oiio_sys as sys;
use std::convert::TryInto;
use std::ffi::{CStr, CString};
use std::marker::PhantomData;
use std::os::raw::c_void;
use std::path::Path;

type Result<T, E = Error> = std::result::Result<T, E>;

#[derive(Debug, Default, Clone, PartialEq, PartialOrd)]
#[repr(transparent)]
pub struct Stride(pub i64);

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
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Roi {
    pub xbegin: i32,
    pub xend: i32,
    pub ybegin: i32,
    pub yend: i32,
    pub zbegin: i32,
    pub zend: i32,
    pub chbegin: i32,
    pub chend: i32,
}

impl Roi {
    pub fn width(&self) -> usize {
        (self.xend - self.xbegin) as usize
    }

    pub fn height(&self) -> usize {
        (self.yend - self.ybegin) as usize
    }

    pub fn depth(&self) -> usize {
        (self.zend - self.zbegin) as usize
    }

    pub fn num_channels(&self) -> usize {
        (self.chend - self.chbegin) as usize
    }

    pub fn num_pixels(&self) -> usize {
        if self.is_defined() {
            self.width() * self.height() * self.depth()
        } else {
            0
        }
    }

    pub fn is_defined(&self) -> bool {
        self.xbegin == std::i32::MIN
    }

    pub fn all() -> Roi {
        Roi::default()
    }

    pub fn new(
        xbegin: usize,
        xend: usize,
        ybegin: usize,
        yend: usize,
        zbegin: usize,
        zend: usize,
        chbegin: usize,
        chend: usize,
    ) -> Roi {
        Roi {
            xbegin: xbegin.try_into().expect("xbegin out of range for i32"),
            xend: xend.try_into().expect("xend out of range for i32"),
            ybegin: ybegin.try_into().expect("ybegin out of range for i32"),
            yend: yend.try_into().expect("yend out of range for i32"),
            zbegin: zbegin.try_into().expect("zbegin out of range for i32"),
            zend: zend.try_into().expect("zend out of range for i32"),
            chbegin: chbegin.try_into().expect("chbegin out of range for i32"),
            chend: chend.try_into().expect("chend out of range for i32"),
        }
    }

    pub fn new2d(
        xbegin: usize,
        xend: usize,
        ybegin: usize,
        yend: usize,
    ) -> Roi {
        Roi::new(xbegin, xend, ybegin, yend, 0, 1, 0, std::i32::MAX as usize)
    }

    pub fn contains_pixel(
        &self,
        x: usize,
        y: usize,
        z: usize,
        ch: usize,
    ) -> bool {
        let x = x.try_into().expect("x out of range for i32");
        let y = y.try_into().expect("y out of range for i32");
        let z = z.try_into().expect("z out of range for i32");
        let ch = ch.try_into().expect("ch out of range for i32");
        (self.xbegin..self.xend).contains(&x)
            && (self.ybegin..self.yend).contains(&y)
            && (self.zbegin..self.zend).contains(&z)
            && (self.chbegin..self.chend).contains(&ch)
    }

    pub fn contains_roi(&self, rhs: &Roi) -> bool {
        (self.xbegin..=self.xend).contains(&rhs.xbegin)
            && (self.ybegin..=self.yend).contains(&rhs.ybegin)
            && (self.zbegin..=self.zend).contains(&rhs.zbegin)
            && (self.chbegin..=self.chend).contains(&rhs.chbegin)
            && (self.xbegin..=self.xend).contains(&rhs.xend)
            && (self.ybegin..=self.yend).contains(&rhs.yend)
            && (self.zbegin..=self.zend).contains(&rhs.zend)
            && (self.chbegin..=self.chend).contains(&rhs.chend)
    }

    pub fn union(&self, rhs: &Roi) -> Roi {
        Roi {
            xbegin: self.xbegin.min(rhs.xbegin),
            xend: self.xend.max(rhs.xend),
            ybegin: self.ybegin.min(rhs.ybegin),
            yend: self.yend.max(rhs.yend),
            zbegin: self.zbegin.min(rhs.zbegin),
            zend: self.zend.max(rhs.zend),
            chbegin: self.chbegin.min(rhs.chbegin),
            chend: self.chend.max(rhs.chend),
        }
    }

    pub fn intersection(&self, rhs: &Roi) -> Roi {
        Roi {
            xbegin: self.xbegin.max(rhs.xbegin),
            xend: self.xend.min(rhs.xend),
            ybegin: self.ybegin.max(rhs.ybegin),
            yend: self.yend.min(rhs.yend),
            zbegin: self.zbegin.max(rhs.zbegin),
            zend: self.zend.min(rhs.zend),
            chbegin: self.chbegin.max(rhs.chbegin),
            chend: self.chend.min(rhs.chend),
        }
    }
}

impl Default for Roi {
    fn default() -> Self {
        Roi {
            xbegin: std::i32::MIN,
            xend: 0,
            ybegin: 0,
            yend: 0,
            zbegin: 0,
            zend: 0,
            chbegin: 0,
            chend: 0,
        }
    }
}

impl From<Roi> for sys::OIIO_ROI_t {
    fn from(r: Roi) -> Self {
        sys::OIIO_ROI_t {
            xbegin: r.xbegin,
            xend: r.xend,
            ybegin: r.ybegin,
            yend: r.yend,
            zbegin: r.zbegin,
            zend: r.zend,
            chbegin: r.chbegin,
            chend: r.chend,
        }
    }
}

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
        xres: usize,
        yres: usize,
        nchans: usize,
        format: TypeDesc,
    ) -> Self {
        let mut inner = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageSpec_from_dimensions(
                &mut inner,
                xres.try_into().expect("xres out of range"),
                yres.try_into().expect("yres out of range"),
                nchans.try_into().expect("nchans out of range"),
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
            sys::OIIO_ImageSpec_from_roi(
                &mut inner,
                roi as *const Roi as *const sys::OIIO_ROI_t,
                format.into(),
            );
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
    pub fn width(&self) -> usize {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_width(self.0, &mut ptr);
            *ptr as usize
        }
    }

    /// Width of the pixel data window
    ///
    pub fn set_width(&mut self, value: i32) {
        let value = value.try_into().expect("value out of range for i32");
        unsafe {
            sys::OIIO_ImageSpec_set_width(self.0, &value);
        }
    }

    /// Height of the pixel data window
    ///
    pub fn height(&self) -> usize {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_height(self.0, &mut ptr);
            *ptr as usize
        }
    }

    /// Height of the pixel data window
    ///
    pub fn set_height(&mut self, value: usize) {
        let value = value.try_into().expect("value out of range for i32");
        unsafe {
            sys::OIIO_ImageSpec_set_height(self.0, &value);
        }
    }

    /// Depth of the pixel data window
    ///
    pub fn depth(&self) -> usize {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_depth(self.0, &mut ptr);
            *ptr as usize
        }
    }

    /// Depth of the pixel data window
    ///
    pub fn set_depth(&mut self, value: usize) {
        let value = value.try_into().expect("value out of range for i32");
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
    pub fn full_width(&self) -> usize {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_full_width(self.0, &mut ptr);
            *ptr as usize
        }
    }

    /// Width of the display window
    ///
    pub fn set_full_width(&mut self, value: usize) {
        let value = value.try_into().expect("value out of range for i32");
        unsafe {
            sys::OIIO_ImageSpec_set_full_width(self.0, &value);
        }
    }

    /// Height of the display window
    ///
    pub fn full_height(&self) -> usize {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_full_height(self.0, &mut ptr);
            *ptr as usize
        }
    }

    /// Height of the display window
    ///
    pub fn set_full_height(&mut self, value: usize) {
        let value = value.try_into().expect("value out of range for i32");
        unsafe {
            sys::OIIO_ImageSpec_set_full_height(self.0, &value);
        }
    }

    /// Depth of the display window
    ///
    pub fn full_depth(&self) -> usize {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_full_depth(self.0, &mut ptr);
            *ptr as usize
        }
    }

    /// Depth of the display window
    ///
    pub fn set_full_depth(&mut self, value: usize) {
        let value = value.try_into().expect("value out of range for i32");
        unsafe {
            sys::OIIO_ImageSpec_set_full_depth(self.0, &value);
        }
    }

    /// Width of a tile (0 if this is a scanline image)
    ///
    pub fn tile_width(&self) -> usize {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_tile_width(self.0, &mut ptr);
            *ptr as usize
        }
    }

    /// Width of a tile (0 if this is a scanline image)
    ///
    pub fn set_tile_width(&mut self, value: usize) {
        let value = value.try_into().expect("value out of range for i32");
        unsafe {
            sys::OIIO_ImageSpec_set_tile_width(self.0, &value);
        }
    }

    /// Height of a tile (0 if this is a scanline image)    
    ///
    pub fn tile_height(&self) -> usize {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_tile_height(self.0, &mut ptr);
            *ptr as usize
        }
    }

    /// Height of a tile (0 if this is a scanline image)    
    ///
    pub fn set_tile_height(&mut self, value: usize) {
        let value = value.try_into().expect("value out of range for i32");
        unsafe {
            sys::OIIO_ImageSpec_set_tile_height(self.0, &value);
        }
    }

    /// Depth of a tile (0 if this is a scanline image)    
    ///
    pub fn tile_depth(&self) -> usize {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_tile_depth(self.0, &mut ptr);
            *ptr as usize
        }
    }

    /// Depth of a tile (0 if this is a scanline image)    
    ///
    pub fn set_tile_depth(&mut self, value: usize) {
        let value = value.try_into().expect("value out of range for i32");
        unsafe {
            sys::OIIO_ImageSpec_set_tile_depth(self.0, &value);
        }
    }

    /// Number of image channels, e.g. 4 for RGBA
    ///
    pub fn num_channels(&self) -> usize {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_nchannels(self.0, &mut ptr);
            *ptr as usize
        }
    }

    /// Number of image channels, e.g. 4 for RGBA
    ///
    pub fn set_num_channels(&mut self, value: usize) {
        let value = value.try_into().expect("value out of range for i32");
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
    pub fn channel_formats(&self) -> CppVectorTypeDescRef {
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
    pub fn set_channel_formats(&mut self, value: &[TypeDesc]) {
        unsafe {
            let vec = CppVectorTypeDesc::from_slice(value);
            sys::OIIO_ImageSpec_set_channelformats(self.0, vec.0);
        }
    }

    /// The names of each channel, in order. Typically this will be "R",
    /// "G", "B", "A" (alpha), "Z" (depth), or other arbitrary names.
    ///
    pub fn channel_names(&self) -> CppVectorStringRef {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_channelnames(self.0, &mut ptr);
        }
        CppVectorStringRef::new(ptr)
    }

    /// The names of each channel, in order. Typically this will be "R",
    /// "G", "B", "A" (alpha), "Z" (depth), or other arbitrary names.
    ///
    pub fn set_channel_names<S: AsRef<str>>(&mut self, value: &[S]) {
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
    pub fn z_channel(&self) -> Option<usize> {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageSpec_get_nchannels(self.0, &mut ptr);
            // "None" is represented by -1 on the C++ side
            if *ptr == -1 {
                None
            } else {
                Some(*ptr as usize)
            }
        }
    }

    /// The index of the channel that represents `z` (depth)
    ///
    /// Pass None if there is no z channel in the image
    ///
    pub fn set_z_channel(&mut self, value: Option<usize>) {
        // "None" is represented by -1 on the C++ side
        let value = if let Some(value) = value {
            value.try_into().expect("value out of range for i32")
        } else {
            -1
        };
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
    pub fn channel_bytes_for_channel(
        &self,
        index: usize,
        native: bool,
    ) -> usize {
        let mut value = 0;
        let index = index.try_into().expect("index out of range for i32");
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
        chbegin: usize,
        chend: usize,
        native: bool,
    ) -> usize {
        let mut value = 0;
        let chbegin = chbegin.try_into().expect("chbegin out of range for i32");
        let chend = chend.try_into().expect("chend out of range for i32");
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
    ///
    pub fn scanline_bytes(&self, native: bool) -> Option<usize> {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageSpec_scanline_bytes(self.0, &mut value, native);
            if value == std::u64::MAX {
                None
            } else {
                Some(value as usize)
            }
        }
    }

    /// Return the number of pixels comprising a tile, or 0 if it is not a
    /// tiled image.  
    ///
    /// This will return None in the event of an overflow where it's not
    /// representable in an `ImageSize`
    ///
    pub fn tile_pixels(&self) -> Option<usize> {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageSpec_tile_pixels(self.0, &mut value);
            if value == std::u64::MAX {
                None
            } else {
                Some(value as usize)
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
    pub fn tile_bytes(&self, native: bool) -> Option<usize> {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageSpec_tile_bytes(self.0, &mut value, native);
            if value == std::u64::MAX {
                None
            } else {
                Some(value as usize)
            }
        }
    }

    /// Return the number of pixels comprising the whole image.
    ///
    /// This will return None in the event of an overflow where it's not
    /// representable in an `ImageSize`
    ///
    pub fn image_pixels(&self) -> Option<usize> {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageSpec_image_pixels(self.0, &mut value);
            if value == std::u64::MAX {
                None
            } else {
                Some(value as usize)
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
    pub fn image_bytes(&self, native: bool) -> Option<usize> {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageSpec_image_bytes(self.0, &mut value, native);
            if value == std::u64::MAX {
                None
            } else {
                Some(value as usize)
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
        let sv = StringView::from(name.as_ref());

        unsafe {
            sys::OIIO_ImageSpec_attribute(
                self.0,
                sv.0,
                A::TYPE.into(),
                attribute.ptr(),
            );
        }
    }

    /// Return the type of the named attribute, or None if it is not found.
    ///
    pub fn get_attribute_type(
        &self,
        name: &str,
        case_sensitive: bool,
    ) -> Option<TypeDesc> {
        let mut result = TypeDesc::UNKNOWN;
        unsafe {
            sys::OIIO_ImageSpec_getattributetype(
                self.0,
                &mut result as *mut _ as *mut sys::OIIO_TypeDesc_t,
                StringView::from(name).into(),
                case_sensitive,
            );
        }
        if result == TypeDesc::UNKNOWN {
            None
        } else {
            Some(result)
        }
    }

    /// If an attribute named `name` exists with type `A`, return it, otherwise
    /// return None
    ///
    pub fn get_attribute<A: AttributeMetadata>(
        &self,
        name: &str,
        case_sensitive: bool,
    ) -> Option<A> {
        let mut ok = false;
        let mut result = A::default();
        let sv = StringView::from(name.as_ref());
        unsafe {
            sys::OIIO_ImageSpec_getattribute(
                self.0,
                &mut ok,
                sv.into(),
                A::TYPE.into(),
                result.ptr_mut(),
                case_sensitive,
            );
        }

        if ok {
            Some(result)
        } else {
            None
        }
    }

    /// Retrieve the named metadata attribute and return its value as an
    /// `i32`.
    ///
    /// Any integer type will convert to `i32` by truncation or
    /// expansion, string data will parsed into an `i32` if its contents
    /// consist of of the text representation of one integer. Floating point
    /// data will not succeed in converting to an `i32`. If no such metadata
    /// exists, or are of a type that cannot be converted, the `default`
    /// will be returned.
    ///
    pub fn get_attribute_as_i32_or(&self, name: &str, default: i32) -> i32 {
        let mut result = default;
        unsafe {
            let sv = StringView::from(name.as_ref());
            sys::OIIO_ImageSpec_get_int_attribute(
                self.0,
                &mut result,
                sv.0,
                default,
            );
        }
        result
    }

    /// Retrieve the named metadata attribute and return its value as an
    /// `f32`.
    ///
    /// Any integer type will convert to `f32` by truncation or
    /// expansion, string data will parsed into an `f32` if its contents
    /// consist of of the text representation of one integer. Floating point
    /// data will not succeed in converting to an `f32`. If no such metadata
    /// exists, or are of a type that cannot be converted, the `default`
    /// will be returned.
    ///
    pub fn get_attribute_as_f32_or(&self, name: &str, default: f32) -> f32 {
        let mut result = default;
        unsafe {
            let sv = StringView::from(name.as_ref());
            sys::OIIO_ImageSpec_get_float_attribute(
                self.0,
                &mut result,
                sv.0,
                default,
            );
        }
        result
    }

    /// Retrieve any metadata attribute, converted to a string.
    /// If no such metadata exists, the `defaultval` will be returned.
    ///
    pub fn get_attribute_as_str(&self, name: &str, default: &str) -> &str {
        unsafe {
            let sv = StringView::from(name);
            let mut sv_result = sys::OIIO_string_view_t::default();
            let sv_default = StringView::from(default);
            sys::OIIO_ImageSpec_get_string_attribute(
                self.0,
                &mut sv_result,
                sv.into(),
                sv_default.0,
            );

            let mut len = 0;
            let mut ptr = std::ptr::null();
            sys::OIIO_string_view_c_str(&sv_result, &mut ptr);
            sys::OIIO_string_view_length(&sv_result, &mut len);

            std::str::from_utf8_unchecked(std::slice::from_raw_parts(
                ptr as *const u8,
                len as usize,
            ))
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

    /// For a given parameter `p`, format the value nicely as a string.  If
    /// `human` is true, use especially human-readable explanations (units,
    /// or decoding of values) for certain known metadata.
    ///
    pub fn metadata_val(p: &ParamValue, human: bool) -> String {
        let mut s = CppString::new("");
        unsafe {
            sys::OIIO_ImageSpec_metadata_val(&mut s.0, &p.0, human);
        }
        s.as_str().to_string()
    }

    /// Returns, as a String, a serialized version of this ImageSpec.
    ///
    pub fn serialize(
        &self,
        format: SerialFormat,
        verbose: SerialVerbose,
    ) -> String {
        let mut s = CppString::new("");
        unsafe {
            sys::OIIO_ImageSpec_serialize(
                self.0,
                &mut s.0,
                format.into(),
                verbose.into(),
            );
        }
        s.as_str().to_string()
    }

    /// Converts the contents of the `ImageSpec` to an XML string.
    ///
    pub fn to_xml(&self) -> String {
        let mut s = CppString::new("");
        unsafe {
            sys::OIIO_ImageSpec_to_xml(self.0, &mut s.0);
        }
        s.as_str().to_string()
    }

    /// Populates the fields of the `ImageSpec` based on the XML passed in.
    ///
    pub fn from_xml(&mut self, xml: &str) {
        let cxml = CString::new(xml).expect("could not convert xml to CString");
        unsafe {
            sys::OIIO_ImageSpec_from_xml(self.0, cxml.as_ptr());
        }
    }

    /// Hunt for the "Compression" and "CompressionQuality" settings in the
    /// spec and turn them into the compression name and quality. This
    /// handles compression name/qual combos of the form "name:quality".
    ///
    pub fn decode_compression_metadata(
        &self,
        default_compression: Option<&str>,
        default_quality: Option<i32>,
    ) -> (&str, i32) {
        let dc = if let Some(dc) = default_compression {
            StringView::from(dc)
        } else {
            StringView::from("")
        };

        let dq = if let Some(dq) = default_quality {
            dq
        } else {
            -1
        };

        let mut p = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageSpec_decode_compression_metadata(
                self.0, &mut p, dc.0, dq,
            );

            let mut sv_ptr = std::ptr::null();
            let mut i_ptr = std::ptr::null();
            sys::std_pair_string_int_get_first(p, &mut sv_ptr);
            sys::std_pair_string_int_get_second(p, &mut i_ptr);

            let mut char_ptr = std::ptr::null();
            let mut len = 0;
            sys::OIIO_string_view_c_str(sv_ptr, &mut char_ptr);
            sys::OIIO_string_view_length(sv_ptr, &mut len);

            (
                std::str::from_utf8_unchecked(std::slice::from_raw_parts(
                    char_ptr as *const u8,
                    len as usize,
                )),
                *i_ptr,
            )
        }
    }

    /// Helper function to verify that the given pixel range exactly covers
    /// a set of tiles.  Also returns false if the spec indicates that the
    /// image isn't tiled at all.
    ///
    /// # Panics
    /// * If any of the arguments are not representable in an i32
    ///
    pub fn valid_tile_range(
        &self,
        xbegin: usize,
        xend: usize,
        ybegin: usize,
        yend: usize,
        zbegin: usize,
        zend: usize,
    ) -> bool {
        let mut result = false;
        unsafe {
            sys::OIIO_ImageSpec_valid_tile_range(
                self.0,
                &mut result,
                xbegin.try_into().expect("xbegin not in range for i32"),
                xend.try_into().expect("xend not in range for i32"),
                ybegin.try_into().expect("ybegin not in range for i32"),
                yend.try_into().expect("yend not in range for i32"),
                zbegin.try_into().expect("zbegin not in range for i32"),
                zend.try_into().expect("zend not in range for i32"),
            );
        }
        result
    }

    /// Return the format of the given channel.
    ///
    /// Returns [`format()`](ImageSpec::format) if `chan` is not a valid channel
    /// index
    ///
    /// # Panics
    /// * If `chan` is not representable in an i32
    ///
    pub fn channel_format(&self, chan: usize) -> TypeDesc {
        let mut td = TypeDesc::UNKNOWN;
        unsafe {
            sys::OIIO_ImageSpec_channelformat(
                self.0,
                &mut td as *mut _ as *mut sys::OIIO_TypeDesc_t,
                chan.try_into().expect("chan is outside range for i32"),
            );
        }
        td
    }

    /// Return the name of the given channel.
    ///
    /// Returns an empty string if `chan` is not a valid channel
    /// index
    ///
    /// # Panics
    /// * If `chan` is not representable in an i32
    ///
    pub fn channel_name(&self, chan: usize) -> &str {
        let mut sv = sys::OIIO_string_view_t::default();
        unsafe {
            sys::OIIO_ImageSpec_channel_name(
                self.0,
                &mut sv,
                chan.try_into().expect("chan is outside range for i32"),
            );

            let mut char_ptr = std::ptr::null();
            let mut len = 0;
            sys::OIIO_string_view_c_str(&sv, &mut char_ptr);
            sys::OIIO_string_view_length(&sv, &mut len);

            std::str::from_utf8_unchecked(std::slice::from_raw_parts(
                char_ptr as *const u8,
                len as usize,
            ))
        }
    }

    /// Get the index of `channel_name`, returning None if not found.
    ///
    pub fn channel_index(&self, channel_name: &str) -> Option<usize> {
        let mut index = 0;
        unsafe {
            sys::OIIO_ImageSpec_channelindex(
                self.0,
                &mut index,
                StringView::from(channel_name).into(),
            );
        }
        if index < 0 {
            None
        } else {
            Some(index as usize)
        }
    }

    /// Return the data window as an Roi
    ///
    pub fn roi(&self) -> Roi {
        let mut r = Roi::default();
        unsafe {
            sys::OIIO_ImageSpec_roi(
                self.0,
                &mut r as *mut _ as *mut sys::OIIO_ROI_t,
            );
        }
        r
    }

    /// Return the display window as an Roi
    ///
    pub fn roi_full(&self) -> Roi {
        let mut r = Roi::default();
        unsafe {
            sys::OIIO_ImageSpec_roi_full(
                self.0,
                &mut r as *mut _ as *mut sys::OIIO_ROI_t,
            );
        }
        r
    }

    /// Set the data window of this spec.
    ///
    /// Note the channel range is ignored and the channels set in the spec are
    /// not changed
    ///
    pub fn set_roi(&mut self, roi: &Roi) {
        unsafe {
            sys::OIIO_ImageSpec_set_roi(
                self.0,
                roi as *const _ as *const sys::OIIO_ROI_t,
            );
        }
    }

    /// Set the display window of this spec.
    ///
    /// Note the channel range is ignored and the channels set in the spec are
    /// not changed
    ///
    pub fn set_roi_full(&mut self, roi: &Roi) {
        unsafe {
            sys::OIIO_ImageSpec_set_roi_full(
                self.0,
                roi as *const _ as *const sys::OIIO_ROI_t,
            );
        }
    }
}

#[derive(Debug, Copy, Clone, PartialEq, PartialOrd)]
pub enum SerialFormat {
    Text,
    Xml,
}

impl From<SerialFormat> for sys::OIIO_ImageSpec_SerialFormat {
    fn from(s: SerialFormat) -> Self {
        match s {
            SerialFormat::Text => sys::OIIO_ImageSpec_SerialFormat_SerialText,
            SerialFormat::Xml => sys::OIIO_ImageSpec_SerialFormat_SerialXML,
        }
    }
}

#[derive(Debug, Copy, Clone, PartialEq, PartialOrd)]
pub enum SerialVerbose {
    Brief,
    Detailed,
    DetailedHuman,
}

impl From<SerialVerbose> for sys::OIIO_ImageSpec_SerialVerbose {
    fn from(s: SerialVerbose) -> Self {
        match s {
            SerialVerbose::Brief => {
                sys::OIIO_ImageSpec_SerialVerbose_SerialBrief
            }
            SerialVerbose::Detailed => {
                sys::OIIO_ImageSpec_SerialVerbose_SerialDetailed
            }
            SerialVerbose::DetailedHuman => {
                sys::OIIO_ImageSpec_SerialVerbose_SerialDetailedHuman
            }
        }
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

/// ImageInput can read any format that OIIO or its plugins support
///
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
    ///     (spec.width() * spec.height() * spec.num_channels())
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
        subimage: usize,
        miplevel: usize,
    ) -> Result<ImageSpec> {
        let mut ptr = std::ptr::null_mut();
        let subimage =
            subimage.try_into().expect("subimage out of range for i32");
        let miplevel =
            miplevel.try_into().expect("miplevel out of range for i32");
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
        subimage: usize,
        miplevel: usize,
    ) -> Result<ImageSpec> {
        let mut ptr = std::ptr::null_mut();
        let subimage =
            subimage.try_into().expect("subimage out of range for i32");
        let miplevel =
            miplevel.try_into().expect("miplevel out of range for i32");
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
    pub fn current_subimage(&self) -> usize {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageInput_current_subimage(self.ptr, &mut value);
        }
        value as usize
    }

    /// Returns the index of the MIPmap image that is currently being read.
    /// The highest-res MIP level (or the only level, if there is just
    /// one) is number 0.
    ///
    pub fn current_miplevel(&self) -> usize {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageInput_current_miplevel(self.ptr, &mut value);
        }
        value as usize
    }

    /// Seek to the given subimage and MIP-map level within the open image
    /// file.  The first subimage of the file has index 0, the highest-
    /// resolution MIP level has index 0.  The new subimage's vital
    /// statistics=may be retrieved by [`spec()`](ImageInput::spec).
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if the `subimage` and/or `miplevel` could not be found
    ///
    /// # Panics
    /// * If `subimage` or `miplevel` are not representable as an i32
    ///
    pub fn seek_subimage(
        &self,
        subimage: usize,
        miplevel: usize,
    ) -> Result<()> {
        let mut result = false;
        unsafe {
            sys::OIIO_ImageInput_seek_subimage(
                self.ptr,
                &mut result,
                subimage
                    .try_into()
                    .expect("subimage is not representable as i32"),
                miplevel
                    .try_into()
                    .expect("miplevel is not representable as i32"),
            );
        }
        if result {
            Ok(())
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
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
    pub fn threads(&self) -> usize {
        let mut value = 0;
        unsafe {
            sys::OIIO_ImageInput_threads_const(self.ptr, &mut value);
        }
        value as usize
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
    pub fn set_threads(&self, threads: usize) {
        let threads = threads.try_into().expect("threads out of range for i32");
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
    pub fn read_image<T: Pixel>(
        &mut self,
        pixels: &mut [T],
        read_options: ReadOptions,
    ) -> Result<()> {
        let spec = self.spec();
        let chend = read_options
            .chend
            .clamp(read_options.chbegin + 1, spec.num_channels());
        let nchannels = chend - read_options.chbegin;
        let num_pixels = spec.width() * spec.height() * nchannels;

        if pixels.len() < num_pixels as usize {
            return Err(Error::BufferTooSmall);
        }

        unsafe {
            self._read_image_impl(
                read_options.subimage,
                read_options.miplevel,
                read_options.chbegin,
                chend,
                T::FORMAT.into(),
                pixels.as_mut_ptr() as *mut std::os::raw::c_void,
                read_options.x_stride,
                read_options.y_stride,
                read_options.z_stride,
                std::mem::transmute::<*const (), ProgressCallback>(
                    std::ptr::null(),
                ),
                std::ptr::null_mut(),
            )
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
    /// may be passed as a closure taking a single f32 which specifies the
    /// proportion of the file read between 0 and 1. Returning `true` from this
    /// closure will cause the read to be aborted, while `false` will let it
    /// continue.
    ///
    pub fn read_image_with_progress<T: Pixel, F: FnMut(f32) -> bool>(
        &mut self,
        pixels: &mut [T],
        read_options: ReadOptions,
        progress_callback: F,
    ) -> Result<()> {
        let spec = self.spec();
        let chend = read_options
            .chend
            .clamp(read_options.chbegin + 1, spec.num_channels());
        let nchannels = chend - read_options.chbegin;
        let num_pixels = spec.width() * spec.height() * nchannels;

        if pixels.len() < num_pixels as usize {
            return Err(Error::BufferTooSmall);
        }

        let mut progress_callback = progress_callback;
        let trampoline = get_trampoline(&progress_callback);

        unsafe {
            self._read_image_impl(
                read_options.subimage,
                read_options.miplevel,
                read_options.chbegin,
                chend,
                T::FORMAT.into(),
                pixels.as_mut_ptr() as *mut std::os::raw::c_void,
                read_options.x_stride,
                read_options.y_stride,
                read_options.z_stride,
                trampoline,
                &mut progress_callback as *mut _ as *mut c_void,
            )
        }
    }

    unsafe fn _read_image_impl(
        &mut self,
        subimage: usize,
        miplevel: usize,
        chbegin: usize,
        chend: usize,
        format: TypeDesc,
        pixels: *mut c_void,
        x_stride: Stride,
        y_stride: Stride,
        z_stride: Stride,
        progress_callback: ProgressCallback,
        progress_callback_data: *mut c_void,
    ) -> Result<()> {
        let mut result = false;
        let subimage =
            subimage.try_into().expect("subimage out of range for i32");
        let miplevel =
            miplevel.try_into().expect("miplevel out of range for i32");
        let chbegin = chbegin.try_into().expect("chbegin out of range for i32");
        let chend = chend.try_into().expect("chend out of range for i32");
        sys::OIIO_ImageInput_read_image(
            self.ptr,
            &mut result,
            subimage,
            miplevel,
            chbegin,
            chend,
            format.into(),
            pixels,
            x_stride.0,
            y_stride.0,
            z_stride.0,
            progress_callback,
            progress_callback_data,
        );

        if !result {
            let mut msg = CppString::new("");
            sys::OIIO_ImageInput_geterror(self.ptr, &mut msg.0, true);
            return Err(Error::Oiio(msg.as_str().to_string()));
        }

        Ok(())
    }

    /// Read the scanline that includes pixels `(*,y,z)` from the current
    /// subimage and MIP level.  
    ///
    /// The `x_stride` value gives the distance between successive pixels (in bytes).
    /// Strides set to `Stride::AUTO` imply "contiguous" data.
    ///
    /// @note This variety of `read_scanline` is not re-entrant nor
    /// thread-safe. If you require concurrent reads to the same open
    /// ImageInput, you should use `read_scanlines`
    ///
    /// # Parameters
    /// * `y/z` - The y & z coordinates of the scanline. For 2D
    ///                     images, z should be 0.
    /// * `format` - A TypeDesc describing the type of `data`.
    /// * `data` - Pointer to the pixel data buffer.
    /// * `x_stride` - The distance in bytes between successive pixels in `data`
    /// (or `Stride::AUTO`).
    ///
    /// # Errors
    /// * [`Error::BufferTooSmall`] - if `pixels` is not big enough to hold the
    /// requested `x_stride`
    /// * [`Error::Oiio`] - if any other error occurs
    ///
    /// # Panics
    /// * if `y` or `z` are not representable as an i32.
    ///
    pub fn read_scanline<T: Pixel>(
        &mut self,
        y: usize,
        z: usize,
        pixels: &mut [T],
        x_stride: Stride,
    ) -> Result<()> {
        let mut result = false;

        let xs = if x_stride == Stride::AUTO {
            std::mem::size_of::<T>() * self.spec().num_channels()
        } else {
            x_stride.0 as usize
        };
        let scanline_bytes = self.spec().width() * xs;
        let slice_bytes = pixels.len() * std::mem::size_of::<T>();
        if slice_bytes < scanline_bytes {
            return Err(Error::BufferTooSmall);
        }

        unsafe {
            sys::OIIO_ImageInput_read_scanline(
                self.ptr,
                &mut result,
                y.try_into().expect("y is not representable as i32"),
                z.try_into().expect("z is not representable as i32"),
                T::FORMAT.into(),
                pixels.as_ptr() as *mut T as *mut c_void,
                x_stride.0,
            );
        }

        Ok(())
    }

    /// Read multiple scanlines that include pixels `(*,y,z)` for all `ybegin
    /// <= y < yend` in the specified subimage and mip level, into `pixels`,
    /// using the strides given and converting to the type of `pixels`.
    /// Only channels `[chbegin,chend)` will be read/copied.
    ///
    /// # Parameters
    /// *  `subimage` - The subimage to read from (starting with 0).
    /// *  `miplevel` - The MIP level to read (0 is the highest
    /// resolution level).
    /// *  `ybegin`/`yend` - The y range of the scanlines being passed.
    /// *  `z` - The z coordinate of the scanline.
    /// *  `chbegin`/`chend` The channel range to read.
    /// *  `format` - A TypeDesc describing the type of `data`.
    /// *  `data` - Pointer to the pixel data.
    /// *  `xstride`/`ystride` - The distance in bytes between successive pixels
    /// and scanlines (or `AutoStride`).
    ///
    /// # Errors
    /// * [`Error::BufferTooSmall`] - if `pixels` is not big enough to hold the
    /// requested rectangle
    /// * [`Error::Oiio`] - if any other error occurs
    ///
    /// # Panics
    /// * if any of the usize parameters are not representable as an i32.
    ///
    ///
    pub fn read_scanlines<T: Pixel>(
        &self,
        subimage: usize,
        miplevel: usize,
        ybegin: usize,
        yend: usize,
        z: usize,
        chbegin: usize,
        chend: usize,
        pixels: &mut [T],
        x_stride: Stride,
        y_stride: Stride,
    ) -> Result<()> {
        let ch = (chend - chbegin).min(self.spec().num_channels());

        let xs = if x_stride == Stride::AUTO {
            std::mem::size_of::<T>() * ch
        } else {
            x_stride.0 as usize
        };

        let scanline_bytes = self.spec().width() * xs;

        let ys = if y_stride == Stride::AUTO {
            scanline_bytes
        } else {
            y_stride.0 as usize
        };

        let rect_bytes = ys * (yend - ybegin);
        let pixels_bytes = pixels.len() * std::mem::size_of::<T>();

        if pixels_bytes < rect_bytes {
            return Err(Error::BufferTooSmall);
        }

        let mut result = false;
        unsafe {
            let subimage = subimage
                .try_into()
                .expect("subimage is not representable as i32");
            let miplevel = miplevel
                .try_into()
                .expect("miplevel is not representable as i32");
            let ybegin = ybegin
                .try_into()
                .expect("ybegin is not representable as i32");
            let yend =
                yend.try_into().expect("yend is not representable as i32");
            let z = z.try_into().expect("z is not representable as i32");
            let chbegin = chbegin
                .try_into()
                .expect("chbegin is not representable as i32");
            let chend =
                chend.try_into().expect("chend is not representable as i32");

            sys::OIIO_ImageInput_read_scanlines(
                self.ptr,
                &mut result,
                subimage,
                miplevel,
                ybegin,
                yend,
                z,
                chbegin,
                chend,
                T::FORMAT.into(),
                pixels.as_mut_ptr() as *mut c_void,
                x_stride.0,
                y_stride.0,
            );
        }

        if result {
            Ok(())
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }

    /// Read the tile whose upper-left origin is `(x,y,z)` into `pixels`,
    /// converting if necessary from the native data format of the file into
    /// the type of `pixels`. 
    ///
    /// The stride values give the data spacing of adjacent pixels, scanlines, 
    /// and volumetric slices (measured in bytes). 
    /// Strides set to AutoStride imply 'contiguous' data in the shape of a full tile.
    ///
    /// @note This variety of `read_tile` is not re-entrant nor thread-safe.
    /// If you require concurrent reads to the same open ImageInput, you
    /// should use [`read_tiles()`](ImageInput::read_tiles).
    ///
    /// # Parameters
    /// *  `x/y/z` - The upper left coordinate of the tile being passed.
    /// *  `pixels` - Slice of pixels to write into
    /// *  `xstride/ystride/zstride` The distance in bytes between successive pixels,
    /// scanlines, and image planes (or `AutoStride` to
    /// indicate a "contiguous" single tile).
    ///
    /// # Errors
    /// * [`Error::BufferTooSmall`] - if `pixels` is not big enough to hold the
    /// requested rectangle
    /// * [`Error::Oiio`] - if any other error occurs, including the image not
    /// being tiled, or `(x, y, z)` not being the upper-left corner of a tile
    ///
    /// # Panics
    /// * if any of the usize parameters are not representable as an i32.
    ///
    pub fn read_tile<T: Pixel>(
        &mut self,
        x: usize,
        y: usize,
        z: usize,
        pixels: &mut [T],
        strides: Strides,
    ) -> Result<()> {
        let xs = if strides.x_stride == Stride::AUTO {
            std::mem::size_of::<T>() * self.spec().num_channels()
        } else {
            strides.x_stride.0 as usize
        };

        let ys = if strides.y_stride == Stride::AUTO {
            xs * self.spec().tile_width()
        } else {
            strides.y_stride.0 as usize
        };

        let zs = if strides.z_stride == Stride::AUTO {
            ys * self.spec().tile_height()
        } else {
            strides.z_stride.0 as usize
        };

        let tile_bytes = zs * self.spec().tile_depth();
        let pixels_bytes = pixels.len() * std::mem::size_of::<T>();

        if pixels_bytes < tile_bytes {
            return Err(Error::BufferTooSmall);
        }

        let x = x.try_into().expect("x is not representable as i32");
        let y = y.try_into().expect("y is not representable as i32");
        let z = z.try_into().expect("z is not representable as i32");

        let mut result = false;
        unsafe {
            sys::OIIO_ImageInput_read_tile(
                self.ptr,
                &mut result,
                x,
                y,
                z,
                T::FORMAT.into(),
                pixels.as_mut_ptr() as *mut c_void,
                strides.x_stride.0,
                strides.y_stride.0,
                strides.z_stride.0,
            );
        }

        if result {
            Ok(())
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }

    /// Read the block of multiple tiles that include all pixels in `[xbegin,xend) X [ybegin,yend) X [zbegin,zend)`.
    ///
    /// This is analogous to calling `read_tile(x,y,z,...)` for each tile
    /// in turn (but for some file formats, reading multiple tiles may allow
    /// it to read more efficiently or in parallel).
    ///
    /// The begin/end pairs must correctly delineate tile boundaries, with
    /// the exception that it may also be the end of the image data if the
    /// image resolution is not a whole multiple of the tile size. The
    /// stride values give the data spacing of adjacent pixels, scanlines,
    /// and volumetric slices (measured in bytes). Strides set to AutoStride
    /// imply contiguous data in the shape of the [begin,end) region.
    ///
    /// * `subimage` -   The subimage to read from (starting with 0).
    /// * `miplevel` - The MIP level to read (0 is the highest resolution level).
    /// * `xbegin/xend` - The x range of the pixels covered by the group of tiles being read.
    /// * `ybegin/yend` - The y range of the pixels covered by the tiles.
    /// * `zbegin/zend` - The z range of the pixels covered by the tiles (for a 2D image, zbegin=0 and zend=1).
    /// * `chbegin/chend` - The channel range to read.
    /// * `pixels` - Slice of pixels to write into.
    /// * `xstride/ystride/zstride` The distance in bytes between successive pixels, scanlines, and image planes (or `AutoStride`).
    ///
    pub fn read_tiles<T: Pixel>(
        &self,
        subimage: usize,
        miplevel: usize,
        xbegin: usize,
        xend: usize,
        ybegin: usize,
        yend: usize,
        zbegin: usize,
        zend: usize,
        chbegin: usize,
        chend: usize,
        pixels: &mut [T],
        strides: Strides,
    ) -> Result<()> {
        let width = (xend - xbegin).min(self.spec().width());
        let height = (yend - ybegin).min(self.spec().height());
        let depth = (zend - zbegin).min(self.spec().depth());
        let chan = (chend - chbegin).min(self.spec().num_channels());

        let xs = if strides.x_stride == Stride::AUTO {
            std::mem::size_of::<T>() * chan
        } else {
            strides.x_stride.0 as usize
        };

        let ys = if strides.y_stride == Stride::AUTO {
            xs * width
        } else {
            strides.y_stride.0 as usize
        };

        let zs = if strides.z_stride == Stride::AUTO {
            ys * height
        } else {
            strides.z_stride.0 as usize
        };

        let tile_bytes = zs * depth;
        let pixels_bytes = pixels.len() * std::mem::size_of::<T>();

        if pixels_bytes < tile_bytes {
            return Err(Error::BufferTooSmall);
        }

        let subimage = subimage.try_into().expect("subimage is not representable as i32");
        let miplevel = miplevel.try_into().expect("miplevel is not representable as i32");
        let xbegin = xbegin.try_into().expect("xbegin is not representable as i32");
        let xend = xend.try_into().expect("xend is not representable as i32");
        let ybegin = ybegin.try_into().expect("ybegin is not representable as i32");
        let yend = yend.try_into().expect("yend is not representable as i32");
        let zbegin = zbegin.try_into().expect("zbegin is not representable as i32");
        let zend = zend.try_into().expect("zend is not representable as i32");
        let chbegin = chbegin.try_into().expect("chbegin is not representable as i32");
        let chend = chend.try_into().expect("chend is not representable as i32");

        let mut result = false;
        unsafe {
            sys::OIIO_ImageInput_read_tiles(
                self.ptr,
                &mut result,
                subimage,
                miplevel,
                xbegin,
                xend,
                ybegin,
                yend,
                zbegin,
                zend,
                chbegin,
                chend,
                T::FORMAT.into(),
                pixels.as_mut_ptr() as *mut c_void,
                strides.x_stride.0,
                strides.y_stride.0,
                strides.z_stride.0,
            );
        }

        if result {
            Ok(())
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }
}

pub type ProgressCallback = extern "C" fn(*mut c_void, f32) -> bool;

pub(crate) extern "C" fn progress_tramp<F>(
    user_data: *mut c_void,
    progress: f32,
) -> bool
where
    F: FnMut(f32) -> bool,
{
    unsafe {
        let user_data = &mut *(user_data as *mut F);
        user_data(progress)
    }
}

pub fn get_trampoline<F>(_closure: &F) -> ProgressCallback
where
    F: FnMut(f32) -> bool,
{
    progress_tramp::<F>
}

pub struct ReadOptions {
    pub subimage: usize,
    pub miplevel: usize,
    pub chbegin: usize,
    pub chend: usize,
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
            chend: std::i32::MAX as usize,
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

/// ImageOutputBase is equivalent to ImageOutput in the C++ library.
///
/// We use the typestate pattern here to make invalid sequences of API calls
/// impossible under the type system. For instance, creating an ImageOutput with create(), then
/// attempting to call any of the write() methods on it will lead to a SIGFPE at best.
/// So we move the writing methods to [`ImageOutputBase<ImageOutputStateOpened>`], which can only be
/// created by calling open(), at which point the write() methods are valid to call.
///
/// We use a type alias:
/// `pub type ImageOutput = ImageOutputBase<ImageOutputStateClosed>` to keep the API looking the
/// same when reading the code.
///
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
pub type ImageOutputOpened = ImageOutputBase<ImageOutputStateOpened>;

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

    /// Create a new ImageOutput, opening the file at `filename` with `spec` and
    /// `mode`.
    ///
    /// This is equivalent to calling [`create()`](ImageOutputBase::create) and then
    /// [`open()`](ImageOutputBase::open)
    ///
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
    /// Return a reference to the image format specification of the current
    /// subimage.  
    ///
    pub fn spec(&self) -> ImageSpecRef {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ImageOutput_spec(self.ptr, &mut ptr);
        }
        ImageSpecRef::new(ptr)
    }

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
        strides: Strides,
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
                strides.x_stride.0,
                strides.y_stride.0,
                strides.z_stride.0,
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

    /// Write the full scanline that includes pixels `(*,y,z)`.  
    ///
    /// For 2D non-volume images, `z` should be 0. The `x_stride` value gives the
    /// distance between successive pixels (in bytes).  Strides set to
    /// `Stride::AUTO` imply "contiguous" data.
    ///
    /// # Errors
    /// * [`Error::BufferTooSmall`] - if the `pixels` slice is too small for the
    /// requested `stride`.
    /// * [`Error::Oiio`] - if any other error occurs
    ///
    /// # Panics
    /// If `y` or `z` are outside of the range of an i32
    ///
    pub fn write_scanline<T: Pixel>(
        &mut self,
        y: usize,
        z: usize,
        pixels: &[T],
        x_stride: Stride,
    ) -> Result<()> {
        let mut result = false;

        let write_byte_size = self.spec().width() as usize
            * std::mem::size_of::<T>()
            * x_stride.0.abs() as usize;
        let slice_byte_size = pixels.len() * std::mem::size_of::<T>();
        if slice_byte_size < write_byte_size {
            return Err(Error::BufferTooSmall);
        }

        unsafe {
            sys::OIIO_ImageOutput_write_scanline(
                self.ptr,
                &mut result,
                y.try_into().expect("y out of range"),
                z.try_into().expect("z out of range"),
                T::FORMAT.into(),
                pixels.as_ptr() as *const c_void,
                x_stride.0,
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

#[derive(Default, Debug, Clone, PartialEq, PartialOrd)]
pub struct Strides {
    pub x_stride: Stride,
    pub y_stride: Stride,
    pub z_stride: Stride,
}

#[cfg(test)]
mod test {
    use crate as oiio;
    use oiio::Error;
    use std::path::Path;

    #[test]
    fn test_imagespec_metadata() -> Result<(), Error> {
        use oiio::prelude::*;

        let mut spec = ImageSpec::from_dimensions(256, 128, 4, TypeDesc::FLOAT);

        spec.set_attribute("attr_i32", &17i32);
        assert_eq!(spec.get_attribute::<i32>("attr_i32", true), Some(17i32));

        spec.set_attribute("attr_i32[]", &[17i32, 18, 19, 20]);
        assert_eq!(
            spec.get_attribute::<[i32; 4]>("attr_i32[]", true),
            Some([17i32, 18, 19, 20])
        );

        spec.set_attribute("attr_f32", &42.0f32);
        assert_eq!(spec.get_attribute::<f32>("attr_f32", true), Some(42.0f32));

        spec.set_attribute("attr_str", &UString::new("foo"));
        assert_eq!(
            spec.get_attribute::<UString>("attr_str", true)
                .unwrap()
                .as_str(),
            "foo"
        );

        spec.set_attribute(
            "attr_str[]",
            &[
                UString::new("foo"),
                UString::new("bar"),
                UString::new("baz"),
            ],
        );
        assert_eq!(
            spec.get_attribute::<[UString; 3]>("attr_str[]", true),
            Some([
                UString::new("foo"),
                UString::new("bar"),
                UString::new("baz")
            ]),
        );

        Ok(())
    }

    #[test]
    fn read_image() -> Result<(), Error> {
        use oiio::prelude::*;

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
        assert_eq!(spec.num_channels(), 4);

        let mut pixels = vec![
            0u8;
            (spec.width() * spec.height() * spec.num_channels())
                as usize
        ];

        ii.read_image_with_progress(
            &mut pixels,
            ReadOptions::default(),
            |progress: f32| {
                println!("Progress: {}", progress);
                false
            },
        )?;

        Ok(())
    }

    #[test]
    fn write_image() -> Result<(), Error> {
        use oiio::prelude::*;

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
        assert_eq!(spec.num_channels(), 4);

        let mut pixels = vec![
            0u8;
            (spec.width() * spec.height() * spec.num_channels())
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
        io.write_image(&pixels, Strides::default())?;

        Ok(())
    }

    #[test]
    fn write_ex1() -> Result<(), Error> {
        use oiio::prelude::*;

        let width = 640;
        let height = 480;
        let num_channels = 3; // RGB
        let pixels = vec![0u8; width * height * num_channels];
        let spec = ImageSpec::from_dimensions(
            width,
            height,
            num_channels,
            TypeDesc::UINT8,
        );
        let mut out =
            ImageOutput::new("foo.jpg", &spec, OpenMode::Create, None, None)?;
        out.write_image(&pixels, Strides::default())?;

        Ok(())
    }
}
