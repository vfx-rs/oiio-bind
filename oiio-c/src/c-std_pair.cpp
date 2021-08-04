#include "c-std_pair_private.h"

#include "c-string_view_private.h"
#include <new>

#include <stdexcept>

unsigned int std__pair_OIIO__string_view_int__copy(
    std_pair_string_int_t * * this_
    , std_pair_string_int_t const * rhs)
{
    try {
        to_c(this_, new std::pair<OIIO::string_view, int>(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__pair_OIIO__string_view_int__dtor(
    std_pair_string_int_t * this_)
{
    try {
        delete to_cpp(this_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int std__pair_OIIO__string_view_int__get_first(
    std_pair_string_int_t const * this_
    , OIIO_string_view_t const * * return_)
{
        to_c(return_, (to_cpp(this_))->first);
        return 0;
}

unsigned int std__pair_OIIO__string_view_int__set_first(
    std_pair_string_int_t * this_
    , OIIO_string_view_t const * value)
{
        (to_cpp(this_))->first = to_cpp_ref(value);
        return 0;
}

unsigned int std__pair_OIIO__string_view_int__get_second(
    std_pair_string_int_t const * this_
    , int const * * return_)
{
        *(return_) = &((to_cpp(this_))->second);
        return 0;
}

unsigned int std__pair_OIIO__string_view_int__set_second(
    std_pair_string_int_t * this_
    , int const * value)
{
        (to_cpp(this_))->second = *(value);
        return 0;
}

