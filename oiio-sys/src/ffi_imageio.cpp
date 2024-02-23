#include "ffi_imageio.h"
#include "oiio-sys/src/imageio.rs.h"
#include <OpenImageIO/imageio.h>
#include <OpenImageIO/string_view.h>
#include <memory>
#include <stdexcept>
#include <stdio.h>

namespace oiio {
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

    return image_input;
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

const ImageSpec&
imageinput_spec(const OIIO::ImageInput& imageinput)
{
    return imageinput.spec();
}

const ImageSpec&
imageinput_spec_subimage_miplevel(OIIO::ImageInput& imageinput,
                                  int32_t subimage, int32_t miplevel)
{
    return imageinput.spec(subimage, miplevel);
}

const ImageSpec&
imageinput_spec_dimensions(OIIO::ImageInput& imageinput, int32_t subimage,
                           int32_t miplevel)
{
    return imageinput.spec_dimensions(subimage, miplevel);
}

bool
imageinput_close(ImageInput& imageinput)
{
    return imageinput.close();
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
imageinput_read_scanline(ImageInput& imageinput, int y, int z, TypeDesc format,
                         rust::Slice<uint8_t> data, int64_t xstride)
{
    return imageinput.read_scanline(y, z, format, data.data(), xstride);
}

bool
imageinput_read_scanlines(ImageInput& imageinput, int subimage, int miplevel,
                          int ybegin, int yend, int z, int chbegin, int chend,
                          TypeDesc format, rust::Slice<uint8_t> data,
                          int64_t xstride, int64_t ystride)
{
    return imageinput.read_scanlines(subimage, miplevel, ybegin, yend, z,
                                     chbegin, chend, format, data.data(),
                                     xstride, ystride);
}

bool
imageinput_read_image(ImageInput& imageinput, int subimage, int miplevel,
                      int chbegin, int chend, TypeDesc format,
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
imageinput_seterror(ImageInput& imageinput, const rust::Str message)
{
    imageinput.errorfmt(message.data());
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

#pragma region ImageOutput
std::unique_ptr<ImageOutput>
imageoutput_create(const rust::Str filename, IOProxy* ioproxy,
                   const rust::Str plugin_searchpath)
{
    OIIO::string_view c_filename(filename.data(), filename.size());
    OIIO::string_view c_plugin_searchpath(plugin_searchpath.data(),
                                          plugin_searchpath.size());
    return ImageOutput::create(c_filename, ioproxy, c_plugin_searchpath);
}

rust::Str
imageoutput_format_name(const ImageOutput& imageoutput)
{
    return imageoutput.format_name();
}

int
imageoutput_supports(const ImageOutput& imageoutput, const rust::Str feature)
{
    return imageoutput.supports(
        OIIO::string_view(feature.data(), feature.size()));
}

bool
imageoutput_open(ImageOutput& imageoutput, const rust::Str filename,
                 const ImageSpec& newspec, OpenMode mode)
{
    return imageoutput.open(std::string(filename), newspec, mode);
}

bool
imageoutput_open_multi_subimage(ImageOutput& imageoutput,
                                const rust::Str filename, int subimages,
                                const ImageSpec* specs)
{
    return imageoutput.open(std::string(filename), subimages, specs);
}

const ImageSpec&
imageoutput_spec(const ImageOutput& imageoutput)
{
    return imageoutput.spec();
}

bool
imageoutput_close(ImageOutput& imageoutput)
{
    return imageoutput.close();
}

bool
imageoutput_write_scanline(ImageOutput& imageoutput, int y, int z,
                           TypeDesc format, const rust::Slice<uint8_t> data,
                           int64_t xstride)
{
    return imageoutput.write_scanline(y, z, format, data.data(), xstride);
}

bool
imageoutput_write_scanlines(ImageOutput& imageoutput, int ybegin, int yend,
                            int z, TypeDesc format,
                            const rust::Slice<uint8_t> data, int64_t xstride,
                            int64_t ystride)
{
    return imageoutput.write_scanlines(ybegin, yend, z, format, data.data(),
                                       xstride, ystride);
}

bool
imageoutput_write_tile(ImageOutput& imageoutput, int x, int y, int z,
                       TypeDesc format, const rust::Slice<uint8_t> data,
                       int64_t xstride, int64_t ystride, int64_t zstride)
{
    return imageoutput.write_tile(x, y, z, format, data.data(), xstride,
                                  ystride, zstride);
}

bool
imageoutput_write_tiles(ImageOutput& imageoutput, int xbegin, int xend,
                        int ybegin, int yend, int zbegin, int zend,
                        TypeDesc format, const rust::Slice<uint8_t> data,
                        int64_t xstride, int64_t ystride, int64_t zstride)
{
    return imageoutput.write_tiles(xbegin, xend, ybegin, yend, zbegin, zend,
                                   format, data.data(), xstride, ystride,
                                   zstride);
}

bool
imageoutput_write_rectangle(ImageOutput& imageoutput, int xbegin, int xend,
                            int ybegin, int yend, int zbegin, int zend,
                            TypeDesc format, const rust::Slice<uint8_t> data,
                            int64_t xstride, int64_t ystride, int64_t zstride)
{
    return imageoutput.write_rectangle(xbegin, xend, ybegin, yend, zbegin, zend,
                                       format, data.data(), xstride, ystride,
                                       zstride);
}

bool
imageoutput_write_image(ImageOutput& imageoutput, TypeDesc format,
                        const rust::Slice<uint8_t> data, int64_t xstride,
                        int64_t ystride, int64_t zstride)
{
    return imageoutput.write_image(format, data.data(), xstride, ystride,
                                   zstride);
}

bool
imageoutput_write_deep_scanlines(ImageOutput& imageoutput, int ybegin, int yend,
                                 int z, const DeepData& deepdata)
{
    return imageoutput.write_deep_scanlines(ybegin, yend, z, deepdata);
}

bool
imageoutput_write_deep_tiles(ImageOutput& imageoutput, int xbegin, int xend,
                             int ybegin, int yend, int zbegin, int zend,
                             const DeepData& deepdata)
{
    return imageoutput.write_deep_tiles(xbegin, xend, ybegin, yend, zbegin,
                                        zend, deepdata);
}

bool
imageoutput_write_deep_image(ImageOutput& imageoutput, const DeepData& deepdata)
{
    return imageoutput.write_deep_image(deepdata);
}

bool
imageoutput_set_thumbnail(ImageOutput& imageoutput, const ImageBuf& thumb)
{
    return imageoutput.set_thumbnail(thumb);
}

bool
imageoutput_copy_image(ImageOutput& imageoutput, ImageInput* imageinput)
{
    return imageoutput.copy_image(imageinput);
}

bool
imageoutput_set_ioproxy(ImageOutput& imageoutput, IOProxy* ioproxy)
{
    return imageoutput.set_ioproxy(ioproxy);
}

bool
imageoutput_has_error(const ImageOutput& imageoutput)
{
    return imageoutput.has_error();
}

rust::String
imageoutput_geterror(const ImageOutput& imageoutput, bool clear)
{
    return rust::String(imageoutput.geterror(clear));
}

void
imageoutput_seterror(ImageOutput& imageoutput, const rust::Str message)
{
    imageoutput.errorfmt(message.data());
}

void
imageoutput_set_threads(ImageOutput& imageoutput, int n)
{
    imageoutput.threads(n);
}

int
imageoutput_threads(const ImageOutput& imageoutput)
{
    return imageoutput.threads();
}
#pragma endregion

#pragma region Utility Functions
void
shutdown()
{
    OIIO::shutdown();
}

int
openimageio_version()
{
    return OIIO::openimageio_version();
}

bool
has_error()
{
    return OIIO::has_error();
}

rust::String
get_error(bool clear)
{
    return OIIO::geterror(clear);
}

bool
attribute(const rust::Str name, TypeDesc type, rust::Slice<uint8_t> value)
{
    return OIIO::attribute(std::string_view(name.data(), name.length()), type,
                           value.data());
}

bool
attribute_float(const rust::Str name, float value)
{
    return OIIO::attribute(std::string_view(name.data(), name.length()), value);
}

bool
attribute_int(const rust::Str name, const int value)
{
    return OIIO::attribute(std::string_view(name.data(), name.length()), value);
}

bool
getattribute(const rust::Str name, const TypeDesc type,
             rust::Slice<uint8_t> value)
{
    return OIIO::getattribute(std::string_view(name.data(), name.length()),
                              type, value.data());
}

bool
getattribute_int(const rust::Str name, int& value)
{
    return OIIO::getattribute(std::string_view(name.data(), name.length()),
                              value);
}

bool
getattribute_float(const rust::Str name, float& value)
{
    {
        return OIIO::getattribute(std::string_view(name.data(), name.length()),
                                  value);
    }
}

bool
getattribute_string(const rust::Str name, rust::String& value)
{
    std::string c_value;
    bool result
        = OIIO::getattribute(std::string_view(name.data(), name.length()),
                             c_value);
    value = rust::String(c_value);
    return result;
}

int
get_int_attribute(const rust::Str name, int defaultval)
{
    return OIIO::get_int_attribute(std::string_view(name.data(), name.length()),
                                   defaultval);
}

float
get_float_attribute(const rust::Str name, float defaultval)
{
    return OIIO::get_float_attribute(std::string_view(name.data(),
                                                      name.length()),
                                     defaultval);
}

rust::String
get_string_attribute(const rust::Str name, const rust::Str defaultval)
{
    std::string c_defaultval(defaultval.data(), defaultval.length());
    std::string c_value = OIIO::get_string_attribute(
        std::string_view(name.data(), name.length()), c_defaultval);
    return rust::String(c_value);
}

// void
// declare_imageio_format(const rust::Str name,
//                        rust::Fn<ImageInput*(ImageInput*)> input_creator,
//                        const rust::Slice<const rust::Str> input_extensions,
//                        rust::Fn<ImageOutput*(ImageOutput*)> output_creator,
//                        const rust::Slice<const rust::Str> output_extensions,
//                        const rust::Str lib_version)
// {
//     auto c_input_creator = [&](OIIO::ImageInput*) -> OIIO::ImageInput* {
//         return input_creator();
//     };

//     std::vector<const char*> c_input_extensions;
//     c_input_extensions.reserve(input_extensions.size() + 1);
//     std::vector<const char*> c_output_extensions;
//     c_output_extensions.reserve(output_extensions.size() + 1);
//     std::string c_name(name.data(), name.length());
//     std::string c_lib_version(lib_version.data(), lib_version.length());

//     for (auto& ext : input_extensions) {
//         c_input_extensions.push_back(ext.data());
//     }
//     c_input_extensions.push_back(nullptr);

//     for (auto& ext : output_extensions) {
//         c_output_extensions.push_back(ext.data());
//     }
//     c_output_extensions.push_back(nullptr);

//     OIIO::declare_imageio_format(c_name, c_input_creator,
//                                  c_input_extensions.data(),
//                                  (ImageOutput::Creator)(&output_creator),
//                                  c_output_extensions.data(),
//                                  c_lib_version.data());
// }

bool
is_imageio_format_name(const rust::Str name)
{
    return OIIO::is_imageio_format_name(std::string(name));
}

rust::Vec<ExtensionMapItem>
get_extension_map()
{
    auto map = OIIO::get_extension_map();
    rust::Vec<ExtensionMapItem> result;

    for (auto& item : map) {
        ExtensionMapItem i {};
        rust::Vec<rust::String> values {};

        for (auto& value : item.second) {
            values.push_back(rust::String(value));
        }

        i.key   = rust::String(item.first);
        i.value = values;
        result.push_back(i);
    }

    return result;
}


bool
convert_pixel_values(TypeDesc src_type, rust::Slice<const uint8_t> src,
                     TypeDesc dst_type, rust::Slice<uint8_t> dst)
{
    return OIIO::convert_pixel_values(src_type, src.data(), dst_type,
                                      dst.data());
}

bool
convert_image(int nchannels, int width, int height, int depth,
              rust::Slice<const uint8_t> src, TypeDesc src_type,
              int64_t src_xstride, int64_t src_ystride, int64_t src_zstride,
              rust::Slice<uint8_t> dst, TypeDesc dst_type, int64_t dst_xstride,
              int64_t dst_ystride, int64_t dst_zstride)
{
    return OIIO::convert_image(nchannels, width, height, depth, src.data(),
                               src_type, src_xstride, src_ystride, src_zstride,
                               dst.data(), dst_type, dst_xstride, dst_ystride,
                               dst_zstride);
}

bool
parallel_convert_image(int nchannels, int width, int height, int depth,
                       rust::Slice<const uint8_t> src, TypeDesc src_type,
                       int64_t src_xstride, int64_t src_ystride,
                       int64_t src_zstride, rust::Slice<uint8_t> dst,
                       TypeDesc dst_type, int64_t dst_xstride,
                       int64_t dst_ystride, int64_t dst_zstride, int nthreads)
{
    return OIIO::parallel_convert_image(nchannels, width, height, depth,
                                        src.data(), src_type, src_xstride,
                                        src_ystride, src_zstride, dst.data(),
                                        dst_type, dst_xstride, dst_ystride,
                                        dst_zstride, nthreads);
}

void
add_dither(int nchannels, int width, int height, int depth, float* data,
           int64_t xstride, int64_t ystride, int64_t zstride,
           float ditheramplitude, int alpha_channel, int z_channel,
           unsigned int ditherseed, int chorigin, int xorigin, int yorigin,
           int zorigin)
{
    OIIO::add_dither(nchannels, width, height, depth, data, xstride, ystride,
                     zstride, ditheramplitude, alpha_channel, z_channel,
                     ditherseed, chorigin, xorigin, yorigin, zorigin);
}

void
premult(int nchannels, int width, int height, int depth, int chbegin, int chend,
        TypeDesc datatype, rust::Slice<uint8_t> data, int64_t xstride,
        int64_t ystride, int64_t zstride, int alpha_channel, int z_channel)
{
    OIIO::premult(nchannels, width, height, depth, chbegin, chend, datatype,
                  data.data(), xstride, ystride, zstride, alpha_channel,
                  z_channel);
}

bool
copy_image(int nchannels, int width, int height, int depth,
           rust::Slice<const uint8_t> src, int64_t pixelsize,
           int64_t src_xstride, int64_t src_ystride, int64_t src_zstride,
           rust::Slice<uint8_t> dst, int64_t dst_xstride, int64_t dst_ystride,
           int64_t dst_zstride)
{
    return OIIO::copy_image(nchannels, width, height, depth, src.data(),
                            pixelsize, src_xstride, src_ystride, src_zstride,
                            dst.data(), dst_xstride, dst_ystride, dst_zstride);
}

bool
wrap_black(int& coord, int origin, int width)
{
    return OIIO::wrap_black(coord, origin, width);
}

bool
wrap_clamp(int& coord, int origin, int width)
{
    return OIIO::wrap_clamp(coord, origin, width);
}

bool
wrap_periodic(int& coord, int origin, int width)
{
    return OIIO::wrap_periodic(coord, origin, width);
}

bool
wrap_periodic_pow2(int& coord, int origin, int width)
{
    return OIIO::wrap_periodic_pow2(coord, origin, width);
}

bool
wrap_mirror(int& coord, int origin, int width)
{
    return OIIO::wrap_mirror(coord, origin, width);
}

void
debug(const rust::Str message)
{
    OIIO::debug(message.data());
}
#pragma endregion
}  // namespace oiio
