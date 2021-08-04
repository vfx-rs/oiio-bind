#include "c-ustring_private.h"

#include "c-std_vector_private.h"
#include <new>

#include <stdexcept>

unsigned int OpenImageIO_v2_3_6__ustring_sizeof()
{
        return sizeof(OpenImageIO_v2_3_6::ustring);
}

unsigned int OpenImageIO_v2_3_6__ustring_alignof()
{
        return alignof(OpenImageIO_v2_3_6::ustring);
}

unsigned int OpenImageIO_v2_3_6__ustring_ctor(
    OIIO_ustring_t * this_
    , char const * str)
{
    try {
        new (this_) OpenImageIO_v2_3_6::ustring(str);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ustring_copy(
    OIIO_ustring_t * this_
    , OIIO_ustring_t const * str)
{
        new (this_) OpenImageIO_v2_3_6::ustring(to_cpp_ref(str));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ustring_dtor(
    OIIO_ustring_t * this_)
{
        (to_cpp(this_)) -> OpenImageIO_v2_3_6::ustring::~ustring();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ustring__assign(
    OIIO_ustring_t * this_
    , OIIO_ustring_t const * * return_
    , OIIO_ustring_t const * str)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(str)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ustring_c_str(
    OIIO_ustring_t const * this_
    , char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> c_str();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ustring_data(
    OIIO_ustring_t const * this_
    , char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ustring_clear(
    OIIO_ustring_t * this_)
{
        (to_cpp(this_)) -> clear();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ustring_length(
    OIIO_ustring_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> length();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ustring_hash(
    OIIO_ustring_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> hash();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ustring_size(
    OIIO_ustring_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ustring_empty(
    OIIO_ustring_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> empty();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ustring__eq(
    OIIO_ustring_t const * this_
    , _Bool * return_
    , OIIO_ustring_t const * str)
{
        *(return_) = (to_cpp(this_)) -> operator==(to_cpp_ref(str));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ustring__ne(
    OIIO_ustring_t const * this_
    , _Bool * return_
    , OIIO_ustring_t const * str)
{
        *(return_) = (to_cpp(this_)) -> operator!=(to_cpp_ref(str));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ustring_total_ustrings(
    unsigned long * return_)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ustring::total_ustrings();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ustring_hash_collisions(
    unsigned long * return_
    , std_vector_ustring_t * collisions)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ustring::hash_collisions(to_cpp(collisions));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

