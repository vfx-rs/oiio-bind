#pragma once
#include <c-std_shared_ptr.h>


#include "oiio-errors-private.h"

#include <OpenImageIO/color.h>
#include <cstring>
#include <memory>

inline std::shared_ptr<OIIO::ColorProcessor> const & to_cpp_ref(
    std_ColorProcessorHandle_t const * rhs)
{
        return *(reinterpret_cast<std::shared_ptr<OIIO::ColorProcessor> const * >(rhs));
}

inline std::shared_ptr<OIIO::ColorProcessor> & to_cpp_ref(
    std_ColorProcessorHandle_t * rhs)
{
        return *(reinterpret_cast<std::shared_ptr<OIIO::ColorProcessor> * >(rhs));
}

inline std::shared_ptr<OIIO::ColorProcessor> const * to_cpp(
    std_ColorProcessorHandle_t const * rhs)
{
        return reinterpret_cast<std::shared_ptr<OIIO::ColorProcessor> const * >(rhs);
}

inline std::shared_ptr<OIIO::ColorProcessor> * to_cpp(
    std_ColorProcessorHandle_t * rhs)
{
        return reinterpret_cast<std::shared_ptr<OIIO::ColorProcessor> * >(rhs);
}

inline void to_c(
    std_ColorProcessorHandle_t const * * lhs
    , std::shared_ptr<OIIO::ColorProcessor> const & rhs)
{
        *(lhs) = reinterpret_cast<std_ColorProcessorHandle_t const * >(&(rhs));
}

inline void to_c(
    std_ColorProcessorHandle_t const * * lhs
    , std::shared_ptr<OIIO::ColorProcessor> const * rhs)
{
        *(lhs) = reinterpret_cast<std_ColorProcessorHandle_t const * >(rhs);
}

inline void to_c(
    std_ColorProcessorHandle_t * * lhs
    , std::shared_ptr<OIIO::ColorProcessor> & rhs)
{
        *(lhs) = reinterpret_cast<std_ColorProcessorHandle_t * >(&(rhs));
}

inline void to_c(
    std_ColorProcessorHandle_t * * lhs
    , std::shared_ptr<OIIO::ColorProcessor> * rhs)
{
        *(lhs) = reinterpret_cast<std_ColorProcessorHandle_t * >(rhs);
}

inline void to_c_copy(
    std_ColorProcessorHandle_t * * lhs
    , std::shared_ptr<OIIO::ColorProcessor> const & rhs)
{
        std__shared_ptr_OIIO__ColorProcessor__copy(lhs, reinterpret_cast<std_ColorProcessorHandle_t const * >(&(rhs)));
}

