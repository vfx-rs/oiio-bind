#pragma once
#include <c-span.h>
#include <c-string_view.h>
#include <c-typedesc.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenImageIO_v2_3_6__ImageSpec_t_s OpenImageIO_v2_3_6__ImageSpec_t;
typedef OpenImageIO_v2_3_6__ImageSpec_t OIIO_ImageSpec_t;

/** A `DeepData` holds the contents of an image of ``deep'' pixels (multiple
depth samples per pixel). */
typedef struct OpenImageIO_v2_3_6__DeepData_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__DeepData_t;
typedef OpenImageIO_v2_3_6__DeepData_t OIIO_DeepData_t;


/** Construct an empty DeepData. */
unsigned int OpenImageIO_v2_3_6__DeepData_ctor(
    OIIO_DeepData_t * * this_);
#define OIIO_DeepData_ctor OpenImageIO_v2_3_6__DeepData_ctor


/** Construct and init from an ImageSpec. */
unsigned int OpenImageIO_v2_3_6__DeepData_with_spec(
    OIIO_DeepData_t * * this_
    , OIIO_ImageSpec_t const * spec);
#define OIIO_DeepData_with_spec OpenImageIO_v2_3_6__DeepData_with_spec


/** Copy constructor */
unsigned int OpenImageIO_v2_3_6__DeepData_copy(
    OIIO_DeepData_t * * this_
    , OIIO_DeepData_t const * d);
#define OIIO_DeepData_copy OpenImageIO_v2_3_6__DeepData_copy


unsigned int OpenImageIO_v2_3_6__DeepData_dtor(
    OIIO_DeepData_t * this_);
#define OIIO_DeepData_dtor OpenImageIO_v2_3_6__DeepData_dtor


/** Copy assignment */
unsigned int OpenImageIO_v2_3_6__DeepData__assign(
    OIIO_DeepData_t * this_
    , OIIO_DeepData_t const * * return_
    , OIIO_DeepData_t const * d);
#define OIIO_DeepData__assign OpenImageIO_v2_3_6__DeepData__assign


/** Reset the `DeepData` to be equivalent to its empty initial state. */
unsigned int OpenImageIO_v2_3_6__DeepData_clear(
    OIIO_DeepData_t * this_);
#define OIIO_DeepData_clear OpenImageIO_v2_3_6__DeepData_clear


/** In addition to performing the tasks of `clear()`, also ensure that
all allocated memory has been truly freed. */
unsigned int OpenImageIO_v2_3_6__DeepData_free(
    OIIO_DeepData_t * this_);
#define OIIO_DeepData_free OpenImageIO_v2_3_6__DeepData_free


/** Initialize the `DeepData` with the specified number of pixels,
channels, channel types, and channel names, and allocate memory for
all the data. */
unsigned int OpenImageIO_v2_3_6__DeepData_init(
    OIIO_DeepData_t * this_
    , long npix
    , int nchan
    , OIIO_cspan_TypeDesc_t channeltypes
    , OIIO_cspan_string_t channelnames);
#define OIIO_DeepData_init OpenImageIO_v2_3_6__DeepData_init


/** Initialize the `DeepData` based on the `ImageSpec`'s total number of
pixels, number and types of channels. At this stage, all pixels are
assumed to have 0 samples, and no sample data is allocated. */
unsigned int OpenImageIO_v2_3_6__DeepData_init_from_spec(
    OIIO_DeepData_t * this_
    , OIIO_ImageSpec_t const * spec);
#define OIIO_DeepData_init_from_spec OpenImageIO_v2_3_6__DeepData_init_from_spec


/** Is the DeepData initialized? */
unsigned int OpenImageIO_v2_3_6__DeepData_initialized(
    OIIO_DeepData_t const * this_
    , _Bool * return_);
#define OIIO_DeepData_initialized OpenImageIO_v2_3_6__DeepData_initialized


/** Has the DeepData fully allocated? If no, it is still very
inexpensive to call set_capacity(). */
unsigned int OpenImageIO_v2_3_6__DeepData_allocated(
    OIIO_DeepData_t const * this_
    , _Bool * return_);
#define OIIO_DeepData_allocated OpenImageIO_v2_3_6__DeepData_allocated


/** Retrieve the total number of pixels. */
unsigned int OpenImageIO_v2_3_6__DeepData_pixels(
    OIIO_DeepData_t const * this_
    , long * return_);
#define OIIO_DeepData_pixels OpenImageIO_v2_3_6__DeepData_pixels


/** Retrieve the number of channels. */
unsigned int OpenImageIO_v2_3_6__DeepData_channels(
    OIIO_DeepData_t const * this_
    , int * return_);
#define OIIO_DeepData_channels OpenImageIO_v2_3_6__DeepData_channels


unsigned int OpenImageIO_v2_3_6__DeepData_Z_channel(
    OIIO_DeepData_t const * this_
    , int * return_);
#define OIIO_DeepData_Z_channel OpenImageIO_v2_3_6__DeepData_Z_channel


unsigned int OpenImageIO_v2_3_6__DeepData_Zback_channel(
    OIIO_DeepData_t const * this_
    , int * return_);
#define OIIO_DeepData_Zback_channel OpenImageIO_v2_3_6__DeepData_Zback_channel


unsigned int OpenImageIO_v2_3_6__DeepData_A_channel(
    OIIO_DeepData_t const * this_
    , int * return_);
#define OIIO_DeepData_A_channel OpenImageIO_v2_3_6__DeepData_A_channel


unsigned int OpenImageIO_v2_3_6__DeepData_AR_channel(
    OIIO_DeepData_t const * this_
    , int * return_);
#define OIIO_DeepData_AR_channel OpenImageIO_v2_3_6__DeepData_AR_channel


unsigned int OpenImageIO_v2_3_6__DeepData_AG_channel(
    OIIO_DeepData_t const * this_
    , int * return_);
#define OIIO_DeepData_AG_channel OpenImageIO_v2_3_6__DeepData_AG_channel


unsigned int OpenImageIO_v2_3_6__DeepData_AB_channel(
    OIIO_DeepData_t const * this_
    , int * return_);
#define OIIO_DeepData_AB_channel OpenImageIO_v2_3_6__DeepData_AB_channel


/** Return the name of channel c. */
unsigned int OpenImageIO_v2_3_6__DeepData_channelname(
    OIIO_DeepData_t const * this_
    , OIIO_string_view_t * return_
    , int c);
#define OIIO_DeepData_channelname OpenImageIO_v2_3_6__DeepData_channelname


/** Retrieve the data type of channel `c`. */
unsigned int OpenImageIO_v2_3_6__DeepData_channeltype(
    OIIO_DeepData_t const * this_
    , OIIO_TypeDesc_t * return_
    , int c);
#define OIIO_DeepData_channeltype OpenImageIO_v2_3_6__DeepData_channeltype


/** Return the size (in bytes) of one sample datum of channel `c`. */
unsigned int OpenImageIO_v2_3_6__DeepData_channelsize(
    OIIO_DeepData_t const * this_
    , unsigned long * return_
    , int c);
#define OIIO_DeepData_channelsize OpenImageIO_v2_3_6__DeepData_channelsize


/** Return the size (in bytes) for all channels of one sample. */
unsigned int OpenImageIO_v2_3_6__DeepData_samplesize(
    OIIO_DeepData_t const * this_
    , unsigned long * return_);
#define OIIO_DeepData_samplesize OpenImageIO_v2_3_6__DeepData_samplesize


/** Retrieve the number of samples for the given pixel index. */
unsigned int OpenImageIO_v2_3_6__DeepData_samples(
    OIIO_DeepData_t const * this_
    , int * return_
    , long pixel);
#define OIIO_DeepData_samples OpenImageIO_v2_3_6__DeepData_samples


/** Set the number of samples for the given pixel. This must be called
after init(). */
unsigned int OpenImageIO_v2_3_6__DeepData_set_samples(
    OIIO_DeepData_t * this_
    , long pixel
    , int samps);
#define OIIO_DeepData_set_samples OpenImageIO_v2_3_6__DeepData_set_samples


/** Set the number of samples for all pixels. The samples.size() is
required to match pixels(). */
unsigned int OpenImageIO_v2_3_6__DeepData_set_all_samples(
    OIIO_DeepData_t * this_
    , OIIO_cspan_uint_t samples);
#define OIIO_DeepData_set_all_samples OpenImageIO_v2_3_6__DeepData_set_all_samples


/** Set the capacity of samples for the given pixel. This must be called
after init(). */
unsigned int OpenImageIO_v2_3_6__DeepData_set_capacity(
    OIIO_DeepData_t * this_
    , long pixel
    , int samps);
#define OIIO_DeepData_set_capacity OpenImageIO_v2_3_6__DeepData_set_capacity


/** Retrieve the capacity (number of allocated samples) for the given
pixel index. */
unsigned int OpenImageIO_v2_3_6__DeepData_capacity(
    OIIO_DeepData_t const * this_
    , int * return_
    , long pixel);
#define OIIO_DeepData_capacity OpenImageIO_v2_3_6__DeepData_capacity


/** Insert `n` samples of the specified pixel, betinning at the sample
position index. After insertion, the new samples will have
uninitialized values. */
unsigned int OpenImageIO_v2_3_6__DeepData_insert_samples(
    OIIO_DeepData_t * this_
    , long pixel
    , int samplepos
    , int n);
#define OIIO_DeepData_insert_samples OpenImageIO_v2_3_6__DeepData_insert_samples


/** Erase `n` samples of the specified pixel, betinning at the sample
position index. */
unsigned int OpenImageIO_v2_3_6__DeepData_erase_samples(
    OIIO_DeepData_t * this_
    , long pixel
    , int samplepos
    , int n);
#define OIIO_DeepData_erase_samples OpenImageIO_v2_3_6__DeepData_erase_samples


/** Retrieve the value of the given pixel, channel, and sample index,
cast to a `float`. */
unsigned int OpenImageIO_v2_3_6__DeepData_deep_value(
    OIIO_DeepData_t const * this_
    , float * return_
    , long pixel
    , int channel
    , int sample);
#define OIIO_DeepData_deep_value OpenImageIO_v2_3_6__DeepData_deep_value


/** Retrieve the value of the given pixel, channel, and sample index,
cast to a `uint32`. */
unsigned int OpenImageIO_v2_3_6__DeepData_deep_value_uint(
    OIIO_DeepData_t const * this_
    , unsigned int * return_
    , long pixel
    , int channel
    , int sample);
#define OIIO_DeepData_deep_value_uint OpenImageIO_v2_3_6__DeepData_deep_value_uint


/** Set the value of the given pixel, channel, and sample index, for
floating-point channels. */
unsigned int OpenImageIO_v2_3_6__DeepData_set_deep_value(
    OIIO_DeepData_t * this_
    , long pixel
    , int channel
    , int sample
    , float value);
#define OIIO_DeepData_set_deep_value OpenImageIO_v2_3_6__DeepData_set_deep_value


/** Set the value of the given pixel, channel, and sample index, for
integer channels. */
unsigned int OpenImageIO_v2_3_6__DeepData_set_deep_value_uint(
    OIIO_DeepData_t * this_
    , long pixel
    , int channel
    , int sample
    , unsigned int value);
#define OIIO_DeepData_set_deep_value_uint OpenImageIO_v2_3_6__DeepData_set_deep_value_uint


/** Retrieve the pointer to a given pixel/channel/sample, or NULL if
there are no samples for that pixel. Use with care, and note that
calls to insert_samples and erase_samples can invalidate pointers
returned by prior calls to data_ptr. */
unsigned int OpenImageIO_v2_3_6__DeepData_data_ptr(
    OIIO_DeepData_t * this_
    , void * * return_
    , long pixel
    , int channel
    , int sample);
#define OIIO_DeepData_data_ptr OpenImageIO_v2_3_6__DeepData_data_ptr


unsigned int OpenImageIO_v2_3_6__DeepData_data_ptr_const(
    OIIO_DeepData_t const * this_
    , void const * * return_
    , long pixel
    , int channel
    , int sample);
#define OIIO_DeepData_data_ptr_const OpenImageIO_v2_3_6__DeepData_data_ptr_const


unsigned int OpenImageIO_v2_3_6__DeepData_all_channeltypes(
    OIIO_DeepData_t const * this_
    , OIIO_cspan_TypeDesc_t * return_);
#define OIIO_DeepData_all_channeltypes OpenImageIO_v2_3_6__DeepData_all_channeltypes


unsigned int OpenImageIO_v2_3_6__DeepData_all_samples(
    OIIO_DeepData_t const * this_
    , OIIO_cspan_uint_t * return_);
#define OIIO_DeepData_all_samples OpenImageIO_v2_3_6__DeepData_all_samples


unsigned int OpenImageIO_v2_3_6__DeepData_all_data(
    OIIO_DeepData_t const * this_
    , OIIO_cspan_char_t * return_);
#define OIIO_DeepData_all_data OpenImageIO_v2_3_6__DeepData_all_data


/** Copy a deep sample from `src` to this `DeepData`. They must have the
same channel layout. Return `true` if ok, `false` if the operation
could not be performed. */
unsigned int OpenImageIO_v2_3_6__DeepData_copy_deep_sample(
    OIIO_DeepData_t * this_
    , _Bool * return_
    , long pixel
    , int sample
    , OIIO_DeepData_t const * src
    , long srcpixel
    , int srcsample);
#define OIIO_DeepData_copy_deep_sample OpenImageIO_v2_3_6__DeepData_copy_deep_sample


/** Copy an entire deep pixel from `src` to this `DeepData`, completely
replacing any pixel data for that pixel. They must have the same
channel layout. Return `true` if ok, `false` if the operation could
not be performed. */
unsigned int OpenImageIO_v2_3_6__DeepData_copy_deep_pixel(
    OIIO_DeepData_t * this_
    , _Bool * return_
    , long pixel
    , OIIO_DeepData_t const * src
    , long srcpixel);
#define OIIO_DeepData_copy_deep_pixel OpenImageIO_v2_3_6__DeepData_copy_deep_pixel


/** Split all samples of that pixel at the given depth zsplit. Samples
that span z (i.e. z < zsplit < zback) will be split into two samples
with depth ranges [z,zsplit] and [zsplit,zback] with appropriate
changes to their color and alpha values. Samples not spanning zsplit
will remain intact. This operation will have no effect if there are
not Z and Zback channels present. Return true if any splits
occurred, false if the pixel was not modified. */
unsigned int OpenImageIO_v2_3_6__DeepData_split(
    OIIO_DeepData_t * this_
    , _Bool * return_
    , long pixel
    , float depth);
#define OIIO_DeepData_split OpenImageIO_v2_3_6__DeepData_split


/** Sort the samples of the pixel by their `Z` depth. */
unsigned int OpenImageIO_v2_3_6__DeepData_sort(
    OIIO_DeepData_t * this_
    , long pixel);
#define OIIO_DeepData_sort OpenImageIO_v2_3_6__DeepData_sort


/** Merge any adjacent samples in the pixel that exactly overlap in z
range. This is only useful if the pixel has previously been split at
all sample starts and ends, and sorted by Z.  Note that this may
change the number of samples in the pixel. */
unsigned int OpenImageIO_v2_3_6__DeepData_merge_overlaps(
    OIIO_DeepData_t * this_
    , long pixel);
#define OIIO_DeepData_merge_overlaps OpenImageIO_v2_3_6__DeepData_merge_overlaps


/** Merge the samples of `src`'s pixel into this `DeepData`'s pixel.
Return `true` if ok, `false` if the operation could not be
performed. */
unsigned int OpenImageIO_v2_3_6__DeepData_merge_deep_pixels(
    OIIO_DeepData_t * this_
    , long pixel
    , OIIO_DeepData_t const * src
    , int srcpixel);
#define OIIO_DeepData_merge_deep_pixels OpenImageIO_v2_3_6__DeepData_merge_deep_pixels


/** Return the z depth at which the pixel reaches full opacity. */
unsigned int OpenImageIO_v2_3_6__DeepData_opaque_z(
    OIIO_DeepData_t const * this_
    , float * return_
    , long pixel);
#define OIIO_DeepData_opaque_z OpenImageIO_v2_3_6__DeepData_opaque_z


/** Remove any samples hidden behind opaque samples. */
unsigned int OpenImageIO_v2_3_6__DeepData_occlusion_cull(
    OIIO_DeepData_t * this_
    , long pixel);
#define OIIO_DeepData_occlusion_cull OpenImageIO_v2_3_6__DeepData_occlusion_cull


#ifdef __cplusplus
}
#endif
