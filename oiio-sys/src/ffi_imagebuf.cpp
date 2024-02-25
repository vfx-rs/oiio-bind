#include "ffi_imagebuf.h"
#include "oiio-sys/src/imagebuf.rs.h"
#include <OpenImageIO/imagebuf.h>
#include <memory>
#include <stdexcept>
#include <stdio.h>

namespace oiio {
#pragma region ImageBuf
std::unique_ptr<ImageBuf>
imagebuf_default()
{
    return std::make_unique<ImageBuf>();
}

std::unique_ptr<ImageBuf>
imagebuf_new_from_file(rust::Str name, int subimage, int miplevel,
                       ImageCache* imagecache, const ImageSpec* config,
                       IOProxy* ioproxy)
{
    std::string_view c_name(name.data(), name.size());
    return std::make_unique<ImageBuf>(c_name, subimage, miplevel, imagecache,
                                      config, ioproxy);
}

std::unique_ptr<ImageBuf>
imagebuf_new_from_spec(const ImageSpec& spec, InitializePixels zero)
{
    return std::make_unique<ImageBuf>(spec, zero);
}

std::unique_ptr<ImageBuf>
imagebuf_new_from_buffer(const ImageSpec& spec, uint8_t* buffer,
                         int64_t xstride, int64_t ystride, int64_t zstride)
{
    return std::make_unique<ImageBuf>(spec, buffer, xstride, ystride, zstride);
}

std::unique_ptr<ImageBuf>
imagebuf_clone(const ImageBuf& imagebuf)
{
    return std::make_unique<ImageBuf>(imagebuf);
}

void
imagebuf_reset(ImageBuf& imagebuf)
{
    imagebuf.reset();
}

void
imagebuf_reset_from_file(ImageBuf& imagebuf, rust::Str name, int subimage,
                         int miplevel, ImageCache* imagecache,
                         const ImageSpec* config, IOProxy* ioproxy)
{
    std::string_view c_name(name.data(), name.size());
    imagebuf.reset(c_name, subimage, miplevel, imagecache, config, ioproxy);
}

void
imagebuf_reset_from_spec(ImageBuf& imagebuf, const ImageSpec& spec,
                         InitializePixels zero)
{
    imagebuf.reset(spec, zero);
}

void
imagebuf_reset_from_buffer(ImageBuf& imagebuf, const ImageSpec& spec,
                           uint8_t* buffer, int64_t xstride, int64_t ystride,
                           int64_t zstride)
{
    imagebuf.reset(spec, buffer, xstride, ystride, zstride);
}

bool
imagebuf_make_writeable(ImageBuf& imagebuf, bool keep_cache_type)
{
    return imagebuf.make_writeable(keep_cache_type);
}


bool
imagebuf_read(ImageBuf& imagebuf, int subimage, int miplevel, bool force,
              TypeDesc convert)
{
    return imagebuf.read(subimage, miplevel, force, convert);
}

bool
imagebuf_read_subset(ImageBuf& imagebuf, int subimage, int miplevel,
                     int chbegin, int chend, bool force, TypeDesc convert)
{
    return imagebuf.read(subimage, miplevel, chbegin, chend, force, convert);
}

bool
imagebuf_init_spec(ImageBuf& imagebuf, rust::Str filename, int subimage,
                   int miplevel)
{
    std::string_view c_filename(filename.data(), filename.size());
    return imagebuf.init_spec(c_filename, subimage, miplevel);
}

bool
imagebuf_write(ImageBuf& imagebuf, rust::Str filename, TypeDesc dtype,
               rust::Str fileformat)
{
    std::string_view c_filename(filename.data(), filename.size());
    std::string_view c_fileformat(fileformat.data(), fileformat.size());
    return imagebuf.write(c_filename, dtype, c_fileformat);
}

void
imagebuf_set_write_format(ImageBuf& imagebuf, TypeDesc format)
{
    imagebuf.set_write_format(format);
}

void
imagebuf_set_write_format_from_channel_names(ImageBuf& imagebuf,
                                             rust::Slice<const TypeDesc> format)
{
    OIIO::cspan<TypeDesc> c_format(format.data(), format.size());
    imagebuf.set_write_format(c_format);
}

void
imagebuf_set_write_tiles(ImageBuf& imagebuf, int width, int height, int depth)
{
    imagebuf.set_write_tiles(width, height, depth);
}

void
imagebuf_set_write_ioproxy(ImageBuf& imagebuf, IOProxy* ioproxy)
{
    imagebuf.set_write_ioproxy(ioproxy);
}

bool
imagebuf_write_to_imageoutput(ImageBuf& imagebuf, ImageOutput* out)
{
    return imagebuf.write(out);
}

void
imagebuf_copy_metadata(ImageBuf& imagebuf, const ImageBuf& src)
{
    imagebuf.copy_metadata(src);
}

bool
imagebuf_copy_pixels(ImageBuf& imagebuf, const ImageBuf& src)
{
    return imagebuf.copy_pixels(src);
}

bool
imagebuf_copy(ImageBuf& imagebuf, const ImageBuf& src, TypeDesc format)
{
    return imagebuf.copy(src, format);
}

std::unique_ptr<ImageBuf>
imagebuf_copy_to_imagebuf(const ImageBuf& imagebuf, TypeDesc format)
{
    return std::make_unique<ImageBuf>(imagebuf.copy(format));
}

void
imagebuf_swap(ImageBuf& imagebuf, ImageBuf& other)
{
    imagebuf.swap(other);
}

float
imagebuf_getchannel(const ImageBuf& imagebuf, int x, int y, int z, int c,
                    WrapMode wrap)
{
    return imagebuf.getchannel(x, y, z, c, wrap);
}

void
imagebuf_getpixel(const ImageBuf& imagebuf, int x, int y, int z, float* pixel,
                  int maxchannels, WrapMode wrap)
{
    imagebuf.getpixel(x, y, z, pixel, maxchannels, wrap);
}

void
imagebuf_interppixel(const ImageBuf& imagebuf, float x, float y, float* pixel,
                     WrapMode wrap)
{
    imagebuf.interppixel(x, y, pixel, wrap);
}

void
imagebuf_interppixel_NDC(const ImageBuf& imagebuf, float s, float t,
                         float* pixel, WrapMode wrap)
{
    imagebuf.interppixel(s, t, pixel, wrap);
}

void
imagebuf_interppixel_bicubic(const ImageBuf& imagebuf, float x, float y,
                             float* pixel, WrapMode wrap)
{
    imagebuf.interppixel_bicubic(x, y, pixel, wrap);
}

void
imagebuf_interppixel_bicubic_NDC(const ImageBuf& imagebuf, float s, float t,
                                 float* pixel, WrapMode wrap)
{
    imagebuf.interppixel_bicubic(s, t, pixel, wrap);
}

void
imagebuf_setpixel(ImageBuf& imagebuf, int x, int y, int z,
                  rust::Slice<const float> pixel)
{
    OIIO::cspan<float> c_pixel(pixel.data(), pixel.size());
    imagebuf.setpixel(x, y, z, c_pixel);
}

void
imagebuf_setpixel_i(ImageBuf& imagebuf, int i, rust::Slice<const float> pixel)
{
    OIIO::cspan<float> c_pixel(pixel.data(), pixel.size());
    imagebuf.setpixel(i, c_pixel);
}

void
imagebuf_setpixel_with_coordinates(ImageBuf& imagebuf, int x, int y, int z,
                                   const float* pixel, int maxchannels)
{
    imagebuf.setpixel(x, y, z, pixel, maxchannels);
}

bool
imagebuf_get_pixels(const ImageBuf& imagebuf, const ROI& roi, TypeDesc format,
                    uint8_t* result, int64_t xstride, int64_t ystride,
                    int64_t zstride)
{
    return imagebuf.get_pixels(roi, format, result, xstride, ystride, zstride);
}

bool
imagebuf_set_pixels(ImageBuf& imagebuf, const ROI& roi, TypeDesc format,
                    const uint8_t* data, int64_t xstride, int64_t ystride,
                    int64_t zstride)
{
    return imagebuf.set_pixels(roi, format, data, xstride, ystride, zstride);
}

bool
imagebuf_initialized(const ImageBuf& imagebuf)
{
    return imagebuf.initialized();
}

IBStorage
imagebuf_storage(const ImageBuf& imagebuf)
{
    return imagebuf.storage();
}

const ImageSpec&
imagebuf_spec(const ImageBuf& imagebuf)
{
    return imagebuf.spec();
}

ImageSpec&
imagebuf_specmod(ImageBuf& imagebuf)
{
    return imagebuf.specmod();
}

const ImageSpec&
imagebuf_nativespec(const ImageBuf& imagebuf)
{
    return imagebuf.nativespec();
}

bool
imagebuf_has_thumbnail(const ImageBuf& imagebuf)
{
    return imagebuf.has_thumbnail();
}

std::shared_ptr<ImageBuf>
imagebuf_get_thumbnail(const ImageBuf& imagebuf)
{
    return imagebuf.get_thumbnail();
}

void
imagebuf_set_thumbnail(ImageBuf& imagebuf, const ImageBuf& thumb)
{
    imagebuf.set_thumbnail(thumb);
}

void
imagebuf_clear_thumbnail(ImageBuf& imagebuf)
{
    imagebuf.clear_thumbnail();
}

rust::Str
imagebuf_name(const ImageBuf& imagebuf)
{
    return rust::Str(imagebuf.name());
}

rust::Str
imagebuf_file_format_name(const ImageBuf& imagebuf)
{
    return rust::Str(imagebuf.file_format_name());
}

int
imagebuf_subimage(const ImageBuf& imagebuf)
{
    return imagebuf.subimage();
}

int
imagebuf_nsubimages(const ImageBuf& imagebuf)
{
    return imagebuf.nsubimages();
}

int
imagebuf_miplevel(const ImageBuf& imagebuf)
{
    return imagebuf.miplevel();
}

int
imagebuf_nmiplevels(const ImageBuf& imagebuf)
{
    return imagebuf.nmiplevels();
}

int
imagebuf_nchannels(const ImageBuf& imagebuf)
{
    return imagebuf.nchannels();
}

int
imagebuf_xbegin(const ImageBuf& imagebuf)
{
    return imagebuf.xbegin();
}

int
imagebuf_ybegin(const ImageBuf& imagebuf)
{
    return imagebuf.ybegin();
}

int
imagebuf_zbegin(const ImageBuf& imagebuf)
{
    return imagebuf.zbegin();
}

int
imagebuf_xend(const ImageBuf& imagebuf)
{
    return imagebuf.xend();
}

int
imagebuf_yend(const ImageBuf& imagebuf)
{
    return imagebuf.yend();
}

int
imagebuf_zend(const ImageBuf& imagebuf)
{
    return imagebuf.zend();
}

int
imagebuf_xmin(const ImageBuf& imagebuf)
{
    return imagebuf.xmin();
}

int
imagebuf_ymin(const ImageBuf& imagebuf)
{
    return imagebuf.ymin();
}

int
imagebuf_zmin(const ImageBuf& imagebuf)
{
    return imagebuf.zmin();
}

int
imagebuf_xmax(const ImageBuf& imagebuf)
{
    return imagebuf.xmax();
}

int
imagebuf_ymax(const ImageBuf& imagebuf)
{
    return imagebuf.ymax();
}

int
imagebuf_zmax(const ImageBuf& imagebuf)
{
    return imagebuf.zmax();
}

int
imagebuf_orientation(const ImageBuf& imagebuf)
{
    return imagebuf.orientation();
}

void
imagebuf_set_orientation(ImageBuf& imagebuf, int orient)
{
    imagebuf.set_orientation(orient);
}

int
imagebuf_oriented_width(const ImageBuf& imagebuf)
{
    return imagebuf.oriented_width();
}

int
imagebuf_oriented_height(const ImageBuf& imagebuf)
{
    return imagebuf.oriented_height();
}

int
imagebuf_oriented_x(const ImageBuf& imagebuf)
{
    return imagebuf.oriented_x();
}

int
imagebuf_oriented_y(const ImageBuf& imagebuf)
{
    return imagebuf.oriented_y();
}

int
imagebuf_oriented_full_width(const ImageBuf& imagebuf)
{
    return imagebuf.oriented_full_width();
}

int
imagebuf_oriented_full_height(const ImageBuf& imagebuf)
{
    return imagebuf.oriented_full_height();
}

int
imagebuf_oriented_full_x(const ImageBuf& imagebuf)
{
    return imagebuf.oriented_full_x();
}

int
imagebuf_oriented_full_y(const ImageBuf& imagebuf)
{
    return imagebuf.oriented_full_y();
}

void
imagebuf_set_origin(ImageBuf& imagebuf, int x, int y, int z)
{
    imagebuf.set_origin(x, y, z);
}

void
imagebuf_set_full(ImageBuf& imagebuf, int xbegin, int xend, int ybegin,
                  int yend, int zbegin, int zend)
{
    imagebuf.set_full(xbegin, xend, ybegin, yend, zbegin, zend);
}

ROI
imagebuf_roi(const ImageBuf& imagebuf)
{
    return imagebuf.roi();
}

ROI
imagebuf_roi_full(const ImageBuf& imagebuf)
{
    return imagebuf.roi_full();
}

void
imagebuf_set_roi_full(ImageBuf& imagebuf, const ROI& newroi)
{
    imagebuf.set_roi_full(newroi);
}

bool
imagebuf_contains_roi(const ImageBuf& imagebuf, ROI roi)
{
    return imagebuf.contains_roi(roi);
}

bool
imagebuf_pixels_valid(const ImageBuf& imagebuf)
{
    return imagebuf.pixels_valid();
}

TypeDesc
imagebuf_pixeltype(const ImageBuf& imagebuf)
{
    return imagebuf.pixeltype();
}

uint8_t*
imagebuf_localpixels_mut(ImageBuf& imagebuf)
{
    return (uint8_t*)(imagebuf.localpixels());
}

const uint8_t*
imagebuf_localpixels(const ImageBuf& imagebuf)
{
    return (const uint8_t*)(imagebuf.localpixels());
}


int64_t
imagebuf_pixel_stride(const ImageBuf& imagebuf)
{
    return imagebuf.pixel_stride();
}

int64_t
imagebuf_scanline_stride(const ImageBuf& imagebuf)
{
    return imagebuf.scanline_stride();
}

int64_t
imagebuf_z_stride(const ImageBuf& imagebuf)
{
    return imagebuf.z_stride();
}

bool
imagebuf_contiguous(const ImageBuf& imagebuf)
{
    return imagebuf.contiguous();
}

bool
imagebuf_cachedpixels(const ImageBuf& imagebuf)
{
    return imagebuf.cachedpixels();
}

ImageCache*
imagebuf_imagecache(const ImageBuf& imagebuf)
{
    return imagebuf.imagecache();
}

const uint8_t*
imagebuf_pixeladdr(const ImageBuf& imagebuf, int x, int y, int z, int ch)
{
    return (const uint8_t*)(imagebuf.pixeladdr(x, y, z, ch));
}

uint8_t*
imagebuf_pixeladdr_mut(const ImageBuf& imagebuf, int x, int y, int z, int ch)
{
    return (uint8_t*)(imagebuf.pixeladdr(x, y, z, ch));
}

int
imagebuf_pixelindex(const ImageBuf& imagebuf, int x, int y, int z,
                    bool check_range)
{
    return imagebuf.pixelindex(x, y, z, check_range);
}

void
imagebuf_set_threads(const ImageBuf& imagebuf, int n)
{
    imagebuf.threads(n);
}

int
imagebuf_threads(const ImageBuf& imagebuf)
{
    return imagebuf.threads();
}

void
imagebuf_error(const ImageBuf& imagebuf, rust::Str message)
{
    std::string_view c_message(message.data(), message.size());
    imagebuf.error(c_message);
}

bool
imagebuf_has_error(const ImageBuf& imagebuf)
{
    return imagebuf.has_error();
}

rust::String
imagebuf_geterror(const ImageBuf& imagebuf, bool clear)
{
    return rust::String(imagebuf.geterror(clear));
}

bool
imagebuf_deep(const ImageBuf& imagebuf)
{
    return imagebuf.deep();
}

int
imagebuf_deep_samples(const ImageBuf& imagebuf, int x, int y, int z)
{
    return imagebuf.deep_samples(x, y, z);
}

const uint8_t*
imagebuf_deep_pixel_ptr(const ImageBuf& imagebuf, int x, int y, int z, int c,
                        int s)
{
    return (const uint8_t*)(imagebuf.deep_pixel_ptr(x, y, z, c, s));
}

float
imagebuf_deep_value(const ImageBuf& imagebuf, int x, int y, int z, int c, int s)
{
    return imagebuf.deep_value(x, y, z, c, s);
}

uint32_t
imagebuf_deep_value_uint(const ImageBuf& imagebuf, int x, int y, int z, int c,
                         int s)
{
    return imagebuf.deep_value_uint(x, y, z, c, s);
}

void
imagebuf_set_deep_samples(ImageBuf& imagebuf, int x, int y, int z, int nsamples)
{
    imagebuf.set_deep_samples(x, y, z, nsamples);
}

void
imagebuf_deep_insert_samples(ImageBuf& imagebuf, int x, int y, int z,
                             int samplepos, int nsamples)
{
    imagebuf.deep_insert_samples(x, y, z, samplepos, nsamples);
}

void
imagebuf_deep_erase_samples(ImageBuf& imagebuf, int x, int y, int z,
                            int samplepos, int nsamples)
{
    imagebuf.deep_erase_samples(x, y, z, samplepos, nsamples);
}

void
imagebuf_set_deep_value(ImageBuf& imagebuf, int x, int y, int z, int c, int s,
                        float value)
{
    imagebuf.set_deep_value(x, y, z, c, s, value);
}

void
imagebuf_set_deep_value_uint(ImageBuf& imagebuf, int x, int y, int z, int c,
                             int s, uint32_t value)
{
    imagebuf.set_deep_value(x, y, z, c, s, value);
}

bool
imagebuf_copy_deep_pixel(ImageBuf& imagebuf, int x, int y, int z,
                         const ImageBuf& src, int srcx, int srcy, int srcz)
{
    return imagebuf.copy_deep_pixel(x, y, z, src, srcx, srcy, srcz);
}

DeepData*
imagebuf_deepdata_mut(ImageBuf& imagebuf)
{
    return imagebuf.deepdata();
}

const DeepData*
imagebuf_deepdata(const ImageBuf& imagebuf)
{
    return imagebuf.deepdata();
}

void
imagebuf_lock(const ImageBuf& imagebuf)
{
    imagebuf.lock();
}

void
imagebuf_unlock(const ImageBuf& imagebuf)
{
    imagebuf.unlock();
}

WrapMode
wrapmode_from_string(rust::Str name)
{
    std::string_view c_name(name.data(), name.size());
    return OIIO::ImageBuf::WrapMode_from_string(c_name);
}

#pragma endregion ImageBuf

#pragma region ImageBuf::IteratorBase

int
imagebuf_iterator_x(const ImageBufIteratorBase& iterator)
{
    return iterator.x();
}

int
imagebuf_iterator_y(const ImageBufIteratorBase& iterator)
{
    return iterator.y();
}

int
imagebuf_iterator_z(const ImageBufIteratorBase& iterator)
{
    return iterator.z();
}

bool
imagebuf_iterator_valid(const ImageBufIteratorBase& iterator)
{
    return iterator.valid();
}

bool
imagebuf_iterator_valid_coordianates(const ImageBufIteratorBase& iterator,
                                     int x, int y, int z)
{
    return iterator.valid(x, y, z);
}

bool
imagebuf_iterator_exists(const ImageBufIteratorBase& iterator)
{
    return iterator.exists();
}

bool
imagebuf_iterator_done(const ImageBufIteratorBase& iterator)
{
    return iterator.done();
}

int
imagebuf_iterator_deep_samples(const ImageBufIteratorBase& iterator)
{
    return iterator.deep_samples();
}

WrapMode
imagebuf_iterator_wrap(const ImageBufIteratorBase& iterator)
{
    return iterator.wrap();
}

void
imagebuf_iterator_pos(ImageBufIteratorBase& iterator, int x, int y, int z)
{
    iterator.pos(x, y, z);
}

void
imagebuf_iterator_next(ImageBufIteratorBase& iterator)
{
    iterator++;
}

ROI
imagebuf_iterator_range(const ImageBufIteratorBase& iterator)
{
    return iterator.range();
}

void
imagebuf_iterator_rerange(ImageBufIteratorBase& iterator, int xbegin, int xend,
                          int ybegin, int yend, int zbegin, int zend,
                          WrapMode wrap)
{
    iterator.rerange(xbegin, xend, ybegin, yend, zbegin, zend, wrap);
}

const uint8_t*
imagebuf_iterator_rawptr(const ImageBufIteratorBase& iterator)
{
    return (const uint8_t*)(iterator.rawptr());
}

float
imagebuf_iterator_deep_value(const ImageBufIteratorBase& iterator, int c, int s)
{
    return iterator.deep_value(c, s);
}

uint32_t
imagebuf_iterator_deep_value_uint(const ImageBufIteratorBase& iterator, int c,
                                  int s)
{
    return iterator.deep_value_uint(c, s);
}

bool
imagebuf_iterator_localpixels(const ImageBufIteratorBase& iterator)
{
    return iterator.localpixels();
}

bool
imagebuf_iterator_has_error(const ImageBufIteratorBase& iterator)
{
    return iterator.has_error();
}

void
imagebuf_iterator_clear_error(ImageBufIteratorBase& iterator)
{
    iterator.clear_error();
}
#pragma endregion ImageBuf::IteratorBase
}  // namespace oiio
