#pragma once
#include <c-std_string.h>
#include <c-string_view.h>
#include <c-typedesc.h>
#include <c-ustring.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenImageIO_v2_3_6__ImageCache_t_s OpenImageIO_v2_3_6__ImageCache_t;
typedef OpenImageIO_v2_3_6__ImageCache_t OIIO_ImageCache_t;
typedef struct std__string_t_s std__string_t;
typedef std__string_t std_string_t;
typedef struct Imath_3_2__Vec3_float__t_s Imath_3_2__Vec3_float__t;
typedef Imath_3_2__Vec3_float__t Imath_V3f_t;
typedef struct OpenImageIO_v2_3_6__ImageSpec_t_s OpenImageIO_v2_3_6__ImageSpec_t;
typedef OpenImageIO_v2_3_6__ImageSpec_t OIIO_ImageSpec_t;

/** Wrap mode describes what happens when texture coordinates describe
a value outside the usual [0,1] range where a texture is defined. */
enum OpenImageIO_v2_3_6__TextureOpt__Wrap_e {
    OIIO_TextureOpt_Wrap_WrapDefault = 0,
    OIIO_TextureOpt_Wrap_WrapBlack = 1,
    OIIO_TextureOpt_Wrap_WrapClamp = 2,
    OIIO_TextureOpt_Wrap_WrapPeriodic = 3,
    OIIO_TextureOpt_Wrap_WrapMirror = 4,
    OIIO_TextureOpt_Wrap_WrapPeriodicPow2 = 5,
    OIIO_TextureOpt_Wrap_WrapPeriodicSharedBorder = 6,
    OIIO_TextureOpt_Wrap_WrapLast = 7,
};
typedef unsigned int OIIO_TextureOpt_Wrap;
/** Mip mode determines if/how we use mipmaps */
enum OpenImageIO_v2_3_6__TextureOpt__MipMode_e {
    OIIO_TextureOpt_MipMode_MipModeDefault = 0,
    OIIO_TextureOpt_MipMode_MipModeNoMIP = 1,
    OIIO_TextureOpt_MipMode_MipModeOneLevel = 2,
    OIIO_TextureOpt_MipMode_MipModeTrilinear = 3,
    OIIO_TextureOpt_MipMode_MipModeAniso = 4,
};
typedef unsigned int OIIO_TextureOpt_MipMode;
/** Interp mode determines how we sample within a mipmap level */
enum OpenImageIO_v2_3_6__TextureOpt__InterpMode_e {
    OIIO_TextureOpt_InterpMode_InterpClosest = 0,
    OIIO_TextureOpt_InterpMode_InterpBilinear = 1,
    OIIO_TextureOpt_InterpMode_InterpBicubic = 2,
    OIIO_TextureOpt_InterpMode_InterpSmartBicubic = 3,
};
typedef unsigned int OIIO_TextureOpt_InterpMode;
enum OpenImageIO_v2_3_6__pvt__TexFormat_e {
    OIIO_pvt_TexFormat_TexFormatUnknown = 0,
    OIIO_pvt_TexFormat_TexFormatTexture = 1,
    OIIO_pvt_TexFormat_TexFormatTexture3d = 2,
    OIIO_pvt_TexFormat_TexFormatShadow = 3,
    OIIO_pvt_TexFormat_TexFormatCubeFaceShadow = 4,
    OIIO_pvt_TexFormat_TexFormatVolumeShadow = 5,
    OIIO_pvt_TexFormat_TexFormatLatLongEnv = 6,
    OIIO_pvt_TexFormat_TexFormatCubeFaceEnv = 7,
    OIIO_pvt_TexFormat_TexFormatLast = 8,
};
typedef unsigned int OIIO_pvt_TexFormat;
enum OpenImageIO_v2_3_6__pvt__EnvLayout_e {
    OIIO_pvt_EnvLayout_LayoutTexture = 0,
    OIIO_pvt_EnvLayout_LayoutLatLong = 1,
    OIIO_pvt_EnvLayout_LayoutCubeThreeByTwo = 2,
    OIIO_pvt_EnvLayout_LayoutCubeOneBySix = 3,
    OIIO_pvt_EnvLayout_EnvLayoutLast = 4,
};
typedef unsigned int OIIO_pvt_EnvLayout;
/** Wrap mode describes what happens when texture coordinates describe
a value outside the usual [0,1] range where a texture is defined. */
enum OpenImageIO_v2_3_6__Tex__Wrap_e {
    OIIO_Tex_Wrap_Default = 0,
    OIIO_Tex_Wrap_Black = 1,
    OIIO_Tex_Wrap_Clamp = 2,
    OIIO_Tex_Wrap_Periodic = 3,
    OIIO_Tex_Wrap_Mirror = 4,
    OIIO_Tex_Wrap_PeriodicPow2 = 5,
    OIIO_Tex_Wrap_PeriodicSharedBorder = 6,
    OIIO_Tex_Wrap_Last = 7,
};
typedef unsigned int OIIO_Tex_Wrap;
/** Mip mode determines if/how we use mipmaps */
enum OpenImageIO_v2_3_6__Tex__MipMode_e {
    OIIO_Tex_MipMode_Default = 0,
    OIIO_Tex_MipMode_NoMIP = 1,
    OIIO_Tex_MipMode_OneLevel = 2,
    OIIO_Tex_MipMode_Trilinear = 3,
    OIIO_Tex_MipMode_Aniso = 4,
};
typedef unsigned int OIIO_Tex_MipMode;
/** Interp mode determines how we sample within a mipmap level */
enum OpenImageIO_v2_3_6__Tex__InterpMode_e {
    OIIO_Tex_InterpMode_Closest = 0,
    OIIO_Tex_InterpMode_Bilinear = 1,
    OIIO_Tex_InterpMode_Bicubic = 2,
    OIIO_Tex_InterpMode_SmartBicubic = 3,
};
typedef unsigned int OIIO_Tex_InterpMode;
/** Pre-defined values for Runflag's. */
enum OpenImageIO_v2_3_6__RunFlagVal_e {
    OIIO_RunFlagVal_RunFlagOff = 0,
    OIIO_RunFlagVal_RunFlagOn = 255,
};
typedef unsigned int OIIO_RunFlagVal;

/** TextureOpt is a structure that holds many options controlling
single-point texture lookups.  Because each texture lookup API call
takes a reference to a TextureOpt, the call signatures remain
uncluttered rather than having an ever-growing list of parameters, most
of which will never vary from their defaults. */
typedef struct OpenImageIO_v2_3_6__TextureOpt_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__TextureOpt_t;
typedef OpenImageIO_v2_3_6__TextureOpt_t OIIO_TextureOpt_t;

/** Texture options for a batch of Tex::BatchWidth points and run mask. */
typedef struct OpenImageIO_v2_3_6__TextureOptBatch_t_s {
    char _unused;
} __attribute__((aligned(64))) OpenImageIO_v2_3_6__TextureOptBatch_t;
typedef OpenImageIO_v2_3_6__TextureOptBatch_t OIIO_TextureOptBatch_t;

/** Define an API to an abstract class that that manages texture files,
caches of open file handles as well as tiles of texels so that truly
huge amounts of texture may be accessed by an application with low
memory footprint, and ways to perform antialiased texture, shadow
map, and environment map lookups. */
typedef struct OpenImageIO_v2_3_6__TextureSystem_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__TextureSystem_t;
typedef OpenImageIO_v2_3_6__TextureSystem_t OIIO_TextureSystem_t;

/** Define an opaque data type that allows us to have a pointer to
certain per-thread information that the TextureSystem maintains. Any
given one of these should NEVER be shared between running threads. */
typedef struct OpenImageIO_v2_3_6__TextureSystem__Perthread_t_s OpenImageIO_v2_3_6__TextureSystem__Perthread_t;
typedef OpenImageIO_v2_3_6__TextureSystem__Perthread_t OIIO_TextureSystem_Perthread_t;

/** Define an opaque data type that allows us to have a handle to a
texture (already having its name resolved) but without exposing
any internals. */
typedef struct OpenImageIO_v2_3_6__TextureSystem__TextureHandle_t_s OpenImageIO_v2_3_6__TextureSystem__TextureHandle_t;
typedef OpenImageIO_v2_3_6__TextureSystem__TextureHandle_t OIIO_TextureSystem_TextureHandle_t;


/** Create a TextureOpt with all fields initialized to reasonable
defaults. */
unsigned int OpenImageIO_v2_3_6__TextureOpt_ctor(
    OIIO_TextureOpt_t * * this_);
#define OIIO_TextureOpt_ctor OpenImageIO_v2_3_6__TextureOpt_ctor


/** Utility: Return the Wrap enum corresponding to a wrap name:
"default", "black", "clamp", "periodic", "mirror". */
unsigned int OpenImageIO_v2_3_6__TextureOpt_decode_wrapmode(
    OIIO_TextureOpt_Wrap * return_
    , char const * name);
#define OIIO_TextureOpt_decode_wrapmode OpenImageIO_v2_3_6__TextureOpt_decode_wrapmode


unsigned int OpenImageIO_v2_3_6__TextureOpt_decode_wrapmode_ustring(
    OIIO_TextureOpt_Wrap * return_
    , OIIO_ustring_t name);
#define OIIO_TextureOpt_decode_wrapmode_ustring OpenImageIO_v2_3_6__TextureOpt_decode_wrapmode_ustring


/** Utility: Parse a single wrap mode (e.g., "periodic") or a
comma-separated wrap modes string (e.g., "black,clamp") into
separate Wrap enums for s and t. */
unsigned int OpenImageIO_v2_3_6__TextureOpt_parse_wrapmodes(
    char const * wrapmodes
    , OIIO_TextureOpt_Wrap * swrapcode
    , OIIO_TextureOpt_Wrap * twrapcode);
#define OIIO_TextureOpt_parse_wrapmodes OpenImageIO_v2_3_6__TextureOpt_parse_wrapmodes


unsigned int OpenImageIO_v2_3_6__TextureOpt_copy(
    OIIO_TextureOpt_t * * this_
    , OIIO_TextureOpt_t const * rhs);
#define OIIO_TextureOpt_copy OpenImageIO_v2_3_6__TextureOpt_copy


unsigned int OpenImageIO_v2_3_6__TextureOpt__assign(
    OIIO_TextureOpt_t * this_
    , OIIO_TextureOpt_t * * return_
    , OIIO_TextureOpt_t const * rhs);
#define OIIO_TextureOpt__assign OpenImageIO_v2_3_6__TextureOpt__assign


unsigned int OpenImageIO_v2_3_6__TextureOpt_dtor(
    OIIO_TextureOpt_t * this_);
#define OIIO_TextureOpt_dtor OpenImageIO_v2_3_6__TextureOpt_dtor


/** Create a TextureOptBatch with all fields initialized to reasonable
defaults. */
unsigned int OpenImageIO_v2_3_6__TextureOptBatch_ctor(
    OIIO_TextureOptBatch_t * * this_);
#define OIIO_TextureOptBatch_ctor OpenImageIO_v2_3_6__TextureOptBatch_ctor


unsigned int OpenImageIO_v2_3_6__TextureOptBatch_copy(
    OIIO_TextureOptBatch_t * * this_
    , OIIO_TextureOptBatch_t const * rhs);
#define OIIO_TextureOptBatch_copy OpenImageIO_v2_3_6__TextureOptBatch_copy


unsigned int OpenImageIO_v2_3_6__TextureOptBatch__assign(
    OIIO_TextureOptBatch_t * this_
    , OIIO_TextureOptBatch_t * * return_
    , OIIO_TextureOptBatch_t const * rhs);
#define OIIO_TextureOptBatch__assign OpenImageIO_v2_3_6__TextureOptBatch__assign


unsigned int OpenImageIO_v2_3_6__TextureOptBatch_dtor(
    OIIO_TextureOptBatch_t * this_);
#define OIIO_TextureOptBatch_dtor OpenImageIO_v2_3_6__TextureOptBatch_dtor


/** Create a TextureSystem and return a pointer to it.  This should only
be freed by passing it to TextureSystem::destroy()!

@param  shared
    If `shared` is `true`, the pointer returned will be a shared
    TextureSystem, (so that multiple parts of an application that
    request a TextureSystem will all end up with the same one, and
    the same underlying ImageCache). If `shared` is `false`, a
    completely unique TextureCache will be created and returned.

@param  imagecache
    If `shared` is `false` and `imagecache` is not `nullptr`, the
    TextureSystem will use this as its underlying ImageCache. In
    that case, it is the caller who is responsible for eventually
    freeing the ImageCache after the TextureSystem is destroyed.  If
    `shared` is `false` and `imagecache` is `nullptr`, then a custom
    ImageCache will be created, owned by the TextureSystem, and
    automatically freed when the TS destroys.

@returns
    A raw pointer to a TextureSystem, which can only be freed with
    `TextureSystem::destroy()`.

@see    TextureSystem::destroy */
unsigned int OpenImageIO_v2_3_6__TextureSystem_create(
    OIIO_TextureSystem_t * * return_
    , _Bool shared
    , OIIO_ImageCache_t * imagecache);
#define OIIO_TextureSystem_create OpenImageIO_v2_3_6__TextureSystem_create


/** Destroy an allocated TextureSystem, including freeing all system
resources that it holds.

It is safe to destroy even a shared TextureSystem, as the
implementation of `destroy()` will recognize a shared one and only
truly release its resources if it has been requested to be destroyed
as many times as shared TextureSystem's were created.

@param  ts
    Raw pointer to the TextureSystem to destroy.

@param  teardown_imagecache
    For a shared TextureSystem, if the `teardown_imagecache`
    parameter is `true`, it will try to truly destroy the shared
    cache if nobody else is still holding a reference (otherwise, it
    will leave it intact). This parameter has no effect if `ts` was
    not the single globally shared TextureSystem. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_destroy(
    OIIO_TextureSystem_t * ts
    , _Bool teardown_imagecache);
#define OIIO_TextureSystem_destroy OpenImageIO_v2_3_6__TextureSystem_destroy


/** Set a named attribute (i.e., a property or option) of the
TextureSystem.

Example:

    TextureSystem *ts;
    ...
    int maxfiles = 50;
    ts->attribute ("max_open_files", TypeDesc::INT, &maxfiles);

    const char *path = "/my/path";
    ts->attribute ("searchpath", TypeDesc::STRING, &path);

    // There are specialized versions for retrieving a single int,
    // float, or string without needing types or pointers:
    ts->getattribute ("max_open_files", 50);
    ic->attribute ("max_memory_MB", 4000.0f);
    ic->attribute ("searchpath", "/my/path");

Note: When passing a string, you need to pass a pointer to the
`char*`, not a pointer to the first character.  (Rationale: for an
`int` attribute, you pass the address of the `int`.  So for a
string, which is a `char*`, you need to pass the address of the
string, i.e., a `char**`).

@param  name    Name of the attribute to set.
@param  type    TypeDesc describing the type of the attribute.
@param  val     Pointer to the value data.
@returns        `true` if the name and type were recognized and the
                attribute was set, or `false` upon failure
                (including it being an unrecognized attribute or not
                of the correct type). */
unsigned int OpenImageIO_v2_3_6__TextureSystem_attribute(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void const * val);
#define OIIO_TextureSystem_attribute OpenImageIO_v2_3_6__TextureSystem_attribute


/** Specialized `attribute()` for setting a single `int` value. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_attribute_int(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , int val);
#define OIIO_TextureSystem_attribute_int OpenImageIO_v2_3_6__TextureSystem_attribute_int


/** Specialized `attribute()` for setting a single `float` value. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_attribute_float(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , float val);
#define OIIO_TextureSystem_attribute_float OpenImageIO_v2_3_6__TextureSystem_attribute_float


unsigned int OpenImageIO_v2_3_6__TextureSystem_attribute_double(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , double val);
#define OIIO_TextureSystem_attribute_double OpenImageIO_v2_3_6__TextureSystem_attribute_double


/** Specialized `attribute()` for setting a single string value. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_attribute_string(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_string_view_t val);
#define OIIO_TextureSystem_attribute_string OpenImageIO_v2_3_6__TextureSystem_attribute_string


/** Get the named attribute of the texture system, store it in `*val`.
All of the attributes that may be set with the `attribute() call`
may also be queried with `getattribute()`.

Examples:

    TextureSystem *ic;
    ...
    int maxfiles;
    ts->getattribute ("max_open_files", TypeDesc::INT, &maxfiles);

    const char *path;
    ts->getattribute ("searchpath", TypeDesc::STRING, &path);

    // There are specialized versions for retrieving a single int,
    // float, or string without needing types or pointers:
    int maxfiles;
    ts->getattribute ("max_open_files", maxfiles);
    const char *path;
    ts->getattribute ("searchpath", &path);

Note: When retrieving a string, you need to pass a pointer to the
`char*`, not a pointer to the first character. Also, the `char*`
will end up pointing to characters owned by the ImageCache; the
caller does not need to ever free the memory that contains the
characters.

@param  name    Name of the attribute to retrieve.
@param  type    TypeDesc describing the type of the attribute.
@param  val     Pointer where the attribute value should be stored.
@returns        `true` if the name and type were recognized and the
                attribute was retrieved, or `false` upon failure
                (including it being an unrecognized attribute or not
                of the correct type). */
unsigned int OpenImageIO_v2_3_6__TextureSystem_getattribute(
    OIIO_TextureSystem_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void * val);
#define OIIO_TextureSystem_getattribute OpenImageIO_v2_3_6__TextureSystem_getattribute


/** Specialized `attribute()` for retrieving a single `int` value. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_getattribute_int(
    OIIO_TextureSystem_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , int * val);
#define OIIO_TextureSystem_getattribute_int OpenImageIO_v2_3_6__TextureSystem_getattribute_int


/** Specialized `attribute()` for retrieving a single `float` value. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_getattribute_float(
    OIIO_TextureSystem_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , float * val);
#define OIIO_TextureSystem_getattribute_float OpenImageIO_v2_3_6__TextureSystem_getattribute_float


unsigned int OpenImageIO_v2_3_6__TextureSystem_getattribute_double(
    OIIO_TextureSystem_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , double * val);
#define OIIO_TextureSystem_getattribute_double OpenImageIO_v2_3_6__TextureSystem_getattribute_double


/** Specialized `attribute()` for retrieving a single `string` value
as a `char*`. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_getattribute_cstr(
    OIIO_TextureSystem_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , char * * val);
#define OIIO_TextureSystem_getattribute_cstr OpenImageIO_v2_3_6__TextureSystem_getattribute_cstr


/** Specialized `attribute()` for retrieving a single `string` value
as a `std::string`. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_getattribute_string(
    OIIO_TextureSystem_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , std_string_t * val);
#define OIIO_TextureSystem_getattribute_string OpenImageIO_v2_3_6__TextureSystem_getattribute_string


/** Retrieve a Perthread, unique to the calling thread. This is a
thread-specific pointer that will always return the Perthread for a
thread, which will also be automatically destroyed when the thread
terminates.

Applications that want to manage their own Perthread pointers (with
`create_thread_info` and `destroy_thread_info`) should still call
this, but passing in their managed pointer. If the passed-in
thread_info is not nullptr, it won't create a new one or retrieve a
TSP, but it will do other necessary housekeeping on the Perthread
information. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_get_perthread_info(
    OIIO_TextureSystem_t * this_
    , OIIO_TextureSystem_Perthread_t * * return_
    , OIIO_TextureSystem_Perthread_t * thread_info);
#define OIIO_TextureSystem_get_perthread_info OpenImageIO_v2_3_6__TextureSystem_get_perthread_info


/** Create a new Perthread. It is the caller's responsibility to
eventually destroy it using `destroy_thread_info()`. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_create_thread_info(
    OIIO_TextureSystem_t * this_
    , OIIO_TextureSystem_Perthread_t * * return_);
#define OIIO_TextureSystem_create_thread_info OpenImageIO_v2_3_6__TextureSystem_create_thread_info


/** Destroy a Perthread that was allocated by `create_thread_info()`. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_destroy_thread_info(
    OIIO_TextureSystem_t * this_
    , OIIO_TextureSystem_Perthread_t * threadinfo);
#define OIIO_TextureSystem_destroy_thread_info OpenImageIO_v2_3_6__TextureSystem_destroy_thread_info


/** Retrieve an opaque handle for fast texture lookups.  The opaque
pointer `thread_info` is thread-specific information returned by
`get_perthread_info()`.  Return nullptr if something has gone
horribly wrong. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_get_texture_handle(
    OIIO_TextureSystem_t * this_
    , OIIO_TextureSystem_TextureHandle_t * * return_
    , OIIO_ustring_t filename
    , OIIO_TextureSystem_Perthread_t * thread_info);
#define OIIO_TextureSystem_get_texture_handle OpenImageIO_v2_3_6__TextureSystem_get_texture_handle


/** Return true if the texture handle (previously returned by
`get_image_handle()`) is a valid texture that can be subsequently
read. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_good(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle);
#define OIIO_TextureSystem_good OpenImageIO_v2_3_6__TextureSystem_good


/** Perform a filtered 2D texture lookup on a position centered at 2D
coordinates (`s`, `t`) from the texture identified by `filename`,
and using relevant texture `options`.  The `nchannels` parameter
determines the number of channels to retrieve (e.g., 1 for a single
value, 3 for an RGB triple, etc.). The filtered results will be
stored in `result[0..nchannels-1]`.

We assume that this lookup will be part of an image that has pixel
coordinates `x` and `y`.  By knowing how `s` and `t` change from
pixel to pixel in the final image, we can properly *filter* or
antialias the texture lookups.  This information is given via
derivatives `dsdx` and `dtdx` that define the change in `s` and `t`
per unit of `x`, and `dsdy` and `dtdy` that define the change in `s`
and `t` per unit of `y`.  If it is impossible to know the
derivatives, you may pass 0 for them, but in that case you will not
receive an antialiased texture lookup.

@param  filename
            The name of the texture.
@param  options
    Fields within `options` that are honored for 2D texture lookups
    include the following:
    - `int firstchannel` :
            The index of the first channel to look up from the texture.
    - `int subimage / ustring subimagename` :
            The subimage or face within the file, specified by
            either by name (if non-empty) or index. This will be
            ignored if the file does not have multiple subimages or
            separate per-face textures.
    - `Wrap swrap, twrap` :
            Specify the *wrap mode* for each direction, one of:
            `WrapBlack`, `WrapClamp`, `WrapPeriodic`, `WrapMirror`,
            or `WrapDefault`.
    - `float swidth, twidth` :
            For each direction, gives a multiplier for the derivatives.
    - `float sblur, tblur` :
            For each direction, specifies an additional amount of
            pre-blur to apply to the texture (*after* derivatives
            are taken into account), expressed as a portion of the
            width of the texture.
    - `float fill` :
            Specifies the value that will be used for any color
            channels that are requested but not found in the file.
            For example, if you perform a 4-channel lookup on a
            3-channel texture, the last channel will get the fill
            value.  (Note: this behavior is affected by the
            `"gray_to_rgb"` TextureSystem attribute.
    - `const float *missingcolor` :
            If not `nullptr`, specifies the color that will be
            returned for missing or broken textures (rather than
            being an error).
@param  s/t
            The 2D texture coordinates.
@param  dsdx,dtdx,dsdy,dtdy
            The differentials of s and t relative to canonical
            directions x and y.  The choice of x and y are not
            important to the implementation; it can be any imposed
            2D coordinates, such as pixels in screen space, adjacent
            samples in parameter space on a surface, etc. The st
            derivatives determine the size and shape of the
            ellipsoid over which the texture lookup is filtered.
@param  nchannels
            The number of channels of data to retrieve into `result`
            (e.g., 1 for a single value, 3 for an RGB triple, etc.).
@param  result[]
            The result of the filtered texture lookup will be placed
            into `result[0..nchannels-1]`.
@param  dresultds/dresultdt
            If non-null, these designate storage locations for the
            derivatives of result, i.e., the rate of change per unit
            s and t, respectively, of the filtered texture. If
            supplied, they must allow for `nchannels` of storage.
@returns
            `true` upon success, or `false` if the file was not
            found or could not be opened by any available ImageIO
            plugin. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_texture(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOpt_t * options
    , float s
    , float t
    , float dsdx
    , float dtdx
    , float dsdy
    , float dtdy
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt);
#define OIIO_TextureSystem_texture OpenImageIO_v2_3_6__TextureSystem_texture


/** Slightly faster version of texture() lookup if the app already has a
texture handle and per-thread info. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_texture_handle(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOpt_t * options
    , float s
    , float t
    , float dsdx
    , float dtdx
    , float dsdy
    , float dtdy
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt);
#define OIIO_TextureSystem_texture_handle OpenImageIO_v2_3_6__TextureSystem_texture_handle


/** Perform a filtered 3D volumetric texture lookup on a position
centered at 3D position `P` (with given differentials) from the
texture identified by `filename`, and using relevant texture
`options`.  The filtered results will be stored in
`result[0..nchannels-1]`.

The `P` coordinate and `dPdx`, `dPdy`, and `dPdz` derivatives are
assumed to be in some kind of common global coordinate system
(usually "world" space) and will be automatically transformed into
volume local coordinates, if such a transformation is specified in
the volume file itself.

@param  filename
            The name of the texture.
@param  options
    Fields within `options` that are honored for 3D texture lookups
    include the following:
    - `int firstchannel` :
            The index of the first channel to look up from the texture.
    - `int subimage / ustring subimagename` :
            The subimage or field within the volume, specified by
            either by name (if non-empty) or index. This will be
            ignored if the file does not have multiple subimages or
            separate per-face textures.
    - `Wrap swrap, twrap, rwrap` :
            Specify the *wrap mode* for each direction, one of:
            `WrapBlack`, `WrapClamp`, `WrapPeriodic`, `WrapMirror`,
            or `WrapDefault`.
    - `float swidth, twidth, rwidth` :
            For each direction, gives a multiplier for the derivatives.
    - `float sblur, tblur, rblur` :
            For each direction, specifies an additional amount of
            pre-blur to apply to the texture (*after* derivatives
            are taken into account), expressed as a portion of the
            width of the texture.
    - `float fill` :
            Specifies the value that will be used for any color
            channels that are requested but not found in the file.
            For example, if you perform a 4-channel lookup on a
            3-channel texture, the last channel will get the fill
            value.  (Note: this behavior is affected by the
            `"gray_to_rgb"` TextureSystem attribute.
    - `const float *missingcolor` :
            If not `nullptr`, specifies the color that will be
            returned for missing or broken textures (rather than
            being an error).
    - `float time` :
            A time value to use if the volume texture specifies a
            time-varying local transformation (default: 0).
@param  P
            The 2D texture coordinates.
@param  dPdx/dPdy/dPdz
            The differentials of `P`. We assume that this lookup
            will be part of an image that has pixel coordinates `x`
            and `y` and depth `z`. By knowing how `P` changes from
            pixel to pixel in the final image, and as we step in *z*
            depth, we can properly *filter* or antialias the texture
            lookups.  This information is given via derivatives
            `dPdx`, `dPdy`, and `dPdz` that define the changes in
            `P` per unit of `x`, `y`, and `z`, respectively.  If it
            is impossible to know the derivatives, you may pass 0
            for them, but in that case you will not receive an
            antialiased texture lookup.
@param  nchannels
            The number of channels of data to retrieve into `result`
            (e.g., 1 for a single value, 3 for an RGB triple, etc.).
@param  result[]
            The result of the filtered texture lookup will be placed
            into `result[0..nchannels-1]`.
@param  dresultds/dresultdt/dresultdr
            If non-null, these designate storage locations for the
            derivatives of result, i.e., the rate of change per unit
            s, t, and r, respectively, of the filtered texture. If
            supplied, they must allow for `nchannels` of storage.
@returns
            `true` upon success, or `false` if the file was not
            found or could not be opened by any available ImageIO
            plugin. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_texture3d(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOpt_t * options
    , Imath_V3f_t const * P
    , Imath_V3f_t const * dPdx
    , Imath_V3f_t const * dPdy
    , Imath_V3f_t const * dPdz
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt
    , float * dresultdr);
#define OIIO_TextureSystem_texture3d OpenImageIO_v2_3_6__TextureSystem_texture3d


/** Slightly faster version of texture3d() lookup if the app already has
a texture handle and per-thread info. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_texture3d_handle(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOpt_t * options
    , Imath_V3f_t const * P
    , Imath_V3f_t const * dPdx
    , Imath_V3f_t const * dPdy
    , Imath_V3f_t const * dPdz
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt
    , float * dresultdr);
#define OIIO_TextureSystem_texture3d_handle OpenImageIO_v2_3_6__TextureSystem_texture3d_handle


unsigned int OpenImageIO_v2_3_6__TextureSystem_shadow(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOpt_t * options
    , Imath_V3f_t const * P
    , Imath_V3f_t const * dPdx
    , Imath_V3f_t const * dPdy
    , float * result
    , float * dresultds
    , float * dresultdt);
#define OIIO_TextureSystem_shadow OpenImageIO_v2_3_6__TextureSystem_shadow


unsigned int OpenImageIO_v2_3_6__TextureSystem_shadow_handle(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOpt_t * options
    , Imath_V3f_t const * P
    , Imath_V3f_t const * dPdx
    , Imath_V3f_t const * dPdy
    , float * result
    , float * dresultds
    , float * dresultdt);
#define OIIO_TextureSystem_shadow_handle OpenImageIO_v2_3_6__TextureSystem_shadow_handle


/** Perform a filtered directional environment map lookup in the
direction of vector `R`, from the texture identified by `filename`,
and using relevant texture `options`.  The filtered results will be
stored in `result[]`.

@param  filename
            The name of the texture.
@param  options
    Fields within `options` that are honored for environment lookups
    include the following:
    - `int firstchannel` :
            The index of the first channel to look up from the texture.
    - `int subimage / ustring subimagename` :
            The subimage or face within the file, specified by
            either by name (if non-empty) or index. This will be
            ignored if the file does not have multiple subimages or
            separate per-face textures.
    - `float swidth, twidth` :
            For each direction, gives a multiplier for the
            derivatives.
    - `float sblur, tblur` :
            For each direction, specifies an additional amount of
            pre-blur to apply to the texture (*after* derivatives
            are taken into account), expressed as a portion of the
            width of the texture.
    - `float fill` :
            Specifies the value that will be used for any color
            channels that are requested but not found in the file.
            For example, if you perform a 4-channel lookup on a
            3-channel texture, the last channel will get the fill
            value.  (Note: this behavior is affected by the
            `"gray_to_rgb"` TextureSystem attribute.
    - `const float *missingcolor` :
            If not `nullptr`, specifies the color that will be
            returned for missing or broken textures (rather than
            being an error).
@param  R
            The direction vector to look up.
@param  dRdx/dRdy
            The differentials of `R` with respect to image
            coordinates x and y.
@param  nchannels
            The number of channels of data to retrieve into `result`
            (e.g., 1 for a single value, 3 for an RGB triple, etc.).
@param  result[]
            The result of the filtered texture lookup will be placed
            into `result[0..nchannels-1]`.
@param  dresultds/dresultdt
            If non-null, these designate storage locations for the
            derivatives of result, i.e., the rate of change per unit
            s and t, respectively, of the filtered texture. If
            supplied, they must allow for `nchannels` of storage.
@returns
            `true` upon success, or `false` if the file was not
            found or could not be opened by any available ImageIO
            plugin. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_environment(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOpt_t * options
    , Imath_V3f_t const * R
    , Imath_V3f_t const * dRdx
    , Imath_V3f_t const * dRdy
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt);
#define OIIO_TextureSystem_environment OpenImageIO_v2_3_6__TextureSystem_environment


/** Slightly faster version of environment() if the app already has a
texture handle and per-thread info. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_environment_handle(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOpt_t * options
    , Imath_V3f_t const * R
    , Imath_V3f_t const * dRdx
    , Imath_V3f_t const * dRdy
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt);
#define OIIO_TextureSystem_environment_handle OpenImageIO_v2_3_6__TextureSystem_environment_handle


/** Perform filtered 2D texture lookups on a batch of positions from the
same texture, all at once.  The parameters `s`, `t`, `dsdx`, `dtdx`,
and `dsdy`, `dtdy` are each a pointer to `[BatchWidth]` values.  The
`mask` determines which of those array elements to actually compute.

The float* results act like `float[nchannels][BatchWidth]`, so that
effectively `result[0..BatchWidth-1]` are the "red" result for each
lane, `result[BatchWidth..2*BatchWidth-1]` are the "green" results,
etc. The `dresultds` and `dresultdt` should either both be provided,
or else both be nullptr (meaning no derivative results are
required).

@param  filename
            The name of the texture.
@param  options
            A TextureOptBatch containing texture lookup options.
            This is conceptually the same as a TextureOpt, but the
            following fields are arrays of `[BatchWidth]` elements:
            sblur, tblur, swidth, twidth. The other fields are, as
            with TextureOpt, ordinary scalar values.
@param  mask
            A bit-field designating which "lanes" should be
            computed: if `mask & (1<<i)` is nonzero, then results
            should be computed and stored for `result[...][i]`.
@param  s/t
            Pointers to the 2D texture coordinates, each as a
            `float[BatchWidth]`.
@param  dsdx/dtdx/dsdy/dtdy
            The differentials of s and t relative to canonical
            directions x and y, each as a `float[BatchWidth]`.
@param  nchannels
            The number of channels of data to retrieve into `result`
            (e.g., 1 for a single value, 3 for an RGB triple, etc.).
@param  result[]
            The result of the filtered texture lookup will be placed
            here, as `float [nchannels][BatchWidth]`. (Note the
            "SOA" data layout.)
@param  dresultds/dresultdt
            If non-null, these designate storage locations for the
            derivatives of result, and like `result` are in SOA
            layout: `float [nchannels][BatchWidth]`
@returns
            `true` upon success, or `false` if the file was not
            found or could not be opened by any available ImageIO
            plugin. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_texture_batch(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOptBatch_t * options
    , unsigned long mask
    , float const * s
    , float const * t
    , float const * dsdx
    , float const * dtdx
    , float const * dsdy
    , float const * dtdy
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt);
#define OIIO_TextureSystem_texture_batch OpenImageIO_v2_3_6__TextureSystem_texture_batch


/** Slightly faster version of texture() lookup if the app already has a
texture handle and per-thread info. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_texture_handle_batch(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOptBatch_t * options
    , unsigned long mask
    , float const * s
    , float const * t
    , float const * dsdx
    , float const * dtdx
    , float const * dsdy
    , float const * dtdy
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt);
#define OIIO_TextureSystem_texture_handle_batch OpenImageIO_v2_3_6__TextureSystem_texture_handle_batch


/** Perform filtered 3D volumetric texture lookups on a batch of
positions from the same texture, all at once. The "point-like"
parameters `P`, `dPdx`, `dPdy`, and `dPdz` are each a pointers to
arrays of `float value[3][BatchWidth]` (or alternately like
`Imath::Vec3<FloatWide>`). That is, each one points to all the *x*
values for the batch, immediately followed by all the *y* values,
followed by the *z* values. The `mask` determines which of those
array elements to actually compute.

The various results arrays are also arranged as arrays that behave
as if they were declared `float result[channels][BatchWidth]`, where
all the batch values for channel 0 are adjacent, followed by all the
batch values for channel 1, etc.

@param  filename
            The name of the texture.
@param  options
            A TextureOptBatch containing texture lookup options.
            This is conceptually the same as a TextureOpt, but the
            following fields are arrays of `[BatchWidth]` elements:
            sblur, tblur, swidth, twidth. The other fields are, as
            with TextureOpt, ordinary scalar values.
@param  mask
            A bit-field designating which "lanes" should be
            computed: if `mask & (1<<i)` is nonzero, then results
            should be computed and stored for `result[...][i]`.
@param  P
            Pointers to the 3D texture coordinates, each as a
            `float[3][BatchWidth]`.
@param  dPdx/dPdy/dPdz
            The differentials of P relative to canonical directions
            x, y, and z, each as a `float[3][BatchWidth]`.
@param  nchannels
            The number of channels of data to retrieve into `result`
            (e.g., 1 for a single value, 3 for an RGB triple, etc.).
@param  result[]
            The result of the filtered texture lookup will be placed
            here, as `float [nchannels][BatchWidth]`. (Note the
            "SOA" data layout.)
@param  dresultds/dresultdt/dresultdr
            If non-null, these designate storage locations for the
            derivatives of result, and like `result` are in SOA
            layout: `float [nchannels][BatchWidth]`
@returns
            `true` upon success, or `false` if the file was not
            found or could not be opened by any available ImageIO
            plugin. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_texture3d_batch(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOptBatch_t * options
    , unsigned long mask
    , float const * P
    , float const * dPdx
    , float const * dPdy
    , float const * dPdz
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt
    , float * dresultdr);
#define OIIO_TextureSystem_texture3d_batch OpenImageIO_v2_3_6__TextureSystem_texture3d_batch


/** Slightly faster version of texture3d() lookup if the app already
has a texture handle and per-thread info. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_texture3d_handle_batch(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOptBatch_t * options
    , unsigned long mask
    , float const * P
    , float const * dPdx
    , float const * dPdy
    , float const * dPdz
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt
    , float * dresultdr);
#define OIIO_TextureSystem_texture3d_handle_batch OpenImageIO_v2_3_6__TextureSystem_texture3d_handle_batch


/** Perform filtered directional environment map lookups on a batch of
directions from the same texture, all at once. The "point-like"
parameters `R`, `dRdx`, and `dRdy` are each a pointers to arrays of
`float value[3][BatchWidth]` (or alternately like
`Imath::Vec3<FloatWide>`). That is, each one points to all the *x*
values for the batch, immediately followed by all the *y* values,
followed by the *z* values. The `mask` determines which of those
array elements to actually compute.

The various results arrays are also arranged as arrays that behave
as if they were declared `float result[channels][BatchWidth]`, where
all the batch values for channel 0 are adjacent, followed by all the
batch values for channel 1, etc.

@param  filename
            The name of the texture.
@param  options
            A TextureOptBatch containing texture lookup options.
            This is conceptually the same as a TextureOpt, but the
            following fields are arrays of `[BatchWidth]` elements:
            sblur, tblur, swidth, twidth. The other fields are, as
            with TextureOpt, ordinary scalar values.
@param  mask
            A bit-field designating which "lanes" should be
            computed: if `mask & (1<<i)` is nonzero, then results
            should be computed and stored for `result[...][i]`.
@param  R
            Pointers to the 3D texture coordinates, each as a
            `float[3][BatchWidth]`.
@param  dRdx/dRdy
            The differentials of R relative to canonical directions
            x and y, each as a `float[3][BatchWidth]`.
@param  nchannels
            The number of channels of data to retrieve into `result`
            (e.g., 1 for a single value, 3 for an RGB triple, etc.).
@param  result[]
            The result of the filtered texture lookup will be placed
            here, as `float [nchannels][BatchWidth]`. (Note the
            "SOA" data layout.)
@param  dresultds/dresultdt
            If non-null, these designate storage locations for the
            derivatives of result, and like `result` are in SOA
            layout: `float [nchannels][BatchWidth]`
@returns
            `true` upon success, or `false` if the file was not
            found or could not be opened by any available ImageIO
            plugin. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_environment_batch(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOptBatch_t * options
    , unsigned long mask
    , float const * R
    , float const * dRdx
    , float const * dRdy
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt);
#define OIIO_TextureSystem_environment_batch OpenImageIO_v2_3_6__TextureSystem_environment_batch


/** Slightly faster version of environment() if the app already has a
texture handle and per-thread info. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_environment_handle_batch(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOptBatch_t * options
    , unsigned long mask
    , float const * R
    , float const * dRdx
    , float const * dRdy
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt);
#define OIIO_TextureSystem_environment_handle_batch OpenImageIO_v2_3_6__TextureSystem_environment_handle_batch


unsigned int OpenImageIO_v2_3_6__TextureSystem_shadow_batch(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOptBatch_t * options
    , unsigned long mask
    , float const * P
    , float const * dPdx
    , float const * dPdy
    , float * result
    , float * dresultds
    , float * dresultdt);
#define OIIO_TextureSystem_shadow_batch OpenImageIO_v2_3_6__TextureSystem_shadow_batch


unsigned int OpenImageIO_v2_3_6__TextureSystem_shadow_handle_batch(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOptBatch_t * options
    , unsigned long mask
    , float const * P
    , float const * dPdx
    , float const * dPdy
    , float * result
    , float * dresultds
    , float * dresultdt);
#define OIIO_TextureSystem_shadow_handle_batch OpenImageIO_v2_3_6__TextureSystem_shadow_handle_batch


/** Given possibly-relative 'filename', resolve it using the search
path rules and return the full resolved filename. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_resolve_filename(
    OIIO_TextureSystem_t const * this_
    , std_string_t * * return_
    , std_string_t const * filename);
#define OIIO_TextureSystem_resolve_filename OpenImageIO_v2_3_6__TextureSystem_resolve_filename


/** Get information or metadata about the named texture and store it in
`*data`.

Data names may include any of the following:

  - `exists` (int):
        Stores the value 1 if the file exists and is an image format
        that OpenImageIO can read, or 0 if the file does not exist,
        or could not be properly read as a texture. Note that unlike
        all other queries, this query will "succeed" (return `true`)
        even if the file does not exist.

  - `udim` (int) :
        Stores the value 1 if the file is a "virtual UDIM" or
        texture atlas file (as described in Section
        :ref:`sec-texturesys-udim`) or 0 otherwise.

  - `subimages` (int) :
        The number of subimages/faces in the file, as an integer.

  - `resolution` (int[2] or int[3]):
        The resolution of the texture file, if an array of 2
        integers (described as `TypeDesc(INT,2)`), or the 3D
        resolution of the texture file, which is an array of 3
        integers (described as `TypeDesc(INT,3)`)  The third value
        will be 1 unless it's a volumetric (3D) image.

  - `miplevels` (int) :
        The number of MIPmap levels for the specified
        subimage (an integer).

  - `texturetype` (string) :
        A string describing the type of texture of the given file,
        which describes how the texture may be used (also which
        texture API call is probably the right one for it). This
        currently may return one of: "unknown", "Plain Texture",
        "Volume Texture", "Shadow", or "Environment".

  - `textureformat` (string) :
        A string describing the format of the given file, which
        describes the kind of texture stored in the file. This
        currently may return one of: "unknown", "Plain Texture",
        "Volume Texture", "Shadow", "CubeFace Shadow", "Volume
        Shadow", "LatLong Environment", or "CubeFace Environment".
        Note that there are several kinds of shadows and environment
        maps, all accessible through the same API calls.

  - `channels` (int) :
        The number of color channels in the file.

  - `format` (int) :
        The native data format of the pixels in the file (an
        integer, giving the `TypeDesc::BASETYPE` of the data). Note
        that this is not necessarily the same as the data format
        stored in the image cache.

  - `cachedformat` (int) :
        The native data format of the pixels as stored in the image
        cache (an integer, giving the `TypeDesc::BASETYPE` of the
        data).  Note that this is not necessarily the same as the
        native data format of the file.

  - `datawindow` (int[4] or int[6]):
        Returns the pixel data window of the image, which is either
        an array of 4 integers (returning xmin, ymin, xmax, ymax) or
        an array of 6 integers (returning xmin, ymin, zmin, xmax,
        ymax, zmax). The z values may be useful for 3D/volumetric
        images; for 2D images they will be 0).

  - `displaywindow` (matrix) :
        Returns the display (a.k.a. full) window of the image, which
        is either an array of 4 integers (returning xmin, ymin,
        xmax, ymax) or an array of 6 integers (returning xmin, ymin,
        zmin, xmax, ymax, zmax). The z values may be useful for
        3D/volumetric images; for 2D images they will be 0).

  - `worldtocamera` (matrix) :
        The viewing matrix, which is a 4x4 matrix (an `Imath::M44f`,
        described as `TypeMatrix44`) giving the world-to-camera 3D
        transformation matrix that was used when  the image was
        created. Generally, only rendered images will have this.

  - `worldtoscreen` (matrix) :
        The projection matrix, which is a 4x4 matrix (an
        `Imath::M44f`, described as `TypeMatrix44`) giving the
        matrix that projected points from world space into a 2D
        screen coordinate system where *x* and *y* range from -1 to
        +1.  Generally, only rendered images will have this.

  - `worldtoNDC` (matrix) :
        The projection matrix, which is a 4x4 matrix (an
        `Imath::M44f`, described as `TypeMatrix44`) giving the
        matrix that projected points from world space into a 2D
        screen coordinate system where *x* and *y* range from 0 to
        +1.  Generally, only rendered images will have this.

  - `averagecolor` (float[nchannels]) :
        If available in the metadata (generally only for files that
        have been processed by `maketx`), this will return the
        average color of the texture (into an array of floats).

  - `averagealpha` (float) :
        If available in the metadata (generally only for files that
        have been processed by `maketx`), this will return the
        average alpha value of the texture (into a float).

  - `constantcolor` (float[nchannels]) :
        If the metadata (generally only for files that have been
        processed by `maketx`) indicates that the texture has the
        same values for all pixels in the texture, this will
        retrieve the constant color of the texture (into an array of
        floats). A non-constant image (or one that does not have the
        special metadata tag identifying it as a constant texture)
        will fail this query (return false).

  - `constantalpha` (float) :
        If the metadata indicates that the texture has the same
        values for all pixels in the texture, this will retrieve the
        constant alpha value of the texture. A non-constant image
        (or one that does not have the special metadata tag
        identifying it as a constant texture) will fail this query
        (return false).

  - `stat:tilesread` (int64) :
        Number of tiles read from this file.

  - `stat:bytesread` (int64) :
        Number of bytes of uncompressed pixel data read

  - `stat:redundant_tiles` (int64) :
        Number of times a tile was read, where the same tile had
        been rad before.

  - `stat:redundant_bytesread` (int64) :
        Number of bytes (of uncompressed pixel data) in tiles that
        were read redundantly.

  - `stat:redundant_bytesread` (int) :
        Number of tiles read from this file.

  - `stat:timesopened` (int) :
        Number of times this file was opened.

  - `stat:iotime` (float) :
        Time (in seconds) spent on all I/O for this file.

  - `stat:mipsused` (int) :
        Stores 1 if any MIP levels beyond the highest resolution
        were accessed, otherwise 0.

  - `stat:is_duplicate` (int) :
        Stores 1 if this file was a duplicate of another image,
        otherwise 0.

  - *Anything else* :
        For all other data names, the the metadata of the image file
        will be searched for an item that matches both the name and
        data type.


@param  filename
            The name of the texture.
@param  subimage
            The subimage to query. (The metadata retrieved is for
            the highest-resolution MIP level of that subimage.)
@param  dataname
            The name of the metadata to retrieve.
@param  datatype
            TypeDesc describing the data type.
@param  data
            Pointer to the caller-owned memory where the values
            should be stored. It is the caller's responsibility to
            ensure that `data` points to a large enough storage area
            to accommodate the `datatype` requested.

@returns
            `true` if `get_textureinfo()` is able to find the
            requested `dataname` for the texture and it matched the
            requested `datatype`.  If the requested data was not
            found or was not of the right data type, return `false`.
            Except for the `"exists"` query, a file that does not
            exist or could not be read properly as an image also
            constitutes a query failure that will return `false`. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_get_texture_info(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , int subimage
    , OIIO_ustring_t dataname
    , OIIO_TypeDesc_t datatype
    , void * data);
#define OIIO_TextureSystem_get_texture_info OpenImageIO_v2_3_6__TextureSystem_get_texture_info


/** A more efficient variety of `get_texture_info()` for cases where you
can use a `TextureHandle*` to specify the image and optionally have
a `Perthread*` for the calling thread. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_get_texture_info_from_handle(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , int subimage
    , OIIO_ustring_t dataname
    , OIIO_TypeDesc_t datatype
    , void * data);
#define OIIO_TextureSystem_get_texture_info_from_handle OpenImageIO_v2_3_6__TextureSystem_get_texture_info_from_handle


/** Copy the ImageSpec associated with the named texture (the first
subimage by default, or as set by `subimage`).

@param  filename
            The name of the image.
@param  subimage
            The subimage to query. (The spec retrieved is for the
            highest-resolution MIP level of that subimage.)
@param  spec
            ImageSpec into which will be copied the spec for the
            requested image.
@returns
            `true` upon success, `false` upon failure failure (such
            as being unable to find, open, or read the file, or if
            it does not contain the designated subimage or MIP
            level). */
unsigned int OpenImageIO_v2_3_6__TextureSystem_get_imagespec(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , int subimage
    , OIIO_ImageSpec_t * spec);
#define OIIO_TextureSystem_get_imagespec OpenImageIO_v2_3_6__TextureSystem_get_imagespec


/** A more efficient variety of `get_imagespec()` for cases where you
can use a `TextureHandle*` to specify the image and optionally have
a `Perthread*` for the calling thread. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_get_imagespec_from_handle(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , int subimage
    , OIIO_ImageSpec_t * spec);
#define OIIO_TextureSystem_get_imagespec_from_handle OpenImageIO_v2_3_6__TextureSystem_get_imagespec_from_handle


/** Return a pointer to an ImageSpec associated with the named texture
if the file is found and is an image format that can be read,
otherwise return `nullptr`.

This method is much more efficient than `get_imagespec()`, since it
just returns a pointer to the spec held internally by the
TextureSystem (rather than copying the spec to the user's memory).
However, the caller must beware that the pointer is only valid as
long as nobody (even other threads) calls `invalidate()` on the
file, or `invalidate_all()`, or destroys the TextureSystem and its
underlying ImageCache.

@param  filename
            The name of the image.
@param  subimage
            The subimage to query.  (The spec retrieved is for the
            highest-resolution MIP level of that subimage.)
@returns
            A pointer to the spec, if the image is found and able to
            be opened and read by an available image format plugin,
            and the designated subimage exists. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_imagespec(
    OIIO_TextureSystem_t * this_
    , OIIO_ImageSpec_t const * * return_
    , OIIO_ustring_t filename
    , int subimage);
#define OIIO_TextureSystem_imagespec OpenImageIO_v2_3_6__TextureSystem_imagespec


/** A more efficient variety of `imagespec()` for cases where you can
use a `TextureHandle*` to specify the image and optionally have a
`Perthread*` for the calling thread. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_imagespace_from_handle(
    OIIO_TextureSystem_t * this_
    , OIIO_ImageSpec_t const * * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , int subimage);
#define OIIO_TextureSystem_imagespace_from_handle OpenImageIO_v2_3_6__TextureSystem_imagespace_from_handle


/** For a texture specified by name, retrieve the rectangle of raw
unfiltered texels from the subimage specified in `options` and at
the designated `miplevel`, storing the pixel values beginning at the
address specified by `result`.  The pixel values will be converted
to the data type specified by `format`. The rectangular region to be
retrieved includes `begin` but does not include `end` (much like STL
begin/end usage). Requested pixels that are not part of the valid
pixel data region of the image file will be filled with zero values.
Channels requested but not present in the file will get the
`options.fill` value.

@param  filename
            The name of the image.
@param  options
            A TextureOpt describing access options, including wrap
            modes, fill value, and subimage, that will be used when
            retrieving pixels.
@param  miplevel
            The MIP level to retrieve pixels from (0 is the highest
            resolution level).
@param  xbegin/xend/ybegin/yend/zbegin/zend
            The range of pixels to retrieve. The pixels retrieved
            include the begin value but not the end value (much like
            STL begin/end usage).
@param  chbegin/chend
            Channel range to retrieve. To retrieve all channels, use
            `chbegin = 0`, `chend = nchannels`.
@param  format
            TypeDesc describing the data type of the values you want
            to retrieve into `result`. The pixel values will be
            converted to this type regardless of how they were
            stored in the file or in the cache.
@param  result
            Pointer to the memory where the pixel values should be
            stored.  It is up to the caller to ensure that `result`
            points to an area of memory big enough to accommodate
            the requested rectangle (taking into consideration its
            dimensions, number of channels, and data format).

@returns
            `true` for success, `false` for failure. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_get_texels(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOpt_t * options
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
    , void * result);
#define OIIO_TextureSystem_get_texels OpenImageIO_v2_3_6__TextureSystem_get_texels


/** A more efficient variety of `get_texels()` for cases where you can
use a `TextureHandle*` to specify the image and optionally have a
`Perthread*` for the calling thread. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_get_texels_from_handle(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOpt_t * options
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
    , void * result);
#define OIIO_TextureSystem_get_texels_from_handle OpenImageIO_v2_3_6__TextureSystem_get_texels_from_handle


/** Invalidate any cached information about the named file, including
loaded texture tiles from that texture, and close any open file
handle associated with the file. This calls
`ImageCache::invalidate(filename,force)` on the underlying
ImageCache. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_invalidate(
    OIIO_TextureSystem_t * this_
    , OIIO_ustring_t filename
    , _Bool force);
#define OIIO_TextureSystem_invalidate OpenImageIO_v2_3_6__TextureSystem_invalidate


/** Invalidate all cached data for all textures.  This calls
`ImageCache::invalidate_all(force)` on the underlying ImageCache. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_invalidate_all(
    OIIO_TextureSystem_t * this_
    , _Bool force);
#define OIIO_TextureSystem_invalidate_all OpenImageIO_v2_3_6__TextureSystem_invalidate_all


/** Close any open file handles associated with a named file, but do not
invalidate any image spec information or pixels associated with the
files.  A client might do this in order to release OS file handle
resources, or to make it safe for other processes to modify textures
on disk.  This calls `ImageCache::close(force)` on the underlying
ImageCache. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_close(
    OIIO_TextureSystem_t * this_
    , OIIO_ustring_t filename);
#define OIIO_TextureSystem_close OpenImageIO_v2_3_6__TextureSystem_close


/** `close()` all files known to the cache. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_close_all(
    OIIO_TextureSystem_t * this_);
#define OIIO_TextureSystem_close_all OpenImageIO_v2_3_6__TextureSystem_close_all


/** Is there a pending error message waiting to be retrieved? */
unsigned int OpenImageIO_v2_3_6__TextureSystem_has_error(
    OIIO_TextureSystem_t const * this_
    , _Bool * return_);
#define OIIO_TextureSystem_has_error OpenImageIO_v2_3_6__TextureSystem_has_error


/** Return the text of all pending error messages issued against this
TextureSystem, and clear the pending error message unless `clear` is
false. If no error message is pending, it will return an empty
string. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_geterror(
    OIIO_TextureSystem_t const * this_
    , std_string_t * * return_
    , _Bool clear);
#define OIIO_TextureSystem_geterror OpenImageIO_v2_3_6__TextureSystem_geterror


/** Returns a big string containing useful statistics about the
TextureSystem operations, suitable for saving to a file or
outputting to the terminal. The `level` indicates the amount of
detail in the statistics, with higher numbers (up to a maximum of 5)
yielding more and more esoteric information.  If `icstats` is true,
the returned string will also contain all the statistics of the
underlying ImageCache, but if false will only contain
texture-specific statistics. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_getstats(
    OIIO_TextureSystem_t const * this_
    , std_string_t * * return_
    , int level
    , _Bool icstats);
#define OIIO_TextureSystem_getstats OpenImageIO_v2_3_6__TextureSystem_getstats


/** Reset most statistics to be as they were with a fresh TextureSystem.
Caveat emptor: this does not flush the cache itself, so the resulting
statistics from the next set of texture requests will not match the
number of tile reads, etc., that would have resulted from a new
TextureSystem. */
unsigned int OpenImageIO_v2_3_6__TextureSystem_reset_stats(
    OIIO_TextureSystem_t * this_);
#define OIIO_TextureSystem_reset_stats OpenImageIO_v2_3_6__TextureSystem_reset_stats


/** Return an opaque, non-owning pointer to the underlying ImageCache
(if there is one). */
unsigned int OpenImageIO_v2_3_6__TextureSystem_imagecache(
    OIIO_TextureSystem_t const * this_
    , OIIO_ImageCache_t * * return_);
#define OIIO_TextureSystem_imagecache OpenImageIO_v2_3_6__TextureSystem_imagecache


unsigned int OpenImageIO_v2_3_6__TextureSystem__assign(
    OIIO_TextureSystem_t * this_
    , OIIO_TextureSystem_t * * return_
    , OIIO_TextureSystem_t const * rhs);
#define OIIO_TextureSystem__assign OpenImageIO_v2_3_6__TextureSystem__assign


/** Utility: Return the Wrap enum corresponding to a wrap name:
"default", "black", "clamp", "periodic", "mirror". */
unsigned int OpenImageIO_v2_3_6_Tex_decode_wrapmode(
    OIIO_Tex_Wrap * return_
    , char const * name);
#define OIIO_Tex_decode_wrapmode OpenImageIO_v2_3_6_Tex_decode_wrapmode


unsigned int OpenImageIO_v2_3_6_Tex_decode_wrapmode_ustring(
    OIIO_Tex_Wrap * return_
    , OIIO_ustring_t name);
#define OIIO_Tex_decode_wrapmode_ustring OpenImageIO_v2_3_6_Tex_decode_wrapmode_ustring


/** Utility: Parse a single wrap mode (e.g., "periodic") or a
comma-separated wrap modes string (e.g., "black,clamp") into
separate Wrap enums for s and t. */
unsigned int OpenImageIO_v2_3_6_Tex_parse_wrapmodes(
    char const * wrapmodes
    , OIIO_Tex_Wrap * swrapcode
    , OIIO_Tex_Wrap * twrapcode);
#define OIIO_Tex_parse_wrapmodes OpenImageIO_v2_3_6_Tex_parse_wrapmodes


#ifdef __cplusplus
}
#endif
