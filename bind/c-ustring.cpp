#include <OpenImageIO/ustring.h>
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OIIO_NAMESPACE {

namespace OIIO = ::OIIO_NAMESPACE;

struct ustring {
    using BoundType = OIIO::ustring;

    ustring() CPPMM_IGNORE;

    ustring(const char* str);

    CPPMM_IGNORE
    ustring(OIIO::string_view str);

    CPPMM_IGNORE
    ustring(const char* str, size_t pos, size_t n);

    CPPMM_IGNORE
    ustring(const char* str, size_t n);

    CPPMM_IGNORE
    ustring(size_t n, char c);

    CPPMM_IGNORE
    ustring(const std::string& str, size_t pos, size_t n);

    CPPMM_RENAME(copy)
    ustring(const OIIO::ustring& str);

    CPPMM_IGNORE
    ustring(const OIIO::ustring& str, size_t pos, size_t n);
    ~ustring();

    operator OIIO::string_view() const CPPMM_IGNORE;
    operator std::string() const CPPMM_IGNORE;

    CPPMM_IGNORE
    auto assign(const OIIO::ustring& str) -> const OIIO::ustring&;

    CPPMM_IGNORE
    auto assign(const OIIO::ustring& str, size_t pos, size_t n)
        -> const OIIO::ustring&;

    CPPMM_IGNORE
    auto assign(const std::string& str) -> const OIIO::ustring&;

    CPPMM_IGNORE
    auto assign(const std::string& str, size_t pos, size_t n)
        -> const OIIO::ustring&;

    CPPMM_IGNORE
    auto assign(const char* str) -> const OIIO::ustring&;

    CPPMM_IGNORE
    auto assign(const char* str, size_t n) -> const OIIO::ustring&;
    CPPMM_IGNORE
    auto assign(size_t n, char c) -> const OIIO::ustring&;
    CPPMM_IGNORE
    auto assign(OIIO::string_view str) -> const OIIO::ustring&;
    auto operator=(const OIIO::ustring& str) -> const OIIO::ustring&;
    CPPMM_IGNORE
    auto operator=(const char* str) -> const OIIO::ustring&;
    CPPMM_IGNORE
    auto operator=(const std::string& str) -> const OIIO::ustring&;
    CPPMM_IGNORE
    auto operator=(OIIO::string_view str) -> const OIIO::ustring&;
    CPPMM_IGNORE
    auto operator=(char c) -> const OIIO::ustring&;
    auto c_str() const -> const char*;
    auto data() const -> const char*;
    CPPMM_IGNORE
    auto string() const -> const std::string&;
    auto clear() -> void;
    auto length() const -> size_t;
    auto hash() const -> size_t;
    auto size() const -> size_t;
    auto empty() const -> bool;
    CPPMM_IGNORE
    auto begin() const
        -> __gnu_cxx::__normal_iterator<const char*,
                                        std::__cxx11::basic_string<char>>;
    CPPMM_IGNORE
    auto end() const
        -> __gnu_cxx::__normal_iterator<const char*,
                                        std::__cxx11::basic_string<char>>;
    CPPMM_IGNORE
    auto rbegin() const -> std::reverse_iterator<__gnu_cxx::__normal_iterator<
        const char*, std::__cxx11::basic_string<char>>>;
    CPPMM_IGNORE
    auto rend() const -> std::reverse_iterator<__gnu_cxx::__normal_iterator<
        const char*, std::__cxx11::basic_string<char>>>;
    CPPMM_IGNORE
    auto operator[](size_t pos) const -> const char&;
    CPPMM_IGNORE
    auto copy(char* s, size_t n, size_t pos) const
        -> size_t;
    CPPMM_IGNORE
    auto substr(size_t pos, size_t n) const -> OIIO::ustring;
    CPPMM_IGNORE
    auto find(const OIIO::ustring& str, size_t pos) const
        -> size_t;
    CPPMM_IGNORE
    auto find(const std::string& str, size_t pos) const -> size_t;
    CPPMM_IGNORE
    auto find(const char* s, size_t pos, size_t n) const
        -> size_t;
    CPPMM_IGNORE
    auto find(const char* s, size_t pos) const -> size_t;
    CPPMM_IGNORE
    auto find(char c, size_t pos) const -> size_t;
    CPPMM_IGNORE
    auto rfind(const OIIO::ustring& str, size_t pos) const
        -> size_t;
    CPPMM_IGNORE
    auto rfind(const std::string& str, size_t pos) const
        -> size_t;
    CPPMM_IGNORE
    auto rfind(const char* s, size_t pos, size_t n) const
        -> size_t;
    CPPMM_IGNORE
    auto rfind(const char* s, size_t pos) const -> size_t;
    CPPMM_IGNORE
    auto rfind(char c, size_t pos) const -> size_t;
    CPPMM_IGNORE
    auto find_first_of(const OIIO::ustring& str, size_t pos) const
        -> size_t;
    CPPMM_IGNORE
    auto find_first_of(const std::string& str, size_t pos) const
        -> size_t;
    CPPMM_IGNORE
    auto find_first_of(const char* s, size_t pos, size_t n) const
        -> size_t;
    CPPMM_IGNORE
    auto find_first_of(const char* s, size_t pos) const -> size_t;
    CPPMM_IGNORE
    auto find_first_of(char c, size_t pos) const -> size_t;
    CPPMM_IGNORE
    auto find_last_of(const OIIO::ustring& str, size_t pos) const
        -> size_t;
    CPPMM_IGNORE
    auto find_last_of(const std::string& str, size_t pos) const
        -> size_t;
    CPPMM_IGNORE
    auto find_last_of(const char* s, size_t pos, size_t n) const
        -> size_t;
    CPPMM_IGNORE
    auto find_last_of(const char* s, size_t pos) const -> size_t;
    CPPMM_IGNORE
    auto find_last_of(char c, size_t pos) const -> size_t;
    CPPMM_IGNORE
    auto find_first_not_of(const OIIO::ustring& str, size_t pos) const
        -> size_t;
    CPPMM_IGNORE
    auto find_first_not_of(const std::string& str, size_t pos) const
        -> size_t;
    CPPMM_IGNORE
    auto find_first_not_of(const char* s, size_t pos,
                           size_t n) const -> size_t;
    CPPMM_IGNORE
    auto find_first_not_of(const char* s, size_t pos) const
        -> size_t;
    CPPMM_IGNORE
    auto find_first_not_of(char c, size_t pos) const -> size_t;
    CPPMM_IGNORE
    auto find_last_not_of(const OIIO::ustring& str, size_t pos) const
        -> size_t;
    CPPMM_IGNORE
    auto find_last_not_of(const std::string& str, size_t pos) const
        -> size_t;
    CPPMM_IGNORE
    auto find_last_not_of(const char* s, size_t pos,
                          size_t n) const -> size_t;
    CPPMM_IGNORE
    auto find_last_not_of(const char* s, size_t pos) const
        -> size_t;
    CPPMM_IGNORE
    auto find_last_not_of(char c, size_t pos) const -> size_t;
    CPPMM_IGNORE
    auto compare(OIIO::string_view str) const -> int;
    CPPMM_IGNORE
    auto compare(const char* str) const -> int;

    auto operator==(const OIIO::ustring& str) const -> bool;
    auto operator!=(const OIIO::ustring& str) const -> bool;

    CPPMM_IGNORE
    auto operator==(const std::string& x) const -> bool;
    CPPMM_IGNORE
    auto operator==(OIIO::string_view x) const -> bool;
    CPPMM_IGNORE
    auto operator==(const char* x) const -> bool;
    CPPMM_IGNORE
    auto operator!=(const std::string& x) const -> bool;
    CPPMM_IGNORE
    auto operator!=(OIIO::string_view x) const -> bool;
    CPPMM_IGNORE
    auto operator!=(const char* x) const -> bool;
    CPPMM_IGNORE
    auto operator<(const OIIO::ustring& x) const -> bool;

    template <typename... Args>
    static OIIO::ustring sprintf(const char* fmt, Args... args) CPPMM_IGNORE;

    template <typename... Args>
    static OIIO::ustring fmtformat(const char* fmt, Args... args) CPPMM_IGNORE;

    template <typename... Args>
    static OIIO::ustring format(const char* fmt, Args... args) CPPMM_IGNORE;

    CPPMM_IGNORE
    static auto concat(OIIO::string_view s, OIIO::string_view t)
        -> OIIO::ustring;

    CPPMM_IGNORE
    static auto getstats(bool verbose) -> std::string;

    CPPMM_IGNORE
    static auto memory() -> size_t;

    CPPMM_IGNORE
    static auto make_unique(OIIO::string_view str) -> const char*;

    CPPMM_IGNORE
    static auto is_unique(const char* str) -> bool;

    CPPMM_IGNORE
    static auto from_unique(const char* unique) -> OIIO::ustring;

    /// Return the total number of ustrings in the internal table.
    static size_t total_ustrings();

    /// Return the total number ustrings that have the exact hash as another
    /// ustring. If `collisions` is passed, store all the colliding ustrings
    /// in the vector.
    static size_t hash_collisions(std::vector<OIIO::ustring>* collisions);

} CPPMM_OPAQUEBYTES CPPMM_TRIVIALLY_MOVABLE
    CPPMM_TRIVIALLY_COPYABLE; // struct ustring

CPPMM_IGNORE
auto iequals(OIIO::ustring a, OIIO::ustring b) -> bool;

CPPMM_IGNORE
auto iequals(OIIO::ustring a, const std::string& b) -> bool;

CPPMM_IGNORE
auto iequals(const std::string& a, OIIO::ustring b) -> bool;

} // namespace OIIO_NAMESPACE

} // namespace cppmm_bind
