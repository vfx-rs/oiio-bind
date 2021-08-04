#pragma once
#include <c-imageio.h>
#include <c-span.h>
#include <c-std_string.h>
#include <c-string_view.h>
#include <c-typedesc.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenImageIO_v2_3_6__Filesystem__IOProxy_t_s OpenImageIO_v2_3_6__Filesystem__IOProxy_t;
typedef OpenImageIO_v2_3_6__Filesystem__IOProxy_t OIIO_Filesystem_IOProxy_t;
typedef struct OpenImageIO_v2_3_6__ImageCache_t_s OpenImageIO_v2_3_6__ImageCache_t;
typedef OpenImageIO_v2_3_6__ImageCache_t OIIO_ImageCache_t;
typedef struct OpenImageIO_v2_3_6__DeepData_t_s OpenImageIO_v2_3_6__DeepData_t;
typedef OpenImageIO_v2_3_6__DeepData_t OIIO_DeepData_t;
typedef struct OpenImageIO_v2_3_6__ROI_t_s OpenImageIO_v2_3_6__ROI_t;
typedef OpenImageIO_v2_3_6__ROI_t OIIO_ROI_t;
typedef struct OpenImageIO_v2_3_6__ImageSpec_t_s OpenImageIO_v2_3_6__ImageSpec_t;
typedef OpenImageIO_v2_3_6__ImageSpec_t OIIO_ImageSpec_t;
typedef struct OpenImageIO_v2_3_6__ImageOutput_t_s OpenImageIO_v2_3_6__ImageOutput_t;
typedef OpenImageIO_v2_3_6__ImageOutput_t OIIO_ImageOutput_t;

/** An ImageBuf can store its pixels in one of several ways (each
identified by an `IBStorage` enumerated value): */
enum OpenImageIO_v2_3_6__ImageBuf__IBStorage_e {
    OIIO_ImageBuf_IBStorage_UNINITIALIZED = 0,
    OIIO_ImageBuf_IBStorage_LOCALBUFFER = 1,
    OIIO_ImageBuf_IBStorage_APPBUFFER = 2,
    OIIO_ImageBuf_IBStorage_IMAGECACHE = 3,
};
typedef unsigned int OIIO_ImageBuf_IBStorage;
/** Wrap mode describes what happens when an iterator points to
a value outside the usual data range of an image. */
enum OpenImageIO_v2_3_6__ImageBuf__WrapMode_e {
    OIIO_ImageBuf_WrapMode_WrapDefault = 0,
    OIIO_ImageBuf_WrapMode_WrapBlack = 1,
    OIIO_ImageBuf_WrapMode_WrapClamp = 2,
    OIIO_ImageBuf_WrapMode_WrapPeriodic = 3,
    OIIO_ImageBuf_WrapMode_WrapMirror = 4,
    OIIO_ImageBuf_WrapMode__WrapLast = 5,
};
typedef unsigned int OIIO_ImageBuf_WrapMode;
enum OpenImageIO_v2_3_6__InitializePixels_e {
    OIIO_InitializePixels_No = 0,
    OIIO_InitializePixels_Yes = 1,
};
typedef unsigned int OIIO_InitializePixels;

/** An ImageBuf is a simple in-memory representation of a 2D image.  It uses
ImageInput and ImageOutput underneath for its file I/O, and has simple
routines for setting and getting individual pixels, that hides most of
the details of memory layout and data representation (translating
to/from float automatically).

ImageBuf makes an important simplification: all channels are just one
data type. For example, if an image file on disk has a mix of `half` and
`float` channels, the in-memory ImageBuf representation will be entirely
`float` (for mixed data types, it will try to pick one that can best
represent all channels without a loss of precision or range). However,
by using the `set_write_format()` method, it is still possible to write
an ImageBuf to a file with mixed channel types.

Most of the time, ImageBuf data is read lazily (I/O only happens when
you first call methods that actually need metadata or pixel data).
Explicit calls to `read()` are therefore optional and are only needed
if you want to specify non-default arguments (such as choosing something
other than the first subimage of the file, or forcing the read to
translate into a different data format than appears in the file).

ImageBuf data coming from disk files is backed by ImageCache. That is,
especially for tiled files, specific regions of the image will only
be read if and when they are needed, and if there are many large
ImageBuf's, memory holding pixels not recently accesssed will be
automatically freed. Thus, performance of ImageBuf on very large images
(or if there are many ImageBuf's simultaneously in use) can be sensitive
to choices of the ImageCache parameters such as "autotile". It may be
wise for maximum performance to explicitly `read()` (with `force=true`)
small images into memory rather than using the ImageCache, in cases
where your application has no need for the ImageCache features that
limit memory footprint (such as if you know for sure that your app will
only read a small number of images, of reasonable size, and will need
to access all the pixels of all the images it reads).

Writeable ImageBufs are always stored entirely in memory, and do not use
the ImageCache or any other clever schemes to limit memory. If you have
enough simultaneous writeable large ImageBuf's, you can run out of RAM.
Note that if an ImageBuf starts as readable (backed by ImageCache), any
alterations to its pixels (for example, via `setpixel()` or traversing
it with a non-const `Iterator`) will cause it to be read entirely into
memory and remain in memory thereafter for the rest of the life of that
ImageBuf.

Notes about ImageBuf thread safety:

* The various read-only methods for accessing the spec or the pixels,
  including `init_spec()`, `read()`, `spec()`, all the getpixel flavors
  and `ConstIterator` over the pixels, and other informational methods
  such as `roi()`, all are thread-safe and may be called concurrently
  with any of the other thread-safe methods.
* Methods that alter pixel values, such as all the setpixel flavors,
  and (non-const) `Iterator` over the pixels, and the `write()` method
  are "thread safe" in the sense that you won't crash your app by doing
  these concurrently with each other or with the reading functionality,
  but on the other hand, if two threads are changing the same pixels
  simultaneously or one is writing while others are reading, you may end
  up with an inconsistent resulting image.
* Construction and destruction, `reset()`, and anything that alters
  image metadata (such as writes through `specmod()`) are NOT THREAD
  SAFE and you should ensure that you are not doing any of these calls
  simultaneously with any other operations on the same ImageBuf. */
typedef struct OpenImageIO_v2_3_6__ImageBuf_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__ImageBuf_t;
typedef OpenImageIO_v2_3_6__ImageBuf_t OIIO_ImageBuf_t;

typedef struct OpenImageIO_v2_3_6__ImageBuf__IteratorBase_t_s {
    char data[128];
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__ImageBuf__IteratorBase_t;
typedef OpenImageIO_v2_3_6__ImageBuf__IteratorBase_t OIIO_ImageBuf_IteratorBase_t;


/** Default constructor makes an empty/uninitialized ImageBuf.  There
isn't much you can do with an uninitialized buffer until you call
`reset()`. The storage type of a default-constructed ImageBuf is
`IBStorage::UNINITIALIZED`. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_default(
    OIIO_ImageBuf_t * * this_);
#define OIIO_ImageBuf_default OpenImageIO_v2_3_6__ImageBuf_default


/** Destructor for an ImageBuf. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_dtor(
    OIIO_ImageBuf_t * this_);
#define OIIO_ImageBuf_dtor OpenImageIO_v2_3_6__ImageBuf_dtor


/** Construct a read-only ImageBuf that will be used to read the named
file (at the given subimage and MIP-level, defaulting to the first
in the file).  But don't read it yet!  The image will actually be
read lazily, only when other methods need to access the spec and/or
pixels, or when an explicit call to `init_spec()` or `read()` is
made, whichever comes first.

The implementation may end up either reading the entire image
internally owned memory (if so, the storage will be `LOCALBUFFER`),
or it may rely on being backed by an ImageCache (in this case, the
storage will be `IMAGECACHE`) -- depending on the image size and
other factors.

@param name
            The image to read.
@param subimage/miplevel
            The subimage and MIP level to read (defaults to the
            first subimage of the file, highest-res MIP level).
@param imagecache
            Optionally, a particular ImageCache to use. If nullptr,
            the default global/shared image cache will be used. If
            a custom ImageCache (not the global/shared one), it is
            important that the IC should not be destroyed while the
            ImageBuf is still alive.
@param config
            Optionally, a pointer to an ImageSpec whose metadata
            contains configuration hints that set options related
            to the opening and reading of the file.
@param ioproxy
        Optional pointer to an IOProxy to use when reading from the
        file. The caller retains ownership of the proxy. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_ctor(
    OIIO_ImageBuf_t * * this_
    , OIIO_string_view_t name
    , int subimage
    , int miplevel
    , OIIO_ImageCache_t * imagecache
    , OIIO_ImageSpec_t const * config
    , OIIO_Filesystem_IOProxy_t * ioproxy);
#define OIIO_ImageBuf_ctor OpenImageIO_v2_3_6__ImageBuf_ctor


/** Construct a writable ImageBuf with the given specification
(including resolution, data type, metadata, etc.). The ImageBuf will
allocate and own its own pixel memory and will free that memory
automatically upon destruction, clear(), or reset(). Upon successful
initialization, the storage will be reported as `LOCALBUFFER`.

@param spec
            An ImageSpec describing the image and its metadata. If
            not enough information is given to know how much memory
            to allocate (width, height, depth, channels, and data
            format), the ImageBuf will remain in an UNINITIALIZED
            state and will have no local pixel storage.
@param zero
            After a successful allocation of the local pixel
            storage, this parameter controls whether the pixels
            will be initialized to hold zero (black) values
            (`InitializePixels::Yes`) or if the pixel memory will
            remain uninitialized (`InitializePixels::No`) and thus
            may hold nonsensical values. Choosing `No` may save the
            time of writing to the pixel memory if you know for sure
            that you are about to overwrite it completely before you
            will need to read any pixel values. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_ctor_initialized(
    OIIO_ImageBuf_t * * this_
    , OIIO_ImageSpec_t const * spec
    , OIIO_InitializePixels zero);
#define OIIO_ImageBuf_ctor_initialized OpenImageIO_v2_3_6__ImageBuf_ctor_initialized


/** Construct a writable ImageBuf that "wraps" existing pixel memory
owned by the calling application. The ImageBuf does not own the
pixel storage and will will not free/delete that memory, even when
the ImageBuf is destroyed. Upon successful initialization, the
storage will be reported as `APPBUFFER`.

@param spec
            An ImageSpec describing the image and its metadata. If
            not enough information is given to know the "shape" of
            the image (width, height, depth, channels, and data
            format), the ImageBuf will remain in an UNINITIALIZED
            state.
@param buffer
            A pointer to the caller-owned memory containing the
            storage for the pixels. It must be already allocated
            with enough space to hold a full image as described by
            `spec`.
@param  xstride/ystride/zstride
            The distance in bytes between successive pixels,
            scanlines, and image planes in the buffer (or
            `AutoStride` to indicate "contiguous" data in any of
            those dimensions). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_wrap_buffer(
    OIIO_ImageBuf_t * * this_
    , OIIO_ImageSpec_t const * spec
    , void * buffer
    , long x_stride
    , long y_stride
    , long z_stride);
#define OIIO_ImageBuf_wrap_buffer OpenImageIO_v2_3_6__ImageBuf_wrap_buffer


/** Construct a copy of an ImageBuf. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_copy(
    OIIO_ImageBuf_t * * this_
    , OIIO_ImageBuf_t const * src);
#define OIIO_ImageBuf_copy OpenImageIO_v2_3_6__ImageBuf_copy


unsigned int OpenImageIO_v2_3_6__ImageBuf_clear(
    OIIO_ImageBuf_t * this_);
#define OIIO_ImageBuf_clear OpenImageIO_v2_3_6__ImageBuf_clear


/** Destroy any previous contents of the ImageBuf and re-initialize it
to resemble a freshly constructed ImageBuf using the default
constructor (holding no image, with storage
`IBStorage::UNINITIALIZED`). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_reset(
    OIIO_ImageBuf_t * this_);
#define OIIO_ImageBuf_reset OpenImageIO_v2_3_6__ImageBuf_reset


/** Destroy any previous contents of the ImageBuf and re-initialize it
as if newly constructed with the same arguments, as a read-only
representation of an existing image file. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_reset_with_file(
    OIIO_ImageBuf_t * this_
    , OIIO_string_view_t name
    , int subimage
    , int miplevel
    , OIIO_ImageCache_t * imagecache
    , OIIO_ImageSpec_t const * config
    , OIIO_Filesystem_IOProxy_t * ioproxy);
#define OIIO_ImageBuf_reset_with_file OpenImageIO_v2_3_6__ImageBuf_reset_with_file


/** Destroy any previous contents of the ImageBuf and re-initialize it
as if newly constructed with the same arguments, as a read/write
image with locally allocated storage that can hold an image as
described by `spec`. The optional `zero` parameter controls whether
the pixel values are filled with black/empty, or are left
uninitialized after being allocated.

Note that if the ImageSpec does not contain enough information to
specify how much memory to allocate (width, height, channels, and
data format), the ImageBuf will remain uninitialized (regardless of
how `zero` is set). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_reset_initialized(
    OIIO_ImageBuf_t * this_
    , OIIO_ImageSpec_t const * spec
    , OIIO_InitializePixels zero);
#define OIIO_ImageBuf_reset_initialized OpenImageIO_v2_3_6__ImageBuf_reset_initialized


/** Destroy any previous contents of the ImageBuf and re-initialize it
as if newly constructed with the same arguments, to "wrap" existing
pixel memory owned by the calling application. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_reset_wrap_buffer(
    OIIO_ImageBuf_t * this_
    , OIIO_ImageSpec_t const * spec
    , void * buffer
    , long x_stride
    , long y_stride
    , long z_stride);
#define OIIO_ImageBuf_reset_wrap_buffer OpenImageIO_v2_3_6__ImageBuf_reset_wrap_buffer


/** Make the ImageBuf be writable. That means that if it was previously
backed by an ImageCache (storage was `IMAGECACHE`), it will force a
full read so that the whole image is in local memory. This will
invalidate any current iterators on the image. It has no effect if
the image storage is not `IMAGECACHE`.

@param keep_cache_type
            If true, preserve any ImageCache-forced data types (you
            might want to do this if it is critical that the
            apparent data type doesn't change, for example if you
            are calling `make_writable()` from within a
            type-specialized function).
@returns
            Return `true` if it works (including if no read was
            necessary), `false` if something went horribly wrong. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_make_writable(
    OIIO_ImageBuf_t * this_
    , _Bool * return_
    , _Bool keep_cache_type);
#define OIIO_ImageBuf_make_writable OpenImageIO_v2_3_6__ImageBuf_make_writable


/** Read the particular subimage and MIP level of the image.  Generally,
this will skip the expensive read if the file has already been read
into the ImageBuf (at the specified subimage and MIP level).  It
will clear and re-allocate memory if the previously allocated space
was not appropriate for the size or data type of the image being
read.

In general, `read()` will try not to do any I/O at the time of the
`read()` call, but rather to have the ImageBuf "backed" by an
ImageCache, which will do the file I/O on demand, as pixel values
are needed, and in that case the ImageBuf doesn't actually allocate
memory for the pixels (the data lives in the ImageCache).  However,
there are several conditions for which the ImageCache will be
bypassed, the ImageBuf will allocate "local" memory, and the disk
file will be read directly into allocated buffer at the time of the
`read()` call: (a) if the `force` parameter is `true`; (b) if the
`convert` parameter requests a data format conversion to a type that
is not the native file type and also is not one of the internal
types supported by the ImageCache (specifically, `float` and
`UINT8`); (c) if the ImageBuf already has local pixel memory
allocated, or "wraps" an application buffer.

Note that `read()` is not strictly necessary. If you are happy with
the filename, subimage and MIP level specified by the ImageBuf
constructor (or the last call to `reset()`), and you want the
storage to be backed by the ImageCache (including storing the
pixels in whatever data format that implies), then the file contents
will be automatically read the first time you make any other
ImageBuf API call that requires the spec or pixel values.  The only
reason to call `read()` yourself is if you are changing the
filename, subimage, or MIP level, or if you want to use `force =
true` or a specific `convert` value to force data format conversion.

@param  subimage/miplevel
            The subimage and MIP level to read.
@param  force
            If `true`, will force an immediate full read into
            ImageBuf-owned local pixel memory (yielding a
            `LOCALPIXELS` storage buffer). Otherwise, it is up to
            the implementation whether to immediately read or have
            the image backed by an ImageCache (storage
            `IMAGECACHE`.)
@param  convert
            If set to a specific type (not`UNKNOWN`), the ImageBuf
            memory will be allocated for that type specifically and
            converted upon read.
@param  progress_callback/progress_callback_data
            If `progress_callback` is non-NULL, the underlying
            read, if expensive, may make several calls to
                `progress_callback(progress_callback_data, portion_done)`
            which allows you to implement some sort of progress
            meter. Note that if the ImageBuf is backed by an
            ImageCache, the progress callback will never be called,
            since no actual file I/O will occur at this time
            (ImageCache will load tiles or scanlines on demand, as
            individual pixel values are needed).

@returns
            `true` upon success, or `false` if the read failed (in
            which case, you should be able to retrieve an error
            message via `geterror()`). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_read(
    OIIO_ImageBuf_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , _Bool force
    , OIIO_TypeDesc_t convert
    , OIIO_ProgressCallback_t progress_callback
    , void * progress_callback_data);
#define OIIO_ImageBuf_read OpenImageIO_v2_3_6__ImageBuf_read


/** Read the file, if possible only allocating and reading a subset of
channels, `[chbegin..chend-1]`. This can be a performance and memory
improvement for some image file formats, if you know that any use of
the ImageBuf will only access a subset of channels from a
many-channel file.

Additional parameters:

@param  chbegin/chend
            The subset (a range with "exclusive end") of channels to
            read, if the implementation is able to read only a
            subset of channels and have a performance advantage by
            doing so. If `chbegin` is 0 and `chend` is either
            negative or greater than the number of channels in the
            file, all channels will be read. Please note that it is
            "advisory" and not guaranteed to be honored by the
            underlying implementation. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_read_channels(
    OIIO_ImageBuf_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , int chbegin
    , int chend
    , _Bool force
    , OIIO_TypeDesc_t convert
    , OIIO_ProgressCallback_t progress_callback
    , void * progress_callback_data);
#define OIIO_ImageBuf_read_channels OpenImageIO_v2_3_6__ImageBuf_read_channels


/** Read the ImageSpec for the given file, subimage, and MIP level into
the ImageBuf, but will not read the pixels or allocate any local
storage (until a subsequent call to `read()`).  This is helpful if
you have an ImageBuf and you need to know information about the
image, but don't want to do a full read yet, and maybe won't need to
do the full read, depending on what's found in the spec.

Note that `init_spec()` is not strictly necessary. If you are happy
with the filename, subimage and MIP level specified by the ImageBuf
constructor (or the last call to `reset()`), then the spec will be
automatically read the first time you make any other ImageBuf API
call that requires it. The only reason to call `read()` yourself is
if you are changing the filename, subimage, or MIP level, or if you
want to use `force=true` or a specific `convert` value to force
data format conversion.

@param  filename
            The filename to read from (should be the same as the
            filename used when the ImageBuf was constructed or
            reset.)
@param  subimage/miplevel
            The subimage and MIP level to read.

@returns
            `true` upon success, or `false` if the read failed (in
            which case, you should be able to retrieve an error
            message via `geterror()`). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_init_spec(
    OIIO_ImageBuf_t * this_
    , _Bool * return_
    , OIIO_string_view_t filename
    , int subimage
    , int miplevel);
#define OIIO_ImageBuf_init_spec OpenImageIO_v2_3_6__ImageBuf_init_spec


/** Write the image to the named file, converted to the specified pixel
data type `dtype` (`TypeUnknown` signifies to use the data type of
the buffer), and file format (an empty `fileformat` means to infer
the type from the filename extension).

By default, it will always try to write a scanline-oriented file,
unless the `set_write_tiles()` method has been used to override
this.

@param  filename
            The filename to write to.
@param  dtype
            Optional override of the pixel data format to use in the
            file being written. The default (`UNKNOWN`) means to try
            writing the same data format that as pixels are stored
            within the ImageBuf memory (or whatever type was
            specified by a prior call to `set_write_format()`). In
            either case, if the file format does not support that
            data type, another will be automatically chosen that is
            supported by the file type and loses as little precision
            as possible.
@param  fileformat
            Optional override of the file format to write. The
            default (empty string) means to infer the file format
            from the extension of the `filename` (for
            example, "foo.tif" will write a TIFF file).
@param  progress_callback/progress_callback_data
            If `progress_callback` is non-NULL, the underlying
            write, if expensive, may make several calls to
                `progress_callback(progress_callback_data, portion_done)`
            which allows you to implement some sort of progress
            meter.

@returns
            `true` upon success, or `false` if the write failed (in
            which case, you should be able to retrieve an error
            message via `geterror()`). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_write(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_
    , OIIO_string_view_t filename
    , OIIO_TypeDesc_t dtype
    , OIIO_string_view_t fileformat
    , OIIO_ProgressCallback_t progress_callback
    , void * progress_callback_data);
#define OIIO_ImageBuf_write OpenImageIO_v2_3_6__ImageBuf_write


/** Set the pixel data format that will be used for subsequent `write()`
calls that do not themselves request a specific data type request.

Note that this does not affect the variety of `write()` that takes
an open `ImageOutput*` as a parameter.

@param  format
            The data type to be used for all channels. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_set_write_format(
    OIIO_ImageBuf_t * this_
    , OIIO_TypeDesc_t format);
#define OIIO_ImageBuf_set_write_format OpenImageIO_v2_3_6__ImageBuf_set_write_format


/** Set the per-channel pixel data format that will be used for
subsequent `write()` calls that do not themselves request a specific
data type request.

@param  format
            The type of each channel (in order). Any channel's
            format specified as `TypeUnknown` will default to be
            whatever type is described in the ImageSpec of the
            buffer. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_set_write_format_per_channel(
    OIIO_ImageBuf_t * this_
    , OIIO_cspan_TypeDesc_t format);
#define OIIO_ImageBuf_set_write_format_per_channel OpenImageIO_v2_3_6__ImageBuf_set_write_format_per_channel


/** Override the tile sizing for subsequent calls to the `write()`
method (the variety that does not take an open `ImageOutput*`).
Setting all three dimensions to 0 indicates that the output should
be a scanline-oriented file.

This lets you write a tiled file from an ImageBuf that may have been
read originally from a scanline file, or change the dimensions of a
tiled file, or to force the file written to be scanline even if it
was originally read from a tiled file.

In all cases, if the file format ultimately written does not support
tiling, or the tile dimensions requested, a suitable supported
tiling choice will be made automatically. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_set_write_tiles(
    OIIO_ImageBuf_t * this_
    , int width
    , int height
    , int depth);
#define OIIO_ImageBuf_set_write_tiles OpenImageIO_v2_3_6__ImageBuf_set_write_tiles


/** Supply an IOProxy to use for a subsequent call to `write()`.

If a proxy is set but it later turns out that the file format
selected does not support write proxies, then `write()` will fail
with an error. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_set_write_ioproxy(
    OIIO_ImageBuf_t * this_
    , OIIO_Filesystem_IOProxy_t * ioproxy);
#define OIIO_ImageBuf_set_write_ioproxy OpenImageIO_v2_3_6__ImageBuf_set_write_ioproxy


/** Write the pixels of the ImageBuf to an open ImageOutput. The
ImageOutput must have already been opened with a spec that indicates
a resolution identical to that of this ImageBuf (but it may have
specified a different pixel data type, in which case data
conversions will happen automatically). This method does NOT close
the file when it's done (and so may be called in a loop to write a
multi-image file).

Note that since this uses an already-opened `ImageOutput`, which is
too late to change how it was opened, it does not honor any prior
calls to `set_write_format` or `set_write_tiles`.

The main application of this method is to allow an ImageBuf (which
by design may hold only a *single* image) to be used for the output
of one image of a multi-subimage and/or MIP-mapped image file.

@param  out
            A pointer to an already-opened `ImageOutput` to which
            the pixels of the ImageBuf will be written.
@param  progress_callback/progress_callback_data
            If `progress_callback` is non-NULL, the underlying
            write, if expensive, may make several calls to
                `progress_callback(progress_callback_data, portion_done)`
            which allows you to implement some sort of progress
            meter.
@returns  `true` if all went ok, `false` if there were errors
          writing. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_write_to_imageoutput(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_
    , OIIO_ImageOutput_t * out
    , OIIO_ProgressCallback_t progress_callback
    , void * progress_callback_data);
#define OIIO_ImageBuf_write_to_imageoutput OpenImageIO_v2_3_6__ImageBuf_write_to_imageoutput


/** Copy assignment. */
unsigned int OpenImageIO_v2_3_6__ImageBuf__assign(
    OIIO_ImageBuf_t * this_
    , OIIO_ImageBuf_t const * * return_
    , OIIO_ImageBuf_t const * src);
#define OIIO_ImageBuf__assign OpenImageIO_v2_3_6__ImageBuf__assign


/** Copy all the metadata from `src` to `*this` (except for pixel data
resolution, channel types and names, and data format). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_copy_metadata(
    OIIO_ImageBuf_t * this_
    , OIIO_ImageBuf_t const * src);
#define OIIO_ImageBuf_copy_metadata OpenImageIO_v2_3_6__ImageBuf_copy_metadata


/** Copy the pixel data from `src` to `*this`, automatically converting
to the existing data format of `*this`.  It only copies pixels in
the overlap regions (and channels) of the two images; pixel data in
`*this` that do exist in `src` will be set to 0, and pixel data in
`src` that do not exist in `*this` will not be copied. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_copy_pixels(
    OIIO_ImageBuf_t * this_
    , _Bool * return_
    , OIIO_ImageBuf_t const * src);
#define OIIO_ImageBuf_copy_pixels OpenImageIO_v2_3_6__ImageBuf_copy_pixels


/** Try to copy the pixels and metadata from `src` to `*this`
(optionally with an explicit data format conversion).

If the previous state of `*this` was uninitialized, owning its own
local pixel memory, or referring to a read-only image backed by
ImageCache, then local pixel memory will be allocated to hold the
new pixels and the call always succeeds unless the memory cannot be
allocated. In this case, the `format` parameter may request a pixel
data type that is different from that of the source buffer.

If `*this` previously referred to an app-owned memory buffer, the
memory cannot be re-allocated, so the call will only succeed if the
app-owned buffer is already the correct resolution and number of
channels.  The data type of the pixels will be converted
automatically to the data type of the app buffer.

@param  src
            Another ImageBuf from which to copy the pixels and
            metadata.
@param  format
            Optionally request the pixel data type to be used. The
            default of `TypeUnknown` means to use whatever data type
            is used by the `src`. If `*this` is already initialized
            and has `APPBUFFER` storage ("wrapping" an application
            buffer), this parameter is ignored.
@returns
            `true` upon success or `false` upon error/failure. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_copy_from(
    OIIO_ImageBuf_t * this_
    , _Bool * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_TypeDesc_t format);
#define OIIO_ImageBuf_copy_from OpenImageIO_v2_3_6__ImageBuf_copy_from


/** Return a full copy of `this` ImageBuf (optionally with an explicit
data format conversion). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_clone(
    OIIO_ImageBuf_t const * this_
    , OIIO_ImageBuf_t * * return_
    , OIIO_TypeDesc_t format);
#define OIIO_ImageBuf_clone OpenImageIO_v2_3_6__ImageBuf_clone


/** Swap the entire contents with another ImageBuf. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_swap(
    OIIO_ImageBuf_t * this_
    , OIIO_ImageBuf_t * other);
#define OIIO_ImageBuf_swap OpenImageIO_v2_3_6__ImageBuf_swap


/** Retrieve a single channel of one pixel.

@param x/y/z
            The pixel coordinates.
@param c
            The channel index to retrieve.
@param wrap
            WrapMode that determines the behavior if the pixel
            coordinates are outside the data window: `WrapBlack`,
            `WrapClamp`, `WrapPeriodic`, `WrapMirror`.
@returns
           The data value, converted to a `float`. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_getchannel(
    OIIO_ImageBuf_t const * this_
    , float * return_
    , int x
    , int y
    , int z
    , int c
    , OIIO_ImageBuf_WrapMode wrap);
#define OIIO_ImageBuf_getchannel OpenImageIO_v2_3_6__ImageBuf_getchannel


/** Retrieve the pixel value by x, y, z pixel indices, placing its
contents in `pixel[0..n-1]` where *n* is the smaller of
`maxchannels` the actual number of channels stored in the buffer.

@param x/y/z
            The pixel coordinates.
@param pixel
            The results are stored in `pixel[0..nchannels-1]`. It is
            up to the caller to ensure that `pixel` points to enough
            memory to hold the required number of channels.
@param maxchannels
            Optional clamp to the number of channels retrieved.
@param wrap
            WrapMode that determines the behavior if the pixel
            coordinates are outside the data window: `WrapBlack`,
            `WrapClamp`, `WrapPeriodic`, `WrapMirror`. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_getpixel_3d(
    OIIO_ImageBuf_t const * this_
    , int x
    , int y
    , int z
    , float * pixel
    , int maxchannels
    , OIIO_ImageBuf_WrapMode wrap);
#define OIIO_ImageBuf_getpixel_3d OpenImageIO_v2_3_6__ImageBuf_getpixel_3d


unsigned int OpenImageIO_v2_3_6__ImageBuf_getpixel(
    OIIO_ImageBuf_t const * this_
    , int x
    , int y
    , float * pixel
    , int maxchannels);
#define OIIO_ImageBuf_getpixel OpenImageIO_v2_3_6__ImageBuf_getpixel


/** Sample the image plane at pixel coordinates (x,y), using linear
interpolation between pixels, placing the result in `pixel[]`.

@param x/y
            The pixel coordinates. Note that pixel data values
            themselves are at the pixel centers, so pixel (i,j) is
            at image plane coordinate (i+0.5, j+0.5).
@param pixel
            The results are stored in `pixel[0..nchannels-1]`. It is
            up to the caller to ensure that `pixel` points to enough
            memory to hold the number of channels in the image.
@param wrap
            WrapMode that determines the behavior if the pixel
            coordinates are outside the data window: `WrapBlack`,
            `WrapClamp`, `WrapPeriodic`, `WrapMirror`. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_interppixel(
    OIIO_ImageBuf_t const * this_
    , float x
    , float y
    , float * pixel
    , OIIO_ImageBuf_WrapMode wrap);
#define OIIO_ImageBuf_interppixel OpenImageIO_v2_3_6__ImageBuf_interppixel


/** Linearly interpolate at NDC coordinates (s,t), where (0,0) is
the upper left corner of the display window, (1,1) the lower
right corner of the display window.

@note `interppixel()` uses pixel coordinates (ranging 0..resolution)
whereas `interppixel_NDC()` uses NDC coordinates (ranging 0..1). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_interppixel_NDC(
    OIIO_ImageBuf_t const * this_
    , float s
    , float t
    , float * pixel
    , OIIO_ImageBuf_WrapMode wrap);
#define OIIO_ImageBuf_interppixel_NDC OpenImageIO_v2_3_6__ImageBuf_interppixel_NDC


unsigned int OpenImageIO_v2_3_6__ImageBuf_interppixel_NDC_full(
    OIIO_ImageBuf_t const * this_
    , float s
    , float t
    , float * pixel
    , OIIO_ImageBuf_WrapMode wrap);
#define OIIO_ImageBuf_interppixel_NDC_full OpenImageIO_v2_3_6__ImageBuf_interppixel_NDC_full


/** Bicubic interpolation at pixel coordinates (x,y). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_interppixel_bicubic(
    OIIO_ImageBuf_t const * this_
    , float x
    , float y
    , float * pixel
    , OIIO_ImageBuf_WrapMode wrap);
#define OIIO_ImageBuf_interppixel_bicubic OpenImageIO_v2_3_6__ImageBuf_interppixel_bicubic


/** Bicubic interpolation at NDC space coordinates (s,t), where (0,0)
is the upper left corner of the display (a.k.a. "full") window,
(1,1) the lower right corner of the display window. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_interppixel_bicubic_NDC(
    OIIO_ImageBuf_t const * this_
    , float s
    , float t
    , float * pixel
    , OIIO_ImageBuf_WrapMode wrap);
#define OIIO_ImageBuf_interppixel_bicubic_NDC OpenImageIO_v2_3_6__ImageBuf_interppixel_bicubic_NDC


/** Set the pixel with coordinates (x,y,0) to have the values in span
`pixel[]`.  The number of channels copied is the minimum of the span
length and the actual number of channels in the image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_setpixel_span(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , OIIO_cspan_float_t pixel);
#define OIIO_ImageBuf_setpixel_span OpenImageIO_v2_3_6__ImageBuf_setpixel_span


/** Set the pixel with coordinates (x,y,z) to have the values in span
`pixel[]`.  The number of channels copied is the minimum of the span
length and the actual number of channels in the image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_setpixel_3d_span(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , int z
    , OIIO_cspan_float_t pixel);
#define OIIO_ImageBuf_setpixel_3d_span OpenImageIO_v2_3_6__ImageBuf_setpixel_3d_span


/** Set the `i`-th pixel value of the image (out of width*height*depth),
from floating-point values in span `pixel[]`.  The number of
channels copied is the minimum of the span length and the actual
number of channels in the image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_setpixel_at_index_span(
    OIIO_ImageBuf_t * this_
    , int i
    , OIIO_cspan_float_t pixel);
#define OIIO_ImageBuf_setpixel_at_index_span OpenImageIO_v2_3_6__ImageBuf_setpixel_at_index_span


/** Set the pixel with coordinates (x,y,0) to have the values in
pixel[0..n-1].  The number of channels copied, n, is the minimum
of maxchannels and the actual number of channels in the image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_setpixel(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , float const * pixel
    , int maxchannels);
#define OIIO_ImageBuf_setpixel OpenImageIO_v2_3_6__ImageBuf_setpixel


/** Set the pixel with coordinates (x,y,z) to have the values in
`pixel[0..n-1]`.  The number of channels copied, n, is the minimum
of `maxchannels` and the actual number of channels in the image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_setpixel_3d(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , int z
    , float const * pixel
    , int maxchannels);
#define OIIO_ImageBuf_setpixel_3d OpenImageIO_v2_3_6__ImageBuf_setpixel_3d


/** Set the `i`-th pixel value of the image (out of width*height*depth),
from floating-point values in `pixel[]`.  Set at most
`maxchannels` (will be clamped to the actual number of channels). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_setpixel_at_index(
    OIIO_ImageBuf_t * this_
    , int i
    , float const * pixel
    , int maxchannels);
#define OIIO_ImageBuf_setpixel_at_index OpenImageIO_v2_3_6__ImageBuf_setpixel_at_index


/** Retrieve the rectangle of pixels spanning the ROI (including
channels) at the current subimage and MIP-map level, storing the
pixel values beginning at the address specified by result and with
the given strides (by default, AutoStride means the usual contiguous
packing of pixels) and converting into the data type described by
`format`.  It is up to the caller to ensure that result points to an
area of memory big enough to accommodate the requested rectangle.
Return true if the operation could be completed, otherwise return
false. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_get_pixels(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_
    , OIIO_ROI_t roi
    , OIIO_TypeDesc_t format
    , void * result
    , long xstride
    , long ystride
    , long zstride);
#define OIIO_ImageBuf_get_pixels OpenImageIO_v2_3_6__ImageBuf_get_pixels


/** Copy the data into the given ROI of the ImageBuf. The data points to
values specified by `format`, with layout detailed by the stride
values (in bytes, with AutoStride indicating "contiguous" layout).
It is up to the caller to ensure that data points to an area of
memory big enough to account for the ROI. Return true if the
operation could be completed, otherwise return false. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_set_pixels(
    OIIO_ImageBuf_t * this_
    , _Bool * return_
    , OIIO_ROI_t roi
    , OIIO_TypeDesc_t format
    , void const * data
    , long xstride
    , long ystride
    , long zstride);
#define OIIO_ImageBuf_set_pixels OpenImageIO_v2_3_6__ImageBuf_set_pixels


/** Returns `true` if the ImageBuf is initialized, `false` if not yet
initialized. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_initialized(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_);
#define OIIO_ImageBuf_initialized OpenImageIO_v2_3_6__ImageBuf_initialized


/** Which type of storage is being used for the pixels? Returns an
enumerated type describing the type of storage currently employed by
the ImageBuf: `UNINITIALIZED` (no storage), `LOCALBUFFER` (the
ImageBuf has allocated and owns the pixel memory), `APPBUFFER` (the
ImageBuf "wraps" memory owned by the calling application), or
`IMAGECACHE` (the image is backed by an ImageCache). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_storage(
    OIIO_ImageBuf_t const * this_
    , OIIO_ImageBuf_IBStorage * return_);
#define OIIO_ImageBuf_storage OpenImageIO_v2_3_6__ImageBuf_storage


/** Return a read-only (const) reference to the image spec that
describes the buffer. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_spec(
    OIIO_ImageBuf_t const * this_
    , OIIO_ImageSpec_t const * * return_);
#define OIIO_ImageBuf_spec OpenImageIO_v2_3_6__ImageBuf_spec


/** Return a writable reference to the ImageSpec that describes the
buffer.  It's ok to modify most of the metadata, but if you modify
the spec's `format`, `width`, `height`, or `depth` fields, you get
the pain you deserve, as the ImageBuf will no longer have correct
knowledge of its pixel memory layout.  USE WITH EXTREME CAUTION. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_specmod(
    OIIO_ImageBuf_t * this_
    , OIIO_ImageSpec_t * * return_);
#define OIIO_ImageBuf_specmod OpenImageIO_v2_3_6__ImageBuf_specmod


/** Return a read-only (const) reference to the "native" image spec
(that describes the file, which may be slightly different than
the spec of the ImageBuf, particularly if the IB is backed by an
ImageCache that is imposing some particular data format or tile
size).

This may differ from `spec()` --- for example, if a data format
conversion was requested, if the buffer is backed by an ImageCache
which stores the pixels internally in a different data format than
that of the file, or if the file had differing per-channel data
formats (ImageBuf must contain a single data format for all
channels). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_nativespec(
    OIIO_ImageBuf_t const * this_
    , OIIO_ImageSpec_t const * * return_);
#define OIIO_ImageBuf_nativespec OpenImageIO_v2_3_6__ImageBuf_nativespec


/** Returns the name of the buffer (name of the file, for an ImageBuf
read from disk). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_name(
    OIIO_ImageBuf_t const * this_
    , OIIO_string_view_t * return_);
#define OIIO_ImageBuf_name OpenImageIO_v2_3_6__ImageBuf_name


/** Return the name of the image file format of the file this ImageBuf
refers to (for example `"openexr"`).  Returns an empty string for an
ImageBuf that was not constructed as a direct reference to a file. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_file_format_name(
    OIIO_ImageBuf_t const * this_
    , OIIO_string_view_t * return_);
#define OIIO_ImageBuf_file_format_name OpenImageIO_v2_3_6__ImageBuf_file_format_name


/** Return the index of the subimage within the file that the ImageBuf
refers to. This will always be 0 for an ImageBuf that was not
constructed as a direct reference to a file, or if the file
contained only one image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_subimage(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_subimage OpenImageIO_v2_3_6__ImageBuf_subimage


/** Return the number of subimages in the file this ImageBuf refers to.
This will always be 1 for an ImageBuf that was not constructed as a
direct reference to a file. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_nsubimages(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_nsubimages OpenImageIO_v2_3_6__ImageBuf_nsubimages


/** Return the index of the miplevel with a file's subimage that the
ImageBuf is currently holding. This will always be 0 for an ImageBuf
that was not constructed as a direct reference to a file, or if the
subimage within that file was not MIP-mapped. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_miplevel(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_miplevel OpenImageIO_v2_3_6__ImageBuf_miplevel


/** Return the number of MIP levels of the current subimage within the
file this ImageBuf refers to. This will always be 1 for an ImageBuf
that was not constructed as a direct reference to a file, or if this
subimage within the file was not MIP-mapped. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_nmiplevels(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_nmiplevels OpenImageIO_v2_3_6__ImageBuf_nmiplevels


/** Return the number of color channels in the image. This is equivalent
to `spec().nchannels`. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_nchannels(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_nchannels OpenImageIO_v2_3_6__ImageBuf_nchannels


/** Return the beginning (minimum) x coordinate of the defined image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_xbegin(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_xbegin OpenImageIO_v2_3_6__ImageBuf_xbegin


/** Return the end (one past maximum) x coordinate of the defined image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_xend(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_xend OpenImageIO_v2_3_6__ImageBuf_xend


/** Return the beginning (minimum) y coordinate of the defined image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_ybegin(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_ybegin OpenImageIO_v2_3_6__ImageBuf_ybegin


/** Return the end (one past maximum) y coordinate of the defined image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_yend(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_yend OpenImageIO_v2_3_6__ImageBuf_yend


/** Return the beginning (minimum) z coordinate of the defined image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_zbegin(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_zbegin OpenImageIO_v2_3_6__ImageBuf_zbegin


/** Return the end (one past maximum) z coordinate of the defined image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_zend(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_zend OpenImageIO_v2_3_6__ImageBuf_zend


/** Return the minimum x coordinate of the defined image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_xmin(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_xmin OpenImageIO_v2_3_6__ImageBuf_xmin


/** Return the maximum x coordinate of the defined image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_xmax(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_xmax OpenImageIO_v2_3_6__ImageBuf_xmax


/** Return the minimum y coordinate of the defined image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_ymin(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_ymin OpenImageIO_v2_3_6__ImageBuf_ymin


/** Return the maximum y coordinate of the defined image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_ymax(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_ymax OpenImageIO_v2_3_6__ImageBuf_ymax


/** Return the minimum z coordinate of the defined image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_zmin(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_zmin OpenImageIO_v2_3_6__ImageBuf_zmin


/** Return the maximum z coordinate of the defined image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_zmax(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_zmax OpenImageIO_v2_3_6__ImageBuf_zmax


/** Return the current `"Orientation"` metadata for the image, per the
table in `sec-metadata-orientation`_ */
unsigned int OpenImageIO_v2_3_6__ImageBuf_orientation(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_orientation OpenImageIO_v2_3_6__ImageBuf_orientation


/** Set the `"Orientation"` metadata for the image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_set_orientation(
    OIIO_ImageBuf_t * this_
    , int orient);
#define OIIO_ImageBuf_set_orientation OpenImageIO_v2_3_6__ImageBuf_set_orientation


unsigned int OpenImageIO_v2_3_6__ImageBuf_oriented_width(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_oriented_width OpenImageIO_v2_3_6__ImageBuf_oriented_width


unsigned int OpenImageIO_v2_3_6__ImageBuf_oriented_height(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_oriented_height OpenImageIO_v2_3_6__ImageBuf_oriented_height


unsigned int OpenImageIO_v2_3_6__ImageBuf_oriented_x(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_oriented_x OpenImageIO_v2_3_6__ImageBuf_oriented_x


unsigned int OpenImageIO_v2_3_6__ImageBuf_oriented_y(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_oriented_y OpenImageIO_v2_3_6__ImageBuf_oriented_y


unsigned int OpenImageIO_v2_3_6__ImageBuf_oriented_full_width(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_oriented_full_width OpenImageIO_v2_3_6__ImageBuf_oriented_full_width


unsigned int OpenImageIO_v2_3_6__ImageBuf_oriented_full_height(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_oriented_full_height OpenImageIO_v2_3_6__ImageBuf_oriented_full_height


unsigned int OpenImageIO_v2_3_6__ImageBuf_oriented_full_x(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_oriented_full_x OpenImageIO_v2_3_6__ImageBuf_oriented_full_x


unsigned int OpenImageIO_v2_3_6__ImageBuf_oriented_full_y(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_oriented_full_y OpenImageIO_v2_3_6__ImageBuf_oriented_full_y


/** Alters the metadata of the spec in the ImageBuf to reset the
"origin" of the pixel data window to be the specified coordinates.
This does not affect the size of the pixel data window, only its
position. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_set_origin(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , int z);
#define OIIO_ImageBuf_set_origin OpenImageIO_v2_3_6__ImageBuf_set_origin


/** Set the "full" (a.k.a. display) window to Alters the metadata of the
spec in the ImageBuf to reset the "full" image size (a.k.a.
"display window") to

    [xbegin,xend) x [ybegin,yend) x [zbegin,zend)`

This does not affect the size of the pixel data window. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_set_full(
    OIIO_ImageBuf_t * this_
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend);
#define OIIO_ImageBuf_set_full OpenImageIO_v2_3_6__ImageBuf_set_full


/** Return pixel data window for this ImageBuf as a ROI. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_roi(
    OIIO_ImageBuf_t const * this_
    , OIIO_ROI_t * return_);
#define OIIO_ImageBuf_roi OpenImageIO_v2_3_6__ImageBuf_roi


/** Return full/display window for this ImageBuf as a ROI. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_roi_full(
    OIIO_ImageBuf_t const * this_
    , OIIO_ROI_t * return_);
#define OIIO_ImageBuf_roi_full OpenImageIO_v2_3_6__ImageBuf_roi_full


/** Set full/display window for this ImageBuf to a ROI.
Does NOT change the channels of the spec, regardless of `newroi`. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_set_roi_full(
    OIIO_ImageBuf_t * this_
    , OIIO_ROI_t const * newroi);
#define OIIO_ImageBuf_set_roi_full OpenImageIO_v2_3_6__ImageBuf_set_roi_full


/** Is the specified roi completely contained in the data window of
this ImageBuf? */
unsigned int OpenImageIO_v2_3_6__ImageBuf_contains_roi(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_
    , OIIO_ROI_t roi);
#define OIIO_ImageBuf_contains_roi OpenImageIO_v2_3_6__ImageBuf_contains_roi


unsigned int OpenImageIO_v2_3_6__ImageBuf_pixels_valid(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_);
#define OIIO_ImageBuf_pixels_valid OpenImageIO_v2_3_6__ImageBuf_pixels_valid


/** The data type of the pixels stored in the buffer (equivalent to
`spec().format`). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_pixeltype(
    OIIO_ImageBuf_t const * this_
    , OIIO_TypeDesc_t * return_);
#define OIIO_ImageBuf_pixeltype OpenImageIO_v2_3_6__ImageBuf_pixeltype


/** Return a raw pointer to "local" pixel memory, if they are fully in
RAM and not backed by an ImageCache, or `nullptr` otherwise.  You
can also test it like a bool to find out if pixels are local.

Note that the data are not necessarily contiguous; use the
`pixel_stride()`, `scanline_stride()`, and `z_stride()` methods
to find out the spacing between pixels, scanlines, and volumetric
planes, respectively. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_localpixels(
    OIIO_ImageBuf_t * this_
    , void * * return_);
#define OIIO_ImageBuf_localpixels OpenImageIO_v2_3_6__ImageBuf_localpixels


unsigned int OpenImageIO_v2_3_6__ImageBuf_localpixels_const(
    OIIO_ImageBuf_t const * this_
    , void const * * return_);
#define OIIO_ImageBuf_localpixels_const OpenImageIO_v2_3_6__ImageBuf_localpixels_const


/** Pixel-to-pixel stride within the localpixels memory. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_pixel_stride(
    OIIO_ImageBuf_t const * this_
    , long * return_);
#define OIIO_ImageBuf_pixel_stride OpenImageIO_v2_3_6__ImageBuf_pixel_stride


/** Scanline-to-scanline stride within the localpixels memory. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_scanline_stride(
    OIIO_ImageBuf_t const * this_
    , long * return_);
#define OIIO_ImageBuf_scanline_stride OpenImageIO_v2_3_6__ImageBuf_scanline_stride


/** Z plane stride within the localpixels memory. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_z_stride(
    OIIO_ImageBuf_t const * this_
    , long * return_);
#define OIIO_ImageBuf_z_stride OpenImageIO_v2_3_6__ImageBuf_z_stride


/** Is the data layout "contiguous", i.e.,
```
    pixel_stride == nchannels * pixeltype().size()
    scanline_stride == pixel_stride * spec().width
    z_stride == scanline_stride * spec().height
``` */
unsigned int OpenImageIO_v2_3_6__ImageBuf_contiguous(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_);
#define OIIO_ImageBuf_contiguous OpenImageIO_v2_3_6__ImageBuf_contiguous


/** Are the pixels backed by an ImageCache, rather than the whole
image being in RAM somewhere? */
unsigned int OpenImageIO_v2_3_6__ImageBuf_cachedpixels(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_);
#define OIIO_ImageBuf_cachedpixels OpenImageIO_v2_3_6__ImageBuf_cachedpixels


/** A pointer to the underlying ImageCache. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_imagecache(
    OIIO_ImageBuf_t const * this_
    , OIIO_ImageCache_t * * return_);
#define OIIO_ImageBuf_imagecache OpenImageIO_v2_3_6__ImageBuf_imagecache


/** Return the address where pixel `(x,y,z)`, channel `ch`, is stored in
the image buffer.  Use with extreme caution!  Will return `nullptr`
if the pixel values aren't local in RAM. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_pixeladdr_const(
    OIIO_ImageBuf_t const * this_
    , void const * * return_
    , int x
    , int y
    , int z
    , int ch);
#define OIIO_ImageBuf_pixeladdr_const OpenImageIO_v2_3_6__ImageBuf_pixeladdr_const


unsigned int OpenImageIO_v2_3_6__ImageBuf_pixeladdr(
    OIIO_ImageBuf_t * this_
    , void * * return_
    , int x
    , int y
    , int z
    , int ch);
#define OIIO_ImageBuf_pixeladdr OpenImageIO_v2_3_6__ImageBuf_pixeladdr


/** Return the index of pixel (x,y,z). If check_range is true, return
-1 for an invalid coordinate that is not within the data window. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_pixelindex(
    OIIO_ImageBuf_t const * this_
    , int * return_
    , int x
    , int y
    , int z
    , _Bool check_range);
#define OIIO_ImageBuf_pixelindex OpenImageIO_v2_3_6__ImageBuf_pixelindex


/** Set the threading policy for this ImageBuf, controlling the maximum
amount of parallelizing thread "fan-out" that might occur during
expensive operations. The default of 0 means that the global
`attribute("threads")` value should be used (which itself defaults
to using as many threads as cores).

The main reason to change this value is to set it to 1 to indicate
that the calling thread should do all the work rather than spawning
new threads. That is probably the desired behavior in situations
where the calling application has already spawned multiple worker
threads. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_threads(
    OIIO_ImageBuf_t const * this_
    , int n);
#define OIIO_ImageBuf_threads OpenImageIO_v2_3_6__ImageBuf_threads


/** Retrieve the current thread-spawning policy of this ImageBuf. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_threads_const(
    OIIO_ImageBuf_t const * this_
    , int * return_);
#define OIIO_ImageBuf_threads_const OpenImageIO_v2_3_6__ImageBuf_threads_const


/** Add simple string to the error message list for this IB. It is not
necessary to have the error message contain a trailing newline. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_error(
    OIIO_ImageBuf_t const * this_
    , OIIO_string_view_t message);
#define OIIO_ImageBuf_error OpenImageIO_v2_3_6__ImageBuf_error


/** Returns `true` if the ImageBuf has had an error and has an error
message ready to retrieve via `geterror()`. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_has_error(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_);
#define OIIO_ImageBuf_has_error OpenImageIO_v2_3_6__ImageBuf_has_error


/** Return the text of all pending error messages issued against this
ImageBuf, and clear the pending error message unless `clear` is
false. If no error message is pending, it will return an empty
string. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_geterror(
    OIIO_ImageBuf_t const * this_
    , std_string_t * * return_
    , _Bool clear);
#define OIIO_ImageBuf_geterror OpenImageIO_v2_3_6__ImageBuf_geterror


/** Does this ImageBuf store deep data? Returns `true` if the ImageBuf
holds a "deep" image, `false` if the ImageBuf holds an ordinary
pixel-based image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_deep(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_);
#define OIIO_ImageBuf_deep OpenImageIO_v2_3_6__ImageBuf_deep


/** Retrieve the number of deep data samples corresponding to pixel
(x,y,z).  Return 0 if not a deep image, or if the pixel is outside
of the data window, or if the designated pixel has no deep samples. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_deep_samples(
    OIIO_ImageBuf_t const * this_
    , int * return_
    , int x
    , int y
    , int z);
#define OIIO_ImageBuf_deep_samples OpenImageIO_v2_3_6__ImageBuf_deep_samples


/** Return a pointer to the raw data of pixel `(x,y,z)`, channel `c`,
sample `s`. Return `nullptr` if the pixel coordinates or channel
number are out of range, if the pixel/channel has no deep samples,
or if the image is not deep. Use with caution --- these pointers may
be invalidated by calls that adjust the number of samples in any
pixel. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_deep_pixel_ptr(
    OIIO_ImageBuf_t const * this_
    , void const * * return_
    , int x
    , int y
    , int z
    , int c
    , int s);
#define OIIO_ImageBuf_deep_pixel_ptr OpenImageIO_v2_3_6__ImageBuf_deep_pixel_ptr


/** Return the value (as a `float`) of sample `s` of channel `c` of
pixel `(x,y,z)`.  Return 0 if not a deep image or if the pixel
coordinates or channel number are out of range or if that pixel has
no deep samples. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_deep_value(
    OIIO_ImageBuf_t const * this_
    , float * return_
    , int x
    , int y
    , int z
    , int c
    , int s);
#define OIIO_ImageBuf_deep_value OpenImageIO_v2_3_6__ImageBuf_deep_value


/** Return the value (as a `uint32_t`) of sample `s` of channel `c` of
pixel `(x,y,z)`.  Return 0 if not a deep image or if the pixel
coordinates or channel number are out of range or if that pixel has
no deep samples. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_deep_value_uint(
    OIIO_ImageBuf_t const * this_
    , unsigned int * return_
    , int x
    , int y
    , int z
    , int c
    , int s);
#define OIIO_ImageBuf_deep_value_uint OpenImageIO_v2_3_6__ImageBuf_deep_value_uint


/** Set the number of deep samples for pixel (x,y,z).  If data has
already been allocated, this is equivalent to inserting or erasing
samples. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_set_deep_samples(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , int z
    , int nsamples);
#define OIIO_ImageBuf_set_deep_samples OpenImageIO_v2_3_6__ImageBuf_set_deep_samples


/** Insert `nsamples` new samples, starting at position `samplepos` of
pixel (x,y,z). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_deep_insert_samples(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , int z
    , int samplepos
    , int nsamples);
#define OIIO_ImageBuf_deep_insert_samples OpenImageIO_v2_3_6__ImageBuf_deep_insert_samples


/** Remove `nsamples` samples, starting at position `samplepos` of pixel
(x,y,z). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_deep_erase_samples(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , int z
    , int samplepos
    , int nsamples);
#define OIIO_ImageBuf_deep_erase_samples OpenImageIO_v2_3_6__ImageBuf_deep_erase_samples


/** Set the value of sample `s` of channel `c` of pixel `(x,y,z)` to a
`float` value (it is expected that channel `c` is a floating point
type). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_set_deep_value(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , int z
    , int c
    , int s
    , float value);
#define OIIO_ImageBuf_set_deep_value OpenImageIO_v2_3_6__ImageBuf_set_deep_value


/** Set the value of sample `s` of channel `c` of pixel `(x,y,z)` to a
`uint32_t` value (it is expected that channel `c` is an integer
type). */
unsigned int OpenImageIO_v2_3_6__ImageBuf_set_deep_value_uint(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , int z
    , int c
    , int s
    , unsigned int value);
#define OIIO_ImageBuf_set_deep_value_uint OpenImageIO_v2_3_6__ImageBuf_set_deep_value_uint


/** Copy a deep pixel from another ImageBuf -- it is required to have
the same channels. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_copy_deep_pixel(
    OIIO_ImageBuf_t * this_
    , _Bool * return_
    , int x
    , int y
    , int z
    , OIIO_ImageBuf_t const * src
    , int srcx
    , int srcy
    , int srcz);
#define OIIO_ImageBuf_copy_deep_pixel OpenImageIO_v2_3_6__ImageBuf_copy_deep_pixel


/** Retrieve the "deep" data. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_deepdata(
    OIIO_ImageBuf_t * this_
    , OIIO_DeepData_t * * return_);
#define OIIO_ImageBuf_deepdata OpenImageIO_v2_3_6__ImageBuf_deepdata


unsigned int OpenImageIO_v2_3_6__ImageBuf_deepdata_const(
    OIIO_ImageBuf_t const * this_
    , OIIO_DeepData_t const * * return_);
#define OIIO_ImageBuf_deepdata_const OpenImageIO_v2_3_6__ImageBuf_deepdata_const


/** Return the `WrapMode` corresponding to the name (`"default"`,
`"black"`, `"clamp"`, `"periodic"`, `"mirror"`). For an unknown
name, this will return `WrapDefault`. */
unsigned int OpenImageIO_v2_3_6__ImageBuf_WrapMode_from_string(
    OIIO_ImageBuf_WrapMode * return_
    , OIIO_string_view_t name);
#define OIIO_ImageBuf_WrapMode_from_string OpenImageIO_v2_3_6__ImageBuf_WrapMode_from_string


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_sizeof();
#define OIIO_ImageBuf_IteratorBase_sizeof OpenImageIO_v2_3_6__ImageBuf__IteratorBase_sizeof


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_alignof();
#define OIIO_ImageBuf_IteratorBase_alignof OpenImageIO_v2_3_6__ImageBuf__IteratorBase_alignof


unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_with_wrapmode(
    OIIO_ImageBuf_IteratorBase_t * this_
    , OIIO_ImageBuf_t const * ib
    , OIIO_ImageBuf_WrapMode wrap);
#define OIIO_ImageBuf_IteratorBase_with_wrapmode OpenImageIO_v2_3_6__ImageBuf__IteratorBase_with_wrapmode


/** Construct valid iteration region from ImageBuf and ROI. */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_with_roi(
    OIIO_ImageBuf_IteratorBase_t * this_
    , OIIO_ImageBuf_t const * ib
    , OIIO_ROI_t const * roi
    , OIIO_ImageBuf_WrapMode wrap);
#define OIIO_ImageBuf_IteratorBase_with_roi OpenImageIO_v2_3_6__ImageBuf__IteratorBase_with_roi


/** Construct from an ImageBuf and designated region -- iterate
over region, starting with the upper left pixel. */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_with_range(
    OIIO_ImageBuf_IteratorBase_t * this_
    , OIIO_ImageBuf_t const * ib
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend
    , OIIO_ImageBuf_WrapMode wrap);
#define OIIO_ImageBuf_IteratorBase_with_range OpenImageIO_v2_3_6__ImageBuf__IteratorBase_with_range


unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_copy(
    OIIO_ImageBuf_IteratorBase_t * this_
    , OIIO_ImageBuf_IteratorBase_t const * i);
#define OIIO_ImageBuf_IteratorBase_copy OpenImageIO_v2_3_6__ImageBuf__IteratorBase_copy


unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_dtor(
    OIIO_ImageBuf_IteratorBase_t * this_);
#define OIIO_ImageBuf_IteratorBase_dtor OpenImageIO_v2_3_6__ImageBuf__IteratorBase_dtor


/** Assign one IteratorBase to another */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_assign_base(
    OIIO_ImageBuf_IteratorBase_t * this_
    , OIIO_ImageBuf_IteratorBase_t const * * return_
    , OIIO_ImageBuf_IteratorBase_t const * i);
#define OIIO_ImageBuf_IteratorBase_assign_base OpenImageIO_v2_3_6__ImageBuf__IteratorBase_assign_base


/** Retrieve the current x location of the iterator. */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_x(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , int * return_);
#define OIIO_ImageBuf_IteratorBase_x OpenImageIO_v2_3_6__ImageBuf__IteratorBase_x


/** Retrieve the current y location of the iterator. */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_y(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , int * return_);
#define OIIO_ImageBuf_IteratorBase_y OpenImageIO_v2_3_6__ImageBuf__IteratorBase_y


/** Retrieve the current z location of the iterator. */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_z(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , int * return_);
#define OIIO_ImageBuf_IteratorBase_z OpenImageIO_v2_3_6__ImageBuf__IteratorBase_z


/** Is the current location within the designated iteration range? */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_valid(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , _Bool * return_);
#define OIIO_ImageBuf_IteratorBase_valid OpenImageIO_v2_3_6__ImageBuf__IteratorBase_valid


/** Is the location (x,y[,z]) within the designated iteration
range? */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_valid_at_index(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , _Bool * return_
    , int x_
    , int y_
    , int z_);
#define OIIO_ImageBuf_IteratorBase_valid_at_index OpenImageIO_v2_3_6__ImageBuf__IteratorBase_valid_at_index


/** Is the location (x,y[,z]) within the region of the ImageBuf
that contains pixel values (sometimes called the "data window")? */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_exists_at_index(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , _Bool * return_
    , int x_
    , int y_
    , int z_);
#define OIIO_ImageBuf_IteratorBase_exists_at_index OpenImageIO_v2_3_6__ImageBuf__IteratorBase_exists_at_index


/** Does the current location exist within the ImageBuf's
data window? */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_exists(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , _Bool * return_);
#define OIIO_ImageBuf_IteratorBase_exists OpenImageIO_v2_3_6__ImageBuf__IteratorBase_exists


/** Are we finished iterating over the region? */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_done(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , _Bool * return_);
#define OIIO_ImageBuf_IteratorBase_done OpenImageIO_v2_3_6__ImageBuf__IteratorBase_done


/** Retrieve the number of deep data samples at this pixel. */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_deep_samples(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , int * return_);
#define OIIO_ImageBuf_IteratorBase_deep_samples OpenImageIO_v2_3_6__ImageBuf__IteratorBase_deep_samples


/** Return the wrap mode */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_wrap(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , OIIO_ImageBuf_WrapMode * return_);
#define OIIO_ImageBuf_IteratorBase_wrap OpenImageIO_v2_3_6__ImageBuf__IteratorBase_wrap


/** Explicitly point the iterator.  This results in an invalid
iterator if outside the previously-designated region. */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_pos(
    OIIO_ImageBuf_IteratorBase_t * this_
    , int x_
    , int y_
    , int z_);
#define OIIO_ImageBuf_IteratorBase_pos OpenImageIO_v2_3_6__ImageBuf__IteratorBase_pos


/** Increment to the next pixel in the region. */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase__op_inc(
    OIIO_ImageBuf_IteratorBase_t * this_);
#define OIIO_ImageBuf_IteratorBase__op_inc OpenImageIO_v2_3_6__ImageBuf__IteratorBase__op_inc


/** Return the iteration range */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_range(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , OIIO_ROI_t * return_);
#define OIIO_ImageBuf_IteratorBase_range OpenImageIO_v2_3_6__ImageBuf__IteratorBase_range


/** Reset the iteration range for this iterator and reposition to
the beginning of the range, but keep referring to the same
image. */
unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_rerange(
    OIIO_ImageBuf_IteratorBase_t * this_
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend
    , OIIO_ImageBuf_WrapMode wrap);
#define OIIO_ImageBuf_IteratorBase_rerange OpenImageIO_v2_3_6__ImageBuf__IteratorBase_rerange


/** Return pixel data window for this ImageSpec as a ROI. */
unsigned int OpenImageIO_v2_3_6_get_roi(
    OIIO_ROI_t * return_
    , OIIO_ImageSpec_t const * spec);
#define OIIO_get_roi OpenImageIO_v2_3_6_get_roi


/** Return full/display window for this ImageSpec as a ROI. */
unsigned int OpenImageIO_v2_3_6_get_roi_full(
    OIIO_ROI_t * return_
    , OIIO_ImageSpec_t const * spec);
#define OIIO_get_roi_full OpenImageIO_v2_3_6_get_roi_full


/** Set pixel data window for this ImageSpec to a ROI.
Does NOT change the channels of the spec, regardless of newroi. */
unsigned int OpenImageIO_v2_3_6_set_roi(
    OIIO_ImageSpec_t * spec
    , OIIO_ROI_t const * newroi);
#define OIIO_set_roi OpenImageIO_v2_3_6_set_roi


/** Set full/display window for this ImageSpec to a ROI.
Does NOT change the channels of the spec, regardless of newroi. */
unsigned int OpenImageIO_v2_3_6_set_roi_full(
    OIIO_ImageSpec_t * spec
    , OIIO_ROI_t const * newroi);
#define OIIO_set_roi_full OpenImageIO_v2_3_6_set_roi_full


#ifdef __cplusplus
}
#endif
