#pragma once
#include <c-std_pair.h>
#include <c-std_string.h>
#include <c-std_unique_ptr.h>
#include <c-string_view.h>
#include <c-typedesc.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenImageIO_v2_3_6__ParamValue_t_s OpenImageIO_v2_3_6__ParamValue_t;
typedef OpenImageIO_v2_3_6__ParamValue_t OIIO_ParamValue_t;
typedef struct OpenImageIO_v2_3_6__ParamValueList_t_s OpenImageIO_v2_3_6__ParamValueList_t;
typedef OpenImageIO_v2_3_6__ParamValueList_t OIIO_ParamValueList_t;
typedef struct std__vector_OIIO__TypeDesc__t_s std__vector_OIIO__TypeDesc__t;
typedef std__vector_OIIO__TypeDesc__t std_vector_typedesc_t;
typedef struct OpenImageIO_v2_3_6__Filesystem__IOProxy_t_s OpenImageIO_v2_3_6__Filesystem__IOProxy_t;
typedef OpenImageIO_v2_3_6__Filesystem__IOProxy_t OIIO_Filesystem_IOProxy_t;
typedef struct std__string_t_s std__string_t;
typedef std__string_t std_string_t;
typedef struct OpenImageIO_v2_3_6__DeepData_t_s OpenImageIO_v2_3_6__DeepData_t;
typedef OpenImageIO_v2_3_6__DeepData_t OIIO_DeepData_t;
typedef struct std__vector_std__string__t_s std__vector_std__string__t;
typedef std__vector_std__string__t std_vector_string_t;
typedef struct OpenImageIO_v2_3_6__TypeDesc_t_s OpenImageIO_v2_3_6__TypeDesc_t;
typedef OpenImageIO_v2_3_6__TypeDesc_t OIIO_TypeDesc_t;

typedef _Bool  (*OIIO_ProgressCallback_t)(void * , float );enum OpenImageIO_v2_3_6__ImageSpec__SerialFormat_e {
    OIIO_ImageSpec_SerialFormat_SerialText = 0,
    OIIO_ImageSpec_SerialFormat_SerialXML = 1,
};
typedef unsigned int OIIO_ImageSpec_SerialFormat;
enum OpenImageIO_v2_3_6__ImageSpec__SerialVerbose_e {
    OIIO_ImageSpec_SerialVerbose_SerialBrief = 0,
    OIIO_ImageSpec_SerialVerbose_SerialDetailed = 1,
    OIIO_ImageSpec_SerialVerbose_SerialDetailedHuman = 2,
};
typedef unsigned int OIIO_ImageSpec_SerialVerbose;
/** Modes passed to the `open()` call. */
enum OpenImageIO_v2_3_6__ImageOutput__OpenMode_e {
    OIIO_ImageOutput_OpenMode_Create = 0,
    OIIO_ImageOutput_OpenMode_AppendSubimage = 1,
    OIIO_ImageOutput_OpenMode_AppendMIPLevel = 2,
};
typedef unsigned int OIIO_ImageOutput_OpenMode;

/** ROI is a small helper struct describing a rectangular region of interest
in an image. The region is [xbegin,xend) x [begin,yend) x [zbegin,zend),
with the "end" designators signifying one past the last pixel in each
dimension, a la STL style. */
typedef struct OpenImageIO_v2_3_6__ROI_t_s {
    int xbegin;
    int xend;
    int ybegin;
    int yend;
    int zbegin;
    int zend;
    int chbegin;
    int chend;
} __attribute__((aligned(4))) OpenImageIO_v2_3_6__ROI_t;
typedef OpenImageIO_v2_3_6__ROI_t OIIO_ROI_t;

/** ImageSpec describes the data format of an image -- dimensions, layout,
number and meanings of image channels.

The `width, height, depth` are the size of the data of this image, i.e.,
the number of pixels in each dimension.  A ``depth`` greater than 1
indicates a 3D "volumetric" image. The `x, y, z` fields indicate the
*origin* of the pixel data of the image. These default to (0,0,0), but
setting them differently may indicate that this image is offset from the
usual origin.
Therefore the pixel data are defined over pixel coordinates
   [`x` ... `x+width-1`] horizontally,
   [`y` ... `y+height-1`] vertically,
   and [`z` ... `z+depth-1`] in depth.

The analogous `full_width`, `full_height`, `full_depth` and `full_x`,
`full_y`, `full_z` fields define a "full" or "display" image window over
the region [`full_x` ... `full_x+full_width-1`] horizontally, [`full_y`
... `full_y+full_height-1`] vertically, and [`full_z`...
`full_z+full_depth-1`] in depth.

Having the full display window different from the pixel data window can
be helpful in cases where you want to indicate that your image is a
*crop window* of a larger image (if the pixel data window is a subset of
the full display window), or that the pixels include *overscan* (if the
pixel data is a superset of the full display window), or may simply
indicate how different non-overlapping images piece together.

For tiled images, `tile_width`, `tile_height`, and `tile_depth` specify
that the image is stored in a file organized into rectangular *tiles*
of these dimensions. The default of 0 value for these fields indicates
that the image is stored in scanline order, rather than as tiles. */
typedef struct OpenImageIO_v2_3_6__ImageSpec_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__ImageSpec_t;
typedef OpenImageIO_v2_3_6__ImageSpec_t OIIO_ImageSpec_t;

/** ImageInput abstracts the reading of an image file in a file
format-agnostic manner. */
typedef struct OpenImageIO_v2_3_6__ImageInput_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__ImageInput_t;
typedef OpenImageIO_v2_3_6__ImageInput_t OIIO_ImageInput_t;

/** ImageOutput abstracts the writing of an image file in a file
format-agnostic manner.

Users don't directly declare these. Instead, you call the `create()`
static method, which will return a `unique_ptr` holding a subclass of
ImageOutput that implements writing the particular format. */
typedef struct OpenImageIO_v2_3_6__ImageOutput_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__ImageOutput_t;
typedef OpenImageIO_v2_3_6__ImageOutput_t OIIO_ImageOutput_t;


/** Is a region defined? */
unsigned int OpenImageIO_v2_3_6__ROI_defined(
    OIIO_ROI_t const * this_
    , _Bool * return_);
#define OIIO_ROI_defined OpenImageIO_v2_3_6__ROI_defined


/** @{
 @name Spatial size functions.
 The width, height, and depth of the region. */
unsigned int OpenImageIO_v2_3_6__ROI_width(
    OIIO_ROI_t const * this_
    , int * return_);
#define OIIO_ROI_width OpenImageIO_v2_3_6__ROI_width


unsigned int OpenImageIO_v2_3_6__ROI_height(
    OIIO_ROI_t const * this_
    , int * return_);
#define OIIO_ROI_height OpenImageIO_v2_3_6__ROI_height


unsigned int OpenImageIO_v2_3_6__ROI_depth(
    OIIO_ROI_t const * this_
    , int * return_);
#define OIIO_ROI_depth OpenImageIO_v2_3_6__ROI_depth


/** Number of channels in the region.  Beware -- this defaults to a
huge number, and to be meaningful you must consider
std::min (imagebuf.nchannels(), roi.nchannels()). */
unsigned int OpenImageIO_v2_3_6__ROI_nchannels(
    OIIO_ROI_t const * this_
    , int * return_);
#define OIIO_ROI_nchannels OpenImageIO_v2_3_6__ROI_nchannels


/** Total number of pixels in the region. */
unsigned int OpenImageIO_v2_3_6__ROI_npixels(
    OIIO_ROI_t const * this_
    , unsigned long * return_);
#define OIIO_ROI_npixels OpenImageIO_v2_3_6__ROI_npixels


/** All() is an alias for the default constructor, which indicates that
it means "all" of the image, or no region restriction.  For example,
    float myfunc (ImageBuf &buf, ROI roi = ROI::All());
Note that this is equivalent to:
    float myfunc (ImageBuf &buf, ROI roi = {}); */
unsigned int OpenImageIO_v2_3_6__ROI_All(
    OIIO_ROI_t * return_);
#define OIIO_ROI_All OpenImageIO_v2_3_6__ROI_All


/** Test if the coordinate is within the ROI. */
unsigned int OpenImageIO_v2_3_6__ROI_contains(
    OIIO_ROI_t const * this_
    , _Bool * return_
    , int x
    , int y
    , int z
    , int ch);
#define OIIO_ROI_contains OpenImageIO_v2_3_6__ROI_contains


/** Test if another ROI is entirely within our ROI. */
unsigned int OpenImageIO_v2_3_6__ROI_contains_roi(
    OIIO_ROI_t const * this_
    , _Bool * return_
    , OIIO_ROI_t const * other);
#define OIIO_ROI_contains_roi OpenImageIO_v2_3_6__ROI_contains_roi


unsigned int OpenImageIO_v2_3_6__ROI_copy(
    OIIO_ROI_t * this_
    , OIIO_ROI_t const * rhs);
#define OIIO_ROI_copy OpenImageIO_v2_3_6__ROI_copy


/** Constructor: given just the data format, set all other fields to
something reasonable. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_from_typedesc(
    OIIO_ImageSpec_t * * this_
    , OIIO_TypeDesc_t format);
#define OIIO_ImageSpec_from_typedesc OpenImageIO_v2_3_6__ImageSpec_from_typedesc


/** Constructs an `ImageSpec` with the given x and y resolution, number
of channels, and pixel data format.

All other fields are set to the obvious defaults -- the image is an
ordinary 2D image (not a volume), the image is not offset or a crop
of a bigger image, the image is scanline-oriented (not tiled),
channel names are "R", "G", "B"' and "A" (up to and including 4
channels, beyond that they are named "channel *n*"), the fourth
channel (if it exists) is assumed to be alpha. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_from_dimensions(
    OIIO_ImageSpec_t * * this_
    , int xres
    , int yres
    , int nchans
    , OIIO_TypeDesc_t fmt);
#define OIIO_ImageSpec_from_dimensions OpenImageIO_v2_3_6__ImageSpec_from_dimensions


/** Construct an `ImageSpec` whose dimensions (both data and "full") and
number of channels are given by the `ROI`, pixel data type by `fmt`,
and other fields are set to their default values. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_from_roi(
    OIIO_ImageSpec_t * * this_
    , OIIO_ROI_t const * roi
    , OIIO_TypeDesc_t fmt);
#define OIIO_ImageSpec_from_roi OpenImageIO_v2_3_6__ImageSpec_from_roi


/** Set the data format, and clear any per-channel format information
in `channelformats`. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_set_format_and_clear(
    OIIO_ImageSpec_t * this_
    , OIIO_TypeDesc_t fmt);
#define OIIO_ImageSpec_set_format_and_clear OpenImageIO_v2_3_6__ImageSpec_set_format_and_clear


/** Sets the `channelnames` to reasonable defaults for the number of
channels.  Specifically, channel names are set to "R", "G", "B,"
and "A" (up to and including 4 channels, beyond that they are named
"channel*n*". */
unsigned int OpenImageIO_v2_3_6__ImageSpec_default_channel_names(
    OIIO_ImageSpec_t * this_);
#define OIIO_ImageSpec_default_channel_names OpenImageIO_v2_3_6__ImageSpec_default_channel_names


/** Returns the number of bytes comprising each channel of each pixel
(i.e., the size of a single value of the type described by the
`format` field). */
unsigned int OpenImageIO_v2_3_6__ImageSpec_channel_bytes(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_);
#define OIIO_ImageSpec_channel_bytes OpenImageIO_v2_3_6__ImageSpec_channel_bytes


/** Return the number of bytes needed for the single specified
channel.  If native is false (default), compute the size of one
channel of `this->format`, but if native is true, compute the size
of the channel in terms of the "native" data format of that
channel as stored in the file. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_channel_bytes_for_channel(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_
    , int chan
    , _Bool native);
#define OIIO_ImageSpec_channel_bytes_for_channel OpenImageIO_v2_3_6__ImageSpec_channel_bytes_for_channel


/** Return the number of bytes for each pixel (counting all channels).
If `native` is false (default), assume all channels are in
`this->format`, but if `native` is true, compute the size of a pixel
in the "native" data format of the file (these may differ in
the case of per-channel formats). */
unsigned int OpenImageIO_v2_3_6__ImageSpec_pixel_bytes(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_
    , _Bool native);
#define OIIO_ImageSpec_pixel_bytes OpenImageIO_v2_3_6__ImageSpec_pixel_bytes


/** Return the number of bytes for just the subset of channels in each
pixel described by [chbegin,chend). If native is false (default),
assume all channels are in this->format, but if native is true,
compute the size of a pixel in the "native" data format of the file
(these may differ in the case of per-channel formats). */
unsigned int OpenImageIO_v2_3_6__ImageSpec_pixel_bytes_for_channels(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_
    , int chbegin
    , int chend
    , _Bool native);
#define OIIO_ImageSpec_pixel_bytes_for_channels OpenImageIO_v2_3_6__ImageSpec_pixel_bytes_for_channels


/** Returns the number of bytes comprising each scanline, i.e.,
`pixel_bytes(native) * width` This will return
`std::numeric_limits<imagesize_t>::max()` in the event of an
overflow where it's not representable in an `imagesize_t`. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_scanline_bytes(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_
    , _Bool native);
#define OIIO_ImageSpec_scanline_bytes OpenImageIO_v2_3_6__ImageSpec_scanline_bytes


/** Return the number of pixels comprising a tile (or 0 if it is not a
tiled image).  This will return
`std::numeric_limits<imagesize_t>::max()` in the event of an
overflow where it's not representable in an `imagesize_t`. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_tile_pixels(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_);
#define OIIO_ImageSpec_tile_pixels OpenImageIO_v2_3_6__ImageSpec_tile_pixels


/** Returns the number of bytes comprising an image tile, i.e.,
    `pixel_bytes(native) * tile_width * tile_height * tile_depth`
If native is false (default), assume all channels are in
`this->format`, but if `native` is true, compute the size of a pixel
in the "native" data format of the file (these may differ in the
case of per-channel formats). */
unsigned int OpenImageIO_v2_3_6__ImageSpec_tile_bytes(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_
    , _Bool native);
#define OIIO_ImageSpec_tile_bytes OpenImageIO_v2_3_6__ImageSpec_tile_bytes


/** Return the number of pixels for an entire image.  This will
return `std::numeric_limits<imagesize_t>::max()` in the event of
an overflow where it's not representable in an `imagesize_t`. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_image_pixels(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_);
#define OIIO_ImageSpec_image_pixels OpenImageIO_v2_3_6__ImageSpec_image_pixels


/** Returns the number of bytes comprising an entire image of these
dimensions, i.e.,
    `pixel_bytes(native) * width * height * depth`
This will return `std::numeric_limits<image size_t>::max()` in the
event of an overflow where it's not representable in an
`imagesize_t`. If `native` is false (default), assume all channels
are in `this->format`, but if `native` is true, compute the size of
a pixel in the "native" data format of the file (these may differ in
the case of per-channel formats). */
unsigned int OpenImageIO_v2_3_6__ImageSpec_image_bytes(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_
    , _Bool native);
#define OIIO_ImageSpec_image_bytes OpenImageIO_v2_3_6__ImageSpec_image_bytes


/** Verify that on this platform, a `size_t` is big enough to hold the
number of bytes (and pixels) in a scanline, a tile, and the
whole image.  If this returns false, the image is much too big
to allocate and read all at once, so client apps beware and check
these routines for overflows! */
unsigned int OpenImageIO_v2_3_6__ImageSpec_size_t_safe(
    OIIO_ImageSpec_t const * this_
    , _Bool * return_);
#define OIIO_ImageSpec_size_t_safe OpenImageIO_v2_3_6__ImageSpec_size_t_safe


/** Adjust the stride values, if set to AutoStride, to be the right
sizes for contiguous data with the given format, channels,
width, height. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_auto_stride(
    long * xstride
    , long * ystride
    , long * zstride
    , long channelsize
    , int nchannels
    , int width
    , int height);
#define OIIO_ImageSpec_auto_stride OpenImageIO_v2_3_6__ImageSpec_auto_stride


/** Adjust the stride values, if set to AutoStride, to be the right
sizes for contiguous data with the given format, channels,
width, height. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_auto_stride_with_typedesc(
    long * xstride
    , long * ystride
    , long * zstride
    , OIIO_TypeDesc_t format
    , int nchannels
    , int width
    , int height);
#define OIIO_ImageSpec_auto_stride_with_typedesc OpenImageIO_v2_3_6__ImageSpec_auto_stride_with_typedesc


/** Adjust xstride, if set to AutoStride, to be the right size for
contiguous data with the given format and channels. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_auto_stride_xstride(
    long * xstride
    , OIIO_TypeDesc_t format
    , int nchannels);
#define OIIO_ImageSpec_auto_stride_xstride OpenImageIO_v2_3_6__ImageSpec_auto_stride_xstride


/** Add a metadata attribute to `extra_attribs`, with the given name and
data type. The `value` pointer specifies the address of the data to
be copied. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_attribute(
    OIIO_ImageSpec_t * this_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void const * value);
#define OIIO_ImageSpec_attribute OpenImageIO_v2_3_6__ImageSpec_attribute


/** Add an `unsigned int` attribute to `extra_attribs`. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_attribute_uint(
    OIIO_ImageSpec_t * this_
    , OIIO_string_view_t name
    , unsigned int value);
#define OIIO_ImageSpec_attribute_uint OpenImageIO_v2_3_6__ImageSpec_attribute_uint


/** Add an `int` attribute to `extra_attribs`. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_attribute_int(
    OIIO_ImageSpec_t * this_
    , OIIO_string_view_t name
    , int value);
#define OIIO_ImageSpec_attribute_int OpenImageIO_v2_3_6__ImageSpec_attribute_int


/** Add a `float` attribute to `extra_attribs`. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_attribute_float(
    OIIO_ImageSpec_t * this_
    , OIIO_string_view_t name
    , float value);
#define OIIO_ImageSpec_attribute_float OpenImageIO_v2_3_6__ImageSpec_attribute_float


/** Add a string attribute to `extra_attribs`. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_attribute_string(
    OIIO_ImageSpec_t * this_
    , OIIO_string_view_t name
    , OIIO_string_view_t value);
#define OIIO_ImageSpec_attribute_string OpenImageIO_v2_3_6__ImageSpec_attribute_string


/** Parse a string containing a textual representation of a value of
the given `type`, and add that as an attribute to `extra_attribs`.
Example:

    spec.attribute ("temperature", TypeString, "-273.15"); */
unsigned int OpenImageIO_v2_3_6__ImageSpec_attribute_from_string(
    OIIO_ImageSpec_t * this_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , OIIO_string_view_t value);
#define OIIO_ImageSpec_attribute_from_string OpenImageIO_v2_3_6__ImageSpec_attribute_from_string


/** Searches `extra_attribs` for any attributes matching `name` (as a
regular expression), removing them entirely from `extra_attribs`. If
`searchtype` is anything other than `TypeDesc::UNKNOWN`, matches
will be restricted only to attributes with the given type. The name
comparison will be case-sensitive if `casesensitive` is true,
otherwise in a case-insensitive manner. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_erase_attribute(
    OIIO_ImageSpec_t * this_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t searchtype
    , _Bool casesensitive);
#define OIIO_ImageSpec_erase_attribute OpenImageIO_v2_3_6__ImageSpec_erase_attribute


/** Searches `extra_attribs` for an attribute matching `name`, returning
a pointer to the attribute record, or NULL if there was no match.
If `searchtype` is anything other than `TypeDesc::UNKNOWN`, matches
will be restricted only to attributes with the given type. The name
comparison will be exact if `casesensitive` is true, otherwise in a
case-insensitive manner if `caseinsensitive` is false. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_find_attribute(
    OIIO_ImageSpec_t * this_
    , OIIO_ParamValue_t * * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t searchtype
    , _Bool casesensitive);
#define OIIO_ImageSpec_find_attribute OpenImageIO_v2_3_6__ImageSpec_find_attribute


unsigned int OpenImageIO_v2_3_6__ImageSpec_find_attribute_const(
    OIIO_ImageSpec_t const * this_
    , OIIO_ParamValue_t const * * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t searchtype
    , _Bool casesensitive);
#define OIIO_ImageSpec_find_attribute_const OpenImageIO_v2_3_6__ImageSpec_find_attribute_const


/** Search for the named attribute and return the pointer to its
`ParamValue` record, or NULL if not found.  This variety of
`find_attribute(}` can retrieve items such as "width", which are
data members of the `ImageSpec`, but not in `extra_attribs`. The
`tmpparam` is a storage area owned by the caller, which is used as
temporary buffer in cases where the information does not correspond
to an actual `extra_attribs` (in this case, the return value will be
`&tmpparam`). The extra names it understands are:

- `"x"` `"y"` `"z"` `"width"` `"height"` `"depth"`
  `"full_x"` `"full_y"` `"full_z"` `"full_width"` `"full_height"` `"full_depth"`

  Returns the `ImageSpec` fields of those names (despite the
  fact that they are technically not arbitrary named attributes
  in `extra_attribs`). All are of type `int`.

- `"datawindow"`

  Without a type, or if requested explicitly as an `int[4]`,
  returns the OpenEXR-like pixel data min and max coordinates,
  as a 4-element integer array: `{ x, y, x+width-1, y+height-1
  }`. If instead you specifically request as an `int[6]`, it
  will return the volumetric data window, `{ x, y, z, x+width-1,
  y+height-1, z+depth-1 }`.

- `"displaywindow"`

  Without a type, or if requested explicitly as an `int[4]`,
  returns the OpenEXR-like pixel display min and max
  coordinates, as a 4-element integer array: `{ full_x, full_y,
  full_x+full_width-1, full_y+full_height-1 }`. If instead you
  specifically request as an `int[6]`, it will return the
  volumetric display window, `{ full_x, full_y, full_z,
  full_x+full_width-1, full_y+full_height-1, full_z+full_depth-1 }`.

EXAMPLES

    ImageSpec spec;           // has the info
    Imath::Box2i dw;          // we want the displaywindow here
    ParamValue tmp;           // so we can retrieve pseudo-values
    TypeDesc int4("int[4]");  // Equivalent: TypeDesc int4(TypeDesc::INT,4);
    const ParamValue* p = spec.find_attribute ("displaywindow", int4);
    if (p)
        dw = Imath::Box2i(p->get<int>(0), p->get<int>(1),
                          p->get<int>(2), p->get<int>(3));

    p = spec.find_attribute("temperature", TypeFloat);
    if (p)
        float temperature = p->get<float>(); */
unsigned int OpenImageIO_v2_3_6__ImageSpec_find_attribute_builtin(
    OIIO_ImageSpec_t const * this_
    , OIIO_ParamValue_t const * * return_
    , OIIO_string_view_t name
    , OIIO_ParamValue_t * tmpparam
    , OIIO_TypeDesc_t searchtype
    , _Bool casesensitive);
#define OIIO_ImageSpec_find_attribute_builtin OpenImageIO_v2_3_6__ImageSpec_find_attribute_builtin


/** If the named attribute can be found in the `ImageSpec`, return its
data type. If no such attribute exists, return `TypeUnknown`.

This was added in version 2.1. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_getattributetype(
    OIIO_ImageSpec_t const * this_
    , OIIO_TypeDesc_t * return_
    , OIIO_string_view_t name
    , _Bool casesensitive);
#define OIIO_ImageSpec_getattributetype OpenImageIO_v2_3_6__ImageSpec_getattributetype


/** If the `ImageSpec` contains the named attribute and its type matches
`type`, copy the attribute value into the memory pointed to by `val`
(it is up to the caller to ensure there is enough space) and return
`true`. If no such attribute is found, or if it doesn't match the
type, return `false` and do not modify `val`.

EXAMPLES:

    ImageSpec spec;
    ...
    // Retrieving an integer attribute:
    int orientation = 0;
    spec.getattribute ("orientation", TypeInt, &orientation);

    // Retrieving a string attribute with a char*:
    const char* compression = nullptr;
    spec.getattribute ("compression", TypeString, &compression);

    // Alternately, retrieving a string with a ustring:
    ustring compression;
    spec.getattribute ("compression", TypeString, &compression);

Note that when passing a string, you need to pass a pointer to the
`char*`, not a pointer to the first character.  Also, the `char*`
will end up pointing to characters owned by the `ImageSpec`; the
caller does not need to ever free the memory that contains the
characters.

This was added in version 2.1. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_getattribute(
    OIIO_ImageSpec_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void * value
    , _Bool casesensitive);
#define OIIO_ImageSpec_getattribute OpenImageIO_v2_3_6__ImageSpec_getattribute


/** Retrieve the named metadata attribute and return its value as an
`int`. Any integer type will convert to `int` by truncation or
expansion, string data will parsed into an `int` if its contents
consist of of the text representation of one integer. Floating point
data will not succeed in converting to an `int`. If no such metadata
exists, or are of a type that cannot be converted, the `defaultval`
will be returned. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_get_int_attribute(
    OIIO_ImageSpec_t const * this_
    , int * return_
    , OIIO_string_view_t name
    , int defaultval);
#define OIIO_ImageSpec_get_int_attribute OpenImageIO_v2_3_6__ImageSpec_get_int_attribute


/** Retrieve the named metadata attribute and return its value as a
`float`. Any integer or floating point type will convert to `float`
in the obvious way (like a C cast), and so will string metadata if
its contents consist of of the text representation of one floating
point value. If no such metadata exists, or are of a type that cannot
be converted, the `defaultval` will be returned. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_get_float_attribute(
    OIIO_ImageSpec_t const * this_
    , float * return_
    , OIIO_string_view_t name
    , float defaultval);
#define OIIO_ImageSpec_get_float_attribute OpenImageIO_v2_3_6__ImageSpec_get_float_attribute


/** Retrieve any metadata attribute, converted to a string.
If no such metadata exists, the `defaultval` will be returned. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_get_string_attribute(
    OIIO_ImageSpec_t const * this_
    , OIIO_string_view_t * return_
    , OIIO_string_view_t name
    , OIIO_string_view_t defaultval);
#define OIIO_ImageSpec_get_string_attribute OpenImageIO_v2_3_6__ImageSpec_get_string_attribute


/** For a given parameter `p`, format the value nicely as a string.  If
`human` is true, use especially human-readable explanations (units,
or decoding of values) for certain known metadata. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_metadata_val(
    std_string_t * * return_
    , OIIO_ParamValue_t const * p
    , _Bool human);
#define OIIO_ImageSpec_metadata_val OpenImageIO_v2_3_6__ImageSpec_metadata_val


/** Returns, as a string, a serialized version of the `ImageSpec`. The
`format` may be either `ImageSpec::SerialText` or
`ImageSpec::SerialXML`. The `verbose` argument may be one of:
`ImageSpec::SerialBrief` (just resolution and other vital
statistics, one line for `SerialText`, `ImageSpec::SerialDetailed`
(contains all metadata in original form), or
`ImageSpec::SerialDetailedHuman` (contains all metadata, in many
cases with human-readable explanation). */
unsigned int OpenImageIO_v2_3_6__ImageSpec_serialize(
    OIIO_ImageSpec_t const * this_
    , std_string_t * * return_
    , OIIO_ImageSpec_SerialFormat format
    , OIIO_ImageSpec_SerialVerbose verbose);
#define OIIO_ImageSpec_serialize OpenImageIO_v2_3_6__ImageSpec_serialize


/** Converts the contents of the `ImageSpec` as an XML string. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_to_xml(
    OIIO_ImageSpec_t const * this_
    , std_string_t * * return_);
#define OIIO_ImageSpec_to_xml OpenImageIO_v2_3_6__ImageSpec_to_xml


/** Populates the fields of the `ImageSpec` based on the XML passed in. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_from_xml(
    OIIO_ImageSpec_t * this_
    , char const * xml);
#define OIIO_ImageSpec_from_xml OpenImageIO_v2_3_6__ImageSpec_from_xml


/** Hunt for the "Compression" and "CompressionQuality" settings in the
spec and turn them into the compression name and quality. This
handles compression name/qual combos of the form "name:quality". */
unsigned int OpenImageIO_v2_3_6__ImageSpec_decode_compression_metadata(
    OIIO_ImageSpec_t const * this_
    , std_pair_string_int_t * * return_
    , OIIO_string_view_t defaultcomp
    , int defaultqual);
#define OIIO_ImageSpec_decode_compression_metadata OpenImageIO_v2_3_6__ImageSpec_decode_compression_metadata


/** Helper function to verify that the given pixel range exactly covers
a set of tiles.  Also returns false if the spec indicates that the
image isn't tiled at all. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_valid_tile_range(
    OIIO_ImageSpec_t * this_
    , _Bool * return_
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend);
#define OIIO_ImageSpec_valid_tile_range OpenImageIO_v2_3_6__ImageSpec_valid_tile_range


/** Return the channelformat of the given channel. This is safe even
if channelformats is not filled out. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_channelformat(
    OIIO_ImageSpec_t const * this_
    , OIIO_TypeDesc_t * return_
    , int chan);
#define OIIO_ImageSpec_channelformat OpenImageIO_v2_3_6__ImageSpec_channelformat


/** Return the channel name of the given channel. This is safe even if
channelnames is not filled out. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_channel_name(
    OIIO_ImageSpec_t const * this_
    , OIIO_string_view_t * return_
    , int chan);
#define OIIO_ImageSpec_channel_name OpenImageIO_v2_3_6__ImageSpec_channel_name


/** Fill in an array of channel formats describing all channels in
the image.  (Note that this differs slightly from the member
data channelformats, which is empty if there are not separate
per-channel formats.) */
unsigned int OpenImageIO_v2_3_6__ImageSpec_get_channelformats_into(
    OIIO_ImageSpec_t const * this_
    , std_vector_typedesc_t * formats);
#define OIIO_ImageSpec_get_channelformats_into OpenImageIO_v2_3_6__ImageSpec_get_channelformats_into


/** Return the index of the channel with the given name, or -1 if no
such channel is present in `channelnames`. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_channelindex(
    OIIO_ImageSpec_t const * this_
    , int * return_
    , OIIO_string_view_t name);
#define OIIO_ImageSpec_channelindex OpenImageIO_v2_3_6__ImageSpec_channelindex


/** Return pixel data window for this ImageSpec expressed as a ROI. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_roi(
    OIIO_ImageSpec_t const * this_
    , OIIO_ROI_t * return_);
#define OIIO_ImageSpec_roi OpenImageIO_v2_3_6__ImageSpec_roi


/** Return full/display window for this ImageSpec expressed as a ROI. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_roi_full(
    OIIO_ImageSpec_t const * this_
    , OIIO_ROI_t * return_);
#define OIIO_ImageSpec_roi_full OpenImageIO_v2_3_6__ImageSpec_roi_full


/** Set pixel data window parameters (x, y, z, width, height, depth)
for this ImageSpec from an ROI.
Does NOT change the channels of the spec, regardless of r. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_set_roi(
    OIIO_ImageSpec_t * this_
    , OIIO_ROI_t const * r);
#define OIIO_ImageSpec_set_roi OpenImageIO_v2_3_6__ImageSpec_set_roi


/** Set full/display window parameters (full_x, full_y, full_z,
full_width, full_height, full_depth) for this ImageSpec from an ROI.
Does NOT change the channels of the spec, regardless of r. */
unsigned int OpenImageIO_v2_3_6__ImageSpec_set_roi_full(
    OIIO_ImageSpec_t * this_
    , OIIO_ROI_t const * r);
#define OIIO_ImageSpec_set_roi_full OpenImageIO_v2_3_6__ImageSpec_set_roi_full


/** Copy from `other` the image dimensions (x, y, z, width, height,
depth, full*, nchannels, format) and data types. It does *not* copy
arbitrary named metadata or channel names (thus, for an `ImageSpec`
with lots of metadata, it is much less expensive than copying the
whole thing with `operator=()`). */
unsigned int OpenImageIO_v2_3_6__ImageSpec_copy_dimensions(
    OIIO_ImageSpec_t * this_
    , OIIO_ImageSpec_t const * other);
#define OIIO_ImageSpec_copy_dimensions OpenImageIO_v2_3_6__ImageSpec_copy_dimensions


/** Returns `true` for a newly initialized (undefined) `ImageSpec`.
(Designated by no channels and undefined data type -- true of the
uninitialized state of an ImageSpec, and presumably not for any
ImageSpec that is useful or purposefully made.) */
unsigned int OpenImageIO_v2_3_6__ImageSpec_undefined(
    OIIO_ImageSpec_t const * this_
    , _Bool * return_);
#define OIIO_ImageSpec_undefined OpenImageIO_v2_3_6__ImageSpec_undefined


unsigned int OpenImageIO_v2_3_6__ImageSpec_copy(
    OIIO_ImageSpec_t * * this_
    , OIIO_ImageSpec_t const * rhs);
#define OIIO_ImageSpec_copy OpenImageIO_v2_3_6__ImageSpec_copy


unsigned int OpenImageIO_v2_3_6__ImageSpec__assign(
    OIIO_ImageSpec_t * this_
    , OIIO_ImageSpec_t * * return_
    , OIIO_ImageSpec_t const * rhs);
#define OIIO_ImageSpec__assign OpenImageIO_v2_3_6__ImageSpec__assign


unsigned int OpenImageIO_v2_3_6__ImageSpec_dtor(
    OIIO_ImageSpec_t * this_);
#define OIIO_ImageSpec_dtor OpenImageIO_v2_3_6__ImageSpec_dtor


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_x(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_x OpenImageIO_v2_3_6__ImageSpec_get_x


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_x(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_x OpenImageIO_v2_3_6__ImageSpec_set_x


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_y(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_y OpenImageIO_v2_3_6__ImageSpec_get_y


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_y(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_y OpenImageIO_v2_3_6__ImageSpec_set_y


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_z(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_z OpenImageIO_v2_3_6__ImageSpec_get_z


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_z(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_z OpenImageIO_v2_3_6__ImageSpec_set_z


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_width(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_width OpenImageIO_v2_3_6__ImageSpec_get_width


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_width(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_width OpenImageIO_v2_3_6__ImageSpec_set_width


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_height(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_height OpenImageIO_v2_3_6__ImageSpec_get_height


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_height(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_height OpenImageIO_v2_3_6__ImageSpec_set_height


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_depth(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_depth OpenImageIO_v2_3_6__ImageSpec_get_depth


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_depth(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_depth OpenImageIO_v2_3_6__ImageSpec_set_depth


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_full_x(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_full_x OpenImageIO_v2_3_6__ImageSpec_get_full_x


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_full_x(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_full_x OpenImageIO_v2_3_6__ImageSpec_set_full_x


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_full_y(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_full_y OpenImageIO_v2_3_6__ImageSpec_get_full_y


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_full_y(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_full_y OpenImageIO_v2_3_6__ImageSpec_set_full_y


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_full_z(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_full_z OpenImageIO_v2_3_6__ImageSpec_get_full_z


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_full_z(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_full_z OpenImageIO_v2_3_6__ImageSpec_set_full_z


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_full_width(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_full_width OpenImageIO_v2_3_6__ImageSpec_get_full_width


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_full_width(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_full_width OpenImageIO_v2_3_6__ImageSpec_set_full_width


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_full_height(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_full_height OpenImageIO_v2_3_6__ImageSpec_get_full_height


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_full_height(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_full_height OpenImageIO_v2_3_6__ImageSpec_set_full_height


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_full_depth(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_full_depth OpenImageIO_v2_3_6__ImageSpec_get_full_depth


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_full_depth(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_full_depth OpenImageIO_v2_3_6__ImageSpec_set_full_depth


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_tile_width(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_tile_width OpenImageIO_v2_3_6__ImageSpec_get_tile_width


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_tile_width(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_tile_width OpenImageIO_v2_3_6__ImageSpec_set_tile_width


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_tile_height(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_tile_height OpenImageIO_v2_3_6__ImageSpec_get_tile_height


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_tile_height(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_tile_height OpenImageIO_v2_3_6__ImageSpec_set_tile_height


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_tile_depth(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_tile_depth OpenImageIO_v2_3_6__ImageSpec_get_tile_depth


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_tile_depth(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_tile_depth OpenImageIO_v2_3_6__ImageSpec_set_tile_depth


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_nchannels(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_nchannels OpenImageIO_v2_3_6__ImageSpec_get_nchannels


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_nchannels(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_nchannels OpenImageIO_v2_3_6__ImageSpec_set_nchannels


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_format(
    OIIO_ImageSpec_t const * this_
    , OIIO_TypeDesc_t const * * return_);
#define OIIO_ImageSpec_get_format OpenImageIO_v2_3_6__ImageSpec_get_format


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_format(
    OIIO_ImageSpec_t * this_
    , OIIO_TypeDesc_t const * value);
#define OIIO_ImageSpec_set_format OpenImageIO_v2_3_6__ImageSpec_set_format


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_channelformats(
    OIIO_ImageSpec_t const * this_
    , std_vector_typedesc_t const * * return_);
#define OIIO_ImageSpec_get_channelformats OpenImageIO_v2_3_6__ImageSpec_get_channelformats


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_channelformats(
    OIIO_ImageSpec_t * this_
    , std_vector_typedesc_t const * value);
#define OIIO_ImageSpec_set_channelformats OpenImageIO_v2_3_6__ImageSpec_set_channelformats


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_channelnames(
    OIIO_ImageSpec_t const * this_
    , std_vector_string_t const * * return_);
#define OIIO_ImageSpec_get_channelnames OpenImageIO_v2_3_6__ImageSpec_get_channelnames


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_channelnames(
    OIIO_ImageSpec_t * this_
    , std_vector_string_t const * value);
#define OIIO_ImageSpec_set_channelnames OpenImageIO_v2_3_6__ImageSpec_set_channelnames


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_alpha_channel(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_alpha_channel OpenImageIO_v2_3_6__ImageSpec_get_alpha_channel


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_alpha_channel(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_alpha_channel OpenImageIO_v2_3_6__ImageSpec_set_alpha_channel


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_z_channel(
    OIIO_ImageSpec_t const * this_
    , int const * * return_);
#define OIIO_ImageSpec_get_z_channel OpenImageIO_v2_3_6__ImageSpec_get_z_channel


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_z_channel(
    OIIO_ImageSpec_t * this_
    , int const * value);
#define OIIO_ImageSpec_set_z_channel OpenImageIO_v2_3_6__ImageSpec_set_z_channel


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_deep(
    OIIO_ImageSpec_t const * this_
    , _Bool const * * return_);
#define OIIO_ImageSpec_get_deep OpenImageIO_v2_3_6__ImageSpec_get_deep


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_deep(
    OIIO_ImageSpec_t * this_
    , _Bool const * value);
#define OIIO_ImageSpec_set_deep OpenImageIO_v2_3_6__ImageSpec_set_deep


unsigned int OpenImageIO_v2_3_6__ImageSpec_get_extra_attribs(
    OIIO_ImageSpec_t const * this_
    , OIIO_ParamValueList_t const * * return_);
#define OIIO_ImageSpec_get_extra_attribs OpenImageIO_v2_3_6__ImageSpec_get_extra_attribs


unsigned int OpenImageIO_v2_3_6__ImageSpec_set_extra_attribs(
    OIIO_ImageSpec_t * this_
    , OIIO_ParamValueList_t const * value);
#define OIIO_ImageSpec_set_extra_attribs OpenImageIO_v2_3_6__ImageSpec_set_extra_attribs


/** Create an ImageInput subclass instance that is able to read the
given file and open it, returning a `unique_ptr` to the ImageInput
if successful.  The `unique_ptr` is set up with an appropriate
deleter so the ImageInput will be properly closed and deleted when
the `unique_ptr` goes out of scope or is reset. If the open fails,
return an empty `unique_ptr` and set an error that can be retrieved
by `OIIO::geterror()`.

The `config`, if not nullptr, points to an ImageSpec giving hints,
requests, or special instructions.  ImageInput implementations are
free to not respond to any such requests, so the default
implementation is just to ignore `config`.

`open()` will first try to make an ImageInput corresponding to
the format implied by the file extension (for example, `"foo.tif"`
will try the TIFF plugin), but if one is not found or if the
inferred one does not open the file, every known ImageInput type
will be tried until one is found that will open the file.

@param filename
        The name of the file to open.

@param config
        Optional pointer to an ImageSpec whose metadata contains
        "configuration hints."

@param ioproxy
        Optional pointer to an IOProxy to use (not supported by all
        formats, see `supports("ioproxy")`). The caller retains
        ownership of the proxy.

@returns
        A `unique_ptr` that will close and free the ImageInput when
        it exits scope or is reset. The pointer will be empty if the
        required writer was not able to be created. */
unsigned int OpenImageIO_v2_3_6__ImageInput_open(
    std_ImageInputPtr_t * return_
    , std_string_t const * filename
    , OIIO_ImageSpec_t const * config
    , OIIO_Filesystem_IOProxy_t * ioproxy);
#define OIIO_ImageInput_open OpenImageIO_v2_3_6__ImageInput_open


unsigned int OpenImageIO_v2_3_6__ImageInput_dtor(
    OIIO_ImageInput_t * this_);
#define OIIO_ImageInput_dtor OpenImageIO_v2_3_6__ImageInput_dtor


/** Return the name of the format implemented by this class. */
unsigned int OpenImageIO_v2_3_6__ImageInput_format_name(
    OIIO_ImageInput_t const * this_
    , char const * * return_);
#define OIIO_ImageInput_format_name OpenImageIO_v2_3_6__ImageInput_format_name


/** Given the name of a "feature", return whether this ImageInput
supports output of images with the given properties. Most queries
will simply return 0 for "doesn't support" and 1 for "supports it,"
but it is acceptable to have queries return other nonzero integers
to indicate varying degrees of support or limits (but should be
clearly documented as such).

Feature names that ImageInput implementations are expected to
recognize include:

- `"arbitrary_metadata"` : Does this format allow metadata with
      arbitrary names and types?

- `"exif"` :
      Can this format store Exif camera data?

- `"iptc"` :
      Can this format store IPTC data?

- `"procedural"` :
      Can this format create images without reading from a disk
      file?

- `"ioproxy"` :
      Does this format reader support reading from an `IOProxy`?

This list of queries may be extended in future releases. Since this
can be done simply by recognizing new query strings, and does not
require any new API entry points, addition of support for new
queries does not break ``link compatibility'' with
previously-compiled plugins. */
unsigned int OpenImageIO_v2_3_6__ImageInput_supports(
    OIIO_ImageInput_t const * this_
    , int * return_
    , OIIO_string_view_t feature);
#define OIIO_ImageInput_supports OpenImageIO_v2_3_6__ImageInput_supports


/** Return true if the `filename` names a file of the type for this
ImageInput.  The implementation will try to determine this as
efficiently as possible, in most cases much less expensively than
doing a full `open()`.  Note that there can be false positives: a
file can appear to be of the right type (i.e., `valid_file()`
returning `true`) but still fail a subsequent call to `open()`, such
as if the contents of the file are truncated, nonsensical, or
otherwise corrupted.

@returns
        `true` upon success, or `false` upon failure. */
unsigned int OpenImageIO_v2_3_6__ImageInput_valid_file(
    OIIO_ImageInput_t const * this_
    , _Bool * return_
    , std_string_t const * filename);
#define OIIO_ImageInput_valid_file OpenImageIO_v2_3_6__ImageInput_valid_file


/** Opens the file with given name and seek to the first subimage in the
file.  Various file attributes are put in `newspec` and a copy
is also saved internally to the `ImageInput` (retrievable via
`spec()`.  From examining `newspec` or `spec()`, you can
discern the resolution, if it's tiled, number of channels, native
data format, and other metadata about the image.

@param name
        Filename to open.

@param newspec
        Reference to an ImageSpec in which to deposit a full
        description of the contents of the first subimage of the
        file.

@returns
        `true` if the file was found and opened successfully. */
unsigned int OpenImageIO_v2_3_6__ImageInput_open_in(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , std_string_t const * name
    , OIIO_ImageSpec_t * newspec);
#define OIIO_ImageInput_open_in OpenImageIO_v2_3_6__ImageInput_open_in


/** Open file with given name, similar to `open(name,newspec)`. The
`config` is an ImageSpec giving requests or special instructions.
ImageInput implementations are free to not respond to any such
requests, so the default implementation is just to ignore config and
call regular `open(name,newspec)`.

@param name
        Filename to open.

@param newspec
        Reference to an ImageSpec in which to deposit a full
        description of the contents of the first subimage of the
        file.

@param config
        An ImageSpec whose metadata contains "configuration hints"
        for the ImageInput implementation.

@returns
        `true` if the file was found and opened successfully. */
unsigned int OpenImageIO_v2_3_6__ImageInput_open_in_with_config(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , std_string_t const * name
    , OIIO_ImageSpec_t * newspec
    , OIIO_ImageSpec_t const * config);
#define OIIO_ImageInput_open_in_with_config OpenImageIO_v2_3_6__ImageInput_open_in_with_config


/** Return a reference to the image specification of the current
subimage/MIPlevel.  Note that the contents of the spec are invalid
before `open()` or after `close()`, and may change with a call to
`seek_subimage()`. It is thus not thread-safe, since the spec may
change if another thread calls `seek_subimage`, or any of the
`read_*()` functions that take explicit subimage/miplevel. */
unsigned int OpenImageIO_v2_3_6__ImageInput_spec(
    OIIO_ImageInput_t const * this_
    , OIIO_ImageSpec_t const * * return_);
#define OIIO_ImageInput_spec OpenImageIO_v2_3_6__ImageInput_spec


/** Return a full copy of the ImageSpec of the designated subimage and
MIPlevel. This method is thread-safe, but it is potentially
expensive, due to the work that needs to be done to fully copy an
ImageSpec if there is lots of named metadata to allocate and copy.
See also the less expensive `spec_dimensions()`. Errors (such as
having requested a nonexistent subimage) are indicated by returning
an ImageSpec with `format==TypeUnknown`. */
unsigned int OpenImageIO_v2_3_6__ImageInput_spec_for_subimage(
    OIIO_ImageInput_t * this_
    , OIIO_ImageSpec_t * * return_
    , int subimage
    , int miplevel);
#define OIIO_ImageInput_spec_for_subimage OpenImageIO_v2_3_6__ImageInput_spec_for_subimage


/** Return a copy of the ImageSpec of the designated subimage and
miplevel, but only the dimension and type fields. Just as with a
call to `ImageSpec::copy_dimensions()`, neither the channel names
nor any of the arbitrary named metadata will be copied, thus this is
a relatively inexpensive operation if you don't need that
information. It is guaranteed to be thread-safe. Errors (such as
having requested a nonexistent subimage) are indicated by returning
an ImageSpec with `format==TypeUnknown`. */
unsigned int OpenImageIO_v2_3_6__ImageInput_spec_dimensions(
    OIIO_ImageInput_t * this_
    , OIIO_ImageSpec_t * * return_
    , int subimage
    , int miplevel);
#define OIIO_ImageInput_spec_dimensions OpenImageIO_v2_3_6__ImageInput_spec_dimensions


/** Close an open ImageInput. The call to close() is not strictly
necessary if the ImageInput is destroyed immediately afterwards,
since it is required for the destructor to close if the file is
still open.

@returns
        `true` upon success, or `false` upon failure. */
unsigned int OpenImageIO_v2_3_6__ImageInput_close(
    OIIO_ImageInput_t * this_
    , _Bool * return_);
#define OIIO_ImageInput_close OpenImageIO_v2_3_6__ImageInput_close


/** Returns the index of the subimage that is currently being read.
The first subimage (or the only subimage, if there is just one)
is number 0. */
unsigned int OpenImageIO_v2_3_6__ImageInput_current_subimage(
    OIIO_ImageInput_t const * this_
    , int * return_);
#define OIIO_ImageInput_current_subimage OpenImageIO_v2_3_6__ImageInput_current_subimage


/** Returns the index of the MIPmap image that is currently being read.
The highest-res MIP level (or the only level, if there is just
one) is number 0. */
unsigned int OpenImageIO_v2_3_6__ImageInput_current_miplevel(
    OIIO_ImageInput_t const * this_
    , int * return_);
#define OIIO_ImageInput_current_miplevel OpenImageIO_v2_3_6__ImageInput_current_miplevel


/** Seek to the given subimage and MIP-map level within the open image
file.  The first subimage of the file has index 0, the highest-
resolution MIP level has index 0.  The new subimage's vital
statistics=may be retrieved by `this->spec()`.  The reader is
expected to give the appearance of random access to subimages and
MIP levels -- in other words, if it can't randomly seek to the given
subimage/level, it should transparently close, reopen, and
sequentially read through prior subimages and levels.

@returns
        `true` upon success, or `false` upon failure. A failure may
        indicate that no such subimage or MIP level exists in the
        file. */
unsigned int OpenImageIO_v2_3_6__ImageInput_seek_subimage(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel);
#define OIIO_ImageInput_seek_subimage OpenImageIO_v2_3_6__ImageInput_seek_subimage


/** Read the scanline that includes pixels (*,y,z) from the "current"
subimage and MIP level.  The `xstride` value gives the distance
between successive pixels (in bytes).  Strides set to `AutoStride`
imply "contiguous" data.

@note This variety of `read_scanline` is not re-entrant nor
thread-safe. If you require concurrent reads to the same open
ImageInput, you should use `read_scanlines` that has the `subimage`
and `miplevel` passed explicitly.

@param  y/z         The y & z coordinates of the scanline. For 2D
                    images, z should be 0.
@param  format      A TypeDesc describing the type of `data`.
@param  data        Pointer to the pixel data buffer.
@param  xstride     The distance in bytes between successive
                    pixels in `data` (or `AutoStride`).
@returns            `true` upon success, or `false` upon failure. */
unsigned int OpenImageIO_v2_3_6__ImageInput_read_scanline(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int y
    , int z
    , OIIO_TypeDesc_t format
    , void * data
    , long xstride);
#define OIIO_ImageInput_read_scanline OpenImageIO_v2_3_6__ImageInput_read_scanline


/** Simple read_scanline reads into contiguous float pixels. */
unsigned int OpenImageIO_v2_3_6__ImageInput_read_scanline_contiguous(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int y
    , int z
    , float * data);
#define OIIO_ImageInput_read_scanline_contiguous OpenImageIO_v2_3_6__ImageInput_read_scanline_contiguous


/** Read multiple scanlines that include pixels (*,y,z) for all ybegin
<= y < yend in the specified subimage and mip level, into `data`,
using the strides given and converting to the requested data
`format` (TypeUnknown indicates no conversion, just copy native data
types). Only channels [chbegin,chend) will be read/copied
(chbegin=0, chend=spec.nchannels reads all channels, yielding
equivalent behavior to the simpler variant of `read_scanlines`).

This version of read_scanlines, because it passes explicit
subimage/miplevel, does not require a separate call to
seek_subimage, and is guaranteed to be thread-safe against other
concurrent calls to any of the read_* methods that take an explicit
subimage/miplevel (but not against any other ImageInput methods).

@param  subimage    The subimage to read from (starting with 0).
@param  miplevel    The MIP level to read (0 is the highest
                    resolution level).
@param  ybegin/yend The y range of the scanlines being passed.
@param  z           The z coordinate of the scanline.
@param  chbegin/chend
                    The channel range to read.
@param  format      A TypeDesc describing the type of `data`.
@param  data        Pointer to the pixel data.
@param  xstride/ystride
                    The distance in bytes between successive pixels
                    and scanlines (or `AutoStride`).
@returns            `true` upon success, or `false` upon failure.

@note This call was changed for OpenImageIO 2.0 to include the
    explicit subimage and miplevel parameters. The previous
    versions, which lacked subimage and miplevel parameters (thus
    were dependent on a prior call to `seek_subimage`) are
    considered deprecated. */
unsigned int OpenImageIO_v2_3_6__ImageInput_read_scanlines(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , int ybegin
    , int yend
    , int z
    , int chbegin
    , int chend
    , OIIO_TypeDesc_t format
    , void * data
    , long xstride
    , long ystride);
#define OIIO_ImageInput_read_scanlines OpenImageIO_v2_3_6__ImageInput_read_scanlines


/** Read the tile whose upper-left origin is (x,y,z) into `data[]`,
converting if necessary from the native data format of the file into
the `format` specified. The stride values give the data spacing of
adjacent pixels, scanlines, and volumetric slices (measured in
bytes). Strides set to AutoStride imply 'contiguous' data in the
shape of a full tile, i.e.,

    xstride = format.size() * spec.nchannels
    ystride = xstride * spec.tile_width
    zstride = ystride * spec.tile_height

@note This variety of `read_tile` is not re-entrant nor thread-safe.
If you require concurrent reads to the same open ImageInput, you
should use `read_tiles()` that has the `subimage` and `miplevel`
passed explicitly.

@param  x/y/z       The upper left coordinate of the tile being passed.
@param  format      A TypeDesc describing the type of `data`.
@param  data        Pointer to the pixel data.
@param  xstride/ystride/zstride
                    The distance in bytes between successive pixels,
                    scanlines, and image planes (or `AutoStride` to
                    indicate a "contiguous" single tile).
@returns            `true` upon success, or `false` upon failure.

@note This call will fail if the image is not tiled, or if (x,y,z)
is not the upper left corner coordinates of a tile. */
unsigned int OpenImageIO_v2_3_6__ImageInput_read_tile(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int x
    , int y
    , int z
    , OIIO_TypeDesc_t format
    , void * data
    , long xstride
    , long ystride
    , long zstride);
#define OIIO_ImageInput_read_tile OpenImageIO_v2_3_6__ImageInput_read_tile


/** Simple read_tile reads into contiguous float pixels. */
unsigned int OpenImageIO_v2_3_6__ImageInput_read_tile_contiguous(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int x
    , int y
    , int z
    , float * data);
#define OIIO_ImageInput_read_tile_contiguous OpenImageIO_v2_3_6__ImageInput_read_tile_contiguous


/** Read the block of multiple tiles that include all pixels in

    [xbegin,xend) X [ybegin,yend) X [zbegin,zend)

This is analogous to calling `read_tile(x,y,z,...)` for each tile
in turn (but for some file formats, reading multiple tiles may allow
it to read more efficiently or in parallel).

The begin/end pairs must correctly delineate tile boundaries, with
the exception that it may also be the end of the image data if the
image resolution is not a whole multiple of the tile size. The
stride values give the data spacing of adjacent pixels, scanlines,
and volumetric slices (measured in bytes). Strides set to AutoStride
imply contiguous data in the shape of the [begin,end) region, i.e.,

    xstride = format.size() * spec.nchannels
    ystride = xstride * (xend-xbegin)
    zstride = ystride * (yend-ybegin)

This version of read_tiles, because it passes explicit subimage and
miplevel, does not require a separate call to seek_subimage, and is
guaranteed to be thread-safe against other concurrent calls to any
of the read_* methods that take an explicit subimage/miplevel (but
not against any other ImageInput methods).

@param  subimage    The subimage to read from (starting with 0).
@param  miplevel    The MIP level to read (0 is the highest
                    resolution level).
@param  xbegin/xend The x range of the pixels covered by the group
                    of tiles being read.
@param  ybegin/yend The y range of the pixels covered by the tiles.
@param  zbegin/zend The z range of the pixels covered by the tiles
                    (for a 2D image, zbegin=0 and zend=1).
@param  chbegin/chend
                    The channel range to read.
@param  format      A TypeDesc describing the type of `data`.
@param  data        Pointer to the pixel data.
@param  xstride/ystride/zstride
                    The distance in bytes between successive pixels,
                    scanlines, and image planes (or `AutoStride`).
@returns            `true` upon success, or `false` upon failure.

@note The call will fail if the image is not tiled, or if the pixel
ranges do not fall along tile (or image) boundaries, or if it is not
a valid tile range. */
unsigned int OpenImageIO_v2_3_6__ImageInput_read_tiles(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend
    , int chbegin
    , int chend
    , OIIO_TypeDesc_t format
    , void * data
    , long xstride
    , long ystride
    , long zstride);
#define OIIO_ImageInput_read_tiles OpenImageIO_v2_3_6__ImageInput_read_tiles


/** Read the entire image of `spec.width x spec.height x spec.depth`
pixels into a buffer with the given strides and in the desired
data format.

Depending on the spec, this will read either all tiles or all
scanlines. Assume that data points to a layout in row-major order.

This version of read_image, because it passes explicit subimage and
miplevel, does not require a separate call to seek_subimage, and is
guaranteed to be thread-safe against other concurrent calls to any
of the read_* methods that take an explicit subimage/miplevel (but
not against any other ImageInput methods).

Because this may be an expensive operation, a progress callback
may be passed.  Periodically, it will be called as follows:

    progress_callback (progress_callback_data, float done);

where `done` gives the portion of the image (between 0.0 and 1.0)
that has been written thus far.

@param  subimage    The subimage to read from (starting with 0).
@param  miplevel    The MIP level to read (0 is the highest
                    resolution level).
@param  chbegin/chend
                    The channel range to read.
@param  format      A TypeDesc describing the type of `data`.
@param  data        Pointer to the pixel data.
@param  xstride/ystride/zstride
                    The distance in bytes between successive pixels,
                    scanlines, and image planes (or `AutoStride`).
@param  progress_callback/progress_callback_data
                    Optional progress callback.
@returns            `true` upon success, or `false` upon failure. */
unsigned int OpenImageIO_v2_3_6__ImageInput_read_image(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , int chbegin
    , int chend
    , OIIO_TypeDesc_t format
    , void * data
    , long xstride
    , long ystride
    , long zstride
    , OIIO_ProgressCallback_t progress_callback
    , void * progress_callback_data);
#define OIIO_ImageInput_read_image OpenImageIO_v2_3_6__ImageInput_read_image


/** Read deep scanlines containing pixels (*,y,z), for all y in the
range [ybegin,yend) into `deepdata`. This will fail if it is not a
deep file.

@param  subimage    The subimage to read from (starting with 0).
@param  miplevel    The MIP level to read (0 is the highest
                    resolution level).
@param  chbegin/chend
                    The channel range to read.
@param  ybegin/yend The y range of the scanlines being passed.
@param  z           The z coordinate of the scanline.
@param  deepdata    A `DeepData` object into which the data for
                    these scanlines will be placed.
@returns            `true` upon success, or `false` upon failure. */
unsigned int OpenImageIO_v2_3_6__ImageInput_read_native_deep_scanlines(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , int ybegin
    , int yend
    , int z
    , int chbegin
    , int chend
    , OIIO_DeepData_t * deepdata);
#define OIIO_ImageInput_read_native_deep_scanlines OpenImageIO_v2_3_6__ImageInput_read_native_deep_scanlines


/** Read into `deepdata` the block of native deep data tiles that
include all pixels and channels specified by pixel range.

@param  subimage    The subimage to read from (starting with 0).
@param  miplevel    The MIP level to read (0 is the highest
                    resolution level).
@param  xbegin/xend The x range of the pixels covered by the group
                    of tiles being read.
@param  ybegin/yend The y range of the pixels covered by the tiles.
@param  zbegin/zend The z range of the pixels covered by the tiles
                    (for a 2D image, zbegin=0 and zend=1).
@param  chbegin/chend
                    The channel range to read.
@param  deepdata    A `DeepData` object into which the data for
                    these tiles will be placed.
@returns            `true` upon success, or `false` upon failure.

@note The call will fail if the image is not tiled, or if the pixel
ranges do not fall along tile (or image) boundaries, or if it is not
a valid tile range. */
unsigned int OpenImageIO_v2_3_6__ImageInput_read_native_deep_tiles(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend
    , int chbegin
    , int chend
    , OIIO_DeepData_t * deepdata);
#define OIIO_ImageInput_read_native_deep_tiles OpenImageIO_v2_3_6__ImageInput_read_native_deep_tiles


/** Read the entire deep data image of spec.width x spec.height x
spec.depth pixels, all channels, into `deepdata`.

@param  subimage    The subimage to read from (starting with 0).
@param  miplevel    The MIP level to read (0 is the highest
                    resolution level).
@param  deepdata    A `DeepData` object into which the data for
                    the image will be placed.
@returns            `true` upon success, or `false` upon failure. */
unsigned int OpenImageIO_v2_3_6__ImageInput_read_native_deep_image(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , OIIO_DeepData_t * deepdata);
#define OIIO_ImageInput_read_native_deep_image OpenImageIO_v2_3_6__ImageInput_read_native_deep_image


/** Read a single scanline (all channels) of native data into contiguous
memory. */
unsigned int OpenImageIO_v2_3_6__ImageInput_read_native_scanline(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , int y
    , int z
    , void * data);
#define OIIO_ImageInput_read_native_scanline OpenImageIO_v2_3_6__ImageInput_read_native_scanline


/** Read a range of scanlines (all channels) of native data into
contiguous memory. */
unsigned int OpenImageIO_v2_3_6__ImageInput_read_native_scanlines(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , int ybegin
    , int yend
    , int z
    , void * data);
#define OIIO_ImageInput_read_native_scanlines OpenImageIO_v2_3_6__ImageInput_read_native_scanlines


/** Read a range of scanlines (with optionally a subset of channels) of
native data into contiguous memory. */
unsigned int OpenImageIO_v2_3_6__ImageInput_read_native_scanlines_with_channels(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , int ybegin
    , int yend
    , int z
    , int chbegin
    , int chend
    , void * data);
#define OIIO_ImageInput_read_native_scanlines_with_channels OpenImageIO_v2_3_6__ImageInput_read_native_scanlines_with_channels


/** Read a single tile (all channels) of native data into contiguous
memory. The base class read_native_tile fails. A format reader that
supports tiles MUST overload this virtual method that reads a single
tile (all channels). */
unsigned int OpenImageIO_v2_3_6__ImageInput_read_native_tile(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , int x
    , int y
    , int z
    , void * data);
#define OIIO_ImageInput_read_native_tile OpenImageIO_v2_3_6__ImageInput_read_native_tile


/** Read multiple tiles (all channels) of native data into contigious
memory. A format reader that supports reading multiple tiles at once
(in a way that's more efficient than reading the tiles one at a
time) is advised (but not required) to overload this virtual method.
If an ImageInput subclass does not overload this, the default
implementation here is simply to loop over the tiles, calling the
single-tile read_native_tile() for each one. */
unsigned int OpenImageIO_v2_3_6__ImageInput_read_native_tiles(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend
    , void * data);
#define OIIO_ImageInput_read_native_tiles OpenImageIO_v2_3_6__ImageInput_read_native_tiles


/** Read multiple tiles (potentially a subset of channels) of native
data into contigious memory. A format reader that supports reading
multiple tiles at once, and can handle a channel subset while doing
so, is advised (but not required) to overload this virtual method.
If an ImageInput subclass does not overload this, the default
implementation here is simply to loop over the tiles, calling the
single-tile read_native_tile() for each one (and copying carefully
to handle the channel subset issues). */
unsigned int OpenImageIO_v2_3_6__ImageInput_read_native_tiles_with_channels(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend
    , int chbegin
    , int chend
    , void * data);
#define OIIO_ImageInput_read_native_tiles_with_channels OpenImageIO_v2_3_6__ImageInput_read_native_tiles_with_channels


/** @} */
unsigned int OpenImageIO_v2_3_6__ImageInput_send_to_input(
    OIIO_ImageInput_t * this_
    , int * return_
    , char const * format);
#define OIIO_ImageInput_send_to_input OpenImageIO_v2_3_6__ImageInput_send_to_input


unsigned int OpenImageIO_v2_3_6__ImageInput_send_to_client(
    OIIO_ImageInput_t * this_
    , int * return_
    , char const * format);
#define OIIO_ImageInput_send_to_client OpenImageIO_v2_3_6__ImageInput_send_to_client


/** Set an IOProxy for this reader. This must be called prior to
`open()`, and only for readers that support them
(`supports("ioproxy")`). The caller retains ownership of the proxy.

@returns `true` for success, `false` for failure. */
unsigned int OpenImageIO_v2_3_6__ImageInput_set_ioproxy(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , OIIO_Filesystem_IOProxy_t * ioproxy);
#define OIIO_ImageInput_set_ioproxy OpenImageIO_v2_3_6__ImageInput_set_ioproxy


/** Is there a pending error message waiting to be retrieved, that
resulted from an ImageInput API call made by the this thread?

Note that any `error()` calls issued are thread-specific, and the
`geterror()/has_error()` are expected to be called by the same
thread that called whichever API function encountered an error. */
unsigned int OpenImageIO_v2_3_6__ImageInput_has_error(
    OIIO_ImageInput_t const * this_
    , _Bool * return_);
#define OIIO_ImageInput_has_error OpenImageIO_v2_3_6__ImageInput_has_error


/** Return the text of all pending error messages issued against this
ImageInput by the calling thread, and clear the pending error
message unless `clear` is false. If no error message is pending, it
will return an empty string.

Note that any `error()` calls issued are thread-specific, and the
`geterror()/has_error()` are expected to be called by the same
thread that called whichever API function encountered an error. */
unsigned int OpenImageIO_v2_3_6__ImageInput_geterror(
    OIIO_ImageInput_t const * this_
    , std_string_t * * return_
    , _Bool clear);
#define OIIO_ImageInput_geterror OpenImageIO_v2_3_6__ImageInput_geterror


/** Set the threading policy for this ImageInput, controlling the
maximum amount of parallelizing thread "fan-out" that might occur
during large read operations. The default of 0 means that the global
`attribute("threads")` value should be used (which itself defaults
to using as many threads as cores; see Section `Global Attributes`_).

The main reason to change this value is to set it to 1 to indicate
that the calling thread should do all the work rather than spawning
new threads. That is probably the desired behavior in situations
where the calling application has already spawned multiple worker
threads. */
unsigned int OpenImageIO_v2_3_6__ImageInput_threads(
    OIIO_ImageInput_t * this_
    , int n);
#define OIIO_ImageInput_threads OpenImageIO_v2_3_6__ImageInput_threads


/** Retrieve the current thread-spawning policy.
@see  `threads(int)` */
unsigned int OpenImageIO_v2_3_6__ImageInput_threads_const(
    OIIO_ImageInput_t const * this_
    , int * return_);
#define OIIO_ImageInput_threads_const OpenImageIO_v2_3_6__ImageInput_threads_const


/** There is a (hidden) internal recursive mutex to each ImageInput
that can be used by the II to enforce thread safety. This is exposed
via the obvious lock()/unlock()/try_lock() semantics. */
unsigned int OpenImageIO_v2_3_6__ImageInput_lock(
    OIIO_ImageInput_t const * this_);
#define OIIO_ImageInput_lock OpenImageIO_v2_3_6__ImageInput_lock


unsigned int OpenImageIO_v2_3_6__ImageInput_unlock(
    OIIO_ImageInput_t const * this_);
#define OIIO_ImageInput_unlock OpenImageIO_v2_3_6__ImageInput_unlock


unsigned int OpenImageIO_v2_3_6__ImageInput_try_lock(
    OIIO_ImageInput_t const * this_
    , _Bool * return_);
#define OIIO_ImageInput_try_lock OpenImageIO_v2_3_6__ImageInput_try_lock


/** Create an `ImageOutput` that can be used to write an image file.
The type of image file (and hence, the particular subclass of
`ImageOutput` returned, and the plugin that contains its methods) is
inferred from the name, if it appears to be a full filename, or it
may also name the format.

@param filename
        The name of the file format (e.g., "openexr"), a file
        extension (e.g., "exr"), or a filename from which the the
        file format can be inferred from its extension (e.g.,
        "hawaii.exr").

@param plugin_searchpath
        An optional colon-separated list of directories to search
        for OpenImageIO plugin DSO/DLL's.

@param ioproxy
        Optional pointer to an IOProxy to use (not supported by all
        formats, see `supports("ioproxy")`). The caller retains
        ownership of the proxy.

@returns
        A `unique_ptr` that will close and free the ImageOutput when
        it exits scope or is reset. The pointer will be empty if the
        required writer was not able to be created. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_create(
    std_ImageOutputPtr_t * return_
    , OIIO_string_view_t filename
    , OIIO_Filesystem_IOProxy_t * ioproxy
    , OIIO_string_view_t plugin_searchpath);
#define OIIO_ImageOutput_create OpenImageIO_v2_3_6__ImageOutput_create


unsigned int OpenImageIO_v2_3_6__ImageOutput_dtor(
    OIIO_ImageOutput_t * this_);
#define OIIO_ImageOutput_dtor OpenImageIO_v2_3_6__ImageOutput_dtor


/** Return the name of the format implemented by this class. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_format_name(
    OIIO_ImageOutput_t const * this_
    , char const * * return_);
#define OIIO_ImageOutput_format_name OpenImageIO_v2_3_6__ImageOutput_format_name


/** Given the name of a "feature", return whether this ImageOutput
supports output of images with the given properties. Most queries
will simply return 0 for "doesn't support" and 1 for "supports it,"
but it is acceptable to have queries return other nonzero integers
to indicate varying degrees of support or limits (but should be
clearly documented as such).

Feature names that ImageOutput implementations are expected to
recognize include:

 - `"tiles"` :
        Is this format writer able to write tiled images?

 - `"rectangles"` :
        Does this writer accept arbitrary rectangular pixel regions
        (via `write_rectangle()`)?  Returning 0 indicates that
        pixels must be transmitted via `write_scanline()` (if
        scanline-oriented) or `write_tile()` (if tile-oriented, and
        only if `supports("tiles")` returns true).

 - `"random_access"` :
        May tiles or scanlines be written in any order (0 indicates
        that they *must* be in successive order)?

 - `"multiimage"` :
        Does this format support multiple subimages within a file?

 - `"appendsubimage"` :
        Does this format support multiple subimages that can be
        successively appended at will via
        `open(name,spec,AppendSubimage)`? A value of 0 means that
        the format requires pre-declaring the number and
        specifications of the subimages when the file is first
        opened, with `open(name,subimages,specs)`.

 - `"mipmap"` :
        Does this format support multiple resolutions for an
        image/subimage?

 - `"volumes"` :
        Does this format support "3D" pixel arrays (a.k.a. volume
        images)?

 - `"alpha"` :
        Can this format support an alpha channel?

 - `"nchannels"` :
        Can this format support arbitrary number of channels (beyond RGBA)?

 - `"rewrite"` :
        May the same scanline or tile be sent more than once?
        Generally, this is true for plugins that implement
        interactive display, rather than a saved image file.

 - `"empty"` :
        Does this plugin support passing a NULL data pointer to the
        various `write` routines to indicate that the entire data
        block is composed of pixels with value zero?  Plugins that
        support this achieve a speedup when passing blank scanlines
        or tiles (since no actual data needs to be transmitted or
        converted).

 - `"channelformats"` :
        Does this format writer support per-channel data formats,
        respecting the ImageSpec's `channelformats` field? If not,
        it only accepts a single data format for all channels and
        will ignore the `channelformats` field of the spec.

 - `"displaywindow"` :
        Does the format support display ("full") windows distinct
        from the pixel data window?

 - `"origin"` :
        Does the image format support specifying a pixel window
        origin (i.e., nonzero ImageSpec `x`, `y`, `z`)?

 - `"negativeorigin"` :
        Does the image format allow data and display window origins
        (i.e., ImageSpec `x`, `y`, `z`, `full_x`, `full_y`, `full_z`)
        to have negative values?

 - `"deepdata"` :
       Does the image format allow "deep" data consisting of
       multiple values per pixel (and potentially a differing number
       of values from pixel to pixel)?

 - `"arbitrary_metadata"` :
        Does the image file format allow metadata with arbitrary
        names (and either arbitrary, or a reasonable set of, data
        types)? (Versus the file format supporting only a fixed list
        of specific metadata names/values.)

 - `"exif"`
        Does the image file format support Exif camera data (either
        specifically, or via arbitrary named metadata)?

 - `"iptc"`
        Does the image file format support IPTC data (either
        specifically, or via arbitrary named metadata)?

 - `"ioproxy"`
        Does the image file format support writing to an `IOProxy`?

- `"procedural"` :
      Is this a purely procedural output that doesn't write an
      actual file?

This list of queries may be extended in future releases. Since this
can be done simply by recognizing new query strings, and does not
require any new API entry points, addition of support for new
queries does not break ``link compatibility'' with
previously-compiled plugins. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_supports(
    OIIO_ImageOutput_t const * this_
    , int * return_
    , OIIO_string_view_t feature);
#define OIIO_ImageOutput_supports OpenImageIO_v2_3_6__ImageOutput_supports


/** Open the file with given name, with resolution and other format
data as given in newspec. It is legal to call open multiple times
on the same file without a call to `close()`, if it supports
multiimage and mode is AppendSubimage, or if it supports
MIP-maps and mode is AppendMIPLevel -- this is interpreted as
appending a subimage, or a MIP level to the current subimage,
respectively.

@param  name        The name of the image file to open.
@param  newspec     The ImageSpec describing the resolution, data
                    types, etc.
@param  mode        Specifies whether the purpose of the `open` is
                    to create/truncate the file (default: `Create`),
                    append another subimage (`AppendSubimage`), or
                    append another MIP level (`AppendMIPLevel`).
@returns            `true` upon success, or `false` upon failure. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_open(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , std_string_t const * name
    , OIIO_ImageSpec_t const * newspec
    , OIIO_ImageOutput_OpenMode mode);
#define OIIO_ImageOutput_open OpenImageIO_v2_3_6__ImageOutput_open


/** Open a multi-subimage file with given name and specifications for
each of the subimages.  Upon success, the first subimage will be
open and ready for transmission of pixels.  Subsequent subimages
will be denoted with the usual call of
`open(name,spec,AppendSubimage)` (and MIP levels by
`open(name,spec,AppendMIPLevel)`).

The purpose of this call is to accommodate format-writing
libraries that must know the number and specifications of the
subimages upon first opening the file; such formats can be
detected by::
    supports("multiimage") && !supports("appendsubimage")
The individual specs passed to the appending open() calls for
subsequent subimages *must* match the ones originally passed.

@param  name        The name of the image file to open.
@param  subimages   The number of subimages (and therefore the
                    length of the `specs[]` array.
@param  specs[]
                     Pointer to an array of `ImageSpec` objects
                     describing each of the expected subimages.
@returns            `true` upon success, or `false` upon failure. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_open_subimage(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , std_string_t const * name
    , int subimages
    , OIIO_ImageSpec_t const * specs);
#define OIIO_ImageOutput_open_subimage OpenImageIO_v2_3_6__ImageOutput_open_subimage


/** Return a reference to the image format specification of the current
subimage.  Note that the contents of the spec are invalid before
`open()` or after `close()`. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_spec(
    OIIO_ImageOutput_t const * this_
    , OIIO_ImageSpec_t const * * return_);
#define OIIO_ImageOutput_spec OpenImageIO_v2_3_6__ImageOutput_spec


/** Closes the currently open file associated with this ImageOutput and
frees any memory or resources associated with it. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_close(
    OIIO_ImageOutput_t * this_
    , _Bool * return_);
#define OIIO_ImageOutput_close OpenImageIO_v2_3_6__ImageOutput_close


/** Write the full scanline that includes pixels (*,y,z).  For 2D
non-volume images, `z` should be 0. The `xstride` value gives the
distance between successive pixels (in bytes).  Strides set to
`AutoStride` imply "contiguous" data.

@param  y/z         The y & z coordinates of the scanline.
@param  format      A TypeDesc describing the type of `data`.
@param  data        Pointer to the pixel data.
@param  xstride     The distance in bytes between successive
                    pixels in `data` (or `AutoStride`).
@returns            `true` upon success, or `false` upon failure. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_write_scanline(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , int y
    , int z
    , OIIO_TypeDesc_t format
    , void const * data
    , long xstride);
#define OIIO_ImageOutput_write_scanline OpenImageIO_v2_3_6__ImageOutput_write_scanline


/** Write multiple scanlines that include pixels (*,y,z) for all ybegin
<= y < yend, from data.  This is analogous to
`write_scanline(y,z,format,data,xstride)` repeatedly for each of the
scanlines in turn (the advantage, though, is that some image file
types may be able to write multiple scanlines more efficiently or
in parallel, than it could with one scanline at a time).

@param  ybegin/yend The y range of the scanlines being passed.
@param  z           The z coordinate of the scanline.
@param  format      A TypeDesc describing the type of `data`.
@param  data        Pointer to the pixel data.
@param  xstride/ystride
                    The distance in bytes between successive pixels
                    and scanlines (or `AutoStride`).
@returns            `true` upon success, or `false` upon failure. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_write_scanlines(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , int ybegin
    , int yend
    , int z
    , OIIO_TypeDesc_t format
    , void const * data
    , long xstride
    , long ystride);
#define OIIO_ImageOutput_write_scanlines OpenImageIO_v2_3_6__ImageOutput_write_scanlines


/** Write the tile with (x,y,z) as the upper left corner.  The three
stride values give the distance (in bytes) between successive
pixels, scanlines, and volumetric slices, respectively.  Strides set
to AutoStride imply 'contiguous' data in the shape of a full tile,
i.e.,

    xstride = format.size() * spec.nchannels
    ystride = xstride * spec.tile_width
    zstride = ystride * spec.tile_height

@param  x/y/z       The upper left coordinate of the tile being passed.
@param  format      A TypeDesc describing the type of `data`.
@param  data        Pointer to the pixel data.
@param  xstride/ystride/zstride
                    The distance in bytes between successive pixels,
                    scanlines, and image planes (or `AutoStride` to
                    indicate a "contiguous" single tile).
@returns            `true` upon success, or `false` upon failure.

@note This call will fail if the image is not tiled, or if (x,y,z)
is not the upper left corner coordinates of a tile. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_write_tile(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , int x
    , int y
    , int z
    , OIIO_TypeDesc_t format
    , void const * data
    , long xstride
    , long ystride
    , long zstride);
#define OIIO_ImageOutput_write_tile OpenImageIO_v2_3_6__ImageOutput_write_tile


/** Write the block of multiple tiles that include all pixels in

    [xbegin,xend) X [ybegin,yend) X [zbegin,zend)

This is analogous to calling `write_tile(x,y,z,...)` for each tile
in turn (but for some file formats, passing multiple tiles may allow
it to write more efficiently or in parallel).

The begin/end pairs must correctly delineate tile boundaries, with
the exception that it may also be the end of the image data if the
image resolution is not a whole multiple of the tile size. The
stride values give the data spacing of adjacent pixels, scanlines,
and volumetric slices (measured in bytes). Strides set to AutoStride
imply contiguous data in the shape of the [begin,end) region, i.e.,

    xstride = format.size() * spec.nchannels
    ystride = xstride * (xend-xbegin)
    zstride = ystride * (yend-ybegin)

@param  xbegin/xend The x range of the pixels covered by the group
                    of tiles passed.
@param  ybegin/yend The y range of the pixels covered by the tiles.
@param  zbegin/zend The z range of the pixels covered by the tiles
                    (for a 2D image, zbegin=0 and zend=1).
@param  format      A TypeDesc describing the type of `data`.
@param  data        Pointer to the pixel data.
@param  xstride/ystride/zstride
                    The distance in bytes between successive pixels,
                    scanlines, and image planes (or `AutoStride`).
@returns            `true` upon success, or `false` upon failure.

@note The call will fail if the image is not tiled, or if the pixel
ranges do not fall along tile (or image) boundaries, or if it is not
a valid tile range. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_write_tiles(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend
    , OIIO_TypeDesc_t format
    , void const * data
    , long xstride
    , long ystride
    , long zstride);
#define OIIO_ImageOutput_write_tiles OpenImageIO_v2_3_6__ImageOutput_write_tiles


/** Write a rectangle of pixels given by the range

    [xbegin,xend) X [ybegin,yend) X [zbegin,zend)

The stride values give the data spacing of adjacent pixels,
scanlines, and volumetric slices (measured in bytes). Strides set to
AutoStride imply contiguous data in the shape of the [begin,end)
region, i.e.,

    xstride = format.size() * spec.nchannels
    ystride = xstride * (xend-xbegin)
    zstride = ystride * (yend-ybegin)

@param  xbegin/xend The x range of the pixels being passed.
@param  ybegin/yend The y range of the pixels being passed.
@param  zbegin/zend The z range of the pixels being passed
                    (for a 2D image, zbegin=0 and zend=1).
@param  format      A TypeDesc describing the type of `data`.
@param  data        Pointer to the pixel data.
@param  xstride/ystride/zstride
                    The distance in bytes between successive pixels,
                    scanlines, and image planes (or `AutoStride`).
@returns            `true` upon success, or `false` upon failure.

@note The call will fail for a format plugin that does not return
true for `supports("rectangles")`. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_write_rectangle(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend
    , OIIO_TypeDesc_t format
    , void const * data
    , long xstride
    , long ystride
    , long zstride);
#define OIIO_ImageOutput_write_rectangle OpenImageIO_v2_3_6__ImageOutput_write_rectangle


/** Write the entire image of `spec.width x spec.height x spec.depth`
pixels, from a buffer with the given strides and in the desired
format.

Depending on the spec, this will write either all tiles or all
scanlines. Assume that data points to a layout in row-major order.

Because this may be an expensive operation, a progress callback
may be passed.  Periodically, it will be called as follows:

    progress_callback (progress_callback_data, float done);

where `done` gives the portion of the image (between 0.0 and 1.0)
that has been written thus far.

@param  format      A TypeDesc describing the type of `data`.
@param  data        Pointer to the pixel data.
@param  xstride/ystride/zstride
                    The distance in bytes between successive pixels,
                    scanlines, and image planes (or `AutoStride`).
@param  progress_callback/progress_callback_data
                    Optional progress callback.
@returns            `true` upon success, or `false` upon failure. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_write_image(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , OIIO_TypeDesc_t format
    , void const * data
    , long xstride
    , long ystride
    , long zstride
    , OIIO_ProgressCallback_t progress_callback
    , void * progress_callback_data);
#define OIIO_ImageOutput_write_image OpenImageIO_v2_3_6__ImageOutput_write_image


/** Write deep scanlines containing pixels (*,y,z), for all y in the
range [ybegin,yend), to a deep file. This will fail if it is not a
deep file.

@param  ybegin/yend The y range of the scanlines being passed.
@param  z           The z coordinate of the scanline.
@param  deepdata    A `DeepData` object with the data for these
                    scanlines.
@returns            `true` upon success, or `false` upon failure. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_write_deep_scanlines(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , int ybegin
    , int yend
    , int z
    , OIIO_DeepData_t const * deepdata);
#define OIIO_ImageOutput_write_deep_scanlines OpenImageIO_v2_3_6__ImageOutput_write_deep_scanlines


/** Write the block of deep tiles that include all pixels in
the range

    [xbegin,xend) X [ybegin,yend) X [zbegin,zend)

The begin/end pairs must correctly delineate tile boundaries, with
the exception that it may also be the end of the image data if the
image resolution is not a whole multiple of the tile size.

@param  xbegin/xend The x range of the pixels covered by the group
                    of tiles passed.
@param  ybegin/yend The y range of the pixels covered by the tiles.
@param  zbegin/zend The z range of the pixels covered by the tiles
                    (for a 2D image, zbegin=0 and zend=1).
@param  deepdata    A `DeepData` object with the data for the tiles.
@returns            `true` upon success, or `false` upon failure.

@note The call will fail if the image is not tiled, or if the pixel
ranges do not fall along tile (or image) boundaries, or if it is not
a valid tile range. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_write_deep_tiles(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend
    , OIIO_DeepData_t const * deepdata);
#define OIIO_ImageOutput_write_deep_tiles OpenImageIO_v2_3_6__ImageOutput_write_deep_tiles


/** Write the entire deep image described by `deepdata`. Depending on
the spec, this will write either all tiles or all scanlines.

@param  deepdata    A `DeepData` object with the data for the image.
@returns            `true` upon success, or `false` upon failure. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_write_deep_image(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , OIIO_DeepData_t const * deepdata);
#define OIIO_ImageOutput_write_deep_image OpenImageIO_v2_3_6__ImageOutput_write_deep_image


/** Read the pixels of the current subimage of `in`, and write it as the
next subimage of `*this`, in a way that is efficient and does not
alter pixel values, if at all possible.  Both `in` and `this` must
be a properly-opened `ImageInput` and `ImageOutput`, respectively,
and their current images must match in size and number of channels.

If a particular ImageOutput implementation does not supply a
`copy_image` method, it will inherit the default implementation,
which is to simply read scanlines or tiles from `in` and write them
to `*this`.  However, some file format implementations may have a
special technique for directly copying raw pixel data from the input
to the output, when both are the same file type and the same pixel
data type.  This can be more efficient than `in->read_image()`
followed by `out->write_image()`, and avoids any unintended pixel
alterations, especially for formats that use lossy compression.

Note: this method is NOT thread-safe, since it depends on persistent
state in the ImageInput.

@param  in          A pointer to the open `ImageInput` to read from.
@returns            `true` upon success, or `false` upon failure. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_copy_image(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , OIIO_ImageInput_t * in);
#define OIIO_ImageOutput_copy_image OpenImageIO_v2_3_6__ImageOutput_copy_image


unsigned int OpenImageIO_v2_3_6__ImageOutput_send_to_output(
    OIIO_ImageOutput_t * this_
    , int * return_
    , char const * format);
#define OIIO_ImageOutput_send_to_output OpenImageIO_v2_3_6__ImageOutput_send_to_output


unsigned int OpenImageIO_v2_3_6__ImageOutput_send_to_client(
    OIIO_ImageOutput_t * this_
    , int * return_
    , char const * format);
#define OIIO_ImageOutput_send_to_client OpenImageIO_v2_3_6__ImageOutput_send_to_client


/** Set an IOProxy for this writer. This must be called prior to
`open()`, and only for writers that support them
(`supports("ioproxy")`). The caller retains ownership of the proxy.

@returns `true` for success, `false` for failure. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_set_ioproxy(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , OIIO_Filesystem_IOProxy_t * ioproxy);
#define OIIO_ImageOutput_set_ioproxy OpenImageIO_v2_3_6__ImageOutput_set_ioproxy


/** Is there a pending error message waiting to be retrieved, that
resulted from an ImageOutput API call made by the this thread?

Note that any `error()` calls issued are thread-specific, and the
`geterror()/has_error()` are expected to be called by the same
thread that called whichever API function encountered an error. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_has_error(
    OIIO_ImageOutput_t const * this_
    , _Bool * return_);
#define OIIO_ImageOutput_has_error OpenImageIO_v2_3_6__ImageOutput_has_error


/** Return the text of all pending error messages issued against this
ImageOutput by the calling thread, and clear the pending error
message unless `clear` is false. If no error message is pending, it
will return an empty string.

Note that any `error()` calls issued are thread-specific, and the
`geterror()/has_error()` are expected to be called by the same
thread that called whichever API function encountered an error. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_geterror(
    OIIO_ImageOutput_t const * this_
    , std_string_t * * return_
    , _Bool clear);
#define OIIO_ImageOutput_geterror OpenImageIO_v2_3_6__ImageOutput_geterror


/** Set the threading policy for this ImageOutput, controlling the
maximum amount of parallelizing thread "fan-out" that might occur
during large write operations. The default of 0 means that the
global `attribute("threads")` value should be used (which itself
defaults to using as many threads as cores; see Section
`Global Attributes`_).

The main reason to change this value is to set it to 1 to indicate
that the calling thread should do all the work rather than spawning
new threads. That is probably the desired behavior in situations
where the calling application has already spawned multiple worker
threads. */
unsigned int OpenImageIO_v2_3_6__ImageOutput_threads(
    OIIO_ImageOutput_t * this_
    , int n);
#define OIIO_ImageOutput_threads OpenImageIO_v2_3_6__ImageOutput_threads


/** Retrieve the current thread-spawning policy.
@see  `threads(int)` */
unsigned int OpenImageIO_v2_3_6__ImageOutput_threads_const(
    OIIO_ImageOutput_t const * this_
    , int * return_);
#define OIIO_ImageOutput_threads_const OpenImageIO_v2_3_6__ImageOutput_threads_const


/** Union of two regions, the smallest region containing both. */
unsigned int OpenImageIO_v2_3_6_roi_union(
    OIIO_ROI_t * return_
    , OIIO_ROI_t const * A
    , OIIO_ROI_t const * B);
#define OIIO_roi_union OpenImageIO_v2_3_6_roi_union


/** Intersection of two regions. */
unsigned int OpenImageIO_v2_3_6_roi_intersection(
    OIIO_ROI_t * return_
    , OIIO_ROI_t const * A
    , OIIO_ROI_t const * B);
#define OIIO_roi_intersection OpenImageIO_v2_3_6_roi_intersection


/** Returns a numeric value for the version of OpenImageIO, 10000 for each
major version, 100 for each minor version, 1 for each patch.  For
example, OpenImageIO 1.2.3 would return a value of 10203. One example of
how this is useful is for plugins to query the version to be sure they
are linked against an adequate version of the library. */
unsigned int OpenImageIO_v2_3_6_openimageio_version(
    int * return_);
#define OIIO_openimageio_version OpenImageIO_v2_3_6_openimageio_version


/** Returns any error string describing what went wrong if
`ImageInput::create()` or `ImageOutput::create()` failed (since in such
cases, the ImageInput or ImageOutput itself does not exist to have its
own `geterror()` function called). This function returns the last error
for this particular thread, and clear the pending error message unless
`clear` is false; separate threads will not clobber each other's global
error messages. */
unsigned int OpenImageIO_v2_3_6_geterror(
    std_string_t * * return_
    , _Bool clear);
#define OIIO_geterror OpenImageIO_v2_3_6_geterror


/** `OIIO::attribute()` sets an global attribute (i.e., a property or
option) of OpenImageIO. The `name` designates the name of the attribute,
`type` describes the type of data, and `val` is a pointer to memory
containing the new value for the attribute.

If the name is known, valid attribute that matches the type specified,
the attribute will be set to the new value and `attribute()` will return
`true`.  If `name` is not recognized, or if the types do not match
(e.g., `type` is `TypeFloat` but the named attribute is a string), the
attribute will not be modified, and `attribute()` will return `false`.

The following are the recognized attributes:

- `string options`

   This catch-all is simply a comma-separated list of `name=value`
   settings of named options, which will be parsed and individually set.
   For example,

       OIIO::attribute ("options", "threads=4,log_times=1");

   Note that if an option takes a string value that must itself contain
   a comma, it is permissible to enclose the value in either 'single'
   or "double" quotes.

- `int threads`

   How many threads to use for operations that can be sped up by being
   multithreaded. (Examples: simultaneous format conversions of multiple
   scanlines read together, or many ImageBufAlgo operations.) The
   default is 0, meaning to use the full available hardware concurrency
   detected.

   Situations where the main application logic is essentially single
   threaded (i.e., one top-level call into OIIO at a time) should leave
   this at the default value, or some reasonable number of cores, thus
   allowing lots of threads to fill the cores when OIIO has big tasks to
   complete. But situations where you have many threads at the
   application level, each of which is expected to be making separate
   OIIO calls simultaneously, should set this to 1, thus having each
   calling thread do its own work inside of OIIO rather than spawning
   new threads with a high overall "fan out.""

- `int exr_threads`

   Sets the internal OpenEXR thread pool size. The default is to use as
   many threads as the amount of hardware concurrency detected. Note
   that this is separate from the OIIO `"threads"` attribute.

- `string plugin_searchpath`

   Colon-separated list of directories to search for dynamically-loaded
   format plugins.

- `int read_chunk`

   When performing a `read_image()`, this is the number of scanlines it
   will attempt to read at a time (some formats are more efficient when
   reading and decoding multiple scanlines).  The default is 256. The
   special value of 0 indicates that it should try to read the whole
   image if possible.

- `float[] missingcolor`, `string missingcolor`

   This attribute may either be an array of float values, or a string
   containing a comma-separated list of the values. Setting this option
   globally is equivalent to always passing an `ImageInput`
   open-with-configuration hint `"oiio:missingcolor"` with the value.

   When set, it gives some `ImageInput` readers the option of ignoring
   any *missing* tiles or scanlines in the file, and instead of treating
   the read failure of an individual tile as a full error, will
   interpret is as an intentionally missing tile and proceed by simply
   filling in the missing pixels with the color specified. If the first
   element is negative, it will use the absolute value, but draw
   alternating diagonal stripes of the color. For example,

       float missing[4] = { -1.0, 0.0, 0.0, 0.0 }; // striped red
       OIIO::attribute ("missingcolor", TypeDesc("float[4]"), &missing);

   Note that only some file formats support files with missing tiles or
   scanlines, and this is only taken as a hint. Please see
   chap-bundledplugins_ for details on which formats accept a
   `"missingcolor"` configuration hint.

- `int debug`

   When nonzero, various debug messages may be printed. The default is 0
   for release builds, 1 for DEBUG builds (values > 1 are for OIIO
   developers to print even more debugging information), This attribute
   but also may be overridden by the OPENIMAGEIO_DEBUG environment
   variable.

- `int tiff:half`

   When nonzero, allows TIFF to write `half` pixel data. N.B. Most apps
   may not read these correctly, but OIIO will. That's why the default
   is not to support it.

- `int log_times`

   When the `"log_times"` attribute is nonzero, `ImageBufAlgo` functions
   are instrumented to record the number of times they were called and
   the total amount of time spent executing them. It can be overridden
   by environment variable `OPENIMAGEIO_LOG_TIMES`. The totals will be
   recorded and can be retrieved as a string by using
   `OIIO::getattribute("timing_report", ...)`. Additionally, if the
   value is 2 or more, the timing report will be printed to `stdout`
   upon application exit (not advised in contexts where it isn't ok to
   print to the terminal via stdout, such as GUI apps or libraries).

   When enabled, there is a slight runtime performance cost due to
   checking the time at the start and end of each of those function
   calls, and the locking and recording of the data structure that holds
   the log information. When the `log_times` attribute is disabled,
   there is no additional performance cost. */
unsigned int OpenImageIO_v2_3_6_attribute(
    _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void const * val);
#define OIIO_attribute OpenImageIO_v2_3_6_attribute


/** Shortcut attribute() for setting a single integer. */
unsigned int OpenImageIO_v2_3_6_attribute_int(
    _Bool * return_
    , OIIO_string_view_t name
    , int val);
#define OIIO_attribute_int OpenImageIO_v2_3_6_attribute_int


/** Shortcut attribute() for setting a single float. */
unsigned int OpenImageIO_v2_3_6_attribute_float(
    _Bool * return_
    , OIIO_string_view_t name
    , float val);
#define OIIO_attribute_float OpenImageIO_v2_3_6_attribute_float


/** Shortcut attribute() for setting a single string. */
unsigned int OpenImageIO_v2_3_6_attribute_string(
    _Bool * return_
    , OIIO_string_view_t name
    , OIIO_string_view_t val);
#define OIIO_attribute_string OpenImageIO_v2_3_6_attribute_string


/** Get the named global attribute of OpenImageIO, store it in `*val`.
Return `true` if found and it was compatible with the type specified,
otherwise return `false` and do not modify the contents of `*val`.  It
is up to the caller to ensure that `val` points to the right kind and
size of storage for the given type.

In addition to being able to retrieve all the attributes that are
documented as settable by the `OIIO::attribute()` call, `getattribute()`
can also retrieve the following read-only attributes:

- `string format_list`
- `string input_format_list`
- `string output_format_list`

  A comma-separated list of all the names of, respectively, all
  supported image formats, all formats accepted as inputs, and all
  formats accepted as outputs.

- `string extension_list`

  For each format, the format name, followed by a colon, followed by a
  comma-separated list of all extensions that are presumed to be used
  for that format.  Semicolons separate the lists for formats.  For
  example,

       "tiff:tif;jpeg:jpg,jpeg;openexr:exr"

- `string library_list`

  For each format that uses a dependent library, the format name,
  followed by a colon, followed by the name and version of the
  dependency. Semicolons separate the lists for formats.  For example,

       "tiff:LIBTIFF 4.0.4;gif:gif_lib 4.2.3;openexr:OpenEXR 2.2.0"

- string "timing_report"
        A string containing the report of all the log_times.

- `string hw:simd`
- `string oiio:simd` (read-only)

  A comma-separated list of hardware CPU features for SIMD (and some
  other things). The `"oiio:simd"` attribute is similarly a list of
  which features this build of OIIO was compiled to support.

  This was added in OpenImageIO 1.8.

- `float resident_memory_used_MB`

  This read-only attribute can be used for debugging purposes to report
  the approximate process memory used (resident) by the application, in
  MB.

- `string timing_report`

   Retrieving this attribute returns the timing report generated by the
   `log_timing` attribute (if it was enabled). The report is sorted
   alphabetically and for each named instrumentation region, prints the
   number of times it executed, the total runtime, and the average per
   call, like this:

       IBA::computePixelStats        2   2.69ms  (avg   1.34ms)
       IBA::make_texture             1  74.05ms  (avg  74.05ms)
       IBA::mul                      8   2.42ms  (avg   0.30ms)
       IBA::over                    10  23.82ms  (avg   2.38ms)
       IBA::resize                  20   0.24s   (avg  12.18ms)
       IBA::zero                     8   0.66ms  (avg   0.08ms) */
unsigned int OpenImageIO_v2_3_6_getattribute(
    _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void * val);
#define OIIO_getattribute OpenImageIO_v2_3_6_getattribute


/** Shortcut getattribute() for retrieving a single integer.
The value is placed in `val`, and the function returns `true` if the
attribute was found and was legally convertible to an int. */
unsigned int OpenImageIO_v2_3_6_getattribute_int(
    _Bool * return_
    , OIIO_string_view_t name
    , int * val);
#define OIIO_getattribute_int OpenImageIO_v2_3_6_getattribute_int


/** Shortcut getattribute() for retrieving a single float.
The value is placed in `val`, and the function returns `true` if the
attribute was found and was legally convertible to a float. */
unsigned int OpenImageIO_v2_3_6_getattribute_float(
    _Bool * return_
    , OIIO_string_view_t name
    , float * val);
#define OIIO_getattribute_float OpenImageIO_v2_3_6_getattribute_float


/** Shortcut getattribute() for retrieving a single string as a
`std::string`. The value is placed in `val`, and the function returns
`true` if the attribute was found. */
unsigned int OpenImageIO_v2_3_6_getattribute_string(
    _Bool * return_
    , OIIO_string_view_t name
    , std_string_t * val);
#define OIIO_getattribute_string OpenImageIO_v2_3_6_getattribute_string


/** Shortcut getattribute() for retrieving a single string as a `char*`. */
unsigned int OpenImageIO_v2_3_6_getattribute_cstr(
    _Bool * return_
    , OIIO_string_view_t name
    , char * * val);
#define OIIO_getattribute_cstr OpenImageIO_v2_3_6_getattribute_cstr


/** Shortcut getattribute() for retrieving a single integer, with a supplied
default value that will be returned if the attribute is not found or
could not legally be converted to an int. */
unsigned int OpenImageIO_v2_3_6_get_int_attribute(
    int * return_
    , OIIO_string_view_t name
    , int defaultval);
#define OIIO_get_int_attribute OpenImageIO_v2_3_6_get_int_attribute


/** Shortcut getattribute() for retrieving a single float, with a supplied
default value that will be returned if the attribute is not found or
could not legally be converted to a float. */
unsigned int OpenImageIO_v2_3_6_get_float_attribute(
    float * return_
    , OIIO_string_view_t name
    , float defaultval);
#define OIIO_get_float_attribute OpenImageIO_v2_3_6_get_float_attribute


/** Shortcut getattribute() for retrieving a single string, with a supplied
default value that will be returned if the attribute is not found. */
unsigned int OpenImageIO_v2_3_6_get_string_attribute(
    OIIO_string_view_t * return_
    , OIIO_string_view_t name
    , OIIO_string_view_t defaultval);
#define OIIO_get_string_attribute OpenImageIO_v2_3_6_get_string_attribute


/** Helper function: convert contiguous data between two arbitrary pixel
data types (specified by TypeDesc's). Return true if ok, false if it
didn't know how to do the conversion.  If dst_type is UNKNOWN, it will
be assumed to be the same as src_type.

The conversion is of normalized (pixel-like) values -- for example
'UINT8' 255 will convert to float 1.0 and vice versa, not float 255.0.
If you want a straight C-like data cast convertion (e.g., uint8 255 ->
float 255.0), then you should prefer the un-normalized convert_type()
utility function found in typedesc.h. */
unsigned int OpenImageIO_v2_3_6_convert_pixel_values(
    _Bool * return_
    , OIIO_TypeDesc_t src_type
    , void const * src
    , OIIO_TypeDesc_t dst_type
    , void * dst
    , int n);
#define OIIO_convert_pixel_values OpenImageIO_v2_3_6_convert_pixel_values


/** DEPRECATED(2.1): old name */
unsigned int OpenImageIO_v2_3_6_convert_types(
    _Bool * return_
    , OIIO_TypeDesc_t src_type
    , void const * src
    , OIIO_TypeDesc_t dst_type
    , void * dst
    , int n);
#define OIIO_convert_types OpenImageIO_v2_3_6_convert_types


/** Helper routine for data conversion: Convert an image of nchannels x
width x height x depth from src to dst.  The src and dst may have
different data formats and layouts.  Clever use of this function can
not only exchange data among different formats (e.g., half to 8-bit
unsigned), but also can copy selective channels, copy subimages,
etc.  If you're lazy, it's ok to pass AutoStride for any of the
stride values, and they will be auto-computed assuming contiguous
data.  Return true if ok, false if it didn't know how to do the
conversion. */
unsigned int OpenImageIO_v2_3_6_convert_image(
    _Bool * return_
    , int nchannels
    , int width
    , int height
    , int depth
    , void const * src
    , OIIO_TypeDesc_t src_type
    , long src_xstride
    , long src_ystride
    , long src_zstride
    , void * dst
    , OIIO_TypeDesc_t dst_type
    , long dst_xstride
    , long dst_ystride
    , long dst_zstride);
#define OIIO_convert_image OpenImageIO_v2_3_6_convert_image


/** A version of convert_image that will break up big jobs into multiple
threads. */
unsigned int OpenImageIO_v2_3_6_parallel_convert_image(
    _Bool * return_
    , int nchannels
    , int width
    , int height
    , int depth
    , void const * src
    , OIIO_TypeDesc_t src_type
    , long src_xstride
    , long src_ystride
    , long src_zstride
    , void * dst
    , OIIO_TypeDesc_t dst_type
    , long dst_xstride
    , long dst_ystride
    , long dst_zstride
    , int nthreads);
#define OIIO_parallel_convert_image OpenImageIO_v2_3_6_parallel_convert_image


/** Add random [-theramplitude,ditheramplitude] dither to the color channels
of the image.  Dither will not be added to the alpha or z channel.  The
image origin and dither seed values allow a reproducible (or variable)
dither pattern.  If the strides are set to AutoStride, they will be
assumed to be contiguous floats in data of the given dimensions. */
unsigned int OpenImageIO_v2_3_6_add_dither(
    int nchannels
    , int width
    , int height
    , int depth
    , float * data
    , long xstride
    , long ystride
    , long zstride
    , float ditheramplitude
    , int alpha_channel
    , int z_channel
    , unsigned int ditherseed
    , int chorigin
    , int xorigin
    , int yorigin
    , int zorigin);
#define OIIO_add_dither OpenImageIO_v2_3_6_add_dither


/** Convert unassociated to associated alpha by premultiplying all color
(non-alpha, non-z) channels by alpha. The nchannels, width, height, and
depth parameters describe the "shape" of the image data (along with
optional stride overrides). The chbegin/chend describe which range of
channels to actually premultiply. */
unsigned int OpenImageIO_v2_3_6_premult(
    int nchannels
    , int width
    , int height
    , int depth
    , int chbegin
    , int chend
    , OIIO_TypeDesc_t datatype
    , void * data
    , long xstride
    , long ystride
    , long zstride
    , int alpha_channel
    , int z_channel);
#define OIIO_premult OpenImageIO_v2_3_6_premult


/** Helper routine for data conversion: Copy an image of nchannels x
width x height x depth from src to dst.  The src and dst may have
different data layouts, but must have the same data type.  Clever
use of this function can change layouts or strides, copy selective
channels, copy subimages, etc.  If you're lazy, it's ok to pass
AutoStride for any of the stride values, and they will be
auto-computed assuming contiguous data.  Return true if ok, false if
it didn't know how to do the conversion. */
unsigned int OpenImageIO_v2_3_6_copy_image(
    _Bool * return_
    , int nchannels
    , int width
    , int height
    , int depth
    , void const * src
    , long pixelsize
    , long src_xstride
    , long src_ystride
    , long src_zstride
    , void * dst
    , long dst_xstride
    , long dst_ystride
    , long dst_zstride);
#define OIIO_copy_image OpenImageIO_v2_3_6_copy_image


unsigned int OpenImageIO_v2_3_6_wrap_black(
    _Bool * return_
    , int * coord
    , int origin
    , int width);
#define OIIO_wrap_black OpenImageIO_v2_3_6_wrap_black


unsigned int OpenImageIO_v2_3_6_wrap_clamp(
    _Bool * return_
    , int * coord
    , int origin
    , int width);
#define OIIO_wrap_clamp OpenImageIO_v2_3_6_wrap_clamp


unsigned int OpenImageIO_v2_3_6_wrap_periodic(
    _Bool * return_
    , int * coord
    , int origin
    , int width);
#define OIIO_wrap_periodic OpenImageIO_v2_3_6_wrap_periodic


unsigned int OpenImageIO_v2_3_6_wrap_periodic_pow2(
    _Bool * return_
    , int * coord
    , int origin
    , int width);
#define OIIO_wrap_periodic_pow2 OpenImageIO_v2_3_6_wrap_periodic_pow2


unsigned int OpenImageIO_v2_3_6_wrap_mirror(
    _Bool * return_
    , int * coord
    , int origin
    , int width);
#define OIIO_wrap_mirror OpenImageIO_v2_3_6_wrap_mirror


/** `debug(format, ...)` prints debugging message when attribute "debug" is
nonzero, which it is by default for DEBUG compiles or when the
environment variable OPENIMAGEIO_DEBUG is set. This is preferred to raw
output to stderr for debugging statements. */
unsigned int OpenImageIO_v2_3_6_debug(
    OIIO_string_view_t str);
#define OIIO_debug OpenImageIO_v2_3_6_debug


unsigned int OpenImageIO_v2_3_6__ImageIO_force_link();
#define OIIO__ImageIO_force_link OpenImageIO_v2_3_6__ImageIO_force_link


#ifdef __cplusplus
}
#endif
