#include <OpenImageIO/imageio.h>
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OIIO_NAMESPACE {

namespace OIIO = ::OIIO_NAMESPACE;

using ProgressCallback = OIIO::ProgressCallback;

struct ROI {
    using BoundType = OIIO::ROI;

    ROI() CPPMM_IGNORE;
    ROI(int xbegin, int xend, int ybegin, int yend, int zbegin, int zend,
        int chbegin, int chend)
    CPPMM_IGNORE;
    auto defined() const -> bool;
    auto width() const -> int;
    auto height() const -> int;
    auto depth() const -> int;
    auto nchannels() const -> int;
    auto npixels() const -> unsigned long;
    static auto All() -> OIIO::ROI;
    auto contains(int x, int y, int z, int ch) const -> bool;
    CPPMM_RENAME(contains_roi)
    auto contains(const OIIO::ROI& other) const -> bool;

    ROI(const OIIO::ROI& rhs);

    CPPMM_IGNORE
    ROI(OIIO::ROI&&);
    ~ROI() CPPMM_IGNORE;
} CPPMM_VALUETYPE; // struct ROI

auto roi_union(const OIIO::ROI& A, const OIIO::ROI& B) -> OIIO::ROI;

auto roi_intersection(const OIIO::ROI& A, const OIIO::ROI& B) -> OIIO::ROI;

struct ImageSpec {
    using BoundType = OIIO::ImageSpec;

    CPPMM_RENAME(from_typedesc)
    ImageSpec(OIIO::TypeDesc format);
    CPPMM_RENAME(from_dimensions)
    ImageSpec(int xres, int yres, int nchans, OIIO::TypeDesc fmt);
    CPPMM_RENAME(from_roi)
    ImageSpec(const OIIO::ROI& roi, OIIO::TypeDesc fmt);

    CPPMM_RENAME(set_format_and_clear)
    auto set_format(OIIO::TypeDesc fmt) -> void;
    auto default_channel_names() -> void;
    auto channel_bytes() const -> unsigned long;

    CPPMM_RENAME(channel_bytes_for_channel)
    auto channel_bytes(int chan, bool native) const -> unsigned long;
    auto pixel_bytes(bool native) const -> unsigned long;

    CPPMM_RENAME(pixel_bytes_for_channels)
    auto pixel_bytes(int chbegin, int chend, bool native) const
        -> unsigned long;
    auto scanline_bytes(bool native) const -> unsigned long;
    auto tile_pixels() const -> unsigned long;
    auto tile_bytes(bool native) const -> unsigned long;
    auto image_pixels() const -> unsigned long;
    auto image_bytes(bool native) const -> unsigned long;
    auto size_t_safe() const -> bool;

    static auto auto_stride(long& xstride, long& ystride, long& zstride,
                            long channelsize, int nchannels, int width,
                            int height) -> void;

    CPPMM_RENAME(auto_stride_with_typedesc)
    static auto auto_stride(long& xstride, long& ystride, long& zstride,
                            OIIO::TypeDesc format, int nchannels, int width,
                            int height) -> void;

    CPPMM_RENAME(auto_stride_xstride)
    static auto auto_stride(long& xstride, OIIO::TypeDesc format, int nchannels)
        -> void;

    auto attribute(OIIO::string_view name, OIIO::TypeDesc type,
                   const void* value) -> void;

    CPPMM_RENAME(attribute_uint)
    auto attribute(OIIO::string_view name, unsigned int value) -> void;

    CPPMM_RENAME(attribute_int)
    auto attribute(OIIO::string_view name, int value) -> void;

    CPPMM_RENAME(attribute_float)
    auto attribute(OIIO::string_view name, float value) -> void;

    CPPMM_RENAME(attribute_string)
    auto attribute(OIIO::string_view name, OIIO::string_view value) -> void;

    CPPMM_RENAME(attribute_from_string)
    auto attribute(OIIO::string_view name, OIIO::TypeDesc type,
                   OIIO::string_view value) -> void;

    auto erase_attribute(OIIO::string_view name, OIIO::TypeDesc searchtype,
                         bool casesensitive) -> void;

    auto find_attribute(OIIO::string_view name, OIIO::TypeDesc searchtype,
                        bool casesensitive) -> OIIO::ParamValue*;

    CPPMM_RENAME(find_attribute_const)
    auto find_attribute(OIIO::string_view name, OIIO::TypeDesc searchtype,
                        bool casesensitive) const -> const OIIO::ParamValue*;

    CPPMM_RENAME(find_attribute_builtin)
    auto find_attribute(OIIO::string_view name, OIIO::ParamValue& tmpparam,
                        OIIO::TypeDesc searchtype, bool casesensitive) const
        -> const OIIO::ParamValue*;

    auto getattributetype(OIIO::string_view name, bool casesensitive) const
        -> OIIO::TypeDesc;

    auto getattribute(OIIO::string_view name, OIIO::TypeDesc type, void* value,
                      bool casesensitive) const -> bool;

    auto get_int_attribute(OIIO::string_view name, int defaultval) const -> int;

    auto get_float_attribute(OIIO::string_view name, float defaultval) const
        -> float;

    auto get_string_attribute(OIIO::string_view name,
                              OIIO::string_view defaultval) const
        -> OIIO::string_view;

    static auto metadata_val(const OIIO::ParamValue& p, bool human)
        -> std::string;

    auto serialize(OIIO::ImageSpec::SerialFormat format,
                   OIIO::ImageSpec::SerialVerbose verbose) const -> std::string;

    auto to_xml() const -> std::string;
    auto from_xml(const char* xml) -> void;

    auto decode_compression_metadata(OIIO::string_view defaultcomp,
                                     int defaultqual) const
        -> std::pair<OIIO::string_view, int>;

    auto valid_tile_range(int xbegin, int xend, int ybegin, int yend,
                          int zbegin, int zend) -> bool;
    auto channelformat(int chan) const -> OIIO::TypeDesc;
    auto channel_name(int chan) const -> OIIO::string_view;

    CPPMM_RENAME(get_channelformats_into)
    auto get_channelformats(std::vector<OIIO::TypeDesc>& formats) const -> void;

    auto channelindex(OIIO::string_view name) const -> int;
    auto roi() const -> OIIO::ROI;
    auto roi_full() const -> OIIO::ROI;
    auto set_roi(const OIIO::ROI& r) -> void;
    auto set_roi_full(const OIIO::ROI& r) -> void;
    auto copy_dimensions(const OIIO::ImageSpec& other) -> void;
    auto undefined() const -> bool;

    CPPMM_IGNORE
    auto operator[](OIIO::string_view name)
        -> OIIO::AttrDelegate<OIIO::ImageSpec>;

    CPPMM_IGNORE
    auto operator[](OIIO::string_view name) const
        -> OIIO::AttrDelegate<const OIIO::ImageSpec>;

    ImageSpec(const OIIO::ImageSpec& rhs);
    CPPMM_IGNORE
    ImageSpec(OIIO::ImageSpec&&);

    ~ImageSpec();

    auto operator=(const OIIO::ImageSpec& rhs) -> OIIO::ImageSpec&;

    enum SerialFormat {
        SerialText = 0,
        SerialXML = 1,
    };

    enum SerialVerbose {
        SerialBrief = 0,
        SerialDetailed = 1,
        SerialDetailedHuman = 2,
    };
} CPPMM_OPAQUEPTR CPPMM_PROPERTIES(x; y; z; width; height; depth; full_x;
                                   full_y; full_z; full_width; full_height;
                                   full_depth; tile_width; tile_height;
                                   tile_depth; nchannels; format;
                                   channelformats; channelnames; alpha_channel;
                                   z_channel; deep;
                                   extra_attribs); // struct ImageSpec

struct ImageInput {
    using BoundType = OIIO::ImageInput;

    static auto open(const std::string& filename, const OIIO::ImageSpec* config,
                     OIIO::Filesystem::IOProxy* ioproxy)
        -> std::unique_ptr<OIIO::ImageInput>;

    CPPMM_IGNORE
    static auto create(OIIO::string_view filename, bool do_open,
                       const OIIO::ImageSpec* config,
                       OIIO::Filesystem::IOProxy* ioproxy,
                       OIIO::string_view plugin_searchpath)
        -> std::unique_ptr<OIIO::ImageInput>;

    CPPMM_IGNORE
    static auto create(const std::string& filename, bool do_open,
                       const OIIO::ImageSpec* config,
                       OIIO::string_view plugin_searchpath)
        -> std::unique_ptr<OIIO::ImageInput>;

    CPPMM_IGNORE
    static auto create(const std::string& filename,
                       const std::string& plugin_searchpath)
        -> std::unique_ptr<OIIO::ImageInput>;

    CPPMM_IGNORE
    static auto destroy(OIIO::ImageInput* x) -> void;

    ~ImageInput();

    auto format_name() const -> const char*;

    auto supports(OIIO::string_view feature) const -> int;

    auto valid_file(const std::string& filename) const -> bool;

    CPPMM_RENAME(open_in)
    auto open(const std::string& name, OIIO::ImageSpec& newspec) -> bool;

    CPPMM_RENAME(open_in_with_config)
    auto open(const std::string& name, OIIO::ImageSpec& newspec,
              const OIIO::ImageSpec& config) -> bool;

    auto spec() const -> const OIIO::ImageSpec&;

    CPPMM_RENAME(spec_for_subimage)
    auto spec(int subimage, int miplevel) -> OIIO::ImageSpec;

    auto spec_dimensions(int subimage, int miplevel) -> OIIO::ImageSpec;
    auto close() -> bool;
    auto current_subimage() const -> int;
    auto current_miplevel() const -> int;

    auto seek_subimage(int subimage, int miplevel) -> bool;

    CPPMM_IGNORE
    auto seek_subimage(int subimage, int miplevel, OIIO::ImageSpec& newspec)
        -> bool;

    CPPMM_IGNORE
    auto seek_subimage(int subimage, OIIO::ImageSpec& newspec) -> bool;

    auto read_scanline(int y, int z, OIIO::TypeDesc format, void* data,
                       long xstride) -> bool;

    CPPMM_RENAME(read_scanline_contiguous)
    auto read_scanline(int y, int z, float* data) -> bool;

    auto read_scanlines(int subimage, int miplevel, int ybegin, int yend, int z,
                        int chbegin, int chend, OIIO::TypeDesc format,
                        void* data, long xstride, long ystride) -> bool;

    CPPMM_IGNORE
    auto read_scanlines(int ybegin, int yend, int z, OIIO::TypeDesc format,
                        void* data, long xstride, long ystride) -> bool;

    CPPMM_IGNORE
    auto read_scanlines(int ybegin, int yend, int z, int chbegin, int chend,
                        OIIO::TypeDesc format, void* data, long xstride,
                        long ystride) -> bool;

    auto read_tile(int x, int y, int z, OIIO::TypeDesc format, void* data,
                   long xstride, long ystride, long zstride) -> bool;

    CPPMM_RENAME(read_tile_contiguous)
    auto read_tile(int x, int y, int z, float* data) -> bool;

    auto read_tiles(int subimage, int miplevel, int xbegin, int xend,
                    int ybegin, int yend, int zbegin, int zend, int chbegin,
                    int chend, OIIO::TypeDesc format, void* data, long xstride,
                    long ystride, long zstride) -> bool;

    CPPMM_IGNORE
    auto read_tiles(int xbegin, int xend, int ybegin, int yend, int zbegin,
                    int zend, OIIO::TypeDesc format, void* data, long xstride,
                    long ystride, long zstride) -> bool;

    CPPMM_IGNORE
    auto read_tiles(int xbegin, int xend, int ybegin, int yend, int zbegin,
                    int zend, int chbegin, int chend, OIIO::TypeDesc format,
                    void* data, long xstride, long ystride, long zstride)
        -> bool;

    auto read_image(int subimage, int miplevel, int chbegin, int chend,
                    OIIO::TypeDesc format, void* data, long xstride,
                    long ystride, long zstride,
                    OIIO::ProgressCallback progress_callback,
                    void* progress_callback_data) -> bool;

    CPPMM_IGNORE
    auto read_image(OIIO::TypeDesc format, void* data, long xstride,
                    long ystride, long zstride,
                    OIIO::ProgressCallback progress_callback,
                    void* progress_callback_data) -> bool;

    CPPMM_IGNORE
    auto read_image(int chbegin, int chend, OIIO::TypeDesc format, void* data,
                    long xstride, long ystride, long zstride,
                    OIIO::ProgressCallback progress_callback,
                    void* progress_callback_data) -> bool;

    CPPMM_IGNORE
    auto read_image(float* data) -> bool;

    auto read_native_deep_scanlines(int subimage, int miplevel, int ybegin,
                                    int yend, int z, int chbegin, int chend,
                                    OIIO::DeepData& deepdata) -> bool;

    auto read_native_deep_tiles(int subimage, int miplevel, int xbegin,
                                int xend, int ybegin, int yend, int zbegin,
                                int zend, int chbegin, int chend,
                                OIIO::DeepData& deepdata) -> bool;

    auto read_native_deep_image(int subimage, int miplevel,
                                OIIO::DeepData& deepdata) -> bool;

    CPPMM_IGNORE
    auto read_native_deep_scanlines(int ybegin, int yend, int z, int chbegin,
                                    int chend, OIIO::DeepData& deepdata)
        -> bool;

    CPPMM_IGNORE
    auto read_native_deep_tiles(int xbegin, int xend, int ybegin, int yend,
                                int zbegin, int zend, int chbegin, int chend,
                                OIIO::DeepData& deepdata) -> bool;

    CPPMM_IGNORE
    auto read_native_deep_image(OIIO::DeepData& deepdata) -> bool;

    auto read_native_scanline(int subimage, int miplevel, int y, int z,
                              void* data) -> bool;

    auto read_native_scanlines(int subimage, int miplevel, int ybegin, int yend,
                               int z, void* data) -> bool;

    CPPMM_RENAME(read_native_scanlines_with_channels)
    auto read_native_scanlines(int subimage, int miplevel, int ybegin, int yend,
                               int z, int chbegin, int chend, void* data)
        -> bool;

    auto read_native_tile(int subimage, int miplevel, int x, int y, int z,
                          void* data) -> bool;

    auto read_native_tiles(int subimage, int miplevel, int xbegin, int xend,
                           int ybegin, int yend, int zbegin, int zend,
                           void* data) -> bool;

    CPPMM_RENAME(read_native_tiles_with_channels)
    auto read_native_tiles(int subimage, int miplevel, int xbegin, int xend,
                           int ybegin, int yend, int zbegin, int zend,
                           int chbegin, int chend, void* data) -> bool;

    auto send_to_input(const char* format) -> int;
    auto send_to_client(const char* format) -> int;
    auto set_ioproxy(OIIO::Filesystem::IOProxy* ioproxy) -> bool;
    bool has_error() const;
    auto geterror(bool clear) const -> std::string;

    template <typename... Args>
    void error(const char* fmt, Args... args) const CPPMM_IGNORE;
    template <typename... Args>
    void errorf(const char* fmt, Args... args) const CPPMM_IGNORE;
    template <typename... Args>
    void errorfmt(const char* fmt, Args... args) const CPPMM_IGNORE;
    template <typename... Args>
    void fmterror(const char* fmt, Args... args) const CPPMM_IGNORE;

    auto threads(int n) -> void;
    CPPMM_RENAME(threads_const)
    auto threads() const -> int;
    auto lock() const -> void;
    auto try_lock() const -> bool;
    auto unlock() const -> void;

    static void* operator new(unsigned long size) CPPMM_IGNORE;
    static void operator delete(void*)CPPMM_IGNORE;

} CPPMM_OPAQUEPTR; // struct ImageInput

struct ImageOutput {
    using BoundType = OIIO::ImageOutput;

    static auto create(OIIO::string_view filename,
                       OIIO::Filesystem::IOProxy* ioproxy,
                       OIIO::string_view plugin_searchpath)
        -> std::unique_ptr<OIIO::ImageOutput>;

    CPPMM_IGNORE
    static auto create(const std::string& filename,
                       const std::string& plugin_searchpath)
        -> std::unique_ptr<OIIO::ImageOutput>;

    CPPMM_IGNORE
    static auto destroy(OIIO::ImageOutput* x) -> void;

    ~ImageOutput();
    auto format_name() const -> const char*;
    auto supports(OIIO::string_view feature) const -> int;

    auto open(const std::string& name, const OIIO::ImageSpec& newspec,
              OIIO::ImageOutput::OpenMode mode) -> bool;

    CPPMM_RENAME(open_subimage)
    auto open(const std::string& name, int subimages,
              const OIIO::ImageSpec* specs) -> bool;

    auto spec() const -> const OIIO::ImageSpec&;
    auto close() -> bool;
    auto write_scanline(int y, int z, OIIO::TypeDesc format, const void* data,
                        long xstride) -> bool;
    auto write_scanlines(int ybegin, int yend, int z, OIIO::TypeDesc format,
                         const void* data, long xstride, long ystride) -> bool;
    auto write_tile(int x, int y, int z, OIIO::TypeDesc format,
                    const void* data, long xstride, long ystride, long zstride)
        -> bool;
    auto write_tiles(int xbegin, int xend, int ybegin, int yend, int zbegin,
                     int zend, OIIO::TypeDesc format, const void* data,
                     long xstride, long ystride, long zstride) -> bool;
    auto write_rectangle(int xbegin, int xend, int ybegin, int yend, int zbegin,
                         int zend, OIIO::TypeDesc format, const void* data,
                         long xstride, long ystride, long zstride) -> bool;
    auto write_image(OIIO::TypeDesc format, const void* data, long xstride,
                     long ystride, long zstride,
                     OIIO::ProgressCallback progress_callback,
                     void* progress_callback_data) -> bool;
    auto write_deep_scanlines(int ybegin, int yend, int z,
                              const OIIO::DeepData& deepdata) -> bool;
    auto write_deep_tiles(int xbegin, int xend, int ybegin, int yend,
                          int zbegin, int zend, const OIIO::DeepData& deepdata)
        -> bool;
    auto write_deep_image(const OIIO::DeepData& deepdata) -> bool;
    auto copy_image(OIIO::ImageInput* in) -> bool;
    auto send_to_output(const char* format) -> int;
    auto send_to_client(const char* format) -> int;
    auto set_ioproxy(OIIO::Filesystem::IOProxy* ioproxy) -> bool;
    bool has_error() const;
    auto geterror(bool clear) const -> std::string;
    template <typename... Args>
    void error(const char* fmt, Args... args) const CPPMM_IGNORE;
    template <typename... Args>
    void errorf(const char* fmt, Args... args) const CPPMM_IGNORE;
    template <typename... Args>
    void errorfmt(const char* fmt, Args... args) const CPPMM_IGNORE;
    template <typename... Args>
    void fmterror(const char* fmt, Args... args) const CPPMM_IGNORE;
    auto threads(int n) -> void;
    CPPMM_RENAME(threads_const)
    auto threads() const -> int;

    enum OpenMode {
        Create = 0,
        AppendSubimage = 1,
        AppendMIPLevel = 2,
    };

    static void* operator new(unsigned long size) CPPMM_IGNORE;
    static void operator delete(void*)CPPMM_IGNORE;

} CPPMM_OPAQUEPTR; // struct ImageOutput

auto openimageio_version() -> int;

auto geterror(bool clear) -> std::string;

auto attribute(OIIO::string_view name, OIIO::TypeDesc type, const void* val)
    -> bool;

CPPMM_RENAME(attribute_int)
auto attribute(OIIO::string_view name, int val) -> bool;

CPPMM_RENAME(attribute_float)
auto attribute(OIIO::string_view name, float val) -> bool;

CPPMM_RENAME(attribute_string)
auto attribute(OIIO::string_view name, OIIO::string_view val) -> bool;

auto getattribute(OIIO::string_view name, OIIO::TypeDesc type, void* val)
    -> bool;

CPPMM_RENAME(getattribute_int)
auto getattribute(OIIO::string_view name, int& val) -> bool;

CPPMM_RENAME(getattribute_float)
auto getattribute(OIIO::string_view name, float& val) -> bool;

CPPMM_RENAME(getattribute_string)
auto getattribute(OIIO::string_view name, std::string& val) -> bool;

CPPMM_RENAME(getattribute_cstr)
auto getattribute(OIIO::string_view name, char** val) -> bool;

auto get_int_attribute(OIIO::string_view name, int defaultval) -> int;

auto get_float_attribute(OIIO::string_view name, float defaultval) -> float;

auto get_string_attribute(OIIO::string_view name, OIIO::string_view defaultval)
    -> OIIO::string_view;

CPPMM_IGNORE
auto declare_imageio_format(const std::string& format_name,
                            OIIO::ImageInput::Creator input_creator,
                            const char** input_extensions,
                            OIIO::ImageOutput::Creator output_creator,
                            const char** output_extensions,
                            const char* lib_version) -> void;

auto convert_pixel_values(OIIO::TypeDesc src_type, const void* src,
                          OIIO::TypeDesc dst_type, void* dst, int n) -> bool;

auto convert_types(OIIO::TypeDesc src_type, const void* src,
                   OIIO::TypeDesc dst_type, void* dst, int n) -> bool;

auto convert_image(int nchannels, int width, int height, int depth,
                   const void* src, OIIO::TypeDesc src_type, long src_xstride,
                   long src_ystride, long src_zstride, void* dst,
                   OIIO::TypeDesc dst_type, long dst_xstride, long dst_ystride,
                   long dst_zstride) -> bool;

CPPMM_IGNORE
auto convert_image(int nchannels, int width, int height, int depth,
                   const void* src, OIIO::TypeDesc src_type, long src_xstride,
                   long src_ystride, long src_zstride, void* dst,
                   OIIO::TypeDesc dst_type, long dst_xstride, long dst_ystride,
                   long dst_zstride, int p1, int p2) -> bool;

auto parallel_convert_image(int nchannels, int width, int height, int depth,
                            const void* src, OIIO::TypeDesc src_type,
                            long src_xstride, long src_ystride,
                            long src_zstride, void* dst,
                            OIIO::TypeDesc dst_type, long dst_xstride,
                            long dst_ystride, long dst_zstride, int nthreads)
    -> bool;

CPPMM_IGNORE
auto parallel_convert_image(int nchannels, int width, int height, int depth,
                            const void* src, OIIO::TypeDesc src_type,
                            long src_xstride, long src_ystride,
                            long src_zstride, void* dst,
                            OIIO::TypeDesc dst_type, long dst_xstride,
                            long dst_ystride, long dst_zstride, int p1, int p2,
                            int nthreads) -> bool;

auto add_dither(int nchannels, int width, int height, int depth, float* data,
                long xstride, long ystride, long zstride, float ditheramplitude,
                int alpha_channel, int z_channel, unsigned int ditherseed,
                int chorigin, int xorigin, int yorigin, int zorigin) -> void;

auto premult(int nchannels, int width, int height, int depth, int chbegin,
             int chend, OIIO::TypeDesc datatype, void* data, long xstride,
             long ystride, long zstride, int alpha_channel, int z_channel)
    -> void;

auto copy_image(int nchannels, int width, int height, int depth,
                const void* src, long pixelsize, long src_xstride,
                long src_ystride, long src_zstride, void* dst, long dst_xstride,
                long dst_ystride, long dst_zstride) -> bool;

auto wrap_black(int& coord, int origin, int width) -> bool;

auto wrap_clamp(int& coord, int origin, int width) -> bool;

auto wrap_periodic(int& coord, int origin, int width) -> bool;

auto wrap_periodic_pow2(int& coord, int origin, int width) -> bool;

auto wrap_mirror(int& coord, int origin, int width) -> bool;

auto debug(OIIO::string_view str) -> void;

template <typename T1, typename... Args>
void debugfmt(const char* fmt, const T1& v1, Args... args) CPPMM_IGNORE;

template <typename T1, typename... Args>
void fmtdebug(const char* fmt, const T1& v1, Args... args) CPPMM_IGNORE;

template <typename T1, typename... Args>
void debugf(const char* fmt, const T1& v1, Args... args) CPPMM_IGNORE;

template <typename T1, typename... Args>
void debug(const char* fmt, const T1& v1, Args... args) CPPMM_IGNORE;

auto _ImageIO_force_link() -> void;

} // namespace OIIO_NAMESPACE

} // namespace cppmm_bind
