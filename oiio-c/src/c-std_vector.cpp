#include "c-std_vector_private.h"

#include "c-std_string_private.h"
#include "c-string_view_private.h"
#include "c-typedesc_private.h"
#include "c-ustring_private.h"
#include <new>

#include <stdexcept>

unsigned int std__vector_std__string__ctor(
    std_vector_string_t * * this_)
{
    try {
        to_c(this_, new std::vector<std::string>());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_std__string__copy(
    std_vector_string_t * * this_
    , std_vector_string_t const * rhs)
{
    try {
        to_c(this_, new std::vector<std::string>(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_std__string__dtor(
    std_vector_string_t * this_)
{
        delete to_cpp(this_);
        return 0;
}

unsigned int std__vector_std__string__size(
    std_vector_string_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int std__vector_std__string__index(
    std_vector_string_t const * this_
    , std_string_t const * * return_
    , unsigned long pos)
{
        to_c(return_, (to_cpp(this_)) -> operator[](pos));
        return 0;
}

unsigned int std__vector_std__string__data(
    std_vector_string_t * this_
    , std_string_t * * return_)
{
        to_c(return_, (to_cpp(this_)) -> data());
        return 0;
}

unsigned int std__vector_std__string__data_const(
    std_vector_string_t const * this_
    , std_string_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> data());
        return 0;
}

unsigned int std__vector_std__string__push_back(
    std_vector_string_t * this_
    , std_string_t const * value)
{
    try {
        (to_cpp(this_)) -> push_back(to_cpp_ref(value));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_OIIO__string_view__ctor(
    std_vector_string_view_t * * this_)
{
    try {
        to_c(this_, new std::vector<OIIO::string_view>());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_OIIO__string_view__copy(
    std_vector_string_view_t * * this_
    , std_vector_string_view_t const * rhs)
{
    try {
        to_c(this_, new std::vector<OIIO::string_view>(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_OIIO__string_view__dtor(
    std_vector_string_view_t * this_)
{
        delete to_cpp(this_);
        return 0;
}

unsigned int std__vector_OIIO__string_view__size(
    std_vector_string_view_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int std__vector_OIIO__string_view__index(
    std_vector_string_view_t const * this_
    , OIIO_string_view_t const * * return_
    , unsigned long pos)
{
        to_c(return_, (to_cpp(this_)) -> operator[](pos));
        return 0;
}

unsigned int std__vector_OIIO__string_view__data(
    std_vector_string_view_t * this_
    , OIIO_string_view_t * * return_)
{
        to_c(return_, (to_cpp(this_)) -> data());
        return 0;
}

unsigned int std__vector_OIIO__string_view__data_const(
    std_vector_string_view_t const * this_
    , OIIO_string_view_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> data());
        return 0;
}

unsigned int std__vector_OIIO__string_view__push_back(
    std_vector_string_view_t * this_
    , OIIO_string_view_t const * value)
{
    try {
        (to_cpp(this_)) -> push_back(to_cpp_ref(value));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_OIIO__ustring__ctor(
    std_vector_ustring_t * * this_)
{
    try {
        to_c(this_, new std::vector<OIIO::ustring>());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_OIIO__ustring__copy(
    std_vector_ustring_t * * this_
    , std_vector_ustring_t const * rhs)
{
    try {
        to_c(this_, new std::vector<OIIO::ustring>(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_OIIO__ustring__dtor(
    std_vector_ustring_t * this_)
{
        delete to_cpp(this_);
        return 0;
}

unsigned int std__vector_OIIO__ustring__size(
    std_vector_ustring_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int std__vector_OIIO__ustring__index(
    std_vector_ustring_t const * this_
    , OIIO_ustring_t const * * return_
    , unsigned long pos)
{
        to_c(return_, (to_cpp(this_)) -> operator[](pos));
        return 0;
}

unsigned int std__vector_OIIO__ustring__data(
    std_vector_ustring_t * this_
    , OIIO_ustring_t * * return_)
{
        to_c(return_, (to_cpp(this_)) -> data());
        return 0;
}

unsigned int std__vector_OIIO__ustring__data_const(
    std_vector_ustring_t const * this_
    , OIIO_ustring_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> data());
        return 0;
}

unsigned int std__vector_OIIO__ustring__push_back(
    std_vector_ustring_t * this_
    , OIIO_ustring_t const * value)
{
    try {
        (to_cpp(this_)) -> push_back(to_cpp_ref(value));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_char__ctor(
    std_vector_char_t * * this_)
{
    try {
        to_c(this_, new std::vector<char>());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_char__copy(
    std_vector_char_t * * this_
    , std_vector_char_t const * rhs)
{
    try {
        to_c(this_, new std::vector<char>(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_char__dtor(
    std_vector_char_t * this_)
{
        delete to_cpp(this_);
        return 0;
}

unsigned int std__vector_char__size(
    std_vector_char_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int std__vector_char__index(
    std_vector_char_t const * this_
    , char const * * return_
    , unsigned long pos)
{
        *(return_) = &((to_cpp(this_)) -> operator[](pos));
        return 0;
}

unsigned int std__vector_char__data(
    std_vector_char_t * this_
    , char * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int std__vector_char__data_const(
    std_vector_char_t const * this_
    , char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int std__vector_char__push_back(
    std_vector_char_t * this_
    , char const * value)
{
    try {
        (to_cpp(this_)) -> push_back(*(value));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_unsignedchar__ctor(
    std_vector_uchar_t * * this_)
{
    try {
        to_c(this_, new std::vector<unsigned char>());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_unsignedchar__copy(
    std_vector_uchar_t * * this_
    , std_vector_uchar_t const * rhs)
{
    try {
        to_c(this_, new std::vector<unsigned char>(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_unsignedchar__dtor(
    std_vector_uchar_t * this_)
{
        delete to_cpp(this_);
        return 0;
}

unsigned int std__vector_unsignedchar__size(
    std_vector_uchar_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int std__vector_unsignedchar__index(
    std_vector_uchar_t const * this_
    , unsigned char const * * return_
    , unsigned long pos)
{
        *(return_) = &((to_cpp(this_)) -> operator[](pos));
        return 0;
}

unsigned int std__vector_unsignedchar__data(
    std_vector_uchar_t * this_
    , unsigned char * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int std__vector_unsignedchar__data_const(
    std_vector_uchar_t const * this_
    , unsigned char const * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int std__vector_unsignedchar__push_back(
    std_vector_uchar_t * this_
    , unsigned char const * value)
{
    try {
        (to_cpp(this_)) -> push_back(*(value));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_float__ctor(
    std_vector_float_t * * this_)
{
    try {
        to_c(this_, new std::vector<float>());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_float__copy(
    std_vector_float_t * * this_
    , std_vector_float_t const * rhs)
{
    try {
        to_c(this_, new std::vector<float>(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_float__dtor(
    std_vector_float_t * this_)
{
        delete to_cpp(this_);
        return 0;
}

unsigned int std__vector_float__size(
    std_vector_float_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int std__vector_float__index(
    std_vector_float_t const * this_
    , float const * * return_
    , unsigned long pos)
{
        *(return_) = &((to_cpp(this_)) -> operator[](pos));
        return 0;
}

unsigned int std__vector_float__data(
    std_vector_float_t * this_
    , float * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int std__vector_float__data_const(
    std_vector_float_t const * this_
    , float const * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int std__vector_float__push_back(
    std_vector_float_t * this_
    , float const * value)
{
    try {
        (to_cpp(this_)) -> push_back(*(value));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_unsignedlong__ctor(
    std_vector_ulong_t * * this_)
{
    try {
        to_c(this_, new std::vector<unsigned long>());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_unsignedlong__copy(
    std_vector_ulong_t * * this_
    , std_vector_ulong_t const * rhs)
{
    try {
        to_c(this_, new std::vector<unsigned long>(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_unsignedlong__dtor(
    std_vector_ulong_t * this_)
{
        delete to_cpp(this_);
        return 0;
}

unsigned int std__vector_unsignedlong__size(
    std_vector_ulong_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int std__vector_unsignedlong__index(
    std_vector_ulong_t const * this_
    , unsigned long const * * return_
    , unsigned long pos)
{
        *(return_) = &((to_cpp(this_)) -> operator[](pos));
        return 0;
}

unsigned int std__vector_unsignedlong__data(
    std_vector_ulong_t * this_
    , unsigned long * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int std__vector_unsignedlong__data_const(
    std_vector_ulong_t const * this_
    , unsigned long const * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int std__vector_unsignedlong__push_back(
    std_vector_ulong_t * this_
    , unsigned long const * value)
{
    try {
        (to_cpp(this_)) -> push_back(*(value));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_int__ctor(
    std_vector_int_t * * this_)
{
    try {
        to_c(this_, new std::vector<int>());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_int__copy(
    std_vector_int_t * * this_
    , std_vector_int_t const * rhs)
{
    try {
        to_c(this_, new std::vector<int>(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_int__dtor(
    std_vector_int_t * this_)
{
        delete to_cpp(this_);
        return 0;
}

unsigned int std__vector_int__size(
    std_vector_int_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int std__vector_int__index(
    std_vector_int_t const * this_
    , int const * * return_
    , unsigned long pos)
{
        *(return_) = &((to_cpp(this_)) -> operator[](pos));
        return 0;
}

unsigned int std__vector_int__data(
    std_vector_int_t * this_
    , int * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int std__vector_int__data_const(
    std_vector_int_t const * this_
    , int const * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int std__vector_int__push_back(
    std_vector_int_t * this_
    , int const * value)
{
    try {
        (to_cpp(this_)) -> push_back(*(value));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_OIIO__TypeDesc__ctor(
    std_vector_typedesc_t * * this_)
{
    try {
        to_c(this_, new std::vector<OIIO::TypeDesc>());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_OIIO__TypeDesc__copy(
    std_vector_typedesc_t * * this_
    , std_vector_typedesc_t const * rhs)
{
    try {
        to_c(this_, new std::vector<OIIO::TypeDesc>(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__vector_OIIO__TypeDesc__dtor(
    std_vector_typedesc_t * this_)
{
        delete to_cpp(this_);
        return 0;
}

unsigned int std__vector_OIIO__TypeDesc__size(
    std_vector_typedesc_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int std__vector_OIIO__TypeDesc__index(
    std_vector_typedesc_t const * this_
    , OIIO_TypeDesc_t const * * return_
    , unsigned long pos)
{
        to_c(return_, (to_cpp(this_)) -> operator[](pos));
        return 0;
}

unsigned int std__vector_OIIO__TypeDesc__data(
    std_vector_typedesc_t * this_
    , OIIO_TypeDesc_t * * return_)
{
        to_c(return_, (to_cpp(this_)) -> data());
        return 0;
}

unsigned int std__vector_OIIO__TypeDesc__data_const(
    std_vector_typedesc_t const * this_
    , OIIO_TypeDesc_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> data());
        return 0;
}

unsigned int std__vector_OIIO__TypeDesc__push_back(
    std_vector_typedesc_t * this_
    , OIIO_TypeDesc_t const * value)
{
    try {
        (to_cpp(this_)) -> push_back(to_cpp_ref(value));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

