#include "c-imagecache_private.h"

#include "c-imageio_private.h"
#include "c-std_string_private.h"
#include "c-string_view_private.h"
#include "c-typedesc_private.h"
#include "c-ustring_private.h"

#include <stdexcept>

unsigned int OpenImageIO_v2_3_6__ImageCache_create(
    OIIO_ImageCache_t * * return_
    , _Bool shared)
{
    try {
        to_c(return_, OpenImageIO_v2_3_6::ImageCache::create(shared));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_destroy(
    OIIO_ImageCache_t * cache
    , _Bool teardown)
{
    try {
        OpenImageIO_v2_3_6::ImageCache::destroy(to_cpp(cache), teardown);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_attribute(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void const * val)
{
    try {
        *(return_) = (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), to_cpp_ref(&(type)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_attribute_int(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , int val)
{
    try {
        *(return_) = (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_attribute_float(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , float val)
{
    try {
        *(return_) = (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_attribute_double(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , double val)
{
    try {
        *(return_) = (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_attribute_string(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_string_view_t val)
{
    try {
        *(return_) = (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), to_cpp_ref(&(val)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_getattribute(
    OIIO_ImageCache_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void * val)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute(to_cpp_ref(&(name)), to_cpp_ref(&(type)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_getattribute_int(
    OIIO_ImageCache_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , int * val)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute(to_cpp_ref(&(name)), *(val));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_getattribute_float(
    OIIO_ImageCache_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , float * val)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute(to_cpp_ref(&(name)), *(val));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_getattribute_double(
    OIIO_ImageCache_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , double * val)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute(to_cpp_ref(&(name)), *(val));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_getattribute_cstr(
    OIIO_ImageCache_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , char * * val)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute(to_cpp_ref(&(name)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_getattribute_string(
    OIIO_ImageCache_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , std_string_t * val)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute(to_cpp_ref(&(name)), to_cpp_ref(val));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_get_perthread_info(
    OIIO_ImageCache_t * this_
    , OIIO_pvt_ImageCachePerThreadInfo_t * * return_
    , OIIO_pvt_ImageCachePerThreadInfo_t * thread_info)
{
    try {
        to_c(return_, (to_cpp(this_)) -> get_perthread_info(to_cpp(thread_info)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_create_thread_info(
    OIIO_ImageCache_t * this_
    , OIIO_pvt_ImageCachePerThreadInfo_t * * return_)
{
    try {
        to_c(return_, (to_cpp(this_)) -> create_thread_info());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_destroy_thread_info(
    OIIO_ImageCache_t * this_
    , OIIO_pvt_ImageCachePerThreadInfo_t * thread_info)
{
    try {
        (to_cpp(this_)) -> destroy_thread_info(to_cpp(thread_info));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_get_image_handle(
    OIIO_ImageCache_t * this_
    , OIIO_pvt_ImageCacheFile_t * * return_
    , OIIO_ustring_t filename
    , OIIO_pvt_ImageCachePerThreadInfo_t * thread_info)
{
    try {
        to_c(return_, (to_cpp(this_)) -> get_image_handle(to_cpp_ref(&(filename)), to_cpp(thread_info)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_good(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_pvt_ImageCacheFile_t * file)
{
    try {
        *(return_) = (to_cpp(this_)) -> good(to_cpp(file));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_resolve_filename(
    OIIO_ImageCache_t const * this_
    , std_string_t * * return_
    , std_string_t const * filename)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> resolve_filename(to_cpp_ref(filename)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_get_image_info(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , int subimage
    , int miplevel
    , OIIO_ustring_t dataname
    , OIIO_TypeDesc_t datatype
    , void * data)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_image_info(to_cpp_ref(&(filename)), subimage, miplevel, to_cpp_ref(&(dataname)), to_cpp_ref(&(datatype)), data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_get_image_info_with_handle(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_pvt_ImageCacheFile_t * file
    , OIIO_pvt_ImageCachePerThreadInfo_t * thread_info
    , int subimage
    , int miplevel
    , OIIO_ustring_t dataname
    , OIIO_TypeDesc_t datatype
    , void * data)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_image_info(to_cpp(file), to_cpp(thread_info), subimage, miplevel, to_cpp_ref(&(dataname)), to_cpp_ref(&(datatype)), data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_get_imagespec(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_ImageSpec_t * spec
    , int subimage
    , int miplevel
    , _Bool native)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_imagespec(to_cpp_ref(&(filename)), to_cpp_ref(spec), subimage, miplevel, native);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_get_imagespec_with_handle(
    OIIO_ImageCache_t * this_
    , _Bool * return_
    , OIIO_pvt_ImageCacheFile_t * file
    , OIIO_pvt_ImageCachePerThreadInfo_t * thread_info
    , OIIO_ImageSpec_t * spec
    , int subimage
    , int miplevel
    , _Bool native)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_imagespec(to_cpp(file), to_cpp(thread_info), to_cpp_ref(spec), subimage, miplevel, native);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_imagespec(
    OIIO_ImageCache_t * this_
    , OIIO_ImageSpec_t const * * return_
    , OIIO_ustring_t filename
    , int subimage
    , int miplevel
    , _Bool native)
{
    try {
        to_c(return_, (to_cpp(this_)) -> imagespec(to_cpp_ref(&(filename)), subimage, miplevel, native));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_imagespec_with_handle(
    OIIO_ImageCache_t * this_
    , OIIO_ImageSpec_t const * * return_
    , OIIO_pvt_ImageCacheFile_t * file
    , OIIO_pvt_ImageCachePerThreadInfo_t * thread_info
    , int subimage
    , int miplevel
    , _Bool native)
{
    try {
        to_c(return_, (to_cpp(this_)) -> imagespec(to_cpp(file), to_cpp(thread_info), subimage, miplevel, native));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , int cache_chend)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_pixels(to_cpp_ref(&(filename)), subimage, miplevel, xbegin, xend, ybegin, yend, zbegin, zend, chbegin, chend, to_cpp_ref(&(format)), result, xstride, ystride, zstride, cache_chbegin, cache_chend);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , int cache_chend)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_pixels(to_cpp(file), to_cpp(thread_info), subimage, miplevel, xbegin, xend, ybegin, yend, zbegin, zend, chbegin, chend, to_cpp_ref(&(format)), result, xstride, ystride, zstride, cache_chbegin, cache_chend);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , void * result)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_pixels(to_cpp_ref(&(filename)), subimage, miplevel, xbegin, xend, ybegin, yend, zbegin, zend, to_cpp_ref(&(format)), result);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , void * result)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_pixels(to_cpp(file), to_cpp(thread_info), subimage, miplevel, xbegin, xend, ybegin, yend, zbegin, zend, to_cpp_ref(&(format)), result);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_invalidate(
    OIIO_ImageCache_t * this_
    , OIIO_ustring_t filename
    , _Bool force)
{
    try {
        (to_cpp(this_)) -> invalidate(to_cpp_ref(&(filename)), force);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_invalidate_all(
    OIIO_ImageCache_t * this_
    , _Bool force)
{
    try {
        (to_cpp(this_)) -> invalidate_all(force);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_close(
    OIIO_ImageCache_t * this_
    , OIIO_ustring_t filename)
{
    try {
        (to_cpp(this_)) -> close(to_cpp_ref(&(filename)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_close_all(
    OIIO_ImageCache_t * this_)
{
    try {
        (to_cpp(this_)) -> close_all();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , int chend)
{
    try {
        to_c(return_, (to_cpp(this_)) -> get_tile(to_cpp_ref(&(filename)), subimage, miplevel, x, y, z, chbegin, chend));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , int chend)
{
    try {
        to_c(return_, (to_cpp(this_)) -> get_tile(to_cpp(file), to_cpp(thread_info), subimage, miplevel, x, y, z, chbegin, chend));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_release_tile(
    OIIO_ImageCache_t const * this_
    , OIIO_ImageCache_Tile_t * tile)
{
    try {
        (to_cpp(this_)) -> release_tile(to_cpp(tile));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_tile_format(
    OIIO_ImageCache_t const * this_
    , OIIO_TypeDesc_t * return_
    , OIIO_ImageCache_Tile_t const * tile)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> tile_format(to_cpp(tile)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_tile_roi(
    OIIO_ImageCache_t const * this_
    , OIIO_ROI_t * return_
    , OIIO_ImageCache_Tile_t const * tile)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> tile_roi(to_cpp(tile)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_tile_pixels(
    OIIO_ImageCache_t const * this_
    , void const * * return_
    , OIIO_ImageCache_Tile_t * tile
    , OIIO_TypeDesc_t * format)
{
    try {
        *(return_) = (to_cpp(this_)) -> tile_pixels(to_cpp(tile), to_cpp_ref(format));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , _Bool copy)
{
    try {
        *(return_) = (to_cpp(this_)) -> add_tile(to_cpp_ref(&(filename)), subimage, miplevel, x, y, z, chbegin, chend, to_cpp_ref(&(format)), buffer, xstride, ystride, zstride, copy);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_has_error(
    OIIO_ImageCache_t const * this_
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

unsigned int OpenImageIO_v2_3_6__ImageCache_geterror(
    OIIO_ImageCache_t const * this_
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

unsigned int OpenImageIO_v2_3_6__ImageCache_getstats(
    OIIO_ImageCache_t const * this_
    , std_string_t * * return_
    , int level)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> getstats(level));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache_reset_stats(
    OIIO_ImageCache_t * this_)
{
    try {
        (to_cpp(this_)) -> reset_stats();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageCache__assign(
    OIIO_ImageCache_t * this_
    , OIIO_ImageCache_t * * return_
    , OIIO_ImageCache_t const * rhs)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

