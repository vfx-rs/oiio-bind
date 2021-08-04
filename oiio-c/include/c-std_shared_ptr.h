#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct std__shared_ptr_OIIO__ColorProcessor__t_s {
    char _unused;
} __attribute__((aligned(8))) std__shared_ptr_OIIO__ColorProcessor__t;
typedef std__shared_ptr_OIIO__ColorProcessor__t std_ColorProcessorHandle_t;


unsigned int std__shared_ptr_OIIO__ColorProcessor__copy(
    std_ColorProcessorHandle_t * * this_
    , std_ColorProcessorHandle_t const * rhs);
#define std_ColorProcessorHandle_copy std__shared_ptr_OIIO__ColorProcessor__copy


unsigned int std__shared_ptr_OIIO__ColorProcessor__dtor(
    std_ColorProcessorHandle_t * this_);
#define std_ColorProcessorHandle_dtor std__shared_ptr_OIIO__ColorProcessor__dtor


#ifdef __cplusplus
}
#endif
