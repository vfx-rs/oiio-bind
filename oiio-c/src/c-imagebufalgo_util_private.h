#pragma once
#include <c-imagebufalgo_util.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/imagebufalgo_util.h>
#include <cstring>

inline OpenImageIO_v2_3_6::ImageBufAlgo::IBAprep_flags const & OIIO_ImageBufAlgo_IBAprep_flags_to_cpp_ref(
    OIIO_ImageBufAlgo_IBAprep_flags const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::IBAprep_flags const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::IBAprep_flags & OIIO_ImageBufAlgo_IBAprep_flags_to_cpp_ref(
    OIIO_ImageBufAlgo_IBAprep_flags * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::IBAprep_flags * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::IBAprep_flags const * OIIO_ImageBufAlgo_IBAprep_flags_to_cpp(
    OIIO_ImageBufAlgo_IBAprep_flags const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::IBAprep_flags const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::IBAprep_flags * OIIO_ImageBufAlgo_IBAprep_flags_to_cpp(
    OIIO_ImageBufAlgo_IBAprep_flags * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::IBAprep_flags * >(rhs);
}

inline void to_c(
    OIIO_ImageBufAlgo_IBAprep_flags const * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::IBAprep_flags const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_IBAprep_flags const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBufAlgo_IBAprep_flags const * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::IBAprep_flags const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_IBAprep_flags const * >(rhs);
}

inline void to_c(
    OIIO_ImageBufAlgo_IBAprep_flags * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::IBAprep_flags & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_IBAprep_flags * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBufAlgo_IBAprep_flags * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::IBAprep_flags * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_IBAprep_flags * >(rhs);
}

inline void to_c_copy(
    OIIO_ImageBufAlgo_IBAprep_flags * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::IBAprep_flags const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

