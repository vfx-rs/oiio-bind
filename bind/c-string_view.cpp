#include <OpenImageIO/string_view.h>
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OIIO_NAMESPACE {

namespace OIIO = ::OIIO_NAMESPACE;

struct string_view {
    using BoundType = OIIO::string_view;

    string_view();

    CPPMM_RENAME(copy)
    string_view(const OIIO::string_view& copy);

    CPPMM_RENAME(from_char_array)
    string_view(const char* chars, unsigned long len);

    CPPMM_RENAME(from_c_str)
    string_view(const char* chars);

    CPPMM_RENAME(from_string)
    string_view(const std::string& str);

    auto str() const -> std::string;
    auto c_str() const -> const char*;
    auto operator=(const OIIO::string_view& copy) -> OIIO::string_view&;

    CPPMM_IGNORE
    operator std::string() const;

    auto begin() const -> const char*;
    auto end() const -> const char*;
    auto cbegin() const -> const char*;
    auto cend() const -> const char*;

    CPPMM_IGNORE
    auto rbegin() const -> std::reverse_iterator<const char*>;

    CPPMM_IGNORE
    auto rend() const -> std::reverse_iterator<const char*>;

    CPPMM_IGNORE
    auto crbegin() const -> std::reverse_iterator<const char*>;

    CPPMM_IGNORE
    auto crend() const -> std::reverse_iterator<const char*>;

    auto size() const -> unsigned long;
    auto length() const -> unsigned long;
    auto max_size() const -> unsigned long;
    auto empty() const -> bool;

    auto operator[](unsigned long pos) const -> const char&;
    auto at(unsigned long pos) const -> const char&;

    CPPMM_IGNORE
    auto front() const -> const char&;

    CPPMM_IGNORE
    auto back() const -> const char&;

    auto data() const -> const char*;

    auto clear() -> void;
    CPPMM_IGNORE
    auto remove_prefix(unsigned long n) -> void;

    CPPMM_IGNORE
    auto remove_suffix(unsigned long n) -> void;

    CPPMM_IGNORE
    auto substr(unsigned long pos, unsigned long n) const -> OIIO::string_view;

    CPPMM_IGNORE
    auto compare(OIIO::string_view x) const -> int;

    CPPMM_IGNORE
    auto find(OIIO::string_view s, unsigned long pos) const -> unsigned long;

    CPPMM_IGNORE
    auto find(char c, unsigned long pos) const -> unsigned long;

    CPPMM_IGNORE
    auto rfind(OIIO::string_view s, unsigned long pos) const -> unsigned long;

    CPPMM_IGNORE
    auto rfind(char c, unsigned long pos) const -> unsigned long;

    CPPMM_IGNORE
    auto find_first_of(char c, unsigned long pos) const -> unsigned long;

    CPPMM_IGNORE
    auto find_last_of(char c, unsigned long pos) const -> unsigned long;

    CPPMM_IGNORE
    auto find_first_of(OIIO::string_view s, unsigned long pos) const
        -> unsigned long;

    CPPMM_IGNORE
    auto find_last_of(OIIO::string_view s, unsigned long pos) const
        -> unsigned long;

    CPPMM_IGNORE
    auto find_first_not_of(OIIO::string_view s, unsigned long pos) const
        -> unsigned long;

    CPPMM_IGNORE
    auto find_first_not_of(char c, unsigned long pos) const -> unsigned long;

    CPPMM_IGNORE
    auto find_last_not_of(OIIO::string_view s, unsigned long pos) const
        -> unsigned long;

    CPPMM_IGNORE
    auto find_last_not_of(char c, unsigned long pos) const -> unsigned long;

    ~string_view();

} CPPMM_OPAQUEBYTES; // struct string_view

CPPMM_IGNORE
auto operator==(OIIO::string_view x, OIIO::string_view y) -> bool;

CPPMM_IGNORE
auto operator!=(OIIO::string_view x, OIIO::string_view y) -> bool;

CPPMM_IGNORE
auto operator<(OIIO::string_view x, OIIO::string_view y) -> bool;

CPPMM_IGNORE
auto operator>(OIIO::string_view x, OIIO::string_view y) -> bool;

CPPMM_IGNORE
auto operator<=(OIIO::string_view x, OIIO::string_view y) -> bool;

CPPMM_IGNORE
auto operator>=(OIIO::string_view x, OIIO::string_view y) -> bool;

CPPMM_IGNORE
auto operator<<(std::basic_ostream<char>& out, const OIIO::string_view& str)
    -> std::basic_ostream<char>&;

} // namespace OIIO_NAMESPACE

} // namespace cppmm_bind
