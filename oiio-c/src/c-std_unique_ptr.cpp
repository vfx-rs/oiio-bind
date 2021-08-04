#include "c-std_unique_ptr_private.h"

#include "c-imageio_private.h"

#include <stdexcept>

unsigned int std__unique_ptr_OIIO__ImageInput__sizeof()
{
        return sizeof(std::unique_ptr<OIIO::ImageInput>);
}

unsigned int std__unique_ptr_OIIO__ImageInput__alignof()
{
        return alignof(std::unique_ptr<OIIO::ImageInput>);
}

unsigned int std__unique_ptr_OIIO__ImageInput__dtor(
    std_ImageInputPtr_t * this_)
{
        (to_cpp(this_)) -> std::unique_ptr<OpenImageIO_v2_3_6::ImageInput, std::default_delete<OpenImageIO_v2_3_6::ImageInput>>::~unique_ptr();
        return 0;
}

unsigned int std__unique_ptr_OIIO__ImageInput__get(
    std_ImageInputPtr_t const * this_
    , OIIO_ImageInput_t * * return_)
{
        to_c(return_, (to_cpp(this_)) -> get());
        return 0;
}

unsigned int std__unique_ptr_OIIO__ImageOutput__sizeof()
{
        return sizeof(std::unique_ptr<OIIO::ImageOutput>);
}

unsigned int std__unique_ptr_OIIO__ImageOutput__alignof()
{
        return alignof(std::unique_ptr<OIIO::ImageOutput>);
}

unsigned int std__unique_ptr_OIIO__ImageOutput__dtor(
    std_ImageOutputPtr_t * this_)
{
        (to_cpp(this_)) -> std::unique_ptr<OpenImageIO_v2_3_6::ImageOutput, std::default_delete<OpenImageIO_v2_3_6::ImageOutput>>::~unique_ptr();
        return 0;
}

unsigned int std__unique_ptr_OIIO__ImageOutput__get(
    std_ImageOutputPtr_t const * this_
    , OIIO_ImageOutput_t * * return_)
{
        to_c(return_, (to_cpp(this_)) -> get());
        return 0;
}

