#pragma once

#include <OpenImageIO/imagebuf.h>
#include <OpenImageIO/imageio.h>
#include <memory>
#include <rust/cxx.h>
#include <string>
#include <string_view>
#include <vector>

namespace oiio {
using DeepData             = OIIO::DeepData;
using IBStorage            = OIIO::ImageBuf::IBStorage;
using ImageBuf             = OIIO::ImageBuf;
using ImageCache           = OIIO::ImageCache;
using ImageOutput          = OIIO::ImageOutput;
using ImageSpec            = OIIO::ImageSpec;
using InitializePixels     = OIIO::InitializePixels;
using IOProxy              = OIIO::Filesystem::IOProxy;
using ImageBufIteratorBase = OIIO::ImageBuf::IteratorBase;
using ROI                  = OIIO::ROI;
using TypeDesc             = OIIO::TypeDesc;
using WrapMode             = OIIO::ImageBuf::WrapMode;

#pragma region ImageBuf
std::unique_ptr<ImageBuf>
imagebuf_default();

std::unique_ptr<ImageBuf>
imagebuf_new_from_file(rust::Str name, int subimage, int miplevel,
                       ImageCache* imagecache, const ImageSpec* config,
                       IOProxy* ioproxy);

std::unique_ptr<ImageBuf>
imagebuf_new_from_spec(const ImageSpec& spec, InitializePixels zero);

std::unique_ptr<ImageBuf>
imagebuf_new_from_buffer(const ImageSpec& spec, uint8_t* buffer,
                         int64_t xstride, int64_t ystride, int64_t zstride);

std::unique_ptr<ImageBuf>
imagebuf_clone(const ImageBuf& imagebuf);

void
imagebuf_reset(ImageBuf& imagebuf);

void
imagebuf_reset_from_file(ImageBuf& imagebuf, rust::Str name, int subimage,
                         int miplevel, ImageCache* imagecache,
                         const ImageSpec* config, IOProxy* ioproxy);

void
imagebuf_reset_from_spec(ImageBuf& imagebuf, const ImageSpec& spec,
                         InitializePixels zero);

void
imagebuf_reset_from_buffer(ImageBuf& imagebuf, const ImageSpec& spec,
                           uint8_t* buffer, int64_t xstride, int64_t ystride,
                           int64_t zstride);

bool
imagebuf_make_writeable(ImageBuf& imagebuf, bool keep_cache_type);


bool
imagebuf_read(ImageBuf& imagebuf, int subimage, int miplevel, bool force,
              TypeDesc convert);

bool
imagebuf_read_subset(ImageBuf& imagebuf, int subimage, int miplevel,
                     int chbegin, int chend, bool force, TypeDesc convert);

bool
imagebuf_init_spec(ImageBuf& imagebuf, rust::Str filename, int subimage,
                   int miplevel);

bool
imagebuf_write(ImageBuf& imagebuf, rust::Str filename, TypeDesc dtype,
               rust::Str fileformat);

void
imagebuf_set_write_format(ImageBuf& imagebuf, TypeDesc format);

void
imagebuf_set_write_format_from_channel_names(ImageBuf& imagebuf,
                                             rust::Slice<const TypeDesc> format);

void
imagebuf_set_write_tiles(ImageBuf& imagebuf, int width, int height, int depth);

void
imagebuf_set_write_ioproxy(ImageBuf& imagebuf, IOProxy* ioproxy);

bool
imagebuf_write_to_imageoutput(ImageBuf& imagebuf, ImageOutput* out);

void
imagebuf_copy_metadata(ImageBuf& imagebuf, const ImageBuf& src);

bool
imagebuf_copy_pixels(ImageBuf& imagebuf, const ImageBuf& src);

bool
imagebuf_copy(ImageBuf& imagebuf, const ImageBuf& src, TypeDesc format);

std::unique_ptr<ImageBuf>
imagebuf_copy_to_imagebuf(const ImageBuf& imagebuf, TypeDesc format);

void
imagebuf_swap(ImageBuf& imagebuf, ImageBuf& other);

float
imagebuf_getchannel(const ImageBuf& imagebuf, int x, int y, int z, int c,
                    WrapMode wrap);

void
imagebuf_getpixel(const ImageBuf& imagebuf, int x, int y, int z, float* pixel,
                  int maxchannels, WrapMode wrap);

void
imagebuf_interppixel(const ImageBuf& imagebuf, float x, float y, float* pixel,
                     WrapMode wrap);

void
imagebuf_interppixel_NDC(const ImageBuf& imagebuf, float s, float t,
                         float* pixel, WrapMode wrap);

void
imagebuf_interppixel_bicubic(const ImageBuf& imagebuf, float x, float y,
                             float* pixel, WrapMode wrap);

void
imagebuf_interppixel_bicubic_NDC(const ImageBuf& imagebuf, float s, float t,
                                 float* pixel, WrapMode wrap);

void
imagebuf_setpixel(ImageBuf& imagebuf, int x, int y, int z,
                  rust::Slice<const float> pixel);

void
imagebuf_setpixel_i(ImageBuf& imagebuf, int i, rust::Slice<const float> pixel);

void
imagebuf_setpixel_with_coordinates(ImageBuf& imagebuf, int x, int y, int z,
                                   const float* pixel, int maxchannels);

bool
imagebuf_get_pixels(const ImageBuf& imagebuf, ROI roi, TypeDesc format,
                    uint8_t* result, int64_t xstride, int64_t ystride,
                    int64_t zstride);

bool
imagebuf_set_pixels(ImageBuf& imagebuf, ROI roi, TypeDesc format,
                    const uint8_t* data, int64_t xstride, int64_t ystride,
                    int64_t zstride);

bool
imagebuf_initialized(const ImageBuf& imagebuf);

IBStorage
imagebuf_storage(const ImageBuf& imagebuf);

const ImageSpec&
imagebuf_spec(const ImageBuf& imagebuf);

ImageSpec&
imagebuf_specmod(ImageBuf& imagebuf);

const ImageSpec&
imagebuf_nativespec(const ImageBuf& imagebuf);

bool
imagebuf_has_thumbnail(const ImageBuf& imagebuf);

std::shared_ptr<ImageBuf>
imagebuf_get_thumbnail(const ImageBuf& imagebuf);

void
imagebuf_set_thumbnail(ImageBuf& imagebuf, const ImageBuf& thumb);

void
imagebuf_clear_thumbnail(ImageBuf& imagebuf);

rust::Str
imagebuf_name(const ImageBuf& imagebuf);

rust::Str
imagebuf_file_format_name(const ImageBuf& imagebuf);

int
imagebuf_subimage(const ImageBuf& imagebuf);

int
imagebuf_nsubimages(const ImageBuf& imagebuf);

int
imagebuf_miplevel(const ImageBuf& imagebuf);

int
imagebuf_nmiplevels(const ImageBuf& imagebuf);

int
imagebuf_nchannels(const ImageBuf& imagebuf);

int
imagebuf_xbegin(const ImageBuf& imagebuf);

int
imagebuf_ybegin(const ImageBuf& imagebuf);

int
imagebuf_zbegin(const ImageBuf& imagebuf);

int
imagebuf_xend(const ImageBuf& imagebuf);

int
imagebuf_yend(const ImageBuf& imagebuf);

int
imagebuf_zend(const ImageBuf& imagebuf);

int
imagebuf_xmin(const ImageBuf& imagebuf);

int
imagebuf_ymin(const ImageBuf& imagebuf);

int
imagebuf_zmin(const ImageBuf& imagebuf);

int
imagebuf_xmax(const ImageBuf& imagebuf);

int
imagebuf_ymax(const ImageBuf& imagebuf);

int
imagebuf_zmax(const ImageBuf& imagebuf);

int
imagebuf_orientation(const ImageBuf& imagebuf);

void
imagebuf_set_orientation(ImageBuf& imagebuf, int orient);

int
imagebuf_oriented_width(const ImageBuf& imagebuf);

int
imagebuf_oriented_height(const ImageBuf& imagebuf);

int
imagebuf_oriented_x(const ImageBuf& imagebuf);

int
imagebuf_oriented_y(const ImageBuf& imagebuf);

int
imagebuf_oriented_full_width(const ImageBuf& imagebuf);

int
imagebuf_oriented_full_height(const ImageBuf& imagebuf);

int
imagebuf_oriented_full_x(const ImageBuf& imagebuf);

int
imagebuf_oriented_full_y(const ImageBuf& imagebuf);

void
imagebuf_set_origin(ImageBuf& imagebuf, int x, int y, int z);

void
imagebuf_set_full(ImageBuf& imagebuf, int xbegin, int xend, int ybegin,
                  int yend, int zbegin, int zend);

ROI
imagebuf_roi(const ImageBuf& imagebuf);

ROI
imagebuf_roi_full(const ImageBuf& imagebuf);

void
imagebuf_set_roi_full(ImageBuf& imagebuf, const ROI& newroi);

bool
imagebuf_contains_roi(const ImageBuf& imagebuf, ROI roi);

bool
imagebuf_pixels_valid(const ImageBuf& imagebuf);

TypeDesc
imagebuf_pixeltype(const ImageBuf& imagebuf);

uint8_t*
imagebuf_localpixels_mut(ImageBuf& imagebuf);

const uint8_t*
imagebuf_localpixels(const ImageBuf& imagebuf);


int64_t
imagebuf_pixel_stride(const ImageBuf& imagebuf);

int64_t
imagebuf_scanline_stride(const ImageBuf& imagebuf);

int64_t
imagebuf_z_stride(const ImageBuf& imagebuf);

bool
imagebuf_contiguous(const ImageBuf& imagebuf);

bool
imagebuf_cachedpixels(const ImageBuf& imagebuf);

ImageCache*
imagebuf_imagecache(const ImageBuf& imagebuf);

const uint8_t*
imagebuf_pixeladdr(const ImageBuf& imagebuf, int x, int y, int z, int ch);

uint8_t*
imagebuf_pixeladdr_mut(const ImageBuf& imagebuf, int x, int y, int z, int ch);

int
imagebuf_pixelindex(const ImageBuf& imagebuf, int x, int y, int z,
                    bool check_range);

void
imagebuf_set_threads(const ImageBuf& imagebuf, int n);

int
imagebuf_threads(const ImageBuf& imagebuf);

void
imagebuf_error(const ImageBuf& imagebuf, rust::Str message);

bool
imagebuf_has_error(const ImageBuf& imagebuf);

rust::String
imagebuf_geterror(const ImageBuf& imagebuf, bool clear);

bool
imagebuf_deep(const ImageBuf& imagebuf);

int
imagebuf_deep_samples(const ImageBuf& imagebuf, int x, int y, int z);

const uint8_t*
imagebuf_deep_pixel_ptr(const ImageBuf& imagebuf, int x, int y, int z, int c,
                        int s);

float
imagebuf_deep_value(const ImageBuf& imagebuf, int x, int y, int z, int c,
                    int s);

uint32_t
imagebuf_deep_value_uint(const ImageBuf& imagebuf, int x, int y, int z, int c,
                         int s);

void
imagebuf_set_deep_samples(ImageBuf& imagebuf, int x, int y, int z,
                          int nsamples);

void
imagebuf_deep_insert_samples(ImageBuf& imagebuf, int x, int y, int z,
                             int samplepos, int nsamples);

void
imagebuf_deep_erase_samples(ImageBuf& imagebuf, int x, int y, int z,
                            int samplepos, int nsamples);

void
imagebuf_set_deep_value(ImageBuf& imagebuf, int x, int y, int z, int c, int s,
                        float value);

void
imagebuf_set_deep_value_uint(ImageBuf& imagebuf, int x, int y, int z, int c,
                             int s, uint32_t value);

bool
imagebuf_copy_deep_pixel(ImageBuf& imagebuf, int x, int y, int z,
                         const ImageBuf& src, int srcx, int srcy, int srcz);

DeepData*
imagebuf_deepdata_mut(ImageBuf& imagebuf);

const DeepData*
imagebuf_deepdata(const ImageBuf& imagebuf);

void
imagebuf_lock(const ImageBuf& imagebuf);

void
imagebuf_unlock(const ImageBuf& imagebuf);

WrapMode
wrapmode_from_string(rust::Str name);

#pragma endregion ImageBuf

#pragma region ImageBuf::IteratorBase

int
imagebuf_iterator_x(const ImageBufIteratorBase& iterator);

int
imagebuf_iterator_y(const ImageBufIteratorBase& iterator);

int
imagebuf_iterator_z(const ImageBufIteratorBase& iterator);

bool
imagebuf_iterator_valid(const ImageBufIteratorBase& iterator);

bool
imagebuf_iterator_valid_coordianates(const ImageBufIteratorBase& iterator,
                                     int x, int y, int z);

bool
imagebuf_iterator_exists(const ImageBufIteratorBase& iterator);

bool
imagebuf_iterator_done(const ImageBufIteratorBase& iterator);

int
imagebuf_iterator_deep_samples(const ImageBufIteratorBase& iterator);

WrapMode
imagebuf_iterator_wrap(const ImageBufIteratorBase& iterator);

void
imagebuf_iterator_pos(ImageBufIteratorBase& iterator, int x, int y, int z);

void
imagebuf_iterator_next(ImageBufIteratorBase& iterator);

ROI
imagebuf_iterator_range(const ImageBufIteratorBase& iterator);

void
imagebuf_iterator_rerange(ImageBufIteratorBase& iterator, int xbegin, int xend,
                          int ybegin, int yend, int zbegin, int zend,
                          WrapMode wrap);

const uint8_t*
imagebuf_iterator_rawptr(const ImageBufIteratorBase& iterator);

float
imagebuf_iterator_deep_value(const ImageBufIteratorBase& iterator, int c,
                             int s);

uint32_t
imagebuf_iterator_deep_value_uint(const ImageBufIteratorBase& iterator, int c,
                                  int s);

bool
imagebuf_iterator_localpixels(const ImageBufIteratorBase& iterator);

bool
imagebuf_iterator_has_error(const ImageBufIteratorBase& iterator);

void
imagebuf_iterator_clear_error(ImageBufIteratorBase& iterator);
#pragma endregion ImageBuf::IteratorBase
}  // namespace oiio
