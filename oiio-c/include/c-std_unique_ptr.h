#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenImageIO_v2_3_6__ImageInput_t_s OpenImageIO_v2_3_6__ImageInput_t;
typedef OpenImageIO_v2_3_6__ImageInput_t OIIO_ImageInput_t;
typedef struct OpenImageIO_v2_3_6__ImageOutput_t_s OpenImageIO_v2_3_6__ImageOutput_t;
typedef OpenImageIO_v2_3_6__ImageOutput_t OIIO_ImageOutput_t;

typedef struct std__unique_ptr_OIIO__ImageInput__t_s {
    char data[8];
} __attribute__((aligned(8))) std__unique_ptr_OIIO__ImageInput__t;
typedef std__unique_ptr_OIIO__ImageInput__t std_ImageInputPtr_t;

typedef struct std__unique_ptr_OIIO__ImageOutput__t_s {
    char data[8];
} __attribute__((aligned(8))) std__unique_ptr_OIIO__ImageOutput__t;
typedef std__unique_ptr_OIIO__ImageOutput__t std_ImageOutputPtr_t;


/** returns the size of this type in bytes */
unsigned int std__unique_ptr_OIIO__ImageInput__sizeof();
#define std_ImageInputPtr_sizeof std__unique_ptr_OIIO__ImageInput__sizeof


/** returns the size of this type in bytes */
unsigned int std__unique_ptr_OIIO__ImageInput__alignof();
#define std_ImageInputPtr_alignof std__unique_ptr_OIIO__ImageInput__alignof


unsigned int std__unique_ptr_OIIO__ImageInput__dtor(
    std_ImageInputPtr_t * this_);
#define std_ImageInputPtr_dtor std__unique_ptr_OIIO__ImageInput__dtor


unsigned int std__unique_ptr_OIIO__ImageInput__get(
    std_ImageInputPtr_t const * this_
    , OIIO_ImageInput_t * * return_);
#define std_ImageInputPtr_get std__unique_ptr_OIIO__ImageInput__get


/** returns the size of this type in bytes */
unsigned int std__unique_ptr_OIIO__ImageOutput__sizeof();
#define std_ImageOutputPtr_sizeof std__unique_ptr_OIIO__ImageOutput__sizeof


/** returns the size of this type in bytes */
unsigned int std__unique_ptr_OIIO__ImageOutput__alignof();
#define std_ImageOutputPtr_alignof std__unique_ptr_OIIO__ImageOutput__alignof


unsigned int std__unique_ptr_OIIO__ImageOutput__dtor(
    std_ImageOutputPtr_t * this_);
#define std_ImageOutputPtr_dtor std__unique_ptr_OIIO__ImageOutput__dtor


unsigned int std__unique_ptr_OIIO__ImageOutput__get(
    std_ImageOutputPtr_t const * this_
    , OIIO_ImageOutput_t * * return_);
#define std_ImageOutputPtr_get std__unique_ptr_OIIO__ImageOutput__get


#ifdef __cplusplus
}
#endif
