#include <OpenImageIO/deepdata.h>
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OIIO_NAMESPACE {

namespace OIIO = ::OIIO_NAMESPACE;

struct DeepData {
    using BoundType = OIIO::DeepData;

    DeepData();
    DeepData(const OIIO::ImageSpec& spec) CPPMM_RENAME(with_spec);
    DeepData(const OIIO::DeepData& d);
    ~DeepData();
    auto operator=(const OIIO::DeepData& d) -> const OIIO::DeepData&;
    auto clear() -> void;
    auto free() -> void;

    auto init(int64_t npix, int nchan,
              OIIO::span<const OIIO::TypeDesc, -1> channeltypes,
              OIIO::span<const std::string, -1> channelnames) -> void;

    CPPMM_RENAME(init_from_spec)
    auto init(const OIIO::ImageSpec& spec) -> void;

    auto initialized() const -> bool;
    auto allocated() const -> bool;
    auto pixels() const -> int64_t;
    auto channels() const -> int;
    auto Z_channel() const -> int;
    auto Zback_channel() const -> int;
    auto A_channel() const -> int;
    auto AR_channel() const -> int;
    auto AG_channel() const -> int;
    auto AB_channel() const -> int;
    auto channelname(int c) const -> OIIO::string_view;
    auto channeltype(int c) const -> OIIO::TypeDesc;
    auto channelsize(int c) const -> size_t;
    auto samplesize() const -> size_t;
    auto samples(int64_t pixel) const -> int;
    auto set_samples(int64_t pixel, int samps) -> void;
    auto set_all_samples(OIIO::span<const unsigned int, -1> samples) -> void;
    auto set_capacity(int64_t pixel, int samps) -> void;
    auto capacity(int64_t pixel) const -> int;
    auto insert_samples(int64_t pixel, int samplepos, int n) -> void;
    auto erase_samples(int64_t pixel, int samplepos, int n) -> void;
    auto deep_value(int64_t pixel, int channel, int sample) const -> float;
    auto deep_value_uint(int64_t pixel, int channel, int sample) const
        -> unsigned int;
    auto set_deep_value(int64_t pixel, int channel, int sample, float value)
        -> void;

    CPPMM_RENAME(set_deep_value_uint)
    auto set_deep_value(int64_t pixel, int channel, int sample, unsigned int value)
        -> void;

    auto data_ptr(int64_t pixel, int channel, int sample) -> void*;

    CPPMM_RENAME(data_ptr_const)
    auto data_ptr(int64_t pixel, int channel, int sample) const -> const void*;

    auto all_channeltypes() const -> OIIO::span<const OIIO::TypeDesc, -1>;
    auto all_samples() const -> OIIO::span<const unsigned int, -1>;
    auto all_data() const -> OIIO::span<const char, -1>;

    CPPMM_IGNORE
    auto get_pointers(std::vector<void*>& pointers) const -> void;

    auto copy_deep_sample(int64_t pixel, int sample, const OIIO::DeepData& src,
                          int64_t srcpixel, int srcsample) -> bool;
    auto copy_deep_pixel(int64_t pixel, const OIIO::DeepData& src, int64_t srcpixel)
        -> bool;
    auto split(int64_t pixel, float depth) -> bool;
    auto sort(int64_t pixel) -> void;
    auto merge_overlaps(int64_t pixel) -> void;
    auto merge_deep_pixels(int64_t pixel, const OIIO::DeepData& src, int srcpixel)
        -> void;
    auto opaque_z(int64_t pixel) const -> float;
    auto occlusion_cull(int64_t pixel) -> void;
} CPPMM_OPAQUEPTR; // struct DeepData

} // namespace OIIO_NAMESPACE

} // namespace cppmm_bind
