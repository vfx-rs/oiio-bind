#pragma once
#include <c-ustring.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/ustring.h>
#include <cstring>

inline OpenImageIO_v2_3_6::ustring const & to_cpp_ref(
    OIIO_ustring_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ustring const * >(rhs));
}

inline OpenImageIO_v2_3_6::ustring & to_cpp_ref(
    OIIO_ustring_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ustring * >(rhs));
}

inline OpenImageIO_v2_3_6::ustring const * to_cpp(
    OIIO_ustring_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ustring const * >(rhs);
}

inline OpenImageIO_v2_3_6::ustring * to_cpp(
    OIIO_ustring_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ustring * >(rhs);
}

inline void to_c(
    OIIO_ustring_t const * * lhs
    , OpenImageIO_v2_3_6::ustring const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ustring_t const * >(&(rhs));
}

inline void to_c(
    OIIO_ustring_t const * * lhs
    , OpenImageIO_v2_3_6::ustring const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ustring_t const * >(rhs);
}

inline void to_c(
    OIIO_ustring_t * * lhs
    , OpenImageIO_v2_3_6::ustring & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ustring_t * >(&(rhs));
}

inline void to_c(
    OIIO_ustring_t * * lhs
    , OpenImageIO_v2_3_6::ustring * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ustring_t * >(rhs);
}

inline void to_c_copy(
    OIIO_ustring_t * lhs
    , OpenImageIO_v2_3_6::ustring const & rhs)
{
        OpenImageIO_v2_3_6__ustring_copy(lhs, reinterpret_cast<OIIO_ustring_t const * >(&(rhs)));
}

