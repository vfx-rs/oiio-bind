#pragma once
#include <c-texture.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/texture.h>
#include <cstring>

inline OpenImageIO_v2_3_6::TextureOpt::Wrap const & OIIO_TextureOpt_Wrap_to_cpp_ref(
    OIIO_TextureOpt_Wrap const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::TextureOpt::Wrap const * >(rhs));
}

inline OpenImageIO_v2_3_6::TextureOpt::Wrap & OIIO_TextureOpt_Wrap_to_cpp_ref(
    OIIO_TextureOpt_Wrap * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::TextureOpt::Wrap * >(rhs));
}

inline OpenImageIO_v2_3_6::TextureOpt::Wrap const * OIIO_TextureOpt_Wrap_to_cpp(
    OIIO_TextureOpt_Wrap const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::TextureOpt::Wrap const * >(rhs);
}

inline OpenImageIO_v2_3_6::TextureOpt::Wrap * OIIO_TextureOpt_Wrap_to_cpp(
    OIIO_TextureOpt_Wrap * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::TextureOpt::Wrap * >(rhs);
}

inline void to_c(
    OIIO_TextureOpt_Wrap const * * lhs
    , OpenImageIO_v2_3_6::TextureOpt::Wrap const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOpt_Wrap const * >(&(rhs));
}

inline void to_c(
    OIIO_TextureOpt_Wrap const * * lhs
    , OpenImageIO_v2_3_6::TextureOpt::Wrap const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOpt_Wrap const * >(rhs);
}

inline void to_c(
    OIIO_TextureOpt_Wrap * * lhs
    , OpenImageIO_v2_3_6::TextureOpt::Wrap & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOpt_Wrap * >(&(rhs));
}

inline void to_c(
    OIIO_TextureOpt_Wrap * * lhs
    , OpenImageIO_v2_3_6::TextureOpt::Wrap * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOpt_Wrap * >(rhs);
}

inline void to_c_copy(
    OIIO_TextureOpt_Wrap * lhs
    , OpenImageIO_v2_3_6::TextureOpt::Wrap const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::TextureOpt::MipMode const & OIIO_TextureOpt_MipMode_to_cpp_ref(
    OIIO_TextureOpt_MipMode const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::TextureOpt::MipMode const * >(rhs));
}

inline OpenImageIO_v2_3_6::TextureOpt::MipMode & OIIO_TextureOpt_MipMode_to_cpp_ref(
    OIIO_TextureOpt_MipMode * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::TextureOpt::MipMode * >(rhs));
}

inline OpenImageIO_v2_3_6::TextureOpt::MipMode const * OIIO_TextureOpt_MipMode_to_cpp(
    OIIO_TextureOpt_MipMode const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::TextureOpt::MipMode const * >(rhs);
}

inline OpenImageIO_v2_3_6::TextureOpt::MipMode * OIIO_TextureOpt_MipMode_to_cpp(
    OIIO_TextureOpt_MipMode * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::TextureOpt::MipMode * >(rhs);
}

inline void to_c(
    OIIO_TextureOpt_MipMode const * * lhs
    , OpenImageIO_v2_3_6::TextureOpt::MipMode const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOpt_MipMode const * >(&(rhs));
}

inline void to_c(
    OIIO_TextureOpt_MipMode const * * lhs
    , OpenImageIO_v2_3_6::TextureOpt::MipMode const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOpt_MipMode const * >(rhs);
}

inline void to_c(
    OIIO_TextureOpt_MipMode * * lhs
    , OpenImageIO_v2_3_6::TextureOpt::MipMode & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOpt_MipMode * >(&(rhs));
}

inline void to_c(
    OIIO_TextureOpt_MipMode * * lhs
    , OpenImageIO_v2_3_6::TextureOpt::MipMode * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOpt_MipMode * >(rhs);
}

inline void to_c_copy(
    OIIO_TextureOpt_MipMode * lhs
    , OpenImageIO_v2_3_6::TextureOpt::MipMode const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::TextureOpt::InterpMode const & OIIO_TextureOpt_InterpMode_to_cpp_ref(
    OIIO_TextureOpt_InterpMode const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::TextureOpt::InterpMode const * >(rhs));
}

inline OpenImageIO_v2_3_6::TextureOpt::InterpMode & OIIO_TextureOpt_InterpMode_to_cpp_ref(
    OIIO_TextureOpt_InterpMode * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::TextureOpt::InterpMode * >(rhs));
}

inline OpenImageIO_v2_3_6::TextureOpt::InterpMode const * OIIO_TextureOpt_InterpMode_to_cpp(
    OIIO_TextureOpt_InterpMode const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::TextureOpt::InterpMode const * >(rhs);
}

inline OpenImageIO_v2_3_6::TextureOpt::InterpMode * OIIO_TextureOpt_InterpMode_to_cpp(
    OIIO_TextureOpt_InterpMode * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::TextureOpt::InterpMode * >(rhs);
}

inline void to_c(
    OIIO_TextureOpt_InterpMode const * * lhs
    , OpenImageIO_v2_3_6::TextureOpt::InterpMode const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOpt_InterpMode const * >(&(rhs));
}

inline void to_c(
    OIIO_TextureOpt_InterpMode const * * lhs
    , OpenImageIO_v2_3_6::TextureOpt::InterpMode const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOpt_InterpMode const * >(rhs);
}

inline void to_c(
    OIIO_TextureOpt_InterpMode * * lhs
    , OpenImageIO_v2_3_6::TextureOpt::InterpMode & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOpt_InterpMode * >(&(rhs));
}

inline void to_c(
    OIIO_TextureOpt_InterpMode * * lhs
    , OpenImageIO_v2_3_6::TextureOpt::InterpMode * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOpt_InterpMode * >(rhs);
}

inline void to_c_copy(
    OIIO_TextureOpt_InterpMode * lhs
    , OpenImageIO_v2_3_6::TextureOpt::InterpMode const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::pvt::TexFormat const & OIIO_pvt_TexFormat_to_cpp_ref(
    OIIO_pvt_TexFormat const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::pvt::TexFormat const * >(rhs));
}

inline OpenImageIO_v2_3_6::pvt::TexFormat & OIIO_pvt_TexFormat_to_cpp_ref(
    OIIO_pvt_TexFormat * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::pvt::TexFormat * >(rhs));
}

inline OpenImageIO_v2_3_6::pvt::TexFormat const * OIIO_pvt_TexFormat_to_cpp(
    OIIO_pvt_TexFormat const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::pvt::TexFormat const * >(rhs);
}

inline OpenImageIO_v2_3_6::pvt::TexFormat * OIIO_pvt_TexFormat_to_cpp(
    OIIO_pvt_TexFormat * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::pvt::TexFormat * >(rhs);
}

inline void to_c(
    OIIO_pvt_TexFormat const * * lhs
    , OpenImageIO_v2_3_6::pvt::TexFormat const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_TexFormat const * >(&(rhs));
}

inline void to_c(
    OIIO_pvt_TexFormat const * * lhs
    , OpenImageIO_v2_3_6::pvt::TexFormat const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_TexFormat const * >(rhs);
}

inline void to_c(
    OIIO_pvt_TexFormat * * lhs
    , OpenImageIO_v2_3_6::pvt::TexFormat & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_TexFormat * >(&(rhs));
}

inline void to_c(
    OIIO_pvt_TexFormat * * lhs
    , OpenImageIO_v2_3_6::pvt::TexFormat * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_TexFormat * >(rhs);
}

inline void to_c_copy(
    OIIO_pvt_TexFormat * lhs
    , OpenImageIO_v2_3_6::pvt::TexFormat const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::pvt::EnvLayout const & OIIO_pvt_EnvLayout_to_cpp_ref(
    OIIO_pvt_EnvLayout const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::pvt::EnvLayout const * >(rhs));
}

inline OpenImageIO_v2_3_6::pvt::EnvLayout & OIIO_pvt_EnvLayout_to_cpp_ref(
    OIIO_pvt_EnvLayout * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::pvt::EnvLayout * >(rhs));
}

inline OpenImageIO_v2_3_6::pvt::EnvLayout const * OIIO_pvt_EnvLayout_to_cpp(
    OIIO_pvt_EnvLayout const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::pvt::EnvLayout const * >(rhs);
}

inline OpenImageIO_v2_3_6::pvt::EnvLayout * OIIO_pvt_EnvLayout_to_cpp(
    OIIO_pvt_EnvLayout * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::pvt::EnvLayout * >(rhs);
}

inline void to_c(
    OIIO_pvt_EnvLayout const * * lhs
    , OpenImageIO_v2_3_6::pvt::EnvLayout const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_EnvLayout const * >(&(rhs));
}

inline void to_c(
    OIIO_pvt_EnvLayout const * * lhs
    , OpenImageIO_v2_3_6::pvt::EnvLayout const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_EnvLayout const * >(rhs);
}

inline void to_c(
    OIIO_pvt_EnvLayout * * lhs
    , OpenImageIO_v2_3_6::pvt::EnvLayout & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_EnvLayout * >(&(rhs));
}

inline void to_c(
    OIIO_pvt_EnvLayout * * lhs
    , OpenImageIO_v2_3_6::pvt::EnvLayout * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_EnvLayout * >(rhs);
}

inline void to_c_copy(
    OIIO_pvt_EnvLayout * lhs
    , OpenImageIO_v2_3_6::pvt::EnvLayout const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::Tex::Wrap const & OIIO_Tex_Wrap_to_cpp_ref(
    OIIO_Tex_Wrap const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::Tex::Wrap const * >(rhs));
}

inline OpenImageIO_v2_3_6::Tex::Wrap & OIIO_Tex_Wrap_to_cpp_ref(
    OIIO_Tex_Wrap * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::Tex::Wrap * >(rhs));
}

inline OpenImageIO_v2_3_6::Tex::Wrap const * OIIO_Tex_Wrap_to_cpp(
    OIIO_Tex_Wrap const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::Tex::Wrap const * >(rhs);
}

inline OpenImageIO_v2_3_6::Tex::Wrap * OIIO_Tex_Wrap_to_cpp(
    OIIO_Tex_Wrap * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::Tex::Wrap * >(rhs);
}

inline void to_c(
    OIIO_Tex_Wrap const * * lhs
    , OpenImageIO_v2_3_6::Tex::Wrap const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Tex_Wrap const * >(&(rhs));
}

inline void to_c(
    OIIO_Tex_Wrap const * * lhs
    , OpenImageIO_v2_3_6::Tex::Wrap const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Tex_Wrap const * >(rhs);
}

inline void to_c(
    OIIO_Tex_Wrap * * lhs
    , OpenImageIO_v2_3_6::Tex::Wrap & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Tex_Wrap * >(&(rhs));
}

inline void to_c(
    OIIO_Tex_Wrap * * lhs
    , OpenImageIO_v2_3_6::Tex::Wrap * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Tex_Wrap * >(rhs);
}

inline void to_c_copy(
    OIIO_Tex_Wrap * lhs
    , OpenImageIO_v2_3_6::Tex::Wrap const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::Tex::MipMode const & OIIO_Tex_MipMode_to_cpp_ref(
    OIIO_Tex_MipMode const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::Tex::MipMode const * >(rhs));
}

inline OpenImageIO_v2_3_6::Tex::MipMode & OIIO_Tex_MipMode_to_cpp_ref(
    OIIO_Tex_MipMode * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::Tex::MipMode * >(rhs));
}

inline OpenImageIO_v2_3_6::Tex::MipMode const * OIIO_Tex_MipMode_to_cpp(
    OIIO_Tex_MipMode const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::Tex::MipMode const * >(rhs);
}

inline OpenImageIO_v2_3_6::Tex::MipMode * OIIO_Tex_MipMode_to_cpp(
    OIIO_Tex_MipMode * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::Tex::MipMode * >(rhs);
}

inline void to_c(
    OIIO_Tex_MipMode const * * lhs
    , OpenImageIO_v2_3_6::Tex::MipMode const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Tex_MipMode const * >(&(rhs));
}

inline void to_c(
    OIIO_Tex_MipMode const * * lhs
    , OpenImageIO_v2_3_6::Tex::MipMode const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Tex_MipMode const * >(rhs);
}

inline void to_c(
    OIIO_Tex_MipMode * * lhs
    , OpenImageIO_v2_3_6::Tex::MipMode & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Tex_MipMode * >(&(rhs));
}

inline void to_c(
    OIIO_Tex_MipMode * * lhs
    , OpenImageIO_v2_3_6::Tex::MipMode * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Tex_MipMode * >(rhs);
}

inline void to_c_copy(
    OIIO_Tex_MipMode * lhs
    , OpenImageIO_v2_3_6::Tex::MipMode const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::Tex::InterpMode const & OIIO_Tex_InterpMode_to_cpp_ref(
    OIIO_Tex_InterpMode const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::Tex::InterpMode const * >(rhs));
}

inline OpenImageIO_v2_3_6::Tex::InterpMode & OIIO_Tex_InterpMode_to_cpp_ref(
    OIIO_Tex_InterpMode * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::Tex::InterpMode * >(rhs));
}

inline OpenImageIO_v2_3_6::Tex::InterpMode const * OIIO_Tex_InterpMode_to_cpp(
    OIIO_Tex_InterpMode const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::Tex::InterpMode const * >(rhs);
}

inline OpenImageIO_v2_3_6::Tex::InterpMode * OIIO_Tex_InterpMode_to_cpp(
    OIIO_Tex_InterpMode * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::Tex::InterpMode * >(rhs);
}

inline void to_c(
    OIIO_Tex_InterpMode const * * lhs
    , OpenImageIO_v2_3_6::Tex::InterpMode const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Tex_InterpMode const * >(&(rhs));
}

inline void to_c(
    OIIO_Tex_InterpMode const * * lhs
    , OpenImageIO_v2_3_6::Tex::InterpMode const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Tex_InterpMode const * >(rhs);
}

inline void to_c(
    OIIO_Tex_InterpMode * * lhs
    , OpenImageIO_v2_3_6::Tex::InterpMode & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Tex_InterpMode * >(&(rhs));
}

inline void to_c(
    OIIO_Tex_InterpMode * * lhs
    , OpenImageIO_v2_3_6::Tex::InterpMode * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_Tex_InterpMode * >(rhs);
}

inline void to_c_copy(
    OIIO_Tex_InterpMode * lhs
    , OpenImageIO_v2_3_6::Tex::InterpMode const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::RunFlagVal const & OIIO_RunFlagVal_to_cpp_ref(
    OIIO_RunFlagVal const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::RunFlagVal const * >(rhs));
}

inline OpenImageIO_v2_3_6::RunFlagVal & OIIO_RunFlagVal_to_cpp_ref(
    OIIO_RunFlagVal * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::RunFlagVal * >(rhs));
}

inline OpenImageIO_v2_3_6::RunFlagVal const * OIIO_RunFlagVal_to_cpp(
    OIIO_RunFlagVal const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::RunFlagVal const * >(rhs);
}

inline OpenImageIO_v2_3_6::RunFlagVal * OIIO_RunFlagVal_to_cpp(
    OIIO_RunFlagVal * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::RunFlagVal * >(rhs);
}

inline void to_c(
    OIIO_RunFlagVal const * * lhs
    , OpenImageIO_v2_3_6::RunFlagVal const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_RunFlagVal const * >(&(rhs));
}

inline void to_c(
    OIIO_RunFlagVal const * * lhs
    , OpenImageIO_v2_3_6::RunFlagVal const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_RunFlagVal const * >(rhs);
}

inline void to_c(
    OIIO_RunFlagVal * * lhs
    , OpenImageIO_v2_3_6::RunFlagVal & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_RunFlagVal * >(&(rhs));
}

inline void to_c(
    OIIO_RunFlagVal * * lhs
    , OpenImageIO_v2_3_6::RunFlagVal * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_RunFlagVal * >(rhs);
}

inline void to_c_copy(
    OIIO_RunFlagVal * lhs
    , OpenImageIO_v2_3_6::RunFlagVal const & rhs)
{
        memcpy(lhs, &(rhs), sizeof(*(lhs)));
}

inline OpenImageIO_v2_3_6::TextureOpt const & to_cpp_ref(
    OIIO_TextureOpt_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::TextureOpt const * >(rhs));
}

inline OpenImageIO_v2_3_6::TextureOpt & to_cpp_ref(
    OIIO_TextureOpt_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::TextureOpt * >(rhs));
}

inline OpenImageIO_v2_3_6::TextureOpt const * to_cpp(
    OIIO_TextureOpt_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::TextureOpt const * >(rhs);
}

inline OpenImageIO_v2_3_6::TextureOpt * to_cpp(
    OIIO_TextureOpt_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::TextureOpt * >(rhs);
}

inline void to_c(
    OIIO_TextureOpt_t const * * lhs
    , OpenImageIO_v2_3_6::TextureOpt const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOpt_t const * >(&(rhs));
}

inline void to_c(
    OIIO_TextureOpt_t const * * lhs
    , OpenImageIO_v2_3_6::TextureOpt const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOpt_t const * >(rhs);
}

inline void to_c(
    OIIO_TextureOpt_t * * lhs
    , OpenImageIO_v2_3_6::TextureOpt & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOpt_t * >(&(rhs));
}

inline void to_c(
    OIIO_TextureOpt_t * * lhs
    , OpenImageIO_v2_3_6::TextureOpt * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOpt_t * >(rhs);
}

inline void to_c_copy(
    OIIO_TextureOpt_t * * lhs
    , OpenImageIO_v2_3_6::TextureOpt const & rhs)
{
        OpenImageIO_v2_3_6__TextureOpt_copy(lhs, reinterpret_cast<OIIO_TextureOpt_t const * >(&(rhs)));
}

inline OpenImageIO_v2_3_6::TextureOptBatch const & to_cpp_ref(
    OIIO_TextureOptBatch_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::TextureOptBatch const * >(rhs));
}

inline OpenImageIO_v2_3_6::TextureOptBatch & to_cpp_ref(
    OIIO_TextureOptBatch_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::TextureOptBatch * >(rhs));
}

inline OpenImageIO_v2_3_6::TextureOptBatch const * to_cpp(
    OIIO_TextureOptBatch_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::TextureOptBatch const * >(rhs);
}

inline OpenImageIO_v2_3_6::TextureOptBatch * to_cpp(
    OIIO_TextureOptBatch_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::TextureOptBatch * >(rhs);
}

inline void to_c(
    OIIO_TextureOptBatch_t const * * lhs
    , OpenImageIO_v2_3_6::TextureOptBatch const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOptBatch_t const * >(&(rhs));
}

inline void to_c(
    OIIO_TextureOptBatch_t const * * lhs
    , OpenImageIO_v2_3_6::TextureOptBatch const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOptBatch_t const * >(rhs);
}

inline void to_c(
    OIIO_TextureOptBatch_t * * lhs
    , OpenImageIO_v2_3_6::TextureOptBatch & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOptBatch_t * >(&(rhs));
}

inline void to_c(
    OIIO_TextureOptBatch_t * * lhs
    , OpenImageIO_v2_3_6::TextureOptBatch * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureOptBatch_t * >(rhs);
}

inline void to_c_copy(
    OIIO_TextureOptBatch_t * * lhs
    , OpenImageIO_v2_3_6::TextureOptBatch const & rhs)
{
        OpenImageIO_v2_3_6__TextureOptBatch_copy(lhs, reinterpret_cast<OIIO_TextureOptBatch_t const * >(&(rhs)));
}

inline OpenImageIO_v2_3_6::TextureSystem const & to_cpp_ref(
    OIIO_TextureSystem_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::TextureSystem const * >(rhs));
}

inline OpenImageIO_v2_3_6::TextureSystem & to_cpp_ref(
    OIIO_TextureSystem_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::TextureSystem * >(rhs));
}

inline OpenImageIO_v2_3_6::TextureSystem const * to_cpp(
    OIIO_TextureSystem_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::TextureSystem const * >(rhs);
}

inline OpenImageIO_v2_3_6::TextureSystem * to_cpp(
    OIIO_TextureSystem_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::TextureSystem * >(rhs);
}

inline void to_c(
    OIIO_TextureSystem_t const * * lhs
    , OpenImageIO_v2_3_6::TextureSystem const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureSystem_t const * >(&(rhs));
}

inline void to_c(
    OIIO_TextureSystem_t const * * lhs
    , OpenImageIO_v2_3_6::TextureSystem const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureSystem_t const * >(rhs);
}

inline void to_c(
    OIIO_TextureSystem_t * * lhs
    , OpenImageIO_v2_3_6::TextureSystem & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureSystem_t * >(&(rhs));
}

inline void to_c(
    OIIO_TextureSystem_t * * lhs
    , OpenImageIO_v2_3_6::TextureSystem * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureSystem_t * >(rhs);
}

inline OpenImageIO_v2_3_6::TextureSystem::Perthread const & to_cpp_ref(
    OIIO_TextureSystem_Perthread_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::TextureSystem::Perthread const * >(rhs));
}

inline OpenImageIO_v2_3_6::TextureSystem::Perthread & to_cpp_ref(
    OIIO_TextureSystem_Perthread_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::TextureSystem::Perthread * >(rhs));
}

inline OpenImageIO_v2_3_6::TextureSystem::Perthread const * to_cpp(
    OIIO_TextureSystem_Perthread_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::TextureSystem::Perthread const * >(rhs);
}

inline OpenImageIO_v2_3_6::TextureSystem::Perthread * to_cpp(
    OIIO_TextureSystem_Perthread_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::TextureSystem::Perthread * >(rhs);
}

inline void to_c(
    OIIO_TextureSystem_Perthread_t const * * lhs
    , OpenImageIO_v2_3_6::TextureSystem::Perthread const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureSystem_Perthread_t const * >(&(rhs));
}

inline void to_c(
    OIIO_TextureSystem_Perthread_t const * * lhs
    , OpenImageIO_v2_3_6::TextureSystem::Perthread const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureSystem_Perthread_t const * >(rhs);
}

inline void to_c(
    OIIO_TextureSystem_Perthread_t * * lhs
    , OpenImageIO_v2_3_6::TextureSystem::Perthread & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureSystem_Perthread_t * >(&(rhs));
}

inline void to_c(
    OIIO_TextureSystem_Perthread_t * * lhs
    , OpenImageIO_v2_3_6::TextureSystem::Perthread * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureSystem_Perthread_t * >(rhs);
}

inline OpenImageIO_v2_3_6::TextureSystem::TextureHandle const & to_cpp_ref(
    OIIO_TextureSystem_TextureHandle_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::TextureSystem::TextureHandle const * >(rhs));
}

inline OpenImageIO_v2_3_6::TextureSystem::TextureHandle & to_cpp_ref(
    OIIO_TextureSystem_TextureHandle_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::TextureSystem::TextureHandle * >(rhs));
}

inline OpenImageIO_v2_3_6::TextureSystem::TextureHandle const * to_cpp(
    OIIO_TextureSystem_TextureHandle_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::TextureSystem::TextureHandle const * >(rhs);
}

inline OpenImageIO_v2_3_6::TextureSystem::TextureHandle * to_cpp(
    OIIO_TextureSystem_TextureHandle_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::TextureSystem::TextureHandle * >(rhs);
}

inline void to_c(
    OIIO_TextureSystem_TextureHandle_t const * * lhs
    , OpenImageIO_v2_3_6::TextureSystem::TextureHandle const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureSystem_TextureHandle_t const * >(&(rhs));
}

inline void to_c(
    OIIO_TextureSystem_TextureHandle_t const * * lhs
    , OpenImageIO_v2_3_6::TextureSystem::TextureHandle const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureSystem_TextureHandle_t const * >(rhs);
}

inline void to_c(
    OIIO_TextureSystem_TextureHandle_t * * lhs
    , OpenImageIO_v2_3_6::TextureSystem::TextureHandle & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureSystem_TextureHandle_t * >(&(rhs));
}

inline void to_c(
    OIIO_TextureSystem_TextureHandle_t * * lhs
    , OpenImageIO_v2_3_6::TextureSystem::TextureHandle * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_TextureSystem_TextureHandle_t * >(rhs);
}

