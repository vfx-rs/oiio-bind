#pragma once
#include <c-std_pair.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/string_view.h>
#include <cstring>
#include <string>
#include <utility>

inline std::pair<OIIO::string_view, int> const & to_cpp_ref(
    std_pair_string_int_t const * rhs)
{
        return *(reinterpret_cast<std::pair<OIIO::string_view, int> const * >(rhs));
}

inline std::pair<OIIO::string_view, int> & to_cpp_ref(
    std_pair_string_int_t * rhs)
{
        return *(reinterpret_cast<std::pair<OIIO::string_view, int> * >(rhs));
}

inline std::pair<OIIO::string_view, int> const * to_cpp(
    std_pair_string_int_t const * rhs)
{
        return reinterpret_cast<std::pair<OIIO::string_view, int> const * >(rhs);
}

inline std::pair<OIIO::string_view, int> * to_cpp(
    std_pair_string_int_t * rhs)
{
        return reinterpret_cast<std::pair<OIIO::string_view, int> * >(rhs);
}

inline void to_c(
    std_pair_string_int_t const * * lhs
    , std::pair<OIIO::string_view, int> const & rhs)
{
        *(lhs) = reinterpret_cast<std_pair_string_int_t const * >(&(rhs));
}

inline void to_c(
    std_pair_string_int_t const * * lhs
    , std::pair<OIIO::string_view, int> const * rhs)
{
        *(lhs) = reinterpret_cast<std_pair_string_int_t const * >(rhs);
}

inline void to_c(
    std_pair_string_int_t * * lhs
    , std::pair<OIIO::string_view, int> & rhs)
{
        *(lhs) = reinterpret_cast<std_pair_string_int_t * >(&(rhs));
}

inline void to_c(
    std_pair_string_int_t * * lhs
    , std::pair<OIIO::string_view, int> * rhs)
{
        *(lhs) = reinterpret_cast<std_pair_string_int_t * >(rhs);
}

inline void to_c_copy(
    std_pair_string_int_t * * lhs
    , std::pair<OIIO::string_view, int> const & rhs)
{
        std__pair_OIIO__string_view_int__copy(lhs, reinterpret_cast<std_pair_string_int_t const * >(&(rhs)));
}

