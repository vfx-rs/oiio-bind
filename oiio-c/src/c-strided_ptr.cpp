#include "c-strided_ptr_private.h"

#include <new>

#include <stdexcept>

unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1__sizeof()
{
        return sizeof(OpenImageIO_v2_3_6::strided_ptr<float, 1>);
}

unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1__alignof()
{
        return alignof(OpenImageIO_v2_3_6::strided_ptr<float, 1>);
}

unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1__ctor(
    OIIO_strided_ptr_float_t * this_
    , float * ptr
    , long stride)
{
        new (this_) OpenImageIO_v2_3_6::strided_ptr<float, 1>(ptr, stride);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1__copy(
    OIIO_strided_ptr_float_t * this_
    , OIIO_strided_ptr_float_t const * p)
{
        new (this_) OpenImageIO_v2_3_6::strided_ptr<float, 1>(to_cpp_ref(p));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1___assign(
    OIIO_strided_ptr_float_t * this_
    , OIIO_strided_ptr_float_t const * * return_
    , OIIO_strided_ptr_float_t const * p)
{
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(p)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1___index(
    OIIO_strided_ptr_float_t const * this_
    , float * * return_
    , long pos)
{
    try {
        *(return_) = &((to_cpp(this_)) -> operator[](pos));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1__data(
    OIIO_strided_ptr_float_t const * this_
    , float * * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1__stride(
    OIIO_strided_ptr_float_t const * this_
    , long * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> stride();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1__dtor(
    OIIO_strided_ptr_float_t * this_)
{
        (to_cpp(this_)) -> OpenImageIO_v2_3_6::strided_ptr<float, 1>::~strided_ptr();
        return 0;
}

