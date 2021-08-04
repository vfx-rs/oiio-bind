#pragma once
#include <c-imagebufalgo.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/imagebufalgo.h>
#include <cstring>

inline OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignX const & OIIO_ImageBufAlgo_TextAlignX_to_cpp_ref(
    OIIO_ImageBufAlgo_TextAlignX const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignX const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignX & OIIO_ImageBufAlgo_TextAlignX_to_cpp_ref(
    OIIO_ImageBufAlgo_TextAlignX * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignX * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignX const * OIIO_ImageBufAlgo_TextAlignX_to_cpp(
    OIIO_ImageBufAlgo_TextAlignX const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignX const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignX * OIIO_ImageBufAlgo_TextAlignX_to_cpp(
    OIIO_ImageBufAlgo_TextAlignX * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignX * >(rhs);
}

inline void to_c(
    OIIO_ImageBufAlgo_TextAlignX const * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignX const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_TextAlignX const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBufAlgo_TextAlignX const * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignX const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_TextAlignX const * >(rhs);
}

inline void to_c(
    OIIO_ImageBufAlgo_TextAlignX * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignX & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_TextAlignX * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBufAlgo_TextAlignX * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignX * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_TextAlignX * >(rhs);
}

inline void to_c_copy(
    OIIO_ImageBufAlgo_TextAlignX * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignX const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignY const & OIIO_ImageBufAlgo_TextAlignY_to_cpp_ref(
    OIIO_ImageBufAlgo_TextAlignY const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignY const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignY & OIIO_ImageBufAlgo_TextAlignY_to_cpp_ref(
    OIIO_ImageBufAlgo_TextAlignY * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignY * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignY const * OIIO_ImageBufAlgo_TextAlignY_to_cpp(
    OIIO_ImageBufAlgo_TextAlignY const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignY const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignY * OIIO_ImageBufAlgo_TextAlignY_to_cpp(
    OIIO_ImageBufAlgo_TextAlignY * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignY * >(rhs);
}

inline void to_c(
    OIIO_ImageBufAlgo_TextAlignY const * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignY const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_TextAlignY const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBufAlgo_TextAlignY const * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignY const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_TextAlignY const * >(rhs);
}

inline void to_c(
    OIIO_ImageBufAlgo_TextAlignY * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignY & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_TextAlignY * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBufAlgo_TextAlignY * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignY * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_TextAlignY * >(rhs);
}

inline void to_c_copy(
    OIIO_ImageBufAlgo_TextAlignY * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::TextAlignY const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::NonFiniteFixMode const & OIIO_ImageBufAlgo_NonFiniteFixMode_to_cpp_ref(
    OIIO_ImageBufAlgo_NonFiniteFixMode const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::NonFiniteFixMode const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::NonFiniteFixMode & OIIO_ImageBufAlgo_NonFiniteFixMode_to_cpp_ref(
    OIIO_ImageBufAlgo_NonFiniteFixMode * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::NonFiniteFixMode * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::NonFiniteFixMode const * OIIO_ImageBufAlgo_NonFiniteFixMode_to_cpp(
    OIIO_ImageBufAlgo_NonFiniteFixMode const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::NonFiniteFixMode const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::NonFiniteFixMode * OIIO_ImageBufAlgo_NonFiniteFixMode_to_cpp(
    OIIO_ImageBufAlgo_NonFiniteFixMode * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::NonFiniteFixMode * >(rhs);
}

inline void to_c(
    OIIO_ImageBufAlgo_NonFiniteFixMode const * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::NonFiniteFixMode const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_NonFiniteFixMode const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBufAlgo_NonFiniteFixMode const * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::NonFiniteFixMode const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_NonFiniteFixMode const * >(rhs);
}

inline void to_c(
    OIIO_ImageBufAlgo_NonFiniteFixMode * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::NonFiniteFixMode & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_NonFiniteFixMode * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBufAlgo_NonFiniteFixMode * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::NonFiniteFixMode * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_NonFiniteFixMode * >(rhs);
}

inline void to_c_copy(
    OIIO_ImageBufAlgo_NonFiniteFixMode * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::NonFiniteFixMode const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::MakeTextureMode const & OIIO_ImageBufAlgo_MakeTextureMode_to_cpp_ref(
    OIIO_ImageBufAlgo_MakeTextureMode const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::MakeTextureMode const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::MakeTextureMode & OIIO_ImageBufAlgo_MakeTextureMode_to_cpp_ref(
    OIIO_ImageBufAlgo_MakeTextureMode * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::MakeTextureMode * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::MakeTextureMode const * OIIO_ImageBufAlgo_MakeTextureMode_to_cpp(
    OIIO_ImageBufAlgo_MakeTextureMode const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::MakeTextureMode const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::MakeTextureMode * OIIO_ImageBufAlgo_MakeTextureMode_to_cpp(
    OIIO_ImageBufAlgo_MakeTextureMode * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::MakeTextureMode * >(rhs);
}

inline void to_c(
    OIIO_ImageBufAlgo_MakeTextureMode const * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::MakeTextureMode const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_MakeTextureMode const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBufAlgo_MakeTextureMode const * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::MakeTextureMode const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_MakeTextureMode const * >(rhs);
}

inline void to_c(
    OIIO_ImageBufAlgo_MakeTextureMode * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::MakeTextureMode & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_MakeTextureMode * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBufAlgo_MakeTextureMode * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::MakeTextureMode * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_MakeTextureMode * >(rhs);
}

inline void to_c_copy(
    OIIO_ImageBufAlgo_MakeTextureMode * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::MakeTextureMode const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::Image_or_Const const & to_cpp_ref(
    OIIO_Image_or_Const_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::Image_or_Const const * >(rhs));
}

inline OpenImageIO_v2_3_6::Image_or_Const & to_cpp_ref(
    OIIO_Image_or_Const_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::Image_or_Const * >(rhs));
}

inline OpenImageIO_v2_3_6::Image_or_Const const * to_cpp(
    OIIO_Image_or_Const_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::Image_or_Const const * >(rhs);
}

inline OpenImageIO_v2_3_6::Image_or_Const * to_cpp(
    OIIO_Image_or_Const_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::Image_or_Const * >(rhs);
}

inline void to_c(
    OIIO_Image_or_Const_t const * * lhs
    , OpenImageIO_v2_3_6::Image_or_Const const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Image_or_Const_t const * >(&(rhs));
}

inline void to_c(
    OIIO_Image_or_Const_t const * * lhs
    , OpenImageIO_v2_3_6::Image_or_Const const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Image_or_Const_t const * >(rhs);
}

inline void to_c(
    OIIO_Image_or_Const_t * * lhs
    , OpenImageIO_v2_3_6::Image_or_Const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Image_or_Const_t * >(&(rhs));
}

inline void to_c(
    OIIO_Image_or_Const_t * * lhs
    , OpenImageIO_v2_3_6::Image_or_Const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Image_or_Const_t * >(rhs);
}

inline void to_c_copy(
    OIIO_Image_or_Const_t * * lhs
    , OpenImageIO_v2_3_6::Image_or_Const const & rhs)
{
        OpenImageIO_v2_3_6__Image_or_Const_copy(lhs, reinterpret_cast<OIIO_Image_or_Const_t const * >(&(rhs)));
}

inline OpenImageIO_v2_3_6::Image_or_Const::None const & to_cpp_ref(
    OIIO_Image_or_Const_None_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::Image_or_Const::None const * >(rhs));
}

inline OpenImageIO_v2_3_6::Image_or_Const::None & to_cpp_ref(
    OIIO_Image_or_Const_None_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::Image_or_Const::None * >(rhs));
}

inline OpenImageIO_v2_3_6::Image_or_Const::None const * to_cpp(
    OIIO_Image_or_Const_None_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::Image_or_Const::None const * >(rhs);
}

inline OpenImageIO_v2_3_6::Image_or_Const::None * to_cpp(
    OIIO_Image_or_Const_None_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::Image_or_Const::None * >(rhs);
}

inline void to_c(
    OIIO_Image_or_Const_None_t const * * lhs
    , OpenImageIO_v2_3_6::Image_or_Const::None const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Image_or_Const_None_t const * >(&(rhs));
}

inline void to_c(
    OIIO_Image_or_Const_None_t const * * lhs
    , OpenImageIO_v2_3_6::Image_or_Const::None const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Image_or_Const_None_t const * >(rhs);
}

inline void to_c(
    OIIO_Image_or_Const_None_t * * lhs
    , OpenImageIO_v2_3_6::Image_or_Const::None & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Image_or_Const_None_t * >(&(rhs));
}

inline void to_c(
    OIIO_Image_or_Const_None_t * * lhs
    , OpenImageIO_v2_3_6::Image_or_Const::None * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Image_or_Const_None_t * >(rhs);
}

inline void to_c_copy(
    OIIO_Image_or_Const_None_t * lhs
    , OpenImageIO_v2_3_6::Image_or_Const::None const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::CompareResults const & to_cpp_ref(
    OIIO_ImageBufAlgo_CompareResults_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::CompareResults const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::CompareResults & to_cpp_ref(
    OIIO_ImageBufAlgo_CompareResults_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::CompareResults * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::CompareResults const * to_cpp(
    OIIO_ImageBufAlgo_CompareResults_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::CompareResults const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageBufAlgo::CompareResults * to_cpp(
    OIIO_ImageBufAlgo_CompareResults_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageBufAlgo::CompareResults * >(rhs);
}

inline void to_c(
    OIIO_ImageBufAlgo_CompareResults_t const * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::CompareResults const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_CompareResults_t const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBufAlgo_CompareResults_t const * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::CompareResults const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_CompareResults_t const * >(rhs);
}

inline void to_c(
    OIIO_ImageBufAlgo_CompareResults_t * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::CompareResults & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_CompareResults_t * >(&(rhs));
}

inline void to_c(
    OIIO_ImageBufAlgo_CompareResults_t * * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::CompareResults * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageBufAlgo_CompareResults_t * >(rhs);
}

inline void to_c_copy(
    OIIO_ImageBufAlgo_CompareResults_t * lhs
    , OpenImageIO_v2_3_6::ImageBufAlgo::CompareResults const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

