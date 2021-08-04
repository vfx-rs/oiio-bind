#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenImageIO_v2_3_6__strided_ptr_float_1__t_s {
    char data[16];
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__strided_ptr_float_1__t;
typedef OpenImageIO_v2_3_6__strided_ptr_float_1__t OIIO_strided_ptr_float_t;


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1__sizeof();
#define OIIO_strided_ptr_float_sizeof OpenImageIO_v2_3_6__strided_ptr_float_1__sizeof


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1__alignof();
#define OIIO_strided_ptr_float_alignof OpenImageIO_v2_3_6__strided_ptr_float_1__alignof


unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1__ctor(
    OIIO_strided_ptr_float_t * this_
    , float * ptr
    , long stride);
#define OIIO_strided_ptr_float_ctor OpenImageIO_v2_3_6__strided_ptr_float_1__ctor


unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1__copy(
    OIIO_strided_ptr_float_t * this_
    , OIIO_strided_ptr_float_t const * p);
#define OIIO_strided_ptr_float_copy OpenImageIO_v2_3_6__strided_ptr_float_1__copy


unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1___assign(
    OIIO_strided_ptr_float_t * this_
    , OIIO_strided_ptr_float_t const * * return_
    , OIIO_strided_ptr_float_t const * p);
#define OIIO_strided_ptr_float__assign OpenImageIO_v2_3_6__strided_ptr_float_1___assign


unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1___index(
    OIIO_strided_ptr_float_t const * this_
    , float * * return_
    , long pos);
#define OIIO_strided_ptr_float__index OpenImageIO_v2_3_6__strided_ptr_float_1___index


unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1__data(
    OIIO_strided_ptr_float_t const * this_
    , float * * return_);
#define OIIO_strided_ptr_float_data OpenImageIO_v2_3_6__strided_ptr_float_1__data


unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1__stride(
    OIIO_strided_ptr_float_t const * this_
    , long * return_);
#define OIIO_strided_ptr_float_stride OpenImageIO_v2_3_6__strided_ptr_float_1__stride


unsigned int OpenImageIO_v2_3_6__strided_ptr_float_1__dtor(
    OIIO_strided_ptr_float_t * this_);
#define OIIO_strided_ptr_float_dtor OpenImageIO_v2_3_6__strided_ptr_float_1__dtor


#ifdef __cplusplus
}
#endif
