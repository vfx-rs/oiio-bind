#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenImageIO_v2_3_6__string_view_t_s OpenImageIO_v2_3_6__string_view_t;
typedef OpenImageIO_v2_3_6__string_view_t OIIO_string_view_t;

typedef struct std__pair_OIIO__string_view_int__t_s {
    char _unused;
} __attribute__((aligned(8))) std__pair_OIIO__string_view_int__t;
typedef std__pair_OIIO__string_view_int__t std_pair_string_int_t;


unsigned int std__pair_OIIO__string_view_int__copy(
    std_pair_string_int_t * * this_
    , std_pair_string_int_t const * rhs);
#define std_pair_string_int_copy std__pair_OIIO__string_view_int__copy


unsigned int std__pair_OIIO__string_view_int__dtor(
    std_pair_string_int_t * this_);
#define std_pair_string_int_dtor std__pair_OIIO__string_view_int__dtor


unsigned int std__pair_OIIO__string_view_int__get_first(
    std_pair_string_int_t const * this_
    , OIIO_string_view_t const * * return_);
#define std_pair_string_int_get_first std__pair_OIIO__string_view_int__get_first


unsigned int std__pair_OIIO__string_view_int__set_first(
    std_pair_string_int_t * this_
    , OIIO_string_view_t const * value);
#define std_pair_string_int_set_first std__pair_OIIO__string_view_int__set_first


unsigned int std__pair_OIIO__string_view_int__get_second(
    std_pair_string_int_t const * this_
    , int const * * return_);
#define std_pair_string_int_get_second std__pair_OIIO__string_view_int__get_second


unsigned int std__pair_OIIO__string_view_int__set_second(
    std_pair_string_int_t * this_
    , int const * value);
#define std_pair_string_int_set_second std__pair_OIIO__string_view_int__set_second


#ifdef __cplusplus
}
#endif
