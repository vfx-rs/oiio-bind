#include "c-filter_private.h"

#include "c-string_view_private.h"

#include <stdexcept>

unsigned int OpenImageIO_v2_3_6__FilterDesc_sizeof()
{
        return sizeof(OpenImageIO_v2_3_6::FilterDesc);
}

unsigned int OpenImageIO_v2_3_6__FilterDesc_alignof()
{
        return alignof(OpenImageIO_v2_3_6::FilterDesc);
}

unsigned int OpenImageIO_v2_3_6__Filter1D_dtor(
    OIIO_Filter1D_t * this_)
{
    try {
        delete to_cpp(this_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter1D_width(
    OIIO_Filter1D_t const * this_
    , float * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> width();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter1D__op_call(
    OIIO_Filter1D_t const * this_
    , float * return_
    , float x)
{
    try {
        *(return_) = (to_cpp(this_)) -> operator()(x);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter1D_name(
    OIIO_Filter1D_t const * this_
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

unsigned int OpenImageIO_v2_3_6__Filter1D_create(
    OIIO_Filter1D_t * * return_
    , OIIO_string_view_t filtername
    , float width)
{
    try {
        to_c(return_, OpenImageIO_v2_3_6::Filter1D::create(to_cpp_ref(&(filtername)), width));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter1D_destroy(
    OIIO_Filter1D_t * filt)
{
    try {
        OpenImageIO_v2_3_6::Filter1D::destroy(to_cpp(filt));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter1D_num_filters(
    int * return_)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filter1D::num_filters();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter1D_get_filterdesc(
    int filternum
    , OIIO_FilterDesc_t * filterdesc)
{
    try {
        OpenImageIO_v2_3_6::Filter1D::get_filterdesc(filternum, to_cpp(filterdesc));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter1D__assign(
    OIIO_Filter1D_t * this_
    , OIIO_Filter1D_t * * return_
    , OIIO_Filter1D_t const * rhs)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter2D_dtor(
    OIIO_Filter2D_t * this_)
{
    try {
        delete to_cpp(this_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter2D_width(
    OIIO_Filter2D_t const * this_
    , float * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> width();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter2D_height(
    OIIO_Filter2D_t const * this_
    , float * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> height();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter2D_separable(
    OIIO_Filter2D_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> separable();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter2D_eval(
    OIIO_Filter2D_t const * this_
    , float * return_
    , float x
    , float y)
{
    try {
        *(return_) = (to_cpp(this_)) -> operator()(x, y);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter2D_xfilt(
    OIIO_Filter2D_t const * this_
    , float * return_
    , float x)
{
    try {
        *(return_) = (to_cpp(this_)) -> xfilt(x);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter2D_yfilt(
    OIIO_Filter2D_t const * this_
    , float * return_
    , float y)
{
    try {
        *(return_) = (to_cpp(this_)) -> yfilt(y);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter2D_name(
    OIIO_Filter2D_t const * this_
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

unsigned int OpenImageIO_v2_3_6__Filter2D_create(
    OIIO_Filter2D_t * * return_
    , OIIO_string_view_t filtername
    , float width
    , float height)
{
    try {
        to_c(return_, OpenImageIO_v2_3_6::Filter2D::create(to_cpp_ref(&(filtername)), width, height));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter2D_destroy(
    OIIO_Filter2D_t * filt)
{
    try {
        OpenImageIO_v2_3_6::Filter2D::destroy(to_cpp(filt));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter2D_num_filters(
    int * return_)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filter2D::num_filters();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter2D_get_filterdesc(
    int filternum
    , OIIO_FilterDesc_t * filterdesc)
{
    try {
        OpenImageIO_v2_3_6::Filter2D::get_filterdesc(filternum, to_cpp(filterdesc));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filter2D__assign(
    OIIO_Filter2D_t * this_
    , OIIO_Filter2D_t * * return_
    , OIIO_Filter2D_t const * rhs)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

