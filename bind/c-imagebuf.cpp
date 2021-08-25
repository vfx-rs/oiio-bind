#include <OpenImageIO/imagebuf.h>
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OIIO_NAMESPACE {

namespace OIIO = ::OIIO_NAMESPACE;

struct ImageBuf {
    using BoundType = OIIO::ImageBuf;

    CPPMM_RENAME(default)
    ImageBuf();

    ~ImageBuf();

    ImageBuf(OIIO::string_view name, int subimage, int miplevel,
             OIIO::ImageCache* imagecache, const OIIO::ImageSpec* config,
             OIIO::Filesystem::IOProxy* ioproxy);

    CPPMM_IGNORE
    ImageBuf(OIIO::string_view name, OIIO::ImageCache* imagecache);

    CPPMM_RENAME(ctor_initialized)
    ImageBuf(const OIIO::ImageSpec& spec, OIIO::InitializePixels zero);

    CPPMM_IGNORE
    ImageBuf(OIIO::string_view name, const OIIO::ImageSpec& spec,
             OIIO::InitializePixels zero);

    CPPMM_RENAME(wrap_buffer)
    ImageBuf(const OIIO::ImageSpec& spec, void* buffer, OIIO::stride_t x_stride,
             OIIO::stride_t y_stride, OIIO::stride_t z_stride);

    CPPMM_IGNORE
    ImageBuf(OIIO::string_view name, const OIIO::ImageSpec& spec, void* buffer);

    ImageBuf(const OIIO::ImageBuf& src);

    CPPMM_IGNORE
    ImageBuf(OIIO::ImageBuf&& src);

    auto clear() -> void;

    auto reset() -> void;

    CPPMM_IGNORE
    auto reset(OIIO::string_view name, OIIO::ImageCache* imagecache) -> void;

    CPPMM_RENAME(reset_with_file)
    auto reset(OIIO::string_view name, int subimage, int miplevel,
               OIIO::ImageCache* imagecache, const OIIO::ImageSpec* config,
               OIIO::Filesystem::IOProxy* ioproxy) -> void;

    CPPMM_RENAME(reset_initialized)
    auto reset(const OIIO::ImageSpec& spec, OIIO::InitializePixels zero)
        -> void;

    CPPMM_IGNORE
    auto reset(OIIO::string_view name, const OIIO::ImageSpec& spec,
               OIIO::InitializePixels zero) -> void;

    CPPMM_RENAME(reset_wrap_buffer)
    void reset(const OIIO::ImageSpec& spec, void* buffer,
               OIIO::stride_t x_stride, OIIO::stride_t y_stride,
               OIIO::stride_t z_stride);

    auto make_writable(bool keep_cache_type) -> bool;

    CPPMM_IGNORE
    auto make_writeable(bool keep_cache_type) -> bool;

    auto read(int subimage, int miplevel, bool force, OIIO::TypeDesc convert,
              OIIO::ProgressCallback progress_callback,
              void* progress_callback_data) -> bool;

    CPPMM_RENAME(read_channels)
    auto read(int subimage, int miplevel, int chbegin, int chend, bool force,
              OIIO::TypeDesc convert, OIIO::ProgressCallback progress_callback,
              void* progress_callback_data) -> bool;

    auto init_spec(OIIO::string_view filename, int subimage, int miplevel)
        -> bool;

    auto write(OIIO::string_view filename, OIIO::TypeDesc dtype,
               OIIO::string_view fileformat,
               OIIO::ProgressCallback progress_callback,
               void* progress_callback_data) const -> bool;

    CPPMM_IGNORE
    auto write(OIIO::string_view filename, OIIO::string_view fileformat,
               OIIO::ProgressCallback progress_callback,
               void* progress_callback_data) const -> bool;

    auto set_write_format(OIIO::TypeDesc format) -> void;

    CPPMM_RENAME(set_write_format_per_channel)
    auto set_write_format(OIIO::span<const OIIO::TypeDesc, -1> format) -> void;

    auto set_write_tiles(int width, int height, int depth) -> void;

    auto set_write_ioproxy(OIIO::Filesystem::IOProxy* ioproxy) -> void;

    CPPMM_RENAME(write_to_imageoutput)
    auto write(OIIO::ImageOutput* out, OIIO::ProgressCallback progress_callback,
               void* progress_callback_data) const -> bool;

    auto operator=(const OIIO::ImageBuf& src) -> const OIIO::ImageBuf&;

    auto copy_metadata(const OIIO::ImageBuf& src) -> void;
    auto copy_pixels(const OIIO::ImageBuf& src) -> bool;

    CPPMM_RENAME(copy_from)
    auto copy(const OIIO::ImageBuf& src, OIIO::TypeDesc format) -> bool;

    CPPMM_RENAME(clone)
    auto copy(OIIO::TypeDesc format) const -> OIIO::ImageBuf;

    auto swap(OIIO::ImageBuf& other) -> void;

    auto getchannel(int x, int y, int z, int c,
                    OIIO::ImageBuf::WrapMode wrap) const -> float;

    CPPMM_RENAME(getpixel_3d)
    auto getpixel(int x, int y, int z, float* pixel, int maxchannels,
                  OIIO::ImageBuf::WrapMode wrap) const -> void;

    auto getpixel(int x, int y, float* pixel, int maxchannels) const -> void;

    auto interppixel(float x, float y, float* pixel,
                     OIIO::ImageBuf::WrapMode wrap) const -> void;

    auto interppixel_NDC(float s, float t, float* pixel,
                         OIIO::ImageBuf::WrapMode wrap) const -> void;

    auto interppixel_NDC_full(float s, float t, float* pixel,
                              OIIO::ImageBuf::WrapMode wrap) const -> void;

    auto interppixel_bicubic(float x, float y, float* pixel,
                             OIIO::ImageBuf::WrapMode wrap) const -> void;

    auto interppixel_bicubic_NDC(float s, float t, float* pixel,
                                 OIIO::ImageBuf::WrapMode wrap) const -> void;

    CPPMM_RENAME(setpixel_span)
    auto setpixel(int x, int y, OIIO::span<const float, -1> pixel) -> void;

    CPPMM_RENAME(setpixel_3d_span)
    auto setpixel(int x, int y, int z, OIIO::span<const float, -1> pixel)
        -> void;

    CPPMM_RENAME(setpixel_at_index_span)
    auto setpixel(int i, OIIO::span<const float, -1> pixel) -> void;

    auto setpixel(int x, int y, const float* pixel, int maxchannels) -> void;

    CPPMM_RENAME(setpixel_3d)
    auto setpixel(int x, int y, int z, const float* pixel, int maxchannels)
        -> void;

    CPPMM_RENAME(setpixel_at_index)
    auto setpixel(int i, const float* pixel, int maxchannels) -> void;

    auto get_pixels(OIIO::ROI roi, OIIO::TypeDesc format, void* result,
                    OIIO::stride_t xstride, OIIO::stride_t ystride, OIIO::stride_t zstride) const -> bool;
    auto set_pixels(OIIO::ROI roi, OIIO::TypeDesc format, const void* data,
                    OIIO::stride_t xstride, OIIO::stride_t ystride, OIIO::stride_t zstride) -> bool;

    auto initialized() const -> bool;
    auto storage() const -> OIIO::ImageBuf::IBStorage;
    auto spec() const -> const OIIO::ImageSpec&;
    auto specmod() -> OIIO::ImageSpec&;
    auto nativespec() const -> const OIIO::ImageSpec&;
    auto name() const -> OIIO::string_view;
    auto file_format_name() const -> OIIO::string_view;
    auto subimage() const -> int;
    auto nsubimages() const -> int;
    auto miplevel() const -> int;
    auto nmiplevels() const -> int;
    auto nchannels() const -> int;

    auto xbegin() const -> int;
    auto xend() const -> int;
    auto ybegin() const -> int;
    auto yend() const -> int;
    auto zbegin() const -> int;
    auto zend() const -> int;

    auto xmin() const -> int;
    auto xmax() const -> int;
    auto ymin() const -> int;
    auto ymax() const -> int;
    auto zmin() const -> int;
    auto zmax() const -> int;

    auto orientation() const -> int;
    auto set_orientation(int orient) -> void;

    auto oriented_width() const -> int;
    auto oriented_height() const -> int;

    auto oriented_x() const -> int;
    auto oriented_y() const -> int;

    auto oriented_full_width() const -> int;
    auto oriented_full_height() const -> int;

    auto oriented_full_x() const -> int;
    auto oriented_full_y() const -> int;

    auto set_origin(int x, int y, int z) -> void;
    auto set_full(int xbegin, int xend, int ybegin, int yend, int zbegin,
                  int zend) -> void;

    auto roi() const -> OIIO::ROI;
    auto roi_full() const -> OIIO::ROI;
    auto set_roi_full(const OIIO::ROI& newroi) -> void;
    auto contains_roi(OIIO::ROI roi) const -> bool;

    auto pixels_valid() const -> bool;

    auto pixeltype() const -> OIIO::TypeDesc;

    auto localpixels() -> void*;

    CPPMM_RENAME(localpixels_const)
    auto localpixels() const -> const void*;

    auto pixel_stride() const -> OIIO::stride_t;
    auto scanline_stride() const -> OIIO::stride_t;
    auto z_stride() const -> OIIO::stride_t;

    auto cachedpixels() const -> bool;
    auto imagecache() const -> OIIO::ImageCache*;

    CPPMM_RENAME(pixeladdr_const)
    auto pixeladdr(int x, int y, int z, int ch) const -> const void*;
    auto pixeladdr(int x, int y, int z, int ch) -> void*;
    auto pixelindex(int x, int y, int z, bool check_range) const -> int;

    auto threads(int n) const -> void;

    CPPMM_RENAME(threads_const)
    auto threads() const -> int;

    void error(OIIO::string_view message) const;

    template <typename... Args>
    auto errorfmt(const char* fmt, Args... args) const -> void;
    template <typename... Args>
    auto errorf(const char* fmt, Args... args) const -> void;
    template <typename... Args>
    auto error(const char* fmt, Args... args) const -> void;
    template <typename... Args>
    auto fmterror(const char* fmt, Args... args) const -> void;

    auto has_error() const -> bool;
    auto geterror(bool clear) const -> std::string;

    auto deep() const -> bool;
    auto deep_samples(int x, int y, int z) const -> int;
    auto deep_pixel_ptr(int x, int y, int z, int c, int s) const -> const void*;

    auto deep_value(int x, int y, int z, int c, int s) const -> float;
    auto deep_value_uint(int x, int y, int z, int c, int s) const
        -> unsigned int;

    auto set_deep_samples(int x, int y, int z, int nsamples) -> void;
    auto deep_insert_samples(int x, int y, int z, int samplepos, int nsamples)
        -> void;
    auto deep_erase_samples(int x, int y, int z, int samplepos, int nsamples)
        -> void;

    auto set_deep_value(int x, int y, int z, int c, int s, float value) -> void;

    CPPMM_RENAME(set_deep_value_uint)
    auto set_deep_value(int x, int y, int z, int c, int s, unsigned int value)
        -> void;

    auto copy_deep_pixel(int x, int y, int z, const OIIO::ImageBuf& src,
                         int srcx, int srcy, int srcz) -> bool;
    auto deepdata() -> OIIO::DeepData*;

    CPPMM_RENAME(deepdata_const)
    auto deepdata() const -> const OIIO::DeepData*;

    /// Is the data layout "contiguous", i.e.,
    /// ```
    ///     pixel_stride == nchannels * pixeltype().size()
    ///     scanline_stride == pixel_stride * spec().width
    ///     z_stride == scanline_stride * spec().height
    /// ```
    bool contiguous() const;

    static auto WrapMode_from_string(OIIO::string_view name)
        -> OIIO::ImageBuf::WrapMode;

    enum IBStorage {
        UNINITIALIZED = 0,
        LOCALBUFFER = 1,
        APPBUFFER = 2,
        IMAGECACHE = 3,
    };

    enum WrapMode {
        WrapDefault = 0,
        WrapBlack = 1,
        WrapClamp = 2,
        WrapPeriodic = 3,
        WrapMirror = 4,
        _WrapLast = 5,
    };

    struct IteratorBase {
        using BoundType = OIIO::ImageBuf::IteratorBase;

        CPPMM_RENAME(with_wrapmode)
        IteratorBase(const OIIO::ImageBuf& ib, OIIO::ImageBuf::WrapMode wrap);

        CPPMM_RENAME(with_roi)
        IteratorBase(const OIIO::ImageBuf& ib, const OIIO::ROI& roi,
                     OIIO::ImageBuf::WrapMode wrap);

        CPPMM_RENAME(with_range)
        IteratorBase(const OIIO::ImageBuf& ib, int xbegin, int xend, int ybegin,
                     int yend, int zbegin, int zend,
                     OIIO::ImageBuf::WrapMode wrap);
        IteratorBase(const OIIO::ImageBuf::IteratorBase& i);

        ~IteratorBase();
        auto assign_base(const OIIO::ImageBuf::IteratorBase& i)
            -> const OIIO::ImageBuf::IteratorBase&;
        auto x() const -> int;
        auto y() const -> int;
        auto z() const -> int;

        auto valid() const -> bool;

        CPPMM_RENAME(valid_at_index)
        auto valid(int x_, int y_, int z_) const -> bool;

        CPPMM_RENAME(exists_at_index)
        auto exists(int x_, int y_, int z_) const -> bool;
        auto exists() const -> bool;

        auto done() const -> bool;
        auto deep_samples() const -> int;
        auto wrap() const -> OIIO::ImageBuf::WrapMode;
        auto pos(int x_, int y_, int z_) -> void;
        auto operator++() -> void;
        CPPMM_IGNORE
        auto operator++(int) -> void;
        auto range() const -> OIIO::ROI;
        auto rerange(int xbegin, int xend, int ybegin, int yend, int zbegin,
                     int zend, OIIO::ImageBuf::WrapMode wrap) -> void;
    } CPPMM_OPAQUEBYTES CPPMM_TRIVIALLY_COPYABLE
        CPPMM_TRIVIALLY_MOVABLE; // struct IteratorBase

    template <class BUFT, class USERT> struct Iterator {
        using BoundType = OIIO::ImageBuf::Iterator<BUFT, USERT>;

        auto assign_base(const OIIO::ImageBuf::IteratorBase& i)
            -> const OIIO::ImageBuf::IteratorBase&;
        auto x() const -> int;
        auto y() const -> int;
        auto z() const -> int;
        auto valid() const -> bool;
        auto valid(int x_, int y_, int z_) const -> bool;
        auto exists(int x_, int y_, int z_) const -> bool;
        auto exists() const -> bool;
        auto done() const -> bool;
        auto deep_samples() const -> int;
        auto wrap() const -> OIIO::ImageBuf::WrapMode;
        auto pos(int x_, int y_, int z_) -> void;
        auto operator++() -> void;
        CPPMM_IGNORE
        auto operator++(int) -> void;
        auto range() const -> OIIO::ROI;
        auto rerange(int xbegin, int xend, int ybegin, int yend, int zbegin,
                     int zend, OIIO::ImageBuf::WrapMode wrap) -> void;
        Iterator<BUFT, USERT>(OIIO::ImageBuf& ib,
                              OIIO::ImageBuf::WrapMode wrap);
        Iterator<BUFT, USERT>(OIIO::ImageBuf& ib, int x, int y, int z,
                              OIIO::ImageBuf::WrapMode wrap);
        Iterator<BUFT, USERT>(OIIO::ImageBuf& ib, const OIIO::ROI& roi,
                              OIIO::ImageBuf::WrapMode wrap);
        Iterator<BUFT, USERT>(OIIO::ImageBuf& ib, int xbegin, int xend,
                              int ybegin, int yend, int zbegin, int zend,
                              OIIO::ImageBuf::WrapMode wrap);
        Iterator<BUFT, USERT>(OIIO::ImageBuf::Iterator<BUFT, USERT>& i);
        ~Iterator<BUFT, USERT>();
        auto operator=(const OIIO::ImageBuf::Iterator<BUFT, USERT>& i)
            -> const OIIO::ImageBuf::Iterator<BUFT, USERT>&;
        auto operator*() -> OIIO::DataArrayProxy<BUFT, USERT>&;
        auto operator[](int i) const -> USERT;
        auto operator[](int i) -> OIIO::DataProxy<BUFT, USERT>;
        auto rawptr() const -> void*;
        auto set_deep_samples(int n) -> void;
        auto deep_value(int c, int s) const -> USERT;
        auto deep_value_uint(int c, int s) const -> unsigned int;
        auto set_deep_value(int c, int s, float value) -> void;
        auto set_deep_value(int c, int s, unsigned int value) -> void;
    } CPPMM_OPAQUEBYTES CPPMM_TRIVIALLY_MOVABLE
        CPPMM_TRIVIALLY_COPYABLE; // struct Iterator

    // TODO: fill in explicit instantiations, e.g.:
    // template class Iterator<int, int>;
    // using IteratorInt = OIIO::ImageBuf::Iterator<int, int>;

    template <class BUFT, class USERT> struct ConstIterator {
        using BoundType = OIIO::ImageBuf::ConstIterator<BUFT, USERT>;

        auto assign_base(const OIIO::ImageBuf::IteratorBase& i)
            -> const OIIO::ImageBuf::IteratorBase&;
        auto x() const -> int;
        auto y() const -> int;
        auto z() const -> int;
        auto valid() const -> bool;
        auto valid(int x_, int y_, int z_) const -> bool;
        auto exists(int x_, int y_, int z_) const -> bool;
        auto exists() const -> bool;
        auto done() const -> bool;
        auto deep_samples() const -> int;
        auto wrap() const -> OIIO::ImageBuf::WrapMode;
        auto pos(int x_, int y_, int z_) -> void;
        auto operator++() -> void;
        CPPMM_IGNORE
        auto operator++(int) -> void;
        auto range() const -> OIIO::ROI;
        auto rerange(int xbegin, int xend, int ybegin, int yend, int zbegin,
                     int zend, OIIO::ImageBuf::WrapMode wrap) -> void;
        ConstIterator<BUFT, USERT>(const OIIO::ImageBuf& ib,
                                   OIIO::ImageBuf::WrapMode wrap);
        ConstIterator<BUFT, USERT>(const OIIO::ImageBuf& ib, int x_, int y_,
                                   int z_, OIIO::ImageBuf::WrapMode wrap);
        ConstIterator<BUFT, USERT>(const OIIO::ImageBuf& ib,
                                   const OIIO::ROI& roi,
                                   OIIO::ImageBuf::WrapMode wrap);
        ConstIterator<BUFT, USERT>(const OIIO::ImageBuf& ib, int xbegin,
                                   int xend, int ybegin, int yend, int zbegin,
                                   int zend, OIIO::ImageBuf::WrapMode wrap);
        ConstIterator<BUFT, USERT>(
            const OIIO::ImageBuf::ConstIterator<BUFT, USERT>& i);
        ~ConstIterator<BUFT, USERT>();
        auto operator=(const OIIO::ImageBuf::ConstIterator<BUFT, USERT>& i)
            -> const OIIO::ImageBuf::ConstIterator<BUFT, USERT>&;
        auto operator*() const -> OIIO::ConstDataArrayProxy<BUFT, USERT>&;
        auto operator[](int i) const -> USERT;
        auto rawptr() const -> const void*;
        auto deep_value(int c, int s) const -> USERT;
        auto deep_value_uint(int c, int s) const -> unsigned int;
    } CPPMM_OPAQUEBYTES CPPMM_TRIVIALLY_MOVABLE
        CPPMM_TRIVIALLY_COPYABLE; // struct ConstIterator

    // TODO: fill in explicit instantiations, e.g.:
    // template class ConstIterator<int, int>;
    // using ConstIteratorInt = OIIO::ImageBuf::ConstIterator<int, int>;

    /// Does this ImageBuf have an associated thumbnail?
    bool has_thumbnail() const;

    /// Return a shared pointer to an ImageBuf containing a thumbnail of the
    /// image (if it existed in the file), which may be empty if there is no
    /// thumbnail.
    std::shared_ptr<OIIO::ImageBuf> get_thumbnail() const;

    /// Reset the thumbnail image associated with this ImageBuf to `thumb`.
    /// This call will invalidate any references previously returned by
    /// `thumbnail()`.
    void set_thumbnail(const OIIO::ImageBuf& thumb);

    /// Clear any thumbnail associated with this ImageBuf. This call will
    /// invalidate any references previously returned by `thumbnail()`.
    void clear_thumbnail();

} CPPMM_OPAQUEPTR; // struct ImageBuf

auto get_roi(const OIIO::ImageSpec& spec) -> OIIO::ROI;

auto get_roi_full(const OIIO::ImageSpec& spec) -> OIIO::ROI;

auto set_roi(OIIO::ImageSpec& spec, const OIIO::ROI& newroi) -> void;

auto set_roi_full(OIIO::ImageSpec& spec, const OIIO::ROI& newroi) -> void;

enum InitializePixels {
    No = 0,
    Yes = 1,
};

} // namespace OIIO_NAMESPACE

} // namespace cppmm_bind

// TODO: fill in explicit instantiations
// template class OIIO::ImageBuf::Iterator<int, int>;
// template class OIIO::ImageBuf::ConstIterator<int, int>;
