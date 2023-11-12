#include "oiio-sys/include/ffi_imageio.h"
#include <OpenImageIO/imageio.h>
#include <OpenImageIO/string_view.h>
#include <memory>
#include <stdexcept>
#include <stdio.h>

namespace oiio {
#pragma region Utility
bool
has_error()
{
    return OIIO::has_error();
}

rust::String
get_error(bool clear) {
    return OIIO::geterror(clear);
}
#pragma endregion

#pragma region ROI
ROI
roi_default() noexcept
{
    return ROI();
}

ROI
roi_new(int xbegin, int xend, int ybegin, int yend, int zbegin, int zend,
        int chbegin, int chend) noexcept
{
    return OIIO::ROI(xbegin, xend, ybegin, yend, zbegin, zend, chbegin, chend);
}

ROI
roi_new_all() noexcept
{
    return OIIO::ROI::All();
}

bool
roi_defined(const ROI& roi) noexcept
{
    return roi.defined();
}

int
roi_width(const ROI& roi) noexcept
{
    return roi.width();
}

int
roi_height(const ROI& roi) noexcept
{
    return roi.height();
}

int
roi_depth(const ROI& roi) noexcept
{
    return roi.depth();
}

int
roi_nchannels(const ROI& roi) noexcept
{
    return roi.nchannels();
}

uint64_t
roi_npixels(const ROI& roi) noexcept
{
    return roi.npixels();
}

bool
roi_eq_roi(const ROI& roi, const ROI& other) noexcept
{
    return roi == other;
}

bool
roi_ne_roi(const ROI& roi, const ROI& other) noexcept
{
    return roi != other;
}

bool
roi_contains(const ROI& roi, int x, int y, int z, int ch) noexcept
{
    return roi.contains(x, y, z, ch);
}

bool
roi_contains_roi(const ROI& roi, const ROI& other) noexcept
{
    return roi.contains(other);
}

ROI
roi_union(const ROI& roi, const ROI& other) noexcept
{
    return OIIO::roi_union(roi, other);
}

ROI
roi_intersection(const ROI& roi, const ROI& other) noexcept
{
    return OIIO::roi_intersection(roi, other);
}
#pragma endregion

#pragma region ImageSpec
std::unique_ptr<ImageSpec>
imagespec_from_resolution(int xres, int yres, int nchans)
{
    OIIO::ImageSpec* spec = new OIIO::ImageSpec(xres, yres, nchans);
    return std::unique_ptr<ImageSpec>(spec);
}

int
imagespec_x(const ImageSpec& spec)
{
    return spec.x;
}

int
imagespec_y(const ImageSpec& spec)
{
    return spec.y;
}

int
imagespec_z(const ImageSpec& spec)
{
    return spec.z;
}

int
imagespec_width(const ImageSpec& spec)
{
    return spec.width;
}

int
imagespec_height(const ImageSpec& spec)
{
    return spec.height;
}

int
imagespec_depth(const ImageSpec& spec)
{
    return spec.depth;
}

int
imagespec_full_x(const ImageSpec& spec)
{
    return spec.full_x;
}

int
imagespec_full_y(const ImageSpec& spec)
{
    return spec.full_y;
}

int
imagespec_full_z(const ImageSpec& spec)
{
    return spec.full_z;
}

int
imagespec_full_width(const ImageSpec& spec)
{
    return spec.full_width;
}

int
imagespec_full_height(const ImageSpec& spec)
{
    return spec.full_height;
}

int
imagespec_full_depth(const ImageSpec& spec)
{
    return spec.full_depth;
}

int
imagespec_tile_width(const ImageSpec& spec)
{
    return spec.tile_width;
}

int
imagespec_tile_height(const ImageSpec& spec)
{
    return spec.tile_height;
}

int
imagespec_tile_depth(const ImageSpec& spec)
{
    return spec.tile_depth;
}

int
imagespec_nchannels(const ImageSpec& spec)
{
    return spec.nchannels;
}

int
imagespec_alpha_channel(const ImageSpec& spec)
{
    return spec.alpha_channel;
}

int
imagespec_z_channel(const ImageSpec& spec)
{
    return spec.z_channel;
}

bool
imagespec_deep(const ImageSpec& spec)
{
    return spec.deep;
}

std::unique_ptr<std::vector<std::string>>
imagespec_channel_names(const ImageSpec& spec)
{
    std::vector<std::string>* channel_names = new std::vector<std::string>(
        spec.channelnames);
    return std::unique_ptr<std::vector<std::string>>(channel_names);
}
#pragma endregion

#pragma region ImageInput
std::unique_ptr<ImageInput>
imageinput_open_with_config(const rust::Str filename, const ImageSpec& config)
{
    std::unique_ptr<OIIO::ImageInput> image_input(
        OIIO::ImageInput::open(std::string(filename), &config));

    if (image_input) {
        return image_input;
    } else {
        throw std::runtime_error(OIIO::geterror());
    }
}

std::unique_ptr<ImageInput>
imageinput_open_without_config(const rust::Str filename)
{
    std::unique_ptr<OIIO::ImageInput> image_input(
        OIIO::ImageInput::open(std::string(filename), nullptr));

    if (image_input) {
        return image_input;
    } else {
        throw std::runtime_error(OIIO::geterror());
    }
}

std::unique_ptr<ImageSpec>
imageinput_open_newspec_with_config(ImageInput& imageinput,
                                    const rust::Str filename,
                                    const ImageSpec& config)
{
    std::unique_ptr<ImageSpec> newspec(new ImageSpec());

    if (!imageinput.open(std::string(filename), *newspec, config)) {
        throw std::runtime_error(imageinput.geterror());
    }

    return newspec;
}

std::unique_ptr<ImageSpec>
imageinput_open_newspec_without_config(ImageInput& imageinput,
                                       const rust::Str filename)
{
    std::unique_ptr<ImageSpec> newspec(new ImageSpec());

    if (!imageinput.open(std::string(filename), *newspec)) {
        throw std::runtime_error(imageinput.geterror());
    }

    return newspec;
}

std::unique_ptr<ImageInput>
imageinput_create_with_config(const rust::Str filename, bool do_open,
                              const ImageSpec& config,
                              const rust::Str plugin_searchpath)
{
    OIIO::string_view c_plugin_searchpath(plugin_searchpath.data(),
                                          plugin_searchpath.size());
    std::unique_ptr<OIIO::ImageInput> image_input(
        OIIO::ImageInput::create(std::string(filename), do_open, &config,
                                 c_plugin_searchpath));

    if (image_input) {
        return image_input;
    } else {
        throw std::runtime_error(OIIO::geterror());
    }
}

std::unique_ptr<ImageInput>
imageinput_create_without_config(const rust::Str filename, bool do_open,
                                 const rust::Str plugin_searchpath)
{
    OIIO::string_view c_plugin_searchpath(plugin_searchpath.data(),
                                          plugin_searchpath.size());
    std::unique_ptr<OIIO::ImageInput> image_input(
        OIIO::ImageInput::create(std::string(filename), do_open, nullptr,
                                 c_plugin_searchpath));

    if (image_input) {
        return image_input;
    } else {
        throw std::runtime_error(OIIO::geterror());
    }
}

void
imageinput_destroy(ImageInput& imageinput)
{
    imageinput.~ImageInput();
}

rust::Str
imageinput_format_name(const ImageInput& imageinput)
{
    return rust::Str(imageinput.format_name());
}

bool
imageinput_supports(const ImageInput& imageinput, const rust::Str feature)
{
    return imageinput.supports(
        OIIO::string_view(feature.data(), feature.size()));
}

bool
imageinput_valid_file(const ImageInput& imageinput, const rust::Str filename)
{
    return imageinput.valid_file(std::string(filename));
}

rust::String
imageinput_spec(OIIO::ImageInput& imageinput)
{
    std::string err = imageinput.geterror();

    return rust::String(err);
}

std::unique_ptr<ImageSpec>
imageinput_spec(const OIIO::ImageInput& imageinput)
{
    ImageSpec spec = static_cast<ImageSpec>(imageinput.spec());
    return std::unique_ptr<ImageSpec>(new ImageSpec(spec));
}

std::unique_ptr<ImageSpec>
imageinput_spec_subimage_miplevel(OIIO::ImageInput& imageinput,
                                  int32_t subimage, int32_t miplevel)
{
    ImageSpec spec = static_cast<ImageSpec>(
        imageinput.spec(subimage, miplevel));
    return std::unique_ptr<ImageSpec>(new ImageSpec(spec));
}

std::unique_ptr<ImageSpec>
imageinput_spec_dimensions(OIIO::ImageInput& imageinput, int32_t subimage,
                           int32_t miplevel)
{
    ImageSpec spec = static_cast<ImageSpec>(
        imageinput.spec_dimensions(subimage, miplevel));
    return std::unique_ptr<ImageSpec>(new ImageSpec(spec));
}

void
imageinput_close(ImageInput& imageinput)
{
    if (!imageinput.close()) {
        throw std::runtime_error(imageinput.geterror());
    }
}

int
imageinput_current_subimage(const ImageInput& imageinput)
{
    return imageinput.current_subimage();
}

int
imageinput_current_miplevel(const ImageInput& imageinput)
{
    return imageinput.current_miplevel();
}

bool
imageinput_seek_subimage(ImageInput& imageinput, int subimage, int miplevel)
{
    return imageinput.seek_subimage(subimage, miplevel);
}

bool
imageinput_read_scanline(ImageInput& imageinput, int y, int z,
                         const TypeDesc& format, rust::Slice<uint8_t> data,
                         int64_t xstride)
{
    return imageinput.read_scanline(y, z, format, data.data(), xstride);
}

bool
imageinput_read_scanlines(ImageInput& imageinput, int subimage, int miplevel,
                          int ybegin, int yend, int z, int chbegin, int chend,
                          const TypeDesc& format, rust::Slice<uint8_t> data,
                          int64_t xstride, int64_t ystride)
{
    return imageinput.read_scanlines(subimage, miplevel, ybegin, yend, z,
                                     chbegin, chend, format, data.data(),
                                     xstride, ystride);
}

bool
imageinput_read_image(ImageInput& imageinput, int subimage, int miplevel,
                      int chbegin, int chend, const TypeDesc& format,
                      rust::Slice<uint8_t> data, int64_t xstride,
                      int64_t ystride, int64_t zstride)
{
    return imageinput.read_image(subimage, miplevel, chbegin, chend, format,
                                 data.data(), xstride, ystride, zstride);
}

bool
imageinput_read_native_deep_scanlines(ImageInput& imageinput, int subimage,
                                      int miplevel, int ybegin, int yend, int z,
                                      int chbegin, int chend, DeepData& data)
{
    return imageinput.read_native_deep_scanlines(subimage, miplevel, ybegin,
                                                 yend, z, chbegin, chend, data);
}

bool
imageinput_read_native_deep_tiles(ImageInput& imageinput, int subimage,
                                  int miplevel, int xbegin, int xend,
                                  int ybegin, int yend, int zbegin, int zend,
                                  int chbegin, int chend, DeepData& data)
{
    return imageinput.read_native_deep_tiles(subimage, miplevel, xbegin, xend,
                                             ybegin, yend, zbegin, zend,
                                             chbegin, chend, data);
}

bool
imageinput_read_native_deep_image(ImageInput& imageinput, int subimage,
                                  int miplevel, DeepData& data)
{
    return imageinput.read_native_deep_image(subimage, miplevel, data);
}

bool
imageinput_read_native_scanline(ImageInput& imageinput, int subimage,
                                int miplevel, int y, int z,
                                rust::Slice<uint8_t> data)
{
    return imageinput.read_native_scanline(subimage, miplevel, y, z,
                                           data.data());
}

bool
imageinput_read_native_scanlines(ImageInput& imageinput, int subimage,
                                 int miplevel, int ybegin, int yend, int z,
                                 int chbegin, int chend,
                                 rust::Slice<uint8_t> data)
{
    return imageinput.read_native_scanlines(subimage, miplevel, ybegin, yend, z,
                                            chbegin, chend, data.data());
}

bool
imageinput_read_native_tile(ImageInput& imageinput, int subimage, int miplevel,
                            int x, int y, int z, rust::Slice<uint8_t> data)
{
    return imageinput.read_native_tile(subimage, miplevel, x, y, z,
                                       data.data());
}

bool
imageinput_read_native_tiles(ImageInput& imageinput, int xbegin, int xend,
                             int ybegin, int yend, int zbegin, int zend,
                             int chbegin, int chend, rust::Slice<uint8_t> data);

bool
imageinput_set_ioproxy(ImageInput& imageinput, IOProxy* ioproxy)
{
    return imageinput.set_ioproxy(ioproxy);
}

bool
imageinput_has_error(const ImageInput& imageinput)
{
    return imageinput.has_error();
}

rust::String
imageinput_geterror(const ImageInput& imageinput, bool clear)
{
    return rust::String(imageinput.geterror(clear));
}

void
imageinput_set_threads(ImageInput& imageinput, int n)
{
    return imageinput.threads(n);
}

int
imageinput_threads(const ImageInput& imageinput)
{
    return imageinput.threads();
}
#pragma endregion
}  // namespace oiio
