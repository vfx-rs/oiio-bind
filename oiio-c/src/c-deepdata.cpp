#include "c-deepdata_private.h"

#include "c-imageio_private.h"
#include "c-span_private.h"
#include "c-string_view_private.h"
#include "c-typedesc_private.h"
#include <new>

#include <stdexcept>

unsigned int OpenImageIO_v2_3_6__DeepData_ctor(
    OIIO_DeepData_t * * this_)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::DeepData());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_with_spec(
    OIIO_DeepData_t * * this_
    , OIIO_ImageSpec_t const * spec)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::DeepData(to_cpp_ref(spec)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_copy(
    OIIO_DeepData_t * * this_
    , OIIO_DeepData_t const * d)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::DeepData(to_cpp_ref(d)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_dtor(
    OIIO_DeepData_t * this_)
{
    try {
        delete to_cpp(this_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData__assign(
    OIIO_DeepData_t * this_
    , OIIO_DeepData_t const * * return_
    , OIIO_DeepData_t const * d)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(d)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_clear(
    OIIO_DeepData_t * this_)
{
    try {
        (to_cpp(this_)) -> clear();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_free(
    OIIO_DeepData_t * this_)
{
    try {
        (to_cpp(this_)) -> free();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_init(
    OIIO_DeepData_t * this_
    , long npix
    , int nchan
    , OIIO_cspan_TypeDesc_t channeltypes
    , OIIO_cspan_string_t channelnames)
{
    try {
        (to_cpp(this_)) -> init(npix, nchan, to_cpp_ref(&(channeltypes)), to_cpp_ref(&(channelnames)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_init_from_spec(
    OIIO_DeepData_t * this_
    , OIIO_ImageSpec_t const * spec)
{
    try {
        (to_cpp(this_)) -> init(to_cpp_ref(spec));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_initialized(
    OIIO_DeepData_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> initialized();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_allocated(
    OIIO_DeepData_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> allocated();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_pixels(
    OIIO_DeepData_t const * this_
    , long * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> pixels();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_channels(
    OIIO_DeepData_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> channels();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_Z_channel(
    OIIO_DeepData_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> Z_channel();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_Zback_channel(
    OIIO_DeepData_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> Zback_channel();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_A_channel(
    OIIO_DeepData_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> A_channel();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_AR_channel(
    OIIO_DeepData_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> AR_channel();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_AG_channel(
    OIIO_DeepData_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> AG_channel();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_AB_channel(
    OIIO_DeepData_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> AB_channel();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_channelname(
    OIIO_DeepData_t const * this_
    , OIIO_string_view_t * return_
    , int c)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> channelname(c));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_channeltype(
    OIIO_DeepData_t const * this_
    , OIIO_TypeDesc_t * return_
    , int c)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> channeltype(c));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_channelsize(
    OIIO_DeepData_t const * this_
    , unsigned long * return_
    , int c)
{
    try {
        *(return_) = (to_cpp(this_)) -> channelsize(c);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_samplesize(
    OIIO_DeepData_t const * this_
    , unsigned long * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> samplesize();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_samples(
    OIIO_DeepData_t const * this_
    , int * return_
    , long pixel)
{
    try {
        *(return_) = (to_cpp(this_)) -> samples(pixel);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_set_samples(
    OIIO_DeepData_t * this_
    , long pixel
    , int samps)
{
    try {
        (to_cpp(this_)) -> set_samples(pixel, samps);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_set_all_samples(
    OIIO_DeepData_t * this_
    , OIIO_cspan_uint_t samples)
{
    try {
        (to_cpp(this_)) -> set_all_samples(to_cpp_ref(&(samples)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_set_capacity(
    OIIO_DeepData_t * this_
    , long pixel
    , int samps)
{
    try {
        (to_cpp(this_)) -> set_capacity(pixel, samps);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_capacity(
    OIIO_DeepData_t const * this_
    , int * return_
    , long pixel)
{
    try {
        *(return_) = (to_cpp(this_)) -> capacity(pixel);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_insert_samples(
    OIIO_DeepData_t * this_
    , long pixel
    , int samplepos
    , int n)
{
    try {
        (to_cpp(this_)) -> insert_samples(pixel, samplepos, n);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_erase_samples(
    OIIO_DeepData_t * this_
    , long pixel
    , int samplepos
    , int n)
{
    try {
        (to_cpp(this_)) -> erase_samples(pixel, samplepos, n);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_deep_value(
    OIIO_DeepData_t const * this_
    , float * return_
    , long pixel
    , int channel
    , int sample)
{
    try {
        *(return_) = (to_cpp(this_)) -> deep_value(pixel, channel, sample);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_deep_value_uint(
    OIIO_DeepData_t const * this_
    , unsigned int * return_
    , long pixel
    , int channel
    , int sample)
{
    try {
        *(return_) = (to_cpp(this_)) -> deep_value_uint(pixel, channel, sample);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_set_deep_value(
    OIIO_DeepData_t * this_
    , long pixel
    , int channel
    , int sample
    , float value)
{
    try {
        (to_cpp(this_)) -> set_deep_value(pixel, channel, sample, value);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_set_deep_value_uint(
    OIIO_DeepData_t * this_
    , long pixel
    , int channel
    , int sample
    , unsigned int value)
{
    try {
        (to_cpp(this_)) -> set_deep_value(pixel, channel, sample, value);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_data_ptr(
    OIIO_DeepData_t * this_
    , void * * return_
    , long pixel
    , int channel
    , int sample)
{
    try {
        *(return_) = (to_cpp(this_)) -> data_ptr(pixel, channel, sample);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_data_ptr_const(
    OIIO_DeepData_t const * this_
    , void const * * return_
    , long pixel
    , int channel
    , int sample)
{
    try {
        *(return_) = (to_cpp(this_)) -> data_ptr(pixel, channel, sample);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_all_channeltypes(
    OIIO_DeepData_t const * this_
    , OIIO_cspan_TypeDesc_t * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> all_channeltypes());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_all_samples(
    OIIO_DeepData_t const * this_
    , OIIO_cspan_uint_t * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> all_samples());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_all_data(
    OIIO_DeepData_t const * this_
    , OIIO_cspan_char_t * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> all_data());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_copy_deep_sample(
    OIIO_DeepData_t * this_
    , _Bool * return_
    , long pixel
    , int sample
    , OIIO_DeepData_t const * src
    , long srcpixel
    , int srcsample)
{
    try {
        *(return_) = (to_cpp(this_)) -> copy_deep_sample(pixel, sample, to_cpp_ref(src), srcpixel, srcsample);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_copy_deep_pixel(
    OIIO_DeepData_t * this_
    , _Bool * return_
    , long pixel
    , OIIO_DeepData_t const * src
    , long srcpixel)
{
    try {
        *(return_) = (to_cpp(this_)) -> copy_deep_pixel(pixel, to_cpp_ref(src), srcpixel);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_split(
    OIIO_DeepData_t * this_
    , _Bool * return_
    , long pixel
    , float depth)
{
    try {
        *(return_) = (to_cpp(this_)) -> split(pixel, depth);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_sort(
    OIIO_DeepData_t * this_
    , long pixel)
{
    try {
        (to_cpp(this_)) -> sort(pixel);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_merge_overlaps(
    OIIO_DeepData_t * this_
    , long pixel)
{
    try {
        (to_cpp(this_)) -> merge_overlaps(pixel);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_merge_deep_pixels(
    OIIO_DeepData_t * this_
    , long pixel
    , OIIO_DeepData_t const * src
    , int srcpixel)
{
    try {
        (to_cpp(this_)) -> merge_deep_pixels(pixel, to_cpp_ref(src), srcpixel);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_opaque_z(
    OIIO_DeepData_t const * this_
    , float * return_
    , long pixel)
{
    try {
        *(return_) = (to_cpp(this_)) -> opaque_z(pixel);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__DeepData_occlusion_cull(
    OIIO_DeepData_t * this_
    , long pixel)
{
    try {
        (to_cpp(this_)) -> occlusion_cull(pixel);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

