#include "ffi_imagecache.h"

namespace oiio {
ImageCache*
imagecache_create(bool shared)
{
    return OIIO::ImageCache::create(shared);
}

void
imagecache_destroy(ImageCache* imagecache, bool teardown)
{
    OIIO::ImageCache::destroy(imagecache, teardown);
}

bool
imagecache_attribute(ImageCache& imagecache, rust::Str name, TypeDesc type,
                     const uint8_t* val)
{
    std::string_view c_name(name.data(), name.size());
    return imagecache.attribute(c_name, type, val);
}

bool
imagecache_attribute_int(ImageCache& imagecache, rust::Str name, int val)
{
    std::string_view c_name(name.data(), name.size());
    return imagecache.attribute(c_name, val);
}

bool
imagecache_attribute_float(ImageCache& imagecache, rust::Str name, float val)
{
    std::string_view c_name(name.data(), name.size());
    return imagecache.attribute(c_name, val);
}

bool
imagecache_attribute_double(ImageCache& imagecache, rust::Str name, double val)
{
    std::string_view c_name(name.data(), name.size());
    return imagecache.attribute(c_name, val);
}

bool
imagecache_attribute_str(ImageCache& imagecache, rust::Str name, rust::Str val)
{
    std::string_view c_name(name.data(), name.size());
    std::string_view c_val(val.data(), val.size());
    return imagecache.attribute(c_name, c_val);
}

bool
imagecache_getattribute(ImageCache& imagecache, rust::Str name, TypeDesc type,
                        const uint8_t* val)
{
    std::string_view c_name(name.data(), name.size());
    return imagecache.getattribute(c_name, type, (void*)val);
}

bool
imagecache_getattribute_int(ImageCache& imagecache, rust::Str name, int& val)
{
    std::string_view c_name(name.data(), name.size());
    return imagecache.getattribute(c_name, val);
}

bool
imagecache_getattribute_float(ImageCache& imagecache, rust::Str name,
                              float& val)
{
    std::string_view c_name(name.data(), name.size());
    return imagecache.getattribute(c_name, val);
}

bool
imagecache_getattribute_double(ImageCache& imagecache, rust::Str name,
                               double& val)
{
    std::string_view c_name(name.data(), name.size());
    return imagecache.getattribute(c_name, val);
}

bool
imagecache_getattribute_string(ImageCache& imagecache, rust::Str name,
                               std::string& val)
{
    std::string_view c_name(name.data(), name.size());
    return imagecache.getattribute(c_name, val);
}

TypeDesc
imagecache_getattributetype(ImageCache& imagecache, rust::Str name)
{
    std::string_view c_name(name.data(), name.size());
    return imagecache.getattributetype(c_name);
}

Perthread*
imagecache_get_perthread_info(ImageCache& imagecache, Perthread* thread_info)
{
    return imagecache.get_perthread_info(thread_info);
}

Perthread*
imagecache_create_thread_info(ImageCache& imagecache)
{
    return imagecache.create_thread_info();
}

void
imagecache_destroy_thread_info(ImageCache& imagecache, Perthread* thread_info)
{
    imagecache.destroy_thread_info(thread_info);
}

ImageHandle*
imagecache_get_image_handle(ImageCache& imagecache, rust::Str filename,
                            Perthread* thread_info, const TextureOpt* options)
{
    OIIO::ustring c_filename(filename.data(), filename.size());
    return imagecache.get_image_handle(c_filename, thread_info, options);
}

bool
imagecache_good(ImageCache& imagecache, ImageHandle* file)
{
    return imagecache.good(file);
}

rust::String
imagecache_filename_from_handle(ImageCache& imagecache, ImageHandle* handle)
{
    return rust::String(imagecache.filename_from_handle(handle).c_str());
}

bool
imagecache_get_image_info(ImageCache& imagecache, rust::Str filename,
                          int subimage, int miplevel, rust::Str dataname,
                          TypeDesc datatype, const uint8_t* data)
{
    OIIO::ustring c_filename(filename.data(), filename.size());
    OIIO::ustring c_dataname(dataname.data(), dataname.size());
    return imagecache.get_image_info(c_filename, subimage, miplevel, c_dataname,
                                     datatype, (void*)data);
}

bool
imagecache_get_image_info_with_handle(ImageCache& imagecache, ImageHandle* file,
                                      Perthread* thread_info, int subimage,
                                      int miplevel, rust::Str dataname,
                                      TypeDesc datatype, const uint8_t* data)
{
    OIIO::ustring c_dataname(dataname.data(), dataname.size());
    return imagecache.get_image_info(file, thread_info, subimage, miplevel,
                                     c_dataname, datatype, (void*)data);
}

bool
imagecache_get_imagespec(ImageCache& imagecache, rust::Str filename,
                         ImageSpec& spec, int subimage, int miplevel,
                         bool native)
{
    OIIO::ustring c_filename(filename.data(), filename.size());
    return imagecache.get_imagespec(c_filename, spec, subimage, miplevel,
                                    native);
}

bool
imagecache_get_imagespec_with_handle(ImageCache& imagecache, ImageHandle* file,
                                     Perthread* thread_info, ImageSpec& spec,
                                     int subimage, int miplevel, bool native)
{
    return imagecache.get_imagespec(file, thread_info, spec, subimage, miplevel,
                                    native);
}

const ImageSpec*
imagecache_imagespec(ImageCache& imagecache, rust::Str filename, int subimage,
                     int miplevel, bool native)
{
    OIIO::ustring c_filename(filename.data(), filename.size());
    return imagecache.imagespec(c_filename, subimage, miplevel, native);
}

const ImageSpec*
imagecache_imagespec_with_handle(ImageCache& imagecache, ImageHandle* file,
                                 Perthread* thread_info, int subimage,
                                 int miplevel, bool native)
{
    return imagecache.imagespec(file, thread_info, subimage, miplevel, native);
}

bool
imagecache_get_thumbnail(ImageCache& imagecache, rust::Str filename,
                         ImageBuf& thumbnail, int subimage)
{
    OIIO::ustring c_filename(filename.data(), filename.size());
    return imagecache.get_thumbnail(c_filename, thumbnail, subimage);
}

bool
imagecache_get_thumbnail_with_handle(ImageCache& imagecache, ImageHandle* file,
                                     Perthread* thread_info,
                                     ImageBuf& thumbnail, int subimage)
{
    return imagecache.get_thumbnail(file, thread_info, thumbnail, subimage);
}

bool
imagecache_get_pixels(ImageCache& imagecache, rust::Str filename, int subimage,
                      int miplevel, int xbegin, int xend, int ybegin, int yend,
                      int zbegin, int zend, int chbegin, int chend,
                      TypeDesc format, const uint8_t* result, int64_t xstride,
                      int64_t ystride, int64_t zstride, int cache_chbegin,
                      int cache_chend)
{
    OIIO::ustring c_filename(filename.data(), filename.size());
    return imagecache.get_pixels(c_filename, subimage, miplevel, xbegin, xend,
                                 ybegin, yend, zbegin, zend, chbegin, chend,
                                 format, (void*)result, xstride, ystride,
                                 zstride, cache_chbegin, cache_chend);
}

bool
imagecache_get_pixels_with_handle(ImageCache& imagecache, ImageHandle* file,
                                  Perthread* thread_info, int subimage,
                                  int miplevel, int xbegin, int xend,
                                  int ybegin, int yend, int zbegin, int zend,
                                  int chbegin, int chend, TypeDesc format,
                                  const uint8_t* result, int64_t xstride,
                                  int64_t ystride, int64_t zstride,
                                  int cache_chbegin, int cache_chend)
{
    return imagecache.get_pixels(file, thread_info, subimage, miplevel, xbegin,
                                 xend, ybegin, yend, zbegin, zend, chbegin,
                                 chend, format, (void*)result, xstride, ystride,
                                 zstride, cache_chbegin, cache_chend);
}

bool
imagecache_get_pixels_all_channels(ImageCache& imagecache, rust::Str filename,
                                   int subimage, int miplevel, int xbegin,
                                   int xend, int ybegin, int yend, int zbegin,
                                   int zend, TypeDesc format,
                                   const uint8_t* result)
{
    OIIO::ustring c_filename(filename.data(), filename.size());
    return imagecache.get_pixels(c_filename, subimage, miplevel, xbegin, xend,
                                 ybegin, yend, zbegin, zend, format,
                                 (void*)result);
}

bool
imagecache_get_pixels_all_channels_with_handle(
    ImageCache& imagecache, ImageHandle* file, Perthread* thread_info,
    int subimage, int miplevel, int xbegin, int xend, int ybegin, int yend,
    int zbegin, int zend, TypeDesc format, const uint8_t* result)
{
    return imagecache.get_pixels(file, thread_info, subimage, miplevel, xbegin,
                                 xend, ybegin, yend, zbegin, zend, format,
                                 (void*)result);
}

void
imagecache_invalidate(ImageCache& imagecache, rust::Str filename, bool force)
{
    OIIO::ustring c_filename(filename.data(), filename.size());
    imagecache.invalidate(c_filename, force);
}

void
imagecache_invalidate_with_handle(ImageCache& imagecache, ImageHandle* file,
                                  bool force)
{
    imagecache.invalidate(file, force);
}

void
imagecache_invalidate_all(ImageCache& imagecache, bool force)
{
    imagecache.invalidate_all(force);
}

void
imagecache_close(ImageCache& imagecache, rust::Str filename)
{
    OIIO::ustring c_filename(filename.data(), filename.size());
    imagecache.close(c_filename);
}

void
imagecache_close_all(ImageCache& imagecache)
{
    imagecache.close_all();
}


Tile*
imagecache_get_tile(ImageCache& imagecache, rust::Str filename, int subimage,
                    int miplevel, int x, int y, int z, int chbegin, int chend)
{
    OIIO::ustring c_filename(filename.data(), filename.size());
    return imagecache.get_tile(c_filename, subimage, miplevel, x, y, z, chbegin,
                               chend);
}

Tile*
imagecache_get_tile_with_handle(ImageCache& imagecache, ImageHandle* file,
                                Perthread* thread_info, int subimage,
                                int miplevel, int x, int y, int z, int chbegin,
                                int chend)
{
    return imagecache.get_tile(file, thread_info, subimage, miplevel, x, y, z,
                               chbegin, chend);
}

void
imagecache_release_tile(ImageCache& imagecache, Tile* tile)
{
    imagecache.release_tile(tile);
}

TypeDesc
imagecache_tile_format(ImageCache& imagecache, const Tile* tile)
{
    return imagecache.tile_format(tile);
}

ROI
imagecache_tile_roi(ImageCache& imagecache, const Tile* tile)
{
    return imagecache.tile_roi(tile);
}

const uint8_t*
imagecache_tile_pixels(ImageCache& imagecache, Tile* tile, TypeDesc& format)
{
    return (uint8_t*)(imagecache.tile_pixels(tile, format));
}

bool
imagecache_add_file(ImageCache& imagecache, rust::Str filename,
                    OIIO::ImageInput::Creator creator, const ImageSpec* config,
                    bool replace)
{
    OIIO::ustring c_filename(filename.data(), filename.size());
    return imagecache.add_file(c_filename, creator, config, replace);
}

bool
imagecache_add_tile_from_coordinates(ImageCache& imagecache, rust::Str filename,
                                     int subimage, int miplevel, int x, int y,
                                     int z, int chbegin, int chend,
                                     TypeDesc format, const uint8_t* buffer,
                                     int64_t xstride, int64_t ystride,
                                     int64_t zstride, bool copy)
{
    OIIO::ustring c_filename(filename.data(), filename.size());
    return imagecache.add_tile(c_filename, subimage, miplevel, x, y, z, chbegin,
                               chend, format, (void*)buffer, xstride, ystride,
                               zstride, copy);
}

bool
imagecache_has_error(ImageCache& imagecache)
{
    return imagecache.has_error();
}

rust::String
imagecache_geterror(ImageCache& imagecache, bool clear)
{
    return rust::String(imagecache.geterror(clear).c_str());
}

rust::String
imagecache_getstats(ImageCache& imagecache, int level)
{
    return rust::String(imagecache.getstats(level).c_str());
}

void
imagecache_reset_stats(ImageCache& imagecache)
{
    imagecache.reset_stats();
}
}  // namespace oiio
