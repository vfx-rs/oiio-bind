#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct std__string_t_s std__string_t;
typedef std__string_t std_string_t;
typedef struct OpenImageIO_v2_3_6__ustring_t_s OpenImageIO_v2_3_6__ustring_t;
typedef OpenImageIO_v2_3_6__ustring_t OIIO_ustring_t;
typedef struct OpenImageIO_v2_3_6__string_view_t_s OpenImageIO_v2_3_6__string_view_t;
typedef OpenImageIO_v2_3_6__string_view_t OIIO_string_view_t;
typedef struct OpenImageIO_v2_3_6__TypeDesc_t_s OpenImageIO_v2_3_6__TypeDesc_t;
typedef OpenImageIO_v2_3_6__TypeDesc_t OIIO_TypeDesc_t;

typedef struct std__vector_std__string__t_s {
    char _unused;
} __attribute__((aligned(8))) std__vector_std__string__t;
typedef std__vector_std__string__t std_vector_string_t;

typedef struct std__vector_OIIO__string_view__t_s {
    char _unused;
} __attribute__((aligned(8))) std__vector_OIIO__string_view__t;
typedef std__vector_OIIO__string_view__t std_vector_string_view_t;

typedef struct std__vector_OIIO__ustring__t_s {
    char _unused;
} __attribute__((aligned(8))) std__vector_OIIO__ustring__t;
typedef std__vector_OIIO__ustring__t std_vector_ustring_t;

typedef struct std__vector_char__t_s {
    char _unused;
} __attribute__((aligned(8))) std__vector_char__t;
typedef std__vector_char__t std_vector_char_t;

typedef struct std__vector_unsignedchar__t_s {
    char _unused;
} __attribute__((aligned(8))) std__vector_unsignedchar__t;
typedef std__vector_unsignedchar__t std_vector_uchar_t;

typedef struct std__vector_float__t_s {
    char _unused;
} __attribute__((aligned(8))) std__vector_float__t;
typedef std__vector_float__t std_vector_float_t;

typedef struct std__vector_unsignedlong__t_s {
    char _unused;
} __attribute__((aligned(8))) std__vector_unsignedlong__t;
typedef std__vector_unsignedlong__t std_vector_ulong_t;

typedef struct std__vector_int__t_s {
    char _unused;
} __attribute__((aligned(8))) std__vector_int__t;
typedef std__vector_int__t std_vector_int_t;

typedef struct std__vector_OIIO__TypeDesc__t_s {
    char _unused;
} __attribute__((aligned(8))) std__vector_OIIO__TypeDesc__t;
typedef std__vector_OIIO__TypeDesc__t std_vector_typedesc_t;


unsigned int std__vector_std__string__ctor(
    std_vector_string_t * * this_);
#define std_vector_string_ctor std__vector_std__string__ctor


unsigned int std__vector_std__string__copy(
    std_vector_string_t * * this_
    , std_vector_string_t const * rhs);
#define std_vector_string_copy std__vector_std__string__copy


unsigned int std__vector_std__string__dtor(
    std_vector_string_t * this_);
#define std_vector_string_dtor std__vector_std__string__dtor


unsigned int std__vector_std__string__size(
    std_vector_string_t const * this_
    , unsigned long * return_);
#define std_vector_string_size std__vector_std__string__size


unsigned int std__vector_std__string__index(
    std_vector_string_t const * this_
    , std_string_t const * * return_
    , unsigned long pos);
#define std_vector_string_index std__vector_std__string__index


unsigned int std__vector_std__string__data(
    std_vector_string_t * this_
    , std_string_t * * return_);
#define std_vector_string_data std__vector_std__string__data


unsigned int std__vector_std__string__data_const(
    std_vector_string_t const * this_
    , std_string_t const * * return_);
#define std_vector_string_data_const std__vector_std__string__data_const


unsigned int std__vector_std__string__push_back(
    std_vector_string_t * this_
    , std_string_t const * value);
#define std_vector_string_push_back std__vector_std__string__push_back


unsigned int std__vector_OIIO__string_view__ctor(
    std_vector_string_view_t * * this_);
#define std_vector_string_view_ctor std__vector_OIIO__string_view__ctor


unsigned int std__vector_OIIO__string_view__copy(
    std_vector_string_view_t * * this_
    , std_vector_string_view_t const * rhs);
#define std_vector_string_view_copy std__vector_OIIO__string_view__copy


unsigned int std__vector_OIIO__string_view__dtor(
    std_vector_string_view_t * this_);
#define std_vector_string_view_dtor std__vector_OIIO__string_view__dtor


unsigned int std__vector_OIIO__string_view__size(
    std_vector_string_view_t const * this_
    , unsigned long * return_);
#define std_vector_string_view_size std__vector_OIIO__string_view__size


unsigned int std__vector_OIIO__string_view__index(
    std_vector_string_view_t const * this_
    , OIIO_string_view_t const * * return_
    , unsigned long pos);
#define std_vector_string_view_index std__vector_OIIO__string_view__index


unsigned int std__vector_OIIO__string_view__data(
    std_vector_string_view_t * this_
    , OIIO_string_view_t * * return_);
#define std_vector_string_view_data std__vector_OIIO__string_view__data


unsigned int std__vector_OIIO__string_view__data_const(
    std_vector_string_view_t const * this_
    , OIIO_string_view_t const * * return_);
#define std_vector_string_view_data_const std__vector_OIIO__string_view__data_const


unsigned int std__vector_OIIO__string_view__push_back(
    std_vector_string_view_t * this_
    , OIIO_string_view_t const * value);
#define std_vector_string_view_push_back std__vector_OIIO__string_view__push_back


unsigned int std__vector_OIIO__ustring__ctor(
    std_vector_ustring_t * * this_);
#define std_vector_ustring_ctor std__vector_OIIO__ustring__ctor


unsigned int std__vector_OIIO__ustring__copy(
    std_vector_ustring_t * * this_
    , std_vector_ustring_t const * rhs);
#define std_vector_ustring_copy std__vector_OIIO__ustring__copy


unsigned int std__vector_OIIO__ustring__dtor(
    std_vector_ustring_t * this_);
#define std_vector_ustring_dtor std__vector_OIIO__ustring__dtor


unsigned int std__vector_OIIO__ustring__size(
    std_vector_ustring_t const * this_
    , unsigned long * return_);
#define std_vector_ustring_size std__vector_OIIO__ustring__size


unsigned int std__vector_OIIO__ustring__index(
    std_vector_ustring_t const * this_
    , OIIO_ustring_t const * * return_
    , unsigned long pos);
#define std_vector_ustring_index std__vector_OIIO__ustring__index


unsigned int std__vector_OIIO__ustring__data(
    std_vector_ustring_t * this_
    , OIIO_ustring_t * * return_);
#define std_vector_ustring_data std__vector_OIIO__ustring__data


unsigned int std__vector_OIIO__ustring__data_const(
    std_vector_ustring_t const * this_
    , OIIO_ustring_t const * * return_);
#define std_vector_ustring_data_const std__vector_OIIO__ustring__data_const


unsigned int std__vector_OIIO__ustring__push_back(
    std_vector_ustring_t * this_
    , OIIO_ustring_t const * value);
#define std_vector_ustring_push_back std__vector_OIIO__ustring__push_back


unsigned int std__vector_char__ctor(
    std_vector_char_t * * this_);
#define std_vector_char_ctor std__vector_char__ctor


unsigned int std__vector_char__copy(
    std_vector_char_t * * this_
    , std_vector_char_t const * rhs);
#define std_vector_char_copy std__vector_char__copy


unsigned int std__vector_char__dtor(
    std_vector_char_t * this_);
#define std_vector_char_dtor std__vector_char__dtor


unsigned int std__vector_char__size(
    std_vector_char_t const * this_
    , unsigned long * return_);
#define std_vector_char_size std__vector_char__size


unsigned int std__vector_char__index(
    std_vector_char_t const * this_
    , char const * * return_
    , unsigned long pos);
#define std_vector_char_index std__vector_char__index


unsigned int std__vector_char__data(
    std_vector_char_t * this_
    , char * * return_);
#define std_vector_char_data std__vector_char__data


unsigned int std__vector_char__data_const(
    std_vector_char_t const * this_
    , char const * * return_);
#define std_vector_char_data_const std__vector_char__data_const


unsigned int std__vector_char__push_back(
    std_vector_char_t * this_
    , char const * value);
#define std_vector_char_push_back std__vector_char__push_back


unsigned int std__vector_unsignedchar__ctor(
    std_vector_uchar_t * * this_);
#define std_vector_uchar_ctor std__vector_unsignedchar__ctor


unsigned int std__vector_unsignedchar__copy(
    std_vector_uchar_t * * this_
    , std_vector_uchar_t const * rhs);
#define std_vector_uchar_copy std__vector_unsignedchar__copy


unsigned int std__vector_unsignedchar__dtor(
    std_vector_uchar_t * this_);
#define std_vector_uchar_dtor std__vector_unsignedchar__dtor


unsigned int std__vector_unsignedchar__size(
    std_vector_uchar_t const * this_
    , unsigned long * return_);
#define std_vector_uchar_size std__vector_unsignedchar__size


unsigned int std__vector_unsignedchar__index(
    std_vector_uchar_t const * this_
    , unsigned char const * * return_
    , unsigned long pos);
#define std_vector_uchar_index std__vector_unsignedchar__index


unsigned int std__vector_unsignedchar__data(
    std_vector_uchar_t * this_
    , unsigned char * * return_);
#define std_vector_uchar_data std__vector_unsignedchar__data


unsigned int std__vector_unsignedchar__data_const(
    std_vector_uchar_t const * this_
    , unsigned char const * * return_);
#define std_vector_uchar_data_const std__vector_unsignedchar__data_const


unsigned int std__vector_unsignedchar__push_back(
    std_vector_uchar_t * this_
    , unsigned char const * value);
#define std_vector_uchar_push_back std__vector_unsignedchar__push_back


unsigned int std__vector_float__ctor(
    std_vector_float_t * * this_);
#define std_vector_float_ctor std__vector_float__ctor


unsigned int std__vector_float__copy(
    std_vector_float_t * * this_
    , std_vector_float_t const * rhs);
#define std_vector_float_copy std__vector_float__copy


unsigned int std__vector_float__dtor(
    std_vector_float_t * this_);
#define std_vector_float_dtor std__vector_float__dtor


unsigned int std__vector_float__size(
    std_vector_float_t const * this_
    , unsigned long * return_);
#define std_vector_float_size std__vector_float__size


unsigned int std__vector_float__index(
    std_vector_float_t const * this_
    , float const * * return_
    , unsigned long pos);
#define std_vector_float_index std__vector_float__index


unsigned int std__vector_float__data(
    std_vector_float_t * this_
    , float * * return_);
#define std_vector_float_data std__vector_float__data


unsigned int std__vector_float__data_const(
    std_vector_float_t const * this_
    , float const * * return_);
#define std_vector_float_data_const std__vector_float__data_const


unsigned int std__vector_float__push_back(
    std_vector_float_t * this_
    , float const * value);
#define std_vector_float_push_back std__vector_float__push_back


unsigned int std__vector_unsignedlong__ctor(
    std_vector_ulong_t * * this_);
#define std_vector_ulong_ctor std__vector_unsignedlong__ctor


unsigned int std__vector_unsignedlong__copy(
    std_vector_ulong_t * * this_
    , std_vector_ulong_t const * rhs);
#define std_vector_ulong_copy std__vector_unsignedlong__copy


unsigned int std__vector_unsignedlong__dtor(
    std_vector_ulong_t * this_);
#define std_vector_ulong_dtor std__vector_unsignedlong__dtor


unsigned int std__vector_unsignedlong__size(
    std_vector_ulong_t const * this_
    , unsigned long * return_);
#define std_vector_ulong_size std__vector_unsignedlong__size


unsigned int std__vector_unsignedlong__index(
    std_vector_ulong_t const * this_
    , unsigned long const * * return_
    , unsigned long pos);
#define std_vector_ulong_index std__vector_unsignedlong__index


unsigned int std__vector_unsignedlong__data(
    std_vector_ulong_t * this_
    , unsigned long * * return_);
#define std_vector_ulong_data std__vector_unsignedlong__data


unsigned int std__vector_unsignedlong__data_const(
    std_vector_ulong_t const * this_
    , unsigned long const * * return_);
#define std_vector_ulong_data_const std__vector_unsignedlong__data_const


unsigned int std__vector_unsignedlong__push_back(
    std_vector_ulong_t * this_
    , unsigned long const * value);
#define std_vector_ulong_push_back std__vector_unsignedlong__push_back


unsigned int std__vector_int__ctor(
    std_vector_int_t * * this_);
#define std_vector_int_ctor std__vector_int__ctor


unsigned int std__vector_int__copy(
    std_vector_int_t * * this_
    , std_vector_int_t const * rhs);
#define std_vector_int_copy std__vector_int__copy


unsigned int std__vector_int__dtor(
    std_vector_int_t * this_);
#define std_vector_int_dtor std__vector_int__dtor


unsigned int std__vector_int__size(
    std_vector_int_t const * this_
    , unsigned long * return_);
#define std_vector_int_size std__vector_int__size


unsigned int std__vector_int__index(
    std_vector_int_t const * this_
    , int const * * return_
    , unsigned long pos);
#define std_vector_int_index std__vector_int__index


unsigned int std__vector_int__data(
    std_vector_int_t * this_
    , int * * return_);
#define std_vector_int_data std__vector_int__data


unsigned int std__vector_int__data_const(
    std_vector_int_t const * this_
    , int const * * return_);
#define std_vector_int_data_const std__vector_int__data_const


unsigned int std__vector_int__push_back(
    std_vector_int_t * this_
    , int const * value);
#define std_vector_int_push_back std__vector_int__push_back


unsigned int std__vector_OIIO__TypeDesc__ctor(
    std_vector_typedesc_t * * this_);
#define std_vector_typedesc_ctor std__vector_OIIO__TypeDesc__ctor


unsigned int std__vector_OIIO__TypeDesc__copy(
    std_vector_typedesc_t * * this_
    , std_vector_typedesc_t const * rhs);
#define std_vector_typedesc_copy std__vector_OIIO__TypeDesc__copy


unsigned int std__vector_OIIO__TypeDesc__dtor(
    std_vector_typedesc_t * this_);
#define std_vector_typedesc_dtor std__vector_OIIO__TypeDesc__dtor


unsigned int std__vector_OIIO__TypeDesc__size(
    std_vector_typedesc_t const * this_
    , unsigned long * return_);
#define std_vector_typedesc_size std__vector_OIIO__TypeDesc__size


unsigned int std__vector_OIIO__TypeDesc__index(
    std_vector_typedesc_t const * this_
    , OIIO_TypeDesc_t const * * return_
    , unsigned long pos);
#define std_vector_typedesc_index std__vector_OIIO__TypeDesc__index


unsigned int std__vector_OIIO__TypeDesc__data(
    std_vector_typedesc_t * this_
    , OIIO_TypeDesc_t * * return_);
#define std_vector_typedesc_data std__vector_OIIO__TypeDesc__data


unsigned int std__vector_OIIO__TypeDesc__data_const(
    std_vector_typedesc_t const * this_
    , OIIO_TypeDesc_t const * * return_);
#define std_vector_typedesc_data_const std__vector_OIIO__TypeDesc__data_const


unsigned int std__vector_OIIO__TypeDesc__push_back(
    std_vector_typedesc_t * this_
    , OIIO_TypeDesc_t const * value);
#define std_vector_typedesc_push_back std__vector_OIIO__TypeDesc__push_back


#ifdef __cplusplus
}
#endif
