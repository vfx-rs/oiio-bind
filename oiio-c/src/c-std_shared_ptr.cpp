#include "c-std_shared_ptr_private.h"

#include <new>

#include <stdexcept>

unsigned int std__shared_ptr_OIIO__ColorProcessor__copy(
    std_ColorProcessorHandle_t * * this_
    , std_ColorProcessorHandle_t const * rhs)
{
        to_c(this_, new std::shared_ptr<OIIO::ColorProcessor>(to_cpp_ref(rhs)));
        return 0;
}

unsigned int std__shared_ptr_OIIO__ColorProcessor__dtor(
    std_ColorProcessorHandle_t * this_)
{
        delete to_cpp(this_);
        return 0;
}

