#pragma once
#include <c-imageio.h>
#include <c-std_string.h>
#include <c-string_view.h>
#include <c-typedesc.h>
#include <c-ustring.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct std__string_t_s std__string_t;
typedef std__string_t std_string_t;
typedef struct OpenImageIO_v2_3_6__ImageSpec_t_s OpenImageIO_v2_3_6__ImageSpec_t;
typedef OpenImageIO_v2_3_6__ImageSpec_t OIIO_ImageSpec_t;
typedef struct OpenImageIO_v2_3_6__TypeDesc_t_s OpenImageIO_v2_3_6__TypeDesc_t;
typedef OpenImageIO_v2_3_6__TypeDesc_t OIIO_TypeDesc_t;

typedef struct OpenImageIO_v2_3_6__pvt__ImageCacheImpl_t_s OpenImageIO_v2_3_6__pvt__ImageCacheImpl_t;
typedef OpenImageIO_v2_3_6__pvt__ImageCacheImpl_t OIIO_pvt_ImageCacheImpl_t;

typedef struct OpenImageIO_v2_3_6__pvt__ImageCacheFile_t_s OpenImageIO_v2_3_6__pvt__ImageCacheFile_t;
typedef OpenImageIO_v2_3_6__pvt__ImageCacheFile_t OIIO_pvt_ImageCacheFile_t;

typedef struct OpenImageIO_v2_3_6__pvt__ImageCachePerThreadInfo_t_s OpenImageIO_v2_3_6__pvt__ImageCachePerThreadInfo_t;
typedef OpenImageIO_v2_3_6__pvt__ImageCachePerThreadInfo_t OIIO_pvt_ImageCachePerThreadInfo_t;

/** Define an API to an abstract class that manages image files,
caches of open file handles as well as tiles of pixels so that truly
huge amounts of image data may be accessed by an application with low
memory footprint. */
typedef struct OpenImageIO_v2_3_6__ImageCache_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__ImageCache_t;
typedef OpenImageIO_v2_3_6__ImageCache_t OIIO_ImageCache_t;

/** An opaque data type that allows us to have a pointer to a tile but
without exposing any internals. */
typedef struct OpenImageIO_v2_3_6__ImageCache__Tile_t_s OpenImageIO_v2_3_6__ImageCache__Tile_t;
typedef OpenImageIO_v2_3_6__ImageCache__Tile_t OIIO_ImageCache_Tile_t;


/** Create a ImageCache and return a raw pointer to it.  This should
only be freed by passing it to `ImageCache::destroy()`!

@param  shared
    If `true`, the pointer returned will be a shared ImageCache (so
    that multiple parts of an application that request an ImageCache
    will all end up with the same one). If `shared` is `false`, a
    completely unique ImageCache will be created and returned.

@returns
    A raw pointer to an ImageCache, which can only be freed with
    `ImageCache::destroy()`.

@see    ImageCache::destroy */
unsigned int OpenImageIO_v2_3_6__ImageCache_create(
    OIIO_ImageCache_t * * return_
    , _Bool shared);
#define OIIO_ImageCache_create OpenImageIO_v2_3_6__ImageCache_create


/** Destroy an allocated ImageCache, including freeing all system
resources that it holds.

It is safe to destroy even a shared ImageCache, as the implementation
of `destroy()` will recognize a shared one and only truly release
its resources if it has been requested to be destroyed as many times as
shared ImageCache's were created.

@param  cache
    Raw pointer to the ImageCache to destroy.

@param  teardown
    For a shared ImageCache, if the `teardown` parameter is
    `true`, it will try to truly destroy the shared cache if
    nobody else is still holding a reference (otherwise, it will
    leave it intact). This parameter has no effect if `cache` was
    not the single globally shared ImageCache. */
unsigned int OpenImageIO_v2_3_6__ImageCache_destroy(
    OIIO_ImageCache_t * cache
    , _Bool teardown);
#define OIIO_ImageCache_destroy OpenImageIO_v2_3_6__ImageCache_destroy


/** Set a named attribute (i.e., a property or option) of the
ImageCache.

Example:

    ImageCache *ic;
    ...
    int maxfiles = 50;
    ic->attribute ("max_open_files", TypeDesc::INT, &maxfiles);

    const char *path = "/my/path";
    ic->attribute ("searchpath", TypeDesc::STRING, &path);

    // There are specialized versions for setting a single int,
    // float, or string without needing types or pointers:
    ic->attribute ("max_open_files", 50);
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
unsigned int OpenImageIO_v2_3_6__ImageCache_attribute(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void const * val);
#define OIIO_ImageCache_attribute OpenImageIO_v2_3_6__ImageCache_attribute


/** Specialized `attribute()` for setting a single `int` value. */
unsigned int OpenImageIO_v2_3_6__ImageCache_attribute_int(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , int val);
#define OIIO_ImageCache_attribute_int OpenImageIO_v2_3_6__ImageCache_attribute_int


/** Specialized `attribute()` for setting a single `float` value. */
unsigned int OpenImageIO_v2_3_6__ImageCache_attribute_float(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , float val);
#define OIIO_ImageCache_attribute_float OpenImageIO_v2_3_6__ImageCache_attribute_float


unsigned int OpenImageIO_v2_3_6__ImageCache_attribute_double(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , double val);
#define OIIO_ImageCache_attribute_double OpenImageIO_v2_3_6__ImageCache_attribute_double


/** Specialized `attribute()` for setting a single string value. */
unsigned int OpenImageIO_v2_3_6__ImageCache_attribute_string(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_string_view_t val);
#define OIIO_ImageCache_attribute_string OpenImageIO_v2_3_6__ImageCache_attribute_string


/** Get the named attribute, store it in `*val`. All of the attributes
that may be set with the `attribute() call` may also be queried with
`getattribute()`.

Examples:

    ImageCache *ic;
    ...
    int maxfiles;
    ic->getattribute ("max_open_files", TypeDesc::INT, &maxfiles);

    const char *path;
    ic->getattribute ("searchpath", TypeDesc::STRING, &path);

    // There are specialized versions for retrieving a single int,
    // float, or string without needing types or pointers:
    int maxfiles;
    ic->getattribute ("max_open_files", maxfiles);
    const char *path;
    ic->getattribute ("searchpath", &path);

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
unsigned int OpenImageIO_v2_3_6__ImageCache_getattribute(
    OIIO_ImageCache_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void * val);
#define OIIO_ImageCache_getattribute OpenImageIO_v2_3_6__ImageCache_getattribute


/** Specialized `attribute()` for retrieving a single `int` value. */
unsigned int OpenImageIO_v2_3_6__ImageCache_getattribute_int(
    OIIO_ImageCache_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , int * val);
#define OIIO_ImageCache_getattribute_int OpenImageIO_v2_3_6__ImageCache_getattribute_int


/** Specialized `attribute()` for retrieving a single `float` value. */
unsigned int OpenImageIO_v2_3_6__ImageCache_getattribute_float(
    OIIO_ImageCache_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , float * val);
#define OIIO_ImageCache_getattribute_float OpenImageIO_v2_3_6__ImageCache_getattribute_float


unsigned int OpenImageIO_v2_3_6__ImageCache_getattribute_double(
    OIIO_ImageCache_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , double * val);
#define OIIO_ImageCache_getattribute_double OpenImageIO_v2_3_6__ImageCache_getattribute_double


/** Specialized `attribute()` for retrieving a single `string` value
as a `char*`. */
unsigned int OpenImageIO_v2_3_6__ImageCache_getattribute_cstr(
    OIIO_ImageCache_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , char * * val);
#define OIIO_ImageCache_getattribute_cstr OpenImageIO_v2_3_6__ImageCache_getattribute_cstr


/** Specialized `attribute()` for retrieving a single `string` value
as a `std::string`. */
unsigned int OpenImageIO_v2_3_6__ImageCache_getattribute_string(
    OIIO_ImageCache_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , std_string_t * val);
#define OIIO_ImageCache_getattribute_string OpenImageIO_v2_3_6__ImageCache_getattribute_string


/** Retrieve a Perthread, unique to the calling thread. This is a
thread-specific pointer that will always return the Perthread for a
thread, which will also be automatically destroyed when the thread
terminates.

Applications that want to manage their own Perthread pointers (with
`create_thread_info` and `destroy_thread_info`) should still call
this, but passing in their managed pointer. If the passed-in
thread_info is not NULL, it won't create a new one or retrieve a
TSP, but it will do other necessary housekeeping on the Perthread
information. */
unsigned int OpenImageIO_v2_3_6__ImageCache_get_perthread_info(
    OIIO_ImageCache_t * this_
    , OIIO_pvt_ImageCachePerThreadInfo_t * * return_
    , OIIO_pvt_ImageCachePerThreadInfo_t * thread_info);
#define OIIO_ImageCache_get_perthread_info OpenImageIO_v2_3_6__ImageCache_get_perthread_info


/** Create a new Perthread. It is the caller's responsibility to
eventually destroy it using `destroy_thread_info()`. */
unsigned int OpenImageIO_v2_3_6__ImageCache_create_thread_info(
    OIIO_ImageCache_t * this_
    , OIIO_pvt_ImageCachePerThreadInfo_t * * return_);
#define OIIO_ImageCache_create_thread_info OpenImageIO_v2_3_6__ImageCache_create_thread_info


/** Destroy a Perthread that was allocated by `create_thread_info()`. */
unsigned int OpenImageIO_v2_3_6__ImageCache_destroy_thread_info(
    OIIO_ImageCache_t * this_
    , OIIO_pvt_ImageCachePerThreadInfo_t * thread_info);
#define OIIO_ImageCache_destroy_thread_info OpenImageIO_v2_3_6__ImageCache_destroy_thread_info


/** Retrieve an opaque handle for fast image lookups.  The opaque
`pointer thread_info` is thread-specific information returned by
`get_perthread_info()`.  Return NULL if something has gone horribly
wrong. */
unsigned int OpenImageIO_v2_3_6__ImageCache_get_image_handle(
    OIIO_ImageCache_t * this_
    , OIIO_pvt_ImageCacheFile_t * * return_
    , OIIO_ustring_t filename
    , OIIO_pvt_ImageCachePerThreadInfo_t * thread_info);
#define OIIO_ImageCache_get_image_handle OpenImageIO_v2_3_6__ImageCache_get_image_handle


/** Return true if the image handle (previously returned by
`get_image_handle()`) is a valid image that can be subsequently read. */
unsigned int OpenImageIO_v2_3_6__ImageCache_good(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_pvt_ImageCacheFile_t * file);
#define OIIO_ImageCache_good OpenImageIO_v2_3_6__ImageCache_good


/** Given possibly-relative `filename`, resolve it and use the true path
to the file, with searchpath logic applied. */
unsigned int OpenImageIO_v2_3_6__ImageCache_resolve_filename(
    OIIO_ImageCache_t const * this_
    , std_string_t * * return_
    , std_string_t const * filename);
#define OIIO_ImageCache_resolve_filename OpenImageIO_v2_3_6__ImageCache_resolve_filename


/** Get information or metadata about the named image and store it in
`*data`.

Data names may include any of the following:

- `"exists"` : Stores the value 1 (as an `int`) if the file exists and
  is an image format that OpenImageIO can read, or 0 if the file
  does not exist, or could not be properly read as an image. Note
  that unlike all other queries, this query will "succeed" (return
  `true`) even if the file does not exist.

- `"udim"` : Stores the value 1 (as an `int`) if the file is a
  "virtual UDIM" or texture atlas file (as described in
  :ref:`sec-texturesys-udim`) or 0 otherwise.

- `"subimages"` : The number of subimages in the file, as an `int`.

- `"resolution"` : The resolution of the image file, which is an
  array of 2 integers (described as `TypeDesc(INT,2)`).

- `"miplevels"` : The number of MIPmap levels for the specified
  subimage (an integer).

- `"texturetype"` : A string describing the type of texture of the
  given file, which describes how the texture may be used (also
  which texture API call is probably the right one for it). This
  currently may return one of: `"unknown"`, `"Plain Texture"`,
  `"Volume Texture"`, `"Shadow"`, or `"Environment"`.

- `"textureformat"` : A string describing the format of the given
  file, which describes the kind of texture stored in the file. This
  currently may return one of: `"unknown"`, `"Plain Texture"`,
  `"Volume Texture"`, `"Shadow"`, `"CubeFace Shadow"`,
  `"Volume Shadow"`, `"LatLong Environment"`, or
  `"CubeFace Environment"`. Note that there are several kinds of
  shadows and environment maps, all accessible through the same API
  calls.

- `"channels"` : The number of color channels in the file (an
  `int`).

- `"format"` : The native data format of the pixels in the file (an
  integer, giving the `TypeDesc::BASETYPE` of the data). Note that
  this is not necessarily the same as the data format stored in the
  image cache.

- `"cachedformat"` : The native data format of the pixels as stored
  in the image cache (an integer, giving the `TypeDesc::BASETYPE` of
  the data).  Note that this is not necessarily the same as the
  native data format of the file.

- `"datawindow"` : Returns the pixel data window of the image, which
  is either an array of 4 integers (returning xmin, ymin, xmax,
  ymax) or an array of 6 integers (returning xmin, ymin, zmin, xmax,
  ymax, zmax). The z values may be useful for 3D/volumetric images;
  for 2D images they will be 0).

- `"displaywindow"` : Returns the display (a.k.a. "full") window of
  the image, which is either an array of 4 integers (returning xmin,
  ymin, xmax, ymax) or an array of 6 integers (returning xmin, ymin,
  zmin, xmax, ymax, zmax). The z values may be useful for
  3D/volumetric images; for 2D images they will be 0).

- `"worldtocamera"` : The viewing matrix, which is a 4x4 matrix (an
  `Imath::M44f`, described as `TypeDesc(FLOAT,MATRIX)`), giving the
  world-to-camera 3D transformation matrix that was used when  the
  image was created. Generally, only rendered images will have this.

- `"worldtoscreen"` : The projection matrix, which is a 4x4 matrix
  (an `Imath::M44f`, described as `TypeDesc(FLOAT,MATRIX)`), giving
  the matrix that projected points from world space into a 2D screen
  coordinate system where $x$ and $y$ range from -1 to +1.
  Generally, only rendered images will have this.

- `"worldtoNDC"` : The projection matrix, which is a 4x4 matrix
  (an `Imath::M44f`, described as `TypeDesc(FLOAT,MATRIX)`), giving
  the matrix that projected points from world space into a 2D NDC
  coordinate system where $x$ and $y$ range from 0 to +1. Generally,
  only rendered images will have this.

- `"averagecolor"` : If available in the metadata (generally only
  for files that have been processed by `maketx`), this will return
  the average color of the texture (into an array of `float`).

- `"averagealpha"` : If available in the metadata (generally only
  for files that have been processed by `maketx`), this will return
  the average alpha value of the texture (into a `float`).

- `"constantcolor"` : If the metadata (generally only for files that
  have been processed by `maketx`) indicates that the texture has
  the same values for all pixels in the texture, this will retrieve
  the constant color of the texture (into an array of floats). A
  non-constant image (or one that does not have the special metadata
  tag identifying it as a constant texture) will fail this query
  (return `false`).

- `"constantalpha"` : If the metadata indicates that the texture has
  the same values for all pixels in the texture, this will retrieve
  the constant alpha value of the texture (into a float). A
  non-constant image (or one that does not have the special metadata
  tag identifying it as a constant texture) will fail this query
  (return `false`).

- `"stat:tilesread"` : Number of tiles read from this file
  (`int64`).

- `"stat:bytesread"` : Number of bytes of uncompressed pixel data
  read from this file (`int64`).

- `"stat:redundant_tiles"` : Number of times a tile was read, where
  the same tile had been rad before. (`int64`).

- `"stat:redundant_bytesread"` : Number of bytes (of uncompressed
  pixel data) in tiles that were read redundantly. (`int64`).

- `"stat:redundant_bytesread"` : Number of tiles read from this file (`int`).

- `"stat:image_size"` : Size of the uncompressed image pixel data
of this image, in bytes (`int64`).

- `"stat:file_size"` : Size of the disk file (possibly compressed)
  for this image, in bytes (`int64`).

- `"stat:timesopened"` : Number of times this file was opened
  (`int`).

- `"stat:iotime"` : Time (in seconds) spent on all I/O for this file
  (`float`).

- `"stat:mipsused"` : Stores 1 if any MIP levels beyond the highest
  resolution were accessed, otherwise 0. (`int`)

- `"stat:is_duplicate"` : Stores 1 if this file was a duplicate of
  another image, otherwise 0. (`int`)

- *Anything else*  : For all other data names, the the metadata of
  the image file will be searched for an item that matches both the
  name and data type.



@param  filename
            The name of the image.
@param  subimage/miplevel
            The subimage and MIP level to query.
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
            `true` if `get_image_info()` is able to find the
            requested `dataname` for the image and it matched the
            requested `datatype`.  If the requested data was not
            found or was not of the right data type, return `false`.
            Except for the `"exists"` query, a file that does not
            exist or could not be read properly as an image also
            constitutes a query failure that will return `false`. */
unsigned int OpenImageIO_v2_3_6__ImageCache_get_image_info(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , int subimage
    , int miplevel
    , OIIO_ustring_t dataname
    , OIIO_TypeDesc_t datatype
    , void * data);
#define OIIO_ImageCache_get_image_info OpenImageIO_v2_3_6__ImageCache_get_image_info


/** A more efficient variety of `get_image_info()` for cases where you
can use an `ImageHandle*` to specify the image and optionally have a
`Perthread*` for the calling thread. */
unsigned int OpenImageIO_v2_3_6__ImageCache_get_image_info_with_handle(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_pvt_ImageCacheFile_t * file
    , OIIO_pvt_ImageCachePerThreadInfo_t * thread_info
    , int subimage
    , int miplevel
    , OIIO_ustring_t dataname
    , OIIO_TypeDesc_t datatype
    , void * data);
#define OIIO_ImageCache_get_image_info_with_handle OpenImageIO_v2_3_6__ImageCache_get_image_info_with_handle


/** Copy the ImageSpec associated with the named image (the first
subimage & miplevel by default, or as set by `subimage` and
`miplevel`).

@param  filename
            The name of the image.
@param  spec
            ImageSpec into which will be copied the spec for the
            requested image.
@param  subimage/miplevel
            The subimage and MIP level to query.
@param  native
            If `false` (the default), then the spec retrieved will
            accurately describe the image stored internally in the
            cache, whereas if `native` is `true`, the spec retrieved
            will reflect the contents of the original file.  These
            may differ due to use of certain ImageCache settings
            such as `"forcefloat"` or `"autotile"`.
@returns
            `true` upon success, `false` upon failure failure (such
            as being unable to find, open, or read the file, or if
            it does not contain the designated subimage or MIP
            level). */
unsigned int OpenImageIO_v2_3_6__ImageCache_get_imagespec(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_ImageSpec_t * spec
    , int subimage
    , int miplevel
    , _Bool native);
#define OIIO_ImageCache_get_imagespec OpenImageIO_v2_3_6__ImageCache_get_imagespec


/** A more efficient variety of `get_imagespec()` for cases where you
can use an `ImageHandle*` to specify the image and optionally have a
`Perthread*` for the calling thread. */
unsigned int OpenImageIO_v2_3_6__ImageCache_get_imagespec_with_handle(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_pvt_ImageCacheFile_t * file
    , OIIO_pvt_ImageCachePerThreadInfo_t * thread_info
    , OIIO_ImageSpec_t * spec
    , int subimage
    , int miplevel
    , _Bool native);
#define OIIO_ImageCache_get_imagespec_with_handle OpenImageIO_v2_3_6__ImageCache_get_imagespec_with_handle


/** Return a pointer to an ImageSpec associated with the named image
(the first subimage & MIP level by default, or as set by `subimage`
and `miplevel`) if the file is found and is an image format that can
be read, otherwise return `nullptr`.

This method is much more efficient than `get_imagespec()`, since it
just returns a pointer to the spec held internally by the ImageCache
(rather than copying the spec to the user's memory). However, the
caller must beware that the pointer is only valid as long as nobody
(even other threads) calls `invalidate()` on the file, or
`invalidate_all()`, or destroys the ImageCache.

@param  filename
            The name of the image.
@param  subimage/miplevel
            The subimage and MIP level to query.
@param  native
            If `false` (the default), then the spec retrieved will
            accurately describe the image stored internally in the
            cache, whereas if `native` is `true`, the spec retrieved
            will reflect the contents of the original file.  These
            may differ due to use of certain ImageCache settings
            such as `"forcefloat"` or `"autotile"`.
@returns
            A pointer to the spec, if the image is found and able to
            be opened and read by an available image format plugin,
            and the designated subimage and MIP level exists. */
unsigned int OpenImageIO_v2_3_6__ImageCache_imagespec(
    OIIO_ImageCache_t * this_
    , OIIO_ImageSpec_t const * * return_
    , OIIO_ustring_t filename
    , int subimage
    , int miplevel
    , _Bool native);
#define OIIO_ImageCache_imagespec OpenImageIO_v2_3_6__ImageCache_imagespec


/** A more efficient variety of `imagespec()` for cases where you can
use an `ImageHandle*` to specify the image and optionally have a
`Perthread*` for the calling thread. */
unsigned int OpenImageIO_v2_3_6__ImageCache_imagespec_with_handle(
    OIIO_ImageCache_t * this_
    , OIIO_ImageSpec_t const * * return_
    , OIIO_pvt_ImageCacheFile_t * file
    , OIIO_pvt_ImageCachePerThreadInfo_t * thread_info
    , int subimage
    , int miplevel
    , _Bool native);
#define OIIO_ImageCache_imagespec_with_handle OpenImageIO_v2_3_6__ImageCache_imagespec_with_handle


/** For an image specified by name, retrieve the rectangle of pixels
from the designated subimage and MIP level, storing the pixel values
beginning at the address specified by `result` and with the given
strides.  The pixel values will be converted to the data type
specified by `format`. The rectangular region to be retrieved
includes `begin` but does not include `end` (much like STL begin/end
usage). Requested pixels that are not part of the valid pixel data
region of the image file will be filled with zero values.

@param  filename
            The name of the image.
@param  subimage/miplevel
            The subimage and MIP level to retrieve pixels from.
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
            stored in the file.
@param  result
            Pointer to the memory where the pixel values should be
            stored.  It is up to the caller to ensure that `result`
            points to an area of memory big enough to accommodate
            the requested rectangle (taking into consideration its
            dimensions, number of channels, and data format).
@param  xstride/ystride/zstride
            The number of bytes between the beginning of successive
            pixels, scanlines, and image planes, respectively. Any
            stride values set to `AutoStride` will be assumed to
            indicate a contiguous data layout in that dimension.
@param  cache_chbegin/cache_chend These parameters can be used to
            tell the ImageCache to read and cache a subset of
            channels (if not specified or if they denote a
            non-positive range, all the channels of the file will be
            stored in the cached tile).

@returns
            `true` for success, `false` for failure. */
unsigned int OpenImageIO_v2_3_6__ImageCache_get_pixels_with_channels(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
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
    , void * result
    , long xstride
    , long ystride
    , long zstride
    , int cache_chbegin
    , int cache_chend);
#define OIIO_ImageCache_get_pixels_with_channels OpenImageIO_v2_3_6__ImageCache_get_pixels_with_channels


/** A more efficient variety of `get_pixels()` for cases where you can
use an `ImageHandle*` to specify the image and optionally have a
`Perthread*` for the calling thread. */
unsigned int OpenImageIO_v2_3_6__ImageCache_get_pixels_with_channels_and_handle(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_pvt_ImageCacheFile_t * file
    , OIIO_pvt_ImageCachePerThreadInfo_t * thread_info
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
    , void * result
    , long xstride
    , long ystride
    , long zstride
    , int cache_chbegin
    , int cache_chend);
#define OIIO_ImageCache_get_pixels_with_channels_and_handle OpenImageIO_v2_3_6__ImageCache_get_pixels_with_channels_and_handle


/** A simplified `get_pixels()` where all channels are retrieved,
strides are assumed to be contiguous. */
unsigned int OpenImageIO_v2_3_6__ImageCache_get_pixels(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , int subimage
    , int miplevel
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend
    , OIIO_TypeDesc_t format
    , void * result);
#define OIIO_ImageCache_get_pixels OpenImageIO_v2_3_6__ImageCache_get_pixels


/** A more efficient variety of `get_pixels()` for cases where you can
use an `ImageHandle*` to specify the image and optionally have a
`Perthread*` for the calling thread. */
unsigned int OpenImageIO_v2_3_6__ImageCache_get_pixels_with_handle(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_pvt_ImageCacheFile_t * file
    , OIIO_pvt_ImageCachePerThreadInfo_t * thread_info
    , int subimage
    , int miplevel
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend
    , OIIO_TypeDesc_t format
    , void * result);
#define OIIO_ImageCache_get_pixels_with_handle OpenImageIO_v2_3_6__ImageCache_get_pixels_with_handle


/** Invalidate any loaded tiles or open file handles associated with the
filename, so that any subsequent queries will be forced to re-open
the file or re-load any tiles (even those that were previously
loaded and would ordinarily be reused).  A client might do this if,
for example, they are aware that an image being held in the cache
has been updated on disk.  This is safe to do even if other
procedures are currently holding reference-counted tile pointers
from the named image, but those procedures will not get updated
pixels until they release the tiles they are holding.

If `force` is true, this invalidation will happen unconditionally;
if false, the file will only be invalidated if it has been changed
since it was first opened by the ImageCache. */
unsigned int OpenImageIO_v2_3_6__ImageCache_invalidate(
    OIIO_ImageCache_t * this_
    , OIIO_ustring_t filename
    , _Bool force);
#define OIIO_ImageCache_invalidate OpenImageIO_v2_3_6__ImageCache_invalidate


/** Invalidate all loaded tiles and close open file handles.  This is
safe to do even if other procedures are currently holding
reference-counted tile pointers from the named image, but those
procedures will not get updated pixels (if the images change) until
they release the tiles they are holding.

If `force` is true, everything will be invalidated, no matter how
wasteful it is, but if `force` is false, in actuality files will
only be invalidated if their modification times have been changed
since they were first opened. */
unsigned int OpenImageIO_v2_3_6__ImageCache_invalidate_all(
    OIIO_ImageCache_t * this_
    , _Bool force);
#define OIIO_ImageCache_invalidate_all OpenImageIO_v2_3_6__ImageCache_invalidate_all


/** Close any open file handles associated with a named file, but do not
invalidate any image spec information or pixels associated with the
files.  A client might do this in order to release OS file handle
resources, or to make it safe for other processes to modify image
files on disk. */
unsigned int OpenImageIO_v2_3_6__ImageCache_close(
    OIIO_ImageCache_t * this_
    , OIIO_ustring_t filename);
#define OIIO_ImageCache_close OpenImageIO_v2_3_6__ImageCache_close


/** `close()` all files known to the cache. */
unsigned int OpenImageIO_v2_3_6__ImageCache_close_all(
    OIIO_ImageCache_t * this_);
#define OIIO_ImageCache_close_all OpenImageIO_v2_3_6__ImageCache_close_all


/** Find the tile specified by an image filename, subimage & miplevel,
the coordinates of a pixel, and optionally a channel range.   An
opaque pointer to the tile will be returned, or `nullptr` if no such
file (or tile within the file) exists or can be read.  The tile will
not be purged from the cache until after `release_tile()` is called
on the tile pointer the same number of times that `get_tile()` was
called (reference counting). This is thread-safe! If `chend <
chbegin`, it will retrieve a tile containing all channels in the
file. */
unsigned int OpenImageIO_v2_3_6__ImageCache_get_tile(
    OIIO_ImageCache_t * this_
    , OIIO_ImageCache_Tile_t * * return_
    , OIIO_ustring_t filename
    , int subimage
    , int miplevel
    , int x
    , int y
    , int z
    , int chbegin
    , int chend);
#define OIIO_ImageCache_get_tile OpenImageIO_v2_3_6__ImageCache_get_tile


/** A slightly more efficient variety of `get_tile()` for cases where
you can use an `ImageHandle*` to specify the image and optionally
have a `Perthread*` for the calling thread.

@see `get_pixels()` */
unsigned int OpenImageIO_v2_3_6__ImageCache_get_tile_with_handle(
    OIIO_ImageCache_t * this_
    , OIIO_ImageCache_Tile_t * * return_
    , OIIO_pvt_ImageCacheFile_t * file
    , OIIO_pvt_ImageCachePerThreadInfo_t * thread_info
    , int subimage
    , int miplevel
    , int x
    , int y
    , int z
    , int chbegin
    , int chend);
#define OIIO_ImageCache_get_tile_with_handle OpenImageIO_v2_3_6__ImageCache_get_tile_with_handle


/** After finishing with a tile, release_tile will allow it to
once again be purged from the tile cache if required. */
unsigned int OpenImageIO_v2_3_6__ImageCache_release_tile(
    OIIO_ImageCache_t const * this_
    , OIIO_ImageCache_Tile_t * tile);
#define OIIO_ImageCache_release_tile OpenImageIO_v2_3_6__ImageCache_release_tile


/** Retrieve the data type of the pixels stored in the tile, which may
be different than the type of the pixels in the disk file. */
unsigned int OpenImageIO_v2_3_6__ImageCache_tile_format(
    OIIO_ImageCache_t const * this_
    , OIIO_TypeDesc_t * return_
    , OIIO_ImageCache_Tile_t const * tile);
#define OIIO_ImageCache_tile_format OpenImageIO_v2_3_6__ImageCache_tile_format


/** Retrieve the ROI describing the pixels and channels stored in the
tile. */
unsigned int OpenImageIO_v2_3_6__ImageCache_tile_roi(
    OIIO_ImageCache_t const * this_
    , OIIO_ROI_t * return_
    , OIIO_ImageCache_Tile_t const * tile);
#define OIIO_ImageCache_tile_roi OpenImageIO_v2_3_6__ImageCache_tile_roi


/** For a tile retrived by `get_tile()`, return a pointer to the pixel
data itself, and also store in `format` the data type that the
pixels are internally stored in (which may be different than the
data type of the pixels in the disk file).   This method should only
be called on a tile that has been requested by `get_tile()` but has
not yet been released with `release_tile()`. */
unsigned int OpenImageIO_v2_3_6__ImageCache_tile_pixels(
    OIIO_ImageCache_t const * this_
    , void const * * return_
    , OIIO_ImageCache_Tile_t * tile
    , OIIO_TypeDesc_t * format);
#define OIIO_ImageCache_tile_pixels OpenImageIO_v2_3_6__ImageCache_tile_pixels


/** Preemptively add a tile corresponding to the named image, at the
given subimage, MIP level, and channel range.  The tile added is the
one whose corner is (x,y,z), and buffer points to the pixels (in the
given format, with supplied strides) which will be copied and
inserted into the cache and made available for future lookups.
If chend < chbegin, it will add a tile containing the full set of
channels for the image. Note that if the 'copy' flag is false, the
data is assumed to be in some kind of persistent storage and will
not be copied, nor will its pixels take up additional memory in the
cache. */
unsigned int OpenImageIO_v2_3_6__ImageCache_add_tile(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , int subimage
    , int miplevel
    , int x
    , int y
    , int z
    , int chbegin
    , int chend
    , OIIO_TypeDesc_t format
    , void const * buffer
    , long xstride
    , long ystride
    , long zstride
    , _Bool copy);
#define OIIO_ImageCache_add_tile OpenImageIO_v2_3_6__ImageCache_add_tile


/** Is there a pending error message waiting to be retrieved? */
unsigned int OpenImageIO_v2_3_6__ImageCache_has_error(
    OIIO_ImageCache_t const * this_
    , _Bool * return_);
#define OIIO_ImageCache_has_error OpenImageIO_v2_3_6__ImageCache_has_error


/** Return the text of all pending error messages issued against this
ImageCache, and clear the pending error message unless `clear` is
false. If no error message is pending, it will return an empty
string. */
unsigned int OpenImageIO_v2_3_6__ImageCache_geterror(
    OIIO_ImageCache_t const * this_
    , std_string_t * * return_
    , _Bool clear);
#define OIIO_ImageCache_geterror OpenImageIO_v2_3_6__ImageCache_geterror


/** Returns a big string containing useful statistics about the
ImageCache operations, suitable for saving to a file or outputting
to the terminal. The `level` indicates the amount of detail in
the statistics, with higher numbers (up to a maximum of 5) yielding
more and more esoteric information. */
unsigned int OpenImageIO_v2_3_6__ImageCache_getstats(
    OIIO_ImageCache_t const * this_
    , std_string_t * * return_
    , int level);
#define OIIO_ImageCache_getstats OpenImageIO_v2_3_6__ImageCache_getstats


/** Reset most statistics to be as they were with a fresh ImageCache.
Caveat emptor: this does not flush the cache itelf, so the resulting
statistics from the next set of texture requests will not match the
number of tile reads, etc., that would have resulted from a new
ImageCache. */
unsigned int OpenImageIO_v2_3_6__ImageCache_reset_stats(
    OIIO_ImageCache_t * this_);
#define OIIO_ImageCache_reset_stats OpenImageIO_v2_3_6__ImageCache_reset_stats


unsigned int OpenImageIO_v2_3_6__ImageCache__assign(
    OIIO_ImageCache_t * this_
    , OIIO_ImageCache_t * * return_
    , OIIO_ImageCache_t const * rhs);
#define OIIO_ImageCache__assign OpenImageIO_v2_3_6__ImageCache__assign


#ifdef __cplusplus
}
#endif
