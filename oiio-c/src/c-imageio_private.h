#pragma once
#include <c-imageio.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/imageio.h>
#include <cstring>

inline OpenImageIO_v2_3_6::ImageSpec::SerialFormat const & OIIO_ImageSpec_SerialFormat_to_cpp_ref(
    OIIO_ImageSpec_SerialFormat const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageSpec::SerialFormat const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageSpec::SerialFormat & OIIO_ImageSpec_SerialFormat_to_cpp_ref(
    OIIO_ImageSpec_SerialFormat * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageSpec::SerialFormat * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageSpec::SerialFormat const * OIIO_ImageSpec_SerialFormat_to_cpp(
    OIIO_ImageSpec_SerialFormat const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageSpec::SerialFormat const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageSpec::SerialFormat * OIIO_ImageSpec_SerialFormat_to_cpp(
    OIIO_ImageSpec_SerialFormat * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageSpec::SerialFormat * >(rhs);
}

inline void to_c(
    OIIO_ImageSpec_SerialFormat const * * lhs
    , OpenImageIO_v2_3_6::ImageSpec::SerialFormat const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageSpec_SerialFormat const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageSpec_SerialFormat const * * lhs
    , OpenImageIO_v2_3_6::ImageSpec::SerialFormat const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageSpec_SerialFormat const * >(rhs);
}

inline void to_c(
    OIIO_ImageSpec_SerialFormat * * lhs
    , OpenImageIO_v2_3_6::ImageSpec::SerialFormat & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageSpec_SerialFormat * >(&(rhs));
}

inline void to_c(
    OIIO_ImageSpec_SerialFormat * * lhs
    , OpenImageIO_v2_3_6::ImageSpec::SerialFormat * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageSpec_SerialFormat * >(rhs);
}

inline void to_c_copy(
    OIIO_ImageSpec_SerialFormat * lhs
    , OpenImageIO_v2_3_6::ImageSpec::SerialFormat const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::ImageSpec::SerialVerbose const & OIIO_ImageSpec_SerialVerbose_to_cpp_ref(
    OIIO_ImageSpec_SerialVerbose const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageSpec::SerialVerbose const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageSpec::SerialVerbose & OIIO_ImageSpec_SerialVerbose_to_cpp_ref(
    OIIO_ImageSpec_SerialVerbose * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageSpec::SerialVerbose * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageSpec::SerialVerbose const * OIIO_ImageSpec_SerialVerbose_to_cpp(
    OIIO_ImageSpec_SerialVerbose const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageSpec::SerialVerbose const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageSpec::SerialVerbose * OIIO_ImageSpec_SerialVerbose_to_cpp(
    OIIO_ImageSpec_SerialVerbose * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageSpec::SerialVerbose * >(rhs);
}

inline void to_c(
    OIIO_ImageSpec_SerialVerbose const * * lhs
    , OpenImageIO_v2_3_6::ImageSpec::SerialVerbose const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageSpec_SerialVerbose const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageSpec_SerialVerbose const * * lhs
    , OpenImageIO_v2_3_6::ImageSpec::SerialVerbose const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageSpec_SerialVerbose const * >(rhs);
}

inline void to_c(
    OIIO_ImageSpec_SerialVerbose * * lhs
    , OpenImageIO_v2_3_6::ImageSpec::SerialVerbose & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageSpec_SerialVerbose * >(&(rhs));
}

inline void to_c(
    OIIO_ImageSpec_SerialVerbose * * lhs
    , OpenImageIO_v2_3_6::ImageSpec::SerialVerbose * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageSpec_SerialVerbose * >(rhs);
}

inline void to_c_copy(
    OIIO_ImageSpec_SerialVerbose * lhs
    , OpenImageIO_v2_3_6::ImageSpec::SerialVerbose const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::ImageOutput::OpenMode const & OIIO_ImageOutput_OpenMode_to_cpp_ref(
    OIIO_ImageOutput_OpenMode const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageOutput::OpenMode const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageOutput::OpenMode & OIIO_ImageOutput_OpenMode_to_cpp_ref(
    OIIO_ImageOutput_OpenMode * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageOutput::OpenMode * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageOutput::OpenMode const * OIIO_ImageOutput_OpenMode_to_cpp(
    OIIO_ImageOutput_OpenMode const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageOutput::OpenMode const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageOutput::OpenMode * OIIO_ImageOutput_OpenMode_to_cpp(
    OIIO_ImageOutput_OpenMode * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageOutput::OpenMode * >(rhs);
}

inline void to_c(
    OIIO_ImageOutput_OpenMode const * * lhs
    , OpenImageIO_v2_3_6::ImageOutput::OpenMode const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageOutput_OpenMode const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageOutput_OpenMode const * * lhs
    , OpenImageIO_v2_3_6::ImageOutput::OpenMode const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageOutput_OpenMode const * >(rhs);
}

inline void to_c(
    OIIO_ImageOutput_OpenMode * * lhs
    , OpenImageIO_v2_3_6::ImageOutput::OpenMode & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageOutput_OpenMode * >(&(rhs));
}

inline void to_c(
    OIIO_ImageOutput_OpenMode * * lhs
    , OpenImageIO_v2_3_6::ImageOutput::OpenMode * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageOutput_OpenMode * >(rhs);
}

inline void to_c_copy(
    OIIO_ImageOutput_OpenMode * lhs
    , OpenImageIO_v2_3_6::ImageOutput::OpenMode const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::ROI const & to_cpp_ref(
    OIIO_ROI_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ROI const * >(rhs));
}

inline OpenImageIO_v2_3_6::ROI & to_cpp_ref(
    OIIO_ROI_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ROI * >(rhs));
}

inline OpenImageIO_v2_3_6::ROI const * to_cpp(
    OIIO_ROI_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ROI const * >(rhs);
}

inline OpenImageIO_v2_3_6::ROI * to_cpp(
    OIIO_ROI_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ROI * >(rhs);
}

inline void to_c(
    OIIO_ROI_t const * * lhs
    , OpenImageIO_v2_3_6::ROI const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ROI_t const * >(&(rhs));
}

inline void to_c(
    OIIO_ROI_t const * * lhs
    , OpenImageIO_v2_3_6::ROI const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ROI_t const * >(rhs);
}

inline void to_c(
    OIIO_ROI_t * * lhs
    , OpenImageIO_v2_3_6::ROI & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ROI_t * >(&(rhs));
}

inline void to_c(
    OIIO_ROI_t * * lhs
    , OpenImageIO_v2_3_6::ROI * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ROI_t * >(rhs);
}

inline void to_c_copy(
    OIIO_ROI_t * lhs
    , OpenImageIO_v2_3_6::ROI const & rhs)
{
        OpenImageIO_v2_3_6__ROI_copy(lhs, reinterpret_cast<OIIO_ROI_t const * >(&(rhs)));
}

inline OpenImageIO_v2_3_6::ImageSpec const & to_cpp_ref(
    OIIO_ImageSpec_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageSpec const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageSpec & to_cpp_ref(
    OIIO_ImageSpec_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageSpec * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageSpec const * to_cpp(
    OIIO_ImageSpec_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageSpec const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageSpec * to_cpp(
    OIIO_ImageSpec_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageSpec * >(rhs);
}

inline void to_c(
    OIIO_ImageSpec_t const * * lhs
    , OpenImageIO_v2_3_6::ImageSpec const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageSpec_t const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageSpec_t const * * lhs
    , OpenImageIO_v2_3_6::ImageSpec const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageSpec_t const * >(rhs);
}

inline void to_c(
    OIIO_ImageSpec_t * * lhs
    , OpenImageIO_v2_3_6::ImageSpec & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageSpec_t * >(&(rhs));
}

inline void to_c(
    OIIO_ImageSpec_t * * lhs
    , OpenImageIO_v2_3_6::ImageSpec * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageSpec_t * >(rhs);
}

inline void to_c_copy(
    OIIO_ImageSpec_t * * lhs
    , OpenImageIO_v2_3_6::ImageSpec const & rhs)
{
        OpenImageIO_v2_3_6__ImageSpec_copy(lhs, reinterpret_cast<OIIO_ImageSpec_t const * >(&(rhs)));
}

inline OpenImageIO_v2_3_6::ImageInput const & to_cpp_ref(
    OIIO_ImageInput_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageInput const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageInput & to_cpp_ref(
    OIIO_ImageInput_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageInput * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageInput const * to_cpp(
    OIIO_ImageInput_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageInput const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageInput * to_cpp(
    OIIO_ImageInput_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageInput * >(rhs);
}

inline void to_c(
    OIIO_ImageInput_t const * * lhs
    , OpenImageIO_v2_3_6::ImageInput const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageInput_t const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageInput_t const * * lhs
    , OpenImageIO_v2_3_6::ImageInput const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageInput_t const * >(rhs);
}

inline void to_c(
    OIIO_ImageInput_t * * lhs
    , OpenImageIO_v2_3_6::ImageInput & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageInput_t * >(&(rhs));
}

inline void to_c(
    OIIO_ImageInput_t * * lhs
    , OpenImageIO_v2_3_6::ImageInput * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageInput_t * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageOutput const & to_cpp_ref(
    OIIO_ImageOutput_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageOutput const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageOutput & to_cpp_ref(
    OIIO_ImageOutput_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageOutput * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageOutput const * to_cpp(
    OIIO_ImageOutput_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageOutput const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageOutput * to_cpp(
    OIIO_ImageOutput_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageOutput * >(rhs);
}

inline void to_c(
    OIIO_ImageOutput_t const * * lhs
    , OpenImageIO_v2_3_6::ImageOutput const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageOutput_t const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageOutput_t const * * lhs
    , OpenImageIO_v2_3_6::ImageOutput const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageOutput_t const * >(rhs);
}

inline void to_c(
    OIIO_ImageOutput_t * * lhs
    , OpenImageIO_v2_3_6::ImageOutput & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageOutput_t * >(&(rhs));
}

inline void to_c(
    OIIO_ImageOutput_t * * lhs
    , OpenImageIO_v2_3_6::ImageOutput * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageOutput_t * >(rhs);
}

