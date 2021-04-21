#include <OpenImageIO/imagecache.h>
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OIIO_NAMESPACE {

namespace OIIO = ::OIIO_NAMESPACE;

struct ImageCache {
    using BoundType = OIIO::ImageCache;

    static auto create(bool shared) -> OIIO::ImageCache*;
    static auto destroy(OIIO::ImageCache* cache, bool teardown) -> void;
    auto attribute(OIIO::string_view name, OIIO::TypeDesc type, const void* val)
        -> bool;
    auto attribute(OIIO::string_view name, int val) -> bool;
    auto attribute(OIIO::string_view name, float val) -> bool;
    auto attribute(OIIO::string_view name, double val) -> bool;
    auto attribute(OIIO::string_view name, OIIO::string_view val) -> bool;
    auto getattribute(OIIO::string_view name, OIIO::TypeDesc type,
                      void* val) const -> bool;
    auto getattribute(OIIO::string_view name, int& val) const -> bool;
    auto getattribute(OIIO::string_view name, float& val) const -> bool;
    auto getattribute(OIIO::string_view name, double& val) const -> bool;
    auto getattribute(OIIO::string_view name, char** val) const -> bool;
    auto getattribute(OIIO::string_view name, std::string& val) const -> bool;

    auto get_perthread_info(OIIO::pvt::ImageCachePerThreadInfo* thread_info)
        -> OIIO::pvt::ImageCachePerThreadInfo*;

    auto create_thread_info() -> OIIO::pvt::ImageCachePerThreadInfo*;

    auto destroy_thread_info(OIIO::pvt::ImageCachePerThreadInfo* thread_info)
        -> void;

    auto get_image_handle(OIIO::ustring filename,
                          OIIO::pvt::ImageCachePerThreadInfo* thread_info)
        -> OIIO::pvt::ImageCacheFile*;

    auto good(OIIO::pvt::ImageCacheFile* file) -> bool;
    auto resolve_filename(const std::string& filename) const -> std::string;

    auto get_image_info(OIIO::ustring filename, int subimage, int miplevel,
                        OIIO::ustring dataname, OIIO::TypeDesc datatype,
                        void* data) -> bool;

    auto get_image_info(OIIO::pvt::ImageCacheFile* file,
                        OIIO::pvt::ImageCachePerThreadInfo* thread_info,
                        int subimage, int miplevel, OIIO::ustring dataname,
                        OIIO::TypeDesc datatype, void* data) -> bool;
    auto get_imagespec(OIIO::ustring filename, OIIO::ImageSpec& spec,
                       int subimage, int miplevel, bool native) -> bool;
    auto get_imagespec(OIIO::pvt::ImageCacheFile* file,
                       OIIO::pvt::ImageCachePerThreadInfo* thread_info,
                       OIIO::ImageSpec& spec, int subimage, int miplevel,
                       bool native) -> bool;

    auto imagespec(OIIO::ustring filename, int subimage, int miplevel,
                   bool native) -> const OIIO::ImageSpec*;

    auto imagespec(OIIO::pvt::ImageCacheFile* file,
                   OIIO::pvt::ImageCachePerThreadInfo* thread_info,
                   int subimage, int miplevel, bool native)
        -> const OIIO::ImageSpec*;

    auto get_pixels(OIIO::ustring filename, int subimage, int miplevel,
                    int xbegin, int xend, int ybegin, int yend, int zbegin,
                    int zend, int chbegin, int chend, OIIO::TypeDesc format,
                    void* result, long xstride, long ystride, long zstride,
                    int cache_chbegin, int cache_chend) -> bool;

    auto get_pixels(OIIO::pvt::ImageCacheFile* file,
                    OIIO::pvt::ImageCachePerThreadInfo* thread_info,
                    int subimage, int miplevel, int xbegin, int xend,
                    int ybegin, int yend, int zbegin, int zend, int chbegin,
                    int chend, OIIO::TypeDesc format, void* result,
                    long xstride, long ystride, long zstride, int cache_chbegin,
                    int cache_chend) -> bool;

    auto get_pixels(OIIO::ustring filename, int subimage, int miplevel,
                    int xbegin, int xend, int ybegin, int yend, int zbegin,
                    int zend, OIIO::TypeDesc format, void* result) -> bool;

    auto get_pixels(OIIO::pvt::ImageCacheFile* file,
                    OIIO::pvt::ImageCachePerThreadInfo* thread_info,
                    int subimage, int miplevel, int xbegin, int xend,
                    int ybegin, int yend, int zbegin, int zend,
                    OIIO::TypeDesc format, void* result) -> bool;

    auto invalidate(OIIO::ustring filename, bool force) -> void;

    auto invalidate_all(bool force) -> void;

    auto close(OIIO::ustring filename) -> void;

    auto close_all() -> void;

    auto get_tile(OIIO::ustring filename, int subimage, int miplevel, int x,
                  int y, int z, int chbegin, int chend)
        -> OIIO::ImageCache::Tile*;

    auto get_tile(OIIO::pvt::ImageCacheFile* file,
                  OIIO::pvt::ImageCachePerThreadInfo* thread_info, int subimage,
                  int miplevel, int x, int y, int z, int chbegin, int chend)
        -> OIIO::ImageCache::Tile*;

    auto release_tile(OIIO::ImageCache::Tile* tile) const -> void;

    auto tile_format(const OIIO::ImageCache::Tile* tile) const
        -> OIIO::TypeDesc;

    auto tile_roi(const OIIO::ImageCache::Tile* tile) const -> OIIO::ROI;

    auto tile_pixels(OIIO::ImageCache::Tile* tile, OIIO::TypeDesc& format) const
        -> const void*;

    auto add_file(OIIO::ustring filename, OIIO::ImageInput::Creator creator,
                  const OIIO::ImageSpec* config, bool replace) -> bool;

    auto add_tile(OIIO::ustring filename, int subimage, int miplevel, int x,
                  int y, int z, int chbegin, int chend, OIIO::TypeDesc format,
                  const void* buffer, long xstride, long ystride, long zstride,
                  bool copy) -> bool;
    auto geterror() const -> std::string;
    auto getstats(int level) const -> std::string;
    auto reset_stats() -> void;
    ~ImageCache();
    auto operator=(const OIIO::ImageCache& rhs) -> OIIO::ImageCache&;
} CPPMM_OPAQUEPTR; // struct ImageCache

} // namespace OIIO_NAMESPACE

} // namespace cppmm_bind
