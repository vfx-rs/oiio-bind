#pragma once
#include <c-imagebuf.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/imagebuf.h>
#include <cstring>

inline OpenImageIO_v2_3_6::ImageBuf::IBStorage const & OIIO_ImageBuf_IBStorage_to_cpp_ref(
    OIIO_ImageBuf_IBStorage const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBuf::IBStorage const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBuf::IBStorage & OIIO_ImageBuf_IBStorage_to_cpp_ref(
    OIIO_ImageBuf_IBStorage * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBuf::IBStorage * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBuf::IBStorage const * OIIO_ImageBuf_IBStorage_to_cpp(
    OIIO_ImageBuf_IBStorage const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBuf::IBStorage const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageBuf::IBStorage * OIIO_ImageBuf_IBStorage_to_cpp(
    OIIO_ImageBuf_IBStorage * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBuf::IBStorage * >(rhs);
}

inline void to_c(
    OIIO_ImageBuf_IBStorage const * * lhs
    , OpenImageIO_v2_3_6::ImageBuf::IBStorage const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBuf_IBStorage const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBuf_IBStorage const * * lhs
    , OpenImageIO_v2_3_6::ImageBuf::IBStorage const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBuf_IBStorage const * >(rhs);
}

inline void to_c(
    OIIO_ImageBuf_IBStorage * * lhs
    , OpenImageIO_v2_3_6::ImageBuf::IBStorage & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBuf_IBStorage * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBuf_IBStorage * * lhs
    , OpenImageIO_v2_3_6::ImageBuf::IBStorage * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBuf_IBStorage * >(rhs);
}

inline void to_c_copy(
    OIIO_ImageBuf_IBStorage * lhs
    , OpenImageIO_v2_3_6::ImageBuf::IBStorage const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::ImageBuf::WrapMode const & OIIO_ImageBuf_WrapMode_to_cpp_ref(
    OIIO_ImageBuf_WrapMode const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBuf::WrapMode const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBuf::WrapMode & OIIO_ImageBuf_WrapMode_to_cpp_ref(
    OIIO_ImageBuf_WrapMode * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBuf::WrapMode * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBuf::WrapMode const * OIIO_ImageBuf_WrapMode_to_cpp(
    OIIO_ImageBuf_WrapMode const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBuf::WrapMode const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageBuf::WrapMode * OIIO_ImageBuf_WrapMode_to_cpp(
    OIIO_ImageBuf_WrapMode * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBuf::WrapMode * >(rhs);
}

inline void to_c(
    OIIO_ImageBuf_WrapMode const * * lhs
    , OpenImageIO_v2_3_6::ImageBuf::WrapMode const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBuf_WrapMode const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBuf_WrapMode const * * lhs
    , OpenImageIO_v2_3_6::ImageBuf::WrapMode const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBuf_WrapMode const * >(rhs);
}

inline void to_c(
    OIIO_ImageBuf_WrapMode * * lhs
    , OpenImageIO_v2_3_6::ImageBuf::WrapMode & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBuf_WrapMode * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBuf_WrapMode * * lhs
    , OpenImageIO_v2_3_6::ImageBuf::WrapMode * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBuf_WrapMode * >(rhs);
}

inline void to_c_copy(
    OIIO_ImageBuf_WrapMode * lhs
    , OpenImageIO_v2_3_6::ImageBuf::WrapMode const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::InitializePixels const & OIIO_InitializePixels_to_cpp_ref(
    OIIO_InitializePixels const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::InitializePixels const * >(rhs));
}

inline OpenImageIO_v2_3_6::InitializePixels & OIIO_InitializePixels_to_cpp_ref(
    OIIO_InitializePixels * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::InitializePixels * >(rhs));
}

inline OpenImageIO_v2_3_6::InitializePixels const * OIIO_InitializePixels_to_cpp(
    OIIO_InitializePixels const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::InitializePixels const * >(rhs);
}

inline OpenImageIO_v2_3_6::InitializePixels * OIIO_InitializePixels_to_cpp(
    OIIO_InitializePixels * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::InitializePixels * >(rhs);
}

inline void to_c(
    OIIO_InitializePixels const * * lhs
    , OpenImageIO_v2_3_6::InitializePixels const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_InitializePixels const * >(&(rhs));
}

inline void to_c(
    OIIO_InitializePixels const * * lhs
    , OpenImageIO_v2_3_6::InitializePixels const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_InitializePixels const * >(rhs);
}

inline void to_c(
    OIIO_InitializePixels * * lhs
    , OpenImageIO_v2_3_6::InitializePixels & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_InitializePixels * >(&(rhs));
}

inline void to_c(
    OIIO_InitializePixels * * lhs
    , OpenImageIO_v2_3_6::InitializePixels * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_InitializePixels * >(rhs);
}

inline void to_c_copy(
    OIIO_InitializePixels * lhs
    , OpenImageIO_v2_3_6::InitializePixels const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::ImageBuf const & to_cpp_ref(
    OIIO_ImageBuf_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBuf const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBuf & to_cpp_ref(
    OIIO_ImageBuf_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBuf * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBuf const * to_cpp(
    OIIO_ImageBuf_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBuf const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageBuf * to_cpp(
    OIIO_ImageBuf_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBuf * >(rhs);
}

inline void to_c(
    OIIO_ImageBuf_t const * * lhs
    , OpenImageIO_v2_3_6::ImageBuf const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBuf_t const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBuf_t const * * lhs
    , OpenImageIO_v2_3_6::ImageBuf const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBuf_t const * >(rhs);
}

inline void to_c(
    OIIO_ImageBuf_t * * lhs
    , OpenImageIO_v2_3_6::ImageBuf & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBuf_t * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBuf_t * * lhs
    , OpenImageIO_v2_3_6::ImageBuf * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBuf_t * >(rhs);
}

inline void to_c_copy(
    OIIO_ImageBuf_t * * lhs
    , OpenImageIO_v2_3_6::ImageBuf const & rhs)
{
        OpenImageIO_v2_3_6__ImageBuf_copy(lhs, reinterpret_cast<OIIO_ImageBuf_t const * >(&(rhs)));
}

inline OpenImageIO_v2_3_6::ImageBuf::IteratorBase const & to_cpp_ref(
    OIIO_ImageBuf_IteratorBase_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBuf::IteratorBase const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBuf::IteratorBase & to_cpp_ref(
    OIIO_ImageBuf_IteratorBase_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBuf::IteratorBase * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBuf::IteratorBase const * to_cpp(
    OIIO_ImageBuf_IteratorBase_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBuf::IteratorBase const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageBuf::IteratorBase * to_cpp(
    OIIO_ImageBuf_IteratorBase_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBuf::IteratorBase * >(rhs);
}

inline void to_c(
    OIIO_ImageBuf_IteratorBase_t const * * lhs
    , OpenImageIO_v2_3_6::ImageBuf::IteratorBase const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBuf_IteratorBase_t const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBuf_IteratorBase_t const * * lhs
    , OpenImageIO_v2_3_6::ImageBuf::IteratorBase const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBuf_IteratorBase_t const * >(rhs);
}

inline void to_c(
    OIIO_ImageBuf_IteratorBase_t * * lhs
    , OpenImageIO_v2_3_6::ImageBuf::IteratorBase & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBuf_IteratorBase_t * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBuf_IteratorBase_t * * lhs
    , OpenImageIO_v2_3_6::ImageBuf::IteratorBase * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBuf_IteratorBase_t * >(rhs);
}

inline void to_c_copy(
    OIIO_ImageBuf_IteratorBase_t * lhs
    , OpenImageIO_v2_3_6::ImageBuf::IteratorBase const & rhs)
{
        OpenImageIO_v2_3_6__ImageBuf__IteratorBase_copy(lhs, reinterpret_cast<OIIO_ImageBuf_IteratorBase_t const * >(&(rhs)));
}

