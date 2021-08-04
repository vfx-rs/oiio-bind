#pragma once
#include <c-std_shared_ptr.h>
#include <c-std_string.h>
#include <c-std_vector.h>
#include <c-string_view.h>
#include <c-typedesc.h>
#include <c-ustring.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Imath_3_2__Matrix44_float__t_s Imath_3_2__Matrix44_float__t;
typedef Imath_3_2__Matrix44_float__t Imath_M44f_t;

/** The ColorProcessor encapsulates a baked color transformation, suitable for
application to raw pixels, or ImageBuf(s). These are generated using
ColorConfig::createColorProcessor, and referenced in ImageBufAlgo
(amongst other places) */
typedef struct OpenImageIO_v2_3_6__ColorProcessor_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__ColorProcessor_t;
typedef OpenImageIO_v2_3_6__ColorProcessor_t OIIO_ColorProcessor_t;

/** Represents the set of all color transformations that are allowed.
If OpenColorIO is enabled at build time, this configuration is loaded
at runtime, allowing the user to have complete control of all color
transformation math. ($OCIO)  (See opencolorio.org for details).
If OpenColorIO is not enabled at build time, a generic color configuration
is provided for minimal color support.

NOTE: ColorConfig(s) and ColorProcessor(s) are potentially heavy-weight.
Their construction / destruction should be kept to a minimum. */
typedef struct OpenImageIO_v2_3_6__ColorConfig_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__ColorConfig_t;
typedef OpenImageIO_v2_3_6__ColorConfig_t OIIO_ColorConfig_t;


unsigned int OpenImageIO_v2_3_6__ColorProcessor_dtor(
    OIIO_ColorProcessor_t * this_);
#define OIIO_ColorProcessor_dtor OpenImageIO_v2_3_6__ColorProcessor_dtor


unsigned int OpenImageIO_v2_3_6__ColorProcessor_isNoOp(
    OIIO_ColorProcessor_t const * this_
    , _Bool * return_);
#define OIIO_ColorProcessor_isNoOp OpenImageIO_v2_3_6__ColorProcessor_isNoOp


unsigned int OpenImageIO_v2_3_6__ColorProcessor_hasChannelCrosstalk(
    OIIO_ColorProcessor_t const * this_
    , _Bool * return_);
#define OIIO_ColorProcessor_hasChannelCrosstalk OpenImageIO_v2_3_6__ColorProcessor_hasChannelCrosstalk


unsigned int OpenImageIO_v2_3_6__ColorProcessor_apply(
    OIIO_ColorProcessor_t const * this_
    , float * data
    , int width
    , int height
    , int channels
    , long chanstride
    , long xstride
    , long ystride);
#define OIIO_ColorProcessor_apply OpenImageIO_v2_3_6__ColorProcessor_apply


unsigned int OpenImageIO_v2_3_6__ColorProcessor_apply_single(
    OIIO_ColorProcessor_t * this_
    , float * data);
#define OIIO_ColorProcessor_apply_single OpenImageIO_v2_3_6__ColorProcessor_apply_single


/** Construct a ColorConfig using the named OCIO configuration file,
or if filename is empty, to the current color configuration
specified by env variable $OCIO.

Multiple calls to this are potentially expensive. A ColorConfig
should usually be shared by an app for its entire runtime. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_ctor(
    OIIO_ColorConfig_t * * this_
    , OIIO_string_view_t filename);
#define OIIO_ColorConfig_ctor OpenImageIO_v2_3_6__ColorConfig_ctor


unsigned int OpenImageIO_v2_3_6__ColorConfig_dtor(
    OIIO_ColorConfig_t * this_);
#define OIIO_ColorConfig_dtor OpenImageIO_v2_3_6__ColorConfig_dtor


/** Reset the config to the named OCIO configuration file, or if
filename is empty, to the current color configuration specified
by env variable $OCIO. Return true for success, false if there
was an error.

Multiple calls to this are potentially expensive. A ColorConfig
should usually be shared by an app for its entire runtime. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_reset(
    OIIO_ColorConfig_t * this_
    , _Bool * return_
    , OIIO_string_view_t filename);
#define OIIO_ColorConfig_reset OpenImageIO_v2_3_6__ColorConfig_reset


/** Has an error string occurred?
(This will not affect the error state.) */
unsigned int OpenImageIO_v2_3_6__ColorConfig_error(
    OIIO_ColorConfig_t const * this_
    , _Bool * return_);
#define OIIO_ColorConfig_error OpenImageIO_v2_3_6__ColorConfig_error


/** This routine will return the error string (and by default, clear any
error flags).  If no error has occurred since the last time
geterror() was called, it will return an empty string. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_geterror(
    OIIO_ColorConfig_t * this_
    , std_string_t * * return_
    , _Bool clear);
#define OIIO_ColorConfig_geterror OpenImageIO_v2_3_6__ColorConfig_geterror


/** Get the number of ColorSpace(s) defined in this configuration */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getNumColorSpaces(
    OIIO_ColorConfig_t const * this_
    , int * return_);
#define OIIO_ColorConfig_getNumColorSpaces OpenImageIO_v2_3_6__ColorConfig_getNumColorSpaces


/** Query the name of the specified ColorSpace. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getColorSpaceNameByIndex(
    OIIO_ColorConfig_t const * this_
    , char const * * return_
    , int index);
#define OIIO_ColorConfig_getColorSpaceNameByIndex OpenImageIO_v2_3_6__ColorConfig_getColorSpaceNameByIndex


/** Get the name of the color space representing the named role,
or NULL if none could be identified. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getColorSpaceNameByRole(
    OIIO_ColorConfig_t const * this_
    , char const * * return_
    , OIIO_string_view_t role);
#define OIIO_ColorConfig_getColorSpaceNameByRole OpenImageIO_v2_3_6__ColorConfig_getColorSpaceNameByRole


/** Get the data type that OCIO thinks this color space is. The name
may be either a color space name or a role. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getColorSpaceDataType(
    OIIO_ColorConfig_t const * this_
    , OIIO_TypeDesc_t * return_
    , OIIO_string_view_t name
    , int * bits);
#define OIIO_ColorConfig_getColorSpaceDataType OpenImageIO_v2_3_6__ColorConfig_getColorSpaceDataType


/** Retrieve the full list of known color space names, as a vector
of strings. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getColorSpaceNames(
    OIIO_ColorConfig_t const * this_
    , std_vector_string_t * * return_);
#define OIIO_ColorConfig_getColorSpaceNames OpenImageIO_v2_3_6__ColorConfig_getColorSpaceNames


/** Get the name of the color space family of the named color space,
or NULL if none could be identified. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getColorSpaceFamilyByName(
    OIIO_ColorConfig_t const * this_
    , char const * * return_
    , OIIO_string_view_t name);
#define OIIO_ColorConfig_getColorSpaceFamilyByName OpenImageIO_v2_3_6__ColorConfig_getColorSpaceFamilyByName


unsigned int OpenImageIO_v2_3_6__ColorConfig_getNumRoles(
    OIIO_ColorConfig_t const * this_
    , int * return_);
#define OIIO_ColorConfig_getNumRoles OpenImageIO_v2_3_6__ColorConfig_getNumRoles


/** Query the name of the specified Role. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getRoleByIndex(
    OIIO_ColorConfig_t const * this_
    , char const * * return_
    , int index);
#define OIIO_ColorConfig_getRoleByIndex OpenImageIO_v2_3_6__ColorConfig_getRoleByIndex


/** Retrieve the full list of known Roles, as a vector of strings. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getRoles(
    OIIO_ColorConfig_t const * this_
    , std_vector_string_t * * return_);
#define OIIO_ColorConfig_getRoles OpenImageIO_v2_3_6__ColorConfig_getRoles


/** Get the number of Looks defined in this configuration */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getNumLooks(
    OIIO_ColorConfig_t const * this_
    , int * return_);
#define OIIO_ColorConfig_getNumLooks OpenImageIO_v2_3_6__ColorConfig_getNumLooks


/** Query the name of the specified Look. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getLookNameByIndex(
    OIIO_ColorConfig_t const * this_
    , char const * * return_
    , int index);
#define OIIO_ColorConfig_getLookNameByIndex OpenImageIO_v2_3_6__ColorConfig_getLookNameByIndex


/** Retrieve the full list of known look names, as a vector of strings. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getLookNames(
    OIIO_ColorConfig_t const * this_
    , std_vector_string_t * * return_);
#define OIIO_ColorConfig_getLookNames OpenImageIO_v2_3_6__ColorConfig_getLookNames


/** Given the specified input and output ColorSpace, request a handle to
a ColorProcessor.  It is possible that this will return an empty
handle, if the inputColorSpace doesn't exist, the outputColorSpace
doesn't exist, or if the specified transformation is illegal (for
example, it may require the inversion of a 3D-LUT, etc).

The handle is actually a shared_ptr, so when you're done with a
ColorProcess, just discard it. ColorProcessor(s) remain valid even
if the ColorConfig that created them no longer exists.

Created ColorProcessors are cached, so asking for the same color
space transformation multiple times shouldn't be very expensive. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_createColorProcessor(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , OIIO_string_view_t inputColorSpace
    , OIIO_string_view_t outputColorSpace
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value);
#define OIIO_ColorConfig_createColorProcessor OpenImageIO_v2_3_6__ColorConfig_createColorProcessor


unsigned int OpenImageIO_v2_3_6__ColorConfig_createColorProcessor_ustring(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , OIIO_ustring_t inputColorSpace
    , OIIO_ustring_t outputColorSpace
    , OIIO_ustring_t context_key
    , OIIO_ustring_t context_value);
#define OIIO_ColorConfig_createColorProcessor_ustring OpenImageIO_v2_3_6__ColorConfig_createColorProcessor_ustring


/** Given the named look(s), input and output color spaces, request a
color processor that applies an OCIO look transformation.  If
inverse==true, request the inverse transformation.  The
context_key and context_value can optionally be used to establish
extra key/value pairs in the OCIO context if they are comma-
separated lists of ontext keys and values, respectively.

The handle is actually a shared_ptr, so when you're done with a
ColorProcess, just discard it. ColorProcessor(s) remain valid even
if the ColorConfig that created them no longer exists.

Created ColorProcessors are cached, so asking for the same color
space transformation multiple times shouldn't be very expensive. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_createLookTransform(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , OIIO_string_view_t looks
    , OIIO_string_view_t inputColorSpace
    , OIIO_string_view_t outputColorSpace
    , _Bool inverse
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value);
#define OIIO_ColorConfig_createLookTransform OpenImageIO_v2_3_6__ColorConfig_createLookTransform


unsigned int OpenImageIO_v2_3_6__ColorConfig_createLookTransform_ustring(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , OIIO_ustring_t looks
    , OIIO_ustring_t inputColorSpace
    , OIIO_ustring_t outputColorSpace
    , _Bool inverse
    , OIIO_ustring_t context_key
    , OIIO_ustring_t context_value);
#define OIIO_ColorConfig_createLookTransform_ustring OpenImageIO_v2_3_6__ColorConfig_createLookTransform_ustring


/** Get the number of displays defined in this configuration */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getNumDisplays(
    OIIO_ColorConfig_t const * this_
    , int * return_);
#define OIIO_ColorConfig_getNumDisplays OpenImageIO_v2_3_6__ColorConfig_getNumDisplays


/** Query the name of the specified display. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getDisplayNameByIndex(
    OIIO_ColorConfig_t const * this_
    , char const * * return_
    , int index);
#define OIIO_ColorConfig_getDisplayNameByIndex OpenImageIO_v2_3_6__ColorConfig_getDisplayNameByIndex


/** Retrieve the full list of known display names, as a vector of
strings. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getDisplayNames(
    OIIO_ColorConfig_t const * this_
    , std_vector_string_t * * return_);
#define OIIO_ColorConfig_getDisplayNames OpenImageIO_v2_3_6__ColorConfig_getDisplayNames


/** Get the name of the default display. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getDefaultDisplayName(
    OIIO_ColorConfig_t const * this_
    , char const * * return_);
#define OIIO_ColorConfig_getDefaultDisplayName OpenImageIO_v2_3_6__ColorConfig_getDefaultDisplayName


/** Get the number of views for a given display defined in this
configuration. If the display is empty or not specified, the default
display will be used. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getNumViews(
    OIIO_ColorConfig_t const * this_
    , int * return_
    , OIIO_string_view_t display);
#define OIIO_ColorConfig_getNumViews OpenImageIO_v2_3_6__ColorConfig_getNumViews


/** Query the name of the specified view for the specified display */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getViewNameByIndex(
    OIIO_ColorConfig_t const * this_
    , char const * * return_
    , OIIO_string_view_t display
    , int index);
#define OIIO_ColorConfig_getViewNameByIndex OpenImageIO_v2_3_6__ColorConfig_getViewNameByIndex


/** Retrieve the full list of known view names for the display, as a
vector of strings. If the display is empty or not specified, the
default display will be used. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getViewNames(
    OIIO_ColorConfig_t const * this_
    , std_vector_string_t * * return_
    , OIIO_string_view_t display);
#define OIIO_ColorConfig_getViewNames OpenImageIO_v2_3_6__ColorConfig_getViewNames


/** Query the name of the default view for the specified display. If the
display is empty or not specified, the default display will be used. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getDefaultViewName(
    OIIO_ColorConfig_t const * this_
    , char const * * return_
    , OIIO_string_view_t display);
#define OIIO_ColorConfig_getDefaultViewName OpenImageIO_v2_3_6__ColorConfig_getDefaultViewName


/** Construct a processor to transform from the given color space
to the color space of the given display and view. You may optionally
override the looks that are, by default, used with the display/view
combination. Looks is a potentially comma (or colon) delimited list
of lookNames, where +/- prefixes are optionally allowed to denote
forward/inverse transformation (and forward is assumed in the
absence of either). It is possible to remove all looks from the
display by passing an empty string. The context_key and context_value
can optionally be used to establish extra key/value pair in the OCIO
context if they are comma-separated lists of context keys and
values, respectively.

It is possible that this will return an empty handle if one of the
color spaces or the display or view doesn't exist or is not allowed.

The handle is actually a shared_ptr, so when you're done with a
ColorProcess, just discard it. ColorProcessor(s) remain valid even
if the ColorConfig that created them no longer exists.

Created ColorProcessors are cached, so asking for the same color
space transformation multiple times shouldn't be very expensive. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_createDisplayTransform(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , OIIO_string_view_t display
    , OIIO_string_view_t view
    , OIIO_string_view_t inputColorSpace
    , OIIO_string_view_t looks
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value);
#define OIIO_ColorConfig_createDisplayTransform OpenImageIO_v2_3_6__ColorConfig_createDisplayTransform


unsigned int OpenImageIO_v2_3_6__ColorConfig_createDisplayTransform_ustring(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , OIIO_ustring_t display
    , OIIO_ustring_t view
    , OIIO_ustring_t inputColorSpace
    , OIIO_ustring_t looks
    , OIIO_ustring_t context_key
    , OIIO_ustring_t context_value);
#define OIIO_ColorConfig_createDisplayTransform_ustring OpenImageIO_v2_3_6__ColorConfig_createDisplayTransform_ustring


/** Construct a processor to perform color transforms determined by an
OpenColorIO FileTransform. It is possible that this will return an
empty handle if the FileTransform doesn't exist or is not allowed.

The handle is actually a shared_ptr, so when you're done with a
ColorProcess, just discard it. ColorProcessor(s) remain valid even
if the ColorConfig that created them no longer exists.

Created ColorProcessors are cached, so asking for the same color
space transformation multiple times shouldn't be very expensive. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_createFileTransform(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , OIIO_string_view_t name
    , _Bool inverse);
#define OIIO_ColorConfig_createFileTransform OpenImageIO_v2_3_6__ColorConfig_createFileTransform


unsigned int OpenImageIO_v2_3_6__ColorConfig_createFileTransform_ustring(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , OIIO_ustring_t name
    , _Bool inverse);
#define OIIO_ColorConfig_createFileTransform_ustring OpenImageIO_v2_3_6__ColorConfig_createFileTransform_ustring


/** Construct a processor to perform color transforms specified by a
4x4 matrix.

The handle is actually a shared_ptr, so when you're done with a
ColorProcess, just discard it.

Created ColorProcessors are cached, so asking for the same color
space transformation multiple times shouldn't be very expensive. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_createMatrixTransform(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , Imath_M44f_t const * M
    , _Bool inverse);
#define OIIO_ColorConfig_createMatrixTransform OpenImageIO_v2_3_6__ColorConfig_createMatrixTransform


/** Given a filepath, ask OCIO what color space it thinks the file
should be, based on how the name matches file naming rules in the
OCIO config.  (This is mostly a wrapper around OCIO's
ColorConfig::getColorSpaceFromSFilepath.) */
unsigned int OpenImageIO_v2_3_6__ColorConfig_getColorSpaceFromFilepath(
    OIIO_ColorConfig_t const * this_
    , OIIO_string_view_t * return_
    , OIIO_string_view_t str);
#define OIIO_ColorConfig_getColorSpaceFromFilepath OpenImageIO_v2_3_6__ColorConfig_getColorSpaceFromFilepath


/** Given a string (like a filename), look for the longest, right-most
colorspace substring that appears. Returns "" if no such color space
is found. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_parseColorSpaceFromString(
    OIIO_ColorConfig_t const * this_
    , OIIO_string_view_t * return_
    , OIIO_string_view_t str);
#define OIIO_ColorConfig_parseColorSpaceFromString OpenImageIO_v2_3_6__ColorConfig_parseColorSpaceFromString


/** Return a filename or other identifier for the config we're using. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_configname(
    OIIO_ColorConfig_t const * this_
    , std_string_t * * return_);
#define OIIO_ColorConfig_configname OpenImageIO_v2_3_6__ColorConfig_configname


/** Return if OpenImageIO was built with OCIO support */
unsigned int OpenImageIO_v2_3_6__ColorConfig_supportsOpenColorIO(
    _Bool * return_);
#define OIIO_ColorConfig_supportsOpenColorIO OpenImageIO_v2_3_6__ColorConfig_supportsOpenColorIO


/** Return the hex OCIO version (maj<<24 + min<<16 + patch), or 0 if no
OCIO support is available. */
unsigned int OpenImageIO_v2_3_6__ColorConfig_OpenColorIO_version_hex(
    int * return_);
#define OIIO_ColorConfig_OpenColorIO_version_hex OpenImageIO_v2_3_6__ColorConfig_OpenColorIO_version_hex


#ifdef __cplusplus
}
#endif
