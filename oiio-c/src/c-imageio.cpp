#include "c-imageio_private.h"

#include "c-deepdata_private.h"
#include "c-filesystem_private.h"
#include "c-paramlist_private.h"
#include "c-std_pair_private.h"
#include "c-std_string_private.h"
#include "c-std_unique_ptr_private.h"
#include "c-std_vector_private.h"
#include "c-string_view_private.h"
#include "c-typedesc_private.h"
#include <new>

#include <stdexcept>

unsigned int OpenImageIO_v2_3_6__ROI_defined(
    OIIO_ROI_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> defined();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ROI_width(
    OIIO_ROI_t const * this_
    , int * return_)
{
        *(return_) = (to_cpp(this_)) -> width();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ROI_height(
    OIIO_ROI_t const * this_
    , int * return_)
{
        *(return_) = (to_cpp(this_)) -> height();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ROI_depth(
    OIIO_ROI_t const * this_
    , int * return_)
{
        *(return_) = (to_cpp(this_)) -> depth();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ROI_nchannels(
    OIIO_ROI_t const * this_
    , int * return_)
{
        *(return_) = (to_cpp(this_)) -> nchannels();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ROI_npixels(
    OIIO_ROI_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> npixels();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ROI_All(
    OIIO_ROI_t * return_)
{
        to_c_copy(return_, OpenImageIO_v2_3_6::ROI::All());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ROI_contains(
    OIIO_ROI_t const * this_
    , _Bool * return_
    , int x
    , int y
    , int z
    , int ch)
{
        *(return_) = (to_cpp(this_)) -> contains(x, y, z, ch);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ROI_contains_roi(
    OIIO_ROI_t const * this_
    , _Bool * return_
    , OIIO_ROI_t const * other)
{
        *(return_) = (to_cpp(this_)) -> contains(to_cpp_ref(other));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ROI_copy(
    OIIO_ROI_t * this_
    , OIIO_ROI_t const * rhs)
{
        new (this_) OpenImageIO_v2_3_6::ROI(to_cpp_ref(rhs));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_from_typedesc(
    OIIO_ImageSpec_t * * this_
    , OIIO_TypeDesc_t format)
{
        to_c(this_, new OpenImageIO_v2_3_6::ImageSpec(to_cpp_ref(&(format))));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_from_dimensions(
    OIIO_ImageSpec_t * * this_
    , int xres
    , int yres
    , int nchans
    , OIIO_TypeDesc_t fmt)
{
        to_c(this_, new OpenImageIO_v2_3_6::ImageSpec(xres, yres, nchans, to_cpp_ref(&(fmt))));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_from_roi(
    OIIO_ImageSpec_t * * this_
    , OIIO_ROI_t const * roi
    , OIIO_TypeDesc_t fmt)
{
        to_c(this_, new OpenImageIO_v2_3_6::ImageSpec(to_cpp_ref(roi), to_cpp_ref(&(fmt))));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_format_and_clear(
    OIIO_ImageSpec_t * this_
    , OIIO_TypeDesc_t fmt)
{
        (to_cpp(this_)) -> set_format(to_cpp_ref(&(fmt)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_default_channel_names(
    OIIO_ImageSpec_t * this_)
{
        (to_cpp(this_)) -> default_channel_names();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_channel_bytes(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> channel_bytes();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_channel_bytes_for_channel(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_
    , int chan
    , _Bool native)
{
        *(return_) = (to_cpp(this_)) -> channel_bytes(chan, native);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_pixel_bytes(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_
    , _Bool native)
{
        *(return_) = (to_cpp(this_)) -> pixel_bytes(native);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_pixel_bytes_for_channels(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_
    , int chbegin
    , int chend
    , _Bool native)
{
        *(return_) = (to_cpp(this_)) -> pixel_bytes(chbegin, chend, native);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_scanline_bytes(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_
    , _Bool native)
{
        *(return_) = (to_cpp(this_)) -> scanline_bytes(native);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_tile_pixels(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> tile_pixels();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_tile_bytes(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_
    , _Bool native)
{
        *(return_) = (to_cpp(this_)) -> tile_bytes(native);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_image_pixels(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> image_pixels();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_image_bytes(
    OIIO_ImageSpec_t const * this_
    , unsigned long * return_
    , _Bool native)
{
        *(return_) = (to_cpp(this_)) -> image_bytes(native);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_size_t_safe(
    OIIO_ImageSpec_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> size_t_safe();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_auto_stride(
    long * xstride
    , long * ystride
    , long * zstride
    , long channelsize
    , int nchannels
    , int width
    , int height)
{
        OpenImageIO_v2_3_6::ImageSpec::auto_stride(*(xstride), *(ystride), *(zstride), channelsize, nchannels, width, height);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_auto_stride_with_typedesc(
    long * xstride
    , long * ystride
    , long * zstride
    , OIIO_TypeDesc_t format
    , int nchannels
    , int width
    , int height)
{
        OpenImageIO_v2_3_6::ImageSpec::auto_stride(*(xstride), *(ystride), *(zstride), to_cpp_ref(&(format)), nchannels, width, height);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_auto_stride_xstride(
    long * xstride
    , OIIO_TypeDesc_t format
    , int nchannels)
{
        OpenImageIO_v2_3_6::ImageSpec::auto_stride(*(xstride), to_cpp_ref(&(format)), nchannels);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_attribute(
    OIIO_ImageSpec_t * this_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void const * value)
{
    try {
        (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), to_cpp_ref(&(type)), value);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_attribute_uint(
    OIIO_ImageSpec_t * this_
    , OIIO_string_view_t name
    , unsigned int value)
{
    try {
        (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), value);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_attribute_int(
    OIIO_ImageSpec_t * this_
    , OIIO_string_view_t name
    , int value)
{
    try {
        (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), value);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_attribute_float(
    OIIO_ImageSpec_t * this_
    , OIIO_string_view_t name
    , float value)
{
    try {
        (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), value);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_attribute_string(
    OIIO_ImageSpec_t * this_
    , OIIO_string_view_t name
    , OIIO_string_view_t value)
{
    try {
        (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), to_cpp_ref(&(value)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_attribute_from_string(
    OIIO_ImageSpec_t * this_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , OIIO_string_view_t value)
{
    try {
        (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), to_cpp_ref(&(type)), to_cpp_ref(&(value)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_erase_attribute(
    OIIO_ImageSpec_t * this_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t searchtype
    , _Bool casesensitive)
{
    try {
        (to_cpp(this_)) -> erase_attribute(to_cpp_ref(&(name)), to_cpp_ref(&(searchtype)), casesensitive);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_find_attribute(
    OIIO_ImageSpec_t * this_
    , OIIO_ParamValue_t * * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t searchtype
    , _Bool casesensitive)
{
    try {
        to_c(return_, (to_cpp(this_)) -> find_attribute(to_cpp_ref(&(name)), to_cpp_ref(&(searchtype)), casesensitive));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_find_attribute_const(
    OIIO_ImageSpec_t const * this_
    , OIIO_ParamValue_t const * * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t searchtype
    , _Bool casesensitive)
{
    try {
        to_c(return_, (to_cpp(this_)) -> find_attribute(to_cpp_ref(&(name)), to_cpp_ref(&(searchtype)), casesensitive));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_find_attribute_builtin(
    OIIO_ImageSpec_t const * this_
    , OIIO_ParamValue_t const * * return_
    , OIIO_string_view_t name
    , OIIO_ParamValue_t * tmpparam
    , OIIO_TypeDesc_t searchtype
    , _Bool casesensitive)
{
    try {
        to_c(return_, (to_cpp(this_)) -> find_attribute(to_cpp_ref(&(name)), to_cpp_ref(tmpparam), to_cpp_ref(&(searchtype)), casesensitive));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_getattributetype(
    OIIO_ImageSpec_t const * this_
    , OIIO_TypeDesc_t * return_
    , OIIO_string_view_t name
    , _Bool casesensitive)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> getattributetype(to_cpp_ref(&(name)), casesensitive));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_getattribute(
    OIIO_ImageSpec_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void * value
    , _Bool casesensitive)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute(to_cpp_ref(&(name)), to_cpp_ref(&(type)), value, casesensitive);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_int_attribute(
    OIIO_ImageSpec_t const * this_
    , int * return_
    , OIIO_string_view_t name
    , int defaultval)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_int_attribute(to_cpp_ref(&(name)), defaultval);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_float_attribute(
    OIIO_ImageSpec_t const * this_
    , float * return_
    , OIIO_string_view_t name
    , float defaultval)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_float_attribute(to_cpp_ref(&(name)), defaultval);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_string_attribute(
    OIIO_ImageSpec_t const * this_
    , OIIO_string_view_t * return_
    , OIIO_string_view_t name
    , OIIO_string_view_t defaultval)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> get_string_attribute(to_cpp_ref(&(name)), to_cpp_ref(&(defaultval))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_metadata_val(
    std_string_t * * return_
    , OIIO_ParamValue_t const * p
    , _Bool human)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageSpec::metadata_val(to_cpp_ref(p), human));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_serialize(
    OIIO_ImageSpec_t const * this_
    , std_string_t * * return_
    , OIIO_ImageSpec_SerialFormat format
    , OIIO_ImageSpec_SerialVerbose verbose)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> serialize(OIIO_ImageSpec_SerialFormat_to_cpp_ref(&(format)), OIIO_ImageSpec_SerialVerbose_to_cpp_ref(&(verbose))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_to_xml(
    OIIO_ImageSpec_t const * this_
    , std_string_t * * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> to_xml());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_from_xml(
    OIIO_ImageSpec_t * this_
    , char const * xml)
{
    try {
        (to_cpp(this_)) -> from_xml(xml);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_decode_compression_metadata(
    OIIO_ImageSpec_t const * this_
    , std_pair_string_int_t * * return_
    , OIIO_string_view_t defaultcomp
    , int defaultqual)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> decode_compression_metadata(to_cpp_ref(&(defaultcomp)), defaultqual));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_valid_tile_range(
    OIIO_ImageSpec_t * this_
    , _Bool * return_
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend)
{
        *(return_) = (to_cpp(this_)) -> valid_tile_range(xbegin, xend, ybegin, yend, zbegin, zend);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_channelformat(
    OIIO_ImageSpec_t const * this_
    , OIIO_TypeDesc_t * return_
    , int chan)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> channelformat(chan));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_channel_name(
    OIIO_ImageSpec_t const * this_
    , OIIO_string_view_t * return_
    , int chan)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> channel_name(chan));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_channelformats_into(
    OIIO_ImageSpec_t const * this_
    , std_vector_typedesc_t * formats)
{
    try {
        (to_cpp(this_)) -> get_channelformats(to_cpp_ref(formats));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_channelindex(
    OIIO_ImageSpec_t const * this_
    , int * return_
    , OIIO_string_view_t name)
{
    try {
        *(return_) = (to_cpp(this_)) -> channelindex(to_cpp_ref(&(name)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_roi(
    OIIO_ImageSpec_t const * this_
    , OIIO_ROI_t * return_)
{
        to_c_copy(return_, (to_cpp(this_)) -> roi());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_roi_full(
    OIIO_ImageSpec_t const * this_
    , OIIO_ROI_t * return_)
{
        to_c_copy(return_, (to_cpp(this_)) -> roi_full());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_roi(
    OIIO_ImageSpec_t * this_
    , OIIO_ROI_t const * r)
{
        (to_cpp(this_)) -> set_roi(to_cpp_ref(r));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_roi_full(
    OIIO_ImageSpec_t * this_
    , OIIO_ROI_t const * r)
{
        (to_cpp(this_)) -> set_roi_full(to_cpp_ref(r));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_copy_dimensions(
    OIIO_ImageSpec_t * this_
    , OIIO_ImageSpec_t const * other)
{
    try {
        (to_cpp(this_)) -> copy_dimensions(to_cpp_ref(other));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_undefined(
    OIIO_ImageSpec_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> undefined();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_copy(
    OIIO_ImageSpec_t * * this_
    , OIIO_ImageSpec_t const * rhs)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::ImageSpec(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec__assign(
    OIIO_ImageSpec_t * this_
    , OIIO_ImageSpec_t * * return_
    , OIIO_ImageSpec_t const * rhs)
{
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(rhs)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_dtor(
    OIIO_ImageSpec_t * this_)
{
    try {
        delete to_cpp(this_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_x(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->x);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_x(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->x = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_y(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->y);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_y(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->y = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_z(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->z);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_z(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->z = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_width(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->width);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_width(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->width = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_height(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->height);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_height(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->height = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_depth(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->depth);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_depth(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->depth = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_full_x(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->full_x);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_full_x(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->full_x = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_full_y(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->full_y);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_full_y(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->full_y = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_full_z(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->full_z);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_full_z(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->full_z = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_full_width(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->full_width);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_full_width(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->full_width = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_full_height(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->full_height);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_full_height(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->full_height = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_full_depth(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->full_depth);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_full_depth(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->full_depth = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_tile_width(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->tile_width);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_tile_width(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->tile_width = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_tile_height(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->tile_height);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_tile_height(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->tile_height = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_tile_depth(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->tile_depth);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_tile_depth(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->tile_depth = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_nchannels(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->nchannels);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_nchannels(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->nchannels = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_format(
    OIIO_ImageSpec_t const * this_
    , OIIO_TypeDesc_t const * * return_)
{
        to_c(return_, (to_cpp(this_))->format);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_format(
    OIIO_ImageSpec_t * this_
    , OIIO_TypeDesc_t const * value)
{
        (to_cpp(this_))->format = to_cpp_ref(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_channelformats(
    OIIO_ImageSpec_t const * this_
    , std_vector_typedesc_t const * * return_)
{
        to_c(return_, (to_cpp(this_))->channelformats);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_channelformats(
    OIIO_ImageSpec_t * this_
    , std_vector_typedesc_t const * value)
{
        (to_cpp(this_))->channelformats = to_cpp_ref(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_channelnames(
    OIIO_ImageSpec_t const * this_
    , std_vector_string_t const * * return_)
{
        to_c(return_, (to_cpp(this_))->channelnames);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_channelnames(
    OIIO_ImageSpec_t * this_
    , std_vector_string_t const * value)
{
        (to_cpp(this_))->channelnames = to_cpp_ref(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_alpha_channel(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->alpha_channel);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_alpha_channel(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->alpha_channel = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_z_channel(
    OIIO_ImageSpec_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->z_channel);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_z_channel(
    OIIO_ImageSpec_t * this_
    , int const * value)
{
        (to_cpp(this_))->z_channel = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_deep(
    OIIO_ImageSpec_t const * this_
    , _Bool const * * return_)
{
        *(return_) = &((to_cpp(this_))->deep);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_deep(
    OIIO_ImageSpec_t * this_
    , _Bool const * value)
{
        (to_cpp(this_))->deep = *(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_get_extra_attribs(
    OIIO_ImageSpec_t const * this_
    , OIIO_ParamValueList_t const * * return_)
{
        to_c(return_, (to_cpp(this_))->extra_attribs);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageSpec_set_extra_attribs(
    OIIO_ImageSpec_t * this_
    , OIIO_ParamValueList_t const * value)
{
        (to_cpp(this_))->extra_attribs = to_cpp_ref(value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ImageInput_open(
    std_ImageInputPtr_t * return_
    , std_string_t const * filename
    , OIIO_ImageSpec_t const * config
    , OIIO_Filesystem_IOProxy_t * ioproxy)
{
    try {
        new (return_) std::unique_ptr<OIIO::ImageInput>(std::move(OpenImageIO_v2_3_6::ImageInput::open(to_cpp_ref(filename), to_cpp(config), to_cpp(ioproxy))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_dtor(
    OIIO_ImageInput_t * this_)
{
    try {
        delete to_cpp(this_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_format_name(
    OIIO_ImageInput_t const * this_
    , char const * * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> format_name();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_supports(
    OIIO_ImageInput_t const * this_
    , int * return_
    , OIIO_string_view_t feature)
{
    try {
        *(return_) = (to_cpp(this_)) -> supports(to_cpp_ref(&(feature)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_valid_file(
    OIIO_ImageInput_t const * this_
    , _Bool * return_
    , std_string_t const * filename)
{
    try {
        *(return_) = (to_cpp(this_)) -> valid_file(to_cpp_ref(filename));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_open_in(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , std_string_t const * name
    , OIIO_ImageSpec_t * newspec)
{
    try {
        *(return_) = (to_cpp(this_)) -> open(to_cpp_ref(name), to_cpp_ref(newspec));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_open_in_with_config(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , std_string_t const * name
    , OIIO_ImageSpec_t * newspec
    , OIIO_ImageSpec_t const * config)
{
    try {
        *(return_) = (to_cpp(this_)) -> open(to_cpp_ref(name), to_cpp_ref(newspec), to_cpp_ref(config));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_spec(
    OIIO_ImageInput_t const * this_
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

unsigned int OpenImageIO_v2_3_6__ImageInput_spec_for_subimage(
    OIIO_ImageInput_t * this_
    , OIIO_ImageSpec_t * * return_
    , int subimage
    , int miplevel)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> spec(subimage, miplevel));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_spec_dimensions(
    OIIO_ImageInput_t * this_
    , OIIO_ImageSpec_t * * return_
    , int subimage
    , int miplevel)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> spec_dimensions(subimage, miplevel));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_close(
    OIIO_ImageInput_t * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> close();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_current_subimage(
    OIIO_ImageInput_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> current_subimage();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_current_miplevel(
    OIIO_ImageInput_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> current_miplevel();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_seek_subimage(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel)
{
    try {
        *(return_) = (to_cpp(this_)) -> seek_subimage(subimage, miplevel);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_read_scanline(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int y
    , int z
    , OIIO_TypeDesc_t format
    , void * data
    , long xstride)
{
    try {
        *(return_) = (to_cpp(this_)) -> read_scanline(y, z, to_cpp_ref(&(format)), data, xstride);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_read_scanline_contiguous(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int y
    , int z
    , float * data)
{
    try {
        *(return_) = (to_cpp(this_)) -> read_scanline(y, z, data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , long ystride)
{
    try {
        *(return_) = (to_cpp(this_)) -> read_scanlines(subimage, miplevel, ybegin, yend, z, chbegin, chend, to_cpp_ref(&(format)), data, xstride, ystride);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , long zstride)
{
    try {
        *(return_) = (to_cpp(this_)) -> read_tile(x, y, z, to_cpp_ref(&(format)), data, xstride, ystride, zstride);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_read_tile_contiguous(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int x
    , int y
    , int z
    , float * data)
{
    try {
        *(return_) = (to_cpp(this_)) -> read_tile(x, y, z, data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , long zstride)
{
    try {
        *(return_) = (to_cpp(this_)) -> read_tiles(subimage, miplevel, xbegin, xend, ybegin, yend, zbegin, zend, chbegin, chend, to_cpp_ref(&(format)), data, xstride, ystride, zstride);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , void * progress_callback_data)
{
    try {
        *(return_) = (to_cpp(this_)) -> read_image(subimage, miplevel, chbegin, chend, to_cpp_ref(&(format)), data, xstride, ystride, zstride, progress_callback, progress_callback_data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , OIIO_DeepData_t * deepdata)
{
    try {
        *(return_) = (to_cpp(this_)) -> read_native_deep_scanlines(subimage, miplevel, ybegin, yend, z, chbegin, chend, to_cpp_ref(deepdata));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , OIIO_DeepData_t * deepdata)
{
    try {
        *(return_) = (to_cpp(this_)) -> read_native_deep_tiles(subimage, miplevel, xbegin, xend, ybegin, yend, zbegin, zend, chbegin, chend, to_cpp_ref(deepdata));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_read_native_deep_image(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , OIIO_DeepData_t * deepdata)
{
    try {
        *(return_) = (to_cpp(this_)) -> read_native_deep_image(subimage, miplevel, to_cpp_ref(deepdata));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_read_native_scanline(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , int y
    , int z
    , void * data)
{
    try {
        *(return_) = (to_cpp(this_)) -> read_native_scanline(subimage, miplevel, y, z, data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_read_native_scanlines(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , int ybegin
    , int yend
    , int z
    , void * data)
{
    try {
        *(return_) = (to_cpp(this_)) -> read_native_scanlines(subimage, miplevel, ybegin, yend, z, data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , void * data)
{
    try {
        *(return_) = (to_cpp(this_)) -> read_native_scanlines(subimage, miplevel, ybegin, yend, z, chbegin, chend, data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_read_native_tile(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , int subimage
    , int miplevel
    , int x
    , int y
    , int z
    , void * data)
{
    try {
        *(return_) = (to_cpp(this_)) -> read_native_tile(subimage, miplevel, x, y, z, data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , void * data)
{
    try {
        *(return_) = (to_cpp(this_)) -> read_native_tiles(subimage, miplevel, xbegin, xend, ybegin, yend, zbegin, zend, data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , void * data)
{
    try {
        *(return_) = (to_cpp(this_)) -> read_native_tiles(subimage, miplevel, xbegin, xend, ybegin, yend, zbegin, zend, chbegin, chend, data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_send_to_input(
    OIIO_ImageInput_t * this_
    , int * return_
    , char const * format)
{
    try {
        *(return_) = (to_cpp(this_)) -> send_to_input(format);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_send_to_client(
    OIIO_ImageInput_t * this_
    , int * return_
    , char const * format)
{
    try {
        *(return_) = (to_cpp(this_)) -> send_to_client(format);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_set_ioproxy(
    OIIO_ImageInput_t * this_
    , _Bool * return_
    , OIIO_Filesystem_IOProxy_t * ioproxy)
{
    try {
        *(return_) = (to_cpp(this_)) -> set_ioproxy(to_cpp(ioproxy));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_has_error(
    OIIO_ImageInput_t const * this_
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

unsigned int OpenImageIO_v2_3_6__ImageInput_geterror(
    OIIO_ImageInput_t const * this_
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

unsigned int OpenImageIO_v2_3_6__ImageInput_threads(
    OIIO_ImageInput_t * this_
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

unsigned int OpenImageIO_v2_3_6__ImageInput_threads_const(
    OIIO_ImageInput_t const * this_
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

unsigned int OpenImageIO_v2_3_6__ImageInput_lock(
    OIIO_ImageInput_t const * this_)
{
    try {
        (to_cpp(this_)) -> lock();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_unlock(
    OIIO_ImageInput_t const * this_)
{
    try {
        (to_cpp(this_)) -> unlock();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageInput_try_lock(
    OIIO_ImageInput_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> try_lock();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_create(
    std_ImageOutputPtr_t * return_
    , OIIO_string_view_t filename
    , OIIO_Filesystem_IOProxy_t * ioproxy
    , OIIO_string_view_t plugin_searchpath)
{
    try {
        new (return_) std::unique_ptr<OIIO::ImageOutput>(std::move(OpenImageIO_v2_3_6::ImageOutput::create(to_cpp_ref(&(filename)), to_cpp(ioproxy), to_cpp_ref(&(plugin_searchpath)))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_dtor(
    OIIO_ImageOutput_t * this_)
{
    try {
        delete to_cpp(this_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_format_name(
    OIIO_ImageOutput_t const * this_
    , char const * * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> format_name();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_supports(
    OIIO_ImageOutput_t const * this_
    , int * return_
    , OIIO_string_view_t feature)
{
    try {
        *(return_) = (to_cpp(this_)) -> supports(to_cpp_ref(&(feature)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_open(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , std_string_t const * name
    , OIIO_ImageSpec_t const * newspec
    , OIIO_ImageOutput_OpenMode mode)
{
    try {
        *(return_) = (to_cpp(this_)) -> open(to_cpp_ref(name), to_cpp_ref(newspec), OIIO_ImageOutput_OpenMode_to_cpp_ref(&(mode)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_open_subimage(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , std_string_t const * name
    , int subimages
    , OIIO_ImageSpec_t const * specs)
{
    try {
        *(return_) = (to_cpp(this_)) -> open(to_cpp_ref(name), subimages, to_cpp(specs));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_spec(
    OIIO_ImageOutput_t const * this_
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

unsigned int OpenImageIO_v2_3_6__ImageOutput_close(
    OIIO_ImageOutput_t * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> close();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_write_scanline(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , int y
    , int z
    , OIIO_TypeDesc_t format
    , void const * data
    , long xstride)
{
    try {
        *(return_) = (to_cpp(this_)) -> write_scanline(y, z, to_cpp_ref(&(format)), data, xstride);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_write_scanlines(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , int ybegin
    , int yend
    , int z
    , OIIO_TypeDesc_t format
    , void const * data
    , long xstride
    , long ystride)
{
    try {
        *(return_) = (to_cpp(this_)) -> write_scanlines(ybegin, yend, z, to_cpp_ref(&(format)), data, xstride, ystride);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , long zstride)
{
    try {
        *(return_) = (to_cpp(this_)) -> write_tile(x, y, z, to_cpp_ref(&(format)), data, xstride, ystride, zstride);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , long zstride)
{
    try {
        *(return_) = (to_cpp(this_)) -> write_tiles(xbegin, xend, ybegin, yend, zbegin, zend, to_cpp_ref(&(format)), data, xstride, ystride, zstride);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , long zstride)
{
    try {
        *(return_) = (to_cpp(this_)) -> write_rectangle(xbegin, xend, ybegin, yend, zbegin, zend, to_cpp_ref(&(format)), data, xstride, ystride, zstride);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_write_image(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , OIIO_TypeDesc_t format
    , void const * data
    , long xstride
    , long ystride
    , long zstride
    , OIIO_ProgressCallback_t progress_callback
    , void * progress_callback_data)
{
    try {
        *(return_) = (to_cpp(this_)) -> write_image(to_cpp_ref(&(format)), data, xstride, ystride, zstride, progress_callback, progress_callback_data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_write_deep_scanlines(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , int ybegin
    , int yend
    , int z
    , OIIO_DeepData_t const * deepdata)
{
    try {
        *(return_) = (to_cpp(this_)) -> write_deep_scanlines(ybegin, yend, z, to_cpp_ref(deepdata));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_write_deep_tiles(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend
    , OIIO_DeepData_t const * deepdata)
{
    try {
        *(return_) = (to_cpp(this_)) -> write_deep_tiles(xbegin, xend, ybegin, yend, zbegin, zend, to_cpp_ref(deepdata));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_write_deep_image(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , OIIO_DeepData_t const * deepdata)
{
    try {
        *(return_) = (to_cpp(this_)) -> write_deep_image(to_cpp_ref(deepdata));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_copy_image(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , OIIO_ImageInput_t * in)
{
    try {
        *(return_) = (to_cpp(this_)) -> copy_image(to_cpp(in));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_send_to_output(
    OIIO_ImageOutput_t * this_
    , int * return_
    , char const * format)
{
    try {
        *(return_) = (to_cpp(this_)) -> send_to_output(format);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_send_to_client(
    OIIO_ImageOutput_t * this_
    , int * return_
    , char const * format)
{
    try {
        *(return_) = (to_cpp(this_)) -> send_to_client(format);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_set_ioproxy(
    OIIO_ImageOutput_t * this_
    , _Bool * return_
    , OIIO_Filesystem_IOProxy_t * ioproxy)
{
    try {
        *(return_) = (to_cpp(this_)) -> set_ioproxy(to_cpp(ioproxy));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageOutput_has_error(
    OIIO_ImageOutput_t const * this_
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

unsigned int OpenImageIO_v2_3_6__ImageOutput_geterror(
    OIIO_ImageOutput_t const * this_
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

unsigned int OpenImageIO_v2_3_6__ImageOutput_threads(
    OIIO_ImageOutput_t * this_
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

unsigned int OpenImageIO_v2_3_6__ImageOutput_threads_const(
    OIIO_ImageOutput_t const * this_
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

unsigned int OpenImageIO_v2_3_6_roi_union(
    OIIO_ROI_t * return_
    , OIIO_ROI_t const * A
    , OIIO_ROI_t const * B)
{
        to_c_copy(return_, OpenImageIO_v2_3_6::roi_union(to_cpp_ref(A), to_cpp_ref(B)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6_roi_intersection(
    OIIO_ROI_t * return_
    , OIIO_ROI_t const * A
    , OIIO_ROI_t const * B)
{
        to_c_copy(return_, OpenImageIO_v2_3_6::roi_intersection(to_cpp_ref(A), to_cpp_ref(B)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6_openimageio_version(
    int * return_)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::openimageio_version();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_geterror(
    std_string_t * * return_
    , _Bool clear)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::geterror(clear));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_attribute(
    _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void const * val)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::attribute(to_cpp_ref(&(name)), to_cpp_ref(&(type)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_attribute_int(
    _Bool * return_
    , OIIO_string_view_t name
    , int val)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::attribute(to_cpp_ref(&(name)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_attribute_float(
    _Bool * return_
    , OIIO_string_view_t name
    , float val)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::attribute(to_cpp_ref(&(name)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_attribute_string(
    _Bool * return_
    , OIIO_string_view_t name
    , OIIO_string_view_t val)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::attribute(to_cpp_ref(&(name)), to_cpp_ref(&(val)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_getattribute(
    _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void * val)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::getattribute(to_cpp_ref(&(name)), to_cpp_ref(&(type)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_getattribute_int(
    _Bool * return_
    , OIIO_string_view_t name
    , int * val)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::getattribute(to_cpp_ref(&(name)), *(val));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_getattribute_float(
    _Bool * return_
    , OIIO_string_view_t name
    , float * val)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::getattribute(to_cpp_ref(&(name)), *(val));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_getattribute_string(
    _Bool * return_
    , OIIO_string_view_t name
    , std_string_t * val)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::getattribute(to_cpp_ref(&(name)), to_cpp_ref(val));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_getattribute_cstr(
    _Bool * return_
    , OIIO_string_view_t name
    , char * * val)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::getattribute(to_cpp_ref(&(name)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_get_int_attribute(
    int * return_
    , OIIO_string_view_t name
    , int defaultval)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::get_int_attribute(to_cpp_ref(&(name)), defaultval);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_get_float_attribute(
    float * return_
    , OIIO_string_view_t name
    , float defaultval)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::get_float_attribute(to_cpp_ref(&(name)), defaultval);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_get_string_attribute(
    OIIO_string_view_t * return_
    , OIIO_string_view_t name
    , OIIO_string_view_t defaultval)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::get_string_attribute(to_cpp_ref(&(name)), to_cpp_ref(&(defaultval))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_convert_pixel_values(
    _Bool * return_
    , OIIO_TypeDesc_t src_type
    , void const * src
    , OIIO_TypeDesc_t dst_type
    , void * dst
    , int n)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::convert_pixel_values(to_cpp_ref(&(src_type)), src, to_cpp_ref(&(dst_type)), dst, n);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_convert_types(
    _Bool * return_
    , OIIO_TypeDesc_t src_type
    , void const * src
    , OIIO_TypeDesc_t dst_type
    , void * dst
    , int n)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::convert_types(to_cpp_ref(&(src_type)), src, to_cpp_ref(&(dst_type)), dst, n);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , long dst_zstride)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::convert_image(nchannels, width, height, depth, src, to_cpp_ref(&(src_type)), src_xstride, src_ystride, src_zstride, dst, to_cpp_ref(&(dst_type)), dst_xstride, dst_ystride, dst_zstride);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::parallel_convert_image(nchannels, width, height, depth, src, to_cpp_ref(&(src_type)), src_xstride, src_ystride, src_zstride, dst, to_cpp_ref(&(dst_type)), dst_xstride, dst_ystride, dst_zstride, nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , int zorigin)
{
    try {
        OpenImageIO_v2_3_6::add_dither(nchannels, width, height, depth, data, xstride, ystride, zstride, ditheramplitude, alpha_channel, z_channel, ditherseed, chorigin, xorigin, yorigin, zorigin);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , int z_channel)
{
    try {
        OpenImageIO_v2_3_6::premult(nchannels, width, height, depth, chbegin, chend, to_cpp_ref(&(datatype)), data, xstride, ystride, zstride, alpha_channel, z_channel);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

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
    , long dst_zstride)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::copy_image(nchannels, width, height, depth, src, pixelsize, src_xstride, src_ystride, src_zstride, dst, dst_xstride, dst_ystride, dst_zstride);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_wrap_black(
    _Bool * return_
    , int * coord
    , int origin
    , int width)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::wrap_black(*(coord), origin, width);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_wrap_clamp(
    _Bool * return_
    , int * coord
    , int origin
    , int width)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::wrap_clamp(*(coord), origin, width);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_wrap_periodic(
    _Bool * return_
    , int * coord
    , int origin
    , int width)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::wrap_periodic(*(coord), origin, width);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_wrap_periodic_pow2(
    _Bool * return_
    , int * coord
    , int origin
    , int width)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::wrap_periodic_pow2(*(coord), origin, width);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_wrap_mirror(
    _Bool * return_
    , int * coord
    , int origin
    , int width)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::wrap_mirror(*(coord), origin, width);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_debug(
    OIIO_string_view_t str)
{
    try {
        OpenImageIO_v2_3_6::debug(to_cpp_ref(&(str)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ImageIO_force_link()
{
    try {
        OpenImageIO_v2_3_6::_ImageIO_force_link();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

