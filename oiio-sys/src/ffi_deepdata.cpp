#include "ffi_deepdata.h"
#include <OpenImageIO/span.h>

namespace oiio {
std::unique_ptr<DeepData>
deepdata_default()
{
    return std::make_unique<DeepData>();
}

std::unique_ptr<DeepData>
deepdata_new_from_spec(const ImageSpec& spec)
{
    return std::make_unique<DeepData>(spec);
}

std::unique_ptr<DeepData>
deepdata_clone(const DeepData& src)
{
    return std::make_unique<DeepData>(src);
}

std::unique_ptr<DeepData>
deepdata_clone_with_channeltypes(const DeepData& src,
                                 rust::Slice<const TypeDesc> channeltypes)
{
    OIIO::cspan<TypeDesc> c_channeltypes(channeltypes.data(),
                                         channeltypes.size());
    return std::make_unique<DeepData>(src, c_channeltypes);
}

void
deepdata_clear(DeepData& deepdata)
{
    deepdata.clear();
}

void
deepdata_free(DeepData& deepdata)
{
    deepdata.free();
}

void
deepdata_init(DeepData& deepdata, int64_t npix, int nchan,
              rust::Slice<const TypeDesc> channeltypes,
              rust::Slice<const rust::String> channelnames)
{
    OIIO::cspan<TypeDesc> c_channeltypes(channeltypes.data(),
                                         channeltypes.size());
    std::vector<std::string> channelnames_vec;
    channelnames_vec.reserve(channelnames.size());

    for (auto& s : channelnames) {
        channelnames_vec.push_back(std::string(s));
    }

    OIIO::cspan<std::string> c_channelnames(channelnames_vec.data(),
                                            channelnames_vec.size());
    deepdata.init(npix, nchan, c_channeltypes, c_channelnames);
}

void
deepdata_init_from_spec(DeepData& deepdata, const ImageSpec& spec)
{
    deepdata.init(spec);
}

bool
deepdata_initialized(const DeepData& deepdata)
{
    return deepdata.initialized();
}

bool
deepdata_allocated(const DeepData& deepdata)
{
    return deepdata.allocated();
}

int64_t
deepdata_pixels(const DeepData& deepdata)
{
    return deepdata.pixels();
}

int
deepdata_channels(const DeepData& deepdata)
{
    return deepdata.channels();
}

int
deepdata_z_channel(const DeepData& deepdata)
{
    return deepdata.Z_channel();
}

int
deepdata_z_back_channel(const DeepData& deepdata)
{
    return deepdata.Zback_channel();
}

int
deepdata_a_channel(const DeepData& deepdata)
{
    return deepdata.A_channel();
}

int
deepdata_ar_channel(const DeepData& deepdata)
{
    return deepdata.AR_channel();
}

int
deepdata_ag_channel(const DeepData& deepdata)
{
    return deepdata.AG_channel();
}

int
deepdata_ab_channel(const DeepData& deepdata)
{
    return deepdata.AB_channel();
}

rust::Str
deepdata_channelname(const DeepData& deepdata, int c)
{
    return rust::Str(deepdata.channelname(c));
}

TypeDesc
deepdata_channeltype(const DeepData& deepdata, int c)
{
    return deepdata.channeltype(c);
}

size_t
deepdata_channelsize(const DeepData& deepdata, int c)
{
    return deepdata.channelsize(c);
}

size_t
deepdata_samplesize(const DeepData& deepdata)
{
    return deepdata.samplesize();
}

bool
deepdata_same_channeltypes(const DeepData& deepdata, const DeepData& other)
{
    return deepdata.same_channeltypes(other);
}

int
deepdata_samples(const DeepData& deepdata, int64_t pixel)
{
    return deepdata.samples(pixel);
}

void
deepdata_set_samples(DeepData& deepdata, int64_t pixel, int samps)
{
    deepdata.set_samples(pixel, samps);
}

void
deepdata_set_all_samples(DeepData& deepdata,
                         rust::Slice<const unsigned int> samples)
{
    deepdata.set_all_samples(
        OIIO::cspan<unsigned int>(samples.data(), samples.size()));
}

void
deepdata_set_capacity(DeepData& deepdata, int64_t pixel, int samps)
{
    deepdata.set_capacity(pixel, samps);
}

int
deepdata_capacity(const DeepData& deepdata, int64_t pixel)
{
    return deepdata.capacity(pixel);
}

void
deepdata_insert_samples(DeepData& deepdata, int64_t pixel, int samplepos, int n)
{
    deepdata.insert_samples(pixel, samplepos, n);
}

void
deepdata_erase_samples(DeepData& deepdata, int64_t pixel, int samplepos, int n)
{
    deepdata.erase_samples(pixel, samplepos, n);
}

float
deepdata_deep_value(const DeepData& deepdata, int64_t pixel, int channel,
                    int sample)
{
    return deepdata.deep_value(pixel, channel, sample);
}

uint32_t
deepdata_deep_value_uint(const DeepData& deepdata, int64_t pixel, int channel,
                         int sample)
{
    return deepdata.deep_value_uint(pixel, channel, sample);
}

void
deepdata_set_deep_value(DeepData& deepdata, int64_t pixel, int channel,
                        int sample, float value)
{
    deepdata.set_deep_value(pixel, channel, sample, value);
}

void
deepdata_set_deep_value_uint(DeepData& deepdata, int64_t pixel, int channel,
                             int sample, uint32_t value)
{
    deepdata.set_deep_value(pixel, channel, sample, value);
}

uint8_t*
deepdata_mut_data_ptr(DeepData& deepdata, int64_t pixel, int channel,
                      int sample)
{
    return (uint8_t*)deepdata.data_ptr(pixel, channel, sample);
}

const uint8_t*
deepdata_data_ptr(const DeepData& deepdata, int64_t pixel, int channel,
                  int sample)
{
    return (uint8_t*)deepdata.data_ptr(pixel, channel, sample);
}

rust::Slice<const TypeDesc>
deepdata_all_channeltypes(const DeepData& deepdata)
{
    OIIO::cspan<TypeDesc> c_all_channeltypes = deepdata.all_channeltypes();
    return rust::Slice<const TypeDesc>(c_all_channeltypes.data(),
                                       c_all_channeltypes.size());
}

rust::Slice<const unsigned int>
deepdata_all_samples(const DeepData& deepdata)
{
    OIIO::cspan<unsigned int> c_all_samples = deepdata.all_samples();
    return rust::Slice<const unsigned int>(c_all_samples.data(),
                                           c_all_samples.size());
}

rust ::Slice<const char>
deepdata_all_data(const DeepData& deepdata)
{
    OIIO::cspan<char> c_all_data = deepdata.all_data();
    return rust::Slice<const char>(c_all_data.data(), c_all_data.size());
}

void
deepdata_get_pointers(const DeepData& deepdata, rust::Slice<uint8_t*> pointers)
{
    // TODO: This is inefficient. Maybe we can use a span instead of a vector.
    std::vector<void*> c_pointers(pointers.begin(), pointers.end());
    deepdata.get_pointers(c_pointers);
}

bool
deepdata_copy_deep_sample(DeepData& deepdata, int64_t pixel, int sample,
                          const DeepData& src, int64_t srcpixel, int srcsample)
{
    return deepdata.copy_deep_sample(pixel, sample, src, srcpixel, srcsample);
}

bool
deepdata_copy_deep_pixel(DeepData& deepdata, int64_t pixel, const DeepData& src,
                         int64_t srcpixel)
{
    return deepdata.copy_deep_pixel(pixel, src, srcpixel);
}

bool
deepdata_split(DeepData& deepdata, int64_t pixel, float depth)
{
    return deepdata.split(pixel, depth);
}

void
deepdata_sort(DeepData& deepdata, int64_t pixel)
{
    deepdata.sort(pixel);
}

void
deepdata_merge_overlaps(DeepData& deepdata, int64_t pixel)
{
    deepdata.merge_overlaps(pixel);
}

void
deepdata_merge_deep_pixels(DeepData& deepdata, int64_t pixel,
                           const DeepData& src, int srcpixel)
{
    deepdata.merge_deep_pixels(pixel, src, srcpixel);
}

float
deepdata_opaque_z(const DeepData& deepdata, int64_t pixel)
{
    return deepdata.opaque_z(pixel);
}

void
deepdata_occlusion_cull(DeepData& deepdata, int64_t pixel)
{
    deepdata.occlusion_cull(pixel);
}
}  // namespace oiio
