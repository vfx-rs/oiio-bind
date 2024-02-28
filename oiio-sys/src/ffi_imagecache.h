#pragma once

#include <OpenImageIO/imagebuf.h>
#include <OpenImageIO/imagecache.h>
#include <OpenImageIO/imageio.h>
#include <OpenImageIO/texture.h>
#include <OpenImageIO/typedesc.h>
#include <rust/cxx.h>
#include <string>

namespace oiio {
using ImageBuf    = OIIO::ImageBuf;
using ImageCache  = OIIO::ImageCache;
using ImageHandle = OIIO::ImageCache::ImageHandle;
using ImageSpec   = OIIO::ImageSpec;
using Perthread   = OIIO::ImageCache::Perthread;
using ROI         = OIIO::ROI;
using TextureOpt  = OIIO::TextureOpt;
using Tile        = OIIO::ImageCache::Tile;
using TypeDesc    = OIIO::TypeDesc;


ImageCache*
imagecache_create(bool shared);

void
imagecache_destroy(ImageCache* imagecache, bool teardown);

bool
imagecache_attribute(ImageCache& imagecache, rust::Str name, TypeDesc type,
                     const uint8_t* val);

bool
imagecache_attribute_int(ImageCache& imagecache, rust::Str name, int val);

bool
imagecache_attribute_float(ImageCache& imagecache, rust::Str name, float val);

bool
imagecache_attribute_double(ImageCache& imagecache, rust::Str name, double val);

bool
imagecache_attribute_str(ImageCache& imagecache, rust::Str name, rust::Str val);

bool
imagecache_getattribute(ImageCache& imagecache, rust::Str name, TypeDesc type,
                        const uint8_t* val);

bool
imagecache_getattribute_int(ImageCache& imagecache, rust::Str name, int& val);

bool
imagecache_getattribute_float(ImageCache& imagecache, rust::Str name,
                              float& val);

bool
imagecache_getattribute_double(ImageCache& imagecache, rust::Str name,
                               double& val);

bool
imagecache_getattribute_string(ImageCache& imagecache, rust::Str name,
                               std::string& val);

TypeDesc
imagecache_getattributetype(ImageCache& imagecache, rust::Str name);

Perthread*
imagecache_get_perthread_info(ImageCache& imagecache, Perthread* thread_info);

Perthread*
imagecache_create_thread_info(ImageCache& imagecache);

void
imagecache_destroy_thread_info(ImageCache& imagecache, Perthread* thread_info);

ImageHandle*
imagecache_get_image_handle(ImageCache& imagecache, rust::Str filename,
                            Perthread* thread_info, const TextureOpt* options);

bool
imagecache_good(ImageCache& imagecache, ImageHandle* file);

rust::String
imagecache_filename_from_handle(ImageCache& imagecache, ImageHandle* handle);

bool
imagecache_get_image_info(ImageCache& imagecache, rust::Str filename,
                          int subimage, int miplevel, rust::Str dataname,
                          TypeDesc datatype, const uint8_t* data);

bool
imagecache_get_image_info_with_handle(ImageCache& imagecache, ImageHandle* file,
                                      Perthread* thread_info, int subimage,
                                      int miplevel, rust::Str dataname,
                                      TypeDesc datatype, const uint8_t* data);

bool
imagecache_get_imagespec(ImageCache& imagecache, rust::Str filename,
                         ImageSpec& spec, int subimage, int miplevel,
                         bool native);

bool
imagecache_get_imagespec_with_handle(ImageCache& imagecache, ImageHandle* file,
                                     Perthread* thread_info, ImageSpec& spec,
                                     int subimage, int miplevel, bool native);

const ImageSpec*
imagecache_imagespec(ImageCache& imagecache, rust::Str filename, int subimage,
                     int miplevel, bool native);

const ImageSpec*
imagecache_imagespec_with_handle(ImageCache& imagecache, ImageHandle* file,
                                 Perthread* thread_info, int subimage,
                                 int miplevel, bool native);

bool
imagecache_get_thumbnail(ImageCache& imagecache, rust::Str filename,
                         ImageBuf& thumbnail, int subimage);

bool
imagecache_get_thumbnail_with_handle(ImageCache& imagecache, ImageHandle* file,
                                     Perthread* thread_info,
                                     ImageBuf& thumbnail, int subimage);

bool
imagecache_get_pixels(ImageCache& imagecache, rust::Str filename, int subimage,
                      int miplevel, int xbegin, int xend, int ybegin, int yend,
                      int zbegin, int zend, int chbegin, int chend,
                      TypeDesc format, const uint8_t* result, int64_t xstride,
                      int64_t ystride, int64_t zstride, int cache_chbegin,
                      int cache_chend);

bool
imagecache_get_pixels_with_handle(ImageCache& imagecache, ImageHandle* file,
                                  Perthread* thread_info, int subimage,
                                  int miplevel, int xbegin, int xend,
                                  int ybegin, int yend, int zbegin, int zend,
                                  int chbegin, int chend, TypeDesc format,
                                  const uint8_t* result, int64_t xstride,
                                  int64_t ystride, int64_t zstride,
                                  int cache_chbegin, int cache_chend);

bool
imagecache_get_pixels_all_channels(ImageCache& imagecache, rust::Str filename,
                                   int subimage, int miplevel, int xbegin,
                                   int xend, int ybegin, int yend, int zbegin,
                                   int zend, TypeDesc format,
                                   const uint8_t* result);

bool
imagecache_get_pixels_all_channels_with_handle(
    ImageCache& imagecache, ImageHandle* file, Perthread* thread_info,
    int subimage, int miplevel, int xbegin, int xend, int ybegin, int yend,
    int zbegin, int zend, TypeDesc format, const uint8_t* result);

void
imagecache_invalidate(ImageCache& imagecache, rust::Str filename, bool force);

void
imagecache_invalidate_with_handle(ImageCache& imagecache, ImageHandle* file,
                                  bool force);

void
imagecache_invalidate_all(ImageCache& imagecache, bool force);

void
imagecache_close(ImageCache& imagecache, rust::Str filename);

void
imagecache_close_all(ImageCache& imagecache);


Tile*
imagecache_get_tile(ImageCache& imagecache, rust::Str filename, int subimage,
                    int miplevel, int x, int y, int z, int chbegin, int chend);

Tile*
imagecache_get_tile_with_handle(ImageCache& imagecache, ImageHandle* file,
                                Perthread* thread_info, int subimage,
                                int miplevel, int x, int y, int z, int chbegin,
                                int chend);

void
imagecache_release_tile(ImageCache& imagecache, Tile* tile);

TypeDesc
imagecache_tile_format(ImageCache& imagecache, const Tile* tile);

ROI
imagecache_tile_roi(ImageCache& imagecache, const Tile* tile);

const uint8_t*
imagecache_tile_pixels(ImageCache& imagecache, Tile* tile, TypeDesc& format);

bool
imagecache_add_file(ImageCache& imagecache, rust::Str filename,
                    OIIO::ImageInput::Creator creator, const ImageSpec* config,
                    bool replace);

bool
imagecache_add_tile_from_coordinates(ImageCache& imagecache, rust::Str filename,
                                     int subimage, int miplevel, int x, int y,
                                     int z, int chbegin, int chend,
                                     TypeDesc format, const uint8_t* buffer,
                                     int64_t xstride, int64_t ystride,
                                     int64_t zstride, bool copy);

bool
imagecache_has_error(ImageCache& imagecache);

rust::String
imagecache_geterror(ImageCache& imagecache, bool clear);

rust::String
imagecache_getstats(ImageCache& imagecache, int level);

void
imagecache_reset_stats(ImageCache& imagecache);
}  // namespace oiio
