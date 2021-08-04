#pragma once
#include <c-filter.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/filter.h>
#include <cstring>

inline OpenImageIO_v2_3_6::FilterDesc const & to_cpp_ref(
    OIIO_FilterDesc_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::FilterDesc const * >(rhs));
}

inline OpenImageIO_v2_3_6::FilterDesc & to_cpp_ref(
    OIIO_FilterDesc_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::FilterDesc * >(rhs));
}

inline OpenImageIO_v2_3_6::FilterDesc const * to_cpp(
    OIIO_FilterDesc_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::FilterDesc const * >(rhs);
}

inline OpenImageIO_v2_3_6::FilterDesc * to_cpp(
    OIIO_FilterDesc_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::FilterDesc * >(rhs);
}

inline void to_c(
    OIIO_FilterDesc_t const * * lhs
    , OpenImageIO_v2_3_6::FilterDesc const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_FilterDesc_t const * >(&(rhs));
}

inline void to_c(
    OIIO_FilterDesc_t const * * lhs
    , OpenImageIO_v2_3_6::FilterDesc const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_FilterDesc_t const * >(rhs);
}

inline void to_c(
    OIIO_FilterDesc_t * * lhs
    , OpenImageIO_v2_3_6::FilterDesc & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_FilterDesc_t * >(&(rhs));
}

inline void to_c(
    OIIO_FilterDesc_t * * lhs
    , OpenImageIO_v2_3_6::FilterDesc * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_FilterDesc_t * >(rhs);
}

inline void to_c_copy(
    OIIO_FilterDesc_t * lhs
    , OpenImageIO_v2_3_6::FilterDesc const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::Filter1D const & to_cpp_ref(
    OIIO_Filter1D_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::Filter1D const * >(rhs));
}

inline OpenImageIO_v2_3_6::Filter1D & to_cpp_ref(
    OIIO_Filter1D_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::Filter1D * >(rhs));
}

inline OpenImageIO_v2_3_6::Filter1D const * to_cpp(
    OIIO_Filter1D_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::Filter1D const * >(rhs);
}

inline OpenImageIO_v2_3_6::Filter1D * to_cpp(
    OIIO_Filter1D_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::Filter1D * >(rhs);
}

inline void to_c(
    OIIO_Filter1D_t const * * lhs
    , OpenImageIO_v2_3_6::Filter1D const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Filter1D_t const * >(&(rhs));
}

inline void to_c(
    OIIO_Filter1D_t const * * lhs
    , OpenImageIO_v2_3_6::Filter1D const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Filter1D_t const * >(rhs);
}

inline void to_c(
    OIIO_Filter1D_t * * lhs
    , OpenImageIO_v2_3_6::Filter1D & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Filter1D_t * >(&(rhs));
}

inline void to_c(
    OIIO_Filter1D_t * * lhs
    , OpenImageIO_v2_3_6::Filter1D * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Filter1D_t * >(rhs);
}

inline OpenImageIO_v2_3_6::Filter2D const & to_cpp_ref(
    OIIO_Filter2D_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::Filter2D const * >(rhs));
}

inline OpenImageIO_v2_3_6::Filter2D & to_cpp_ref(
    OIIO_Filter2D_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::Filter2D * >(rhs));
}

inline OpenImageIO_v2_3_6::Filter2D const * to_cpp(
    OIIO_Filter2D_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::Filter2D const * >(rhs);
}

inline OpenImageIO_v2_3_6::Filter2D * to_cpp(
    OIIO_Filter2D_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::Filter2D * >(rhs);
}

inline void to_c(
    OIIO_Filter2D_t const * * lhs
    , OpenImageIO_v2_3_6::Filter2D const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Filter2D_t const * >(&(rhs));
}

inline void to_c(
    OIIO_Filter2D_t const * * lhs
    , OpenImageIO_v2_3_6::Filter2D const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Filter2D_t const * >(rhs);
}

inline void to_c(
    OIIO_Filter2D_t * * lhs
    , OpenImageIO_v2_3_6::Filter2D & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Filter2D_t * >(&(rhs));
}

inline void to_c(
    OIIO_Filter2D_t * * lhs
    , OpenImageIO_v2_3_6::Filter2D * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Filter2D_t * >(rhs);
}

