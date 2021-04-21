#include <OpenImageIO/filesystem.h>
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OIIO_NAMESPACE {

namespace OIIO = ::OIIO_NAMESPACE;

namespace Filesystem {

auto filename(const std::string& filepath) -> std::string;

auto extension(const std::string& filepath, bool include_dot) -> std::string;

auto parent_path(const std::string& filepath) -> std::string;

auto replace_extension(const std::string& filepath,
                       const std::string& new_extension) -> std::string;

auto searchpath_split(const std::string& searchpath,
                      std::vector<std::string>& dirs, bool validonly) -> void;

auto searchpath_find(const std::string& filename,
                     const std::vector<std::string>& dirs, bool testcwd,
                     bool recursive) -> std::string;

auto get_directory_entries(const std::string& dirname,
                           std::vector<std::string>& filenames, bool recursive,
                           const std::string& filter_regex) -> bool;

auto path_is_absolute(OIIO::string_view path, bool dot_is_absolute) -> bool;

auto exists(OIIO::string_view path) -> bool;

auto is_directory(OIIO::string_view path) -> bool;

auto is_regular(OIIO::string_view path) -> bool;

auto create_directory(OIIO::string_view path, std::string& err) -> bool;

CPPMM_IGNORE
auto create_directory(OIIO::string_view path) -> bool;

auto copy(OIIO::string_view from, OIIO::string_view to, std::string& err)
    -> bool;

CPPMM_IGNORE
auto copy(OIIO::string_view from, OIIO::string_view to) -> bool;

auto rename(OIIO::string_view from, OIIO::string_view to, std::string& err)
    -> bool;

CPPMM_IGNORE
auto rename(OIIO::string_view from, OIIO::string_view to) -> bool;

auto remove(OIIO::string_view path, std::string& err) -> bool;

CPPMM_IGNORE
auto remove(OIIO::string_view path) -> bool;

auto remove_all(OIIO::string_view path, std::string& err) -> unsigned long long;

CPPMM_IGNORE
auto remove_all(OIIO::string_view path) -> unsigned long long;

auto temp_directory_path() -> std::string;

auto unique_path(OIIO::string_view model) -> std::string;

CPPMM_IGNORE
auto fopen(OIIO::string_view path, OIIO::string_view mode) -> _IO_FILE*;

CPPMM_IGNORE
auto fseek(_IO_FILE* file, long offset, int whence) -> int;

CPPMM_IGNORE
auto ftell(_IO_FILE* file) -> long;

auto current_path() -> std::string;

CPPMM_IGNORE
auto open(std::basic_ifstream<char>& stream, OIIO::string_view path,
          std::_Ios_Openmode mode) -> void;

CPPMM_IGNORE
auto open(std::basic_ofstream<char>& stream, OIIO::string_view path,
          std::_Ios_Openmode mode) -> void;

auto read_text_file(OIIO::string_view filename, std::string& str) -> bool;

auto write_text_file(OIIO::string_view filename, OIIO::string_view str) -> bool;

auto read_bytes(OIIO::string_view path, void* buffer, unsigned long n,
                unsigned long pos) -> unsigned long;

auto last_write_time(OIIO::string_view path) -> long;

CPPMM_IGNORE
auto last_write_time(OIIO::string_view path, long time) -> void;

auto file_size(OIIO::string_view path) -> unsigned long;

auto convert_native_arguments(int argc, const char** argv) -> void;

auto enumerate_sequence(OIIO::string_view desc,
                        std::vector<int, std::allocator<int>>& numbers) -> bool;

auto parse_pattern(const char* pattern, int framepadding_override,
                   std::string& normalized_pattern, std::string& framespec)
    -> bool;

auto enumerate_file_sequence(const std::string& pattern,
                             const std::vector<int>& numbers,
                             std::vector<std::string>& filenames) -> bool;

CPPMM_RENAME(enumerate_file_sequence_with_views)
auto enumerate_file_sequence(const std::string& pattern,
                             const std::vector<int>& numbers,
                             const std::vector<OIIO::string_view>& views,
                             std::vector<std::string>& filenames) -> bool;

CPPMM_RENAME(scan_for_matching_filenames_with_views)
auto scan_for_matching_filenames(const std::string& pattern,
                                 const std::vector<OIIO::string_view>& views,
                                 std::vector<int>& frame_numbers,
                                 std::vector<OIIO::string_view>& frame_views,
                                 std::vector<std::string>& filenames) -> bool;

auto scan_for_matching_filenames(const std::string& pattern,
                                 std::vector<int>& numbers,
                                 std::vector<std::string>& filenames) -> bool;

struct IOProxy {
    using BoundType = OIIO::Filesystem::IOProxy;

    CPPMM_RENAME(default)
    IOProxy();
    CPPMM_RENAME(new)
    IOProxy(OIIO::string_view filename, OIIO::Filesystem::IOProxy::Mode mode);
    ~IOProxy();
    auto proxytype() const -> const char*;
    auto close() -> void;
    auto opened() const -> bool;
    auto tell() -> long;
    auto seek(long offset) -> bool;
    auto read(void* buf, unsigned long size) -> unsigned long;
    auto write(const void* buf, unsigned long size) -> unsigned long;
    auto pread(void* buf, unsigned long size, long offset) -> unsigned long;
    auto pwrite(const void* buf, unsigned long size, long offset)
        -> unsigned long;
    auto size() const -> unsigned long;
    auto flush() const -> void;
    auto mode() const -> OIIO::Filesystem::IOProxy::Mode;
    auto filename() const -> const std::string&;
    template <typename T> auto read(OIIO::span<T, -1> buf) -> unsigned long;
    template <typename T> auto write(OIIO::span<T, -1> buf) -> unsigned long;
    auto write(OIIO::string_view buf) -> unsigned long;
    auto seek(long offset, int origin) -> bool;
    auto error() const -> std::string;

    CPPMM_IGNORE
    auto error(OIIO::string_view e) -> void;

    CPPMM_RENAME(from_proxy)
    IOProxy(const OIIO::Filesystem::IOProxy&);
    auto operator=(const OIIO::Filesystem::IOProxy& rhs)
        -> OIIO::Filesystem::IOProxy&;

    enum Mode {
        Closed = 0,
        Read = 114,
        Write = 119,
    };
} CPPMM_OPAQUEPTR; // struct IOProxy

struct IOFile {
    using BoundType = OIIO::Filesystem::IOFile;

    auto proxytype() const -> const char*;
    auto close() -> void;
    auto opened() const -> bool;
    auto tell() -> long;
    auto seek(long offset) -> bool;
    auto read(void* buf, unsigned long size) -> unsigned long;
    auto write(const void* buf, unsigned long size) -> unsigned long;
    auto pread(void* buf, unsigned long size, long offset) -> unsigned long;
    auto pwrite(const void* buf, unsigned long size, long offset)
        -> unsigned long;
    auto size() const -> unsigned long;
    auto flush() const -> void;
    auto mode() const -> OIIO::Filesystem::IOProxy::Mode;
    auto filename() const -> const std::string&;
    template <typename T> auto read(OIIO::span<T, -1> buf) -> unsigned long;
    template <typename T> auto write(OIIO::span<T, -1> buf) -> unsigned long;
    auto error() const -> std::string;

    CPPMM_IGNORE
    auto error(OIIO::string_view e) -> void;

    CPPMM_RENAME(new)
    IOFile(OIIO::string_view filename, OIIO::Filesystem::IOProxy::Mode mode);

    CPPMM_IGNORE
    IOFile(_IO_FILE* file, OIIO::Filesystem::IOProxy::Mode mode);

    ~IOFile();

    CPPMM_IGNORE
    auto handle() const -> _IO_FILE*;

    CPPMM_IGNORE
    IOFile(const OIIO::Filesystem::IOFile& rhs);

    CPPMM_IGNORE
    auto operator=(const OIIO::Filesystem::IOFile& rhs)
        -> OIIO::Filesystem::IOFile&;
} CPPMM_OPAQUEBYTES; // struct IOFile

struct IOVecOutput {
    using BoundType = OIIO::Filesystem::IOVecOutput;

    auto proxytype() const -> const char*;
    auto close() -> void;
    auto opened() const -> bool;
    auto tell() -> long;
    auto seek(long offset) -> bool;
    auto read(void* buf, unsigned long size) -> unsigned long;
    auto write(const void* buf, unsigned long size) -> unsigned long;
    auto pread(void* buf, unsigned long size, long offset) -> unsigned long;
    auto pwrite(const void* buf, unsigned long size, long offset)
        -> unsigned long;
    auto size() const -> unsigned long;
    auto flush() const -> void;
    auto mode() const -> OIIO::Filesystem::IOProxy::Mode;
    auto filename() const -> const std::string&;
    template <typename T> auto read(OIIO::span<T, -1> buf) -> unsigned long;
    template <typename T> auto write(OIIO::span<T, -1> buf) -> unsigned long;

    auto seek(long offset, int origin) -> bool;
    auto error() const -> std::string;
    auto error(OIIO::string_view e) -> void;

    IOVecOutput();
    IOVecOutput(std::vector<unsigned char>& buf) CPPMM_RENAME(from_buf);
    auto buffer() const -> std::vector<unsigned char>&;

    CPPMM_IGNORE
    IOVecOutput(const OIIO::Filesystem::IOVecOutput& rhs);

    IOVecOutput(OIIO::Filesystem::IOVecOutput&&) CPPMM_IGNORE;

    CPPMM_IGNORE
    auto operator=(const OIIO::Filesystem::IOVecOutput& rhs)
        -> OIIO::Filesystem::IOVecOutput&;

    CPPMM_IGNORE
    auto operator=(OIIO::Filesystem::IOVecOutput &&)
        -> OIIO::Filesystem::IOVecOutput&;
    ~IOVecOutput();
} CPPMM_OPAQUEBYTES; // struct IOVecOutput

struct IOMemReader {
    using BoundType = OIIO::Filesystem::IOMemReader;

    auto proxytype() const -> const char*;
    auto close() -> void;
    auto opened() const -> bool;
    auto tell() -> long;
    auto seek(long offset) -> bool;
    auto read(void* buf, unsigned long size) -> unsigned long;
    auto write(const void* buf, unsigned long size) -> unsigned long;
    auto pread(void* buf, unsigned long size, long offset) -> unsigned long;
    auto pwrite(const void* buf, unsigned long size, long offset)
        -> unsigned long;
    auto size() const -> unsigned long;
    auto flush() const -> void;
    auto mode() const -> OIIO::Filesystem::IOProxy::Mode;
    auto filename() const -> const std::string&;
    template <typename T> auto read(OIIO::span<T, -1> buf) -> unsigned long;
    template <typename T> auto write(OIIO::span<T, -1> buf) -> unsigned long;
    auto error() const -> std::string;

    CPPMM_IGNORE
    auto error(OIIO::string_view e) -> void;

    CPPMM_RENAME(from_buf)
    IOMemReader(void* buf, unsigned long size);

    CPPMM_IGNORE
    IOMemReader(OIIO::span<const unsigned char, -1> buf);
    auto buffer() const -> OIIO::span<const unsigned char, -1>;
    IOMemReader(const OIIO::Filesystem::IOMemReader& rhs);

    CPPMM_IGNORE
    IOMemReader(OIIO::Filesystem::IOMemReader&&);
    auto operator=(const OIIO::Filesystem::IOMemReader& rhs)
        -> OIIO::Filesystem::IOMemReader&;

    CPPMM_IGNORE
    auto operator=(OIIO::Filesystem::IOMemReader &&)
        -> OIIO::Filesystem::IOMemReader&;
    ~IOMemReader();
} CPPMM_OPAQUEBYTES; // struct IOMemReader

} // namespace Filesystem

} // namespace OIIO_NAMESPACE

} // namespace cppmm_bind
