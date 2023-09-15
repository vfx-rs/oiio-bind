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
using DeepData   = OIIO::DeepData;
using ImageInput = OIIO::ImageInput;
using ImageSpec  = OIIO::ImageSpec;
using IOProxy    = OIIO::Filesystem::IOProxy;
using ROI        = OIIO::ROI;
using TypeDesc   = OIIO::TypeDesc;

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

std::unique_ptr<ImageSpec>
imageinput_open_newspec_with_config(ImageInput& imageinput,
                                    const rust::Str filename,
                                    const ImageSpec& config);

std::unique_ptr<ImageSpec>
imageinput_open_newspec_without_config(ImageInput& imageinput,
                                       const rust::Str filename);

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

std::unique_ptr<ImageSpec>
imageinput_spec(const ImageInput& imageinput);

std::unique_ptr<ImageSpec>
imageinput_spec_subimage_miplevel(ImageInput& imageinput, int32_t subimage,
                                  int32_t miplevel);

std::unique_ptr<ImageSpec>
imageinput_spec_dimensions(ImageInput& imageinput, int32_t subimage,
                           int32_t miplevel);

void
imageinput_close(ImageInput& imageinput);

int
imageinput_current_subimage(const ImageInput& imageinput);

int
imageinput_current_miplevel(const ImageInput& imageinput);

bool
imageinput_seek_subimage(ImageInput& imageinput, int subimage, int miplevel);

bool
imageinput_read_scanline(ImageInput& imageinput, int y, int z,
                         const TypeDesc& format, rust::Slice<uint8_t> data,
                         int64_t xstride);

bool
imageinput_read_scanlines(ImageInput& imageinput, int subimage, int miplevel,
                          int ybegin, int yend, int z, int chbegin, int chend,
                          const TypeDesc& format, rust::Slice<uint8_t> data,
                          int64_t xstride, int64_t ystride);

bool
imageinput_read_tile(ImageInput& imageinput, int x, int y, int z,
                     const TypeDesc& format, rust::Slice<uint8_t> data,
                     int64_t xstride, int64_t ystride, int64_t zstride);

bool
imageinput_read_scanlines(ImageInput& imageinput, int subimage, int miplevel,
                          int ybegin, int yend, int zbegin, int zend,
                          int chbegin, int chend, const TypeDesc& format,
                          rust::Slice<uint8_t> data, int64_t xstride,
                          int64_t ystride, int64_t zstride);

bool
imageinput_read_image(ImageInput& imageinput, int subimage, int miplevel,
                      int chbegin, int chend, const TypeDesc& format,
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
imageinput_set_threads(ImageInput& imageinput, int n);

int
imageinput_threads(const ImageInput& imageinput);
#pragma endregion
}  // namespace oiio
