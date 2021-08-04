#pragma once
#include <c-deepdata.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/deepdata.h>
#include <cstring>

inline OpenImageIO_v2_3_6::DeepData const & to_cpp_ref(
    OIIO_DeepData_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::DeepData const * >(rhs));
}

inline OpenImageIO_v2_3_6::DeepData & to_cpp_ref(
    OIIO_DeepData_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::DeepData * >(rhs));
}

inline OpenImageIO_v2_3_6::DeepData const * to_cpp(
    OIIO_DeepData_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::DeepData const * >(rhs);
}

inline OpenImageIO_v2_3_6::DeepData * to_cpp(
    OIIO_DeepData_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::DeepData * >(rhs);
}

inline void to_c(
    OIIO_DeepData_t const * * lhs
    , OpenImageIO_v2_3_6::DeepData const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_DeepData_t const * >(&(rhs));
}

inline void to_c(
    OIIO_DeepData_t const * * lhs
    , OpenImageIO_v2_3_6::DeepData const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_DeepData_t const * >(rhs);
}

inline void to_c(
    OIIO_DeepData_t * * lhs
    , OpenImageIO_v2_3_6::DeepData & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_DeepData_t * >(&(rhs));
}

inline void to_c(
    OIIO_DeepData_t * * lhs
    , OpenImageIO_v2_3_6::DeepData * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_DeepData_t * >(rhs);
}

inline void to_c_copy(
    OIIO_DeepData_t * * lhs
    , OpenImageIO_v2_3_6::DeepData const & rhs)
{
        OpenImageIO_v2_3_6__DeepData_copy(lhs, reinterpret_cast<OIIO_DeepData_t const * >(&(rhs)));
}

