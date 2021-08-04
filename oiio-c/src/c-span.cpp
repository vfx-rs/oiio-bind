#include "c-span_private.h"

#include "c-std_string_private.h"
#include "c-typedesc_private.h"
#include <new>

#include <stdexcept>

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__sizeof()
{
        return sizeof(OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1>);
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__alignof()
{
        return alignof(OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1>);
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__ctor(
    OIIO_cspan_TypeDesc_t * this_)
{
        new (this_) OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1>();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__copy(
    OIIO_cspan_TypeDesc_t * this_
    , OIIO_cspan_TypeDesc_t const * copy)
{
        new (this_) OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1>(to_cpp_ref(copy));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__from_ptr(
    OIIO_cspan_TypeDesc_t * this_
    , OIIO_TypeDesc_t const * data
    , long size)
{
        new (this_) OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1>(to_cpp(data), size);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__from_begin_end(
    OIIO_cspan_TypeDesc_t * this_
    , OIIO_TypeDesc_t const * b
    , OIIO_TypeDesc_t const * e)
{
        new (this_) OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1>(to_cpp(b), to_cpp(e));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__from_value(
    OIIO_cspan_TypeDesc_t * this_
    , OIIO_TypeDesc_t const * data)
{
    try {
        new (this_) OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1>(to_cpp_ref(data));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1___assign(
    OIIO_cspan_TypeDesc_t * this_
    , OIIO_cspan_TypeDesc_t * * return_
    , OIIO_cspan_TypeDesc_t const * copy)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(copy)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__size(
    OIIO_cspan_TypeDesc_t const * this_
    , long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__size_bytes(
    OIIO_cspan_TypeDesc_t const * this_
    , long * return_)
{
        *(return_) = (to_cpp(this_)) -> size_bytes();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__empty(
    OIIO_cspan_TypeDesc_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> empty();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__data(
    OIIO_cspan_TypeDesc_t const * this_
    , OIIO_TypeDesc_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> data());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1___index(
    OIIO_cspan_TypeDesc_t const * this_
    , OIIO_TypeDesc_t const * * return_
    , long idx)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator[](idx));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__at(
    OIIO_cspan_TypeDesc_t const * this_
    , OIIO_TypeDesc_t const * * return_
    , long idx)
{
    try {
        to_c(return_, (to_cpp(this_)) -> at(idx));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__begin(
    OIIO_cspan_TypeDesc_t const * this_
    , OIIO_TypeDesc_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> begin());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__end(
    OIIO_cspan_TypeDesc_t const * this_
    , OIIO_TypeDesc_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> end());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__cbegin(
    OIIO_cspan_TypeDesc_t const * this_
    , OIIO_TypeDesc_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> cbegin());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__cend(
    OIIO_cspan_TypeDesc_t const * this_
    , OIIO_TypeDesc_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> cend());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1__sizeof()
{
        return sizeof(OpenImageIO_v2_3_6::span<const float, -1>);
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1__alignof()
{
        return alignof(OpenImageIO_v2_3_6::span<const float, -1>);
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1__ctor(
    OIIO_cspan_float_t * this_)
{
        new (this_) OpenImageIO_v2_3_6::span<const float, -1>();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1__copy(
    OIIO_cspan_float_t * this_
    , OIIO_cspan_float_t const * copy)
{
        new (this_) OpenImageIO_v2_3_6::span<const float, -1>(to_cpp_ref(copy));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1__from_ptr(
    OIIO_cspan_float_t * this_
    , float const * data
    , long size)
{
        new (this_) OpenImageIO_v2_3_6::span<const float, -1>(data, size);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1__from_begin_end(
    OIIO_cspan_float_t * this_
    , float const * b
    , float const * e)
{
        new (this_) OpenImageIO_v2_3_6::span<const float, -1>(b, e);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1__from_value(
    OIIO_cspan_float_t * this_
    , float const * data)
{
    try {
        new (this_) OpenImageIO_v2_3_6::span<const float, -1>(*(data));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1___assign(
    OIIO_cspan_float_t * this_
    , OIIO_cspan_float_t * * return_
    , OIIO_cspan_float_t const * copy)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(copy)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1__size(
    OIIO_cspan_float_t const * this_
    , long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1__size_bytes(
    OIIO_cspan_float_t const * this_
    , long * return_)
{
        *(return_) = (to_cpp(this_)) -> size_bytes();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1__empty(
    OIIO_cspan_float_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> empty();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1__data(
    OIIO_cspan_float_t const * this_
    , float const * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1___index(
    OIIO_cspan_float_t const * this_
    , float const * * return_
    , long idx)
{
    try {
        *(return_) = &((to_cpp(this_)) -> operator[](idx));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1__at(
    OIIO_cspan_float_t const * this_
    , float const * * return_
    , long idx)
{
    try {
        *(return_) = &((to_cpp(this_)) -> at(idx));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1__begin(
    OIIO_cspan_float_t const * this_
    , float const * * return_)
{
        *(return_) = (to_cpp(this_)) -> begin();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1__end(
    OIIO_cspan_float_t const * this_
    , float const * * return_)
{
        *(return_) = (to_cpp(this_)) -> end();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1__cbegin(
    OIIO_cspan_float_t const * this_
    , float const * * return_)
{
        *(return_) = (to_cpp(this_)) -> cbegin();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constfloat__1__cend(
    OIIO_cspan_float_t const * this_
    , float const * * return_)
{
        *(return_) = (to_cpp(this_)) -> cend();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_float__1__sizeof()
{
        return sizeof(OpenImageIO_v2_3_6::span<float, -1>);
}

unsigned int OpenImageIO_v2_3_6__span_float__1__alignof()
{
        return alignof(OpenImageIO_v2_3_6::span<float, -1>);
}

unsigned int OpenImageIO_v2_3_6__span_float__1__ctor(
    OIIO_span_float_t * this_)
{
        new (this_) OpenImageIO_v2_3_6::span<float, -1>();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_float__1__copy(
    OIIO_span_float_t * this_
    , OIIO_span_float_t const * copy)
{
        new (this_) OpenImageIO_v2_3_6::span<float, -1>(to_cpp_ref(copy));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_float__1__from_ptr(
    OIIO_span_float_t * this_
    , float * data
    , long size)
{
        new (this_) OpenImageIO_v2_3_6::span<float, -1>(data, size);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_float__1__from_begin_end(
    OIIO_span_float_t * this_
    , float * b
    , float * e)
{
        new (this_) OpenImageIO_v2_3_6::span<float, -1>(b, e);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_float__1__from_value(
    OIIO_span_float_t * this_
    , float * data)
{
    try {
        new (this_) OpenImageIO_v2_3_6::span<float, -1>(*(data));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_float__1___assign(
    OIIO_span_float_t * this_
    , OIIO_span_float_t * * return_
    , OIIO_span_float_t const * copy)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(copy)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_float__1__size(
    OIIO_span_float_t const * this_
    , long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_float__1__size_bytes(
    OIIO_span_float_t const * this_
    , long * return_)
{
        *(return_) = (to_cpp(this_)) -> size_bytes();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_float__1__empty(
    OIIO_span_float_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> empty();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_float__1__data(
    OIIO_span_float_t const * this_
    , float * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_float__1___index(
    OIIO_span_float_t const * this_
    , float * * return_
    , long idx)
{
    try {
        *(return_) = &((to_cpp(this_)) -> operator[](idx));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_float__1__at(
    OIIO_span_float_t const * this_
    , float * * return_
    , long idx)
{
    try {
        *(return_) = &((to_cpp(this_)) -> at(idx));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_float__1__begin(
    OIIO_span_float_t const * this_
    , float * * return_)
{
        *(return_) = (to_cpp(this_)) -> begin();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_float__1__end(
    OIIO_span_float_t const * this_
    , float * * return_)
{
        *(return_) = (to_cpp(this_)) -> end();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_float__1__cbegin(
    OIIO_span_float_t const * this_
    , float const * * return_)
{
        *(return_) = (to_cpp(this_)) -> cbegin();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_float__1__cend(
    OIIO_span_float_t const * this_
    , float const * * return_)
{
        *(return_) = (to_cpp(this_)) -> cend();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__sizeof()
{
        return sizeof(OpenImageIO_v2_3_6::span<const unsigned int, -1>);
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__alignof()
{
        return alignof(OpenImageIO_v2_3_6::span<const unsigned int, -1>);
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__ctor(
    OIIO_cspan_uint_t * this_)
{
        new (this_) OpenImageIO_v2_3_6::span<const unsigned int, -1>();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__copy(
    OIIO_cspan_uint_t * this_
    , OIIO_cspan_uint_t const * copy)
{
        new (this_) OpenImageIO_v2_3_6::span<const unsigned int, -1>(to_cpp_ref(copy));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__from_ptr(
    OIIO_cspan_uint_t * this_
    , unsigned int const * data
    , long size)
{
        new (this_) OpenImageIO_v2_3_6::span<const unsigned int, -1>(data, size);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__from_begin_end(
    OIIO_cspan_uint_t * this_
    , unsigned int const * b
    , unsigned int const * e)
{
        new (this_) OpenImageIO_v2_3_6::span<const unsigned int, -1>(b, e);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__from_value(
    OIIO_cspan_uint_t * this_
    , unsigned int const * data)
{
    try {
        new (this_) OpenImageIO_v2_3_6::span<const unsigned int, -1>(*(data));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1___assign(
    OIIO_cspan_uint_t * this_
    , OIIO_cspan_uint_t * * return_
    , OIIO_cspan_uint_t const * copy)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(copy)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__size(
    OIIO_cspan_uint_t const * this_
    , long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__size_bytes(
    OIIO_cspan_uint_t const * this_
    , long * return_)
{
        *(return_) = (to_cpp(this_)) -> size_bytes();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__empty(
    OIIO_cspan_uint_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> empty();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__data(
    OIIO_cspan_uint_t const * this_
    , unsigned int const * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1___index(
    OIIO_cspan_uint_t const * this_
    , unsigned int const * * return_
    , long idx)
{
    try {
        *(return_) = &((to_cpp(this_)) -> operator[](idx));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__at(
    OIIO_cspan_uint_t const * this_
    , unsigned int const * * return_
    , long idx)
{
    try {
        *(return_) = &((to_cpp(this_)) -> at(idx));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__begin(
    OIIO_cspan_uint_t const * this_
    , unsigned int const * * return_)
{
        *(return_) = (to_cpp(this_)) -> begin();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__end(
    OIIO_cspan_uint_t const * this_
    , unsigned int const * * return_)
{
        *(return_) = (to_cpp(this_)) -> end();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__cbegin(
    OIIO_cspan_uint_t const * this_
    , unsigned int const * * return_)
{
        *(return_) = (to_cpp(this_)) -> cbegin();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__cend(
    OIIO_cspan_uint_t const * this_
    , unsigned int const * * return_)
{
        *(return_) = (to_cpp(this_)) -> cend();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constint__1__sizeof()
{
        return sizeof(OpenImageIO_v2_3_6::span<const int, -1>);
}

unsigned int OpenImageIO_v2_3_6__span_constint__1__alignof()
{
        return alignof(OpenImageIO_v2_3_6::span<const int, -1>);
}

unsigned int OpenImageIO_v2_3_6__span_constint__1__ctor(
    OIIO_cspan_int_t * this_)
{
        new (this_) OpenImageIO_v2_3_6::span<const int, -1>();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constint__1__copy(
    OIIO_cspan_int_t * this_
    , OIIO_cspan_int_t const * copy)
{
        new (this_) OpenImageIO_v2_3_6::span<const int, -1>(to_cpp_ref(copy));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constint__1__from_ptr(
    OIIO_cspan_int_t * this_
    , int const * data
    , long size)
{
        new (this_) OpenImageIO_v2_3_6::span<const int, -1>(data, size);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constint__1__from_begin_end(
    OIIO_cspan_int_t * this_
    , int const * b
    , int const * e)
{
        new (this_) OpenImageIO_v2_3_6::span<const int, -1>(b, e);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constint__1__from_value(
    OIIO_cspan_int_t * this_
    , int const * data)
{
    try {
        new (this_) OpenImageIO_v2_3_6::span<const int, -1>(*(data));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constint__1___assign(
    OIIO_cspan_int_t * this_
    , OIIO_cspan_int_t * * return_
    , OIIO_cspan_int_t const * copy)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(copy)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constint__1__size(
    OIIO_cspan_int_t const * this_
    , long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constint__1__size_bytes(
    OIIO_cspan_int_t const * this_
    , long * return_)
{
        *(return_) = (to_cpp(this_)) -> size_bytes();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constint__1__empty(
    OIIO_cspan_int_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> empty();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constint__1__data(
    OIIO_cspan_int_t const * this_
    , int const * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constint__1___index(
    OIIO_cspan_int_t const * this_
    , int const * * return_
    , long idx)
{
    try {
        *(return_) = &((to_cpp(this_)) -> operator[](idx));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constint__1__at(
    OIIO_cspan_int_t const * this_
    , int const * * return_
    , long idx)
{
    try {
        *(return_) = &((to_cpp(this_)) -> at(idx));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constint__1__begin(
    OIIO_cspan_int_t const * this_
    , int const * * return_)
{
        *(return_) = (to_cpp(this_)) -> begin();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constint__1__end(
    OIIO_cspan_int_t const * this_
    , int const * * return_)
{
        *(return_) = (to_cpp(this_)) -> end();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constint__1__cbegin(
    OIIO_cspan_int_t const * this_
    , int const * * return_)
{
        *(return_) = (to_cpp(this_)) -> cbegin();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constint__1__cend(
    OIIO_cspan_int_t const * this_
    , int const * * return_)
{
        *(return_) = (to_cpp(this_)) -> cend();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1__sizeof()
{
        return sizeof(OpenImageIO_v2_3_6::span<const char, -1>);
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1__alignof()
{
        return alignof(OpenImageIO_v2_3_6::span<const char, -1>);
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1__ctor(
    OIIO_cspan_char_t * this_)
{
        new (this_) OpenImageIO_v2_3_6::span<const char, -1>();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1__copy(
    OIIO_cspan_char_t * this_
    , OIIO_cspan_char_t const * copy)
{
        new (this_) OpenImageIO_v2_3_6::span<const char, -1>(to_cpp_ref(copy));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1__from_ptr(
    OIIO_cspan_char_t * this_
    , char const * data
    , long size)
{
        new (this_) OpenImageIO_v2_3_6::span<const char, -1>(data, size);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1__from_begin_end(
    OIIO_cspan_char_t * this_
    , char const * b
    , char const * e)
{
        new (this_) OpenImageIO_v2_3_6::span<const char, -1>(b, e);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1__from_value(
    OIIO_cspan_char_t * this_
    , char const * data)
{
    try {
        new (this_) OpenImageIO_v2_3_6::span<const char, -1>(*(data));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1___assign(
    OIIO_cspan_char_t * this_
    , OIIO_cspan_char_t * * return_
    , OIIO_cspan_char_t const * copy)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(copy)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1__size(
    OIIO_cspan_char_t const * this_
    , long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1__size_bytes(
    OIIO_cspan_char_t const * this_
    , long * return_)
{
        *(return_) = (to_cpp(this_)) -> size_bytes();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1__empty(
    OIIO_cspan_char_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> empty();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1__data(
    OIIO_cspan_char_t const * this_
    , char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1___index(
    OIIO_cspan_char_t const * this_
    , char const * * return_
    , long idx)
{
    try {
        *(return_) = &((to_cpp(this_)) -> operator[](idx));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1__at(
    OIIO_cspan_char_t const * this_
    , char const * * return_
    , long idx)
{
    try {
        *(return_) = &((to_cpp(this_)) -> at(idx));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1__begin(
    OIIO_cspan_char_t const * this_
    , char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> begin();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1__end(
    OIIO_cspan_char_t const * this_
    , char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> end();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1__cbegin(
    OIIO_cspan_char_t const * this_
    , char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> cbegin();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constchar__1__cend(
    OIIO_cspan_char_t const * this_
    , char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> cend();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__sizeof()
{
        return sizeof(OpenImageIO_v2_3_6::span<const unsigned char, -1>);
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__alignof()
{
        return alignof(OpenImageIO_v2_3_6::span<const unsigned char, -1>);
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__ctor(
    OIIO_cspan_uchar_t * this_)
{
        new (this_) OpenImageIO_v2_3_6::span<const unsigned char, -1>();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__copy(
    OIIO_cspan_uchar_t * this_
    , OIIO_cspan_uchar_t const * copy)
{
        new (this_) OpenImageIO_v2_3_6::span<const unsigned char, -1>(to_cpp_ref(copy));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__from_ptr(
    OIIO_cspan_uchar_t * this_
    , unsigned char const * data
    , long size)
{
        new (this_) OpenImageIO_v2_3_6::span<const unsigned char, -1>(data, size);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__from_begin_end(
    OIIO_cspan_uchar_t * this_
    , unsigned char const * b
    , unsigned char const * e)
{
        new (this_) OpenImageIO_v2_3_6::span<const unsigned char, -1>(b, e);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__from_value(
    OIIO_cspan_uchar_t * this_
    , unsigned char const * data)
{
    try {
        new (this_) OpenImageIO_v2_3_6::span<const unsigned char, -1>(*(data));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1___assign(
    OIIO_cspan_uchar_t * this_
    , OIIO_cspan_uchar_t * * return_
    , OIIO_cspan_uchar_t const * copy)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(copy)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__size(
    OIIO_cspan_uchar_t const * this_
    , long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__size_bytes(
    OIIO_cspan_uchar_t const * this_
    , long * return_)
{
        *(return_) = (to_cpp(this_)) -> size_bytes();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__empty(
    OIIO_cspan_uchar_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> empty();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__data(
    OIIO_cspan_uchar_t const * this_
    , unsigned char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1___index(
    OIIO_cspan_uchar_t const * this_
    , unsigned char const * * return_
    , long idx)
{
    try {
        *(return_) = &((to_cpp(this_)) -> operator[](idx));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__at(
    OIIO_cspan_uchar_t const * this_
    , unsigned char const * * return_
    , long idx)
{
    try {
        *(return_) = &((to_cpp(this_)) -> at(idx));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__begin(
    OIIO_cspan_uchar_t const * this_
    , unsigned char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> begin();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__end(
    OIIO_cspan_uchar_t const * this_
    , unsigned char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> end();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__cbegin(
    OIIO_cspan_uchar_t const * this_
    , unsigned char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> cbegin();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__cend(
    OIIO_cspan_uchar_t const * this_
    , unsigned char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> cend();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__sizeof()
{
        return sizeof(OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1>);
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__alignof()
{
        return alignof(OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1>);
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__ctor(
    OIIO_cspan_string_t * this_)
{
        new (this_) OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1>();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__copy(
    OIIO_cspan_string_t * this_
    , OIIO_cspan_string_t const * copy)
{
        new (this_) OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1>(to_cpp_ref(copy));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__from_ptr(
    OIIO_cspan_string_t * this_
    , std_string_t const * data
    , long size)
{
        new (this_) OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1>(to_cpp(data), size);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__from_begin_end(
    OIIO_cspan_string_t * this_
    , std_string_t const * b
    , std_string_t const * e)
{
        new (this_) OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1>(to_cpp(b), to_cpp(e));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__from_value(
    OIIO_cspan_string_t * this_
    , std_string_t const * data)
{
    try {
        new (this_) OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1>(to_cpp_ref(data));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1___assign(
    OIIO_cspan_string_t * this_
    , OIIO_cspan_string_t * * return_
    , OIIO_cspan_string_t const * copy)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(copy)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__size(
    OIIO_cspan_string_t const * this_
    , long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__size_bytes(
    OIIO_cspan_string_t const * this_
    , long * return_)
{
        *(return_) = (to_cpp(this_)) -> size_bytes();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__empty(
    OIIO_cspan_string_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> empty();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__data(
    OIIO_cspan_string_t const * this_
    , std_string_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> data());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1___index(
    OIIO_cspan_string_t const * this_
    , std_string_t const * * return_
    , long idx)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator[](idx));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__at(
    OIIO_cspan_string_t const * this_
    , std_string_t const * * return_
    , long idx)
{
    try {
        to_c(return_, (to_cpp(this_)) -> at(idx));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__begin(
    OIIO_cspan_string_t const * this_
    , std_string_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> begin());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__end(
    OIIO_cspan_string_t const * this_
    , std_string_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> end());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__cbegin(
    OIIO_cspan_string_t const * this_
    , std_string_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> cbegin());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__cend(
    OIIO_cspan_string_t const * this_
    , std_string_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> cend());
        return 0;
}

