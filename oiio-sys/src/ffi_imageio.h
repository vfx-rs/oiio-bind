#pragma once

#include <OpenImageIO/deepdata.h>
#include <OpenImageIO/filesystem.h>
#include <OpenImageIO/imageio.h>
#include <OpenImageIO/typedesc.h>
#include <memory>
#include <rust/cxx.h>
#include <string>
#include <vector>

namespace oiio {
enum class Aggregate : uint8_t;
enum class BaseType : uint8_t;
enum class VecSemantics : uint8_t;
using DeepData    = OIIO::DeepData;
using ImageBuf    = OIIO::ImageBuf;
using ImageInput  = OIIO::ImageInput;
using ImageOutput = OIIO::ImageOutput;
using ImageSpec   = OIIO::ImageSpec;
using IOProxy     = OIIO::Filesystem::IOProxy;
using OpenMode    = OIIO::ImageOutput::OpenMode;
using ROI         = OIIO::ROI;
using TypeDesc    = OIIO::TypeDesc;

struct ExtensionMapItem;

#pragma region ROI

ROI
roi_default() noexcept;

ROI
roi_new(int xbegin, int xend, int ybegin, int yend, int zbegin, int zend,
        int chbegin, int chend) noexcept;

ROI
roi_new_all() noexcept;

bool
roi_defined(const ROI& roi) noexcept;

int
roi_width(const ROI& roi) noexcept;

int
roi_height(const ROI& roi) noexcept;

int
roi_depth(const ROI& roi) noexcept;

int
roi_nchannels(const ROI& roi) noexcept;

uint64_t
roi_npixels(const ROI& roi) noexcept;

bool
roi_eq_roi(const ROI& roi, const ROI& other) noexcept;

bool
roi_ne_roi(const ROI& roi, const ROI& other) noexcept;

bool
roi_contains(const ROI& roi, int x, int y, int z, int ch) noexcept;

bool
roi_contains_roi(const ROI& roi, const ROI& other) noexcept;

ROI
roi_union(const ROI& roi, const ROI& other) noexcept;

ROI
roi_intersection(const ROI& roi, const ROI& other) noexcept;
#pragma endregion

#pragma region ImageSpec
std::unique_ptr<ImageSpec>
imagespec_from_resolution(int xres, int yres, int nchans);

int
imagespec_x(const ImageSpec& spec);

int
imagespec_y(const ImageSpec& spec);

int
imagespec_z(const ImageSpec& spec);

int
imagespec_width(const ImageSpec& spec);

int
imagespec_height(const ImageSpec& spec);

int
imagespec_depth(const ImageSpec& spec);

int
imagespec_full_x(const ImageSpec& spec);

int
imagespec_full_y(const ImageSpec& spec);

int
imagespec_full_z(const ImageSpec& spec);

int
imagespec_full_width(const ImageSpec& spec);

int
imagespec_full_height(const ImageSpec& spec);

int
imagespec_full_depth(const ImageSpec& spec);

int
imagespec_tile_width(const ImageSpec& spec);

int
imagespec_tile_height(const ImageSpec& spec);

int
imagespec_tile_depth(const ImageSpec& spec);

int
imagespec_nchannels(const ImageSpec& spec);

int
imagespec_alpha_channel(const ImageSpec& spec);

int
imagespec_z_channel(const ImageSpec& spec);

bool
imagespec_deep(const ImageSpec& spec);

std::unique_ptr<std::vector<std::string>>
imagespec_channel_names(const ImageSpec& spec);
#pragma endregion

#pragma region ImageInput

std::unique_ptr<ImageInput>
imageinput_open_with_config(const rust::Str filename, const ImageSpec& config);

std::unique_ptr<ImageInput>
imageinput_open_without_config(const rust::Str filename);

std::unique_ptr<ImageInput>
imageinput_create_with_config(const rust::Str filename, bool do_open,
                              const ImageSpec& config,
                              const rust::Str plugin_searchpath);

std::unique_ptr<ImageInput>
imageinput_create_without_config(const rust::Str filename, bool do_open,
                                 const rust::Str plugin_searchpath);

void
imageinput_destroy(ImageInput& imageinput);

rust::Str
imageinput_format_name(const ImageInput& imageinput);

bool
imageinput_supports(const ImageInput& imageinput, const rust::Str feature);

bool
imageinput_valid_file(const ImageInput& imageinput, const rust::Str filename);

rust::String
imageinput_geterror(ImageInput& imageinput);

const ImageSpec&
imageinput_spec(const ImageInput& imageinput);

const ImageSpec&
imageinput_spec_subimage_miplevel(ImageInput& imageinput, int32_t subimage,
                                  int32_t miplevel);

const ImageSpec&
imageinput_spec_dimensions(ImageInput& imageinput, int32_t subimage,
                           int32_t miplevel);

bool
imageinput_close(ImageInput& imageinput);

int
imageinput_current_subimage(const ImageInput& imageinput);

int
imageinput_current_miplevel(const ImageInput& imageinput);

bool
imageinput_seek_subimage(ImageInput& imageinput, int subimage, int miplevel);

bool
imageinput_read_scanline(ImageInput& imageinput, int y, int z, TypeDesc format,
                         rust::Slice<uint8_t> data, int64_t xstride);

bool
imageinput_read_scanlines(ImageInput& imageinput, int subimage, int miplevel,
                          int ybegin, int yend, int z, int chbegin, int chend,
                          TypeDesc format, rust::Slice<uint8_t> data,
                          int64_t xstride, int64_t ystride);

bool
imageinput_read_tile(ImageInput& imageinput, int x, int y, int z,
                     TypeDesc format, rust::Slice<uint8_t> data,
                     int64_t xstride, int64_t ystride, int64_t zstride);

bool
imageinput_read_scanlines(ImageInput& imageinput, int subimage, int miplevel,
                          int ybegin, int yend, int zbegin, int zend,
                          int chbegin, int chend, TypeDesc format,
                          rust::Slice<uint8_t> data, int64_t xstride,
                          int64_t ystride, int64_t zstride);

bool
imageinput_read_image(ImageInput& imageinput, int subimage, int miplevel,
                      int chbegin, int chend, TypeDesc format,
                      rust::Slice<uint8_t> data, int64_t xstride,
                      int64_t ystride, int64_t zstride);

bool
imageinput_read_native_deep_scanlines(ImageInput& imageinput, int subimage,
                                      int miplevel, int ybegin, int yend, int z,
                                      int chbegin, int chend, DeepData& data);

bool
imageinput_read_native_deep_tiles(ImageInput& imageinput, int subimage,
                                  int miplevel, int xbegin, int xend,
                                  int ybegin, int yend, int zbegin, int zend,
                                  int chbegin, int chend, DeepData& data);

bool
imageinput_read_native_deep_image(ImageInput& imageinput, int subimage,
                                  int miplevel, DeepData& data);

bool
imageinput_read_native_scanline(ImageInput& imageinput, int subimage,
                                int miplevel, int y, int z,
                                rust::Slice<uint8_t> data);

bool
imageinput_read_native_scanlines(ImageInput& imageinput, int subimage,
                                 int miplevel, int ybegin, int yend, int z,
                                 int chbegin, int chend,
                                 rust::Slice<uint8_t> data);

bool
imageinput_read_native_tile(ImageInput& imageinput, int subimage, int miplevel,
                            int x, int y, int z, rust::Slice<uint8_t> data);

bool
imageinput_read_native_tiles(ImageInput& imageinput, int xbegin, int xend,
                             int ybegin, int yend, int zbegin, int zend,
                             int chbegin, int chend, rust::Slice<uint8_t> data);

bool
imageinput_set_ioproxy(ImageInput& imageinput, IOProxy* ioproxy);

bool
imageinput_has_error(const ImageInput& imageinput);

rust::String
imageinput_geterror(const ImageInput& imageinput, bool clear);

void
imageinput_seterror(ImageInput& imageinput, const rust::Str message);

void
imageinput_set_threads(ImageInput& imageinput, int n);

int
imageinput_threads(const ImageInput& imageinput);
#pragma endregion

#pragma region ImageOutput
std::unique_ptr<ImageOutput>
imageoutput_create(const rust::Str filename, IOProxy* ioproxy,
                   const rust::Str plugin_searchpath);

rust::Str
imageoutput_format_name(const ImageOutput& imageoutput);

int
imageoutput_supports(const ImageOutput& imageoutput, const rust::Str feature);

bool
imageoutput_open(ImageOutput& imageoutput, const rust::Str filename,
                 const ImageSpec& newspec, OpenMode mode);

bool
imageoutput_open_multi_subimage(ImageOutput& imageoutput,
                                const rust::Str filename, int subimages,
                                const ImageSpec* specs);

const ImageSpec&
imageoutput_spec(const ImageOutput& imageoutput);

bool
imageoutput_close(ImageOutput& imageoutput);

bool
imageoutput_write_scanline(ImageOutput& imageoutput, int y, int z,
                           TypeDesc format, const rust::Slice<uint8_t> data,
                           int64_t xstride);

bool
imageoutput_write_scanlines(ImageOutput& imageoutput, int ybegin, int yend,
                            int z, TypeDesc format,
                            const rust::Slice<uint8_t> data, int64_t xstride,
                            int64_t ystride);

bool
imageoutput_write_tile(ImageOutput& imageoutput, int x, int y, int z,
                       TypeDesc format, const rust::Slice<uint8_t> data,
                       int64_t xstride, int64_t ystride, int64_t zstride);

bool
imageoutput_write_tiles(ImageOutput& imageoutput, int xbegin, int xend,
                        int ybegin, int yend, int zbegin, int zend,
                        TypeDesc format, const rust::Slice<uint8_t> data,
                        int64_t xstride, int64_t ystride, int64_t zstride);

bool
imageoutput_write_rectangle(ImageOutput& imageoutput, int xbegin, int xend,
                            int ybegin, int yend, int zbegin, int zend,
                            TypeDesc format, const rust::Slice<uint8_t> data,
                            int64_t xstride, int64_t ystride, int64_t zstride);

bool
imageoutput_write_image(ImageOutput& imageoutput, TypeDesc format,
                        const rust::Slice<uint8_t> data, int64_t xstride,
                        int64_t ystride, int64_t zstride);

bool
imageoutput_write_deep_scanlines(ImageOutput& imageoutput, int ybegin, int yend,
                                 int z, const DeepData& deepdata);

bool
imageoutput_write_deep_tiles(ImageOutput& imageoutput, int xbegin, int xend,
                             int ybegin, int yend, int zbegin, int zend,
                             const DeepData& deepdata);

bool
imageoutput_write_deep_image(ImageOutput& imageoutput,
                             const DeepData& deepdata);

bool
imageoutput_set_thumbnail(ImageOutput& imageoutput, const ImageBuf& thumb);

bool
imageoutput_copy_image(ImageOutput& imageoutput, ImageInput* imageinput);

bool
imageoutput_set_ioproxy(ImageOutput& imageoutput, IOProxy* ioproxy);

bool
imageoutput_has_error(const ImageOutput& imageoutput);

rust::String
imageoutput_geterror(const ImageOutput& imageoutput, bool clear);

void
imageoutput_seterror(ImageOutput& imageoutput, const rust::Str message);

void
imageoutput_set_threads(ImageOutput& imageoutput, int n);

int
imageoutput_threads(const ImageOutput& imageoutput);
#pragma endregion

#pragma region Utility Functions
void
shutdown();

int
openimageio_version();

bool
has_error();

rust::String
get_error(bool clear);

bool
attribute(const rust::Str name, TypeDesc type, rust::Slice<uint8_t> value);

bool
attribute_float(const rust::Str name, float value);

bool
attribute_int(const rust::Str name, int value);

bool
getattribute(const rust::Str name, TypeDesc type, rust::Slice<uint8_t> value);

bool
getattribute_int(const rust::Str name, int& value);

bool
getattribute_float(const rust::Str name, float& value);

bool
getattribute_string(const rust::Str name, rust::String& value);

int
get_int_attribute(const rust::Str name, int defaultval);

float
get_float_attribute(const rust::Str name, float defaultval);

rust::String
get_string_attribute(const rust::Str name, const rust::Str defaultval);

// void
// declare_imageio_format(const rust::Str name,
//                        rust::Fn<ImageInput*(ImageInput*)> input_creator,
//                        const rust::Slice<const rust::Str> input_extensions,
//                        rust::Fn<ImageOutput*(ImageOutput*)> output_creator,
//                        const rust::Slice<const rust::Str> output_extensions,
//                        const rust::Str lib_version);

bool
is_imageio_format_name(const rust::Str name);

rust::Vec<ExtensionMapItem>
get_extension_map();

bool
convert_pixel_values(TypeDesc src_type, rust::Slice<const uint8_t> src,
                     TypeDesc dst_type, rust::Slice<uint8_t> dst);

bool
convert_image(int nchannels, int width, int height, int depth,
              rust::Slice<const uint8_t> src, TypeDesc src_type,
              int64_t src_xstride, int64_t src_ystride, int64_t src_zstride,
              rust::Slice<uint8_t> dst, TypeDesc dst_type, int64_t dst_xstride,
              int64_t dst_ystride, int64_t dst_zstride);

bool
parallel_convert_image(int nchannels, int width, int height, int depth,
                       rust::Slice<const uint8_t> src, TypeDesc src_type,
                       int64_t src_xstride, int64_t src_ystride,
                       int64_t src_zstride, rust::Slice<uint8_t> dst,
                       TypeDesc dst_type, int64_t dst_xstride,
                       int64_t dst_ystride, int64_t dst_zstride, int nthreads);

void
add_dither(int nchannels, int width, int height, int depth, float* data,
           int64_t xstride, int64_t ystride, int64_t zstride,
           float ditheramplitude, int alpha_channel, int z_channel,
           unsigned int ditherseed, int chorigin, int xorigin, int yorigin,
           int zorigin);

void
premult(int nchannels, int width, int height, int depth, int chbegin, int chend,
        TypeDesc datatype, rust::Slice<uint8_t> data, int64_t xstride,
        int64_t ystride, int64_t zstride, int alpha_channel, int z_channel);

bool
copy_image(int nchannels, int width, int height, int depth,
           rust::Slice<const uint8_t> src, int64_t pixelsize,
           int64_t src_xstride, int64_t src_ystride, int64_t src_zstride,
           rust::Slice<uint8_t> dst, int64_t dst_xstride, int64_t dst_ystride,
           int64_t dst_zstride);

bool
wrap_black(int& coord, int origin, int width);

bool
wrap_clamp(int& coord, int origin, int width);

bool
wrap_periodic(int& coord, int origin, int width);

bool
wrap_periodic_pow2(int& coord, int origin, int width);

bool
wrap_mirror(int& coord, int origin, int width);

void
debug(const rust::Str message);
#pragma endregion
}  // namespace oiio
