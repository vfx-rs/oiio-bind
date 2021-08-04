#pragma once
#include <c-std_unique_ptr.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/imageio.h>
#include <cstring>
#include <memory>

inline std::unique_ptr<OIIO::ImageInput> const & to_cpp_ref(
    std_ImageInputPtr_t const * rhs)
{
        return *(reinterpret_cast<std::unique_ptr<OIIO::ImageInput> const * >(rhs));
}

inline std::unique_ptr<OIIO::ImageInput> & to_cpp_ref(
    std_ImageInputPtr_t * rhs)
{
        return *(reinterpret_cast<std::unique_ptr<OIIO::ImageInput> * >(rhs));
}

inline std::unique_ptr<OIIO::ImageInput> const * to_cpp(
    std_ImageInputPtr_t const * rhs)
{
        return reinterpret_cast<std::unique_ptr<OIIO::ImageInput> const * >(rhs);
}

inline std::unique_ptr<OIIO::ImageInput> * to_cpp(
    std_ImageInputPtr_t * rhs)
{
        return reinterpret_cast<std::unique_ptr<OIIO::ImageInput> * >(rhs);
}

inline void to_c(
    std_ImageInputPtr_t const * * lhs
    , std::unique_ptr<OIIO::ImageInput> const & rhs)
{
        *(lhs) = reinterpret_cast<std_ImageInputPtr_t const * >(&(rhs));
}

inline void to_c(
    std_ImageInputPtr_t const * * lhs
    , std::unique_ptr<OIIO::ImageInput> const * rhs)
{
        *(lhs) = reinterpret_cast<std_ImageInputPtr_t const * >(rhs);
}

inline void to_c(
    std_ImageInputPtr_t * * lhs
    , std::unique_ptr<OIIO::ImageInput> & rhs)
{
        *(lhs) = reinterpret_cast<std_ImageInputPtr_t * >(&(rhs));
}

inline void to_c(
    std_ImageInputPtr_t * * lhs
    , std::unique_ptr<OIIO::ImageInput> * rhs)
{
        *(lhs) = reinterpret_cast<std_ImageInputPtr_t * >(rhs);
}

inline void to_c_move(
    std_ImageInputPtr_t * lhs
    , std::unique_ptr<OIIO::ImageInput> rhs)
{
        new (lhs) std::unique_ptr<OIIO::ImageInput>(std::move(rhs));
}

inline std::unique_ptr<OIIO::ImageOutput> const & to_cpp_ref(
    std_ImageOutputPtr_t const * rhs)
{
        return *(reinterpret_cast<std::unique_ptr<OIIO::ImageOutput> const * >(rhs));
}

inline std::unique_ptr<OIIO::ImageOutput> & to_cpp_ref(
    std_ImageOutputPtr_t * rhs)
{
        return *(reinterpret_cast<std::unique_ptr<OIIO::ImageOutput> * >(rhs));
}

inline std::unique_ptr<OIIO::ImageOutput> const * to_cpp(
    std_ImageOutputPtr_t const * rhs)
{
        return reinterpret_cast<std::unique_ptr<OIIO::ImageOutput> const * >(rhs);
}

inline std::unique_ptr<OIIO::ImageOutput> * to_cpp(
    std_ImageOutputPtr_t * rhs)
{
        return reinterpret_cast<std::unique_ptr<OIIO::ImageOutput> * >(rhs);
}

inline void to_c(
    std_ImageOutputPtr_t const * * lhs
    , std::unique_ptr<OIIO::ImageOutput> const & rhs)
{
        *(lhs) = reinterpret_cast<std_ImageOutputPtr_t const * >(&(rhs));
}

inline void to_c(
    std_ImageOutputPtr_t const * * lhs
    , std::unique_ptr<OIIO::ImageOutput> const * rhs)
{
        *(lhs) = reinterpret_cast<std_ImageOutputPtr_t const * >(rhs);
}

inline void to_c(
    std_ImageOutputPtr_t * * lhs
    , std::unique_ptr<OIIO::ImageOutput> & rhs)
{
        *(lhs) = reinterpret_cast<std_ImageOutputPtr_t * >(&(rhs));
}

inline void to_c(
    std_ImageOutputPtr_t * * lhs
    , std::unique_ptr<OIIO::ImageOutput> * rhs)
{
        *(lhs) = reinterpret_cast<std_ImageOutputPtr_t * >(rhs);
}

inline void to_c_move(
    std_ImageOutputPtr_t * lhs
    , std::unique_ptr<OIIO::ImageOutput> rhs)
{
        new (lhs) std::unique_ptr<OIIO::ImageOutput>(std::move(rhs));
}

