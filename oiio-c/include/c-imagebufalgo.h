#pragma once
#include <c-imagebuf.h>
#include <c-imageio.h>
#include <c-span.h>
#include <c-std_string.h>
#include <c-std_vector.h>
#include <c-string_view.h>
#include <c-typedesc.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenImageIO_v2_3_6__ColorProcessor_t_s OpenImageIO_v2_3_6__ColorProcessor_t;
typedef OpenImageIO_v2_3_6__ColorProcessor_t OIIO_ColorProcessor_t;
typedef struct std__vector_float__t_s std__vector_float__t;
typedef std__vector_float__t std_vector_float_t;
typedef struct OpenImageIO_v2_3_6__ColorConfig_t_s OpenImageIO_v2_3_6__ColorConfig_t;
typedef OpenImageIO_v2_3_6__ColorConfig_t OIIO_ColorConfig_t;
typedef struct Imath_3_2__Matrix33_float__t_s Imath_3_2__Matrix33_float__t;
typedef Imath_3_2__Matrix33_float__t Imath_M33f_t;
typedef struct Imath_3_2__Matrix44_float__t_s Imath_3_2__Matrix44_float__t;
typedef Imath_3_2__Matrix44_float__t Imath_M44f_t;
typedef struct OpenImageIO_v2_3_6__Filter2D_t_s OpenImageIO_v2_3_6__Filter2D_t;
typedef OpenImageIO_v2_3_6__Filter2D_t OIIO_Filter2D_t;
typedef struct OpenImageIO_v2_3_6__ImageBuf_t_s OpenImageIO_v2_3_6__ImageBuf_t;
typedef OpenImageIO_v2_3_6__ImageBuf_t OIIO_ImageBuf_t;

enum OpenImageIO_v2_3_6__ImageBufAlgo__TextAlignX_e {
    OIIO_ImageBufAlgo_TextAlignX_Left = 0,
    OIIO_ImageBufAlgo_TextAlignX_Right = 1,
    OIIO_ImageBufAlgo_TextAlignX_Center = 2,
};
typedef unsigned int OIIO_ImageBufAlgo_TextAlignX;
enum OpenImageIO_v2_3_6__ImageBufAlgo__TextAlignY_e {
    OIIO_ImageBufAlgo_TextAlignY_Baseline = 0,
    OIIO_ImageBufAlgo_TextAlignY_Top = 1,
    OIIO_ImageBufAlgo_TextAlignY_Bottom = 2,
    OIIO_ImageBufAlgo_TextAlignY_Center = 3,
};
typedef unsigned int OIIO_ImageBufAlgo_TextAlignY;
/** @} */
enum OpenImageIO_v2_3_6__ImageBufAlgo__NonFiniteFixMode_e {
    OIIO_ImageBufAlgo_NonFiniteFixMode_NONFINITE_NONE = 0,
    OIIO_ImageBufAlgo_NonFiniteFixMode_NONFINITE_BLACK = 1,
    OIIO_ImageBufAlgo_NonFiniteFixMode_NONFINITE_BOX3 = 2,
    OIIO_ImageBufAlgo_NonFiniteFixMode_NONFINITE_ERROR = 100,
};
typedef unsigned int OIIO_ImageBufAlgo_NonFiniteFixMode;
/** @} */
enum OpenImageIO_v2_3_6__ImageBufAlgo__MakeTextureMode_e {
    OIIO_ImageBufAlgo_MakeTextureMode_MakeTxTexture = 0,
    OIIO_ImageBufAlgo_MakeTextureMode_MakeTxShadow = 1,
    OIIO_ImageBufAlgo_MakeTextureMode_MakeTxEnvLatl = 2,
    OIIO_ImageBufAlgo_MakeTextureMode_MakeTxEnvLatlFromLightProbe = 3,
    OIIO_ImageBufAlgo_MakeTextureMode_MakeTxBumpWithSlopes = 4,
    OIIO_ImageBufAlgo_MakeTextureMode__MakeTxLast = 5,
};
typedef unsigned int OIIO_ImageBufAlgo_MakeTextureMode;

/** Image_or_Const: Parameter-passing helper that is a non-owning reference
to either an `ImageBuf&`, `ImageBuf*`, per-channel float constant, or a
single float constant. This lets us tame the combinatorics of functions
where each of several input parameters may be either images or constant
values. */
typedef struct OpenImageIO_v2_3_6__Image_or_Const_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__Image_or_Const_t;
typedef OpenImageIO_v2_3_6__Image_or_Const_t OIIO_Image_or_Const_t;

typedef struct OpenImageIO_v2_3_6__Image_or_Const__None_t_s {
    char data[1];
} __attribute__((aligned(1))) OpenImageIO_v2_3_6__Image_or_Const__None_t;
typedef OpenImageIO_v2_3_6__Image_or_Const__None_t OIIO_Image_or_Const_None_t;

typedef struct OpenImageIO_v2_3_6__ImageBufAlgo__CompareResults_t_s {
    double meanerror;
    double rms_error;
    double PSNR;
    double maxerror;
    int maxx;
    int maxy;
    int maxz;
    int maxc;
    unsigned long nwarn;
    unsigned long nfail;
    _Bool error;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__ImageBufAlgo__CompareResults_t;
typedef OpenImageIO_v2_3_6__ImageBufAlgo__CompareResults_t OIIO_ImageBufAlgo_CompareResults_t;


unsigned int OpenImageIO_v2_3_6__Image_or_Const_none(
    OIIO_Image_or_Const_t * * this_
    , OIIO_Image_or_Const_None_t n);
#define OIIO_Image_or_Const_none OpenImageIO_v2_3_6__Image_or_Const_none


unsigned int OpenImageIO_v2_3_6__Image_or_Const_from_imagebuf(
    OIIO_Image_or_Const_t * * this_
    , OIIO_ImageBuf_t const * img);
#define OIIO_Image_or_Const_from_imagebuf OpenImageIO_v2_3_6__Image_or_Const_from_imagebuf


unsigned int OpenImageIO_v2_3_6__Image_or_Const_from_float(
    OIIO_Image_or_Const_t * * this_
    , float const * val);
#define OIIO_Image_or_Const_from_float OpenImageIO_v2_3_6__Image_or_Const_from_float


unsigned int OpenImageIO_v2_3_6__Image_or_Const_from_float_vector(
    OIIO_Image_or_Const_t * * this_
    , std_vector_float_t const * val);
#define OIIO_Image_or_Const_from_float_vector OpenImageIO_v2_3_6__Image_or_Const_from_float_vector


unsigned int OpenImageIO_v2_3_6__Image_or_Const_from_float_array(
    OIIO_Image_or_Const_t * * this_
    , float const * v
    , unsigned long s);
#define OIIO_Image_or_Const_from_float_array OpenImageIO_v2_3_6__Image_or_Const_from_float_array


unsigned int OpenImageIO_v2_3_6__Image_or_Const_is_img(
    OIIO_Image_or_Const_t const * this_
    , _Bool * return_);
#define OIIO_Image_or_Const_is_img OpenImageIO_v2_3_6__Image_or_Const_is_img


unsigned int OpenImageIO_v2_3_6__Image_or_Const_is_val(
    OIIO_Image_or_Const_t const * this_
    , _Bool * return_);
#define OIIO_Image_or_Const_is_val OpenImageIO_v2_3_6__Image_or_Const_is_val


unsigned int OpenImageIO_v2_3_6__Image_or_Const_is_empty(
    OIIO_Image_or_Const_t const * this_
    , _Bool * return_);
#define OIIO_Image_or_Const_is_empty OpenImageIO_v2_3_6__Image_or_Const_is_empty


unsigned int OpenImageIO_v2_3_6__Image_or_Const_imgptr(
    OIIO_Image_or_Const_t const * this_
    , OIIO_ImageBuf_t const * * return_);
#define OIIO_Image_or_Const_imgptr OpenImageIO_v2_3_6__Image_or_Const_imgptr


unsigned int OpenImageIO_v2_3_6__Image_or_Const_val(
    OIIO_Image_or_Const_t const * this_
    , OIIO_cspan_float_t * return_);
#define OIIO_Image_or_Const_val OpenImageIO_v2_3_6__Image_or_Const_val


unsigned int OpenImageIO_v2_3_6__Image_or_Const_swap(
    OIIO_Image_or_Const_t * this_
    , OIIO_Image_or_Const_t * other);
#define OIIO_Image_or_Const_swap OpenImageIO_v2_3_6__Image_or_Const_swap


unsigned int OpenImageIO_v2_3_6__Image_or_Const_copy(
    OIIO_Image_or_Const_t * * this_
    , OIIO_Image_or_Const_t const * rhs);
#define OIIO_Image_or_Const_copy OpenImageIO_v2_3_6__Image_or_Const_copy


unsigned int OpenImageIO_v2_3_6__Image_or_Const_dtor(
    OIIO_Image_or_Const_t * this_);
#define OIIO_Image_or_Const_dtor OpenImageIO_v2_3_6__Image_or_Const_dtor


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__Image_or_Const__None_sizeof();
#define OIIO_Image_or_Const_None_sizeof OpenImageIO_v2_3_6__Image_or_Const__None_sizeof


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__Image_or_Const__None_alignof();
#define OIIO_Image_or_Const_None_alignof OpenImageIO_v2_3_6__Image_or_Const__None_alignof


/** Create an all-black `float` image of size and channels as described by
the ROI. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_zero(
    OIIO_ImageBuf_t * * return_
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_zero OpenImageIO_v2_3_6_ImageBufAlgo_zero


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_zero_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_zero_in OpenImageIO_v2_3_6_ImageBufAlgo_zero_in


/** @defgroup fill (ImageBufAlgo::fill -- fill a region)
@{

Fill an image region with given channel values, either returning a new
image or altering the existing `dst` image within the ROI.  Note that the
values arrays start with channel 0, even if the ROI indicates that a
later channel is the first to be changed.

Three varieties of fill() exist: (a) a single set of channel values that
will apply to the whole ROI, (b) two sets of values that will create a
linearly interpolated gradient from top to bottom of the ROI, (c) four
sets of values that will be bilinearly interpolated across all four
corners of the ROI. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fill(
    OIIO_ImageBuf_t * * return_
    , OIIO_cspan_float_t values
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_fill OpenImageIO_v2_3_6_ImageBufAlgo_fill


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fill_grad2(
    OIIO_ImageBuf_t * * return_
    , OIIO_cspan_float_t top
    , OIIO_cspan_float_t bottom
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_fill_grad2 OpenImageIO_v2_3_6_ImageBufAlgo_fill_grad2


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fill_grad4(
    OIIO_ImageBuf_t * * return_
    , OIIO_cspan_float_t topleft
    , OIIO_cspan_float_t topright
    , OIIO_cspan_float_t bottomleft
    , OIIO_cspan_float_t bottomright
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_fill_grad4 OpenImageIO_v2_3_6_ImageBufAlgo_fill_grad4


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fill_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_cspan_float_t values
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_fill_in OpenImageIO_v2_3_6_ImageBufAlgo_fill_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fill_grad2_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_cspan_float_t top
    , OIIO_cspan_float_t bottom
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_fill_grad2_in OpenImageIO_v2_3_6_ImageBufAlgo_fill_grad2_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fill_grad4_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_cspan_float_t topleft
    , OIIO_cspan_float_t topright
    , OIIO_cspan_float_t bottomleft
    , OIIO_cspan_float_t bottomright
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_fill_grad4_in OpenImageIO_v2_3_6_ImageBufAlgo_fill_grad4_in


/** Create a checkerboard pattern of size given by `roi`, with origin given
by the `offset` values, checker size given by the `width`, `height`,
`depth` values, and alternating between `color1[]` and `color2[]`.  The
pattern is defined in abstract "image space" independently of the pixel
data window of `dst` or the ROI. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_checker(
    OIIO_ImageBuf_t * * return_
    , int width
    , int height
    , int depth
    , OIIO_cspan_float_t color1
    , OIIO_cspan_float_t color2
    , int xoffset
    , int yoffset
    , int zoffset
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_checker OpenImageIO_v2_3_6_ImageBufAlgo_checker


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_checker_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , int width
    , int height
    , int depth
    , OIIO_cspan_float_t color1
    , OIIO_cspan_float_t color2
    , int xoffset
    , int yoffset
    , int zoffset
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_checker_in OpenImageIO_v2_3_6_ImageBufAlgo_checker_in


/** Return an image of "noise" in every pixel and channel specified by the
roi. There are several noise types to choose from, and each behaves
differently and has a different interpretation of the `A` and `B`
parameters:

- "gaussian"   adds Gaussian (normal distribution) noise values with
                  mean value A and standard deviation B.
- "uniform"    adds noise values uniformly distributed on range [A,B).
- "salt"       changes to value A a portion of pixels given by B.

If the `mono` flag is true, a single noise value will be applied to all
channels specified by `roi`, but if `mono` is false, a separate noise
value will be computed for each channel in the region.

The random number generator is actually driven by a hash on the "image
space" coordinates and channel, independently of the pixel data window
of `dst` or the ROI. Choosing different seed values will result in a
different pattern, but for the same seed value, the noise at a given
pixel coordinate (x,y,z) channel c will is completely deterministic and
repeatable. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_noise(
    OIIO_ImageBuf_t * * return_
    , OIIO_string_view_t noisetype
    , float A
    , float B
    , _Bool mono
    , int seed
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_noise OpenImageIO_v2_3_6_ImageBufAlgo_noise


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_noise_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_string_view_t noisetype
    , float A
    , float B
    , _Bool mono
    , int seed
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_noise_in OpenImageIO_v2_3_6_ImageBufAlgo_noise_in


/** Render a single point at (x,y) of the given color "over" the existing
image `dst`. If there is no alpha channel, the color will be written
unconditionally (as if the alpha is 1.0). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_render_point(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , int x
    , int y
    , OIIO_cspan_float_t color
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_render_point OpenImageIO_v2_3_6_ImageBufAlgo_render_point


/** Render a line from pixel (`x1`,`y1`) to (`x2`,`y2`) into `dst`, doing an
"over" of the color (if it includes an alpha channel) onto the existing
data in `dst`. The `color` should include as many values as
`roi.chend-1`. The ROI can be used to limit the pixel area or channels
that are modified, and default to the entirety of `dst`. If
`skip_first_point` is `true`, the first point (`x1`, `y1`) will not be
drawn (this can be helpful when drawing poly-lines, to avoid
double-rendering of the vertex positions). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_render_line(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , int x1
    , int y1
    , int x2
    , int y2
    , OIIO_cspan_float_t color
    , _Bool skip_first_point
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_render_line OpenImageIO_v2_3_6_ImageBufAlgo_render_line


/** Render a filled or unfilled box with corners at pixels (`x1`,`y1`) and
(`x2`,`y2`) into `dst`, doing an "over" of the color (if it includes an
alpha channel) onto the existing data in `dst`. The `color` must include
as many values as `roi.chend-1`. The ROI can be used to limit the pixel
area or channels that are modified, and default to the entirety of
`dst`. If `fill` is `true`, the box will be completely filled in,
otherwise only its outlien will be drawn. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_render_box(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , int x1
    , int y1
    , int x2
    , int y2
    , OIIO_cspan_float_t color
    , _Bool fill
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_render_box OpenImageIO_v2_3_6_ImageBufAlgo_render_box


/** Render a text string (encoded as UTF-8) into image `dst`. If the `dst`
image is not yet initialized, it will be initialized to be a black
background exactly large enough to contain the rasterized text.  If
`dst` is already initialized, the text will be rendered into the
existing image by essentially doing an "over" of the character into the
existing pixel data.

@param dst
            Destination ImageBuf -- text is rendered into this image.
@param x/y
            The position to place the text.
@param text
            The text to draw. Linefeed (`\n`) characters are respected
            as indications that the text spans multiple rows.
@param fontsize/fontname
            Size and name of the font. If the name is not a full
            pathname to a font file, it will search for a matching font,
            defaulting to some reasonable system font if not supplied at
            all), and with a nominal height of fontsize (in pixels).
@param textcolor
            Color for drawing the text, defaulting to opaque white
            (1.0,1.0,...) in all channels if not supplied. If provided,
            it is expected to point to a float array of length at least
            equal to `R.spec().nchannels`, or defaults will be chosen
            for you).
@param alignx/aligny
            The default behavior is to align the left edge of the
            character baseline to (`x`,`y`). Optionally, `alignx` and
            `aligny` can override the alignment behavior, with
            horizontal alignment choices of TextAlignX::Left, Right, and
            Center, and vertical alignment choices of Baseline, Top,
            Bottom, or Center.
@param shadow
            If nonzero, a "drop shadow" of this radius will be used to
            make the text look more clear by dilating the alpha channel
            of the composite (makes a black halo around the characters). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_render_text(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , int x
    , int y
    , OIIO_string_view_t text
    , int fontsize
    , OIIO_string_view_t fontname
    , OIIO_cspan_float_t textcolor
    , OIIO_ImageBufAlgo_TextAlignX alignx
    , OIIO_ImageBufAlgo_TextAlignY aligny
    , int shadow
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_render_text OpenImageIO_v2_3_6_ImageBufAlgo_render_text


/** The helper function `text_size()` merely computes the dimensions of the
text, returning it as an ROI relative to the left side of the baseline
of the first character. Only the `x` and `y` dimensions of the ROI will
be used. The x dimension runs from left to right, and y runs from top to
bottom (image coordinates). For a failure (such as an invalid font
name), the ROI will return `false` if you call its `defined()` method.
The `text` may contain linefeed characters to designate multiple lines
of text. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_text_size(
    OIIO_ROI_t * return_
    , OIIO_string_view_t text
    , int fontsize
    , OIIO_string_view_t fontname);
#define OIIO_ImageBufAlgo_text_size OpenImageIO_v2_3_6_ImageBufAlgo_text_size


/** Generic channel shuffling: return (or store in `dst`) a copy of `src`,
but with channels in the order `channelorder[0..nchannels-1]` (or set to
a constant value, designated by `channelorder[0] = -1` and having the
fill value in `channelvalues[i]`. In-place operation is allowed (i.e.,
`dst` and `src` the same image, but an extra copy will occur).

@param  nchannels
            The total number of channels that will be set up in the
            `dst` image.
@param  channelorder
            For each channel in `dst`, the index of he `src` channel
            from which to copy. Any `channelorder[i]` < 0 indicates that
            the channel `i` should be filled with constant value
            `channelvalues[i]` rather than copy any channel from `src`.
            If `channelorder` itself is empty, the implied channel order
            will be `{0, 1, ..., nchannels-1}`, meaning that it's only
            renaming channels, not reordering them.
@param  channelvalues Fill values for color channels in which
            `channelorder[i]` < 0.
@param  newchannelnames
            An array of new channel names. Channels for which this
            specifies an empty string will have their name taken from
            the `src` channel that was copied. If `newchannelnames` is
            entirely empty, all channel names will simply be copied from
            `src`.
@param  shuffle_channel_names
            If true, the channel names will be taken from the
            corresponding channels of the source image -- be careful
            with this, shuffling both channel ordering and their names
            could result in no semantic change at all, if you catch the
            drift. If false (the default), If false, the resulting `dst`
            image will have default channel names in the usual order
            ("R", "G", etc.), but i */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_channels(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , int nchannels
    , OIIO_cspan_int_t channelorder
    , OIIO_cspan_float_t channelvalues
    , OIIO_cspan_string_t newchannelnames
    , _Bool shuffle_channel_names
    , int nthreads);
#define OIIO_ImageBufAlgo_channels OpenImageIO_v2_3_6_ImageBufAlgo_channels


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_channels_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , int nchannels
    , OIIO_cspan_int_t channelorder
    , OIIO_cspan_float_t channelvalues
    , OIIO_cspan_string_t newchannelnames
    , _Bool shuffle_channel_names
    , int nthreads);
#define OIIO_ImageBufAlgo_channels_in OpenImageIO_v2_3_6_ImageBufAlgo_channels_in


/** Append the channels of `A` and `B` together into `dst` over the region
of interest.  If the region passed is uninitialized (the default), it
will be interpreted as being the union of the pixel windows of `A` and `B`
(and all channels of both images).  If `dst` is not already initialized,
it will be resized to be big enough for the region. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_channel_append(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_channel_append OpenImageIO_v2_3_6_ImageBufAlgo_channel_append


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_channel_append_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_channel_append_in OpenImageIO_v2_3_6_ImageBufAlgo_channel_append_in


/** Return the specified region of pixels of `src` as specified by `roi`
(which will default to the whole of `src`, optionally with the pixel
type overridden by convert (if it is not `TypeUnknown`). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_copy(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_TypeDesc_t convert
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_copy OpenImageIO_v2_3_6_ImageBufAlgo_copy


/** Write to an existing image `dst` (allocating if it is uninitialized).
If `dst` is not already initialized, it will be set to the same size as
`roi` (defaulting to all of `src`) */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_copy_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_TypeDesc_t convert
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_copy_in OpenImageIO_v2_3_6_ImageBufAlgo_copy_in


/** Return the specified region of `src` as an image, without altering its
position in the image plane.

Pixels from `src` which are outside `roi` will not be copied, and new
black pixels will be added for regions of `roi` which were outside the
data window of `src`.

Note that the `crop` operation does not actually move the pixels on the
image plane or adjust the full/display window; it merely restricts which
pixels are copied from `src` to `dst`.  (Note the difference compared to
`cut()`). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_crop(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_crop OpenImageIO_v2_3_6_ImageBufAlgo_crop


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_crop_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_crop_in OpenImageIO_v2_3_6_ImageBufAlgo_crop_in


/** Return the designated region of `src`, but repositioned to the image
origin and with the full/display window set to exactly cover the new
pixel data window. (Note the difference compared to `crop()`). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_cut(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_cut OpenImageIO_v2_3_6_ImageBufAlgo_cut


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_cut_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_cut_in OpenImageIO_v2_3_6_ImageBufAlgo_cut_in


/** Copy `src` pixels within `srcroi` into the `dst` image, offset so that
source location (0,0,0) will be copied to destination location
(`xbegin`,`ybegin`,`zbegin`). If the `srcroi` is `ROI::All()`, the
entirety of the data window of `src` will be used.  It will copy into
`channels[chbegin...]`, as many channels as are described by srcroi.
Pixels or channels of `src` inside `srcroi` will replace the
corresponding destination pixels entirely, whereas `src` pixels outside
of `srcroi` will not be copied and the corresponding offset pixels of
`dst` will not be altered. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_paste(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , int xbegin
    , int ybegin
    , int zbegin
    , int chbegin
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t srcroi
    , int nthreads);
#define OIIO_ImageBufAlgo_paste OpenImageIO_v2_3_6_ImageBufAlgo_paste


/** @defgroup rotateN (rotate in 90 degree increments)
@{

Return (or copy into `dst`) a rotated copy of the image pixels of `src`,
in 90 degree increments. Pictorially:

     rotate90             rotate180            rotate270
    -----------          -----------          -----------
    AB  -->  CA          AB  -->  DC          AB  -->  BD
    CD       DB          CD       BA          CD       AC */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate90(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rotate90 OpenImageIO_v2_3_6_ImageBufAlgo_rotate90


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate180(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rotate180 OpenImageIO_v2_3_6_ImageBufAlgo_rotate180


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate270(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rotate270 OpenImageIO_v2_3_6_ImageBufAlgo_rotate270


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate90_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rotate90_in OpenImageIO_v2_3_6_ImageBufAlgo_rotate90_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate180_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rotate180_in OpenImageIO_v2_3_6_ImageBufAlgo_rotate180_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate270_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rotate270_in OpenImageIO_v2_3_6_ImageBufAlgo_rotate270_in


/** @defgroup flip-flop-transpose (flip/flop/transpose: mirroring)
@{

Return (or copy into `dst`) a subregion of `src`, but with the scanlines
exchanged vertically (flip), or columns exchanged horizontally (flop),
or transposed across the diagonal by swapping rows for columns
(transpose) within the display/full window. In other words,

       flip                 flop               transpose
    -----------          -----------          -----------
    AB  -->  CD          AB  -->  BA          AB  -->  AC
    CD       AB          CD       DC          CD       BD */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_flip(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_flip OpenImageIO_v2_3_6_ImageBufAlgo_flip


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_flop(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_flop OpenImageIO_v2_3_6_ImageBufAlgo_flop


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_transpose(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_transpose OpenImageIO_v2_3_6_ImageBufAlgo_transpose


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_flip_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_flip_in OpenImageIO_v2_3_6_ImageBufAlgo_flip_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_flop_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_flop_in OpenImageIO_v2_3_6_ImageBufAlgo_flop_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_transpose_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_transpose_in OpenImageIO_v2_3_6_ImageBufAlgo_transpose_in


/** Return (or store into `dst`) a copy of `src`, but with whatever seties
of rotations, flips, or flops are necessary to transform the pixels into
the configuration suggested by the "Orientation" metadata of the image
(and the "Orientation" metadata is then set to 1, ordinary orientation). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_reorient(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , int nthreads);
#define OIIO_ImageBufAlgo_reorient OpenImageIO_v2_3_6_ImageBufAlgo_reorient


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_reorient_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , int nthreads);
#define OIIO_ImageBufAlgo_reorient_in OpenImageIO_v2_3_6_ImageBufAlgo_reorient_in


/** Return a subregion of `src`, but circularly shifting by the given
amount.  To clarify, the circular shift of [0,1,2,3,4,5] by +2 is
[4,5,0,1,2,3]. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_circular_shift(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , int xshift
    , int yshift
    , int zshift
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_circular_shift OpenImageIO_v2_3_6_ImageBufAlgo_circular_shift


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_circular_shift_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , int xshift
    , int yshift
    , int zshift
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_circular_shift_in OpenImageIO_v2_3_6_ImageBufAlgo_circular_shift_in


/** @defgroup rotate (rotate: arbitrary rotation)
@{

Rotate the `src` image by the `angle` (in radians, with positive angles
clockwise). When `center_x` and `center_y` are supplied, they denote the
center of rotation; in their absence, the rotation will be about the
center of the image's display window.

Only the pixels (and channels) of `dst` that are specified by `roi` will
be copied from the rotated `src`; the default `roi` is to alter all the
pixels in `dst`. If `dst` is uninitialized, it will be resized to be an
ImageBuf large enough to hold the rotated image if recompute_roi is
true, or will have the same ROI as `src` if `recompute_roi` is `false`.
It is an error to pass both an uninitialized `dst` and an undefined
`roi`.

The filter is used to weight the `src` pixels falling underneath it for
each `dst` pixel.  The caller may specify a reconstruction filter by
name and width (expressed in pixels units of the `dst` image), or
`rotate()` will choose a reasonable default high-quality default filter
(lanczos3) if the empty string is passed, and a reasonable filter width
if `filterwidth` is 0. (Note that some filter choices only make sense
with particular width, in which case this filterwidth parameter may be
ignored.) */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , float angle
    , OIIO_string_view_t filtername
    , float filterwidth
    , _Bool recompute_roi
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rotate OpenImageIO_v2_3_6_ImageBufAlgo_rotate


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_filter(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , float angle
    , OIIO_Filter2D_t * filter
    , _Bool recompute_roi
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rotate_with_filter OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_filter


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_center(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , float angle
    , float center_x
    , float center_y
    , OIIO_string_view_t filtername
    , float filterwidth
    , _Bool recompute_roi
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rotate_with_center OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_center


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_filter_and_center(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , float angle
    , float center_x
    , float center_y
    , OIIO_Filter2D_t * filter
    , _Bool recompute_roi
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rotate_with_filter_and_center OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_filter_and_center


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , float angle
    , OIIO_string_view_t filtername
    , float filterwidth
    , _Bool recompute_roi
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rotate_in OpenImageIO_v2_3_6_ImageBufAlgo_rotate_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_filter_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , float angle
    , OIIO_Filter2D_t * filter
    , _Bool recompute_roi
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rotate_with_filter_in OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_filter_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_center_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , float angle
    , float center_x
    , float center_y
    , OIIO_string_view_t filtername
    , float filterwidth
    , _Bool recompute_roi
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rotate_with_center_in OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_center_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_filter_and_center_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , float angle
    , float center_x
    , float center_y
    , OIIO_Filter2D_t * filter
    , _Bool recompute_roi
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rotate_with_filter_and_center_in OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_filter_and_center_in


/** @defgroup resize (resize: resize the image with nicely filtered results)
@{

Set `dst`, over the region of interest, to be a resized version of the
corresponding portion of `src` (mapping such that the "full" image
window of each correspond to each other, regardless of resolution).
If `dst` is not yet initialized, it will be sized according to `roi`.

The caller may either (a) explicitly pass a reconstruction `filter`, or
(b) specify one by `filtername` and `filterwidth`. If `filter` is
`nullptr` or if `filtername` is the empty string `resize()` will choose
a reasonable high-quality default (blackman-harris when upsizing,
lanczos3 when downsizing).  The filter is used to weight the `src`
pixels falling underneath it for each `dst` pixel; the filter's size is
expressed in pixel units of the `dst` image. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_resize(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t filtername
    , float filterwidth
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_resize OpenImageIO_v2_3_6_ImageBufAlgo_resize


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_resize_with_filter(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_Filter2D_t * filter
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_resize_with_filter OpenImageIO_v2_3_6_ImageBufAlgo_resize_with_filter


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_resize_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t filtername
    , float filterwidth
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_resize_in OpenImageIO_v2_3_6_ImageBufAlgo_resize_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_resize_with_filter_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_Filter2D_t * filter
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_resize_with_filter_in OpenImageIO_v2_3_6_ImageBufAlgo_resize_with_filter_in


/** Set `dst`, over the region of interest, to be a resized version of the
corresponding portion of `src` (mapping such that the "full" image
window of each correspond to each other, regardless of resolution).  If
`dst` is not yet initialized, it will be sized according to `roi`.

Unlike `ImageBufAlgo::resize()`, `resample()` does not take a filter; it
just samples either with a bilinear interpolation (if `interpolate` is
`true`, the default) or uses the single "closest" pixel (if
`interpolate` is `false`).  This makes it a lot faster than a proper
`resize()`, though obviously with lower quality (aliasing when
downsizing, pixel replication when upsizing).

For "deep" images, this function returns copies the closest source pixel
needed, rather than attempting to interpolate deep pixels (regardless of
the value of `interpolate`). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_resample(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , _Bool interpolate
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_resample OpenImageIO_v2_3_6_ImageBufAlgo_resample


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_resample_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , _Bool interpolate
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_resample_in OpenImageIO_v2_3_6_ImageBufAlgo_resample_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fit(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t filtername
    , float filterwidth
    , _Bool exact
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_fit OpenImageIO_v2_3_6_ImageBufAlgo_fit


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fit_with_filter(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_Filter2D_t * filter
    , _Bool exact
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_fit_with_filter OpenImageIO_v2_3_6_ImageBufAlgo_fit_with_filter


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fit_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t filtername
    , float filterwidth
    , _Bool exact
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_fit_in OpenImageIO_v2_3_6_ImageBufAlgo_fit_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fit_with_filter_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_Filter2D_t * filter
    , _Bool exact
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_fit_with_filter_in OpenImageIO_v2_3_6_ImageBufAlgo_fit_with_filter_in


/** @defgroup warp (warp: arbitrary warp by a 3x3 matrix)
@{

Warp the `src` image using the supplied 3x3 transformation matrix.

Only the pixels (and channels) of `dst` that are specified by `roi` will
be copied from the warped `src`; the default roi is to alter all the
pixels in dst. If `dst` is uninitialized, it will be sized to be an
ImageBuf large enough to hold the warped image if recompute_roi is true,
or will have the same ROI as src if recompute_roi is false. It is an
error to pass both an uninitialized `dst` and an undefined `roi`.

The caller may explicitly pass a reconstruction filter, or specify one
by name and size, or if the name is the empty string `resize()` will
choose a reasonable high-quality default if `nullptr` is passed.  The
filter is used to weight the `src` pixels falling underneath it for each
`dst` pixel; the filter's size is expressed in pixel units of the `dst`
image. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_warp(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , Imath_M33f_t const * M
    , OIIO_string_view_t filtername
    , float filterwidth
    , _Bool recompute_roi
    , OIIO_ImageBuf_WrapMode wrap
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_warp OpenImageIO_v2_3_6_ImageBufAlgo_warp


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_warp_with_filter(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , Imath_M33f_t const * M
    , OIIO_Filter2D_t const * filter
    , _Bool recompute_roi
    , OIIO_ImageBuf_WrapMode wrap
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_warp_with_filter OpenImageIO_v2_3_6_ImageBufAlgo_warp_with_filter


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_warp_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , Imath_M33f_t const * M
    , OIIO_string_view_t filtername
    , float filterwidth
    , _Bool recompute_roi
    , OIIO_ImageBuf_WrapMode wrap
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_warp_in OpenImageIO_v2_3_6_ImageBufAlgo_warp_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_warp_with_filter_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , Imath_M33f_t const * M
    , OIIO_Filter2D_t const * filter
    , _Bool recompute_roi
    , OIIO_ImageBuf_WrapMode wrap
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_warp_with_filter_in OpenImageIO_v2_3_6_ImageBufAlgo_warp_with_filter_in


/** Compute per-pixel sum `A + B`, returning the result image.

`A` and `B` may each either be an `ImageBuf&`, or a `cspan<float>`
giving a per- channel constant, or a single constant used for all
channels. (But at least one must be an image.) */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_add(
    OIIO_ImageBuf_t * * return_
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_add OpenImageIO_v2_3_6_ImageBufAlgo_add


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_add_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_add_in OpenImageIO_v2_3_6_ImageBufAlgo_add_in


/** Compute per-pixel signed difference `A - B`, returning the result image.

`A` and `B` may each either be an `ImageBuf&`, or a `cspan<float>`
giving a per-channel constant, or a single constant used for all
channels. (But at least one must be an image.) */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_sub(
    OIIO_ImageBuf_t * * return_
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_sub OpenImageIO_v2_3_6_ImageBufAlgo_sub


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_sub_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_sub_in OpenImageIO_v2_3_6_ImageBufAlgo_sub_in


/** Compute per-pixel absolute difference `abs(A - B)`, returning the result
image.

`A` and `B` may each either be an `ImageBuf&`, or a `cspan<float>`
giving a per- channel constant, or a single constant used for all
channels. (But at least one must be an image.) */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_absdiff(
    OIIO_ImageBuf_t * * return_
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_absdiff OpenImageIO_v2_3_6_ImageBufAlgo_absdiff


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_absdiff_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_absdiff_in OpenImageIO_v2_3_6_ImageBufAlgo_absdiff_in


/** Compute per-pixel absolute value `abs(A)`, returning the result image. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_abs(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_abs OpenImageIO_v2_3_6_ImageBufAlgo_abs


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_abs_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * A
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_abs_in OpenImageIO_v2_3_6_ImageBufAlgo_abs_in


/** Compute per-pixel product `A * B`, returning the result image.

Either both `A` and `B` are images, or one is an image and the other is
a `cspan<float>` giving a per-channel constant or a single constant
used for all channels. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_mul(
    OIIO_ImageBuf_t * * return_
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_mul OpenImageIO_v2_3_6_ImageBufAlgo_mul


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_mul_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_mul_in OpenImageIO_v2_3_6_ImageBufAlgo_mul_in


/** Compute per-pixel division `A / B`, returning the result image.
Division by zero is defined to result in zero.

`A` is always an image, and `B` is either an image or a `cspan<float>`
giving a per-channel constant or a single constant used for all
channels. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_div(
    OIIO_ImageBuf_t * * return_
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_div OpenImageIO_v2_3_6_ImageBufAlgo_div


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_div_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_div_in OpenImageIO_v2_3_6_ImageBufAlgo_div_in


/** Compute per-pixel multiply-and-add `A * B + C`, returning the result
image.

`A`, `B`, and `C` are each either an image, or a `cspan<float>` giving a
per-channel constant or a single constant used for all channels. (Note:
at least one must be an image.) */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_mad(
    OIIO_ImageBuf_t * * return_
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_Image_or_Const_t C
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_mad OpenImageIO_v2_3_6_ImageBufAlgo_mad


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_mad_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_Image_or_Const_t C
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_mad_in OpenImageIO_v2_3_6_ImageBufAlgo_mad_in


/** Return the composite of `A` over `B` using the Porter/Duff definition of
"over", returning true upon success and false for any of a variety of
failures (as described below).

`A` and `B` (and dst, if already defined/allocated) must have valid
alpha channels identified by their ImageSpec `alpha_channel` field.  If`
A` or `B` do not have alpha channels (as determined by those rules) or
if the number of non-alpha channels do not match between `A` and `B`,
`over()` will fail, returning false.

If `dst` is not already an initialized ImageBuf, it will be sized to
encompass the minimal rectangular pixel region containing the union of
the defined pixels of `A` and `B`, and with a number of channels equal
to the number of non-alpha channels of `A` and `B`, plus an alpha
channel.  However, if `dst` is already initialized, it will not be
resized, and the "over" operation will apply to its existing pixel data
window.  In this case, dst must have an alpha channel designated and
must have the same number of non-alpha channels as `A` and `B`,
otherwise it will fail, returning false.

`A`, `B`, and `dst` need not perfectly overlap in their pixel data
windows; pixel values of `A` or `B` that are outside their respective
pixel data window will be treated as having "zero" (0,0,0...) value. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_over(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_over OpenImageIO_v2_3_6_ImageBufAlgo_over


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_over_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_over_in OpenImageIO_v2_3_6_ImageBufAlgo_over_in


/** Just like `ImageBufAlgo::over()`, but inputs `A` and `B` must have
designated 'z' channels, and on a pixel-by-pixel basis, the z values
will determine which of `A` or `B` will be considered the foreground or
background (lower z is foreground).  If `z_zeroisinf` is true, then z=0
values will be treated as if they are infinitely far away. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_zover(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , _Bool z_zeroisinf
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_zover OpenImageIO_v2_3_6_ImageBufAlgo_zover


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_zover_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , _Bool z_zeroisinf
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_zover_in OpenImageIO_v2_3_6_ImageBufAlgo_zover_in


/** Compute per-pixel value inverse `1.0 - A` (which you can think of as
roughly meaning switching white and black), returning the result image.

Tips for callers: (1) You probably want to set `roi` to restrict the
operation to only the color channels, and not accidentally include
alpha, z, or others. (2) There may be situations where you want to
`unpremult()` before the invert, then `premult()` the result, so that
you are computing the inverse of the unmasked color. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_invert(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_invert OpenImageIO_v2_3_6_ImageBufAlgo_invert


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_invert_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * A
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_invert_in OpenImageIO_v2_3_6_ImageBufAlgo_invert_in


/** Compute per-pixel raise-to-power `A ^ B`. returning the result image. It
is permitted for `dst` and `A` to be the same image.

`A` is always an image, and `B` is either an image or a `cspan<float>`
giving a per-channel constant or a single constant used for all
channels. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_pow(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_cspan_float_t B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_pow OpenImageIO_v2_3_6_ImageBufAlgo_pow


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_pow_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * A
    , OIIO_cspan_float_t B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_pow_in OpenImageIO_v2_3_6_ImageBufAlgo_pow_in


/** Converts a multi-channel image into a one-channel image via a weighted
sum of channels:

    (channel[0]*weight[0] + channel[1]*weight[1] + ...)

returning the resulting one-channel image. The `weights`, if not
supplied, default to `{ 1, 1, 1, ... }`). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_channel_sum(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_cspan_float_t weights
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_channel_sum OpenImageIO_v2_3_6_ImageBufAlgo_channel_sum


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_channel_sum_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_cspan_float_t weights
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_channel_sum_in OpenImageIO_v2_3_6_ImageBufAlgo_channel_sum_in


/** Compute per-pixel `max(A, B)`, returning the result image.

Either both `A` and `B` are images, or one is an image and the other is
a `cspan<float>` giving a per-channel constant or a single constant
used for all channels. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_max(
    OIIO_ImageBuf_t * * return_
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_max OpenImageIO_v2_3_6_ImageBufAlgo_max


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_max_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_max_in OpenImageIO_v2_3_6_ImageBufAlgo_max_in


/** Compute per-pixel `min(A, B)`, returning the result image.

Either both `A` and `B` are images, or one is an image and the other is
a `cspan<float>` giving a per-channel constant or a single constant
used for all channels. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_min(
    OIIO_ImageBuf_t * * return_
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_min OpenImageIO_v2_3_6_ImageBufAlgo_min


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_min_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_min_in OpenImageIO_v2_3_6_ImageBufAlgo_min_in


/** Return pixels of `src` with pixel values clamped as follows:
* `min` specifies the minimum clamp value for each channel
  (if min is empty, no minimum clamping is performed).
* `max` specifies the maximum clamp value for each channel
  (if `max` is empty, no maximum clamping is performed).
* If `clampalpha01` is true, then additionally any alpha channel is
  clamped to the 0-1 range. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_clamp(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_cspan_float_t min
    , OIIO_cspan_float_t max
    , _Bool clampalpha01
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_clamp OpenImageIO_v2_3_6_ImageBufAlgo_clamp


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_clamp_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_cspan_float_t min
    , OIIO_cspan_float_t max
    , _Bool clampalpha01
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_clamp_in OpenImageIO_v2_3_6_ImageBufAlgo_clamp_in


/** Return pixel values that are a contrast-remap of the corresponding
values of the `src` image, transforming pixel value domain [black,
white] to range [min, max], either linearly or with optional application
of a smooth sigmoidal remapping (if `scontrast` != 1.0).

The following steps are performed, in order:

1. Linearly rescale values [`black`, `white`] to [0, 1].
2. If `scontrast` != 1, apply a sigmoidal remapping where a larger
   `scontrast` value makes a steeper slope, and the steepest part is at
   value `sthresh` (relative to the new remapped value after steps 1 &
   2; the default is 0.5).
3. Rescale the range of that result: 0.0 -> `min` and 1.0 -> `max`.

Values outside of the [black,white] range will be extrapolated to
outside [min,max], so it may be prudent to apply a clamp() to the
results.

The black, white, min, max, scontrast, sthresh parameters may each
either be a single float value for all channels, or a span giving
per-channel values.

You can use this function for a simple linear contrast remapping of
[black, white] to [min, max] if you use the default values for sthresh.
Or just a simple sigmoidal contrast stretch within the [0,1] range if
you leave all other parameters at their defaults, or a combination of
these effects. Note that if `black` == `white`, the result will be a
simple binary thresholding where values < `black` map to `min` and
values >= `black` map to `max`. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_contrast_remap(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_cspan_float_t black
    , OIIO_cspan_float_t white
    , OIIO_cspan_float_t min
    , OIIO_cspan_float_t max
    , OIIO_cspan_float_t scontrast
    , OIIO_cspan_float_t sthresh
    , OIIO_ROI_t _param7
    , int nthreads);
#define OIIO_ImageBufAlgo_contrast_remap OpenImageIO_v2_3_6_ImageBufAlgo_contrast_remap


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_contrast_remap_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_cspan_float_t black
    , OIIO_cspan_float_t white
    , OIIO_cspan_float_t min
    , OIIO_cspan_float_t max
    , OIIO_cspan_float_t scontrast
    , OIIO_cspan_float_t sthresh
    , OIIO_ROI_t _param8
    , int nthreads);
#define OIIO_ImageBufAlgo_contrast_remap_in OpenImageIO_v2_3_6_ImageBufAlgo_contrast_remap_in


/** @defgroup color_map (Remap value range by spline or name)
@{

Remap value range by spline or name

Return (or copy into `dst`) pixel values determined by looking up a
color map using values of the source image, using either the channel
specified by `srcchannel`, or the luminance of `src`'s RGB if
`srcchannel` is -1. This happens for all pixels within the  ROI (which
defaults to all of `src`), and if `dst` is not already initialized, it
will be initialized to the ROI and with color channels equal to
`channels`.

In the variant that takes a `knots` parameter, this specifies the values
of a linearly-interpolated color map given by `knots[nknots*channels]`.
An input value of 0.0 is mapped to `knots[0..channels-1]` (one value for
each color channel), and an input value of 1.0 is mapped to
`knots[(nknots-1)*channels..knots.size()-1]`.

In the variant that takes a `mapname` parameter, this is the name of a
color map. Recognized map names include: "inferno", "viridis", "magma",
"plasma", all of which are perceptually uniform, strictly increasing in
luminance, look good when converted to grayscale, and work for people
with all types of colorblindness. Also "turbo" has most of these
properties (except for being strictly increasing in luminance) and
is a nice rainbow-like pattern. Also supported are the following color
maps that do not have those desirable qualities (and are thus not
recommended, but are present for back-compatibility or for use by
clueless people): "blue-red", "spectrum", and "heat". In all cases, the
implied `channels` is 3. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_color_map(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , int srcchannel
    , int nknots
    , int channels
    , OIIO_cspan_float_t knots
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_color_map OpenImageIO_v2_3_6_ImageBufAlgo_color_map


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_color_map_named(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , int srcchannel
    , OIIO_string_view_t mapname
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_color_map_named OpenImageIO_v2_3_6_ImageBufAlgo_color_map_named


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_color_map_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , int srcchannel
    , int nknots
    , int channels
    , OIIO_cspan_float_t knots
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_color_map_in OpenImageIO_v2_3_6_ImageBufAlgo_color_map_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_color_map_named_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , int srcchannel
    , OIIO_string_view_t mapname
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_color_map_named_in OpenImageIO_v2_3_6_ImageBufAlgo_color_map_named_in


/** @defgroup range (Nonlinear range remapping for contrast preservation)
@{

Nonlinear range remapping for contrast preservation

`rangecompress()` returns (or copy into `dst`) all pixels and color
channels of `src` within region `roi` (defaulting to all the defined
pixels of `dst`), rescaling their range with a logarithmic
transformation. Alpha and z channels are not transformed.

`rangeexpand()` performs the inverse transformation (logarithmic back
into linear).

If `useluma` is true, the luma of channels [roi.chbegin..roi.chbegin+2]
(presumed to be R, G, and B) are used to compute a single scale factor
for all color channels, rather than scaling all channels individually
(which could result in a color shift).

The purpose of these function is as follows: Some image operations (such
as resizing with a "good" filter that contains negative lobes) can have
objectionable artifacts when applied to images with very high-contrast
regions involving extra bright pixels (such as highlights in HDR
captured or rendered images).  By compressing the range pixel values,
then performing the operation, then expanding the range of the result
again, the result can be much more pleasing (even if not exactly
correct). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rangecompress(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , _Bool useluma
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rangecompress OpenImageIO_v2_3_6_ImageBufAlgo_rangecompress


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rangeexpand(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , _Bool useluma
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rangeexpand OpenImageIO_v2_3_6_ImageBufAlgo_rangeexpand


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rangecompress_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , _Bool useluma
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rangecompress_in OpenImageIO_v2_3_6_ImageBufAlgo_rangecompress_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rangeexpand_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , _Bool useluma
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_rangeexpand_in OpenImageIO_v2_3_6_ImageBufAlgo_rangeexpand_in


/** Numerically compare two images.  The difference threshold (for any
individual color channel in any pixel) for a "failure" is
failthresh, and for a "warning" is warnthresh.  The results are
stored in result.  If roi is defined, pixels will be compared for
the pixel and channel range that is specified.  If roi is not
defined, the comparison will be for all channels, on the union of
the defined pixel windows of the two images (for either image,
undefined pixels will be assumed to be black). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_compare(
    OIIO_ImageBufAlgo_CompareResults_t * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , float failthresh
    , float warnthresh
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_compare OpenImageIO_v2_3_6_ImageBufAlgo_compare


/** Compare two images using Hector Yee's perceptual metric, returning
the number of pixels that fail the comparison.  Only the first three
channels (or first three channels specified by `roi`) are compared.
Free parameters are the ambient luminance in the room and the field
of view of the image display; our defaults are probably reasonable
guesses for an office environment.  The 'result' structure will
store the maxerror, and the maxx, maxy, maxz of the pixel that
failed most severely.  (The other fields of the CompareResults
are not used for Yee comparison.)

Works for all pixel types.  But it's basically meaningless if the
first three channels aren't RGB in a linear color space that sort
of resembles AdobeRGB.

Return true on success, false on error. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_compare_Yee(
    int * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , OIIO_ImageBufAlgo_CompareResults_t * result
    , float luminance
    , float fov
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_compare_Yee OpenImageIO_v2_3_6_ImageBufAlgo_compare_Yee


/** Do all pixels within the ROI have the same values for channels
`[roi.chbegin..roi.chend-1]`, within a tolerance of +/- `threshold`?  If
so, return `true` and store that color in `color[chbegin...chend-1]` (if
`color` is not empty); otherwise return `false`.  If `roi` is not
defined (the default), it will be understood to be all of the defined
pixels and channels of source. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_isConstantColor(
    _Bool * return_
    , OIIO_ImageBuf_t const * src
    , float threshold
    , OIIO_span_float_t color
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_isConstantColor OpenImageIO_v2_3_6_ImageBufAlgo_isConstantColor


/** Does the requested channel have a given value (within a tolerance of +/-
`threshold`) for every channel within the ROI?  (For this function, the
ROI's chbegin/chend are ignored.)  Return `true` if so, otherwise return
`false`.  If `roi` is not defined (the default), it will be understood
to be all of the defined pixels and channels of source. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_isConstantChannel(
    _Bool * return_
    , OIIO_ImageBuf_t const * src
    , int channel
    , float val
    , float threshold
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_isConstantChannel OpenImageIO_v2_3_6_ImageBufAlgo_isConstantChannel


/** Is the image monochrome within the ROI, i.e., for every pixel within the
region, do all channels [roi.chbegin, roi.chend) have the same value
(within a tolerance of +/- threshold)?  If roi is not defined (the
default), it will be understood to be all of the defined pixels and
channels of source. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_isMonochrome(
    _Bool * return_
    , OIIO_ImageBuf_t const * src
    , float threshold
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_isMonochrome OpenImageIO_v2_3_6_ImageBufAlgo_isMonochrome


/** Count how many pixels in the ROI match a list of colors. The colors to
match are in::

    colors[0 ... nchans-1]
    colors[nchans ... 2*nchans-1]
    ...
    colors[(ncolors-1)*nchans ... (ncolors*nchans)-1]

and so on, a total of `ncolors` consecutively stored colors of `nchans`
channels each (`nchans` is the number of channels in the image, itself,
it is not passed as a parameter).

`eps[0..nchans-1]` are the error tolerances for a match, for each
channel. Setting `eps[c]` = `numeric_limits<float>::max()` will
effectively make it ignore the channel.  The default `eps` is 0.001 for
all channels (this value is chosen because it requires exact matches for
8 bit images, but allows a wee bit of imprecision for float images.

Upon success, return `true` and store the number of pixels that matched
each color `count[..ncolors-1]`.  If there is an error, returns `false`
and sets an appropriate error message set in `src`. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_color_count(
    _Bool * return_
    , OIIO_ImageBuf_t const * src
    , unsigned long * count
    , int ncolors
    , OIIO_cspan_float_t color
    , OIIO_cspan_float_t eps
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_color_count OpenImageIO_v2_3_6_ImageBufAlgo_color_count


/** Count how many pixels in the image (within the ROI) are outside the
value range described by `low[roi.chbegin..roi.chend-1]` and
`high[roi.chbegin..roi.chend-1]` as the low and high acceptable values
for each color channel.

The number of pixels containing values that fall below the lower bound
will be stored in `*lowcount`, the number of pixels containing
values that fall above the upper bound will be stored in 
`*highcount`, and the number of pixels for which all channels fell
within the bounds will be stored in `*inrangecount`.  Any of these
may be NULL, which simply means that the counts need not be collected or
stored. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_color_range_check(
    _Bool * return_
    , OIIO_ImageBuf_t const * src
    , unsigned long * lowcount
    , unsigned long * highcount
    , unsigned long * inrangecount
    , OIIO_cspan_float_t low
    , OIIO_cspan_float_t high
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_color_range_check OpenImageIO_v2_3_6_ImageBufAlgo_color_range_check


/** Find the minimal rectangular region within `roi` (which defaults to the
entire pixel data window of `src`) that consists of nonzero pixel
values.  In other words, gives the region that is a "shrink-wraps" of
`src` to exclude black border pixels.  Note that if the entire image was
black, the ROI returned will contain no pixels.

For "deep" images, this function returns the smallest ROI that contains
all pixels that contain depth samples, and excludes the border pixels
that contain no depth samples at all. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_nonzero_region(
    OIIO_ROI_t * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_nonzero_region OpenImageIO_v2_3_6_ImageBufAlgo_nonzero_region


/** Compute the SHA-1 byte hash for all the pixels in the specifed region of
the image.  If `blocksize` > 0, the function will compute separate SHA-1
hashes of each `blocksize` batch of scanlines, then return a hash of the
individual hashes.  This is just as strong a hash, but will NOT match a
single hash of the entire image (`blocksize==0`).  But by breaking up
the hash into independent blocks, we can parallelize across multiple
threads, given by `nthreads` (if `nthreads` is 0, it will use the global
OIIO thread count).  The `extrainfo` provides additional text that will
be incorporated into the hash. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_computePixelHashSHA1(
    std_string_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t extrainfo
    , OIIO_ROI_t roi
    , int blocksize
    , int nthreads);
#define OIIO_ImageBufAlgo_computePixelHashSHA1 OpenImageIO_v2_3_6_ImageBufAlgo_computePixelHashSHA1


/** Compute a histogram of `src`, for the given channel and ROI. Return a
vector of length `bins` that contains the counts of how many pixel
values were in each of `bins` equally spaced bins covering the range of
values `[min,max]`. Values < `min` count for bin 0, values > `max` count
for bin `nbins-1`. If `ignore_empty` is `true`, no counts will be
incremented for any pixels whose value is 0 in all channels. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_histogram(
    std_vector_ulong_t * * return_
    , OIIO_ImageBuf_t const * src
    , int channel
    , int bins
    , float min
    , float max
    , _Bool ignore_empty
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_histogram OpenImageIO_v2_3_6_ImageBufAlgo_histogram


/** Make a 1-channel `float` image of the named kernel. The size of the
image will be big enough to contain the kernel given its size (`width` x
`height`) and rounded up to odd resolution so that the center of the
kernel can be at the center of the middle pixel.  The kernel image will
be offset so that its center is at the (0,0) coordinate.  If `normalize`
is true, the values will be normalized so that they sum to 1.0. If
`depth` > 1, a volumetric kernel will be created.  Use with caution!

Kernel names can be: "gaussian", "sharp-gaussian", "box",
"triangle", "blackman-harris", "mitchell", "b-spline", "catmull-rom",
"lanczos3", "disk", "binomial", "laplacian".

Note that "catmull-rom" and "lanczos3" are fixed-size kernels that
don't scale with the width, and are therefore probably less useful
in most cases. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_make_kernel(
    OIIO_ImageBuf_t * * return_
    , OIIO_string_view_t name
    , float width
    , float height
    , float depth
    , _Bool normalize);
#define OIIO_ImageBufAlgo_make_kernel OpenImageIO_v2_3_6_ImageBufAlgo_make_kernel


/** Return the convolution of `src` and a `kernel`. If `roi` is not defined,
it defaults to the full size `src`. If `normalized` is true, the kernel will
be normalized for the  convolution, otherwise the original values will
be used. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_convolve(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ImageBuf_t const * kernel
    , _Bool normalize
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_convolve OpenImageIO_v2_3_6_ImageBufAlgo_convolve


/** Write to an existing image `dst` (allocating if it is uninitialized).
If `roi` is not defined, it defaults to the full size of `dst` (or
`src`, if `dst` was uninitialized).  If `dst` is uninitialized, it will
be allocated to be the size specified by `roi`. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_convolve_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ImageBuf_t const * kernel
    , _Bool normalize
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_convolve_in OpenImageIO_v2_3_6_ImageBufAlgo_convolve_in


/** Return the Laplacian of the corresponding region of `src`.  The
Laplacian is the generalized second derivative of the image
\f[
\frac{\partial^2 s}{\partial x^2} + \frac{\partial^2 s}{\partial y^2}
\f]
which is approximated by convolving the image with a discrete 3x3
Laplacian kernel,

                    [ 0  1  0 ]
                    [ 1 -4  1 ]
                    [ 0  1  0 ] */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_laplacian(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_laplacian OpenImageIO_v2_3_6_ImageBufAlgo_laplacian


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_laplacian_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_laplacian_in OpenImageIO_v2_3_6_ImageBufAlgo_laplacian_in


/** @defgroup fft-ifft (Fast Fourier Transform and inverse)
@{

Fast Fourier Transform and inverse

Return (or copy into `dst`) the discrete Fourier transform (DFT), or its
inverse, of the section of `src` denoted by roi,  If roi is not defined,
it will be all of `src`'s pixels.

`fft()` takes the discrete Fourier transform (DFT) of the section of
`src` denoted by `roi`, returning it or storing it in `dst`. If `roi` is
not defined, it will be all of `src`'s pixels. Only one channel of `src`
may be transformed at a time, so it will be the first channel described
by `roi` (or, again, channel 0 if `roi` is undefined).  If not already
in the correct format, `dst` will be re-allocated to be a 2-channel
`float` buffer of size `roi.width()` x `roi.height`, with channel 0
being the "real" part and channel 1 being the the "imaginary" part.  The
values returned are actually the unitary DFT, meaning that it is scaled
by 1/sqrt(npixels).

`ifft()` takes the inverse discrete Fourier transform, transforming a
2-channel complex (real and imaginary) frequency domain image and into a
single-channel spatial domain image. `src` must be a 2-channel float
image, and is assumed to be a complex frequency-domain signal with the
"real" component in channel 0 and the "imaginary" component in channel 1.
`dst` will end up being a float image of one channel (the real component
is kept, the imaginary component of the spatial-domain will be
discarded). Just as with `fft()`, the `ifft()` function is dealing with
the unitary DFT, so it is scaled by 1/sqrt(npixels). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fft(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_fft OpenImageIO_v2_3_6_ImageBufAlgo_fft


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_ifft(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_ifft OpenImageIO_v2_3_6_ImageBufAlgo_ifft


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fft_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_fft_in OpenImageIO_v2_3_6_ImageBufAlgo_fft_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_ifft_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_ifft_in OpenImageIO_v2_3_6_ImageBufAlgo_ifft_in


/** @defgroup complex-polar (Converting complex to polar and back)
@{

Converting complex to polar and back

The `polar_to_complex()` function transforms a 2-channel image whose
channels are interpreted as complex values (real and imaginary
components) into the equivalent values expressed in polar form of
amplitude and phase (with phase between 0 and \f$ 2\pi \f$.

The `complex_to_polar()` function performs the reverse transformation,
converting from  polar values (amplitude and phase) to complex (real and
imaginary).

In either case,  the section of `src` denoted by `roi` is transformed,
storing the result in `dst`. If `roi` is not defined, it will be all of
`src`'s pixels.  Only the first two channels of `src` will be
transformed.

The transformation between the two representations are:

    real = amplitude * cos(phase);
    imag = amplitude * sin(phase);

    amplitude = hypot (real, imag);
    phase = atan2 (imag, real); */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_complex_to_polar(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_complex_to_polar OpenImageIO_v2_3_6_ImageBufAlgo_complex_to_polar


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_complex_to_polar_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_complex_to_polar_in OpenImageIO_v2_3_6_ImageBufAlgo_complex_to_polar_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_polar_to_complex(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_polar_to_complex OpenImageIO_v2_3_6_ImageBufAlgo_polar_to_complex


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_polar_to_complex_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_polar_to_complex_in OpenImageIO_v2_3_6_ImageBufAlgo_polar_to_complex_in


/** `fixNonFinite()` returns in image containing the values of `src` (within
the ROI), while repairing  any non-finite (NaN/Inf) pixels. If
pixelsFixed is not nullptr, store in it the number of pixels that
contained non-finite value.  It is permissible to operate in-place (with
`src` and  `dst` referring to the same image).

How the non-finite values are repaired is specified by one of the `mode`
parameter, which is an enum of `NonFiniteFixMode`.

This function works on all pixel data types, though it's just a copy for
images with pixel data types that cannot represent NaN or Inf values. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fixNonFinite(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ImageBufAlgo_NonFiniteFixMode mode
    , int * pixelsFixed
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_fixNonFinite OpenImageIO_v2_3_6_ImageBufAlgo_fixNonFinite


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fixNonFinite_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ImageBufAlgo_NonFiniteFixMode mode
    , int * pixelsFixed
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_fixNonFinite_in OpenImageIO_v2_3_6_ImageBufAlgo_fixNonFinite_in


/** Copy the specified ROI of `src` and fill any holes (pixels where alpha <
1) with plausible values using a push-pull technique. The `src` image
must have an alpha channel.  The `dst` image will end up with a copy of
`src`, but will have an alpha of 1.0 everywhere within `roi`, and any
place where the alpha of `src` was < 1, `dst` will have a pixel color
that is a plausible "filling" of the original alpha hole. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fillholes_pushpull(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_fillholes_pushpull OpenImageIO_v2_3_6_ImageBufAlgo_fillholes_pushpull


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fillholes_pushpull_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_fillholes_pushpull_in OpenImageIO_v2_3_6_ImageBufAlgo_fillholes_pushpull_in


/** Return a median-filtered version of the corresponding region of `src`.
The median filter replaces each pixel with the median value underneath
the `width` x `height` window surrounding it. If `height` <= 0, it will
be set to `width`, making a square window.

Median filters are good for removing high-frequency detail smaller than
the window size (including noise), without blurring edges that are
larger than the window size. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_median_filter(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , int width
    , int height
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_median_filter OpenImageIO_v2_3_6_ImageBufAlgo_median_filter


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_median_filter_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , int width
    , int height
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_median_filter_in OpenImageIO_v2_3_6_ImageBufAlgo_median_filter_in


/** Return a sharpened version of the corresponding region of `src` using
the "unsharp mask" technique. Unsharp masking basically works by first
blurring the image (low pass filter), subtracting this from the original
image, then adding the residual back to the original to emphasize the
edges. Roughly speaking,

     dst = src + contrast * thresh(src - blur(src))

The specific blur can be selected by kernel name and width (for example,
"gaussian" is typical). As a special case, "median" is also accepted as
the kernel name, in which case a median filter is performed rather than
a blurring convolution (Gaussian and other blurs sometimes over-sharpen
edges, whereas using the median filter will sharpen compact
high-frequency details while not over-sharpening long edges).

The `contrast` is a multiplier on the overall sharpening effect.  The
thresholding step causes all differences less than `threshold` to be
squashed to zero, which can be useful for suppressing sharpening of
low-contrast details (like noise) but allow sharpening of
higher-contrast edges. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_unsharp_mask(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t kernel
    , float width
    , float contrast
    , float threshold
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_unsharp_mask OpenImageIO_v2_3_6_ImageBufAlgo_unsharp_mask


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_unsharp_mask_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t kernel
    , float width
    , float contrast
    , float threshold
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_unsharp_mask_in OpenImageIO_v2_3_6_ImageBufAlgo_unsharp_mask_in


/** Return a dilated version of the corresponding region of `src`. Dilation
is defined as the maximum value of all pixels under nonzero values of
the structuring element (which is taken to be a width x height square).
If height is not set, it will default to be the same as width. Dilation
makes bright features wider and more prominent, dark features thinner,
and removes small isolated dark spots. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_dilate(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , int width
    , int height
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_dilate OpenImageIO_v2_3_6_ImageBufAlgo_dilate


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_dilate_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , int width
    , int height
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_dilate_in OpenImageIO_v2_3_6_ImageBufAlgo_dilate_in


/** Return an eroded version of the corresponding region of `src`. Erosion
is defined as the minimum value of all pixels under nonzero values of
the structuring element (which is taken to be a width x height square).
If height is not set, it will default to be the same as width. Erosion
makes dark features wider, bright features thinner, and removes small
isolated bright spots. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_erode(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , int width
    , int height
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_erode OpenImageIO_v2_3_6_ImageBufAlgo_erode


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_erode_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , int width
    , int height
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_erode_in OpenImageIO_v2_3_6_ImageBufAlgo_erode_in


/** Transform between named color spaces, returning an ImageBuf result. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_colorconvert(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t fromspace
    , OIIO_string_view_t tospace
    , _Bool unpremult
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value
    , OIIO_ColorConfig_t * colorconfig
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_colorconvert OpenImageIO_v2_3_6_ImageBufAlgo_colorconvert


/** Transform using a ColorProcessor, returning an ImageBuf result. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_colorconvert_with_processor(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ColorProcessor_t const * processor
    , _Bool unpremult
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_colorconvert_with_processor OpenImageIO_v2_3_6_ImageBufAlgo_colorconvert_with_processor


/** Transform between named color spaces, storing reults into an existing ImageBuf. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_colorconvert_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t fromspace
    , OIIO_string_view_t tospace
    , _Bool unpremult
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value
    , OIIO_ColorConfig_t * colorconfig
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_colorconvert_in OpenImageIO_v2_3_6_ImageBufAlgo_colorconvert_in


/** Transform using a ColorProcessor, storing reults into an existing ImageBuf. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_colorconvert_with_processor_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ColorProcessor_t const * processor
    , _Bool unpremult
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_colorconvert_with_processor_in OpenImageIO_v2_3_6_ImageBufAlgo_colorconvert_with_processor_in


/** Apply a color transform in-place to just one color:
`color[0..nchannels-1]`.  `nchannels` should either be 3 or 4 (if 4, the
last channel is alpha). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_colorconvert_span(
    _Bool * return_
    , OIIO_span_float_t color
    , OIIO_ColorProcessor_t const * processor
    , _Bool unpremult);
#define OIIO_ImageBufAlgo_colorconvert_span OpenImageIO_v2_3_6_ImageBufAlgo_colorconvert_span


/** Return a copy of the pixels of `src` within the ROI, applying a color
transform specified by a 4x4 matrix.  In-place operations
(`dst` == `src`) are supported.

The first three channels are presumed to be the color to be
transformed, and the fourth channel (if it exists) is presumed to be
alpha. Any additional channels will be simply copied unaltered.

@param  M
            A 4x4 matrix. Following Imath conventions, the color is a
            row vector and the matrix has the "translation" part in
            elements [12..14] (matching the memory layout of OpenGL or
            RenderMan), so the math is `color * Matrix` (NOT `M*c`).
@param  unpremult
            If true, unpremultiply the image (divide the RGB channels by
            alpha if it exists and is nonzero) before color conversion,
            then repremult after the after the color conversion. Passing
            unpremult=false skips this step, which may be desirable if
            you know that the image is "unassociated alpha" (a.k.a.,
            "not pre-multiplied colors").

@version 2.1+ */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_colormatrixtransform(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , Imath_M44f_t const * M
    , _Bool unpremult
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_colormatrixtransform OpenImageIO_v2_3_6_ImageBufAlgo_colormatrixtransform


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_colormatrixtransform_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , Imath_M44f_t const * M
    , _Bool unpremult
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_colormatrixtransform_in OpenImageIO_v2_3_6_ImageBufAlgo_colormatrixtransform_in


/** Return a copy of the pixels of `src` within the ROI, applying an
OpenColorIO "look" transform to the pixel values. In-place operations
(`dst` == `src`) are supported.

The first three channels are presumed to be the color to be
transformed, and the fourth channel (if it exists) is presumed to be
alpha. Any additional channels will be simply copied unaltered.

@param  looks
            The looks to apply (comma-separated).
@param  fromspace/tospace
            For the varieties of `colorconvert()` that use named color
            spaces, these specify the color spaces by name.
@param  unpremult
            If true, unpremultiply the image (divide the RGB channels by
            alpha if it exists and is nonzero) before color conversion,
            then repremult after the after the color conversion. Passing
            unpremult=false skips this step, which may be desirable if
            you know that the image is "unassociated alpha" (a.k.a.,
            "not pre-multiplied colors").
@param  inverse
            If `true`, it will reverse the color transformation and look
            application.
@param  context_key/context_value
            Optional key/value to establish a context (for example, a
            shot-specific transform).
@param  colorconfig
            An optional `ColorConfig*` specifying an OpenColorIO
            configuration. If not supplied, the default OpenColorIO
            color configuration found by examining the `$OCIO`
            environment variable will be used instead. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_ociolook(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t looks
    , OIIO_string_view_t fromspace
    , OIIO_string_view_t tospace
    , _Bool unpremult
    , _Bool inverse
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value
    , OIIO_ColorConfig_t * colorconfig
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_ociolook OpenImageIO_v2_3_6_ImageBufAlgo_ociolook


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_ociolook_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t looks
    , OIIO_string_view_t fromspace
    , OIIO_string_view_t tospace
    , _Bool unpremult
    , _Bool inverse
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value
    , OIIO_ColorConfig_t * colorconfig
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_ociolook_in OpenImageIO_v2_3_6_ImageBufAlgo_ociolook_in


/** Return the pixels of `src` within the ROI, applying an OpenColorIO
"display" transform to the pixel values. In-place operations
(`dst` == `src`) are supported.

The first three channels are presumed to be the color to be
transformed, and the fourth channel (if it exists) is presumed to be
alpha. Any additional channels will be simply copied unaltered.

@param  display
            The OCIO "display" to apply. If this is the empty string,
            the default display will be used.
@param  view
            The OCIO "view" to use. If this is the empty string, the
            default view for this display will be used.
@param  fromspace
            If `fromspace` is not supplied, it will assume that the
            source color space is whatever is indicated by the source
            image's metadata or filename, and if that cannot be deduced,
            it will be assumed to be scene linear.
@param  looks
            The looks to apply (comma-separated). This may be empty,
            in which case no "look" is used. Note: this parameter value
            is not used when building against OpenColorIO 2.x.
@param  unpremult
            If true, unpremultiply the image (divide the RGB channels by
            alpha if it exists and is nonzero) before color conversion,
            then repremult after the after the color conversion. Passing
            unpremult=false skips this step, which may be desirable if
            you know that the image is "unassociated alpha" (a.k.a.,
            "not pre-multiplied colors").
@param  inverse
            If `true`, it will reverse the color transformation and
            display application.
@param  context_key/context_value
            Optional key/value to establish a context (for example, a
            shot-specific transform).
@param  colorconfig
            An optional `ColorConfig*` specifying an OpenColorIO
            configuration. If not supplied, the default OpenColorIO
            color configuration found by examining the `$OCIO`
            environment variable will be used instead. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_ociodisplay(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t display
    , OIIO_string_view_t view
    , OIIO_string_view_t fromspace
    , OIIO_string_view_t looks
    , _Bool unpremult
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value
    , OIIO_ColorConfig_t * colorconfig
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_ociodisplay OpenImageIO_v2_3_6_ImageBufAlgo_ociodisplay


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_ociodisplay_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t display
    , OIIO_string_view_t view
    , OIIO_string_view_t fromspace
    , OIIO_string_view_t looks
    , _Bool unpremult
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value
    , OIIO_ColorConfig_t * colorconfig
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_ociodisplay_in OpenImageIO_v2_3_6_ImageBufAlgo_ociodisplay_in


/** Return the pixels of `src` within the ROI, applying an OpenColorIO
"file" transform. In-place operations (`dst` == `src`) are supported.

The first three channels are presumed to be the color to be
transformed, and the fourth channel (if it exists) is presumed to be
alpha. Any additional channels will be simply copied unaltered.

@param  name
            The name of the file containing the transform information.
@param  unpremult
            If true, unpremultiply the image (divide the RGB channels by
            alpha if it exists and is nonzero) before color conversion,
            then repremult after the after the color conversion. Passing
            unpremult=false skips this step, which may be desirable if
            you know that the image is "unassociated alpha" (a.k.a.,
            "not pre-multiplied colors").
@param  inverse
            If `true`, it will reverse the color transformation.
@param  colorconfig
            An optional `ColorConfig*` specifying an OpenColorIO
            configuration. If not supplied, the default OpenColorIO
            color configuration found by examining the `$OCIO`
            environment variable will be used instead. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_ociofiletransform(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t name
    , _Bool unpremult
    , _Bool inverse
    , OIIO_ColorConfig_t * colorconfig
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_ociofiletransform OpenImageIO_v2_3_6_ImageBufAlgo_ociofiletransform


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_ociofiletransform_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t name
    , _Bool unpremult
    , _Bool inverse
    , OIIO_ColorConfig_t * colorconfig
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_ociofiletransform_in OpenImageIO_v2_3_6_ImageBufAlgo_ociofiletransform_in


/** @defgroup premult (Premultiply or un-premultiply color by alpha)
@{

Premultiply or un-premultiply color by alpha

The `unpremult` operation returns (or copies into `dst`) the pixels of
`src` within the ROI, and in the process divides all color channels
(those not alpha or z) by the alpha value, to "un-premultiply" them.
This presumes that the image starts of as "associated alpha" a.k.a.
"premultipled," and you are converting to "unassociated alpha." For
pixels with alpha == 0, the color values are not modified.

The `premult` operation returns (or copies into `dst`) the pixels of
`src` within the ROI, and in the process multiplies all color channels
(those not alpha or z) by the alpha value, to "premultiply" them.  This
presumes that the image starts of as "unassociated alpha" a.k.a.
"non-premultipled" and converts it to "associated alpha / premultipled."

The `repremult` operation is like `premult`, but preserves the color
values of pixels whose alpha is 0. This is intended for cases where you
unpremult, do an operation (such as color transforms), then want to
return to associated/premultiplied alpha -- in that case, you want to
make sure that "glow" pixels (those with alpha=0 but RGB > 0) are
preserved for the round trip, and not crushed to black. This use case is
distinct from a simple `premult` that is a one-time conversion from
unassociated to associated alpha.

All three operations are simply a copy if there is no identified alpha
channel (and a no-op if `dst` and `src` are the same image). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_unpremult(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_unpremult OpenImageIO_v2_3_6_ImageBufAlgo_unpremult


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_unpremult_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_unpremult_in OpenImageIO_v2_3_6_ImageBufAlgo_unpremult_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_premult(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_premult OpenImageIO_v2_3_6_ImageBufAlgo_premult


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_premult_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_premult_in OpenImageIO_v2_3_6_ImageBufAlgo_premult_in


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_repremult(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_repremult OpenImageIO_v2_3_6_ImageBufAlgo_repremult


unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_repremult_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_repremult_in OpenImageIO_v2_3_6_ImageBufAlgo_repremult_in


/** Return the "deep" equivalent of the "flat" input `src`. Turning a flat
image into a deep one means:

* If the `src` image has a "Z" channel: if the source pixel's Z channel
  value is not infinite, the corresponding pixel of `dst` will get a
  single depth sample that copies the data from the source pixel;
  otherwise, dst will get an empty pixel. In other words, infinitely far
  pixels will not turn into deep samples.

* If the `src` image lacks a "Z" channel: if any of the source pixel's
  channel values are nonzero, the corresponding pixel of `dst` will get
  a single depth sample that copies the data from the source pixel and
  uses the zvalue parameter for the depth; otherwise, if all source
  channels in that pixel are zero, the destination pixel will get no
  depth samples.

If `src` is already a deep image, it will just copy pixel values from
`src`. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_deepen(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , float zvalue
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_deepen OpenImageIO_v2_3_6_ImageBufAlgo_deepen


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_deepen_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , float zvalue
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_deepen_in OpenImageIO_v2_3_6_ImageBufAlgo_deepen_in


/** Return the "flattened" composite of deep image `src`. That is, it
converts a deep image to a simple flat image by front-to- back
compositing the samples within each pixel.  If `src` is already a
non-deep/flat image, it will just copy pixel values from `src` to `dst`.
If `dst` is not already an initialized ImageBuf, it will be sized to
match `src` (but made non-deep). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_flatten(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_flatten OpenImageIO_v2_3_6_ImageBufAlgo_flatten


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_flatten_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_flatten_in OpenImageIO_v2_3_6_ImageBufAlgo_flatten_in


/** Return the deep merge of the samples of deep images `A` and `B`,
overwriting any existing samples of `dst` in the ROI. If
`occlusion_cull` is true, any samples occluded by an opaque sample will
be deleted. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_deep_merge(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , _Bool occlusion_cull
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_deep_merge OpenImageIO_v2_3_6_ImageBufAlgo_deep_merge


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_deep_merge_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , _Bool occlusion_cull
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_deep_merge_in OpenImageIO_v2_3_6_ImageBufAlgo_deep_merge_in


/** Return the samples of deep image `src` that are closer than the opaque
frontier of deep image holdout, returning true upon success and false
for any failures. Samples of `src` that are farther than the first
opaque sample of holdout (for the corresponding pixel)will not be copied
to `dst`. Image holdout is only used as the depth threshold; no sample
values from holdout are themselves copied to `dst`. */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_deep_holdout(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ImageBuf_t const * holdout
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_deep_holdout OpenImageIO_v2_3_6_ImageBufAlgo_deep_holdout


/** Write to an existing image `dst` (allocating if it is uninitialized). */
unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_deep_holdout_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ImageBuf_t const * holdout
    , OIIO_ROI_t roi
    , int nthreads);
#define OIIO_ImageBufAlgo_deep_holdout_in OpenImageIO_v2_3_6_ImageBufAlgo_deep_holdout_in


#ifdef __cplusplus
}
#endif
