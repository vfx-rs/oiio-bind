#pragma once
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct std__string_t_s std__string_t;
typedef std__string_t std_string_t;
typedef struct OpenImageIO_v2_3_6__TypeDesc_t_s OpenImageIO_v2_3_6__TypeDesc_t;
typedef OpenImageIO_v2_3_6__TypeDesc_t OIIO_TypeDesc_t;

typedef struct OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__t_s {
    char data[16];
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__t;
typedef OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__t OIIO_cspan_TypeDesc_t;

typedef struct OpenImageIO_v2_3_6__span_constfloat__1__t_s {
    char data[16];
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__span_constfloat__1__t;
typedef OpenImageIO_v2_3_6__span_constfloat__1__t OIIO_cspan_float_t;

typedef struct OpenImageIO_v2_3_6__span_float__1__t_s {
    char data[16];
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__span_float__1__t;
typedef OpenImageIO_v2_3_6__span_float__1__t OIIO_span_float_t;

typedef struct OpenImageIO_v2_3_6__span_constunsignedint__1__t_s {
    char data[16];
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__span_constunsignedint__1__t;
typedef OpenImageIO_v2_3_6__span_constunsignedint__1__t OIIO_cspan_uint_t;

typedef struct OpenImageIO_v2_3_6__span_constint__1__t_s {
    char data[16];
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__span_constint__1__t;
typedef OpenImageIO_v2_3_6__span_constint__1__t OIIO_cspan_int_t;

typedef struct OpenImageIO_v2_3_6__span_constchar__1__t_s {
    char data[16];
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__span_constchar__1__t;
typedef OpenImageIO_v2_3_6__span_constchar__1__t OIIO_cspan_char_t;

typedef struct OpenImageIO_v2_3_6__span_constunsignedchar__1__t_s {
    char data[16];
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__span_constunsignedchar__1__t;
typedef OpenImageIO_v2_3_6__span_constunsignedchar__1__t OIIO_cspan_uchar_t;

typedef struct OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__t_s {
    char data[16];
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__t;
typedef OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__t OIIO_cspan_string_t;


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__sizeof();
#define OIIO_cspan_TypeDesc_sizeof OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__sizeof


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__alignof();
#define OIIO_cspan_TypeDesc_alignof OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__alignof


unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__ctor(
    OIIO_cspan_TypeDesc_t * this_);
#define OIIO_cspan_TypeDesc_ctor OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__ctor


unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__copy(
    OIIO_cspan_TypeDesc_t * this_
    , OIIO_cspan_TypeDesc_t const * copy);
#define OIIO_cspan_TypeDesc_copy OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__copy


/** Construct from T* and length. */
unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__from_ptr(
    OIIO_cspan_TypeDesc_t * this_
    , OIIO_TypeDesc_t const * data
    , long size);
#define OIIO_cspan_TypeDesc_from_ptr OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__from_ptr


unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__from_begin_end(
    OIIO_cspan_TypeDesc_t * this_
    , OIIO_TypeDesc_t const * b
    , OIIO_TypeDesc_t const * e);
#define OIIO_cspan_TypeDesc_from_begin_end OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__from_begin_end


unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__from_value(
    OIIO_cspan_TypeDesc_t * this_
    , OIIO_TypeDesc_t const * data);
#define OIIO_cspan_TypeDesc_from_value OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__from_value


unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1___assign(
    OIIO_cspan_TypeDesc_t * this_
    , OIIO_cspan_TypeDesc_t * * return_
    , OIIO_cspan_TypeDesc_t const * copy);
#define OIIO_cspan_TypeDesc__assign OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1___assign


unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__size(
    OIIO_cspan_TypeDesc_t const * this_
    , long * return_);
#define OIIO_cspan_TypeDesc_size OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__size


unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__size_bytes(
    OIIO_cspan_TypeDesc_t const * this_
    , long * return_);
#define OIIO_cspan_TypeDesc_size_bytes OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__size_bytes


unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__empty(
    OIIO_cspan_TypeDesc_t const * this_
    , _Bool * return_);
#define OIIO_cspan_TypeDesc_empty OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__empty


unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__data(
    OIIO_cspan_TypeDesc_t const * this_
    , OIIO_TypeDesc_t const * * return_);
#define OIIO_cspan_TypeDesc_data OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__data


unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1___index(
    OIIO_cspan_TypeDesc_t const * this_
    , OIIO_TypeDesc_t const * * return_
    , long idx);
#define OIIO_cspan_TypeDesc__index OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1___index


unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__at(
    OIIO_cspan_TypeDesc_t const * this_
    , OIIO_TypeDesc_t const * * return_
    , long idx);
#define OIIO_cspan_TypeDesc_at OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__at


unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__begin(
    OIIO_cspan_TypeDesc_t const * this_
    , OIIO_TypeDesc_t const * * return_);
#define OIIO_cspan_TypeDesc_begin OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__begin


unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__end(
    OIIO_cspan_TypeDesc_t const * this_
    , OIIO_TypeDesc_t const * * return_);
#define OIIO_cspan_TypeDesc_end OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__end


unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__cbegin(
    OIIO_cspan_TypeDesc_t const * this_
    , OIIO_TypeDesc_t const * * return_);
#define OIIO_cspan_TypeDesc_cbegin OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__cbegin


unsigned int OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__cend(
    OIIO_cspan_TypeDesc_t const * this_
    , OIIO_TypeDesc_t const * * return_);
#define OIIO_cspan_TypeDesc_cend OpenImageIO_v2_3_6__span_constOpenImageIO_v2_3_6__TypeDesc__1__cend


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__span_constfloat__1__sizeof();
#define OIIO_cspan_float_sizeof OpenImageIO_v2_3_6__span_constfloat__1__sizeof


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__span_constfloat__1__alignof();
#define OIIO_cspan_float_alignof OpenImageIO_v2_3_6__span_constfloat__1__alignof


unsigned int OpenImageIO_v2_3_6__span_constfloat__1__ctor(
    OIIO_cspan_float_t * this_);
#define OIIO_cspan_float_ctor OpenImageIO_v2_3_6__span_constfloat__1__ctor


unsigned int OpenImageIO_v2_3_6__span_constfloat__1__copy(
    OIIO_cspan_float_t * this_
    , OIIO_cspan_float_t const * copy);
#define OIIO_cspan_float_copy OpenImageIO_v2_3_6__span_constfloat__1__copy


/** Construct from T* and length. */
unsigned int OpenImageIO_v2_3_6__span_constfloat__1__from_ptr(
    OIIO_cspan_float_t * this_
    , float const * data
    , long size);
#define OIIO_cspan_float_from_ptr OpenImageIO_v2_3_6__span_constfloat__1__from_ptr


unsigned int OpenImageIO_v2_3_6__span_constfloat__1__from_begin_end(
    OIIO_cspan_float_t * this_
    , float const * b
    , float const * e);
#define OIIO_cspan_float_from_begin_end OpenImageIO_v2_3_6__span_constfloat__1__from_begin_end


unsigned int OpenImageIO_v2_3_6__span_constfloat__1__from_value(
    OIIO_cspan_float_t * this_
    , float const * data);
#define OIIO_cspan_float_from_value OpenImageIO_v2_3_6__span_constfloat__1__from_value


unsigned int OpenImageIO_v2_3_6__span_constfloat__1___assign(
    OIIO_cspan_float_t * this_
    , OIIO_cspan_float_t * * return_
    , OIIO_cspan_float_t const * copy);
#define OIIO_cspan_float__assign OpenImageIO_v2_3_6__span_constfloat__1___assign


unsigned int OpenImageIO_v2_3_6__span_constfloat__1__size(
    OIIO_cspan_float_t const * this_
    , long * return_);
#define OIIO_cspan_float_size OpenImageIO_v2_3_6__span_constfloat__1__size


unsigned int OpenImageIO_v2_3_6__span_constfloat__1__size_bytes(
    OIIO_cspan_float_t const * this_
    , long * return_);
#define OIIO_cspan_float_size_bytes OpenImageIO_v2_3_6__span_constfloat__1__size_bytes


unsigned int OpenImageIO_v2_3_6__span_constfloat__1__empty(
    OIIO_cspan_float_t const * this_
    , _Bool * return_);
#define OIIO_cspan_float_empty OpenImageIO_v2_3_6__span_constfloat__1__empty


unsigned int OpenImageIO_v2_3_6__span_constfloat__1__data(
    OIIO_cspan_float_t const * this_
    , float const * * return_);
#define OIIO_cspan_float_data OpenImageIO_v2_3_6__span_constfloat__1__data


unsigned int OpenImageIO_v2_3_6__span_constfloat__1___index(
    OIIO_cspan_float_t const * this_
    , float const * * return_
    , long idx);
#define OIIO_cspan_float__index OpenImageIO_v2_3_6__span_constfloat__1___index


unsigned int OpenImageIO_v2_3_6__span_constfloat__1__at(
    OIIO_cspan_float_t const * this_
    , float const * * return_
    , long idx);
#define OIIO_cspan_float_at OpenImageIO_v2_3_6__span_constfloat__1__at


unsigned int OpenImageIO_v2_3_6__span_constfloat__1__begin(
    OIIO_cspan_float_t const * this_
    , float const * * return_);
#define OIIO_cspan_float_begin OpenImageIO_v2_3_6__span_constfloat__1__begin


unsigned int OpenImageIO_v2_3_6__span_constfloat__1__end(
    OIIO_cspan_float_t const * this_
    , float const * * return_);
#define OIIO_cspan_float_end OpenImageIO_v2_3_6__span_constfloat__1__end


unsigned int OpenImageIO_v2_3_6__span_constfloat__1__cbegin(
    OIIO_cspan_float_t const * this_
    , float const * * return_);
#define OIIO_cspan_float_cbegin OpenImageIO_v2_3_6__span_constfloat__1__cbegin


unsigned int OpenImageIO_v2_3_6__span_constfloat__1__cend(
    OIIO_cspan_float_t const * this_
    , float const * * return_);
#define OIIO_cspan_float_cend OpenImageIO_v2_3_6__span_constfloat__1__cend


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__span_float__1__sizeof();
#define OIIO_span_float_sizeof OpenImageIO_v2_3_6__span_float__1__sizeof


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__span_float__1__alignof();
#define OIIO_span_float_alignof OpenImageIO_v2_3_6__span_float__1__alignof


unsigned int OpenImageIO_v2_3_6__span_float__1__ctor(
    OIIO_span_float_t * this_);
#define OIIO_span_float_ctor OpenImageIO_v2_3_6__span_float__1__ctor


unsigned int OpenImageIO_v2_3_6__span_float__1__copy(
    OIIO_span_float_t * this_
    , OIIO_span_float_t const * copy);
#define OIIO_span_float_copy OpenImageIO_v2_3_6__span_float__1__copy


/** Construct from T* and length. */
unsigned int OpenImageIO_v2_3_6__span_float__1__from_ptr(
    OIIO_span_float_t * this_
    , float * data
    , long size);
#define OIIO_span_float_from_ptr OpenImageIO_v2_3_6__span_float__1__from_ptr


unsigned int OpenImageIO_v2_3_6__span_float__1__from_begin_end(
    OIIO_span_float_t * this_
    , float * b
    , float * e);
#define OIIO_span_float_from_begin_end OpenImageIO_v2_3_6__span_float__1__from_begin_end


unsigned int OpenImageIO_v2_3_6__span_float__1__from_value(
    OIIO_span_float_t * this_
    , float * data);
#define OIIO_span_float_from_value OpenImageIO_v2_3_6__span_float__1__from_value


unsigned int OpenImageIO_v2_3_6__span_float__1___assign(
    OIIO_span_float_t * this_
    , OIIO_span_float_t * * return_
    , OIIO_span_float_t const * copy);
#define OIIO_span_float__assign OpenImageIO_v2_3_6__span_float__1___assign


unsigned int OpenImageIO_v2_3_6__span_float__1__size(
    OIIO_span_float_t const * this_
    , long * return_);
#define OIIO_span_float_size OpenImageIO_v2_3_6__span_float__1__size


unsigned int OpenImageIO_v2_3_6__span_float__1__size_bytes(
    OIIO_span_float_t const * this_
    , long * return_);
#define OIIO_span_float_size_bytes OpenImageIO_v2_3_6__span_float__1__size_bytes


unsigned int OpenImageIO_v2_3_6__span_float__1__empty(
    OIIO_span_float_t const * this_
    , _Bool * return_);
#define OIIO_span_float_empty OpenImageIO_v2_3_6__span_float__1__empty


unsigned int OpenImageIO_v2_3_6__span_float__1__data(
    OIIO_span_float_t const * this_
    , float * * return_);
#define OIIO_span_float_data OpenImageIO_v2_3_6__span_float__1__data


unsigned int OpenImageIO_v2_3_6__span_float__1___index(
    OIIO_span_float_t const * this_
    , float * * return_
    , long idx);
#define OIIO_span_float__index OpenImageIO_v2_3_6__span_float__1___index


unsigned int OpenImageIO_v2_3_6__span_float__1__at(
    OIIO_span_float_t const * this_
    , float * * return_
    , long idx);
#define OIIO_span_float_at OpenImageIO_v2_3_6__span_float__1__at


unsigned int OpenImageIO_v2_3_6__span_float__1__begin(
    OIIO_span_float_t const * this_
    , float * * return_);
#define OIIO_span_float_begin OpenImageIO_v2_3_6__span_float__1__begin


unsigned int OpenImageIO_v2_3_6__span_float__1__end(
    OIIO_span_float_t const * this_
    , float * * return_);
#define OIIO_span_float_end OpenImageIO_v2_3_6__span_float__1__end


unsigned int OpenImageIO_v2_3_6__span_float__1__cbegin(
    OIIO_span_float_t const * this_
    , float const * * return_);
#define OIIO_span_float_cbegin OpenImageIO_v2_3_6__span_float__1__cbegin


unsigned int OpenImageIO_v2_3_6__span_float__1__cend(
    OIIO_span_float_t const * this_
    , float const * * return_);
#define OIIO_span_float_cend OpenImageIO_v2_3_6__span_float__1__cend


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__sizeof();
#define OIIO_cspan_uint_sizeof OpenImageIO_v2_3_6__span_constunsignedint__1__sizeof


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__alignof();
#define OIIO_cspan_uint_alignof OpenImageIO_v2_3_6__span_constunsignedint__1__alignof


unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__ctor(
    OIIO_cspan_uint_t * this_);
#define OIIO_cspan_uint_ctor OpenImageIO_v2_3_6__span_constunsignedint__1__ctor


unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__copy(
    OIIO_cspan_uint_t * this_
    , OIIO_cspan_uint_t const * copy);
#define OIIO_cspan_uint_copy OpenImageIO_v2_3_6__span_constunsignedint__1__copy


/** Construct from T* and length. */
unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__from_ptr(
    OIIO_cspan_uint_t * this_
    , unsigned int const * data
    , long size);
#define OIIO_cspan_uint_from_ptr OpenImageIO_v2_3_6__span_constunsignedint__1__from_ptr


unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__from_begin_end(
    OIIO_cspan_uint_t * this_
    , unsigned int const * b
    , unsigned int const * e);
#define OIIO_cspan_uint_from_begin_end OpenImageIO_v2_3_6__span_constunsignedint__1__from_begin_end


unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__from_value(
    OIIO_cspan_uint_t * this_
    , unsigned int const * data);
#define OIIO_cspan_uint_from_value OpenImageIO_v2_3_6__span_constunsignedint__1__from_value


unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1___assign(
    OIIO_cspan_uint_t * this_
    , OIIO_cspan_uint_t * * return_
    , OIIO_cspan_uint_t const * copy);
#define OIIO_cspan_uint__assign OpenImageIO_v2_3_6__span_constunsignedint__1___assign


unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__size(
    OIIO_cspan_uint_t const * this_
    , long * return_);
#define OIIO_cspan_uint_size OpenImageIO_v2_3_6__span_constunsignedint__1__size


unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__size_bytes(
    OIIO_cspan_uint_t const * this_
    , long * return_);
#define OIIO_cspan_uint_size_bytes OpenImageIO_v2_3_6__span_constunsignedint__1__size_bytes


unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__empty(
    OIIO_cspan_uint_t const * this_
    , _Bool * return_);
#define OIIO_cspan_uint_empty OpenImageIO_v2_3_6__span_constunsignedint__1__empty


unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__data(
    OIIO_cspan_uint_t const * this_
    , unsigned int const * * return_);
#define OIIO_cspan_uint_data OpenImageIO_v2_3_6__span_constunsignedint__1__data


unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1___index(
    OIIO_cspan_uint_t const * this_
    , unsigned int const * * return_
    , long idx);
#define OIIO_cspan_uint__index OpenImageIO_v2_3_6__span_constunsignedint__1___index


unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__at(
    OIIO_cspan_uint_t const * this_
    , unsigned int const * * return_
    , long idx);
#define OIIO_cspan_uint_at OpenImageIO_v2_3_6__span_constunsignedint__1__at


unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__begin(
    OIIO_cspan_uint_t const * this_
    , unsigned int const * * return_);
#define OIIO_cspan_uint_begin OpenImageIO_v2_3_6__span_constunsignedint__1__begin


unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__end(
    OIIO_cspan_uint_t const * this_
    , unsigned int const * * return_);
#define OIIO_cspan_uint_end OpenImageIO_v2_3_6__span_constunsignedint__1__end


unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__cbegin(
    OIIO_cspan_uint_t const * this_
    , unsigned int const * * return_);
#define OIIO_cspan_uint_cbegin OpenImageIO_v2_3_6__span_constunsignedint__1__cbegin


unsigned int OpenImageIO_v2_3_6__span_constunsignedint__1__cend(
    OIIO_cspan_uint_t const * this_
    , unsigned int const * * return_);
#define OIIO_cspan_uint_cend OpenImageIO_v2_3_6__span_constunsignedint__1__cend


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__span_constint__1__sizeof();
#define OIIO_cspan_int_sizeof OpenImageIO_v2_3_6__span_constint__1__sizeof


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__span_constint__1__alignof();
#define OIIO_cspan_int_alignof OpenImageIO_v2_3_6__span_constint__1__alignof


unsigned int OpenImageIO_v2_3_6__span_constint__1__ctor(
    OIIO_cspan_int_t * this_);
#define OIIO_cspan_int_ctor OpenImageIO_v2_3_6__span_constint__1__ctor


unsigned int OpenImageIO_v2_3_6__span_constint__1__copy(
    OIIO_cspan_int_t * this_
    , OIIO_cspan_int_t const * copy);
#define OIIO_cspan_int_copy OpenImageIO_v2_3_6__span_constint__1__copy


/** Construct from T* and length. */
unsigned int OpenImageIO_v2_3_6__span_constint__1__from_ptr(
    OIIO_cspan_int_t * this_
    , int const * data
    , long size);
#define OIIO_cspan_int_from_ptr OpenImageIO_v2_3_6__span_constint__1__from_ptr


unsigned int OpenImageIO_v2_3_6__span_constint__1__from_begin_end(
    OIIO_cspan_int_t * this_
    , int const * b
    , int const * e);
#define OIIO_cspan_int_from_begin_end OpenImageIO_v2_3_6__span_constint__1__from_begin_end


unsigned int OpenImageIO_v2_3_6__span_constint__1__from_value(
    OIIO_cspan_int_t * this_
    , int const * data);
#define OIIO_cspan_int_from_value OpenImageIO_v2_3_6__span_constint__1__from_value


unsigned int OpenImageIO_v2_3_6__span_constint__1___assign(
    OIIO_cspan_int_t * this_
    , OIIO_cspan_int_t * * return_
    , OIIO_cspan_int_t const * copy);
#define OIIO_cspan_int__assign OpenImageIO_v2_3_6__span_constint__1___assign


unsigned int OpenImageIO_v2_3_6__span_constint__1__size(
    OIIO_cspan_int_t const * this_
    , long * return_);
#define OIIO_cspan_int_size OpenImageIO_v2_3_6__span_constint__1__size


unsigned int OpenImageIO_v2_3_6__span_constint__1__size_bytes(
    OIIO_cspan_int_t const * this_
    , long * return_);
#define OIIO_cspan_int_size_bytes OpenImageIO_v2_3_6__span_constint__1__size_bytes


unsigned int OpenImageIO_v2_3_6__span_constint__1__empty(
    OIIO_cspan_int_t const * this_
    , _Bool * return_);
#define OIIO_cspan_int_empty OpenImageIO_v2_3_6__span_constint__1__empty


unsigned int OpenImageIO_v2_3_6__span_constint__1__data(
    OIIO_cspan_int_t const * this_
    , int const * * return_);
#define OIIO_cspan_int_data OpenImageIO_v2_3_6__span_constint__1__data


unsigned int OpenImageIO_v2_3_6__span_constint__1___index(
    OIIO_cspan_int_t const * this_
    , int const * * return_
    , long idx);
#define OIIO_cspan_int__index OpenImageIO_v2_3_6__span_constint__1___index


unsigned int OpenImageIO_v2_3_6__span_constint__1__at(
    OIIO_cspan_int_t const * this_
    , int const * * return_
    , long idx);
#define OIIO_cspan_int_at OpenImageIO_v2_3_6__span_constint__1__at


unsigned int OpenImageIO_v2_3_6__span_constint__1__begin(
    OIIO_cspan_int_t const * this_
    , int const * * return_);
#define OIIO_cspan_int_begin OpenImageIO_v2_3_6__span_constint__1__begin


unsigned int OpenImageIO_v2_3_6__span_constint__1__end(
    OIIO_cspan_int_t const * this_
    , int const * * return_);
#define OIIO_cspan_int_end OpenImageIO_v2_3_6__span_constint__1__end


unsigned int OpenImageIO_v2_3_6__span_constint__1__cbegin(
    OIIO_cspan_int_t const * this_
    , int const * * return_);
#define OIIO_cspan_int_cbegin OpenImageIO_v2_3_6__span_constint__1__cbegin


unsigned int OpenImageIO_v2_3_6__span_constint__1__cend(
    OIIO_cspan_int_t const * this_
    , int const * * return_);
#define OIIO_cspan_int_cend OpenImageIO_v2_3_6__span_constint__1__cend


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__span_constchar__1__sizeof();
#define OIIO_cspan_char_sizeof OpenImageIO_v2_3_6__span_constchar__1__sizeof


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__span_constchar__1__alignof();
#define OIIO_cspan_char_alignof OpenImageIO_v2_3_6__span_constchar__1__alignof


unsigned int OpenImageIO_v2_3_6__span_constchar__1__ctor(
    OIIO_cspan_char_t * this_);
#define OIIO_cspan_char_ctor OpenImageIO_v2_3_6__span_constchar__1__ctor


unsigned int OpenImageIO_v2_3_6__span_constchar__1__copy(
    OIIO_cspan_char_t * this_
    , OIIO_cspan_char_t const * copy);
#define OIIO_cspan_char_copy OpenImageIO_v2_3_6__span_constchar__1__copy


/** Construct from T* and length. */
unsigned int OpenImageIO_v2_3_6__span_constchar__1__from_ptr(
    OIIO_cspan_char_t * this_
    , char const * data
    , long size);
#define OIIO_cspan_char_from_ptr OpenImageIO_v2_3_6__span_constchar__1__from_ptr


unsigned int OpenImageIO_v2_3_6__span_constchar__1__from_begin_end(
    OIIO_cspan_char_t * this_
    , char const * b
    , char const * e);
#define OIIO_cspan_char_from_begin_end OpenImageIO_v2_3_6__span_constchar__1__from_begin_end


unsigned int OpenImageIO_v2_3_6__span_constchar__1__from_value(
    OIIO_cspan_char_t * this_
    , char const * data);
#define OIIO_cspan_char_from_value OpenImageIO_v2_3_6__span_constchar__1__from_value


unsigned int OpenImageIO_v2_3_6__span_constchar__1___assign(
    OIIO_cspan_char_t * this_
    , OIIO_cspan_char_t * * return_
    , OIIO_cspan_char_t const * copy);
#define OIIO_cspan_char__assign OpenImageIO_v2_3_6__span_constchar__1___assign


unsigned int OpenImageIO_v2_3_6__span_constchar__1__size(
    OIIO_cspan_char_t const * this_
    , long * return_);
#define OIIO_cspan_char_size OpenImageIO_v2_3_6__span_constchar__1__size


unsigned int OpenImageIO_v2_3_6__span_constchar__1__size_bytes(
    OIIO_cspan_char_t const * this_
    , long * return_);
#define OIIO_cspan_char_size_bytes OpenImageIO_v2_3_6__span_constchar__1__size_bytes


unsigned int OpenImageIO_v2_3_6__span_constchar__1__empty(
    OIIO_cspan_char_t const * this_
    , _Bool * return_);
#define OIIO_cspan_char_empty OpenImageIO_v2_3_6__span_constchar__1__empty


unsigned int OpenImageIO_v2_3_6__span_constchar__1__data(
    OIIO_cspan_char_t const * this_
    , char const * * return_);
#define OIIO_cspan_char_data OpenImageIO_v2_3_6__span_constchar__1__data


unsigned int OpenImageIO_v2_3_6__span_constchar__1___index(
    OIIO_cspan_char_t const * this_
    , char const * * return_
    , long idx);
#define OIIO_cspan_char__index OpenImageIO_v2_3_6__span_constchar__1___index


unsigned int OpenImageIO_v2_3_6__span_constchar__1__at(
    OIIO_cspan_char_t const * this_
    , char const * * return_
    , long idx);
#define OIIO_cspan_char_at OpenImageIO_v2_3_6__span_constchar__1__at


unsigned int OpenImageIO_v2_3_6__span_constchar__1__begin(
    OIIO_cspan_char_t const * this_
    , char const * * return_);
#define OIIO_cspan_char_begin OpenImageIO_v2_3_6__span_constchar__1__begin


unsigned int OpenImageIO_v2_3_6__span_constchar__1__end(
    OIIO_cspan_char_t const * this_
    , char const * * return_);
#define OIIO_cspan_char_end OpenImageIO_v2_3_6__span_constchar__1__end


unsigned int OpenImageIO_v2_3_6__span_constchar__1__cbegin(
    OIIO_cspan_char_t const * this_
    , char const * * return_);
#define OIIO_cspan_char_cbegin OpenImageIO_v2_3_6__span_constchar__1__cbegin


unsigned int OpenImageIO_v2_3_6__span_constchar__1__cend(
    OIIO_cspan_char_t const * this_
    , char const * * return_);
#define OIIO_cspan_char_cend OpenImageIO_v2_3_6__span_constchar__1__cend


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__sizeof();
#define OIIO_cspan_uchar_sizeof OpenImageIO_v2_3_6__span_constunsignedchar__1__sizeof


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__alignof();
#define OIIO_cspan_uchar_alignof OpenImageIO_v2_3_6__span_constunsignedchar__1__alignof


unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__ctor(
    OIIO_cspan_uchar_t * this_);
#define OIIO_cspan_uchar_ctor OpenImageIO_v2_3_6__span_constunsignedchar__1__ctor


unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__copy(
    OIIO_cspan_uchar_t * this_
    , OIIO_cspan_uchar_t const * copy);
#define OIIO_cspan_uchar_copy OpenImageIO_v2_3_6__span_constunsignedchar__1__copy


/** Construct from T* and length. */
unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__from_ptr(
    OIIO_cspan_uchar_t * this_
    , unsigned char const * data
    , long size);
#define OIIO_cspan_uchar_from_ptr OpenImageIO_v2_3_6__span_constunsignedchar__1__from_ptr


unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__from_begin_end(
    OIIO_cspan_uchar_t * this_
    , unsigned char const * b
    , unsigned char const * e);
#define OIIO_cspan_uchar_from_begin_end OpenImageIO_v2_3_6__span_constunsignedchar__1__from_begin_end


unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__from_value(
    OIIO_cspan_uchar_t * this_
    , unsigned char const * data);
#define OIIO_cspan_uchar_from_value OpenImageIO_v2_3_6__span_constunsignedchar__1__from_value


unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1___assign(
    OIIO_cspan_uchar_t * this_
    , OIIO_cspan_uchar_t * * return_
    , OIIO_cspan_uchar_t const * copy);
#define OIIO_cspan_uchar__assign OpenImageIO_v2_3_6__span_constunsignedchar__1___assign


unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__size(
    OIIO_cspan_uchar_t const * this_
    , long * return_);
#define OIIO_cspan_uchar_size OpenImageIO_v2_3_6__span_constunsignedchar__1__size


unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__size_bytes(
    OIIO_cspan_uchar_t const * this_
    , long * return_);
#define OIIO_cspan_uchar_size_bytes OpenImageIO_v2_3_6__span_constunsignedchar__1__size_bytes


unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__empty(
    OIIO_cspan_uchar_t const * this_
    , _Bool * return_);
#define OIIO_cspan_uchar_empty OpenImageIO_v2_3_6__span_constunsignedchar__1__empty


unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__data(
    OIIO_cspan_uchar_t const * this_
    , unsigned char const * * return_);
#define OIIO_cspan_uchar_data OpenImageIO_v2_3_6__span_constunsignedchar__1__data


unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1___index(
    OIIO_cspan_uchar_t const * this_
    , unsigned char const * * return_
    , long idx);
#define OIIO_cspan_uchar__index OpenImageIO_v2_3_6__span_constunsignedchar__1___index


unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__at(
    OIIO_cspan_uchar_t const * this_
    , unsigned char const * * return_
    , long idx);
#define OIIO_cspan_uchar_at OpenImageIO_v2_3_6__span_constunsignedchar__1__at


unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__begin(
    OIIO_cspan_uchar_t const * this_
    , unsigned char const * * return_);
#define OIIO_cspan_uchar_begin OpenImageIO_v2_3_6__span_constunsignedchar__1__begin


unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__end(
    OIIO_cspan_uchar_t const * this_
    , unsigned char const * * return_);
#define OIIO_cspan_uchar_end OpenImageIO_v2_3_6__span_constunsignedchar__1__end


unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__cbegin(
    OIIO_cspan_uchar_t const * this_
    , unsigned char const * * return_);
#define OIIO_cspan_uchar_cbegin OpenImageIO_v2_3_6__span_constunsignedchar__1__cbegin


unsigned int OpenImageIO_v2_3_6__span_constunsignedchar__1__cend(
    OIIO_cspan_uchar_t const * this_
    , unsigned char const * * return_);
#define OIIO_cspan_uchar_cend OpenImageIO_v2_3_6__span_constunsignedchar__1__cend


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__sizeof();
#define OIIO_cspan_string_sizeof OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__sizeof


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__alignof();
#define OIIO_cspan_string_alignof OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__alignof


unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__ctor(
    OIIO_cspan_string_t * this_);
#define OIIO_cspan_string_ctor OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__ctor


unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__copy(
    OIIO_cspan_string_t * this_
    , OIIO_cspan_string_t const * copy);
#define OIIO_cspan_string_copy OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__copy


/** Construct from T* and length. */
unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__from_ptr(
    OIIO_cspan_string_t * this_
    , std_string_t const * data
    , long size);
#define OIIO_cspan_string_from_ptr OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__from_ptr


unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__from_begin_end(
    OIIO_cspan_string_t * this_
    , std_string_t const * b
    , std_string_t const * e);
#define OIIO_cspan_string_from_begin_end OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__from_begin_end


unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__from_value(
    OIIO_cspan_string_t * this_
    , std_string_t const * data);
#define OIIO_cspan_string_from_value OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__from_value


unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1___assign(
    OIIO_cspan_string_t * this_
    , OIIO_cspan_string_t * * return_
    , OIIO_cspan_string_t const * copy);
#define OIIO_cspan_string__assign OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1___assign


unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__size(
    OIIO_cspan_string_t const * this_
    , long * return_);
#define OIIO_cspan_string_size OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__size


unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__size_bytes(
    OIIO_cspan_string_t const * this_
    , long * return_);
#define OIIO_cspan_string_size_bytes OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__size_bytes


unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__empty(
    OIIO_cspan_string_t const * this_
    , _Bool * return_);
#define OIIO_cspan_string_empty OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__empty


unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__data(
    OIIO_cspan_string_t const * this_
    , std_string_t const * * return_);
#define OIIO_cspan_string_data OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__data


unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1___index(
    OIIO_cspan_string_t const * this_
    , std_string_t const * * return_
    , long idx);
#define OIIO_cspan_string__index OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1___index


unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__at(
    OIIO_cspan_string_t const * this_
    , std_string_t const * * return_
    , long idx);
#define OIIO_cspan_string_at OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__at


unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__begin(
    OIIO_cspan_string_t const * this_
    , std_string_t const * * return_);
#define OIIO_cspan_string_begin OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__begin


unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__end(
    OIIO_cspan_string_t const * this_
    , std_string_t const * * return_);
#define OIIO_cspan_string_end OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__end


unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__cbegin(
    OIIO_cspan_string_t const * this_
    , std_string_t const * * return_);
#define OIIO_cspan_string_cbegin OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__cbegin


unsigned int OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__cend(
    OIIO_cspan_string_t const * this_
    , std_string_t const * * return_);
#define OIIO_cspan_string_cend OpenImageIO_v2_3_6__span_conststd____cxx11__basic_string_char___1__cend


#ifdef __cplusplus
}
#endif
