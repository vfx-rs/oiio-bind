#pragma once
#include <c-span.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/span.h>
#include <OpenImageIO/typedesc.h>
#include <cstring>

inline OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1> const & to_cpp_ref(
    OIIO_cspan_TypeDesc_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1> const * >(rhs));
}

inline OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1> & to_cpp_ref(
    OIIO_cspan_TypeDesc_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1> * >(rhs));
}

inline OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1> const * to_cpp(
    OIIO_cspan_TypeDesc_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1> const * >(rhs);
}

inline OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1> * to_cpp(
    OIIO_cspan_TypeDesc_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1> * >(rhs);
}

inline void to_c(
    OIIO_cspan_TypeDesc_t const * * lhs
    , OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1> const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_TypeDesc_t const * >(&(rhs));
}

inline void to_c(
    OIIO_cspan_TypeDesc_t const * * lhs
    , OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1> const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_TypeDesc_t const * >(rhs);
}

inline void to_c(
    OIIO_cspan_TypeDesc_t * * lhs
    , OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1> & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_TypeDesc_t * >(&(rhs));
}

inline void to_c(
    OIIO_cspan_TypeDesc_t * * lhs
    , OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1> * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_TypeDesc_t * >(rhs);
}

inline void to_c_copy(
    OIIO_cspan_TypeDesc_t * lhs
    , OpenImageIO_v2_3_6::span<const OpenImageIO_v2_3_6::TypeDesc, -1> const & rhs)
{
        OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__copy(lhs, reinterpret_cast<OIIO_cspan_TypeDesc_t const * >(&(rhs)));
}

inline OpenImageIO_v2_3_6::span<const float, -1> const & to_cpp_ref(
    OIIO_cspan_float_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::span<const float, -1> const * >(rhs));
}

inline OpenImageIO_v2_3_6::span<const float, -1> & to_cpp_ref(
    OIIO_cspan_float_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::span<const float, -1> * >(rhs));
}

inline OpenImageIO_v2_3_6::span<const float, -1> const * to_cpp(
    OIIO_cspan_float_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::span<const float, -1> const * >(rhs);
}

inline OpenImageIO_v2_3_6::span<const float, -1> * to_cpp(
    OIIO_cspan_float_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::span<const float, -1> * >(rhs);
}

inline void to_c(
    OIIO_cspan_float_t const * * lhs
    , OpenImageIO_v2_3_6::span<const float, -1> const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_float_t const * >(&(rhs));
}

inline void to_c(
    OIIO_cspan_float_t const * * lhs
    , OpenImageIO_v2_3_6::span<const float, -1> const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_float_t const * >(rhs);
}

inline void to_c(
    OIIO_cspan_float_t * * lhs
    , OpenImageIO_v2_3_6::span<const float, -1> & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_float_t * >(&(rhs));
}

inline void to_c(
    OIIO_cspan_float_t * * lhs
    , OpenImageIO_v2_3_6::span<const float, -1> * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_float_t * >(rhs);
}

inline void to_c_copy(
    OIIO_cspan_float_t * lhs
    , OpenImageIO_v2_3_6::span<const float, -1> const & rhs)
{
        OpenImageIO_v2_3_6__span_constfloat__1__copy(lhs, reinterpret_cast<OIIO_cspan_float_t const * >(&(rhs)));
}

inline OpenImageIO_v2_3_6::span<float, -1> const & to_cpp_ref(
    OIIO_span_float_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::span<float, -1> const * >(rhs));
}

inline OpenImageIO_v2_3_6::span<float, -1> & to_cpp_ref(
    OIIO_span_float_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::span<float, -1> * >(rhs));
}

inline OpenImageIO_v2_3_6::span<float, -1> const * to_cpp(
    OIIO_span_float_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::span<float, -1> const * >(rhs);
}

inline OpenImageIO_v2_3_6::span<float, -1> * to_cpp(
    OIIO_span_float_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::span<float, -1> * >(rhs);
}

inline void to_c(
    OIIO_span_float_t const * * lhs
    , OpenImageIO_v2_3_6::span<float, -1> const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_span_float_t const * >(&(rhs));
}

inline void to_c(
    OIIO_span_float_t const * * lhs
    , OpenImageIO_v2_3_6::span<float, -1> const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_span_float_t const * >(rhs);
}

inline void to_c(
    OIIO_span_float_t * * lhs
    , OpenImageIO_v2_3_6::span<float, -1> & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_span_float_t * >(&(rhs));
}

inline void to_c(
    OIIO_span_float_t * * lhs
    , OpenImageIO_v2_3_6::span<float, -1> * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_span_float_t * >(rhs);
}

inline void to_c_copy(
    OIIO_span_float_t * lhs
    , OpenImageIO_v2_3_6::span<float, -1> const & rhs)
{
        OpenImageIO_v2_3_6__span_float__1__copy(lhs, reinterpret_cast<OIIO_span_float_t const * >(&(rhs)));
}

inline OpenImageIO_v2_3_6::span<const unsigned int, -1> const & to_cpp_ref(
    OIIO_cspan_uint_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::span<const unsigned int, -1> const * >(rhs));
}

inline OpenImageIO_v2_3_6::span<const unsigned int, -1> & to_cpp_ref(
    OIIO_cspan_uint_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::span<const unsigned int, -1> * >(rhs));
}

inline OpenImageIO_v2_3_6::span<const unsigned int, -1> const * to_cpp(
    OIIO_cspan_uint_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::span<const unsigned int, -1> const * >(rhs);
}

inline OpenImageIO_v2_3_6::span<const unsigned int, -1> * to_cpp(
    OIIO_cspan_uint_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::span<const unsigned int, -1> * >(rhs);
}

inline void to_c(
    OIIO_cspan_uint_t const * * lhs
    , OpenImageIO_v2_3_6::span<const unsigned int, -1> const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_uint_t const * >(&(rhs));
}

inline void to_c(
    OIIO_cspan_uint_t const * * lhs
    , OpenImageIO_v2_3_6::span<const unsigned int, -1> const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_uint_t const * >(rhs);
}

inline void to_c(
    OIIO_cspan_uint_t * * lhs
    , OpenImageIO_v2_3_6::span<const unsigned int, -1> & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_uint_t * >(&(rhs));
}

inline void to_c(
    OIIO_cspan_uint_t * * lhs
    , OpenImageIO_v2_3_6::span<const unsigned int, -1> * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_uint_t * >(rhs);
}

inline void to_c_copy(
    OIIO_cspan_uint_t * lhs
    , OpenImageIO_v2_3_6::span<const unsigned int, -1> const & rhs)
{
        OpenImageIO_v2_3_6__span_constunsignedint__1__copy(lhs, reinterpret_cast<OIIO_cspan_uint_t const * >(&(rhs)));
}

inline OpenImageIO_v2_3_6::span<const int, -1> const & to_cpp_ref(
    OIIO_cspan_int_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::span<const int, -1> const * >(rhs));
}

inline OpenImageIO_v2_3_6::span<const int, -1> & to_cpp_ref(
    OIIO_cspan_int_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::span<const int, -1> * >(rhs));
}

inline OpenImageIO_v2_3_6::span<const int, -1> const * to_cpp(
    OIIO_cspan_int_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::span<const int, -1> const * >(rhs);
}

inline OpenImageIO_v2_3_6::span<const int, -1> * to_cpp(
    OIIO_cspan_int_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::span<const int, -1> * >(rhs);
}

inline void to_c(
    OIIO_cspan_int_t const * * lhs
    , OpenImageIO_v2_3_6::span<const int, -1> const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_int_t const * >(&(rhs));
}

inline void to_c(
    OIIO_cspan_int_t const * * lhs
    , OpenImageIO_v2_3_6::span<const int, -1> const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_int_t const * >(rhs);
}

inline void to_c(
    OIIO_cspan_int_t * * lhs
    , OpenImageIO_v2_3_6::span<const int, -1> & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_int_t * >(&(rhs));
}

inline void to_c(
    OIIO_cspan_int_t * * lhs
    , OpenImageIO_v2_3_6::span<const int, -1> * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_int_t * >(rhs);
}

inline void to_c_copy(
    OIIO_cspan_int_t * lhs
    , OpenImageIO_v2_3_6::span<const int, -1> const & rhs)
{
        OpenImageIO_v2_3_6__span_constint__1__copy(lhs, reinterpret_cast<OIIO_cspan_int_t const * >(&(rhs)));
}

inline OpenImageIO_v2_3_6::span<const char, -1> const & to_cpp_ref(
    OIIO_cspan_char_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::span<const char, -1> const * >(rhs));
}

inline OpenImageIO_v2_3_6::span<const char, -1> & to_cpp_ref(
    OIIO_cspan_char_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::span<const char, -1> * >(rhs));
}

inline OpenImageIO_v2_3_6::span<const char, -1> const * to_cpp(
    OIIO_cspan_char_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::span<const char, -1> const * >(rhs);
}

inline OpenImageIO_v2_3_6::span<const char, -1> * to_cpp(
    OIIO_cspan_char_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::span<const char, -1> * >(rhs);
}

inline void to_c(
    OIIO_cspan_char_t const * * lhs
    , OpenImageIO_v2_3_6::span<const char, -1> const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_char_t const * >(&(rhs));
}

inline void to_c(
    OIIO_cspan_char_t const * * lhs
    , OpenImageIO_v2_3_6::span<const char, -1> const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_char_t const * >(rhs);
}

inline void to_c(
    OIIO_cspan_char_t * * lhs
    , OpenImageIO_v2_3_6::span<const char, -1> & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_char_t * >(&(rhs));
}

inline void to_c(
    OIIO_cspan_char_t * * lhs
    , OpenImageIO_v2_3_6::span<const char, -1> * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_char_t * >(rhs);
}

inline void to_c_copy(
    OIIO_cspan_char_t * lhs
    , OpenImageIO_v2_3_6::span<const char, -1> const & rhs)
{
        OpenImageIO_v2_3_6__span_constchar__1__copy(lhs, reinterpret_cast<OIIO_cspan_char_t const * >(&(rhs)));
}

inline OpenImageIO_v2_3_6::span<const unsigned char, -1> const & to_cpp_ref(
    OIIO_cspan_uchar_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::span<const unsigned char, -1> const * >(rhs));
}

inline OpenImageIO_v2_3_6::span<const unsigned char, -1> & to_cpp_ref(
    OIIO_cspan_uchar_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::span<const unsigned char, -1> * >(rhs));
}

inline OpenImageIO_v2_3_6::span<const unsigned char, -1> const * to_cpp(
    OIIO_cspan_uchar_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::span<const unsigned char, -1> const * >(rhs);
}

inline OpenImageIO_v2_3_6::span<const unsigned char, -1> * to_cpp(
    OIIO_cspan_uchar_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::span<const unsigned char, -1> * >(rhs);
}

inline void to_c(
    OIIO_cspan_uchar_t const * * lhs
    , OpenImageIO_v2_3_6::span<const unsigned char, -1> const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_uchar_t const * >(&(rhs));
}

inline void to_c(
    OIIO_cspan_uchar_t const * * lhs
    , OpenImageIO_v2_3_6::span<const unsigned char, -1> const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_uchar_t const * >(rhs);
}

inline void to_c(
    OIIO_cspan_uchar_t * * lhs
    , OpenImageIO_v2_3_6::span<const unsigned char, -1> & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_uchar_t * >(&(rhs));
}

inline void to_c(
    OIIO_cspan_uchar_t * * lhs
    , OpenImageIO_v2_3_6::span<const unsigned char, -1> * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_uchar_t * >(rhs);
}

inline void to_c_copy(
    OIIO_cspan_uchar_t * lhs
    , OpenImageIO_v2_3_6::span<const unsigned char, -1> const & rhs)
{
        OpenImageIO_v2_3_6__span_constunsignedchar__1__copy(lhs, reinterpret_cast<OIIO_cspan_uchar_t const * >(&(rhs)));
}

inline OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1> const & to_cpp_ref(
    OIIO_cspan_string_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1> const * >(rhs));
}

inline OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1> & to_cpp_ref(
    OIIO_cspan_string_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1> * >(rhs));
}

inline OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1> const * to_cpp(
    OIIO_cspan_string_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1> const * >(rhs);
}

inline OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1> * to_cpp(
    OIIO_cspan_string_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1> * >(rhs);
}

inline void to_c(
    OIIO_cspan_string_t const * * lhs
    , OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1> const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_string_t const * >(&(rhs));
}

inline void to_c(
    OIIO_cspan_string_t const * * lhs
    , OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1> const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_string_t const * >(rhs);
}

inline void to_c(
    OIIO_cspan_string_t * * lhs
    , OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1> & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_string_t * >(&(rhs));
}

inline void to_c(
    OIIO_cspan_string_t * * lhs
    , OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1> * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_cspan_string_t * >(rhs);
}

inline void to_c_copy(
    OIIO_cspan_string_t * lhs
    , OpenImageIO_v2_3_6::span<const std::__cxx11::basic_string<char>, -1> const & rhs)
{
        OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__copy(lhs, reinterpret_cast<OIIO_cspan_string_t const * >(&(rhs)));
}

