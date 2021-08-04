#pragma once
#include <c-std_string.h>
#include <c-string_view.h>
#include <c-typedesc.h>
#include <c-ustring.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct std__string_t_s std__string_t;
typedef std__string_t std_string_t;
typedef struct OpenImageIO_v2_3_6__ustring_t_s OpenImageIO_v2_3_6__ustring_t;
typedef OpenImageIO_v2_3_6__ustring_t OIIO_ustring_t;

/** Interpolation types */
enum OpenImageIO_v2_3_6__ParamValue__Interp_e {
    OIIO_ParamValue_Interp_INTERP_CONSTANT = 0,
    OIIO_ParamValue_Interp_INTERP_PERPIECE = 1,
    OIIO_ParamValue_Interp_INTERP_LINEAR = 2,
    OIIO_ParamValue_Interp_INTERP_VERTEX = 3,
};
typedef unsigned int OIIO_ParamValue_Interp;

/** ParamValue holds a parameter and a pointer to its value(s)

Nomenclature: if you have an array of 4 colors for each of 15 points...
 - There are 15 VALUES
 - Each value has an array of 4 ELEMENTS, each of which is a color
 - A color has 3 COMPONENTS (R, G, B) */
typedef struct OpenImageIO_v2_3_6__ParamValue_t_s {
    char data[40];
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__ParamValue_t;
typedef OpenImageIO_v2_3_6__ParamValue_t OIIO_ParamValue_t;

/** A list of ParamValue entries, that can be iterated over or searched.
It's really just a std::vector<ParamValue>, but with a few more handy
methods. */
typedef struct OpenImageIO_v2_3_6__ParamValueList_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__ParamValueList_t;
typedef OpenImageIO_v2_3_6__ParamValueList_t OIIO_ParamValueList_t;


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__ParamValue_sizeof();
#define OIIO_ParamValue_sizeof OpenImageIO_v2_3_6__ParamValue_sizeof


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__ParamValue_alignof();
#define OIIO_ParamValue_alignof OpenImageIO_v2_3_6__ParamValue_alignof


unsigned int OpenImageIO_v2_3_6__ParamValue_default(
    OIIO_ParamValue_t * this_);
#define OIIO_ParamValue_default OpenImageIO_v2_3_6__ParamValue_default


unsigned int OpenImageIO_v2_3_6__ParamValue_ctor_ustring(
    OIIO_ParamValue_t * this_
    , OIIO_ustring_t const * _name
    , OIIO_TypeDesc_t _type
    , int _nvalues
    , void const * _value
    , _Bool _copy);
#define OIIO_ParamValue_ctor_ustring OpenImageIO_v2_3_6__ParamValue_ctor_ustring


unsigned int OpenImageIO_v2_3_6__ParamValue_with_interp_ustring(
    OIIO_ParamValue_t * this_
    , OIIO_ustring_t const * _name
    , OIIO_TypeDesc_t _type
    , int _nvalues
    , OIIO_ParamValue_Interp _interp
    , void const * _value
    , _Bool _copy);
#define OIIO_ParamValue_with_interp_ustring OpenImageIO_v2_3_6__ParamValue_with_interp_ustring


unsigned int OpenImageIO_v2_3_6__ParamValue_ctor(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , OIIO_TypeDesc_t _type
    , int _nvalues
    , void const * _value
    , _Bool _copy);
#define OIIO_ParamValue_ctor OpenImageIO_v2_3_6__ParamValue_ctor


unsigned int OpenImageIO_v2_3_6__ParamValue_with_interp(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , OIIO_TypeDesc_t _type
    , int _nvalues
    , OIIO_ParamValue_Interp _interp
    , void const * _value
    , _Bool _copy);
#define OIIO_ParamValue_with_interp OpenImageIO_v2_3_6__ParamValue_with_interp


unsigned int OpenImageIO_v2_3_6__ParamValue_from_int(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , int value);
#define OIIO_ParamValue_from_int OpenImageIO_v2_3_6__ParamValue_from_int


unsigned int OpenImageIO_v2_3_6__ParamValue_from_float(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , float value);
#define OIIO_ParamValue_from_float OpenImageIO_v2_3_6__ParamValue_from_float


unsigned int OpenImageIO_v2_3_6__ParamValue_from_ustring(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , OIIO_ustring_t value);
#define OIIO_ParamValue_from_ustring OpenImageIO_v2_3_6__ParamValue_from_ustring


unsigned int OpenImageIO_v2_3_6__ParamValue_from_string(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , OIIO_string_view_t value);
#define OIIO_ParamValue_from_string OpenImageIO_v2_3_6__ParamValue_from_string


unsigned int OpenImageIO_v2_3_6__ParamValue_parse(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , OIIO_TypeDesc_t type
    , OIIO_string_view_t value);
#define OIIO_ParamValue_parse OpenImageIO_v2_3_6__ParamValue_parse


unsigned int OpenImageIO_v2_3_6__ParamValue_copy(
    OIIO_ParamValue_t * this_
    , OIIO_ParamValue_t const * p);
#define OIIO_ParamValue_copy OpenImageIO_v2_3_6__ParamValue_copy


unsigned int OpenImageIO_v2_3_6__ParamValue_dtor(
    OIIO_ParamValue_t * this_);
#define OIIO_ParamValue_dtor OpenImageIO_v2_3_6__ParamValue_dtor


unsigned int OpenImageIO_v2_3_6__ParamValue_init_with_interp_ustring(
    OIIO_ParamValue_t * this_
    , OIIO_ustring_t _name
    , OIIO_TypeDesc_t _type
    , int _nvalues
    , OIIO_ParamValue_Interp _interp
    , void const * _value
    , _Bool _copy);
#define OIIO_ParamValue_init_with_interp_ustring OpenImageIO_v2_3_6__ParamValue_init_with_interp_ustring


unsigned int OpenImageIO_v2_3_6__ParamValue_init_ustring(
    OIIO_ParamValue_t * this_
    , OIIO_ustring_t _name
    , OIIO_TypeDesc_t _type
    , int _nvalues
    , void const * _value
    , _Bool _copy);
#define OIIO_ParamValue_init_ustring OpenImageIO_v2_3_6__ParamValue_init_ustring


unsigned int OpenImageIO_v2_3_6__ParamValue_init(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , OIIO_TypeDesc_t _type
    , int _nvalues
    , void const * _value
    , _Bool _copy);
#define OIIO_ParamValue_init OpenImageIO_v2_3_6__ParamValue_init


unsigned int OpenImageIO_v2_3_6__ParamValue_init_with_interp(
    OIIO_ParamValue_t * this_
    , OIIO_string_view_t _name
    , OIIO_TypeDesc_t _type
    , int _nvalues
    , OIIO_ParamValue_Interp _interp
    , void const * _value
    , _Bool _copy);
#define OIIO_ParamValue_init_with_interp OpenImageIO_v2_3_6__ParamValue_init_with_interp


unsigned int OpenImageIO_v2_3_6__ParamValue__assign(
    OIIO_ParamValue_t * this_
    , OIIO_ParamValue_t const * * return_
    , OIIO_ParamValue_t const * p);
#define OIIO_ParamValue__assign OpenImageIO_v2_3_6__ParamValue__assign


unsigned int OpenImageIO_v2_3_6__ParamValue_name(
    OIIO_ParamValue_t const * this_
    , OIIO_ustring_t const * * return_);
#define OIIO_ParamValue_name OpenImageIO_v2_3_6__ParamValue_name


unsigned int OpenImageIO_v2_3_6__ParamValue_uname(
    OIIO_ParamValue_t const * this_
    , OIIO_ustring_t const * * return_);
#define OIIO_ParamValue_uname OpenImageIO_v2_3_6__ParamValue_uname


unsigned int OpenImageIO_v2_3_6__ParamValue_type(
    OIIO_ParamValue_t const * this_
    , OIIO_TypeDesc_t * return_);
#define OIIO_ParamValue_type OpenImageIO_v2_3_6__ParamValue_type


unsigned int OpenImageIO_v2_3_6__ParamValue_nvalues(
    OIIO_ParamValue_t const * this_
    , int * return_);
#define OIIO_ParamValue_nvalues OpenImageIO_v2_3_6__ParamValue_nvalues


unsigned int OpenImageIO_v2_3_6__ParamValue_data(
    OIIO_ParamValue_t const * this_
    , void const * * return_);
#define OIIO_ParamValue_data OpenImageIO_v2_3_6__ParamValue_data


unsigned int OpenImageIO_v2_3_6__ParamValue_datasize(
    OIIO_ParamValue_t const * this_
    , int * return_);
#define OIIO_ParamValue_datasize OpenImageIO_v2_3_6__ParamValue_datasize


unsigned int OpenImageIO_v2_3_6__ParamValue_interp_const(
    OIIO_ParamValue_t const * this_
    , OIIO_ParamValue_Interp * return_);
#define OIIO_ParamValue_interp_const OpenImageIO_v2_3_6__ParamValue_interp_const


unsigned int OpenImageIO_v2_3_6__ParamValue_interp(
    OIIO_ParamValue_t * this_
    , OIIO_ParamValue_Interp i);
#define OIIO_ParamValue_interp OpenImageIO_v2_3_6__ParamValue_interp


unsigned int OpenImageIO_v2_3_6__ParamValue_is_nonlocal(
    OIIO_ParamValue_t const * this_
    , _Bool * return_);
#define OIIO_ParamValue_is_nonlocal OpenImageIO_v2_3_6__ParamValue_is_nonlocal


/** Retrive an integer, with converstions from a wide variety of type
cases, including unsigned, short, byte. Not float. It will retrive
from a string, but only if the string is entirely a valid int
format. Unconvertible types return the default value. */
unsigned int OpenImageIO_v2_3_6__ParamValue_get_int(
    OIIO_ParamValue_t const * this_
    , int * return_
    , int defaultval);
#define OIIO_ParamValue_get_int OpenImageIO_v2_3_6__ParamValue_get_int


unsigned int OpenImageIO_v2_3_6__ParamValue_get_int_indexed(
    OIIO_ParamValue_t const * this_
    , int * return_
    , int index
    , int defaultval);
#define OIIO_ParamValue_get_int_indexed OpenImageIO_v2_3_6__ParamValue_get_int_indexed


/** Retrive a float, with converstions from a wide variety of type
cases, including integers. It will retrive from a string, but only
if the string is entirely a valid float format. Unconvertible types
return the default value. */
unsigned int OpenImageIO_v2_3_6__ParamValue_get_float(
    OIIO_ParamValue_t const * this_
    , float * return_
    , float defaultval);
#define OIIO_ParamValue_get_float OpenImageIO_v2_3_6__ParamValue_get_float


unsigned int OpenImageIO_v2_3_6__ParamValue_get_float_indexed(
    OIIO_ParamValue_t const * this_
    , float * return_
    , int index
    , float defaultval);
#define OIIO_ParamValue_get_float_indexed OpenImageIO_v2_3_6__ParamValue_get_float_indexed


/** Convert any type to a string value. An optional maximum number of
elements is also passed. In the case of a single string, just the
string directly is returned. But for an array of strings, the array
is returned as one string that's a comma-separated list of double-
quoted, escaped strings. */
unsigned int OpenImageIO_v2_3_6__ParamValue_get_string(
    OIIO_ParamValue_t const * this_
    , std_string_t * * return_
    , int maxsize);
#define OIIO_ParamValue_get_string OpenImageIO_v2_3_6__ParamValue_get_string


unsigned int OpenImageIO_v2_3_6__ParamValue_get_string_indexed(
    OIIO_ParamValue_t const * this_
    , std_string_t * * return_
    , int index);
#define OIIO_ParamValue_get_string_indexed OpenImageIO_v2_3_6__ParamValue_get_string_indexed


/** Convert any type to a ustring value. An optional maximum number of
elements is also passed. Same behavior as get_string, but returning
a ustring. */
unsigned int OpenImageIO_v2_3_6__ParamValue_get_ustring(
    OIIO_ParamValue_t const * this_
    , OIIO_ustring_t * return_
    , int maxsize);
#define OIIO_ParamValue_get_ustring OpenImageIO_v2_3_6__ParamValue_get_ustring


unsigned int OpenImageIO_v2_3_6__ParamValue_get_ustring_indexed(
    OIIO_ParamValue_t const * this_
    , OIIO_ustring_t * return_
    , int index);
#define OIIO_ParamValue_get_ustring_indexed OpenImageIO_v2_3_6__ParamValue_get_ustring_indexed


unsigned int OpenImageIO_v2_3_6__ParamValueList_data(
    OIIO_ParamValueList_t * this_
    , OIIO_ParamValue_t * * return_);
#define OIIO_ParamValueList_data OpenImageIO_v2_3_6__ParamValueList_data


unsigned int OpenImageIO_v2_3_6__ParamValueList_data_const(
    OIIO_ParamValueList_t const * this_
    , OIIO_ParamValue_t const * * return_);
#define OIIO_ParamValueList_data_const OpenImageIO_v2_3_6__ParamValueList_data_const


unsigned int OpenImageIO_v2_3_6__ParamValueList_push_back(
    OIIO_ParamValueList_t * this_
    , OIIO_ParamValue_t const * __x);
#define OIIO_ParamValueList_push_back OpenImageIO_v2_3_6__ParamValueList_push_back


unsigned int OpenImageIO_v2_3_6__ParamValueList_pop_back(
    OIIO_ParamValueList_t * this_);
#define OIIO_ParamValueList_pop_back OpenImageIO_v2_3_6__ParamValueList_pop_back


unsigned int OpenImageIO_v2_3_6__ParamValueList_clear(
    OIIO_ParamValueList_t * this_);
#define OIIO_ParamValueList_clear OpenImageIO_v2_3_6__ParamValueList_clear


unsigned int OpenImageIO_v2_3_6__ParamValueList_ctor(
    OIIO_ParamValueList_t * * this_);
#define OIIO_ParamValueList_ctor OpenImageIO_v2_3_6__ParamValueList_ctor


/** Add space for one more ParamValue to the list, and return a
reference to its slot. */
unsigned int OpenImageIO_v2_3_6__ParamValueList_grow(
    OIIO_ParamValueList_t * this_
    , OIIO_ParamValue_t * * return_);
#define OIIO_ParamValueList_grow OpenImageIO_v2_3_6__ParamValueList_grow


/** Search for the first entry with matching name, etc., and return
a pointer to it, or nullptr if it is not found. */
unsigned int OpenImageIO_v2_3_6__ParamValueList_find_pv(
    OIIO_ParamValueList_t * this_
    , OIIO_ParamValue_t * * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , _Bool casesensitive);
#define OIIO_ParamValueList_find_pv OpenImageIO_v2_3_6__ParamValueList_find_pv


unsigned int OpenImageIO_v2_3_6__ParamValueList_find_pv_const(
    OIIO_ParamValueList_t const * this_
    , OIIO_ParamValue_t const * * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , _Bool casesensitive);
#define OIIO_ParamValueList_find_pv_const OpenImageIO_v2_3_6__ParamValueList_find_pv_const


/** Case insensitive search for an integer, with default if not found.
Automatically will return an int even if the data is really
unsigned, short, or byte, but not float. It will retrive from a
string, but only if the string is entirely a valid int format. */
unsigned int OpenImageIO_v2_3_6__ParamValueList_get_int(
    OIIO_ParamValueList_t const * this_
    , int * return_
    , OIIO_string_view_t name
    , int defaultval
    , _Bool casesensitive
    , _Bool convert);
#define OIIO_ParamValueList_get_int OpenImageIO_v2_3_6__ParamValueList_get_int


/** Case insensitive search for a float, with default if not found.
Automatically will return a float even if the data is really double
or half. It will retrive from a string, but only if the string is
entirely a valid float format. */
unsigned int OpenImageIO_v2_3_6__ParamValueList_get_float(
    OIIO_ParamValueList_t const * this_
    , float * return_
    , OIIO_string_view_t name
    , float defaultval
    , _Bool casesensitive
    , _Bool convert);
#define OIIO_ParamValueList_get_float OpenImageIO_v2_3_6__ParamValueList_get_float


/** Simple way to get a string attribute, with default provided.
If the value is another type, it will be turned into a string. */
unsigned int OpenImageIO_v2_3_6__ParamValueList_get_string(
    OIIO_ParamValueList_t const * this_
    , OIIO_string_view_t * return_
    , OIIO_string_view_t name
    , OIIO_string_view_t defaultval
    , _Bool casesensitive
    , _Bool convert);
#define OIIO_ParamValueList_get_string OpenImageIO_v2_3_6__ParamValueList_get_string


unsigned int OpenImageIO_v2_3_6__ParamValueList_get_ustring(
    OIIO_ParamValueList_t const * this_
    , OIIO_ustring_t * return_
    , OIIO_string_view_t name
    , OIIO_string_view_t defaultval
    , _Bool casesensitive
    , _Bool convert);
#define OIIO_ParamValueList_get_ustring OpenImageIO_v2_3_6__ParamValueList_get_ustring


/** Remove the named parameter, if it is in the list. */
unsigned int OpenImageIO_v2_3_6__ParamValueList_remove(
    OIIO_ParamValueList_t * this_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , _Bool casesensitive);
#define OIIO_ParamValueList_remove OpenImageIO_v2_3_6__ParamValueList_remove


/** Does the list contain the named attribute? */
unsigned int OpenImageIO_v2_3_6__ParamValueList_contains(
    OIIO_ParamValueList_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , _Bool casesensitive);
#define OIIO_ParamValueList_contains OpenImageIO_v2_3_6__ParamValueList_contains


unsigned int OpenImageIO_v2_3_6__ParamValueList_add_or_replace(
    OIIO_ParamValueList_t * this_
    , OIIO_ParamValue_t const * pv
    , _Bool casesensitive);
#define OIIO_ParamValueList_add_or_replace OpenImageIO_v2_3_6__ParamValueList_add_or_replace


/** Add (or replace) a value in the list. */
unsigned int OpenImageIO_v2_3_6__ParamValueList_attribute(
    OIIO_ParamValueList_t * this_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , int nvalues
    , void const * value);
#define OIIO_ParamValueList_attribute OpenImageIO_v2_3_6__ParamValueList_attribute


/** Set directly from string -- parse if type is non-string. */
unsigned int OpenImageIO_v2_3_6__ParamValueList_attribute_parse_from_string(
    OIIO_ParamValueList_t * this_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , OIIO_string_view_t value);
#define OIIO_ParamValueList_attribute_parse_from_string OpenImageIO_v2_3_6__ParamValueList_attribute_parse_from_string


unsigned int OpenImageIO_v2_3_6__ParamValueList_attribute_int(
    OIIO_ParamValueList_t * this_
    , OIIO_string_view_t name
    , int value);
#define OIIO_ParamValueList_attribute_int OpenImageIO_v2_3_6__ParamValueList_attribute_int


unsigned int OpenImageIO_v2_3_6__ParamValueList_attribute_uint(
    OIIO_ParamValueList_t * this_
    , OIIO_string_view_t name
    , unsigned int value);
#define OIIO_ParamValueList_attribute_uint OpenImageIO_v2_3_6__ParamValueList_attribute_uint


unsigned int OpenImageIO_v2_3_6__ParamValueList_attribute_float(
    OIIO_ParamValueList_t * this_
    , OIIO_string_view_t name
    , float value);
#define OIIO_ParamValueList_attribute_float OpenImageIO_v2_3_6__ParamValueList_attribute_float


unsigned int OpenImageIO_v2_3_6__ParamValueList_attribute_string(
    OIIO_ParamValueList_t * this_
    , OIIO_string_view_t name
    , OIIO_string_view_t value);
#define OIIO_ParamValueList_attribute_string OpenImageIO_v2_3_6__ParamValueList_attribute_string


/** Search list for named item, return its type or TypeUnknown if not
found. */
unsigned int OpenImageIO_v2_3_6__ParamValueList_getattributetype(
    OIIO_ParamValueList_t const * this_
    , OIIO_TypeDesc_t * return_
    , OIIO_string_view_t name
    , _Bool casesensitive);
#define OIIO_ParamValueList_getattributetype OpenImageIO_v2_3_6__ParamValueList_getattributetype


/** Retrieve from list: If found its data type is reasonably convertible
to `type`, copy/convert the value into val[...] and return true.
Otherwise, return false and don't modify what val points to. */
unsigned int OpenImageIO_v2_3_6__ParamValueList_getattribute(
    OIIO_ParamValueList_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void * value
    , _Bool casesensitive);
#define OIIO_ParamValueList_getattribute OpenImageIO_v2_3_6__ParamValueList_getattribute


/** Shortcut for retrieving a single string via getattribute. */
unsigned int OpenImageIO_v2_3_6__ParamValueList_getattribute_as_string(
    OIIO_ParamValueList_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , std_string_t * value
    , _Bool casesensitive);
#define OIIO_ParamValueList_getattribute_as_string OpenImageIO_v2_3_6__ParamValueList_getattribute_as_string


/** Retrieve from list: If found its data type is reasonably convertible
to `type`, copy/convert the value into val[...] and return true.
Otherwise, return false and don't modify what val points to. */
unsigned int OpenImageIO_v2_3_6__ParamValueList_getattribute_indexed(
    OIIO_ParamValueList_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , int index
    , OIIO_TypeDesc_t type
    , void * value
    , _Bool casesensitive);
#define OIIO_ParamValueList_getattribute_indexed OpenImageIO_v2_3_6__ParamValueList_getattribute_indexed


/** Shortcut for retrieving a single string via getattribute. */
unsigned int OpenImageIO_v2_3_6__ParamValueList_getattribute_indexed_as_string(
    OIIO_ParamValueList_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , int index
    , std_string_t * value
    , _Bool casesensitive);
#define OIIO_ParamValueList_getattribute_indexed_as_string OpenImageIO_v2_3_6__ParamValueList_getattribute_indexed_as_string


/** Sort alphabetically, optionally case-insensitively, locale-
independently, and with all the "un-namespaced" items appearing
first, followed by items with "prefixed namespaces" (e.g. "z" comes
before "foo:a"). */
unsigned int OpenImageIO_v2_3_6__ParamValueList_sort(
    OIIO_ParamValueList_t * this_
    , _Bool casesensitive);
#define OIIO_ParamValueList_sort OpenImageIO_v2_3_6__ParamValueList_sort


/** Merge items from PVL `other` into `*this`. Note how this differs
from `operator=` : assignment completely replaces the list with
the contents of another. But merge() adds the other items without
erasing any items already in this list.

@param other
    The ParamValueList whose entries will be merged into this one.
@param override
    If true, `other` attributes will replace any identically-named
    attributes already in this list. If false, only attributes whose
    names are not already in this list will be appended. */
unsigned int OpenImageIO_v2_3_6__ParamValueList_merge(
    OIIO_ParamValueList_t * this_
    , OIIO_ParamValueList_t const * other
    , _Bool override);
#define OIIO_ParamValueList_merge OpenImageIO_v2_3_6__ParamValueList_merge


/** Even more radical than clear, free ALL memory associated with the
list itself. */
unsigned int OpenImageIO_v2_3_6__ParamValueList_free(
    OIIO_ParamValueList_t * this_);
#define OIIO_ParamValueList_free OpenImageIO_v2_3_6__ParamValueList_free


unsigned int OpenImageIO_v2_3_6__ParamValueList_copy(
    OIIO_ParamValueList_t * * this_
    , OIIO_ParamValueList_t const * rhs);
#define OIIO_ParamValueList_copy OpenImageIO_v2_3_6__ParamValueList_copy


unsigned int OpenImageIO_v2_3_6__ParamValueList_dtor(
    OIIO_ParamValueList_t * this_);
#define OIIO_ParamValueList_dtor OpenImageIO_v2_3_6__ParamValueList_dtor


#ifdef __cplusplus
}
#endif
