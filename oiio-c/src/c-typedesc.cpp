#include "c-typedesc_private.h"

#include "c-string_view_private.h"
#include <new>

#include <stdexcept>

unsigned int OpenImageIO_v2_3_6__TypeDesc_ctor(
    OIIO_TypeDesc_t * this_
    , OIIO_TypeDesc_BASETYPE btype
    , OIIO_TypeDesc_AGGREGATE agg
    , OIIO_TypeDesc_VECSEMANTICS semantics
    , int arraylen)
{
        new (this_) OpenImageIO_v2_3_6::TypeDesc(OIIO_TypeDesc_BASETYPE_to_cpp_ref(&(btype)), OIIO_TypeDesc_AGGREGATE_to_cpp_ref(&(agg)), OIIO_TypeDesc_VECSEMANTICS_to_cpp_ref(&(semantics)), arraylen);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_from_basetype(
    OIIO_TypeDesc_t * this_
    , OIIO_TypeDesc_BASETYPE btype
    , int arraylen)
{
        new (this_) OpenImageIO_v2_3_6::TypeDesc(OIIO_TypeDesc_BASETYPE_to_cpp_ref(&(btype)), arraylen);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_from_string(
    OIIO_TypeDesc_t * this_
    , OIIO_string_view_t typestring)
{
    try {
        new (this_) OpenImageIO_v2_3_6::TypeDesc(to_cpp_ref(&(typestring)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_copy(
    OIIO_TypeDesc_t * this_
    , OIIO_TypeDesc_t const * t)
{
        new (this_) OpenImageIO_v2_3_6::TypeDesc(to_cpp_ref(t));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_c_str(
    OIIO_TypeDesc_t const * this_
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

unsigned int OpenImageIO_v2_3_6__TypeDesc_numelements(
    OIIO_TypeDesc_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> numelements();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_basevalues(
    OIIO_TypeDesc_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> basevalues();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_is_array(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> is_array();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_is_unsized_array(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> is_unsized_array();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_is_sized_array(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> is_sized_array();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_size(
    OIIO_TypeDesc_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_elementtype(
    OIIO_TypeDesc_t const * this_
    , OIIO_TypeDesc_t * return_)
{
        to_c_copy(return_, (to_cpp(this_)) -> elementtype());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_elementsize(
    OIIO_TypeDesc_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> elementsize();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_scalartype(
    OIIO_TypeDesc_t const * this_
    , OIIO_TypeDesc_t * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> scalartype());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_basesize(
    OIIO_TypeDesc_t const * this_
    , unsigned long * return_)
{
        *(return_) = (to_cpp(this_)) -> basesize();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_is_floating_point(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> is_floating_point();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_is_signed(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> is_signed();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_is_unknown(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> is_unknown();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_fromstring(
    OIIO_TypeDesc_t * this_
    , unsigned long * return_
    , OIIO_string_view_t typestring)
{
    try {
        *(return_) = (to_cpp(this_)) -> fromstring(to_cpp_ref(&(typestring)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TypeDesc__eq(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_t const * t)
{
        *(return_) = (to_cpp(this_)) -> operator==(to_cpp_ref(t));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc__ne(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_t const * t)
{
        *(return_) = (to_cpp(this_)) -> operator!=(to_cpp_ref(t));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_equivalent(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_t const * b)
{
        *(return_) = (to_cpp(this_)) -> equivalent(to_cpp_ref(b));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_is_vec2(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_BASETYPE b)
{
        *(return_) = (to_cpp(this_)) -> is_vec2(OIIO_TypeDesc_BASETYPE_to_cpp_ref(&(b)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_is_vec3(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_BASETYPE b)
{
        *(return_) = (to_cpp(this_)) -> is_vec3(OIIO_TypeDesc_BASETYPE_to_cpp_ref(&(b)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_is_vec4(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_BASETYPE b)
{
        *(return_) = (to_cpp(this_)) -> is_vec4(OIIO_TypeDesc_BASETYPE_to_cpp_ref(&(b)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_is_box2(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_BASETYPE b)
{
        *(return_) = (to_cpp(this_)) -> is_box2(OIIO_TypeDesc_BASETYPE_to_cpp_ref(&(b)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_is_box3(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_BASETYPE b)
{
        *(return_) = (to_cpp(this_)) -> is_box3(OIIO_TypeDesc_BASETYPE_to_cpp_ref(&(b)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_unarray(
    OIIO_TypeDesc_t * this_)
{
        (to_cpp(this_)) -> unarray();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_operator_(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_t const * x)
{
        *(return_) = (to_cpp(this_)) -> operator<(to_cpp_ref(x));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_basetype_merge(
    OIIO_TypeDesc_BASETYPE * return_
    , OIIO_TypeDesc_t a
    , OIIO_TypeDesc_t b)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::TypeDesc::basetype_merge(to_cpp_ref(&(a)), to_cpp_ref(&(b))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TypeDesc_dtor(
    OIIO_TypeDesc_t * this_)
{
        (to_cpp(this_)) -> OpenImageIO_v2_3_6::TypeDesc::~TypeDesc();
        return 0;
}

