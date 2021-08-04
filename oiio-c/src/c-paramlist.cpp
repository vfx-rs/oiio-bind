#include "c-paramlist_private.h"

#include "c-std_string_private.h"
#include "c-string_view_private.h"
#include "c-typedesc_private.h"
#include "c-ustring_private.h"
#include <new>

#include <stdexcept>

unsigned int OpenImageIO_v2_3_6__ParamValue_sizeof()
{
        return sizeof(OpenImageIO_v2_3_6::ParamValue);
}

unsigned int OpenImageIO_v2_3_6__ParamValue_alignof()
{
        return alignof(OpenImageIO_v2_3_6::ParamValue);
}

unsigned int OpenImageIO_v2_3_6__ParamValue_default(
    OIIO_ParamValue_t * this_)
{
        new (this_) OpenImageIO_v2_3_6::ParamValue();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_ctor_ustring(
    OIIO_ParamValue_t * this_
    , OIIO_ustring_t const * _name
    , OIIO_TypeDesc_t _type
    , int _nvalues
    , void const * _value
    , _Bool _copy)
{
        new (this_) OpenImageIO_v2_3_6::ParamValue(to_cpp_ref(_name), to_cpp_ref(&(_type)), _nvalues, _value, _copy);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_with_interp_ustring(
    OIIO_ParamValue_t * this_
    , OIIO_ustring_t const * _name
    , OIIO_TypeDesc_t _type
    , int _nvalues
    , OIIO_ParamValue_Interp _interp
    , void const * _value
    , _Bool _copy)
{
        new (this_) OpenImageIO_v2_3_6::ParamValue(to_cpp_ref(_name), to_cpp_ref(&(_type)), _nvalues, OIIO_ParamValue_Interp_to_cpp_ref(&(_interp)), _value, _copy);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_ctor(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , OIIO_TypeDesc_t _type
    , int _nvalues
    , void const * _value
    , _Bool _copy)
{
        new (this_) OpenImageIO_v2_3_6::ParamValue(to_cpp_ref(&(_name)), to_cpp_ref(&(_type)), _nvalues, _value, _copy);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_with_interp(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , OIIO_TypeDesc_t _type
    , int _nvalues
    , OIIO_ParamValue_Interp _interp
    , void const * _value
    , _Bool _copy)
{
        new (this_) OpenImageIO_v2_3_6::ParamValue(to_cpp_ref(&(_name)), to_cpp_ref(&(_type)), _nvalues, OIIO_ParamValue_Interp_to_cpp_ref(&(_interp)), _value, _copy);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_from_int(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , int value)
{
        new (this_) OpenImageIO_v2_3_6::ParamValue(to_cpp_ref(&(_name)), value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_from_float(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , float value)
{
        new (this_) OpenImageIO_v2_3_6::ParamValue(to_cpp_ref(&(_name)), value);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_from_ustring(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , OIIO_ustring_t value)
{
        new (this_) OpenImageIO_v2_3_6::ParamValue(to_cpp_ref(&(_name)), to_cpp_ref(&(value)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_from_string(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , OIIO_string_view_t value)
{
        new (this_) OpenImageIO_v2_3_6::ParamValue(to_cpp_ref(&(_name)), to_cpp_ref(&(value)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_parse(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , OIIO_TypeDesc_t type
    , OIIO_string_view_t value)
{
    try {
        new (this_) OpenImageIO_v2_3_6::ParamValue(to_cpp_ref(&(_name)), to_cpp_ref(&(type)), to_cpp_ref(&(value)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValue_copy(
    OIIO_ParamValue_t * this_
    , OIIO_ParamValue_t const * p)
{
        new (this_) OpenImageIO_v2_3_6::ParamValue(to_cpp_ref(p));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_dtor(
    OIIO_ParamValue_t * this_)
{
        (to_cpp(this_)) -> OpenImageIO_v2_3_6::ParamValue::~ParamValue();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_init_with_interp_ustring(
    OIIO_ParamValue_t * this_
    , OIIO_ustring_t _name
    , OIIO_TypeDesc_t _type
    , int _nvalues
    , OIIO_ParamValue_Interp _interp
    , void const * _value
    , _Bool _copy)
{
        (to_cpp(this_)) -> init(to_cpp_ref(&(_name)), to_cpp_ref(&(_type)), _nvalues, OIIO_ParamValue_Interp_to_cpp_ref(&(_interp)), _value, _copy);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_init_ustring(
    OIIO_ParamValue_t * this_
    , OIIO_ustring_t _name
    , OIIO_TypeDesc_t _type
    , int _nvalues
    , void const * _value
    , _Bool _copy)
{
        (to_cpp(this_)) -> init(to_cpp_ref(&(_name)), to_cpp_ref(&(_type)), _nvalues, _value, _copy);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_init(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , OIIO_TypeDesc_t _type
    , int _nvalues
    , void const * _value
    , _Bool _copy)
{
        (to_cpp(this_)) -> init(to_cpp_ref(&(_name)), to_cpp_ref(&(_type)), _nvalues, _value, _copy);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_init_with_interp(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , OIIO_TypeDesc_t _type
    , int _nvalues
    , OIIO_ParamValue_Interp _interp
    , void const * _value
    , _Bool _copy)
{
        (to_cpp(this_)) -> init(to_cpp_ref(&(_name)), to_cpp_ref(&(_type)), _nvalues, OIIO_ParamValue_Interp_to_cpp_ref(&(_interp)), _value, _copy);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue__assign(
    OIIO_ParamValue_t * this_
    , OIIO_ParamValue_t const * * return_
    , OIIO_ParamValue_t const * p)
{
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(p)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_name(
    OIIO_ParamValue_t const * this_
    , OIIO_ustring_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> name());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_uname(
    OIIO_ParamValue_t const * this_
    , OIIO_ustring_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> uname());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_type(
    OIIO_ParamValue_t const * this_
    , OIIO_TypeDesc_t * return_)
{
        to_c_copy(return_, (to_cpp(this_)) -> type());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_nvalues(
    OIIO_ParamValue_t const * this_
    , int * return_)
{
        *(return_) = (to_cpp(this_)) -> nvalues();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_data(
    OIIO_ParamValue_t const * this_
    , void const * * return_)
{
        *(return_) = (to_cpp(this_)) -> data();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_datasize(
    OIIO_ParamValue_t const * this_
    , int * return_)
{
        *(return_) = (to_cpp(this_)) -> datasize();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_interp_const(
    OIIO_ParamValue_t const * this_
    , OIIO_ParamValue_Interp * return_)
{
        to_c_copy(return_, (to_cpp(this_)) -> interp());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_interp(
    OIIO_ParamValue_t * this_
    , OIIO_ParamValue_Interp i)
{
        (to_cpp(this_)) -> interp(OIIO_ParamValue_Interp_to_cpp_ref(&(i)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_is_nonlocal(
    OIIO_ParamValue_t const * this_
    , _Bool * return_)
{
        *(return_) = (to_cpp(this_)) -> is_nonlocal();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValue_get_int(
    OIIO_ParamValue_t const * this_
    , int * return_
    , int defaultval)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_int(defaultval);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValue_get_int_indexed(
    OIIO_ParamValue_t const * this_
    , int * return_
    , int index
    , int defaultval)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_int_indexed(index, defaultval);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValue_get_float(
    OIIO_ParamValue_t const * this_
    , float * return_
    , float defaultval)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_float(defaultval);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValue_get_float_indexed(
    OIIO_ParamValue_t const * this_
    , float * return_
    , int index
    , float defaultval)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_float_indexed(index, defaultval);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValue_get_string(
    OIIO_ParamValue_t const * this_
    , std_string_t * * return_
    , int maxsize)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> get_string(maxsize));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValue_get_string_indexed(
    OIIO_ParamValue_t const * this_
    , std_string_t * * return_
    , int index)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> get_string_indexed(index));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValue_get_ustring(
    OIIO_ParamValue_t const * this_
    , OIIO_ustring_t * return_
    , int maxsize)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> get_ustring(maxsize));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValue_get_ustring_indexed(
    OIIO_ParamValue_t const * this_
    , OIIO_ustring_t * return_
    , int index)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> get_ustring_indexed(index));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_data(
    OIIO_ParamValueList_t * this_
    , OIIO_ParamValue_t * * return_)
{
        to_c(return_, (to_cpp(this_)) -> data());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_data_const(
    OIIO_ParamValueList_t const * this_
    , OIIO_ParamValue_t const * * return_)
{
        to_c(return_, (to_cpp(this_)) -> data());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_push_back(
    OIIO_ParamValueList_t * this_
    , OIIO_ParamValue_t const * __x)
{
    try {
        (to_cpp(this_)) -> push_back(to_cpp_ref(__x));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_pop_back(
    OIIO_ParamValueList_t * this_)
{
        (to_cpp(this_)) -> pop_back();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_clear(
    OIIO_ParamValueList_t * this_)
{
        (to_cpp(this_)) -> clear();
        return 0;
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_ctor(
    OIIO_ParamValueList_t * * this_)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::ParamValueList());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_grow(
    OIIO_ParamValueList_t * this_
    , OIIO_ParamValue_t * * return_)
{
    try {
        to_c(return_, (to_cpp(this_)) -> grow());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_find_pv(
    OIIO_ParamValueList_t * this_
    , OIIO_ParamValue_t * * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , _Bool casesensitive)
{
    try {
        to_c(return_, (to_cpp(this_)) -> find_pv(to_cpp_ref(&(name)), to_cpp_ref(&(type)), casesensitive));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_find_pv_const(
    OIIO_ParamValueList_t const * this_
    , OIIO_ParamValue_t const * * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , _Bool casesensitive)
{
    try {
        to_c(return_, (to_cpp(this_)) -> find_pv(to_cpp_ref(&(name)), to_cpp_ref(&(type)), casesensitive));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_get_int(
    OIIO_ParamValueList_t const * this_
    , int * return_
    , OIIO_string_view_t name
    , int defaultval
    , _Bool casesensitive
    , _Bool convert)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_int(to_cpp_ref(&(name)), defaultval, casesensitive, convert);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_get_float(
    OIIO_ParamValueList_t const * this_
    , float * return_
    , OIIO_string_view_t name
    , float defaultval
    , _Bool casesensitive
    , _Bool convert)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_float(to_cpp_ref(&(name)), defaultval, casesensitive, convert);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_get_string(
    OIIO_ParamValueList_t const * this_
    , OIIO_string_view_t * return_
    , OIIO_string_view_t name
    , OIIO_string_view_t defaultval
    , _Bool casesensitive
    , _Bool convert)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> get_string(to_cpp_ref(&(name)), to_cpp_ref(&(defaultval)), casesensitive, convert));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_get_ustring(
    OIIO_ParamValueList_t const * this_
    , OIIO_ustring_t * return_
    , OIIO_string_view_t name
    , OIIO_string_view_t defaultval
    , _Bool casesensitive
    , _Bool convert)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> get_ustring(to_cpp_ref(&(name)), to_cpp_ref(&(defaultval)), casesensitive, convert));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_remove(
    OIIO_ParamValueList_t * this_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , _Bool casesensitive)
{
    try {
        (to_cpp(this_)) -> remove(to_cpp_ref(&(name)), to_cpp_ref(&(type)), casesensitive);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_contains(
    OIIO_ParamValueList_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , _Bool casesensitive)
{
    try {
        *(return_) = (to_cpp(this_)) -> contains(to_cpp_ref(&(name)), to_cpp_ref(&(type)), casesensitive);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_add_or_replace(
    OIIO_ParamValueList_t * this_
    , OIIO_ParamValue_t const * pv
    , _Bool casesensitive)
{
    try {
        (to_cpp(this_)) -> add_or_replace(to_cpp_ref(pv), casesensitive);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_attribute(
    OIIO_ParamValueList_t * this_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , int nvalues
    , void const * value)
{
    try {
        (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), to_cpp_ref(&(type)), nvalues, value);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_attribute_parse_from_string(
    OIIO_ParamValueList_t * this_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , OIIO_string_view_t value)
{
    try {
        (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), to_cpp_ref(&(type)), to_cpp_ref(&(value)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_attribute_int(
    OIIO_ParamValueList_t * this_
    , OIIO_string_view_t name
    , int value)
{
    try {
        (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), value);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_attribute_uint(
    OIIO_ParamValueList_t * this_
    , OIIO_string_view_t name
    , unsigned int value)
{
    try {
        (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), value);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_attribute_float(
    OIIO_ParamValueList_t * this_
    , OIIO_string_view_t name
    , float value)
{
    try {
        (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), value);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_attribute_string(
    OIIO_ParamValueList_t * this_
    , OIIO_string_view_t name
    , OIIO_string_view_t value)
{
    try {
        (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), to_cpp_ref(&(value)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_getattributetype(
    OIIO_ParamValueList_t const * this_
    , OIIO_TypeDesc_t * return_
    , OIIO_string_view_t name
    , _Bool casesensitive)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> getattributetype(to_cpp_ref(&(name)), casesensitive));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_getattribute(
    OIIO_ParamValueList_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void * value
    , _Bool casesensitive)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute(to_cpp_ref(&(name)), to_cpp_ref(&(type)), value, casesensitive);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_getattribute_as_string(
    OIIO_ParamValueList_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , std_string_t * value
    , _Bool casesensitive)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute(to_cpp_ref(&(name)), to_cpp_ref(value), casesensitive);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_getattribute_indexed(
    OIIO_ParamValueList_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , int index
    , OIIO_TypeDesc_t type
    , void * value
    , _Bool casesensitive)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute_indexed(to_cpp_ref(&(name)), index, to_cpp_ref(&(type)), value, casesensitive);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_getattribute_indexed_as_string(
    OIIO_ParamValueList_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , int index
    , std_string_t * value
    , _Bool casesensitive)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute_indexed(to_cpp_ref(&(name)), index, to_cpp_ref(value), casesensitive);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_sort(
    OIIO_ParamValueList_t * this_
    , _Bool casesensitive)
{
    try {
        (to_cpp(this_)) -> sort(casesensitive);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_merge(
    OIIO_ParamValueList_t * this_
    , OIIO_ParamValueList_t const * other
    , _Bool override)
{
    try {
        (to_cpp(this_)) -> merge(to_cpp_ref(other), override);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_free(
    OIIO_ParamValueList_t * this_)
{
    try {
        (to_cpp(this_)) -> free();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_copy(
    OIIO_ParamValueList_t * * this_
    , OIIO_ParamValueList_t const * rhs)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::ParamValueList(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ParamValueList_dtor(
    OIIO_ParamValueList_t * this_)
{
    try {
        delete to_cpp(this_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

