#include "c-string_view_private.h"

#include "c-std_string_private.h"
#include <new>

#include <stdexcept>

unsigned int OpenImageIO_v2_3_6__string_view_sizeof()
{
        return sizeof(OpenImageIO_v2_3_6::string_view);
}

unsigned int OpenImageIO_v2_3_6__string_view_alignof()
{
        return alignof(OpenImageIO_v2_3_6::string_view);
}

unsigned int OpenImageIO_v2_3_6__string_view_ctor(
    OIIO_string_view_t * this_)
{
        new (this_) OpenImageIO_v2_3_6::string_view();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__string_view_copy(
    OIIO_string_view_t * this_
    , OIIO_string_view_t const * copy)
{
    try {
        new (this_) OpenImageIO_v2_3_6::string_view(to_cpp_ref(copy));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__string_view_from_char_array(
    OIIO_string_view_t * this_
    , char const * chars
    , unsigned long len)
{
    try {
        new (this_) OpenImageIO_v2_3_6::string_view(chars, len);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__string_view_from_c_str(
    OIIO_string_view_t * this_
    , char const * chars)
{
    try {
        new (this_) OpenImageIO_v2_3_6::string_view(chars);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__string_view_from_string(
    OIIO_string_view_t * this_
    , std_string_t const * str)
{
        new (this_) OpenImageIO_v2_3_6::string_view(to_cpp_ref(str));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__string_view_str(
    OIIO_string_view_t const * this_
    , std_string_t * * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> str());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__string_view_c_str(
    OIIO_string_view_t const * this_
    , char const * * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> c_str();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__string_view__assign(
    OIIO_string_view_t * this_
    , OIIO_string_view_t * * return_
    , OIIO_string_view_t const * copy)
{
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(copy)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__string_view_begin(
    OIIO_string_view_t const * this_
    , char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> begin();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__string_view_end(
    OIIO_string_view_t const * this_
    , char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> end();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__string_view_cbegin(
    OIIO_string_view_t const * this_
    , char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> cbegin();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__string_view_cend(
    OIIO_string_view_t const * this_
    , char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> cend();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__string_view_size(
    OIIO_string_view_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__string_view_length(
    OIIO_string_view_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> length();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__string_view_max_size(
    OIIO_string_view_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> max_size();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__string_view_empty(
    OIIO_string_view_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> empty();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__string_view__index(
    OIIO_string_view_t const * this_
    , char const * * return_
    , unsigned long pos)
{
    try {
        *(return_) = &((to_cpp(this_)) -> operator[](pos));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__string_view_at(
    OIIO_string_view_t const * this_
    , char const * * return_
    , unsigned long pos)
{
    try {
        *(return_) = &((to_cpp(this_)) -> at(pos));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__string_view_data(
    OIIO_string_view_t const * this_
    , char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__string_view_clear(
    OIIO_string_view_t * this_)
{
        (to_cpp(this_)) -> clear();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__string_view_dtor(
    OIIO_string_view_t * this_)
{
        (to_cpp(this_)) -> OpenImageIO_v2_3_6::string_view::~string_view();
        return 0;
}

