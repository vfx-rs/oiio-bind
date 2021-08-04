#pragma once
#include <c-paramlist.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/paramlist.h>
#include <cstring>

inline OpenImageIO_v2_3_6::ParamValue::Interp const & OIIO_ParamValue_Interp_to_cpp_ref(
    OIIO_ParamValue_Interp const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ParamValue::Interp const * >(rhs));
}

inline OpenImageIO_v2_3_6::ParamValue::Interp & OIIO_ParamValue_Interp_to_cpp_ref(
    OIIO_ParamValue_Interp * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ParamValue::Interp * >(rhs));
}

inline OpenImageIO_v2_3_6::ParamValue::Interp const * OIIO_ParamValue_Interp_to_cpp(
    OIIO_ParamValue_Interp const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ParamValue::Interp const * >(rhs);
}

inline OpenImageIO_v2_3_6::ParamValue::Interp * OIIO_ParamValue_Interp_to_cpp(
    OIIO_ParamValue_Interp * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ParamValue::Interp * >(rhs);
}

inline void to_c(
    OIIO_ParamValue_Interp const * * lhs
    , OpenImageIO_v2_3_6::ParamValue::Interp const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ParamValue_Interp const * >(&(rhs));
}

inline void to_c(
    OIIO_ParamValue_Interp const * * lhs
    , OpenImageIO_v2_3_6::ParamValue::Interp const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ParamValue_Interp const * >(rhs);
}

inline void to_c(
    OIIO_ParamValue_Interp * * lhs
    , OpenImageIO_v2_3_6::ParamValue::Interp & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ParamValue_Interp * >(&(rhs));
}

inline void to_c(
    OIIO_ParamValue_Interp * * lhs
    , OpenImageIO_v2_3_6::ParamValue::Interp * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ParamValue_Interp * >(rhs);
}

inline void to_c_copy(
    OIIO_ParamValue_Interp * lhs
    , OpenImageIO_v2_3_6::ParamValue::Interp const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::ParamValue const & to_cpp_ref(
    OIIO_ParamValue_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ParamValue const * >(rhs));
}

inline OpenImageIO_v2_3_6::ParamValue & to_cpp_ref(
    OIIO_ParamValue_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ParamValue * >(rhs));
}

inline OpenImageIO_v2_3_6::ParamValue const * to_cpp(
    OIIO_ParamValue_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ParamValue const * >(rhs);
}

inline OpenImageIO_v2_3_6::ParamValue * to_cpp(
    OIIO_ParamValue_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ParamValue * >(rhs);
}

inline void to_c(
    OIIO_ParamValue_t const * * lhs
    , OpenImageIO_v2_3_6::ParamValue const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ParamValue_t const * >(&(rhs));
}

inline void to_c(
    OIIO_ParamValue_t const * * lhs
    , OpenImageIO_v2_3_6::ParamValue const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ParamValue_t const * >(rhs);
}

inline void to_c(
    OIIO_ParamValue_t * * lhs
    , OpenImageIO_v2_3_6::ParamValue & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ParamValue_t * >(&(rhs));
}

inline void to_c(
    OIIO_ParamValue_t * * lhs
    , OpenImageIO_v2_3_6::ParamValue * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ParamValue_t * >(rhs);
}

inline void to_c_copy(
    OIIO_ParamValue_t * lhs
    , OpenImageIO_v2_3_6::ParamValue const & rhs)
{
        OpenImageIO_v2_3_6__ParamValue_copy(lhs, reinterpret_cast<OIIO_ParamValue_t const * >(&(rhs)));
}

inline OpenImageIO_v2_3_6::ParamValueList const & to_cpp_ref(
    OIIO_ParamValueList_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ParamValueList const * >(rhs));
}

inline OpenImageIO_v2_3_6::ParamValueList & to_cpp_ref(
    OIIO_ParamValueList_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ParamValueList * >(rhs));
}

inline OpenImageIO_v2_3_6::ParamValueList const * to_cpp(
    OIIO_ParamValueList_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ParamValueList const * >(rhs);
}

inline OpenImageIO_v2_3_6::ParamValueList * to_cpp(
    OIIO_ParamValueList_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ParamValueList * >(rhs);
}

inline void to_c(
    OIIO_ParamValueList_t const * * lhs
    , OpenImageIO_v2_3_6::ParamValueList const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ParamValueList_t const * >(&(rhs));
}

inline void to_c(
    OIIO_ParamValueList_t const * * lhs
    , OpenImageIO_v2_3_6::ParamValueList const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ParamValueList_t const * >(rhs);
}

inline void to_c(
    OIIO_ParamValueList_t * * lhs
    , OpenImageIO_v2_3_6::ParamValueList & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ParamValueList_t * >(&(rhs));
}

inline void to_c(
    OIIO_ParamValueList_t * * lhs
    , OpenImageIO_v2_3_6::ParamValueList * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ParamValueList_t * >(rhs);
}

inline void to_c_copy(
    OIIO_ParamValueList_t * * lhs
    , OpenImageIO_v2_3_6::ParamValueList const & rhs)
{
        OpenImageIO_v2_3_6__ParamValueList_copy(lhs, reinterpret_cast<OIIO_ParamValueList_t const * >(&(rhs)));
}

