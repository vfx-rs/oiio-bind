#pragma once
#include <c-color.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/color.h>
#include <cstring>

inline OpenImageIO_v2_3_6::ColorProcessor const & to_cpp_ref(
    OIIO_ColorProcessor_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ColorProcessor const * >(rhs));
}

inline OpenImageIO_v2_3_6::ColorProcessor & to_cpp_ref(
    OIIO_ColorProcessor_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ColorProcessor * >(rhs));
}

inline OpenImageIO_v2_3_6::ColorProcessor const * to_cpp(
    OIIO_ColorProcessor_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ColorProcessor const * >(rhs);
}

inline OpenImageIO_v2_3_6::ColorProcessor * to_cpp(
    OIIO_ColorProcessor_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ColorProcessor * >(rhs);
}

inline void to_c(
    OIIO_ColorProcessor_t const * * lhs
    , OpenImageIO_v2_3_6::ColorProcessor const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ColorProcessor_t const * >(&(rhs));
}

inline void to_c(
    OIIO_ColorProcessor_t const * * lhs
    , OpenImageIO_v2_3_6::ColorProcessor const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ColorProcessor_t const * >(rhs);
}

inline void to_c(
    OIIO_ColorProcessor_t * * lhs
    , OpenImageIO_v2_3_6::ColorProcessor & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ColorProcessor_t * >(&(rhs));
}

inline void to_c(
    OIIO_ColorProcessor_t * * lhs
    , OpenImageIO_v2_3_6::ColorProcessor * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ColorProcessor_t * >(rhs);
}

inline OpenImageIO_v2_3_6::ColorConfig const & to_cpp_ref(
    OIIO_ColorConfig_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ColorConfig const * >(rhs));
}

inline OpenImageIO_v2_3_6::ColorConfig & to_cpp_ref(
    OIIO_ColorConfig_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ColorConfig * >(rhs));
}

inline OpenImageIO_v2_3_6::ColorConfig const * to_cpp(
    OIIO_ColorConfig_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ColorConfig const * >(rhs);
}

inline OpenImageIO_v2_3_6::ColorConfig * to_cpp(
    OIIO_ColorConfig_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ColorConfig * >(rhs);
}

inline void to_c(
    OIIO_ColorConfig_t const * * lhs
    , OpenImageIO_v2_3_6::ColorConfig const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ColorConfig_t const * >(&(rhs));
}

inline void to_c(
    OIIO_ColorConfig_t const * * lhs
    , OpenImageIO_v2_3_6::ColorConfig const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ColorConfig_t const * >(rhs);
}

inline void to_c(
    OIIO_ColorConfig_t * * lhs
    , OpenImageIO_v2_3_6::ColorConfig & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ColorConfig_t * >(&(rhs));
}

inline void to_c(
    OIIO_ColorConfig_t * * lhs
    , OpenImageIO_v2_3_6::ColorConfig * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ColorConfig_t * >(rhs);
}

