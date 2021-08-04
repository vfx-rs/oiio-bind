#pragma once
#include <c-std_vector.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/string_view.h>
#include <OpenImageIO/typedesc.h>
#include <OpenImageIO/ustring.h>
#include <cstring>
#include <string>
#include <vector>

inline std::vector<std::string> const & to_cpp_ref(
    std_vector_string_t const * rhs)
{
        return *(reinterpret_cast<std::vector<std::string> const * >(rhs));
}

inline std::vector<std::string> & to_cpp_ref(
    std_vector_string_t * rhs)
{
        return *(reinterpret_cast<std::vector<std::string> * >(rhs));
}

inline std::vector<std::string> const * to_cpp(
    std_vector_string_t const * rhs)
{
        return reinterpret_cast<std::vector<std::string> const * >(rhs);
}

inline std::vector<std::string> * to_cpp(
    std_vector_string_t * rhs)
{
        return reinterpret_cast<std::vector<std::string> * >(rhs);
}

inline void to_c(
    std_vector_string_t const * * lhs
    , std::vector<std::string> const & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_string_t const * >(&(rhs));
}

inline void to_c(
    std_vector_string_t const * * lhs
    , std::vector<std::string> const * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_string_t const * >(rhs);
}

inline void to_c(
    std_vector_string_t * * lhs
    , std::vector<std::string> & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_string_t * >(&(rhs));
}

inline void to_c(
    std_vector_string_t * * lhs
    , std::vector<std::string> * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_string_t * >(rhs);
}

inline void to_c_copy(
    std_vector_string_t * * lhs
    , std::vector<std::string> const & rhs)
{
        std__vector_std__string__copy(lhs, reinterpret_cast<std_vector_string_t const * >(&(rhs)));
}

inline std::vector<OIIO::string_view> const & to_cpp_ref(
    std_vector_string_view_t const * rhs)
{
        return *(reinterpret_cast<std::vector<OIIO::string_view> const * >(rhs));
}

inline std::vector<OIIO::string_view> & to_cpp_ref(
    std_vector_string_view_t * rhs)
{
        return *(reinterpret_cast<std::vector<OIIO::string_view> * >(rhs));
}

inline std::vector<OIIO::string_view> const * to_cpp(
    std_vector_string_view_t const * rhs)
{
        return reinterpret_cast<std::vector<OIIO::string_view> const * >(rhs);
}

inline std::vector<OIIO::string_view> * to_cpp(
    std_vector_string_view_t * rhs)
{
        return reinterpret_cast<std::vector<OIIO::string_view> * >(rhs);
}

inline void to_c(
    std_vector_string_view_t const * * lhs
    , std::vector<OIIO::string_view> const & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_string_view_t const * >(&(rhs));
}

inline void to_c(
    std_vector_string_view_t const * * lhs
    , std::vector<OIIO::string_view> const * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_string_view_t const * >(rhs);
}

inline void to_c(
    std_vector_string_view_t * * lhs
    , std::vector<OIIO::string_view> & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_string_view_t * >(&(rhs));
}

inline void to_c(
    std_vector_string_view_t * * lhs
    , std::vector<OIIO::string_view> * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_string_view_t * >(rhs);
}

inline void to_c_copy(
    std_vector_string_view_t * * lhs
    , std::vector<OIIO::string_view> const & rhs)
{
        std__vector_OIIO__string_view__copy(lhs, reinterpret_cast<std_vector_string_view_t const * >(&(rhs)));
}

inline std::vector<OIIO::ustring> const & to_cpp_ref(
    std_vector_ustring_t const * rhs)
{
        return *(reinterpret_cast<std::vector<OIIO::ustring> const * >(rhs));
}

inline std::vector<OIIO::ustring> & to_cpp_ref(
    std_vector_ustring_t * rhs)
{
        return *(reinterpret_cast<std::vector<OIIO::ustring> * >(rhs));
}

inline std::vector<OIIO::ustring> const * to_cpp(
    std_vector_ustring_t const * rhs)
{
        return reinterpret_cast<std::vector<OIIO::ustring> const * >(rhs);
}

inline std::vector<OIIO::ustring> * to_cpp(
    std_vector_ustring_t * rhs)
{
        return reinterpret_cast<std::vector<OIIO::ustring> * >(rhs);
}

inline void to_c(
    std_vector_ustring_t const * * lhs
    , std::vector<OIIO::ustring> const & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_ustring_t const * >(&(rhs));
}

inline void to_c(
    std_vector_ustring_t const * * lhs
    , std::vector<OIIO::ustring> const * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_ustring_t const * >(rhs);
}

inline void to_c(
    std_vector_ustring_t * * lhs
    , std::vector<OIIO::ustring> & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_ustring_t * >(&(rhs));
}

inline void to_c(
    std_vector_ustring_t * * lhs
    , std::vector<OIIO::ustring> * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_ustring_t * >(rhs);
}

inline void to_c_copy(
    std_vector_ustring_t * * lhs
    , std::vector<OIIO::ustring> const & rhs)
{
        std__vector_OIIO__ustring__copy(lhs, reinterpret_cast<std_vector_ustring_t const * >(&(rhs)));
}

inline std::vector<char> const & to_cpp_ref(
    std_vector_char_t const * rhs)
{
        return *(reinterpret_cast<std::vector<char> const * >(rhs));
}

inline std::vector<char> & to_cpp_ref(
    std_vector_char_t * rhs)
{
        return *(reinterpret_cast<std::vector<char> * >(rhs));
}

inline std::vector<char> const * to_cpp(
    std_vector_char_t const * rhs)
{
        return reinterpret_cast<std::vector<char> const * >(rhs);
}

inline std::vector<char> * to_cpp(
    std_vector_char_t * rhs)
{
        return reinterpret_cast<std::vector<char> * >(rhs);
}

inline void to_c(
    std_vector_char_t const * * lhs
    , std::vector<char> const & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_char_t const * >(&(rhs));
}

inline void to_c(
    std_vector_char_t const * * lhs
    , std::vector<char> const * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_char_t const * >(rhs);
}

inline void to_c(
    std_vector_char_t * * lhs
    , std::vector<char> & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_char_t * >(&(rhs));
}

inline void to_c(
    std_vector_char_t * * lhs
    , std::vector<char> * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_char_t * >(rhs);
}

inline void to_c_copy(
    std_vector_char_t * * lhs
    , std::vector<char> const & rhs)
{
        std__vector_char__copy(lhs, reinterpret_cast<std_vector_char_t const * >(&(rhs)));
}

inline std::vector<unsigned char> const & to_cpp_ref(
    std_vector_uchar_t const * rhs)
{
        return *(reinterpret_cast<std::vector<unsigned char> const * >(rhs));
}

inline std::vector<unsigned char> & to_cpp_ref(
    std_vector_uchar_t * rhs)
{
        return *(reinterpret_cast<std::vector<unsigned char> * >(rhs));
}

inline std::vector<unsigned char> const * to_cpp(
    std_vector_uchar_t const * rhs)
{
        return reinterpret_cast<std::vector<unsigned char> const * >(rhs);
}

inline std::vector<unsigned char> * to_cpp(
    std_vector_uchar_t * rhs)
{
        return reinterpret_cast<std::vector<unsigned char> * >(rhs);
}

inline void to_c(
    std_vector_uchar_t const * * lhs
    , std::vector<unsigned char> const & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_uchar_t const * >(&(rhs));
}

inline void to_c(
    std_vector_uchar_t const * * lhs
    , std::vector<unsigned char> const * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_uchar_t const * >(rhs);
}

inline void to_c(
    std_vector_uchar_t * * lhs
    , std::vector<unsigned char> & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_uchar_t * >(&(rhs));
}

inline void to_c(
    std_vector_uchar_t * * lhs
    , std::vector<unsigned char> * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_uchar_t * >(rhs);
}

inline void to_c_copy(
    std_vector_uchar_t * * lhs
    , std::vector<unsigned char> const & rhs)
{
        std__vector_unsignedchar__copy(lhs, reinterpret_cast<std_vector_uchar_t const * >(&(rhs)));
}

inline std::vector<float> const & to_cpp_ref(
    std_vector_float_t const * rhs)
{
        return *(reinterpret_cast<std::vector<float> const * >(rhs));
}

inline std::vector<float> & to_cpp_ref(
    std_vector_float_t * rhs)
{
        return *(reinterpret_cast<std::vector<float> * >(rhs));
}

inline std::vector<float> const * to_cpp(
    std_vector_float_t const * rhs)
{
        return reinterpret_cast<std::vector<float> const * >(rhs);
}

inline std::vector<float> * to_cpp(
    std_vector_float_t * rhs)
{
        return reinterpret_cast<std::vector<float> * >(rhs);
}

inline void to_c(
    std_vector_float_t const * * lhs
    , std::vector<float> const & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_float_t const * >(&(rhs));
}

inline void to_c(
    std_vector_float_t const * * lhs
    , std::vector<float> const * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_float_t const * >(rhs);
}

inline void to_c(
    std_vector_float_t * * lhs
    , std::vector<float> & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_float_t * >(&(rhs));
}

inline void to_c(
    std_vector_float_t * * lhs
    , std::vector<float> * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_float_t * >(rhs);
}

inline void to_c_copy(
    std_vector_float_t * * lhs
    , std::vector<float> const & rhs)
{
        std__vector_float__copy(lhs, reinterpret_cast<std_vector_float_t const * >(&(rhs)));
}

inline std::vector<unsigned long> const & to_cpp_ref(
    std_vector_ulong_t const * rhs)
{
        return *(reinterpret_cast<std::vector<unsigned long> const * >(rhs));
}

inline std::vector<unsigned long> & to_cpp_ref(
    std_vector_ulong_t * rhs)
{
        return *(reinterpret_cast<std::vector<unsigned long> * >(rhs));
}

inline std::vector<unsigned long> const * to_cpp(
    std_vector_ulong_t const * rhs)
{
        return reinterpret_cast<std::vector<unsigned long> const * >(rhs);
}

inline std::vector<unsigned long> * to_cpp(
    std_vector_ulong_t * rhs)
{
        return reinterpret_cast<std::vector<unsigned long> * >(rhs);
}

inline void to_c(
    std_vector_ulong_t const * * lhs
    , std::vector<unsigned long> const & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_ulong_t const * >(&(rhs));
}

inline void to_c(
    std_vector_ulong_t const * * lhs
    , std::vector<unsigned long> const * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_ulong_t const * >(rhs);
}

inline void to_c(
    std_vector_ulong_t * * lhs
    , std::vector<unsigned long> & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_ulong_t * >(&(rhs));
}

inline void to_c(
    std_vector_ulong_t * * lhs
    , std::vector<unsigned long> * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_ulong_t * >(rhs);
}

inline void to_c_copy(
    std_vector_ulong_t * * lhs
    , std::vector<unsigned long> const & rhs)
{
        std__vector_unsignedlong__copy(lhs, reinterpret_cast<std_vector_ulong_t const * >(&(rhs)));
}

inline std::vector<int> const & to_cpp_ref(
    std_vector_int_t const * rhs)
{
        return *(reinterpret_cast<std::vector<int> const * >(rhs));
}

inline std::vector<int> & to_cpp_ref(
    std_vector_int_t * rhs)
{
        return *(reinterpret_cast<std::vector<int> * >(rhs));
}

inline std::vector<int> const * to_cpp(
    std_vector_int_t const * rhs)
{
        return reinterpret_cast<std::vector<int> const * >(rhs);
}

inline std::vector<int> * to_cpp(
    std_vector_int_t * rhs)
{
        return reinterpret_cast<std::vector<int> * >(rhs);
}

inline void to_c(
    std_vector_int_t const * * lhs
    , std::vector<int> const & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_int_t const * >(&(rhs));
}

inline void to_c(
    std_vector_int_t const * * lhs
    , std::vector<int> const * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_int_t const * >(rhs);
}

inline void to_c(
    std_vector_int_t * * lhs
    , std::vector<int> & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_int_t * >(&(rhs));
}

inline void to_c(
    std_vector_int_t * * lhs
    , std::vector<int> * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_int_t * >(rhs);
}

inline void to_c_copy(
    std_vector_int_t * * lhs
    , std::vector<int> const & rhs)
{
        std__vector_int__copy(lhs, reinterpret_cast<std_vector_int_t const * >(&(rhs)));
}

inline std::vector<OIIO::TypeDesc> const & to_cpp_ref(
    std_vector_typedesc_t const * rhs)
{
        return *(reinterpret_cast<std::vector<OIIO::TypeDesc> const * >(rhs));
}

inline std::vector<OIIO::TypeDesc> & to_cpp_ref(
    std_vector_typedesc_t * rhs)
{
        return *(reinterpret_cast<std::vector<OIIO::TypeDesc> * >(rhs));
}

inline std::vector<OIIO::TypeDesc> const * to_cpp(
    std_vector_typedesc_t const * rhs)
{
        return reinterpret_cast<std::vector<OIIO::TypeDesc> const * >(rhs);
}

inline std::vector<OIIO::TypeDesc> * to_cpp(
    std_vector_typedesc_t * rhs)
{
        return reinterpret_cast<std::vector<OIIO::TypeDesc> * >(rhs);
}

inline void to_c(
    std_vector_typedesc_t const * * lhs
    , std::vector<OIIO::TypeDesc> const & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_typedesc_t const * >(&(rhs));
}

inline void to_c(
    std_vector_typedesc_t const * * lhs
    , std::vector<OIIO::TypeDesc> const * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_typedesc_t const * >(rhs);
}

inline void to_c(
    std_vector_typedesc_t * * lhs
    , std::vector<OIIO::TypeDesc> & rhs)
{
        *(lhs) = reinterpret_cast<std_vector_typedesc_t * >(&(rhs));
}

inline void to_c(
    std_vector_typedesc_t * * lhs
    , std::vector<OIIO::TypeDesc> * rhs)
{
        *(lhs) = reinterpret_cast<std_vector_typedesc_t * >(rhs);
}

inline void to_c_copy(
    std_vector_typedesc_t * * lhs
    , std::vector<OIIO::TypeDesc> const & rhs)
{
        std__vector_OIIO__TypeDesc__copy(lhs, reinterpret_cast<std_vector_typedesc_t const * >(&(rhs)));
}

