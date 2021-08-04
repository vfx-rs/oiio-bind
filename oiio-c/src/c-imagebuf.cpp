#include "c-imagebuf_private.h"

#include "c-deepdata_private.h"
#include "c-filesystem_private.h"
#include "c-imagecache_private.h"
#include "c-imageio_private.h"
#include "c-span_private.h"
#include "c-std_string_private.h"
#include "c-string_view_private.h"
#include "c-typedesc_private.h"
#include <new>

#include <stdexcept>

unsigned int OpenImageIO_v2_3_6__ImageBuf_default(
    OIIO_ImageBuf_t * * this_)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::ImageBuf());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_dtor(
    OIIO_ImageBuf_t * this_)
{
    try {
        delete to_cpp(this_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_ctor(
    OIIO_ImageBuf_t * * this_
    , OIIO_string_view_t name
    , int subimage
    , int miplevel
    , OIIO_ImageCache_t * imagecache
    , OIIO_ImageSpec_t const * config
    , OIIO_Filesystem_IOProxy_t * ioproxy)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::ImageBuf(to_cpp_ref(&(name)), subimage, miplevel, to_cpp(imagecache), to_cpp(config), to_cpp(ioproxy)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_ctor_initialized(
    OIIO_ImageBuf_t * * this_
    , OIIO_ImageSpec_t const * spec
    , OIIO_InitializePixels zero)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::ImageBuf(to_cpp_ref(spec), OIIO_InitializePixels_to_cpp_ref(&(zero))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_wrap_buffer(
    OIIO_ImageBuf_t * * this_
    , OIIO_ImageSpec_t const * spec
    , void * buffer
    , long x_stride
    , long y_stride
    , long z_stride)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::ImageBuf(to_cpp_ref(spec), buffer, x_stride, y_stride, z_stride));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_copy(
    OIIO_ImageBuf_t * * this_
    , OIIO_ImageBuf_t const * src)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::ImageBuf(to_cpp_ref(src)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_clear(
    OIIO_ImageBuf_t * this_)
{
    try {
        (to_cpp(this_)) -> clear();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_reset(
    OIIO_ImageBuf_t * this_)
{
    try {
        (to_cpp(this_)) -> reset();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_reset_with_file(
    OIIO_ImageBuf_t * this_
    , OIIO_string_view_t name
    , int subimage
    , int miplevel
    , OIIO_ImageCache_t * imagecache
    , OIIO_ImageSpec_t const * config
    , OIIO_Filesystem_IOProxy_t * ioproxy)
{
    try {
        (to_cpp(this_)) -> reset(to_cpp_ref(&(name)), subimage, miplevel, to_cpp(imagecache), to_cpp(config), to_cpp(ioproxy));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_reset_initialized(
    OIIO_ImageBuf_t * this_
    , OIIO_ImageSpec_t const * spec
    , OIIO_InitializePixels zero)
{
    try {
        (to_cpp(this_)) -> reset(to_cpp_ref(spec), OIIO_InitializePixels_to_cpp_ref(&(zero)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_reset_wrap_buffer(
    OIIO_ImageBuf_t * this_
    , OIIO_ImageSpec_t const * spec
    , void * buffer
    , long x_stride
    , long y_stride
    , long z_stride)
{
    try {
        (to_cpp(this_)) -> reset(to_cpp_ref(spec), buffer, x_stride, y_stride, z_stride);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_make_writable(
    OIIO_ImageBuf_t * this_
    , _Bool * return_
    , _Bool keep_cache_type)
{
    try {
        *(return_) = (to_cpp(this_)) -> make_writable(keep_cache_type);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_read(
    OIIO_ImageBuf_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , _Bool force
    , OIIO_TypeDesc_t convert
    , OIIO_ProgressCallback_t progress_callback
    , void * progress_callback_data)
{
    try {
        *(return_) = (to_cpp(this_)) -> read(subimage, miplevel, force, to_cpp_ref(&(convert)), progress_callback, progress_callback_data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , void * progress_callback_data)
{
    try {
        *(return_) = (to_cpp(this_)) -> read(subimage, miplevel, chbegin, chend, force, to_cpp_ref(&(convert)), progress_callback, progress_callback_data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_init_spec(
    OIIO_ImageBuf_t * this_
    , _Bool * return_
    , OIIO_string_view_t filename
    , int subimage
    , int miplevel)
{
    try {
        *(return_) = (to_cpp(this_)) -> init_spec(to_cpp_ref(&(filename)), subimage, miplevel);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_write(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_
    , OIIO_string_view_t filename
    , OIIO_TypeDesc_t dtype
    , OIIO_string_view_t fileformat
    , OIIO_ProgressCallback_t progress_callback
    , void * progress_callback_data)
{
    try {
        *(return_) = (to_cpp(this_)) -> write(to_cpp_ref(&(filename)), to_cpp_ref(&(dtype)), to_cpp_ref(&(fileformat)), progress_callback, progress_callback_data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_set_write_format(
    OIIO_ImageBuf_t * this_
    , OIIO_TypeDesc_t format)
{
    try {
        (to_cpp(this_)) -> set_write_format(to_cpp_ref(&(format)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_set_write_format_per_channel(
    OIIO_ImageBuf_t * this_
    , OIIO_cspan_TypeDesc_t format)
{
    try {
        (to_cpp(this_)) -> set_write_format(to_cpp_ref(&(format)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_set_write_tiles(
    OIIO_ImageBuf_t * this_
    , int width
    , int height
    , int depth)
{
    try {
        (to_cpp(this_)) -> set_write_tiles(width, height, depth);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_set_write_ioproxy(
    OIIO_ImageBuf_t * this_
    , OIIO_Filesystem_IOProxy_t * ioproxy)
{
    try {
        (to_cpp(this_)) -> set_write_ioproxy(to_cpp(ioproxy));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_write_to_imageoutput(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_
    , OIIO_ImageOutput_t * out
    , OIIO_ProgressCallback_t progress_callback
    , void * progress_callback_data)
{
    try {
        *(return_) = (to_cpp(this_)) -> write(to_cpp(out), progress_callback, progress_callback_data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__assign(
    OIIO_ImageBuf_t * this_
    , OIIO_ImageBuf_t const * * return_
    , OIIO_ImageBuf_t const * src)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(src)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_copy_metadata(
    OIIO_ImageBuf_t * this_
    , OIIO_ImageBuf_t const * src)
{
    try {
        (to_cpp(this_)) -> copy_metadata(to_cpp_ref(src));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_copy_pixels(
    OIIO_ImageBuf_t * this_
    , _Bool * return_
    , OIIO_ImageBuf_t const * src)
{
    try {
        *(return_) = (to_cpp(this_)) -> copy_pixels(to_cpp_ref(src));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_copy_from(
    OIIO_ImageBuf_t * this_
    , _Bool * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_TypeDesc_t format)
{
    try {
        *(return_) = (to_cpp(this_)) -> copy(to_cpp_ref(src), to_cpp_ref(&(format)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_clone(
    OIIO_ImageBuf_t const * this_
    , OIIO_ImageBuf_t * * return_
    , OIIO_TypeDesc_t format)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> copy(to_cpp_ref(&(format))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_swap(
    OIIO_ImageBuf_t * this_
    , OIIO_ImageBuf_t * other)
{
    try {
        (to_cpp(this_)) -> swap(to_cpp_ref(other));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_getchannel(
    OIIO_ImageBuf_t const * this_
    , float * return_
    , int x
    , int y
    , int z
    , int c
    , OIIO_ImageBuf_WrapMode wrap)
{
    try {
        *(return_) = (to_cpp(this_)) -> getchannel(x, y, z, c, OIIO_ImageBuf_WrapMode_to_cpp_ref(&(wrap)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_getpixel_3d(
    OIIO_ImageBuf_t const * this_
    , int x
    , int y
    , int z
    , float * pixel
    , int maxchannels
    , OIIO_ImageBuf_WrapMode wrap)
{
    try {
        (to_cpp(this_)) -> getpixel(x, y, z, pixel, maxchannels, OIIO_ImageBuf_WrapMode_to_cpp_ref(&(wrap)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_getpixel(
    OIIO_ImageBuf_t const * this_
    , int x
    , int y
    , float * pixel
    , int maxchannels)
{
    try {
        (to_cpp(this_)) -> getpixel(x, y, pixel, maxchannels);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_interppixel(
    OIIO_ImageBuf_t const * this_
    , float x
    , float y
    , float * pixel
    , OIIO_ImageBuf_WrapMode wrap)
{
    try {
        (to_cpp(this_)) -> interppixel(x, y, pixel, OIIO_ImageBuf_WrapMode_to_cpp_ref(&(wrap)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_interppixel_NDC(
    OIIO_ImageBuf_t const * this_
    , float s
    , float t
    , float * pixel
    , OIIO_ImageBuf_WrapMode wrap)
{
    try {
        (to_cpp(this_)) -> interppixel_NDC(s, t, pixel, OIIO_ImageBuf_WrapMode_to_cpp_ref(&(wrap)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_interppixel_NDC_full(
    OIIO_ImageBuf_t const * this_
    , float s
    , float t
    , float * pixel
    , OIIO_ImageBuf_WrapMode wrap)
{
    try {
        (to_cpp(this_)) -> interppixel_NDC_full(s, t, pixel, OIIO_ImageBuf_WrapMode_to_cpp_ref(&(wrap)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_interppixel_bicubic(
    OIIO_ImageBuf_t const * this_
    , float x
    , float y
    , float * pixel
    , OIIO_ImageBuf_WrapMode wrap)
{
    try {
        (to_cpp(this_)) -> interppixel_bicubic(x, y, pixel, OIIO_ImageBuf_WrapMode_to_cpp_ref(&(wrap)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_interppixel_bicubic_NDC(
    OIIO_ImageBuf_t const * this_
    , float s
    , float t
    , float * pixel
    , OIIO_ImageBuf_WrapMode wrap)
{
    try {
        (to_cpp(this_)) -> interppixel_bicubic_NDC(s, t, pixel, OIIO_ImageBuf_WrapMode_to_cpp_ref(&(wrap)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_setpixel_span(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , OIIO_cspan_float_t pixel)
{
    try {
        (to_cpp(this_)) -> setpixel(x, y, to_cpp_ref(&(pixel)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_setpixel_3d_span(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , int z
    , OIIO_cspan_float_t pixel)
{
    try {
        (to_cpp(this_)) -> setpixel(x, y, z, to_cpp_ref(&(pixel)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_setpixel_at_index_span(
    OIIO_ImageBuf_t * this_
    , int i
    , OIIO_cspan_float_t pixel)
{
    try {
        (to_cpp(this_)) -> setpixel(i, to_cpp_ref(&(pixel)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_setpixel(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , float const * pixel
    , int maxchannels)
{
    try {
        (to_cpp(this_)) -> setpixel(x, y, pixel, maxchannels);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_setpixel_3d(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , int z
    , float const * pixel
    , int maxchannels)
{
    try {
        (to_cpp(this_)) -> setpixel(x, y, z, pixel, maxchannels);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_setpixel_at_index(
    OIIO_ImageBuf_t * this_
    , int i
    , float const * pixel
    , int maxchannels)
{
    try {
        (to_cpp(this_)) -> setpixel(i, pixel, maxchannels);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_get_pixels(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_
    , OIIO_ROI_t roi
    , OIIO_TypeDesc_t format
    , void * result
    , long xstride
    , long ystride
    , long zstride)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_pixels(to_cpp_ref(&(roi)), to_cpp_ref(&(format)), result, xstride, ystride, zstride);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_set_pixels(
    OIIO_ImageBuf_t * this_
    , _Bool * return_
    , OIIO_ROI_t roi
    , OIIO_TypeDesc_t format
    , void const * data
    , long xstride
    , long ystride
    , long zstride)
{
    try {
        *(return_) = (to_cpp(this_)) -> set_pixels(to_cpp_ref(&(roi)), to_cpp_ref(&(format)), data, xstride, ystride, zstride);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_initialized(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> initialized();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_storage(
    OIIO_ImageBuf_t const * this_
    , OIIO_ImageBuf_IBStorage * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> storage());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_spec(
    OIIO_ImageBuf_t const * this_
    , OIIO_ImageSpec_t const * * return_)
{
    try {
        to_c(return_, (to_cpp(this_)) -> spec());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_specmod(
    OIIO_ImageBuf_t * this_
    , OIIO_ImageSpec_t * * return_)
{
    try {
        to_c(return_, (to_cpp(this_)) -> specmod());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_nativespec(
    OIIO_ImageBuf_t const * this_
    , OIIO_ImageSpec_t const * * return_)
{
    try {
        to_c(return_, (to_cpp(this_)) -> nativespec());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_name(
    OIIO_ImageBuf_t const * this_
    , OIIO_string_view_t * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> name());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_file_format_name(
    OIIO_ImageBuf_t const * this_
    , OIIO_string_view_t * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> file_format_name());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_subimage(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> subimage();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_nsubimages(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> nsubimages();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_miplevel(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> miplevel();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_nmiplevels(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> nmiplevels();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_nchannels(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> nchannels();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_xbegin(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> xbegin();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_xend(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> xend();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_ybegin(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> ybegin();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_yend(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> yend();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_zbegin(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> zbegin();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_zend(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> zend();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_xmin(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> xmin();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_xmax(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> xmax();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_ymin(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> ymin();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_ymax(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> ymax();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_zmin(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> zmin();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_zmax(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> zmax();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_orientation(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> orientation();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_set_orientation(
    OIIO_ImageBuf_t * this_
    , int orient)
{
    try {
        (to_cpp(this_)) -> set_orientation(orient);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_oriented_width(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> oriented_width();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_oriented_height(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> oriented_height();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_oriented_x(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> oriented_x();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_oriented_y(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> oriented_y();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_oriented_full_width(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> oriented_full_width();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_oriented_full_height(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> oriented_full_height();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_oriented_full_x(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> oriented_full_x();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_oriented_full_y(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> oriented_full_y();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_set_origin(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , int z)
{
    try {
        (to_cpp(this_)) -> set_origin(x, y, z);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_set_full(
    OIIO_ImageBuf_t * this_
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend)
{
    try {
        (to_cpp(this_)) -> set_full(xbegin, xend, ybegin, yend, zbegin, zend);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_roi(
    OIIO_ImageBuf_t const * this_
    , OIIO_ROI_t * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> roi());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_roi_full(
    OIIO_ImageBuf_t const * this_
    , OIIO_ROI_t * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> roi_full());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_set_roi_full(
    OIIO_ImageBuf_t * this_
    , OIIO_ROI_t const * newroi)
{
    try {
        (to_cpp(this_)) -> set_roi_full(to_cpp_ref(newroi));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_contains_roi(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_
    , OIIO_ROI_t roi)
{
    try {
        *(return_) = (to_cpp(this_)) -> contains_roi(to_cpp_ref(&(roi)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_pixels_valid(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> pixels_valid();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_pixeltype(
    OIIO_ImageBuf_t const * this_
    , OIIO_TypeDesc_t * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> pixeltype());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_localpixels(
    OIIO_ImageBuf_t * this_
    , void * * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> localpixels();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_localpixels_const(
    OIIO_ImageBuf_t const * this_
    , void const * * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> localpixels();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_pixel_stride(
    OIIO_ImageBuf_t const * this_
    , long * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> pixel_stride();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_scanline_stride(
    OIIO_ImageBuf_t const * this_
    , long * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> scanline_stride();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_z_stride(
    OIIO_ImageBuf_t const * this_
    , long * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> z_stride();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_contiguous(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> contiguous();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_cachedpixels(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> cachedpixels();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_imagecache(
    OIIO_ImageBuf_t const * this_
    , OIIO_ImageCache_t * * return_)
{
    try {
        to_c(return_, (to_cpp(this_)) -> imagecache());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_pixeladdr_const(
    OIIO_ImageBuf_t const * this_
    , void const * * return_
    , int x
    , int y
    , int z
    , int ch)
{
    try {
        *(return_) = (to_cpp(this_)) -> pixeladdr(x, y, z, ch);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_pixeladdr(
    OIIO_ImageBuf_t * this_
    , void * * return_
    , int x
    , int y
    , int z
    , int ch)
{
    try {
        *(return_) = (to_cpp(this_)) -> pixeladdr(x, y, z, ch);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_pixelindex(
    OIIO_ImageBuf_t const * this_
    , int * return_
    , int x
    , int y
    , int z
    , _Bool check_range)
{
    try {
        *(return_) = (to_cpp(this_)) -> pixelindex(x, y, z, check_range);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_threads(
    OIIO_ImageBuf_t const * this_
    , int n)
{
    try {
        (to_cpp(this_)) -> threads(n);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_threads_const(
    OIIO_ImageBuf_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> threads();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_error(
    OIIO_ImageBuf_t const * this_
    , OIIO_string_view_t message)
{
    try {
        (to_cpp(this_)) -> error(to_cpp_ref(&(message)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_has_error(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> has_error();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_geterror(
    OIIO_ImageBuf_t const * this_
    , std_string_t * * return_
    , _Bool clear)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> geterror(clear));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_deep(
    OIIO_ImageBuf_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> deep();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_deep_samples(
    OIIO_ImageBuf_t const * this_
    , int * return_
    , int x
    , int y
    , int z)
{
    try {
        *(return_) = (to_cpp(this_)) -> deep_samples(x, y, z);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_deep_pixel_ptr(
    OIIO_ImageBuf_t const * this_
    , void const * * return_
    , int x
    , int y
    , int z
    , int c
    , int s)
{
    try {
        *(return_) = (to_cpp(this_)) -> deep_pixel_ptr(x, y, z, c, s);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_deep_value(
    OIIO_ImageBuf_t const * this_
    , float * return_
    , int x
    , int y
    , int z
    , int c
    , int s)
{
    try {
        *(return_) = (to_cpp(this_)) -> deep_value(x, y, z, c, s);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_deep_value_uint(
    OIIO_ImageBuf_t const * this_
    , unsigned int * return_
    , int x
    , int y
    , int z
    , int c
    , int s)
{
    try {
        *(return_) = (to_cpp(this_)) -> deep_value_uint(x, y, z, c, s);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_set_deep_samples(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , int z
    , int nsamples)
{
    try {
        (to_cpp(this_)) -> set_deep_samples(x, y, z, nsamples);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_deep_insert_samples(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , int z
    , int samplepos
    , int nsamples)
{
    try {
        (to_cpp(this_)) -> deep_insert_samples(x, y, z, samplepos, nsamples);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_deep_erase_samples(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , int z
    , int samplepos
    , int nsamples)
{
    try {
        (to_cpp(this_)) -> deep_erase_samples(x, y, z, samplepos, nsamples);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_set_deep_value(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , int z
    , int c
    , int s
    , float value)
{
    try {
        (to_cpp(this_)) -> set_deep_value(x, y, z, c, s, value);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_set_deep_value_uint(
    OIIO_ImageBuf_t * this_
    , int x
    , int y
    , int z
    , int c
    , int s
    , unsigned int value)
{
    try {
        (to_cpp(this_)) -> set_deep_value(x, y, z, c, s, value);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_copy_deep_pixel(
    OIIO_ImageBuf_t * this_
    , _Bool * return_
    , int x
    , int y
    , int z
    , OIIO_ImageBuf_t const * src
    , int srcx
    , int srcy
    , int srcz)
{
    try {
        *(return_) = (to_cpp(this_)) -> copy_deep_pixel(x, y, z, to_cpp_ref(src), srcx, srcy, srcz);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_deepdata(
    OIIO_ImageBuf_t * this_
    , OIIO_DeepData_t * * return_)
{
    try {
        to_c(return_, (to_cpp(this_)) -> deepdata());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_deepdata_const(
    OIIO_ImageBuf_t const * this_
    , OIIO_DeepData_t const * * return_)
{
    try {
        to_c(return_, (to_cpp(this_)) -> deepdata());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf_WrapMode_from_string(
    OIIO_ImageBuf_WrapMode * return_
    , OIIO_string_view_t name)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBuf::WrapMode_from_string(to_cpp_ref(&(name))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_sizeof()
{
        return sizeof(OpenImageIO_v2_3_6::ImageBuf::IteratorBase);
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_alignof()
{
        return alignof(OpenImageIO_v2_3_6::ImageBuf::IteratorBase);
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_with_wrapmode(
    OIIO_ImageBuf_IteratorBase_t * this_
    , OIIO_ImageBuf_t const * ib
    , OIIO_ImageBuf_WrapMode wrap)
{
    try {
        new (this_) OpenImageIO_v2_3_6::ImageBuf::IteratorBase(to_cpp_ref(ib), OIIO_ImageBuf_WrapMode_to_cpp_ref(&(wrap)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_with_roi(
    OIIO_ImageBuf_IteratorBase_t * this_
    , OIIO_ImageBuf_t const * ib
    , OIIO_ROI_t const * roi
    , OIIO_ImageBuf_WrapMode wrap)
{
    try {
        new (this_) OpenImageIO_v2_3_6::ImageBuf::IteratorBase(to_cpp_ref(ib), to_cpp_ref(roi), OIIO_ImageBuf_WrapMode_to_cpp_ref(&(wrap)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_with_range(
    OIIO_ImageBuf_IteratorBase_t * this_
    , OIIO_ImageBuf_t const * ib
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend
    , OIIO_ImageBuf_WrapMode wrap)
{
    try {
        new (this_) OpenImageIO_v2_3_6::ImageBuf::IteratorBase(to_cpp_ref(ib), xbegin, xend, ybegin, yend, zbegin, zend, OIIO_ImageBuf_WrapMode_to_cpp_ref(&(wrap)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_copy(
    OIIO_ImageBuf_IteratorBase_t * this_
    , OIIO_ImageBuf_IteratorBase_t const * i)
{
    try {
        new (this_) OpenImageIO_v2_3_6::ImageBuf::IteratorBase(to_cpp_ref(i));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_dtor(
    OIIO_ImageBuf_IteratorBase_t * this_)
{
    try {
        (to_cpp(this_)) -> OpenImageIO_v2_3_6::ImageBuf::IteratorBase::~IteratorBase();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_assign_base(
    OIIO_ImageBuf_IteratorBase_t * this_
    , OIIO_ImageBuf_IteratorBase_t const * * return_
    , OIIO_ImageBuf_IteratorBase_t const * i)
{
    try {
        to_c(return_, (to_cpp(this_)) -> assign_base(to_cpp_ref(i)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_x(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> x();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_y(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> y();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_z(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> z();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_valid(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> valid();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_valid_at_index(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , _Bool * return_
    , int x_
    , int y_
    , int z_)
{
    try {
        *(return_) = (to_cpp(this_)) -> valid(x_, y_, z_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_exists_at_index(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , _Bool * return_
    , int x_
    , int y_
    , int z_)
{
    try {
        *(return_) = (to_cpp(this_)) -> exists(x_, y_, z_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_exists(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> exists();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_done(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> done();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_deep_samples(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> deep_samples();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_wrap(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , OIIO_ImageBuf_WrapMode * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> wrap());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_pos(
    OIIO_ImageBuf_IteratorBase_t * this_
    , int x_
    , int y_
    , int z_)
{
    try {
        (to_cpp(this_)) -> pos(x_, y_, z_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase__op_inc(
    OIIO_ImageBuf_IteratorBase_t * this_)
{
    try {
        (to_cpp(this_)) -> operator++();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_range(
    OIIO_ImageBuf_IteratorBase_t const * this_
    , OIIO_ROI_t * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> range());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageBuf__IteratorBase_rerange(
    OIIO_ImageBuf_IteratorBase_t * this_
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend
    , OIIO_ImageBuf_WrapMode wrap)
{
    try {
        (to_cpp(this_)) -> rerange(xbegin, xend, ybegin, yend, zbegin, zend, OIIO_ImageBuf_WrapMode_to_cpp_ref(&(wrap)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_get_roi(
    OIIO_ROI_t * return_
    , OIIO_ImageSpec_t const * spec)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::get_roi(to_cpp_ref(spec)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_get_roi_full(
    OIIO_ROI_t * return_
    , OIIO_ImageSpec_t const * spec)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::get_roi_full(to_cpp_ref(spec)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_set_roi(
    OIIO_ImageSpec_t * spec
    , OIIO_ROI_t const * newroi)
{
    try {
        OpenImageIO_v2_3_6::set_roi(to_cpp_ref(spec), to_cpp_ref(newroi));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_set_roi_full(
    OIIO_ImageSpec_t * spec
    , OIIO_ROI_t const * newroi)
{
    try {
        OpenImageIO_v2_3_6::set_roi_full(to_cpp_ref(spec), to_cpp_ref(newroi));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

