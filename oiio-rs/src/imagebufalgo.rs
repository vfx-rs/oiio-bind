use crate::cppstd::CppString;
use crate::error::{get_error, Error};
use crate::filesystem::IOProxy;
use crate::imagebuf::ImageBuf;
use crate::imagecache::ImageCache;
use crate::imageio::{
    get_trampoline, ImageOutputOpened, ImageSpec, ImageSpecRef, Roi, Stride,
    Strides,
};
use crate::span::{SpanF32, SpanI32, SpanString};
use crate::typedesc::TypeDesc;

use crate::string_view::StringView;
use crate::traits::Pixel;

use oiio_sys as sys;

use std::convert::TryInto;
use std::os::raw::c_void;
use std::path::Path;

type Result<T, E = Error> = std::result::Result<T, E>;

pub enum ImageOrConst<'a> {
    Buf(&'a ImageBuf),
    Slice(&'a [f32]),
    Const(f32),
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
pub fn crop(
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
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
pub fn cut(
    src: &ImageBuf,
    roi: Roi,
    nthreads: usize,
) -> ImageBuf {
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
