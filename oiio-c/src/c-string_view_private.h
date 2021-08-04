#pragma once
#include <c-string_view.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/string_view.h>
#include <cstring>

inline OpenImageIO_v2_3_6::string_view const & to_cpp_ref(
    OIIO_string_view_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::string_view const * >(rhs));
}

inline OpenImageIO_v2_3_6::string_view & to_cpp_ref(
    OIIO_string_view_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::string_view * >(rhs));
}

inline OpenImageIO_v2_3_6::string_view const * to_cpp(
    OIIO_string_view_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::string_view const * >(rhs);
}

inline OpenImageIO_v2_3_6::string_view * to_cpp(
    OIIO_string_view_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::string_view * >(rhs);
}

inline void to_c(
    OIIO_string_view_t const * * lhs
    , OpenImageIO_v2_3_6::string_view const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_string_view_t const * >(&(rhs));
}

inline void to_c(
    OIIO_string_view_t const * * lhs
    , OpenImageIO_v2_3_6::string_view const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_string_view_t const * >(rhs);
}

inline void to_c(
    OIIO_string_view_t * * lhs
    , OpenImageIO_v2_3_6::string_view & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_string_view_t * >(&(rhs));
}

inline void to_c(
    OIIO_string_view_t * * lhs
    , OpenImageIO_v2_3_6::string_view * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_string_view_t * >(rhs);
}

inline void to_c_copy(
    OIIO_string_view_t * lhs
    , OpenImageIO_v2_3_6::string_view const & rhs)
{
        OpenImageIO_v2_3_6__string_view_copy(lhs, reinterpret_cast<OIIO_string_view_t const * >(&(rhs)));
}

