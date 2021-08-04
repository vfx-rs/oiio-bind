#pragma once
#include <c-string_view.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/** BASETYPE is a simple enum describing the base data types that
correspond (mostly) to the C/C++ built-in types. */
enum OpenImageIO_v2_3_6__TypeDesc__BASETYPE_e {
    OIIO_TypeDesc_BASETYPE_UNKNOWN = 0,
    OIIO_TypeDesc_BASETYPE_NONE = 1,
    OIIO_TypeDesc_BASETYPE_UINT8 = 2,
    OIIO_TypeDesc_BASETYPE_UCHAR = 2,
    OIIO_TypeDesc_BASETYPE_CHAR = 3,
    OIIO_TypeDesc_BASETYPE_INT8 = 3,
    OIIO_TypeDesc_BASETYPE_USHORT = 4,
    OIIO_TypeDesc_BASETYPE_UINT16 = 4,
    OIIO_TypeDesc_BASETYPE_INT16 = 5,
    OIIO_TypeDesc_BASETYPE_SHORT = 5,
    OIIO_TypeDesc_BASETYPE_UINT = 6,
    OIIO_TypeDesc_BASETYPE_UINT32 = 6,
    OIIO_TypeDesc_BASETYPE_INT32 = 7,
    OIIO_TypeDesc_BASETYPE_INT = 7,
    OIIO_TypeDesc_BASETYPE_ULONGLONG = 8,
    OIIO_TypeDesc_BASETYPE_UINT64 = 8,
    OIIO_TypeDesc_BASETYPE_INT64 = 9,
    OIIO_TypeDesc_BASETYPE_LONGLONG = 9,
    OIIO_TypeDesc_BASETYPE_HALF = 10,
    OIIO_TypeDesc_BASETYPE_FLOAT = 11,
    OIIO_TypeDesc_BASETYPE_DOUBLE = 12,
    OIIO_TypeDesc_BASETYPE_STRING = 13,
    OIIO_TypeDesc_BASETYPE_PTR = 14,
    OIIO_TypeDesc_BASETYPE_LASTBASE = 15,
};
typedef unsigned int OIIO_TypeDesc_BASETYPE;
/** AGGREGATE describes whether our TypeDesc is a simple scalar of one
of the BASETYPE's, or one of several simple aggregates.

Note that aggregates and arrays are different. A `TypeDesc(FLOAT,3)`
is an array of three floats, a `TypeDesc(FLOAT,VEC3)` is a single
3-component vector comprised of floats, and `TypeDesc(FLOAT,3,VEC3)`
is an array of 3 vectors, each of which is comprised of 3 floats. */
enum OpenImageIO_v2_3_6__TypeDesc__AGGREGATE_e {
    OIIO_TypeDesc_AGGREGATE_SCALAR = 1,
    OIIO_TypeDesc_AGGREGATE_VEC2 = 2,
    OIIO_TypeDesc_AGGREGATE_VEC3 = 3,
    OIIO_TypeDesc_AGGREGATE_VEC4 = 4,
    OIIO_TypeDesc_AGGREGATE_MATRIX33 = 9,
    OIIO_TypeDesc_AGGREGATE_MATRIX44 = 16,
};
typedef unsigned int OIIO_TypeDesc_AGGREGATE;
/** VECSEMANTICS gives hints about what the data represent (for example,
if a spatial vector quantity should transform as a point, direction
vector, or surface normal). */
enum OpenImageIO_v2_3_6__TypeDesc__VECSEMANTICS_e {
    OIIO_TypeDesc_VECSEMANTICS_NOSEMANTICS = 0,
    OIIO_TypeDesc_VECSEMANTICS_NOXFORM = 0,
    OIIO_TypeDesc_VECSEMANTICS_COLOR = 1,
    OIIO_TypeDesc_VECSEMANTICS_POINT = 2,
    OIIO_TypeDesc_VECSEMANTICS_VECTOR = 3,
    OIIO_TypeDesc_VECSEMANTICS_NORMAL = 4,
    OIIO_TypeDesc_VECSEMANTICS_TIMECODE = 5,
    OIIO_TypeDesc_VECSEMANTICS_KEYCODE = 6,
    OIIO_TypeDesc_VECSEMANTICS_RATIONAL = 7,
    OIIO_TypeDesc_VECSEMANTICS_BOX = 8,
};
typedef unsigned int OIIO_TypeDesc_VECSEMANTICS;

/** //////////////////////////////////////////////////////////////////////////
 A TypeDesc describes simple data types.

 It frequently comes up (in my experience, with renderers and image
 handling programs) that you want a way to describe data that is passed
 through APIs through blind pointers.  These are some simple classes
 that provide a simple type descriptor system.  This is not meant to
 be comprehensive -- for example, there is no provision for structs,
 unions, pointers, const, or 'nested' type definitions.  Just simple
 integer and floating point, *common* aggregates such as 3-points,
 and reasonably-lengthed arrays thereof.

////////////////////////////////////////////////////////////////////////// */
typedef struct OpenImageIO_v2_3_6__TypeDesc_t_s {
    unsigned char basetype;
    unsigned char aggregate;
    unsigned char vecsemantics;
    unsigned char reserved;
    int arraylen;
} __attribute__((aligned(4))) OpenImageIO_v2_3_6__TypeDesc_t;
typedef OpenImageIO_v2_3_6__TypeDesc_t OIIO_TypeDesc_t;


/** Construct from a BASETYPE and optional aggregateness, semantics,
and arrayness. */
unsigned int OpenImageIO_v2_3_6__TypeDesc_ctor(
    OIIO_TypeDesc_t * this_
    , OIIO_TypeDesc_BASETYPE btype
    , OIIO_TypeDesc_AGGREGATE agg
    , OIIO_TypeDesc_VECSEMANTICS semantics
    , int arraylen);
#define OIIO_TypeDesc_ctor OpenImageIO_v2_3_6__TypeDesc_ctor


/** Construct an array of a non-aggregate BASETYPE. */
unsigned int OpenImageIO_v2_3_6__TypeDesc_from_basetype(
    OIIO_TypeDesc_t * this_
    , OIIO_TypeDesc_BASETYPE btype
    , int arraylen);
#define OIIO_TypeDesc_from_basetype OpenImageIO_v2_3_6__TypeDesc_from_basetype


/** Construct from a string (e.g., "float[3]").  If no valid
type could be assembled, set base to UNKNOWN.

Examples:
```
     TypeDesc("int") == TypeDesc(TypeDesc::INT)            // C++ int32_t
     TypeDesc("float") == TypeDesc(TypeDesc::FLOAT)        // C++ float
     TypeDesc("uint16") == TypeDesc(TypeDesc::UINT16)      // C++ uint16_t
     TypeDesc("float[4]") == TypeDesc(TypeDesc::FLOAT, 4)  // array
     TypeDesc("point") == TypeDesc(TypeDesc::FLOAT,
                                   TypeDesc::VEC3, TypeDesc::POINT)
``` */
unsigned int OpenImageIO_v2_3_6__TypeDesc_from_string(
    OIIO_TypeDesc_t * this_
    , OIIO_string_view_t typestring);
#define OIIO_TypeDesc_from_string OpenImageIO_v2_3_6__TypeDesc_from_string


/** Copy constructor. */
unsigned int OpenImageIO_v2_3_6__TypeDesc_copy(
    OIIO_TypeDesc_t * this_
    , OIIO_TypeDesc_t const * t);
#define OIIO_TypeDesc_copy OpenImageIO_v2_3_6__TypeDesc_copy


/** Return the name, for printing and whatnot.  For example,
"float", "int[5]", "normal" */
unsigned int OpenImageIO_v2_3_6__TypeDesc_c_str(
    OIIO_TypeDesc_t const * this_
    , char const * * return_);
#define OIIO_TypeDesc_c_str OpenImageIO_v2_3_6__TypeDesc_c_str


/** Return the number of elements: 1 if not an array, or the array
length. Invalid to call this for arrays of undetermined size. */
unsigned int OpenImageIO_v2_3_6__TypeDesc_numelements(
    OIIO_TypeDesc_t const * this_
    , unsigned long * return_);
#define OIIO_TypeDesc_numelements OpenImageIO_v2_3_6__TypeDesc_numelements


/** Return the number of basetype values: the aggregate count multiplied
by the array length (or 1 if not an array). Invalid to call this
for arrays of undetermined size. */
unsigned int OpenImageIO_v2_3_6__TypeDesc_basevalues(
    OIIO_TypeDesc_t const * this_
    , unsigned long * return_);
#define OIIO_TypeDesc_basevalues OpenImageIO_v2_3_6__TypeDesc_basevalues


/** Does this TypeDesc describe an array? */
unsigned int OpenImageIO_v2_3_6__TypeDesc_is_array(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_);
#define OIIO_TypeDesc_is_array OpenImageIO_v2_3_6__TypeDesc_is_array


/** Does this TypeDesc describe an array, but whose length is not
specified? */
unsigned int OpenImageIO_v2_3_6__TypeDesc_is_unsized_array(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_);
#define OIIO_TypeDesc_is_unsized_array OpenImageIO_v2_3_6__TypeDesc_is_unsized_array


/** Does this TypeDesc describe an array, whose length is specified? */
unsigned int OpenImageIO_v2_3_6__TypeDesc_is_sized_array(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_);
#define OIIO_TypeDesc_is_sized_array OpenImageIO_v2_3_6__TypeDesc_is_sized_array


/** Return the size, in bytes, of this type. */
unsigned int OpenImageIO_v2_3_6__TypeDesc_size(
    OIIO_TypeDesc_t const * this_
    , unsigned long * return_);
#define OIIO_TypeDesc_size OpenImageIO_v2_3_6__TypeDesc_size


/** Return the type of one element, i.e., strip out the array-ness. */
unsigned int OpenImageIO_v2_3_6__TypeDesc_elementtype(
    OIIO_TypeDesc_t const * this_
    , OIIO_TypeDesc_t * return_);
#define OIIO_TypeDesc_elementtype OpenImageIO_v2_3_6__TypeDesc_elementtype


/** Return the size, in bytes, of one element of this type (that is,
ignoring whether it's an array). */
unsigned int OpenImageIO_v2_3_6__TypeDesc_elementsize(
    OIIO_TypeDesc_t const * this_
    , unsigned long * return_);
#define OIIO_TypeDesc_elementsize OpenImageIO_v2_3_6__TypeDesc_elementsize


/** Return just the underlying C scalar type, i.e., strip out the
array-ness and the aggregateness. */
unsigned int OpenImageIO_v2_3_6__TypeDesc_scalartype(
    OIIO_TypeDesc_t const * this_
    , OIIO_TypeDesc_t * return_);
#define OIIO_TypeDesc_scalartype OpenImageIO_v2_3_6__TypeDesc_scalartype


/** Return the base type size, i.e., stripped of both array-ness
and aggregateness. */
unsigned int OpenImageIO_v2_3_6__TypeDesc_basesize(
    OIIO_TypeDesc_t const * this_
    , unsigned long * return_);
#define OIIO_TypeDesc_basesize OpenImageIO_v2_3_6__TypeDesc_basesize


/** True if it's a floating-point type (versus a fundamentally
integral type or something else like a string). */
unsigned int OpenImageIO_v2_3_6__TypeDesc_is_floating_point(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_);
#define OIIO_TypeDesc_is_floating_point OpenImageIO_v2_3_6__TypeDesc_is_floating_point


/** True if it's a signed type that allows for negative values. */
unsigned int OpenImageIO_v2_3_6__TypeDesc_is_signed(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_);
#define OIIO_TypeDesc_is_signed OpenImageIO_v2_3_6__TypeDesc_is_signed


/** Shortcut: is it UNKNOWN? */
unsigned int OpenImageIO_v2_3_6__TypeDesc_is_unknown(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_);
#define OIIO_TypeDesc_is_unknown OpenImageIO_v2_3_6__TypeDesc_is_unknown


/** Set *this to the type described in the string.  Return the
length of the part of the string that describes the type.  If
no valid type could be assembled, return 0 and do not modify
*this. */
unsigned int OpenImageIO_v2_3_6__TypeDesc_fromstring(
    OIIO_TypeDesc_t * this_
    , unsigned long * return_
    , OIIO_string_view_t typestring);
#define OIIO_TypeDesc_fromstring OpenImageIO_v2_3_6__TypeDesc_fromstring


/** Compare two TypeDesc values for equality. */
unsigned int OpenImageIO_v2_3_6__TypeDesc__eq(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_t const * t);
#define OIIO_TypeDesc__eq OpenImageIO_v2_3_6__TypeDesc__eq


/** Compare two TypeDesc values for inequality. */
unsigned int OpenImageIO_v2_3_6__TypeDesc__ne(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_t const * t);
#define OIIO_TypeDesc__ne OpenImageIO_v2_3_6__TypeDesc__ne


/** Member version of equivalent */
unsigned int OpenImageIO_v2_3_6__TypeDesc_equivalent(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_t const * b);
#define OIIO_TypeDesc_equivalent OpenImageIO_v2_3_6__TypeDesc_equivalent


/** Is this a 2-vector aggregate (of the given type, float by default)? */
unsigned int OpenImageIO_v2_3_6__TypeDesc_is_vec2(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_BASETYPE b);
#define OIIO_TypeDesc_is_vec2 OpenImageIO_v2_3_6__TypeDesc_is_vec2


/** Is this a 3-vector aggregate (of the given type, float by default)? */
unsigned int OpenImageIO_v2_3_6__TypeDesc_is_vec3(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_BASETYPE b);
#define OIIO_TypeDesc_is_vec3 OpenImageIO_v2_3_6__TypeDesc_is_vec3


/** Is this a 4-vector aggregate (of the given type, float by default)? */
unsigned int OpenImageIO_v2_3_6__TypeDesc_is_vec4(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_BASETYPE b);
#define OIIO_TypeDesc_is_vec4 OpenImageIO_v2_3_6__TypeDesc_is_vec4


/** Is this an array of aggregates that represents a 2D bounding box? */
unsigned int OpenImageIO_v2_3_6__TypeDesc_is_box2(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_BASETYPE b);
#define OIIO_TypeDesc_is_box2 OpenImageIO_v2_3_6__TypeDesc_is_box2


/** Is this an array of aggregates that represents a 3D bounding box? */
unsigned int OpenImageIO_v2_3_6__TypeDesc_is_box3(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_BASETYPE b);
#define OIIO_TypeDesc_is_box3 OpenImageIO_v2_3_6__TypeDesc_is_box3


/** Demote the type to a non-array */
unsigned int OpenImageIO_v2_3_6__TypeDesc_unarray(
    OIIO_TypeDesc_t * this_);
#define OIIO_TypeDesc_unarray OpenImageIO_v2_3_6__TypeDesc_unarray


/** Test for lexicographic 'less', comes in handy for lots of STL
containers and algorithms. */
unsigned int OpenImageIO_v2_3_6__TypeDesc_operator_(
    OIIO_TypeDesc_t const * this_
    , _Bool * return_
    , OIIO_TypeDesc_t const * x);
#define OIIO_TypeDesc_operator_ OpenImageIO_v2_3_6__TypeDesc_operator_


/** Given base data types of a and b, return a basetype that is a best
guess for one that can handle both without any loss of range or
precision. */
unsigned int OpenImageIO_v2_3_6__TypeDesc_basetype_merge(
    OIIO_TypeDesc_BASETYPE * return_
    , OIIO_TypeDesc_t a
    , OIIO_TypeDesc_t b);
#define OIIO_TypeDesc_basetype_merge OpenImageIO_v2_3_6__TypeDesc_basetype_merge


unsigned int OpenImageIO_v2_3_6__TypeDesc_dtor(
    OIIO_TypeDesc_t * this_);
#define OIIO_TypeDesc_dtor OpenImageIO_v2_3_6__TypeDesc_dtor


#ifdef __cplusplus
}
#endif
