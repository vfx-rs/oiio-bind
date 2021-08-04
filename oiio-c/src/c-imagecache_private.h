#pragma once
#include <c-imagecache.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/imagecache.h>
#include <cstring>

inline OpenImageIO_v2_3_6::pvt::ImageCacheImpl const & to_cpp_ref(
    OIIO_pvt_ImageCacheImpl_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::pvt::ImageCacheImpl const * >(rhs));
}

inline OpenImageIO_v2_3_6::pvt::ImageCacheImpl & to_cpp_ref(
    OIIO_pvt_ImageCacheImpl_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::pvt::ImageCacheImpl * >(rhs));
}

inline OpenImageIO_v2_3_6::pvt::ImageCacheImpl const * to_cpp(
    OIIO_pvt_ImageCacheImpl_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::pvt::ImageCacheImpl const * >(rhs);
}

inline OpenImageIO_v2_3_6::pvt::ImageCacheImpl * to_cpp(
    OIIO_pvt_ImageCacheImpl_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::pvt::ImageCacheImpl * >(rhs);
}

inline void to_c(
    OIIO_pvt_ImageCacheImpl_t const * * lhs
    , OpenImageIO_v2_3_6::pvt::ImageCacheImpl const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_ImageCacheImpl_t const * >(&(rhs));
}

inline void to_c(
    OIIO_pvt_ImageCacheImpl_t const * * lhs
    , OpenImageIO_v2_3_6::pvt::ImageCacheImpl const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_ImageCacheImpl_t const * >(rhs);
}

inline void to_c(
    OIIO_pvt_ImageCacheImpl_t * * lhs
    , OpenImageIO_v2_3_6::pvt::ImageCacheImpl & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_ImageCacheImpl_t * >(&(rhs));
}

inline void to_c(
    OIIO_pvt_ImageCacheImpl_t * * lhs
    , OpenImageIO_v2_3_6::pvt::ImageCacheImpl * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_ImageCacheImpl_t * >(rhs);
}

inline OpenImageIO_v2_3_6::pvt::ImageCacheFile const & to_cpp_ref(
    OIIO_pvt_ImageCacheFile_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::pvt::ImageCacheFile const * >(rhs));
}

inline OpenImageIO_v2_3_6::pvt::ImageCacheFile & to_cpp_ref(
    OIIO_pvt_ImageCacheFile_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::pvt::ImageCacheFile * >(rhs));
}

inline OpenImageIO_v2_3_6::pvt::ImageCacheFile const * to_cpp(
    OIIO_pvt_ImageCacheFile_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::pvt::ImageCacheFile const * >(rhs);
}

inline OpenImageIO_v2_3_6::pvt::ImageCacheFile * to_cpp(
    OIIO_pvt_ImageCacheFile_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::pvt::ImageCacheFile * >(rhs);
}

inline void to_c(
    OIIO_pvt_ImageCacheFile_t const * * lhs
    , OpenImageIO_v2_3_6::pvt::ImageCacheFile const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_ImageCacheFile_t const * >(&(rhs));
}

inline void to_c(
    OIIO_pvt_ImageCacheFile_t const * * lhs
    , OpenImageIO_v2_3_6::pvt::ImageCacheFile const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_ImageCacheFile_t const * >(rhs);
}

inline void to_c(
    OIIO_pvt_ImageCacheFile_t * * lhs
    , OpenImageIO_v2_3_6::pvt::ImageCacheFile & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_ImageCacheFile_t * >(&(rhs));
}

inline void to_c(
    OIIO_pvt_ImageCacheFile_t * * lhs
    , OpenImageIO_v2_3_6::pvt::ImageCacheFile * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_ImageCacheFile_t * >(rhs);
}

inline OpenImageIO_v2_3_6::pvt::ImageCachePerThreadInfo const & to_cpp_ref(
    OIIO_pvt_ImageCachePerThreadInfo_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::pvt::ImageCachePerThreadInfo const * >(rhs));
}

inline OpenImageIO_v2_3_6::pvt::ImageCachePerThreadInfo & to_cpp_ref(
    OIIO_pvt_ImageCachePerThreadInfo_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::pvt::ImageCachePerThreadInfo * >(rhs));
}

inline OpenImageIO_v2_3_6::pvt::ImageCachePerThreadInfo const * to_cpp(
    OIIO_pvt_ImageCachePerThreadInfo_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::pvt::ImageCachePerThreadInfo const * >(rhs);
}

inline OpenImageIO_v2_3_6::pvt::ImageCachePerThreadInfo * to_cpp(
    OIIO_pvt_ImageCachePerThreadInfo_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::pvt::ImageCachePerThreadInfo * >(rhs);
}

inline void to_c(
    OIIO_pvt_ImageCachePerThreadInfo_t const * * lhs
    , OpenImageIO_v2_3_6::pvt::ImageCachePerThreadInfo const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_ImageCachePerThreadInfo_t const * >(&(rhs));
}

inline void to_c(
    OIIO_pvt_ImageCachePerThreadInfo_t const * * lhs
    , OpenImageIO_v2_3_6::pvt::ImageCachePerThreadInfo const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_ImageCachePerThreadInfo_t const * >(rhs);
}

inline void to_c(
    OIIO_pvt_ImageCachePerThreadInfo_t * * lhs
    , OpenImageIO_v2_3_6::pvt::ImageCachePerThreadInfo & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_ImageCachePerThreadInfo_t * >(&(rhs));
}

inline void to_c(
    OIIO_pvt_ImageCachePerThreadInfo_t * * lhs
    , OpenImageIO_v2_3_6::pvt::ImageCachePerThreadInfo * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_pvt_ImageCachePerThreadInfo_t * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageCache const & to_cpp_ref(
    OIIO_ImageCache_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageCache const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageCache & to_cpp_ref(
    OIIO_ImageCache_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageCache * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageCache const * to_cpp(
    OIIO_ImageCache_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageCache const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageCache * to_cpp(
    OIIO_ImageCache_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageCache * >(rhs);
}

inline void to_c(
    OIIO_ImageCache_t const * * lhs
    , OpenImageIO_v2_3_6::ImageCache const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageCache_t const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageCache_t const * * lhs
    , OpenImageIO_v2_3_6::ImageCache const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageCache_t const * >(rhs);
}

inline void to_c(
    OIIO_ImageCache_t * * lhs
    , OpenImageIO_v2_3_6::ImageCache & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageCache_t * >(&(rhs));
}

inline void to_c(
    OIIO_ImageCache_t * * lhs
    , OpenImageIO_v2_3_6::ImageCache * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageCache_t * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageCache::Tile const & to_cpp_ref(
    OIIO_ImageCache_Tile_t const * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageCache::Tile const * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageCache::Tile & to_cpp_ref(
    OIIO_ImageCache_Tile_t * rhs)
{
        return *(reinterpret_cast<OpenImageIO_v2_3_6::ImageCache::Tile * >(rhs));
}

inline OpenImageIO_v2_3_6::ImageCache::Tile const * to_cpp(
    OIIO_ImageCache_Tile_t const * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageCache::Tile const * >(rhs);
}

inline OpenImageIO_v2_3_6::ImageCache::Tile * to_cpp(
    OIIO_ImageCache_Tile_t * rhs)
{
        return reinterpret_cast<OpenImageIO_v2_3_6::ImageCache::Tile * >(rhs);
}

inline void to_c(
    OIIO_ImageCache_Tile_t const * * lhs
    , OpenImageIO_v2_3_6::ImageCache::Tile const & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageCache_Tile_t const * >(&(rhs));
}

inline void to_c(
    OIIO_ImageCache_Tile_t const * * lhs
    , OpenImageIO_v2_3_6::ImageCache::Tile const * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageCache_Tile_t const * >(rhs);
}

inline void to_c(
    OIIO_ImageCache_Tile_t * * lhs
    , OpenImageIO_v2_3_6::ImageCache::Tile & rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageCache_Tile_t * >(&(rhs));
}

inline void to_c(
    OIIO_ImageCache_Tile_t * * lhs
    , OpenImageIO_v2_3_6::ImageCache::Tile * rhs)
{
        *(lhs) = reinterpret_cast<OIIO_ImageCache_Tile_t * >(rhs);
}

