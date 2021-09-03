use crate::cppstd::{CppString, CppVectorSize};
use crate::error::{get_error, Error};
use crate::filesystem::IOProxy;
use crate::imagebuf::{ImageBuf, WrapMode};
use crate::imagecache::ImageCache;
use crate::imageio::{
    get_trampoline, ImageOutputOpened, ImageSpec, ImageSpecRef, Roi, Stride,
    Strides,
};
use crate::span::{SpanF32, SpanF32Mut, SpanI32, SpanString};
use crate::typedesc::TypeDesc;

use crate::color::{ColorConfig, ColorProcessor};
use crate::string_view::StringView;
use crate::traits::Pixel;

use oiio_sys as sys;

use std::convert::TryInto;
use std::os::raw::c_void;
use std::path::Path;

use imath_traits::{Matrix33, Matrix44};

type Result<T, E = Error> = std::result::Result<T, E>;

pub enum ImageOrConst<'a> {
    Buf(&'a ImageBuf),
    Slice(&'a [f32]),
    Const(f32),
}

impl<'a> From<ImageOrConst<'a>> for sys::OIIO_Image_or_Const_t {
    fn from(ioc: ImageOrConst<'a>) -> Self {
        let mut i = sys::OIIO_Image_or_Const_t::default();
        match ioc {
            ImageOrConst::Buf(b) => unsafe {
                sys::OIIO_Image_or_Const_from_imagebuf(&mut i, b.ptr);
            },
            ImageOrConst::Slice(s) => unsafe {
                sys::OIIO_Image_or_Const_from_float_array(
                    &mut i,
                    s.as_ptr(),
                    s.len(),
                );
            },
            ImageOrConst::Const(c) => unsafe {
                sys::OIIO_Image_or_Const_from_float(&mut i, &c);
            },
        }

        i
    }
}

/// Create an all-black `float` image of size and channels as described by
/// the ROI.
///
pub fn zero(roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_zero(
            &mut ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Create an all-black `float` image of size and channels as described by
/// the ROI.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn zero_in(dst: &mut ImageBuf, roi: Roi, nthreads: usize) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_zero_in(
            &mut result,
            dst.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Create an image filled with each pixel's channels set to `values`
///
pub fn fill(values: &[f32], roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_fill(
            &mut ptr,
            SpanF32::from(values).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Create an image filled with each pixel's channels set to `values`
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn fill_in(
    dst: &mut ImageBuf,
    values: &[f32],
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_fill_in(
            &mut result,
            dst.ptr,
            SpanF32::from(values).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Create an image filled with each pixel's channels set to the linear
/// interpolation of `top` to `bottom`.
///
pub fn fill_grad2(
    top: &[f32],
    bottom: &[f32],
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_fill_grad2(
            &mut ptr,
            SpanF32::from(top).0,
            SpanF32::from(bottom).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Create an image filled with each pixel's channels set to the linear
/// interpolation of `top` to `bottom`.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn fill_grad2_in(
    dst: &mut ImageBuf,
    top: &[f32],
    bottom: &[f32],
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_fill_grad2_in(
            &mut result,
            dst.ptr,
            SpanF32::from(top).0,
            SpanF32::from(bottom).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Create an image filled with each pixel's channels set to the bilinear
/// interpolation of the provided corner values
///
pub fn fill_grad4(
    top_left: &[f32],
    top_right: &[f32],
    bottom_left: &[f32],
    bottom_right: &[f32],
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_fill_grad4(
            &mut ptr,
            SpanF32::from(top_left).0,
            SpanF32::from(top_right).0,
            SpanF32::from(bottom_left).0,
            SpanF32::from(bottom_right).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Create an image filled with each pixel's channels set to the linear
/// interpolation of `top` to `bottom`.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn fill_grad4_in(
    dst: &mut ImageBuf,
    top_left: &[f32],
    top_right: &[f32],
    bottom_left: &[f32],
    bottom_right: &[f32],
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_fill_grad4_in(
            &mut result,
            dst.ptr,
            SpanF32::from(top_left).0,
            SpanF32::from(top_right).0,
            SpanF32::from(bottom_left).0,
            SpanF32::from(bottom_right).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Create a checkerboard pattern of size given by `roi`, with origin given
/// by the `offset` values, checker size given by the `width`, `height`,
/// `depth` values, and alternating between `color1[]` and `color2[]`.  The
/// pattern is defined in abstract "image space" independently of the pixel
/// data window of `dst` or the ROI.
///
pub fn checker(
    width: usize,
    height: usize,
    depth: usize,
    color1: &[f32],
    color2: &[f32],
    xoffset: i32,
    yoffset: i32,
    zoffset: i32,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_checker(
            &mut ptr,
            width.try_into().expect("not representable as i32"),
            height.try_into().expect("not representable as i32"),
            depth.try_into().expect("not representable as i32"),
            SpanF32::from(color1).0,
            SpanF32::from(color2).0,
            xoffset,
            yoffset,
            zoffset,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Create a checkerboard pattern of size given by `roi`, with origin given
/// by the `offset` values, checker size given by the `width`, `height`,
/// `depth` values, and alternating between `color1[]` and `color2[]`.  The
/// pattern is defined in abstract "image space" independently of the pixel
/// data window of `dst` or the ROI.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn checker_in(
    dst: &mut ImageBuf,
    width: usize,
    height: usize,
    depth: usize,
    color1: &[f32],
    color2: &[f32],
    xoffset: i32,
    yoffset: i32,
    zoffset: i32,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_checker_in(
            &mut result,
            dst.ptr,
            width.try_into().expect("not representable as i32"),
            height.try_into().expect("not representable as i32"),
            depth.try_into().expect("not representable as i32"),
            SpanF32::from(color1).0,
            SpanF32::from(color2).0,
            xoffset,
            yoffset,
            zoffset,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return an image of "noise" in every pixel and channel specified by the
/// roi. There are several noise types to choose from, and each behaves
/// differently and has a different interpretation of the `A` and `B`
/// parameters:
///
/// - "gaussian"   adds Gaussian (normal distribution) noise values with
///                   mean value A and standard deviation B.
/// - "uniform"    adds noise values uniformly distributed on range [A,B).
/// - "salt"       changes to value A a portion of pixels given by B.
///
/// If the `mono` flag is true, a single noise value will be applied to all
/// channels specified by `roi`, but if `mono` is false, a separate noise
/// value will be computed for each channel in the region.
///
/// The random number generator is actually driven by a hash on the "image
/// space" coordinates and channel, independently of the pixel data window
/// of `dst` or the ROI. Choosing different seed values will result in a
/// different pattern, but for the same seed value, the noise at a given
/// pixel coordinate (x,y,z) channel c will is completely deterministic and
/// repeatable.
///
pub fn noise(
    noise_type: &str,
    a: f32,
    b: f32,
    mono: bool,
    seed: i32,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_noise(
            &mut ptr,
            StringView::from(noise_type).0,
            a,
            b,
            mono,
            seed,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return an image of "noise" in every pixel and channel specified by the
/// roi. There are several noise types to choose from, and each behaves
/// differently and has a different interpretation of the `A` and `B`
/// parameters:
///
/// - "gaussian"   adds Gaussian (normal distribution) noise values with
///                   mean value A and standard deviation B.
/// - "uniform"    adds noise values uniformly distributed on range [A,B).
/// - "salt"       changes to value A a portion of pixels given by B.
///
/// If the `mono` flag is true, a single noise value will be applied to all
/// channels specified by `roi`, but if `mono` is false, a separate noise
/// value will be computed for each channel in the region.
///
/// The random number generator is actually driven by a hash on the "image
/// space" coordinates and channel, independently of the pixel data window
/// of `dst` or the ROI. Choosing different seed values will result in a
/// different pattern, but for the same seed value, the noise at a given
/// pixel coordinate (x,y,z) channel c will is completely deterministic and
/// repeatable.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn noise_in(
    dst: &mut ImageBuf,
    noise_type: &str,
    a: f32,
    b: f32,
    mono: bool,
    seed: i32,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_noise_in(
            &mut result,
            dst.ptr,
            StringView::from(noise_type).0,
            a,
            b,
            mono,
            seed,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Render a single point at (x,y) of the given color "over" the existing
/// image `dst`. If there is no alpha channel, the color will be written
/// unconditionally (as if the alpha is 1.0).
///
pub fn render_point_in(
    dst: &mut ImageBuf,
    x: i32,
    y: i32,
    color: &[f32],
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_render_point(
            &mut result,
            dst.ptr,
            x,
            y,
            SpanF32::from(color).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Render a line from pixel (`x1`,`y1`) to (`x2`,`y2`) into `dst`, doing an
/// "over" of the color (if it includes an alpha channel) onto the existing
/// data in `dst`. The `color` should include as many values as
/// `roi.chend-1`. The ROI can be used to limit the pixel area or channels
/// that are modified, and default to the entirety of `dst`. If
/// `skip_first_point` is `true`, the first point (`x1`, `y1`) will not be
/// drawn (this can be helpful when drawing poly-lines, to avoid
/// double-rendering of the vertex positions).
///
pub fn render_line_in(
    dst: &mut ImageBuf,
    x1: i32,
    y1: i32,
    x2: i32,
    y2: i32,
    color: &[f32],
    skip_first_point: bool,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_render_line(
            &mut result,
            dst.ptr,
            x1,
            y1,
            x2,
            y2,
            SpanF32::from(color).0,
            skip_first_point,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Render a filled or unfilled box with corners at pixels (`x1`,`y1`) and
/// (`x2`,`y2`) into `dst`, doing an "over" of the color (if it includes an
/// alpha channel) onto the existing data in `dst`. The `color` must include
/// as many values as `roi.chend-1`. The ROI can be used to limit the pixel
/// area or channels that are modified, and default to the entirety of
/// `dst`. If `fill` is `true`, the box will be completely filled in,
/// otherwise only its outlien will be drawn.
///
pub fn render_box_in(
    dst: &mut ImageBuf,
    x1: i32,
    y1: i32,
    x2: i32,
    y2: i32,
    color: &[f32],
    fill: bool,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_render_box(
            &mut result,
            dst.ptr,
            x1,
            y1,
            x2,
            y2,
            SpanF32::from(color).0,
            fill,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

pub use sys::OIIO_ImageBufAlgo_TextAlignX as TextAlignX;
pub use sys::OIIO_ImageBufAlgo_TextAlignY as TextAlignY;

/// Render a text string into image `dst`. If the `dst`
/// image is not yet initialized, it will be initialized to be a black
/// background exactly large enough to contain the rasterized text.  If
/// `dst` is already initialized, the text will be rendered into the
/// existing image by essentially doing an "over" of the character into the
/// existing pixel data.
///
/// * dst
///             Destination ImageBuf -- text is rendered into this image.
/// * x/y
///             The position to place the text.
/// * text
///             The text to draw. Linefeed (`\n`) characters are respected
///             as indications that the text spans multiple rows.
/// * fontsize/fontname
///             Size and name of the font. If the name is not a full
///             pathname to a font file, it will search for a matching font,
///             defaulting to some reasonable system font if not supplied at
///             all), and with a nominal height of fontsize (in pixels).
/// * textcolor
///             Color for drawing the text, defaulting to opaque white
///             (1.0,1.0,...) in all channels if not supplied. If provided,
///             it is expected to point to a float array of length at least
///             equal to `R.spec().nchannels`, or defaults will be chosen
///             for you).
/// * alignx/aligny
///             The default behavior is to align the left edge of the
///             character baseline to (`x`,`y`). Optionally, `alignx` and
///             `aligny` can override the alignment behavior, with
///             horizontal alignment choices of TextAlignX::Left, Right, and
///             Center, and vertical alignment choices of Baseline, Top,
///             Bottom, or Center.
/// * shadow
///             If nonzero, a "drop shadow" of this radius will be used to
///             make the text look more clear by dilating the alpha channel
///             of the composite (makes a black halo around the characters).
///
pub fn render_text(
    dst: &mut ImageBuf,
    x: i32,
    y: i32,
    text: &str,
    font_size: i32,
    font_name: &str,
    text_color: &[f32],
    align_x: TextAlignX,
    align_y: TextAlignY,
    shadow: i32,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_render_text(
            &mut result,
            dst.ptr,
            x,
            y,
            StringView::from(text).0,
            font_size,
            StringView::from(font_name).0,
            SpanF32::from(text_color).0,
            align_x,
            align_y,
            shadow,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// The helper function `text_size()` merely computes the dimensions of the
/// text, returning it as an ROI relative to the left side of the baseline
/// of the first character. Only the `x` and `y` dimensions of the ROI will
/// be used. The x dimension runs from left to right, and y runs from top to
/// bottom (image coordinates). For a failure (such as an invalid font
/// name), the ROI will return `false` if you call its `defined()` method.
/// The `text` may contain linefeed characters to designate multiple lines
/// of text.
///
pub fn text_size(text: &str, font_size: i32, font_name: &str) -> Roi {
    let mut roi = Roi::default();
    unsafe {
        sys::OIIO_ImageBufAlgo_text_size(
            &mut roi as *mut _ as *mut sys::OIIO_ROI_t,
            StringView::from(text).0,
            font_size,
            StringView::from(font_name).0,
        );
    }

    roi
}

/// Generic channel shuffling: return (or store in `dst`) a copy of `src`,
/// but with channels in the order `channelorder[0..nchannels-1]` (or set to
/// a constant value, designated by `channelorder[i] = -1` and having the
/// fill value in `channelvalues[i]`. In-place operation is allowed (i.e.,
/// `dst` and `src` the same image, but an extra copy will occur).
///
/// * nchannels
///             The total number of channels that will be set up in the
///             `dst` image.
/// * channelorder
///             For each channel in `dst`, the index of he `src` channel
///             from which to copy. Any `channelorder[i]` < 0 indicates that
///             the channel `i` should be filled with constant value
///             `channelvalues[i]` rather than copy any channel from `src`.
///             If `channelorder` itself is empty, the implied channel order
///             will be `{0, 1, ..., nchannels-1}`, meaning that it's only
///             renaming channels, not reordering them.
/// * channelvalues Fill values for color channels in which
///             `channelorder[i]` < 0.
/// * newchannelnames
///             An array of new channel names. Channels for which this
///             specifies an empty string will have their name taken from
///             the `src` channel that was copied. If `newchannelnames` is
///             entirely empty, all channel names will simply be copied from
///             `src`.
/// * shuffle_channel_names
///             If true, the channel names will be taken from the
///             corresponding channels of the source image -- be careful
///             with this, shuffling both channel ordering and their names
///             could result in no semantic change at all, if you catch the
///             drift. If false (the default), If false, the resulting `dst`
///             image will have default channel names in the usual order
///             ("R", "G", etc.), but i
pub fn channels<S: AsRef<str>>(
    src: &ImageBuf,
    num_channels: i32,
    channel_order: &[i32],
    channel_values: &[f32],
    new_channel_names: &[S],
    shuffle_channel_names: bool,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();

    let new_channel_names: Vec<CppString> = new_channel_names
        .iter()
        .map(|s| CppString::new(s.as_ref()))
        .collect();

    unsafe {
        sys::OIIO_ImageBufAlgo_channels(
            &mut ptr,
            src.ptr,
            num_channels,
            SpanI32::from(channel_order).0,
            SpanF32::from(channel_values).0,
            SpanString::from(new_channel_names.as_slice()).0,
            shuffle_channel_names,
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Generic channel shuffling: return (or store in `dst`) a copy of `src`,
/// but with channels in the order `channelorder[0..nchannels-1]` (or set to
/// a constant value, designated by `channelorder[i] = -1` and having the
/// fill value in `channelvalues[i]`. In-place operation is allowed (i.e.,
/// `dst` and `src` the same image, but an extra copy will occur).
///
/// * nchannels
///             The total number of channels that will be set up in the
///             `dst` image.
/// * channelorder
///             For each channel in `dst`, the index of he `src` channel
///             from which to copy. Any `channelorder[i]` < 0 indicates that
///             the channel `i` should be filled with constant value
///             `channelvalues[i]` rather than copy any channel from `src`.
///             If `channelorder` itself is empty, the implied channel order
///             will be `{0, 1, ..., nchannels-1}`, meaning that it's only
///             renaming channels, not reordering them.
/// * channelvalues Fill values for color channels in which
///             `channelorder[i]` < 0.
/// * newchannelnames
///             An array of new channel names. Channels for which this
///             specifies an empty string will have their name taken from
///             the `src` channel that was copied. If `newchannelnames` is
///             entirely empty, all channel names will simply be copied from
///             `src`.
/// * shuffle_channel_names
///             If true, the channel names will be taken from the
///             corresponding channels of the source image -- be careful
///             with this, shuffling both channel ordering and their names
///             could result in no semantic change at all, if you catch the
///             drift. If false (the default), If false, the resulting `dst`
///             image will have default channel names in the usual order
///             ("R", "G", etc.), but i
pub fn channels_in<S: AsRef<str>>(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    num_channels: i32,
    channel_order: &[i32],
    channel_values: &[f32],
    new_channel_names: &[S],
    shuffle_channel_names: bool,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;

    let new_channel_names: Vec<CppString> = new_channel_names
        .iter()
        .map(|s| CppString::new(s.as_ref()))
        .collect();

    unsafe {
        sys::OIIO_ImageBufAlgo_channels_in(
            &mut result,
            dst.ptr,
            src.ptr,
            num_channels,
            SpanI32::from(channel_order).0,
            SpanF32::from(channel_values).0,
            SpanString::from(new_channel_names.as_slice()).0,
            shuffle_channel_names,
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Append the channels of `A` and `B` together into `dst` over the region
/// of interest.  If the region passed is uninitialized (the default), it
/// will be interpreted as being the union of the pixel windows of `A` and `B`
/// (and all channels of both images).  
///
pub fn channel_append(
    a: &ImageBuf,
    b: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_channel_append(
            &mut ptr,
            a.ptr,
            b.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Append the channels of `A` and `B` together into `dst` over the region
/// of interest.  If the region passed is uninitialized (the default), it
/// will be interpreted as being the union of the pixel windows of `A` and `B`
/// (and all channels of both images).  
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn channel_append_in(
    dst: &mut ImageBuf,
    a: &ImageBuf,
    b: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_channel_append_in(
            &mut result,
            dst.ptr,
            a.ptr,
            b.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return the specified region of pixels of `src` as specified by `roi`
/// (which will default to the whole of `src`, optionally with the pixel
/// type overridden by convert (if it is not `TypeUnknown`).
///
pub fn copy(
    src: &ImageBuf,
    convert: TypeDesc,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_copy(
            &mut ptr,
            src.ptr,
            convert.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return the specified region of pixels of `src` as specified by `roi`
/// (which will default to the whole of `src`, optionally with the pixel
/// type overridden by convert (if it is not `TypeUnknown`).
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn copy_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    convert: TypeDesc,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_copy_in(
            &mut result,
            dst.ptr,
            src.ptr,
            convert.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return the specified region of `src` as an image, without altering its
/// position in the image plane.
///
/// Pixels from `src` which are outside `roi` will not be copied, and new
/// black pixels will be added for regions of `roi` which were outside the
/// data window of `src`.
///
/// Note that the `crop` operation does not actually move the pixels on the
/// image plane or adjust the full/display window; it merely restricts which
/// pixels are copied from `src` to `dst`.  (Note the difference compared to
/// `cut()`).
///
pub fn crop(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_crop(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return the specified region of `src` as an image, without altering its
/// position in the image plane.
///
/// Pixels from `src` which are outside `roi` will not be copied, and new
/// black pixels will be added for regions of `roi` which were outside the
/// data window of `src`.
///
/// Note that the `crop` operation does not actually move the pixels on the
/// image plane or adjust the full/display window; it merely restricts which
/// pixels are copied from `src` to `dst`.  (Note the difference compared to
/// `cut()`).
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn crop_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_crop_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return the designated region of `src`, but repositioned to the image
/// origin and with the full/display window set to exactly cover the new
/// pixel data window. (Note the difference compared to `crop()`).
///
pub fn cut(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_cut(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return the designated region of `src`, but repositioned to the image
/// origin and with the full/display window set to exactly cover the new
/// pixel data window. (Note the difference compared to `crop()`).
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn cut_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_cut_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Copy `src` pixels within `srcroi` into the `dst` image, offset so that
/// source location (0,0,0) will be copied to destination location
/// (`xbegin`,`ybegin`,`zbegin`). If the `srcroi` is `ROI::All()`, the
/// entirety of the data window of `src` will be used.  It will copy into
/// `channels[chbegin...]`, as many channels as are described by srcroi.
/// Pixels or channels of `src` inside `srcroi` will replace the
/// corresponding destination pixels entirely, whereas `src` pixels outside
/// of `srcroi` will not be copied and the corresponding offset pixels of
/// `dst` will not be altered.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn paste_in(
    dst: &mut ImageBuf,
    xbegin: i32,
    ybegin: i32,
    zbegin: i32,
    chbegin: i32,
    src: &ImageBuf,
    src_roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_paste(
            &mut result,
            dst.ptr,
            xbegin,
            ybegin,
            zbegin,
            chbegin,
            src.ptr,
            src_roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Rotate `src` 90 degrees clockwise
///
pub fn rotate90(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_rotate90(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Rotate `src` 90 degrees clockwise
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn rotate90_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_rotate90_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Rotate `src` 180 degrees clockwise
///
pub fn rotate180(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_rotate180(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Rotate `src` 180 degrees clockwise
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn rotate180_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_rotate180_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Rotate `src` 270 degrees clockwise
///
pub fn rotate270(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_rotate270(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Rotate `src` 270 degrees clockwise
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn rotate270_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_rotate270_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Mirror the image in the Y axis.
///
pub fn flip(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_flip(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Mirror the image in the Y axis.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn flip_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_flip_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Mirror the image in the X axis.
///
pub fn flop(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_flop(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Mirror the image in the X axis.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn flop_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_flop_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Mirror the image in both axes.
///
pub fn transpose(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_transpose(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Mirror the image in the both axes.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn transpose_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_transpose_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Apply whatever series of rotations, flips, or flops are necessary to
/// transform the pixels into the configuration suggested by the "Orientation"
/// metadata of the image (and the "Orientation" metadata is then set to 1,
/// ordinary orientation).
///
pub fn reorient(src: &ImageBuf, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_reorient(
            &mut ptr,
            src.ptr,
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Apply whatever series of rotations, flips, or flops are necessary to
/// transform the pixels into the configuration suggested by the "Orientation"
/// metadata of the image (and the "Orientation" metadata is then set to 1,
/// ordinary orientation).
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn reorient_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_reorient_in(
            &mut result,
            dst.ptr,
            src.ptr,
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return a subregion of `src`, but circularly shifting by the given
/// amount.  To clarify, the circular shift of [0,1,2,3,4,5] by +2 is
/// [4,5,0,1,2,3].
///
pub fn circular_shift(
    src: &ImageBuf,
    xshift: i32,
    yshift: i32,
    zshift: i32,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_circular_shift(
            &mut ptr,
            src.ptr,
            xshift,
            yshift,
            zshift,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return a subregion of `src`, but circularly shifting by the given
/// amount.  To clarify, the circular shift of [0,1,2,3,4,5] by +2 is
/// [4,5,0,1,2,3].
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn circular_shift_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    xshift: i32,
    yshift: i32,
    zshift: i32,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_circular_shift_in(
            &mut result,
            dst.ptr,
            src.ptr,
            xshift,
            yshift,
            zshift,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Rotate the `src` image by the `angle` (in radians, with positive angles
/// clockwise). When `center_x` and `center_y` are supplied, they denote the
/// center of rotation; in their absence, the rotation will be about the
/// center of the image's display window.
///
/// Only the pixels (and channels) of `dst` that are specified by `roi` will
/// be copied from the rotated `src`; the default `roi` is to alter all the
/// pixels in `dst`. If `dst` is uninitialized, it will be resized to be an
/// ImageBuf large enough to hold the rotated image if recompute_roi is
/// true, or will have the same ROI as `src` if `recompute_roi` is `false`.
/// It is an error to pass both an uninitialized `dst` and an undefined
/// `roi`.
///
/// The filter is used to weight the `src` pixels falling underneath it for
/// each `dst` pixel.  The caller may specify a reconstruction filter by
/// name and width (expressed in pixels units of the `dst` image), or
/// `rotate()` will choose a reasonable default high-quality default filter
/// (lanczos3) if the empty string is passed, and a reasonable filter width
/// if `filterwidth` is 0. (Note that some filter choices only make sense
/// with particular width, in which case this filterwidth parameter may be
/// ignored.)
///
pub fn rotate(
    src: &ImageBuf,
    angle: f32,
    center_x: f32,
    center_y: f32,
    filter_name: &str,
    filter_width: f32,
    recompute_roi: bool,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_rotate_with_center(
            &mut ptr,
            src.ptr,
            angle,
            center_x,
            center_y,
            StringView::from(filter_name).0,
            filter_width,
            recompute_roi,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Rotate the `src` image by the `angle` (in radians, with positive angles
/// clockwise). When `center_x` and `center_y` are supplied, they denote the
/// center of rotation; in their absence, the rotation will be about the
/// center of the image's display window.
///
/// Only the pixels (and channels) of `dst` that are specified by `roi` will
/// be copied from the rotated `src`; the default `roi` is to alter all the
/// pixels in `dst`. If `dst` is uninitialized, it will be resized to be an
/// ImageBuf large enough to hold the rotated image if recompute_roi is
/// true, or will have the same ROI as `src` if `recompute_roi` is `false`.
/// It is an error to pass both an uninitialized `dst` and an undefined
/// `roi`.
///
/// The filter is used to weight the `src` pixels falling underneath it for
/// each `dst` pixel.  The caller may specify a reconstruction filter by
/// name and width (expressed in pixels units of the `dst` image), or
/// `rotate()` will choose a reasonable default high-quality default filter
/// (lanczos3) if the empty string is passed, and a reasonable filter width
/// if `filterwidth` is 0. (Note that some filter choices only make sense
/// with particular width, in which case this filterwidth parameter may be
/// ignored.)
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn rotate_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    angle: f32,
    center_x: f32,
    center_y: f32,
    filter_name: &str,
    filter_width: f32,
    recompute_roi: bool,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_rotate_with_center_in(
            &mut result,
            dst.ptr,
            src.ptr,
            angle,
            center_x,
            center_y,
            StringView::from(filter_name).0,
            filter_width,
            recompute_roi,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Set `dst`, over the region of interest, to be a resized version of the
/// corresponding portion of `src` (mapping such that the "full" image
/// window of each correspond to each other, regardless of resolution).
/// If `dst` is not yet initialized, it will be sized according to `roi`.
///
/// The caller may either (a) explicitly pass a reconstruction `filter`, or
/// (b) specify one by `filtername` and `filterwidth`. If `filter` is
/// `nullptr` or if `filtername` is the empty string `resize()` will choose
/// a reasonable high-quality default (blackman-harris when upsizing,
/// lanczos3 when downsizing).  The filter is used to weight the `src`
/// pixels falling underneath it for each `dst` pixel; the filter's size is
/// expressed in pixel units of the `dst` image.
///
pub fn resize(
    src: &ImageBuf,
    filter_name: &str,
    filter_width: f32,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_resize(
            &mut ptr,
            src.ptr,
            StringView::from(filter_name).0,
            filter_width,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Set `dst`, over the region of interest, to be a resized version of the
/// corresponding portion of `src` (mapping such that the "full" image
/// window of each correspond to each other, regardless of resolution).
/// If `dst` is not yet initialized, it will be sized according to `roi`.
///
/// The caller may either (a) explicitly pass a reconstruction `filter`, or
/// (b) specify one by `filtername` and `filterwidth`. If `filter` is
/// `nullptr` or if `filtername` is the empty string `resize()` will choose
/// a reasonable high-quality default (blackman-harris when upsizing,
/// lanczos3 when downsizing).  The filter is used to weight the `src`
/// pixels falling underneath it for each `dst` pixel; the filter's size is
/// expressed in pixel units of the `dst` image.
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn resize_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    filter_name: &str,
    filter_width: f32,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_resize_in(
            &mut result,
            dst.ptr,
            src.ptr,
            StringView::from(filter_name).0,
            filter_width,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Set `dst`, over the region of interest, to be a resized version of the
/// corresponding portion of `src` (mapping such that the "full" image
/// window of each correspond to each other, regardless of resolution).  If
/// `dst` is not yet initialized, it will be sized according to `roi`.
///
/// Unlike `ImageBufAlgo::resize()`, `resample()` does not take a filter; it
/// just samples either with a bilinear interpolation (if `interpolate` is
/// `true`, the default) or uses the single "closest" pixel (if
/// `interpolate` is `false`).  This makes it a lot faster than a proper
/// `resize()`, though obviously with lower quality (aliasing when
/// downsizing, pixel replication when upsizing).
///
/// For "deep" images, this function returns copies the closest source pixel
/// needed, rather than attempting to interpolate deep pixels (regardless of
/// the value of `interpolate`).
///
pub fn resample(
    src: &ImageBuf,
    interpolate: bool,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_resample(
            &mut ptr,
            src.ptr,
            interpolate,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Set `dst`, over the region of interest, to be a resized version of the
/// corresponding portion of `src` (mapping such that the "full" image
/// window of each correspond to each other, regardless of resolution).  If
/// `dst` is not yet initialized, it will be sized according to `roi`.
///
/// Unlike `ImageBufAlgo::resize()`, `resample()` does not take a filter; it
/// just samples either with a bilinear interpolation (if `interpolate` is
/// `true`, the default) or uses the single "closest" pixel (if
/// `interpolate` is `false`).  This makes it a lot faster than a proper
/// `resize()`, though obviously with lower quality (aliasing when
/// downsizing, pixel replication when upsizing).
///
/// For "deep" images, this function returns copies the closest source pixel
/// needed, rather than attempting to interpolate deep pixels (regardless of
/// the value of `interpolate`).
///
pub fn resample_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    interpolate: bool,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_resample_in(
            &mut result,
            dst.ptr,
            src.ptr,
            interpolate,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Fit src into `dst` (to a size specified by `roi`, if `dst` is not
/// initialized), resizing but preserving its original aspect ratio. Thus,
/// it will resize to be the largest size with the same aspect ratio that
/// can fit inside the region, but will not stretch to completely fill it in
/// both dimensions.
///
/// The `fillmode` determines which of several methods will be used to
/// determine how the image will fill the new frame, if its aspect ratio
/// does not precisely match the original source aspect ratio:
///     - "width" exactly fills the width of the new frame, either cropping
///       or letterboxing the height if it isn't precisely the right size to
///       preserve the original aspect ratio.
///     - "height" exactly fills the height of the new frame, either cropping
///       or letterboxing the width if it isn't precisely the right size to
///       preserve the original aspect ratio.
///     - "letterbox" (the default) chooses whichever of "width" or "height"
///       will maximally fill the new frame with no image data lost (it will
///       only letterbox, never crop).
///
/// If `exact` is true, will result in an exact match on aspect ratio and
/// centering (partial pixel shift if necessary), whereas exact=false
/// will only preserve aspect ratio and centering to the precision of a
/// whole pixel.
///
/// The filter is used to weight the `src` pixels falling underneath it for
/// each `dst` pixel.  The caller may specify a reconstruction filter by
/// name and width (expressed in pixels units of the `dst` image), or
/// `rotate()` will choose a reasonable default high-quality default filter
/// (lanczos3) if the empty string is passed, and a reasonable filter width
/// if `filterwidth` is 0. (Note that some filter choices only make sense
/// with particular width, in which case this filterwidth parameter may be
/// ignored.)
///
pub fn fit(
    src: &ImageBuf,
    filter_name: &str,
    filter_width: f32,
    fill_mode: &str,
    exact: bool,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_fit(
            &mut ptr,
            src.ptr,
            StringView::from(filter_name).0,
            filter_width,
            StringView::from(fill_mode).0,
            exact,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Fit src into `dst` (to a size specified by `roi`, if `dst` is not
/// initialized), resizing but preserving its original aspect ratio. Thus,
/// it will resize to be the largest size with the same aspect ratio that
/// can fit inside the region, but will not stretch to completely fill it in
/// both dimensions.
///
/// The `fillmode` determines which of several methods will be used to
/// determine how the image will fill the new frame, if its aspect ratio
/// does not precisely match the original source aspect ratio:
///     - "width" exactly fills the width of the new frame, either cropping
///       or letterboxing the height if it isn't precisely the right size to
///       preserve the original aspect ratio.
///     - "height" exactly fills the height of the new frame, either cropping
///       or letterboxing the width if it isn't precisely the right size to
///       preserve the original aspect ratio.
///     - "letterbox" (the default) chooses whichever of "width" or "height"
///       will maximally fill the new frame with no image data lost (it will
///       only letterbox, never crop).
///
/// If `exact` is true, will result in an exact match on aspect ratio and
/// centering (partial pixel shift if necessary), whereas exact=false
/// will only preserve aspect ratio and centering to the precision of a
/// whole pixel.
///
/// The filter is used to weight the `src` pixels falling underneath it for
/// each `dst` pixel.  The caller may specify a reconstruction filter by
/// name and width (expressed in pixels units of the `dst` image), or
/// `rotate()` will choose a reasonable default high-quality default filter
/// (lanczos3) if the empty string is passed, and a reasonable filter width
/// if `filterwidth` is 0. (Note that some filter choices only make sense
/// with particular width, in which case this filterwidth parameter may be
/// ignored.)
///
pub fn fit_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    filter_name: &str,
    filter_width: f32,
    fill_mode: &str,
    exact: bool,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_fit_in(
            &mut result,
            dst.ptr,
            src.ptr,
            StringView::from(filter_name).0,
            filter_width,
            StringView::from(fill_mode).0,
            exact,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Warp the `src` image using the supplied 3x3 transformation matrix.
///
/// Only the pixels (and channels) of `dst` that are specified by `roi` will
/// be copied from the warped `src`; the default roi is to alter all the
/// pixels in dst. If `dst` is uninitialized, it will be sized to be an
/// ImageBuf large enough to hold the warped image if recompute_roi is true,
/// or will have the same ROI as src if recompute_roi is false. It is an
/// error to pass both an uninitialized `dst` and an undefined `roi`.
///
/// The caller may explicitly pass a reconstruction filter, or specify one
/// by name and size, or if the name is the empty string `resize()` will
/// choose a reasonable high-quality default if `nullptr` is passed.  The
/// filter is used to weight the `src` pixels falling underneath it for each
/// `dst` pixel; the filter's size is expressed in pixel units of the `dst`
/// image.
///
pub fn warp<M: Matrix33<f32>>(
    src: &ImageBuf,
    matrix: &M,
    filter_name: &str,
    filter_width: f32,
    recompute_roi: bool,
    wrap_mode: WrapMode,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_warp(
            &mut ptr,
            src.ptr,
            matrix.as_ptr() as *const sys::Imath_M33f_t,
            StringView::from(filter_name).0,
            filter_width,
            recompute_roi,
            wrap_mode.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Warp the `src` image using the supplied 3x3 transformation matrix.
///
/// Only the pixels (and channels) of `dst` that are specified by `roi` will
/// be copied from the warped `src`; the default roi is to alter all the
/// pixels in dst. If `dst` is uninitialized, it will be sized to be an
/// ImageBuf large enough to hold the warped image if recompute_roi is true,
/// or will have the same ROI as src if recompute_roi is false. It is an
/// error to pass both an uninitialized `dst` and an undefined `roi`.
///
/// The caller may explicitly pass a reconstruction filter, or specify one
/// by name and size, or if the name is the empty string `resize()` will
/// choose a reasonable high-quality default if `nullptr` is passed.  The
/// filter is used to weight the `src` pixels falling underneath it for each
/// `dst` pixel; the filter's size is expressed in pixel units of the `dst`
/// image.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn warp_in<M: Matrix33<f32>>(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    matrix: &M,
    filter_name: &str,
    filter_width: f32,
    recompute_roi: bool,
    wrap_mode: WrapMode,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_warp_in(
            &mut result,
            dst.ptr,
            src.ptr,
            matrix.as_ptr() as *const sys::Imath_M33f_t,
            StringView::from(filter_name).0,
            filter_width,
            recompute_roi,
            wrap_mode.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Compute per-pixel sum `A + B`, returning the result image.
///
/// `A` and `B` may each either be a `&ImageBuf`, or a `&[f32]`
/// giving a per- channel constant, or a single constant used for all
/// channels. (But at least one must be an image.)
///
pub fn add(
    a: ImageOrConst,
    b: ImageOrConst,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_add(
            &mut ptr,
            a.into(),
            b.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Compute per-pixel sum `A + B`, returning the result image.
///
/// `A` and `B` may each either be a `&ImageBuf`, or a `&[f32]`
/// giving a per- channel constant, or a single constant used for all
/// channels. (But at least one must be an image.)
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn add_in(
    dst: &mut ImageBuf,
    a: ImageOrConst,
    b: ImageOrConst,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_add_in(
            &mut result,
            dst.ptr,
            a.into(),
            b.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Compute per-pixel signed difference `A - B`, returning the result image.
///
/// `A` and `B` may each either be a `&ImageBuf`, or a `&[f32]`
/// giving a per- channel constant, or a single constant used for all
/// channels. (But at least one must be an image.)
///
pub fn sub(
    a: ImageOrConst,
    b: ImageOrConst,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_sub(
            &mut ptr,
            a.into(),
            b.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Compute per-pixel signed difference `A - B`.
///
/// `A` and `B` may each either be a `&ImageBuf`, or a `&[f32]`
/// giving a per- channel constant, or a single constant used for all
/// channels. (But at least one must be an image.)
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn sub_in(
    dst: &mut ImageBuf,
    a: ImageOrConst,
    b: ImageOrConst,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_sub_in(
            &mut result,
            dst.ptr,
            a.into(),
            b.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Compute per-pixel absolute difference `abs(A - B)`, returning the result image.
///
/// `A` and `B` may each either be a `&ImageBuf`, or a `&[f32]`
/// giving a per- channel constant, or a single constant used for all
/// channels. (But at least one must be an image.)
///
pub fn absdiff(
    a: ImageOrConst,
    b: ImageOrConst,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_absdiff(
            &mut ptr,
            a.into(),
            b.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Compute per-pixel absolute difference `abs(A - B)`.
///
/// `A` and `B` may each either be a `&ImageBuf`, or a `&[f32]`
/// giving a per- channel constant, or a single constant used for all
/// channels. (But at least one must be an image.)
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn absdiff_in(
    dst: &mut ImageBuf,
    a: ImageOrConst,
    b: ImageOrConst,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_absdiff_in(
            &mut result,
            dst.ptr,
            a.into(),
            b.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Compute per-pixel absolute value `abs(A)`, returning the result image.
///
/// `A` and `B` may each either be a `&ImageBuf`, or a `&[f32]`
/// giving a per- channel constant, or a single constant used for all
/// channels. (But at least one must be an image.)
///
pub fn abs(a: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_abs(
            &mut ptr,
            a.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Compute per-pixel absolute value `abs(A)`.
///
/// `A` and `B` may each either be a `&ImageBuf`, or a `&[f32]`
/// giving a per- channel constant, or a single constant used for all
/// channels. (But at least one must be an image.)
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn abs_in(
    dst: &mut ImageBuf,
    a: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_abs_in(
            &mut result,
            dst.ptr,
            a.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Compute per-pixel product `A * B`, returning the result image.
///
/// `A` and `B` may each either be a `&ImageBuf`, or a `&[f32]`
/// giving a per- channel constant, or a single constant used for all
/// channels. (But at least one must be an image.)
///
pub fn mul(
    a: ImageOrConst,
    b: ImageOrConst,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_mul(
            &mut ptr,
            a.into(),
            b.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Compute per-pixel product `A * B`.
///
/// `A` and `B` may each either be a `&ImageBuf`, or a `&[f32]`
/// giving a per- channel constant, or a single constant used for all
/// channels. (But at least one must be an image.)
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn mul_in(
    dst: &mut ImageBuf,
    a: ImageOrConst,
    b: ImageOrConst,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_mul_in(
            &mut result,
            dst.ptr,
            a.into(),
            b.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Compute per-pixel product `A * B`, returning the result image.
///
/// `A` and `B` may each either be a `&ImageBuf`, or a `&[f32]`
/// giving a per- channel constant, or a single constant used for all
/// channels. (But at least one must be an image.)
///
pub fn div(
    a: ImageOrConst,
    b: ImageOrConst,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_div(
            &mut ptr,
            a.into(),
            b.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Compute per-pixel product `A * B`, returning the result image.
///
/// `A` and `B` may each either be a `&ImageBuf`, or a `&[f32]`
/// giving a per- channel constant, or a single constant used for all
/// channels. (But at least one must be an image.)
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn div_in(
    dst: &mut ImageBuf,
    a: ImageOrConst,
    b: ImageOrConst,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_div_in(
            &mut result,
            dst.ptr,
            a.into(),
            b.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Compute per-pixel multiply-and-add `A * B + C`.
///
/// `A` and `B` may each either be a `&ImageBuf`, or a `&[f32]`
/// giving a per- channel constant, or a single constant used for all
/// channels. (But at least one must be an image.)
///
pub fn mad(
    a: ImageOrConst,
    b: ImageOrConst,
    c: ImageOrConst,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_mad(
            &mut ptr,
            a.into(),
            b.into(),
            c.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Compute per-pixel multiply-and-add `A * B + C`.
///
/// `A` and `B` may each either be a `&ImageBuf`, or a `&[f32]`
/// giving a per- channel constant, or a single constant used for all
/// channels. (But at least one must be an image.)
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn mad_in(
    dst: &mut ImageBuf,
    a: ImageOrConst,
    b: ImageOrConst,
    c: ImageOrConst,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_mad_in(
            &mut result,
            dst.ptr,
            a.into(),
            b.into(),
            c.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return the composite of `A` over `B` using the Porter/Duff definition of
/// "over", returning true upon success and false for any of a variety of
/// failures (as described below).
///
/// `A` and `B` (and dst, if already defined/allocated) must have valid
/// alpha channels identified by their ImageSpec `alpha_channel` field.  If`
/// A` or `B` do not have alpha channels (as determined by those rules) or
/// if the number of non-alpha channels do not match between `A` and `B`,
/// `over()` will fail, returning false.
///
/// If `dst` is not already an initialized ImageBuf, it will be sized to
/// encompass the minimal rectangular pixel region containing the union of
/// the defined pixels of `A` and `B`, and with a number of channels equal
/// to the number of non-alpha channels of `A` and `B`, plus an alpha
/// channel.  However, if `dst` is already initialized, it will not be
/// resized, and the "over" operation will apply to its existing pixel data
/// window.  In this case, dst must have an alpha channel designated and
/// must have the same number of non-alpha channels as `A` and `B`,
/// otherwise it will fail, returning false.
///
/// `A`, `B`, and `dst` need not perfectly overlap in their pixel data
/// windows; pixel values of `A` or `B` that are outside their respective
/// pixel data window will be treated as having "zero" (0,0,0...) value.
///
pub fn over(a: &ImageBuf, b: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_over(
            &mut ptr,
            a.ptr,
            b.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return the composite of `A` over `B` using the Porter/Duff definition of
/// "over", returning true upon success and false for any of a variety of
/// failures (as described below).
///
/// `A` and `B` (and dst, if already defined/allocated) must have valid
/// alpha channels identified by their ImageSpec `alpha_channel` field.  If`
/// A` or `B` do not have alpha channels (as determined by those rules) or
/// if the number of non-alpha channels do not match between `A` and `B`,
/// `over()` will fail, returning false.
///
/// If `dst` is not already an initialized ImageBuf, it will be sized to
/// encompass the minimal rectangular pixel region containing the union of
/// the defined pixels of `A` and `B`, and with a number of channels equal
/// to the number of non-alpha channels of `A` and `B`, plus an alpha
/// channel.  However, if `dst` is already initialized, it will not be
/// resized, and the "over" operation will apply to its existing pixel data
/// window.  In this case, dst must have an alpha channel designated and
/// must have the same number of non-alpha channels as `A` and `B`,
/// otherwise it will fail, returning false.
///
/// `A`, `B`, and `dst` need not perfectly overlap in their pixel data
/// windows; pixel values of `A` or `B` that are outside their respective
/// pixel data window will be treated as having "zero" (0,0,0...) value.
///
pub fn over_in(
    dst: &mut ImageBuf,
    a: &ImageBuf,
    b: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_over_in(
            &mut result,
            dst.ptr,
            a.ptr,
            b.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Just like `ImageBufAlgo::over()`, but inputs `A` and `B` must have
/// designated 'z' channels, and on a pixel-by-pixel basis, the z values
/// will determine which of `A` or `B` will be considered the foreground or
/// background (lower z is foreground).  If `z_zeroisinf` is true, then z=0
/// values will be treated as if they are infinitely far away.
///
pub fn zover(
    a: &ImageBuf,
    b: &ImageBuf,
    z_zero_is_inf: bool,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_zover(
            &mut ptr,
            a.ptr,
            b.ptr,
            z_zero_is_inf,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Just like `ImageBufAlgo::over()`, but inputs `A` and `B` must have
/// designated 'z' channels, and on a pixel-by-pixel basis, the z values
/// will determine which of `A` or `B` will be considered the foreground or
/// background (lower z is foreground).  If `z_zeroisinf` is true, then z=0
/// values will be treated as if they are infinitely far away.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn zover_in(
    dst: &mut ImageBuf,
    a: &ImageBuf,
    b: &ImageBuf,
    z_zero_is_inf: bool,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_zover_in(
            &mut result,
            dst.ptr,
            a.ptr,
            b.ptr,
            z_zero_is_inf,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Compute per-pixel value inverse `1.0 - A` (which you can think of as
/// roughly meaning switching white and black), returning the result image.
///
/// Tips for callers: (1) You probably want to set `roi` to restrict the
/// operation to only the color channels, and not accidentally include
/// alpha, z, or others. (2) There may be situations where you want to
/// `unpremult()` before the invert, then `premult()` the result, so that
/// you are computing the inverse of the unmasked color.
///
pub fn invert(a: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_invert(
            &mut ptr,
            a.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Compute per-pixel value inverse `1.0 - A` (which you can think of as
/// roughly meaning switching white and black), returning the result image.
///
/// Tips for callers: (1) You probably want to set `roi` to restrict the
/// operation to only the color channels, and not accidentally include
/// alpha, z, or others. (2) There may be situations where you want to
/// `unpremult()` before the invert, then `premult()` the result, so that
/// you are computing the inverse of the unmasked color.
///
pub fn invert_in(
    dst: &mut ImageBuf,
    a: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_invert_in(
            &mut result,
            dst.ptr,
            a.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Compute per-pixel raise-to-power `A ^ B`. returning the result image. It
/// is permitted for `dst` and `A` to be the same image.
///
pub fn pow(a: &ImageBuf, b: &[f32], roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_pow(
            &mut ptr,
            a.ptr,
            SpanF32::from(b).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Compute per-pixel value inverse `1.0 - A` (which you can think of as
/// roughly meaning switching white and black), returning the result image.
///
/// Tips for callers: (1) You probably want to set `roi` to restrict the
/// operation to only the color channels, and not accidentally include
/// alpha, z, or others. (2) There may be situations where you want to
/// `unpremult()` before the pow, then `premult()` the result, so that
/// you are computing the inverse of the unmasked color.
///
pub fn pow_in(
    dst: &mut ImageBuf,
    a: &ImageBuf,
    b: &[f32],
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_pow_in(
            &mut result,
            dst.ptr,
            a.ptr,
            SpanF32::from(b).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Converts a multi-channel image into a one-channel image via a weighted
/// sum of channels:
///
/// (channel[0]*weight[0] + channel[1]*weight[1] + ...)
///
pub fn channel_sum(
    a: &ImageBuf,
    weights: &[f32],
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_channel_sum(
            &mut ptr,
            a.ptr,
            SpanF32::from(weights).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Converts a multi-channel image into a one-channel image via a weighted
/// sum of channels:
///
/// (channel[0]*weight[0] + channel[1]*weight[1] + ...)
///
pub fn channel_sum_in(
    dst: &mut ImageBuf,
    a: &ImageBuf,
    weights: &[f32],
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_channel_sum_in(
            &mut result,
            dst.ptr,
            a.ptr,
            SpanF32::from(weights).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Compute per-pixel `max(A, B)`, returning the result image.
///
pub fn max(
    a: ImageOrConst,
    b: ImageOrConst,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_max(
            &mut ptr,
            a.into(),
            b.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Compute per-pixel `max(A, B)`, returning the result image.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn max_in(
    dst: &mut ImageBuf,
    a: ImageOrConst,
    b: ImageOrConst,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_max_in(
            &mut result,
            dst.ptr,
            a.into(),
            b.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Compute per-pixel `min(A, B)`, returning the result image.
///
pub fn min(
    a: ImageOrConst,
    b: ImageOrConst,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_min(
            &mut ptr,
            a.into(),
            b.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Compute per-pixel `min(A, B)`, returning the result image.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn min_in(
    dst: &mut ImageBuf,
    a: ImageOrConst,
    b: ImageOrConst,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_min_in(
            &mut result,
            dst.ptr,
            a.into(),
            b.into(),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return pixels of `src` with pixel values clamped as follows:
/// * `min` specifies the minimum clamp value for each channel
///   (if min is empty, no minimum clamping is performed).
/// * `max` specifies the maximum clamp value for each channel
///   (if `max` is empty, no maximum clamping is performed).
/// * If `clampalpha01` is true, then additionally any alpha channel is
///   clamped to the 0-1 range.
///
pub fn clamp(
    a: &ImageBuf,
    min: &[f32],
    max: &[f32],
    clamp_alpha_01: bool,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_clamp(
            &mut ptr,
            a.ptr,
            SpanF32::from(min).0,
            SpanF32::from(max).0,
            clamp_alpha_01,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return pixels of `src` with pixel values clamped as follows:
/// * `min` specifies the minimum clamp value for each channel
///   (if min is empty, no minimum clamping is performed).
/// * `max` specifies the maximum clamp value for each channel
///   (if `max` is empty, no maximum clamping is performed).
/// * If `clampalpha01` is true, then additionally any alpha channel is
///   clamped to the 0-1 range.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn clamp_in(
    dst: &mut ImageBuf,
    a: &ImageBuf,
    min: &[f32],
    max: &[f32],
    clamp_alpha_01: bool,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_clamp_in(
            &mut result,
            dst.ptr,
            a.ptr,
            SpanF32::from(min).0,
            SpanF32::from(max).0,
            clamp_alpha_01,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return pixel values that are a contrast-remap of the corresponding
/// values of the `src` image, transforming pixel value domain [black,
/// white] to range [min, max], either linearly or with optional application
/// of a smooth sigmoidal remapping (if `scontrast` != 1.0).
///
/// The following steps are performed, in order:
///
/// 1. Linearly rescale values [`black`, `white`] to [0, 1].
/// 2. If `scontrast` != 1, apply a sigmoidal remapping where a larger
///    `scontrast` value makes a steeper slope, and the steepest part is at
///    value `sthresh` (relative to the new remapped value after steps 1 &
///    2; the default is 0.5).
/// 3. Rescale the range of that result: 0.0 -> `min` and 1.0 -> `max`.
///
/// Values outside of the [black,white] range will be extrapolated to
/// outside [min,max], so it may be prudent to apply a clamp() to the
/// results.
///
/// The black, white, min, max, scontrast, sthresh parameters may each
/// either be a single float value for all channels, or a span giving
/// per-channel values.
///
/// You can use this function for a simple linear contrast remapping of
/// [black, white] to [min, max] if you use the default values for sthresh.
/// Or just a simple sigmoidal contrast stretch within the [0,1] range if
/// you leave all other parameters at their defaults, or a combination of
/// these effects. Note that if `black` == `white`, the result will be a
/// simple binary thresholding where values < `black` map to `min` and
/// values >= `black` map to `max`.
///
pub fn contrast_remap(
    a: &ImageBuf,
    black: &[f32],
    white: &[f32],
    min: &[f32],
    max: &[f32],
    s_contrast: &[f32],
    s_thresh: &[f32],
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_contrast_remap(
            &mut ptr,
            a.ptr,
            SpanF32::from(black).0,
            SpanF32::from(white).0,
            SpanF32::from(min).0,
            SpanF32::from(max).0,
            SpanF32::from(s_contrast).0,
            SpanF32::from(s_thresh).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return pixel values that are a contrast-remap of the corresponding
/// values of the `src` image, transforming pixel value domain [black,
/// white] to range [min, max], either linearly or with optional application
/// of a smooth sigmoidal remapping (if `scontrast` != 1.0).
///
/// The following steps are performed, in order:
///
/// 1. Linearly rescale values [`black`, `white`] to [0, 1].
/// 2. If `scontrast` != 1, apply a sigmoidal remapping where a larger
///    `scontrast` value makes a steeper slope, and the steepest part is at
///    value `sthresh` (relative to the new remapped value after steps 1 &
///    2; the default is 0.5).
/// 3. Rescale the range of that result: 0.0 -> `min` and 1.0 -> `max`.
///
/// Values outside of the [black,white] range will be extrapolated to
/// outside [min,max], so it may be prudent to apply a clamp() to the
/// results.
///
/// The black, white, min, max, scontrast, sthresh parameters may each
/// either be a single float value for all channels, or a span giving
/// per-channel values.
///
/// You can use this function for a simple linear contrast remapping of
/// [black, white] to [min, max] if you use the default values for sthresh.
/// Or just a simple sigmoidal contrast stretch within the [0,1] range if
/// you leave all other parameters at their defaults, or a combination of
/// these effects. Note that if `black` == `white`, the result will be a
/// simple binary thresholding where values < `black` map to `min` and
/// values >= `black` map to `max`.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn contrast_remap_in(
    dst: &mut ImageBuf,
    a: &ImageBuf,
    black: &[f32],
    white: &[f32],
    min: &[f32],
    max: &[f32],
    s_contrast: &[f32],
    s_thresh: &[f32],
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_contrast_remap_in(
            &mut result,
            dst.ptr,
            a.ptr,
            SpanF32::from(black).0,
            SpanF32::from(white).0,
            SpanF32::from(min).0,
            SpanF32::from(max).0,
            SpanF32::from(s_contrast).0,
            SpanF32::from(s_thresh).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return (or copy into `dst`) pixel values determined by looking up a
/// color map using values of the source image, using either the channel
/// specified by `srcchannel`, or the luminance of `src`'s RGB if
/// `srcchannel` is None. This happens for all pixels within the  ROI (which
/// defaults to all of `src`), and if `dst` is not already initialized, it
/// will be initialized to the ROI and with color channels equal to
/// `channels`.
///
/// In the variant that takes a `knots` parameter, this specifies the values
/// of a linearly-interpolated color map given by `knots[nknots*channels]`.
/// An input value of 0.0 is mapped to `knots[0..channels-1]` (one value for
/// each color channel), and an input value of 1.0 is mapped to
/// `knots[(nknots-1)*channels..knots.size()-1]`.
///
///
pub fn color_map(
    a: &ImageBuf,
    src_channel: Option<usize>,
    num_knots: usize,
    num_channels: usize,
    knots: &[f32],
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_color_map(
            &mut ptr,
            a.ptr,
            if let Some(c) = src_channel {
                c.try_into()
                    .expect("src_channel is not representable as i32")
            } else {
                -1
            },
            num_knots
                .try_into()
                .expect("num_knots is not representable as i32"),
            num_channels
                .try_into()
                .expect("num_channels is not representable as i32"),
            SpanF32::from(knots).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return (or copy into `dst`) pixel values determined by looking up a
/// color map using values of the source image, using either the channel
/// specified by `srcchannel`, or the luminance of `src`'s RGB if
/// `srcchannel` is None. This happens for all pixels within the  ROI (which
/// defaults to all of `src`), and if `dst` is not already initialized, it
/// will be initialized to the ROI and with color channels equal to
/// `channels`.
///
/// In the variant that takes a `mapname` parameter, this is the name of a
/// color map. Recognized map names include: "inferno", "viridis", "magma",
/// "plasma", all of which are perceptually uniform, strictly increasing in
/// luminance, look good when converted to grayscale, and work for people
/// with all types of colorblindness. Also "turbo" has most of these
/// properties (except for being strictly increasing in luminance) and
/// is a nice rainbow-like pattern. Also supported are the following color
/// maps that do not have those desirable qualities (and are thus not
/// recommended, but are present for back-compatibility or for use by
/// clueless people): "blue-red", "spectrum", and "heat". In all cases, the
/// implied `channels` is 3.
///
pub fn color_map_named(
    a: &ImageBuf,
    src_channel: Option<usize>,
    map_name: &str,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_color_map_named(
            &mut ptr,
            a.ptr,
            if let Some(c) = src_channel {
                c.try_into()
                    .expect("src_channel is not representable as i32")
            } else {
                -1
            },
            StringView::from(map_name).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return (or copy into `dst`) pixel values determined by looking up a
/// color map using values of the source image, using either the channel
/// specified by `srcchannel`, or the luminance of `src`'s RGB if
/// `srcchannel` is None. This happens for all pixels within the  ROI (which
/// defaults to all of `src`), and if `dst` is not already initialized, it
/// will be initialized to the ROI and with color channels equal to
/// `channels`.
///
/// In the variant that takes a `knots` parameter, this specifies the values
/// of a linearly-interpolated color map given by `knots[nknots*channels]`.
/// An input value of 0.0 is mapped to `knots[0..channels-1]` (one value for
/// each color channel), and an input value of 1.0 is mapped to
/// `knots[(nknots-1)*channels..knots.size()-1]`.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
///
pub fn color_map_in(
    dst: &mut ImageBuf,
    a: &ImageBuf,
    src_channel: Option<usize>,
    num_knots: usize,
    num_channels: usize,
    knots: &[f32],
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_color_map_in(
            &mut result,
            dst.ptr,
            a.ptr,
            if let Some(c) = src_channel {
                c.try_into()
                    .expect("src_channel is not representable as i32")
            } else {
                -1
            },
            num_knots
                .try_into()
                .expect("num_knots is not representable as i32"),
            num_channels
                .try_into()
                .expect("num_channels is not representable as i32"),
            SpanF32::from(knots).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return (or copy into `dst`) pixel values determined by looking up a
/// color map using values of the source image, using either the channel
/// specified by `srcchannel`, or the luminance of `src`'s RGB if
/// `srcchannel` is None. This happens for all pixels within the  ROI (which
/// defaults to all of `src`), and if `dst` is not already initialized, it
/// will be initialized to the ROI and with color channels equal to
/// `channels`.
///
/// In the variant that takes a `mapname` parameter, this is the name of a
/// color map. Recognized map names include: "inferno", "viridis", "magma",
/// "plasma", all of which are perceptually uniform, strictly increasing in
/// luminance, look good when converted to grayscale, and work for people
/// with all types of colorblindness. Also "turbo" has most of these
/// properties (except for being strictly increasing in luminance) and
/// is a nice rainbow-like pattern. Also supported are the following color
/// maps that do not have those desirable qualities (and are thus not
/// recommended, but are present for back-compatibility or for use by
/// clueless people): "blue-red", "spectrum", and "heat". In all cases, the
/// implied `channels` is 3.
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn color_map_named_in(
    dst: &mut ImageBuf,
    a: &ImageBuf,
    src_channel: Option<usize>,
    map_name: &str,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_color_map_named_in(
            &mut result,
            dst.ptr,
            a.ptr,
            if let Some(c) = src_channel {
                c.try_into()
                    .expect("src_channel is not representable as i32")
            } else {
                -1
            },
            StringView::from(map_name).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// `rangecompress()` returns (or copy into `dst`) all pixels and color
/// channels of `src` within region `roi` (defaulting to all the defined
/// pixels of `dst`), rescaling their range with a logarithmic
/// transformation. Alpha and z channels are not transformed.
///
/// If `useluma` is true, the luma of channels [roi.chbegin..roi.chbegin+2]
/// (presumed to be R, G, and B) are used to compute a single scale factor
/// for all color channels, rather than scaling all channels individually
/// (which could result in a color shift).
///
/// The purpose of these function is as follows: Some image operations (such
/// as resizing with a "good" filter that contains negative lobes) can have
/// objectionable artifacts when applied to images with very high-contrast
/// regions involving extra bright pixels (such as highlights in HDR
/// captured or rendered images).  By compressing the range pixel values,
/// then performing the operation, then expanding the range of the result
/// again, the result can be much more pleasing (even if not exactly
/// correct).
///
pub fn range_compress(
    a: &ImageBuf,
    use_luma: bool,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_rangecompress(
            &mut ptr,
            a.ptr,
            use_luma,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// `rangecompress()` returns (or copy into `dst`) all pixels and color
/// channels of `src` within region `roi` (defaulting to all the defined
/// pixels of `dst`), rescaling their range with a logarithmic
/// transformation. Alpha and z channels are not transformed.
///
/// If `useluma` is true, the luma of channels [roi.chbegin..roi.chbegin+2]
/// (presumed to be R, G, and B) are used to compute a single scale factor
/// for all color channels, rather than scaling all channels individually
/// (which could result in a color shift).
///
/// The purpose of these function is as follows: Some image operations (such
/// as resizing with a "good" filter that contains negative lobes) can have
/// objectionable artifacts when applied to images with very high-contrast
/// regions involving extra bright pixels (such as highlights in HDR
/// captured or rendered images).  By compressing the range pixel values,
/// then performing the operation, then expanding the range of the result
/// again, the result can be much more pleasing (even if not exactly
/// correct).
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn range_compress_in(
    dst: &mut ImageBuf,
    a: &ImageBuf,
    use_luma: bool,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_rangecompress_in(
            &mut result,
            dst.ptr,
            a.ptr,
            use_luma,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// `rangeexpand()` performs the inverse transformation (logarithmic back
/// into linear).
///
/// If `useluma` is true, the luma of channels [roi.chbegin..roi.chbegin+2]
/// (presumed to be R, G, and B) are used to compute a single scale factor
/// for all color channels, rather than scaling all channels individually
/// (which could result in a color shift).
///
/// The purpose of these function is as follows: Some image operations (such
/// as resizing with a "good" filter that contains negative lobes) can have
/// objectionable artifacts when applied to images with very high-contrast
/// regions involving extra bright pixels (such as highlights in HDR
/// captured or rendered images).  By compressing the range pixel values,
/// then performing the operation, then expanding the range of the result
/// again, the result can be much more pleasing (even if not exactly
/// correct).
///
pub fn range_expand(
    a: &ImageBuf,
    use_luma: bool,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_rangeexpand(
            &mut ptr,
            a.ptr,
            use_luma,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// `rangeexpand()` performs the inverse transformation (logarithmic back
/// into linear).
///
/// If `useluma` is true, the luma of channels [roi.chbegin..roi.chbegin+2]
/// (presumed to be R, G, and B) are used to compute a single scale factor
/// for all color channels, rather than scaling all channels individually
/// (which could result in a color shift).
///
/// The purpose of these function is as follows: Some image operations (such
/// as resizing with a "good" filter that contains negative lobes) can have
/// objectionable artifacts when applied to images with very high-contrast
/// regions involving extra bright pixels (such as highlights in HDR
/// captured or rendered images).  By compressing the range pixel values,
/// then performing the operation, then expanding the range of the result
/// again, the result can be much more pleasing (even if not exactly
/// correct).
///
/// Write to an existing image `dst` (allocating if it is uninitialized).
///
pub fn range_expand_in(
    dst: &mut ImageBuf,
    a: &ImageBuf,
    use_luma: bool,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_rangeexpand_in(
            &mut result,
            dst.ptr,
            a.ptr,
            use_luma,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Struct holding all the results computed by ImageBufAlgo::compare().
/// (maxx,maxy,maxz,maxc) gives the pixel coordinates (x,y,z) and color
/// channel of the pixel that differed maximally between the two images.
/// nwarn and nfail are the number of "warnings" and "failures",
/// respectively.
///
pub use sys::OIIO_ImageBufAlgo_CompareResults_t as CompareResults;

/// Numerically compare two images.  The difference threshold (for any
/// individual color channel in any pixel) for a "failure" is
/// failthresh, and for a "warning" is warnthresh.  The results are
/// stored in result.  If roi is defined, pixels will be compared for
/// the pixel and channel range that is specified.  If roi is not
/// defined, the comparison will be for all channels, on the union of
/// the defined pixel windows of the two images (for either image,
/// undefined pixels will be assumed to be black).
///
pub fn compare(
    a: &ImageBuf,
    b: &ImageBuf,
    fail_threshold: f32,
    warn_threshold: f32,
    roi: Roi,
    nthreads: usize,
) -> CompareResults {
    let mut results = CompareResults::default();
    unsafe {
        sys::OIIO_ImageBufAlgo_compare(
            &mut results,
            a.ptr,
            b.ptr,
            fail_threshold,
            warn_threshold,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    results
}

/// Compare two images using Hector Yee's perceptual metric, returning
/// the number of pixels that fail the comparison.  Only the first three
/// channels (or first three channels specified by `roi`) are compared.
/// Free parameters are the ambient luminance in the room and the field
/// of view of the image display; our defaults are probably reasonable
/// guesses for an office environment.  The 'result' structure will
/// store the maxerror, and the maxx, maxy, maxz of the pixel that
/// failed most severely.  (The other fields of the CompareResults
/// are not used for Yee comparison.)
///
/// Works for all pixel types.  But it's basically meaningless if the
/// first three channels aren't RGB in a linear color space that sort
/// of resembles AdobeRGB.
///
pub fn compare_yee(
    a: &ImageBuf,
    b: &ImageBuf,
    luminance: f32,
    fov: f32,
    roi: Roi,
    nthreads: usize,
) -> usize {
    let mut result = 0;
    let mut compare_results = CompareResults::default();
    unsafe {
        sys::OIIO_ImageBufAlgo_compare_Yee(
            &mut result,
            a.ptr,
            b.ptr,
            &mut compare_results,
            luminance,
            fov,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    result
        .try_into()
        .expect("result is not representable as i32")
}

/// Do all pixels within the ROI have the same values for channels
/// `[roi.chbegin..roi.chend-1]`, within a tolerance of +/- `threshold`?  If
/// so, return `true` and store that color in `color[chbegin...chend-1]` (if
/// `color` is not empty); otherwise return `false`.  If `roi` is not
/// defined (the default), it will be understood to be all of the defined
/// pixels and channels of source.
///
pub fn is_constant_color(
    src: &ImageBuf,
    threshold: f32,
    color: &mut [f32],
    roi: Roi,
    nthreads: usize,
) -> bool {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_isConstantColor(
            &mut result,
            src.ptr,
            threshold,
            SpanF32Mut::from(color).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    result
}

/// Does the requested channel have a given value (within a tolerance of +/-
/// `threshold`) for every channel within the ROI?  (For this function, the
/// ROI's chbegin/chend are ignored.)  Return `true` if so, otherwise return
/// `false`.  If `roi` is not defined (the default), it will be understood
/// to be all of the defined pixels and channels of source.
///
pub fn is_constant_channel(
    src: &ImageBuf,
    channel: usize,
    val: f32,
    threshold: f32,
    roi: Roi,
    nthreads: usize,
) -> bool {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_isConstantChannel(
            &mut result,
            src.ptr,
            channel
                .try_into()
                .expect("channel is not representable as i32"),
            val,
            threshold,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    result
}

/// Is the image monochrome within the ROI, i.e., for every pixel within the
/// region, do all channels [roi.chbegin, roi.chend) have the same value
/// (within a tolerance of +/- threshold)?  If roi is not defined (the
/// default), it will be understood to be all of the defined pixels and
/// channels of source.
///
pub fn is_monochrome(
    src: &ImageBuf,
    threshold: f32,
    roi: Roi,
    nthreads: usize,
) -> bool {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_isMonochrome(
            &mut result,
            src.ptr,
            threshold,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    result
}

/// Count how many pixels in the image (within the ROI) are outside the
/// value range described by `low[roi.chbegin..roi.chend-1]` and
/// `high[roi.chbegin..roi.chend-1]` as the low and high acceptable values
/// for each color channel.
///
/// On success, returns the tuple (low_count, high_count, in_range_count).
///
pub fn color_range_check(
    src: &ImageBuf,
    low: &[f32],
    high: &[f32],
    roi: Roi,
    nthreads: usize,
) -> Result<(usize, usize, usize)> {
    let mut result = false;
    let mut low_count = 0;
    let mut high_count = 0;
    let mut in_range_count = 0;
    unsafe {
        sys::OIIO_ImageBufAlgo_color_range_check(
            &mut result,
            src.ptr,
            &mut low_count,
            &mut high_count,
            &mut in_range_count,
            SpanF32::from(low).0,
            SpanF32::from(high).0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok((low_count, high_count, in_range_count))
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Find the minimal rectangular region within `roi` (which defaults to the
/// entire pixel data window of `src`) that consists of nonzero pixel
/// values.  In other words, gives the region that is a "shrink-wraps" of
/// `src` to exclude black border pixels.  Note that if the entire image was
/// black, the ROI returned will contain no pixels.
///
/// For "deep" images, this function returns the smallest ROI that contains
/// all pixels that contain depth samples, and excludes the border pixels
/// that contain no depth samples at all.

pub fn nonzero_region(src: &ImageBuf, roi: Roi, nthreads: usize) -> Roi {
    let mut result = Roi::all();
    unsafe {
        sys::OIIO_ImageBufAlgo_nonzero_region(
            &mut result as *mut Roi as *mut sys::OIIO_ROI_t,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    result
}

/// Compute the SHA-1 byte hash for all the pixels in the specifed region of
/// the image.  If `blocksize` > 0, the function will compute separate SHA-1
/// hashes of each `blocksize` batch of scanlines, then return a hash of the
/// individual hashes.  This is just as strong a hash, but will NOT match a
/// single hash of the entire image (`blocksize==0`).  But by breaking up
/// the hash into independent blocks, we can parallelize across multiple
/// threads, given by `nthreads` (if `nthreads` is 0, it will use the global
/// OIIO thread count).  The `extrainfo` provides additional text that will
/// be incorporated into the hash.
///
pub fn compute_pixel_hash_sha1(
    src: &ImageBuf,
    extra_info: &str,
    roi: Roi,
    block_size: usize,
    nthreads: usize,
) -> String {
    let mut result = CppString::new("");
    unsafe {
        sys::OIIO_ImageBufAlgo_computePixelHashSHA1(
            &mut result.0,
            src.ptr,
            StringView::from(extra_info).0,
            roi.into(),
            block_size
                .try_into()
                .expect("block_size is not representable as i32"),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    result.as_str().to_string()
}

/// Compute the SHA-1 byte hash for all the pixels in the specifed region of
/// the image.  If `blocksize` > 0, the function will compute separate SHA-1
/// hashes of each `blocksize` batch of scanlines, then return a hash of the
/// individual hashes.  This is just as strong a hash, but will NOT match a
/// single hash of the entire image (`blocksize==0`).  But by breaking up
/// the hash into independent blocks, we can parallelize across multiple
/// threads, given by `nthreads` (if `nthreads` is 0, it will use the global
/// OIIO thread count).  The `extrainfo` provides additional text that will
/// be incorporated into the hash.
///
pub fn histogram(
    src: &ImageBuf,
    channel: usize,
    num_bins: usize,
    min: f32,
    max: f32,
    ignore_empty: bool,
    roi: Roi,
    nthreads: usize,
) -> Vec<usize> {
    let mut result = CppVectorSize::new();
    unsafe {
        sys::OIIO_ImageBufAlgo_histogram(
            &mut result.0,
            src.ptr,
            channel
                .try_into()
                .expect("channel is not representable as i32"),
            num_bins
                .try_into()
                .expect("num_bins is not representable as i32"),
            min,
            max,
            ignore_empty,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    result.as_slice().to_vec()
}

/// Make a 1-channel `float` image of the named kernel. The size of the
/// image will be big enough to contain the kernel given its size (`width` x
/// `height`) and rounded up to odd resolution so that the center of the
/// kernel can be at the center of the middle pixel.  The kernel image will
/// be offset so that its center is at the (0,0) coordinate.  If `normalize`
/// is true, the values will be normalized so that they sum to 1.0. If
/// `depth` > 1, a volumetric kernel will be created.  Use with caution!
///
/// Kernel names can be: "gaussian", "sharp-gaussian", "box",
/// "triangle", "blackman-harris", "mitchell", "b-spline", "catmull-rom",
/// "lanczos3", "disk", "binomial", "laplacian".
///
/// Note that "catmull-rom" and "lanczos3" are fixed-size kernels that
/// don't scale with the width, and are therefore probably less useful
/// in most cases.
///
pub fn make_kernel(
    name: &str,
    width: f32,
    height: f32,
    depth: f32,
    normalize: bool,
) -> Result<ImageBuf> {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_make_kernel(
            &mut ptr,
            StringView::from(name).0,
            width,
            height,
            depth,
            normalize,
        );
    }

    let buf = ImageBuf { ptr };
    if buf.has_error() {
        Err(Error::Oiio(buf.get_error(true)))
    } else {
        Ok(buf)
    }
}

/// Return the convolution of `src` and a `kernel`. If `roi` is not defined,
/// it defaults to the full size `src`. If `normalized` is true, the kernel will
/// be normalized for the  convolution, otherwise the original values will
/// be used.
pub fn convolve(
    src: &ImageBuf,
    kernel: &ImageBuf,
    normalize: bool,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_convolve(
            &mut ptr,
            src.ptr,
            kernel.ptr,
            normalize,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return the convolution of `src` and a `kernel`. If `roi` is not defined,
/// it defaults to the full size `src`. If `normalized` is true, the kernel will
/// be normalized for the  convolution, otherwise the original values will
/// be used.
pub fn convolve_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    kernel: &ImageBuf,
    normalize: bool,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_convolve_in(
            &mut result,
            dst.ptr,
            src.ptr,
            kernel.ptr,
            normalize,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return the Laplacian of the corresponding region of `src`.  The
/// Laplacian is the generalized second derivative of the image
///
pub fn laplacian(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_laplacian(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return the Laplacian of the corresponding region of `src`.  The
/// Laplacian is the generalized second derivative of the image
///
pub fn laplacian_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_laplacian_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return (or copy into `dst`) the discrete Fourier transform (DFT), or its
/// inverse, of the section of `src` denoted by roi,  If roi is not defined,
/// it will be all of `src`'s pixels.
///
/// `fft()` takes the discrete Fourier transform (DFT) of the section of
/// `src` denoted by `roi`, returning it or storing it in `dst`. If `roi` is
/// not defined, it will be all of `src`'s pixels. Only one channel of `src`
/// may be transformed at a time, so it will be the first channel described
/// by `roi` (or, again, channel 0 if `roi` is undefined).  If not already
/// in the correct format, `dst` will be re-allocated to be a 2-channel
/// `float` buffer of size `roi.width()` x `roi.height`, with channel 0
/// being the "real" part and channel 1 being the the "imaginary" part.  The
/// values returned are actually the unitary DFT, meaning that it is scaled
/// by 1/sqrt(npixels).
///
/// `ifft()` takes the inverse discrete Fourier transform, transforming a
/// 2-channel complex (real and imaginary) frequency domain image and into a
/// single-channel spatial domain image. `src` must be a 2-channel float
/// image, and is assumed to be a complex frequency-domain signal with the
/// "real" component in channel 0 and the "imaginary" component in channel 1.
/// `dst` will end up being a float image of one channel (the real component
/// is kept, the imaginary component of the spatial-domain will be
/// discarded). Just as with `fft()`, the `ifft()` function is dealing with
/// the unitary DFT, so it is scaled by 1/sqrt(npixels).
///
pub fn fft(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_fft(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return (or copy into `dst`) the discrete Fourier transform (DFT), or its
/// inverse, of the section of `src` denoted by roi,  If roi is not defined,
/// it will be all of `src`'s pixels.
///
/// `fft()` takes the discrete Fourier transform (DFT) of the section of
/// `src` denoted by `roi`, returning it or storing it in `dst`. If `roi` is
/// not defined, it will be all of `src`'s pixels. Only one channel of `src`
/// may be transformed at a time, so it will be the first channel described
/// by `roi` (or, again, channel 0 if `roi` is undefined).  If not already
/// in the correct format, `dst` will be re-allocated to be a 2-channel
/// `float` buffer of size `roi.width()` x `roi.height`, with channel 0
/// being the "real" part and channel 1 being the the "imaginary" part.  The
/// values returned are actually the unitary DFT, meaning that it is scaled
/// by 1/sqrt(npixels).
///
/// `ifft()` takes the inverse discrete Fourier transform, transforming a
/// 2-channel complex (real and imaginary) frequency domain image and into a
/// single-channel spatial domain image. `src` must be a 2-channel float
/// image, and is assumed to be a complex frequency-domain signal with the
/// "real" component in channel 0 and the "imaginary" component in channel 1.
/// `dst` will end up being a float image of one channel (the real component
/// is kept, the imaginary component of the spatial-domain will be
/// discarded). Just as with `fft()`, the `ifft()` function is dealing with
/// the unitary DFT, so it is scaled by 1/sqrt(npixels).
///
pub fn fft_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_fft_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return (or copy into `dst`) the discrete Fourier transform (DFT), or its
/// inverse, of the section of `src` denoted by roi,  If roi is not defined,
/// it will be all of `src`'s pixels.
///
/// `fft()` takes the discrete Fourier transform (DFT) of the section of
/// `src` denoted by `roi`, returning it or storing it in `dst`. If `roi` is
/// not defined, it will be all of `src`'s pixels. Only one channel of `src`
/// may be transformed at a time, so it will be the first channel described
/// by `roi` (or, again, channel 0 if `roi` is undefined).  If not already
/// in the correct format, `dst` will be re-allocated to be a 2-channel
/// `float` buffer of size `roi.width()` x `roi.height`, with channel 0
/// being the "real" part and channel 1 being the the "imaginary" part.  The
/// values returned are actually the unitary DFT, meaning that it is scaled
/// by 1/sqrt(npixels).
///
/// `ifft()` takes the inverse discrete Fourier transform, transforming a
/// 2-channel complex (real and imaginary) frequency domain image and into a
/// single-channel spatial domain image. `src` must be a 2-channel float
/// image, and is assumed to be a complex frequency-domain signal with the
/// "real" component in channel 0 and the "imaginary" component in channel 1.
/// `dst` will end up being a float image of one channel (the real component
/// is kept, the imaginary component of the spatial-domain will be
/// discarded). Just as with `fft()`, the `ifft()` function is dealing with
/// the unitary DFT, so it is scaled by 1/sqrt(npixels).
///
pub fn inverse_fft(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_ifft(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return (or copy into `dst`) the discrete Fourier transform (DFT), or its
/// inverse, of the section of `src` denoted by roi,  If roi is not defined,
/// it will be all of `src`'s pixels.
///
/// `fft()` takes the discrete Fourier transform (DFT) of the section of
/// `src` denoted by `roi`, returning it or storing it in `dst`. If `roi` is
/// not defined, it will be all of `src`'s pixels. Only one channel of `src`
/// may be transformed at a time, so it will be the first channel described
/// by `roi` (or, again, channel 0 if `roi` is undefined).  If not already
/// in the correct format, `dst` will be re-allocated to be a 2-channel
/// `float` buffer of size `roi.width()` x `roi.height`, with channel 0
/// being the "real" part and channel 1 being the the "imaginary" part.  The
/// values returned are actually the unitary DFT, meaning that it is scaled
/// by 1/sqrt(npixels).
///
/// `ifft()` takes the inverse discrete Fourier transform, transforming a
/// 2-channel complex (real and imaginary) frequency domain image and into a
/// single-channel spatial domain image. `src` must be a 2-channel float
/// image, and is assumed to be a complex frequency-domain signal with the
/// "real" component in channel 0 and the "imaginary" component in channel 1.
/// `dst` will end up being a float image of one channel (the real component
/// is kept, the imaginary component of the spatial-domain will be
/// discarded). Just as with `fft()`, the `ifft()` function is dealing with
/// the unitary DFT, so it is scaled by 1/sqrt(npixels).
///
pub fn inverse_fft_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_ifft_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// The `complex_to_polar()` function performs the reverse transformation,
/// converting from  polar values (amplitude and phase) to complex (real and
/// imaginary).
///
pub fn complex_to_polar(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_complex_to_polar(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// The `complex_to_polar()` function performs the reverse transformation,
/// converting from  polar values (amplitude and phase) to complex (real and
/// imaginary).
///
pub fn complex_to_polar_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_complex_to_polar_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// The `polar_to_complex()` function transforms a 2-channel image whose
/// channels are interpreted as complex values (real and imaginary
/// components) into the equivalent values expressed in polar form of
/// amplitude and phase (with phase between 0 and \f$ 2\pi \f$.
///
pub fn polar_to_complex(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_polar_to_complex(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// The `polar_to_complex()` function transforms a 2-channel image whose
/// channels are interpreted as complex values (real and imaginary
/// components) into the equivalent values expressed in polar form of
/// amplitude and phase (with phase between 0 and \f$ 2\pi \f$.
///
pub fn polar_to_complex_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_polar_to_complex_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

pub use sys::NonFiniteFixMode;

/// `fixNonFinite()` returns in image containing the values of `src` (within
/// the ROI), while repairing  any non-finite (NaN/Inf) pixels. If
/// pixelsFixed is not nullptr, store in it the number of pixels that
/// contained non-finite value.  It is permissible to operate in-place (with
/// `src` and  `dst` referring to the same image).
///
/// How the non-finite values are repaired is specified by one of the `mode`
/// parameter, which is an enum of `NonFiniteFixMode`.
///
/// This function works on all pixel data types, though it's just a copy for
/// images with pixel data types that cannot represent NaN or Inf values.
///
pub fn fix_non_finite(
    src: &ImageBuf,
    mode: NonFiniteFixMode,
    roi: Roi,
    nthreads: usize,
) -> (ImageBuf, usize) {
    let mut ptr = std::ptr::null_mut();
    let mut num = 0;
    unsafe {
        sys::OIIO_ImageBufAlgo_fixNonFinite(
            &mut ptr,
            src.ptr,
            mode.into(),
            &mut num,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    (
        ImageBuf { ptr },
        num.try_into().expect("num not representable as usize"),
    )
}

/// `fixNonFinite()` returns in image containing the values of `src` (within
/// the ROI), while repairing  any non-finite (NaN/Inf) pixels. If
/// pixelsFixed is not nullptr, store in it the number of pixels that
/// contained non-finite value.  It is permissible to operate in-place (with
/// `src` and  `dst` referring to the same image).
///
/// How the non-finite values are repaired is specified by one of the `mode`
/// parameter, which is an enum of `NonFiniteFixMode`.
///
/// This function works on all pixel data types, though it's just a copy for
/// images with pixel data types that cannot represent NaN or Inf values.
///
pub fn fix_non_finite_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    mode: NonFiniteFixMode,
    roi: Roi,
    nthreads: usize,
) -> Result<usize> {
    let mut result = false;
    let mut num = 0;
    unsafe {
        sys::OIIO_ImageBufAlgo_fixNonFinite_in(
            &mut result,
            dst.ptr,
            src.ptr,
            mode.into(),
            &mut num,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(num.try_into().expect("num not representable as usize"))
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Copy the specified ROI of `src` and fill any holes (pixels where alpha <
/// 1) with plausible values using a push-pull technique. The `src` image
/// must have an alpha channel.  The `dst` image will end up with a copy of
/// `src`, but will have an alpha of 1.0 everywhere within `roi`, and any
/// place where the alpha of `src` was < 1, `dst` will have a pixel color
/// that is a plausible "filling" of the original alpha hole.
///
pub fn fill_holes_push_pull(
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_fillholes_pushpull(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Copy the specified ROI of `src` and fill any holes (pixels where alpha <
/// 1) with plausible values using a push-pull technique. The `src` image
/// must have an alpha channel.  The `dst` image will end up with a copy of
/// `src`, but will have an alpha of 1.0 everywhere within `roi`, and any
/// place where the alpha of `src` was < 1, `dst` will have a pixel color
/// that is a plausible "filling" of the original alpha hole.
///
pub fn fill_holes_push_pull_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_fillholes_pushpull_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return a median-filtered version of the corresponding region of `src`.
/// The median filter replaces each pixel with the median value underneath
/// the `width` x `height` window surrounding it. If `height` <= 0, it will
/// be set to `width`, making a square window.
///
/// Median filters are good for removing high-frequency detail smaller than
/// the window size (including noise), without blurring edges that are
/// larger than the window size.
///
pub fn median_filter(
    src: &ImageBuf,
    width: usize,
    height: usize,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_median_filter(
            &mut ptr,
            src.ptr,
            width.try_into().expect("width is not representable as i32"),
            height
                .try_into()
                .expect("width is not representable as i32"),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return a median-filtered version of the corresponding region of `src`.
/// The median filter replaces each pixel with the median value underneath
/// the `width` x `height` window surrounding it. If `height` <= 0, it will
/// be set to `width`, making a square window.
///
/// Median filters are good for removing high-frequency detail smaller than
/// the window size (including noise), without blurring edges that are
/// larger than the window size.
///
pub fn median_filter_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    width: usize,
    height: usize,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_median_filter_in(
            &mut result,
            dst.ptr,
            src.ptr,
            width.try_into().expect("width is not representable as i32"),
            height
                .try_into()
                .expect("width is not representable as i32"),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return a sharpened version of the corresponding region of `src` using
/// the "unsharp mask" technique. Unsharp masking basically works by first
/// blurring the image (low pass filter), subtracting this from the original
/// image, then adding the residual back to the original to emphasize the
/// edges. Roughly speaking,
///
/// dst = src + contrast * thresh(src - blur(src))
///
/// The specific blur can be selected by kernel name and width (for example,
/// "gaussian" is typical). As a special case, "median" is also accepted as
/// the kernel name, in which case a median filter is performed rather than
/// a blurring convolution (Gaussian and other blurs sometimes over-sharpen
/// edges, whereas using the median filter will sharpen compact
/// high-frequency details while not over-sharpening long edges).
///
/// The `contrast` is a multiplier on the overall sharpening effect.  The
/// thresholding step causes all differences less than `threshold` to be
/// squashed to zero, which can be useful for suppressing sharpening of
/// low-contrast details (like noise) but allow sharpening of
/// higher-contrast edges.
///
pub fn unsharp_mask(
    src: &ImageBuf,
    kernel: &str,
    width: f32,
    contrast: f32,
    threshold: f32,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_unsharp_mask(
            &mut ptr,
            src.ptr,
            StringView::from(kernel).0,
            width,
            contrast,
            threshold,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return a sharpened version of the corresponding region of `src` using
/// the "unsharp mask" technique. Unsharp masking basically works by first
/// blurring the image (low pass filter), subtracting this from the original
/// image, then adding the residual back to the original to emphasize the
/// edges. Roughly speaking,
///
/// dst = src + contrast * thresh(src - blur(src))
///
/// The specific blur can be selected by kernel name and width (for example,
/// "gaussian" is typical). As a special case, "median" is also accepted as
/// the kernel name, in which case a median filter is performed rather than
/// a blurring convolution (Gaussian and other blurs sometimes over-sharpen
/// edges, whereas using the median filter will sharpen compact
/// high-frequency details while not over-sharpening long edges).
///
/// The `contrast` is a multiplier on the overall sharpening effect.  The
/// thresholding step causes all differences less than `threshold` to be
/// squashed to zero, which can be useful for suppressing sharpening of
/// low-contrast details (like noise) but allow sharpening of
/// higher-contrast edges.
///
pub fn unsharp_mask_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    kernel: &str,
    width: f32,
    contrast: f32,
    threshold: f32,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_unsharp_mask_in(
            &mut result,
            dst.ptr,
            src.ptr,
            StringView::from(kernel).0,
            width,
            contrast,
            threshold,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return a dilated version of the corresponding region of `src`. Dilation
/// is defined as the maximum value of all pixels under nonzero values of
/// the structuring element (which is taken to be a width x height square).
/// If height is not set, it will default to be the same as width. Dilation
/// makes bright features wider and more prominent, dark features thinner,
/// and removes small isolated dark spots.
///
pub fn dilate(
    src: &ImageBuf,
    width: usize,
    height: usize,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_dilate(
            &mut ptr,
            src.ptr,
            width.try_into().expect("width is not representable as i32"),
            height
                .try_into()
                .expect("width is not representable as i32"),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return a dilated version of the corresponding region of `src`. Dilation
/// is defined as the maximum value of all pixels under nonzero values of
/// the structuring element (which is taken to be a width x height square).
/// If height is not set, it will default to be the same as width. Dilation
/// makes bright features wider and more prominent, dark features thinner,
/// and removes small isolated dark spots.
///
pub fn dilate_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    width: usize,
    height: usize,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_dilate_in(
            &mut result,
            dst.ptr,
            src.ptr,
            width.try_into().expect("width is not representable as i32"),
            height
                .try_into()
                .expect("width is not representable as i32"),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return an eroded version of the corresponding region of `src`. Erosion
/// is defined as the minimum value of all pixels under nonzero values of
/// the structuring element (which is taken to be a width x height square).
/// If height is not set, it will default to be the same as width. Erosion
/// makes dark features wider, bright features thinner, and removes small
/// isolated bright spots.
///
pub fn erode(
    src: &ImageBuf,
    width: usize,
    height: usize,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_erode(
            &mut ptr,
            src.ptr,
            width.try_into().expect("width is not representable as i32"),
            height
                .try_into()
                .expect("width is not representable as i32"),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return an eroded version of the corresponding region of `src`. Erosion
/// is defined as the minimum value of all pixels under nonzero values of
/// the structuring element (which is taken to be a width x height square).
/// If height is not set, it will default to be the same as width. Erosion
/// makes dark features wider, bright features thinner, and removes small
/// isolated bright spots.
///
pub fn erode_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    width: usize,
    height: usize,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_erode_in(
            &mut result,
            dst.ptr,
            src.ptr,
            width.try_into().expect("width is not representable as i32"),
            height
                .try_into()
                .expect("width is not representable as i32"),
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

pub fn color_convert(
    src: &ImageBuf,
    from_space: &str,
    to_space: &str,
    unpremult: bool,
    context_key: &str,
    context_value: &str,
    color_config: &ColorConfig,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_colorconvert(
            &mut ptr,
            src.ptr,
            StringView::from(from_space).0,
            StringView::from(to_space).0,
            unpremult,
            StringView::from(context_key).0,
            StringView::from(context_value).0,
            color_config.0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

pub fn color_convert_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    from_space: &str,
    to_space: &str,
    unpremult: bool,
    context_key: &str,
    context_value: &str,
    color_config: &ColorConfig,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_colorconvert_in(
            &mut result,
            dst.ptr,
            src.ptr,
            StringView::from(from_space).0,
            StringView::from(to_space).0,
            unpremult,
            StringView::from(context_key).0,
            StringView::from(context_value).0,
            color_config.0,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

pub fn color_convert_with_processor(
    src: &ImageBuf,
    color_processor: &ColorProcessor,
    unpremult: bool,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_colorconvert_with_processor(
            &mut ptr,
            src.ptr,
            color_processor.get_raw_ptr(),
            unpremult,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

pub fn color_convert_with_processor_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    color_processor: &ColorProcessor,
    unpremult: bool,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_colorconvert_with_processor_in(
            &mut result,
            dst.ptr,
            src.ptr,
            color_processor.get_raw_ptr(),
            unpremult,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return a copy of the pixels of `src` within the ROI, applying a color
/// transform specified by a 4x4 matrix.  In-place operations
/// (`dst` == `src`) are supported.
///
/// The first three channels are presumed to be the color to be
/// transformed, and the fourth channel (if it exists) is presumed to be
/// alpha. Any additional channels will be simply copied unaltered.
///
pub fn color_matrix_transform<M: Matrix44<f32>>(
    src: &ImageBuf,
    matrix: &M,
    unpremult: bool,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_colormatrixtransform(
            &mut ptr,
            src.ptr,
            matrix as *const _ as *const sys::Imath_M44f_t,
            unpremult,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return a copy of the pixels of `src` within the ROI, applying a color
/// transform specified by a 4x4 matrix.  In-place operations
/// (`dst` == `src`) are supported.
///
/// The first three channels are presumed to be the color to be
/// transformed, and the fourth channel (if it exists) is presumed to be
/// alpha. Any additional channels will be simply copied unaltered.
///
pub fn color_matrix_transform_in<M: Matrix44<f32>>(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    matrix: &M,
    unpremult: bool,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_colormatrixtransform_in(
            &mut result,
            dst.ptr,
            src.ptr,
            matrix as *const _ as *const sys::Imath_M44f_t,
            unpremult,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return a copy of the pixels of `src` within the ROI, applying an
/// OpenColorIO "look" transform to the pixel values. In-place operations
/// (`dst` == `src`) are supported.
///
/// The first three channels are presumed to be the color to be
/// transformed, and the fourth channel (if it exists) is presumed to be
/// alpha. Any additional channels will be simply copied unaltered.
///
/// * looks
///             The looks to apply (comma-separated).
/// * fromspace/tospace
///             For the varieties of `colorconvert()` that use named color
///             spaces, these specify the color spaces by name.
/// * unpremult
///             If true, unpremultiply the image (divide the RGB channels by
///             alpha if it exists and is nonzero) before color conversion,
///             then repremult after the after the color conversion. Passing
///             unpremult=false skips this step, which may be desirable if
///             you know that the image is "unassociated alpha" (a.k.a.,
///             "not pre-multiplied colors").
/// * inverse
///             If `true`, it will reverse the color transformation and look
///             application.
/// * context_key/context_value
///             Optional key/value to establish a context (for example, a
///             shot-specific transform).
/// * colorconfig
///             An optional `ColorConfig*` specifying an OpenColorIO
///             configuration. If not supplied, the default OpenColorIO
///             color configuration found by examining the `$OCIO`
///             environment variable will be used instead.
///
pub fn ocio_look(
    src: &ImageBuf,
    looks: &str,
    from_space: &str,
    to_space: &str,
    unpremult: bool,
    inverse: bool,
    context_key: &str,
    context_value: &str,
    color_config: Option<&ColorConfig>,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_ociolook(
            &mut ptr,
            src.ptr,
            StringView::from(looks).0,
            StringView::from(from_space).0,
            StringView::from(to_space).0,
            unpremult,
            inverse,
            StringView::from(context_key).0,
            StringView::from(context_value).0,
            if let Some(cc) = color_config {
                cc.0
            } else {
                std::ptr::null_mut()
            },
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return a copy of the pixels of `src` within the ROI, applying an
/// OpenColorIO "look" transform to the pixel values. In-place operations
/// (`dst` == `src`) are supported.
///
/// The first three channels are presumed to be the color to be
/// transformed, and the fourth channel (if it exists) is presumed to be
/// alpha. Any additional channels will be simply copied unaltered.
///
/// * looks
///             The looks to apply (comma-separated).
/// * fromspace/tospace
///             For the varieties of `colorconvert()` that use named color
///             spaces, these specify the color spaces by name.
/// * unpremult
///             If true, unpremultiply the image (divide the RGB channels by
///             alpha if it exists and is nonzero) before color conversion,
///             then repremult after the after the color conversion. Passing
///             unpremult=false skips this step, which may be desirable if
///             you know that the image is "unassociated alpha" (a.k.a.,
///             "not pre-multiplied colors").
/// * inverse
///             If `true`, it will reverse the color transformation and look
///             application.
/// * context_key/context_value
///             Optional key/value to establish a context (for example, a
///             shot-specific transform).
/// * colorconfig
///             An optional `ColorConfig*` specifying an OpenColorIO
///             configuration. If not supplied, the default OpenColorIO
///             color configuration found by examining the `$OCIO`
///             environment variable will be used instead.
///
pub fn ocio_look_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    looks: &str,
    from_space: &str,
    to_space: &str,
    unpremult: bool,
    inverse: bool,
    context_key: &str,
    context_value: &str,
    color_config: Option<&ColorConfig>,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_ociolook_in(
            &mut result,
            dst.ptr,
            src.ptr,
            StringView::from(looks).0,
            StringView::from(from_space).0,
            StringView::from(to_space).0,
            unpremult,
            inverse,
            StringView::from(context_key).0,
            StringView::from(context_value).0,
            if let Some(cc) = color_config {
                cc.0
            } else {
                std::ptr::null_mut()
            },
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return a copy of the pixels of `src` within the ROI, applying an
/// OpenColorIO "display" transform to the pixel values. In-place operations
/// (`dst` == `src`) are supported.
///
/// The first three channels are presumed to be the color to be
/// transformed, and the fourth channel (if it exists) is presumed to be
/// alpha. Any additional channels will be simply copied unaltered.
///
/// * displays
///             The displays to apply (comma-separated).
/// * fromspace/tospace
///             For the varieties of `colorconvert()` that use named color
///             spaces, these specify the color spaces by name.
/// * unpremult
///             If true, unpremultiply the image (divide the RGB channels by
///             alpha if it exists and is nonzero) before color conversion,
///             then repremult after the after the color conversion. Passing
///             unpremult=false skips this step, which may be desirable if
///             you know that the image is "unassociated alpha" (a.k.a.,
///             "not pre-multiplied colors").
/// * inverse
///             If `true`, it will reverse the color transformation and display
///             application.
/// * context_key/context_value
///             Optional key/value to establish a context (for example, a
///             shot-specific transform).
/// * colorconfig
///             An optional `ColorConfig*` specifying an OpenColorIO
///             configuration. If not supplied, the default OpenColorIO
///             color configuration found by examining the `$OCIO`
///             environment variable will be used instead.
///
pub fn ocio_display(
    src: &ImageBuf,
    display: &str,
    view: &str,
    from_space: &str,
    to_space: &str,
    unpremult: bool,
    context_key: &str,
    context_value: &str,
    color_config: Option<&ColorConfig>,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_ociodisplay(
            &mut ptr,
            src.ptr,
            StringView::from(display).0,
            StringView::from(view).0,
            StringView::from(from_space).0,
            StringView::from(to_space).0,
            unpremult,
            StringView::from(context_key).0,
            StringView::from(context_value).0,
            if let Some(cc) = color_config {
                cc.0
            } else {
                std::ptr::null_mut()
            },
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return a copy of the pixels of `src` within the ROI, applying an
/// OpenColorIO "display" transform to the pixel values. In-place operations
/// (`dst` == `src`) are supported.
///
/// The first three channels are presumed to be the color to be
/// transformed, and the fourth channel (if it exists) is presumed to be
/// alpha. Any additional channels will be simply copied unaltered.
///
/// * displays
///             The displays to apply (comma-separated).
/// * fromspace/tospace
///             For the varieties of `colorconvert()` that use named color
///             spaces, these specify the color spaces by name.
/// * unpremult
///             If true, unpremultiply the image (divide the RGB channels by
///             alpha if it exists and is nonzero) before color conversion,
///             then repremult after the after the color conversion. Passing
///             unpremult=false skips this step, which may be desirable if
///             you know that the image is "unassociated alpha" (a.k.a.,
///             "not pre-multiplied colors").
/// * inverse
///             If `true`, it will reverse the color transformation and display
///             application.
/// * context_key/context_value
///             Optional key/value to establish a context (for example, a
///             shot-specific transform).
/// * colorconfig
///             An optional `ColorConfig*` specifying an OpenColorIO
///             configuration. If not supplied, the default OpenColorIO
///             color configuration found by examining the `$OCIO`
///             environment variable will be used instead.
///
pub fn ocio_display_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    display: &str,
    view: &str,
    from_space: &str,
    to_space: &str,
    unpremult: bool,
    context_key: &str,
    context_value: &str,
    color_config: Option<&ColorConfig>,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_ociodisplay_in(
            &mut result,
            dst.ptr,
            src.ptr,
            StringView::from(display).0,
            StringView::from(view).0,
            StringView::from(from_space).0,
            StringView::from(to_space).0,
            unpremult,
            StringView::from(context_key).0,
            StringView::from(context_value).0,
            if let Some(cc) = color_config {
                cc.0
            } else {
                std::ptr::null_mut()
            },
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return the pixels of `src` within the ROI, applying an OpenColorIO
/// "file" transform. In-place operations (`dst` == `src`) are supported.
///
/// The first three channels are presumed to be the color to be
/// transformed, and the fourth channel (if it exists) is presumed to be
/// alpha. Any additional channels will be simply copied unaltered.
///
/// * name
///             The name of the file containing the transform information.
/// * unpremult
///             If true, unpremultiply the image (divide the RGB channels by
///             alpha if it exists and is nonzero) before color conversion,
///             then repremult after the after the color conversion. Passing
///             unpremult=false skips this step, which may be desirable if
///             you know that the image is "unassociated alpha" (a.k.a.,
///             "not pre-multiplied colors").
/// * inverse
///             If `true`, it will reverse the color transformation.
/// * colorconfig
///             An optional `ColorConfig*` specifying an OpenColorIO
///             configuration. If not supplied, the default OpenColorIO
///             color configuration found by examining the `$OCIO`
///             environment variable will be used instead.
///
pub fn ocio_file_transform(
    src: &ImageBuf,
    name: &str,
    unpremult: bool,
    inverse: bool,
    color_config: Option<&ColorConfig>,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_ociofiletransform(
            &mut ptr,
            src.ptr,
            StringView::from(name).0,
            unpremult,
            inverse,
            if let Some(cc) = color_config {
                cc.0
            } else {
                std::ptr::null_mut()
            },
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return the pixels of `src` within the ROI, applying an OpenColorIO
/// "file" transform. In-place operations (`dst` == `src`) are supported.
///
/// The first three channels are presumed to be the color to be
/// transformed, and the fourth channel (if it exists) is presumed to be
/// alpha. Any additional channels will be simply copied unaltered.
///
/// * name
///             The name of the file containing the transform information.
/// * unpremult
///             If true, unpremultiply the image (divide the RGB channels by
///             alpha if it exists and is nonzero) before color conversion,
///             then repremult after the after the color conversion. Passing
///             unpremult=false skips this step, which may be desirable if
///             you know that the image is "unassociated alpha" (a.k.a.,
///             "not pre-multiplied colors").
/// * inverse
///             If `true`, it will reverse the color transformation.
/// * colorconfig
///             An optional `ColorConfig*` specifying an OpenColorIO
///             configuration. If not supplied, the default OpenColorIO
///             color configuration found by examining the `$OCIO`
///             environment variable will be used instead.
///
pub fn ocio_file_transform_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    name: &str,
    unpremult: bool,
    inverse: bool,
    color_config: Option<&ColorConfig>,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_ociofiletransform_in(
            &mut result,
            dst.ptr,
            src.ptr,
            StringView::from(name).0,
            unpremult,
            inverse,
            if let Some(cc) = color_config {
                cc.0
            } else {
                std::ptr::null_mut()
            },
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// The `unpremult` operation returns (or copies into `dst`) the pixels of
/// `src` within the ROI, and in the process divides all color channels
/// (those not alpha or z) by the alpha value, to "un-premultiply" them.
/// This presumes that the image starts of as "associated alpha" a.k.a.
/// "premultipled," and you are converting to "unassociated alpha." For
/// pixels with alpha == 0, the color values are not modified.
///
pub fn unpremult(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_unpremult(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// The `unpremult` operation returns (or copies into `dst`) the pixels of
/// `src` within the ROI, and in the process divides all color channels
/// (those not alpha or z) by the alpha value, to "un-premultiply" them.
/// This presumes that the image starts of as "associated alpha" a.k.a.
/// "premultipled," and you are converting to "unassociated alpha." For
/// pixels with alpha == 0, the color values are not modified.
///
pub fn unpremult_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_unpremult_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// The `premult` operation returns (or copies into `dst`) the pixels of
/// `src` within the ROI, and in the process multiplies all color channels
/// (those not alpha or z) by the alpha value, to "premultiply" them.  This
/// presumes that the image starts of as "unassociated alpha" a.k.a.
/// "non-premultipled" and converts it to "associated alpha / premultipled."
///
pub fn premult(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_premult(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// The `premult` operation returns (or copies into `dst`) the pixels of
/// `src` within the ROI, and in the process multiplies all color channels
/// (those not alpha or z) by the alpha value, to "premultiply" them.  This
/// presumes that the image starts of as "unassociated alpha" a.k.a.
/// "non-premultipled" and converts it to "associated alpha / premultipled."
///
pub fn premult_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_premult_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// The `repremult` operation is like `premult`, but preserves the color
/// values of pixels whose alpha is 0. This is intended for cases where you
/// unpremult, do an operation (such as color transforms), then want to
/// return to associated/premultiplied alpha -- in that case, you want to
/// make sure that "glow" pixels (those with alpha=0 but RGB > 0) are
/// preserved for the round trip, and not crushed to black. This use case is
/// distinct from a simple `premult` that is a one-time conversion from
/// unassociated to associated alpha.
///
pub fn repremult(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_repremult(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// The `repremult` operation is like `premult`, but preserves the color
/// values of pixels whose alpha is 0. This is intended for cases where you
/// unpremult, do an operation (such as color transforms), then want to
/// return to associated/premultiplied alpha -- in that case, you want to
/// make sure that "glow" pixels (those with alpha=0 but RGB > 0) are
/// preserved for the round trip, and not crushed to black. This use case is
/// distinct from a simple `premult` that is a one-time conversion from
/// unassociated to associated alpha.
///
pub fn repremult_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_repremult_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return the "deep" equivalent of the "flat" input `src`. Turning a flat
/// image into a deep one means:
///
/// * If the `src` image has a "Z" channel: if the source pixel's Z channel
///   value is not infinite, the corresponding pixel of `dst` will get a
///   single depth sample that copies the data from the source pixel;
///   otherwise, dst will get an empty pixel. In other words, infinitely far
///   pixels will not turn into deep samples.
///
/// * If the `src` image lacks a "Z" channel: if any of the source pixel's
///   channel values are nonzero, the corresponding pixel of `dst` will get
///   a single depth sample that copies the data from the source pixel and
///   uses the zvalue parameter for the depth; otherwise, if all source
///   channels in that pixel are zero, the destination pixel will get no
///   depth samples.
///
/// If `src` is already a deep image, it will just copy pixel values from
/// `src`.
///
pub fn deepen(
    src: &ImageBuf,
    z_value: f32,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_deepen(
            &mut ptr,
            src.ptr,
            z_value,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return the "deep" equivalent of the "flat" input `src`. Turning a flat
/// image into a deep one means:
///
/// * If the `src` image has a "Z" channel: if the source pixel's Z channel
///   value is not infinite, the corresponding pixel of `dst` will get a
///   single depth sample that copies the data from the source pixel;
///   otherwise, dst will get an empty pixel. In other words, infinitely far
///   pixels will not turn into deep samples.
///
/// * If the `src` image lacks a "Z" channel: if any of the source pixel's
///   channel values are nonzero, the corresponding pixel of `dst` will get
///   a single depth sample that copies the data from the source pixel and
///   uses the zvalue parameter for the depth; otherwise, if all source
///   channels in that pixel are zero, the destination pixel will get no
///   depth samples.
///
/// If `src` is already a deep image, it will just copy pixel values from
/// `src`.
///
pub fn deepen_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    z_value: f32,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_deepen_in(
            &mut result,
            dst.ptr,
            src.ptr,
            z_value,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return the "flattened" composite of deep image `src`. That is, it
/// converts a deep image to a simple flat image by front-to- back
/// compositing the samples within each pixel.  If `src` is already a
/// non-deep/flat image, it will just copy pixel values from `src` to `dst`.
/// If `dst` is not already an initialized ImageBuf, it will be sized to
/// match `src` (but made non-deep).
///
pub fn flatten(src: &ImageBuf, roi: Roi, nthreads: usize) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_flatten(
            &mut ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return the "flattened" composite of deep image `src`. That is, it
/// converts a deep image to a simple flat image by front-to- back
/// compositing the samples within each pixel.  If `src` is already a
/// non-deep/flat image, it will just copy pixel values from `src` to `dst`.
/// If `dst` is not already an initialized ImageBuf, it will be sized to
/// match `src` (but made non-deep).
///
pub fn flatten_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_flatten_in(
            &mut result,
            dst.ptr,
            src.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return the deep merge of the samples of deep images `A` and `B`,
/// overwriting any existing samples of `dst` in the ROI. If
/// `occlusion_cull` is true, any samples occluded by an opaque sample will
/// be deleted.
///
pub fn deep_merge(
    a: &ImageBuf,
    b: &ImageBuf,
    occlusion_cull: bool,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_deep_merge(
            &mut ptr,
            a.ptr,
            b.ptr,
            occlusion_cull,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return the deep merge of the samples of deep images `A` and `B`,
/// overwriting any existing samples of `dst` in the ROI. If
/// `occlusion_cull` is true, any samples occluded by an opaque sample will
/// be deleted.
///
pub fn deep_merge_in(
    dst: &mut ImageBuf,
    a: &ImageBuf,
    b: &ImageBuf,
    occlusion_cull: bool,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_deep_merge_in(
            &mut result,
            dst.ptr,
            a.ptr,
            b.ptr,
            occlusion_cull,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}

/// Return the deep merge of the samples of deep images `A` and `B`,
/// overwriting any existing samples of `dst` in the ROI. If
/// `occlusion_cull` is true, any samples occluded by an opaque sample will
/// be deleted.
///
pub fn deep_holdout(
    src: &ImageBuf,
    holdout: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
    let mut ptr = std::ptr::null_mut();
    unsafe {
        sys::OIIO_ImageBufAlgo_deep_holdout(
            &mut ptr,
            src.ptr,
            holdout.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    ImageBuf { ptr }
}

/// Return the deep holdout of the samples of deep images `A` and `B`,
/// overwriting any existing samples of `dst` in the ROI. If
/// `occlusion_cull` is true, any samples occluded by an opaque sample will
/// be deleted.
///
pub fn deep_holdout_in(
    dst: &mut ImageBuf,
    src: &ImageBuf,
    holdout: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> Result<()> {
    let mut result = false;
    unsafe {
        sys::OIIO_ImageBufAlgo_deep_holdout_in(
            &mut result,
            dst.ptr,
            src.ptr,
            holdout.ptr,
            roi.into(),
            nthreads
                .try_into()
                .expect("nthreads is not representable as i32"),
        );
    }

    if result {
        Ok(())
    } else {
        Err(Error::Oiio(get_error(true)))
    }
}
