#pragma once
#include <c-strided_ptr.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/strided_ptr.h>
#include <cstring>

inline OpenImageIO_v2_3_6::strided_ptr<float, 1> const & to_cpp_ref(
    OIIO_strided_ptr_float_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::strided_ptr<float, 1> const * >(rhs));
}

inline OpenImageIO_v2_3_6::strided_ptr<float, 1> & to_cpp_ref(
    OIIO_strided_ptr_float_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::strided_ptr<float, 1> * >(rhs));
}

inline OpenImageIO_v2_3_6::strided_ptr<float, 1> const * to_cpp(
    OIIO_strided_ptr_float_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::strided_ptr<float, 1> const * >(rhs);
}

inline OpenImageIO_v2_3_6::strided_ptr<float, 1> * to_cpp(
    OIIO_strided_ptr_float_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::strided_ptr<float, 1> * >(rhs);
}

inline void to_c(
    OIIO_strided_ptr_float_t const * * lhs
    , OpenImageIO_v2_3_6::strided_ptr<float, 1> const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_strided_ptr_float_t const * >(&(rhs));
}

inline void to_c(
    OIIO_strided_ptr_float_t const * * lhs
    , OpenImageIO_v2_3_6::strided_ptr<float, 1> const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_strided_ptr_float_t const * >(rhs);
}

inline void to_c(
    OIIO_strided_ptr_float_t * * lhs
    , OpenImageIO_v2_3_6::strided_ptr<float, 1> & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_strided_ptr_float_t * >(&(rhs));
}

inline void to_c(
    OIIO_strided_ptr_float_t * * lhs
    , OpenImageIO_v2_3_6::strided_ptr<float, 1> * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_strided_ptr_float_t * >(rhs);
}

inline void to_c_copy(
    OIIO_strided_ptr_float_t * lhs
    , OpenImageIO_v2_3_6::strided_ptr<float, 1> const & rhs)
{
        OpenImageIO_v2_3_6__strided_ptr_float_1__copy(lhs, reinterpret_cast<OIIO_strided_ptr_float_t const * >(&(rhs)));
}

