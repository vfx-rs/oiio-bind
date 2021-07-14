#include <OpenImageIO/span.h>
#include <OpenImageIO/typedesc.h>
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OIIO_NAMESPACE {

namespace OIIO = ::OIIO_NAMESPACE;

template <class T, ptrdiff_t Extent = -1> struct span {
    using BoundType = OIIO::span<T, Extent>;

    span<T, Extent>();

    template <typename U, ptrdiff_t N>
    span<T, N>(const OIIO::span<U, N>& copy) CPPMM_IGNORE;

    CPPMM_RENAME(copy)
    span<T, Extent>(const OIIO::span<T, Extent>& copy);

    CPPMM_RENAME(from_ptr)
    span<T, Extent>(T* data, long size);

    CPPMM_RENAME(from_begin_end)
    span<T, Extent>(T* b, T* e);

    CPPMM_RENAME(from_value)
    span<T, Extent>(T& data);

    template <typename Allocator>
    span<T, Extent>(std::vector<T, Allocator>& v) CPPMM_IGNORE;

    template <typename Allocator>
    span<T, Extent>(const std::vector<T, Allocator>& v) CPPMM_IGNORE;

    template <ptrdiff_t N> span<T, Extent>(std::array<T, N>& arr) CPPMM_IGNORE;

    template <ptrdiff_t N>
    span<T, Extent>(const std::array<T, N>& arr) CPPMM_IGNORE;

    auto operator=(const OIIO::span<T, Extent>& copy) -> OIIO::span<T, Extent>&;

    auto size() const -> long;
    auto size_bytes() const -> long;
    auto empty() const -> bool;
    auto data() const -> T*;
    auto operator[](long idx) const -> T&;
    CPPMM_IGNORE
    auto operator()(long idx) const -> T&;
    auto at(long idx) const -> T&;
    CPPMM_IGNORE
    auto front() const -> T&;
    CPPMM_IGNORE
    auto back() const -> T&;
    auto begin() const -> T*;
    auto end() const -> T*;
    auto cbegin() const -> const T*;
    auto cend() const -> const T*;
} CPPMM_OPAQUEBYTES CPPMM_IGNORE_UNBOUND CPPMM_TRIVIALLY_MOVABLE
    CPPMM_TRIVIALLY_COPYABLE; // struct span

// TODO: fill in explicit instantiations, e.g.:
// template class span<int, int>;
// using spanInt = OIIO::span<int, int>;

template class span<const OIIO::TypeDesc>;
using cspan_TypeDesc = OIIO::span<const OIIO::TypeDesc>;

template class span<const float>;
using cspan_float = OIIO::span<const float>;

template class span<float>;
using span_float = OIIO::span<float>;

template class span<const unsigned int>;
using cspan_uint = OIIO::span<const unsigned int>;

template class span<const int>;
using cspan_int = OIIO::span<const int>;

template class span<const char>;
using cspan_char = OIIO::span<const char>;

template class span<const unsigned char>;
using cspan_uchar = OIIO::span<const unsigned char>;

template class span<const std::string>;
using cspan_string = OIIO::span<const std::string>;

/*
template <typename T, ptrdiff_t X, typename U, ptrdiff_t Y>
auto operator==(OIIO::span<T, X> l, OIIO::span<U, Y> r) -> bool;

template <typename T, ptrdiff_t X, typename U, ptrdiff_t Y>
auto operator!=(OIIO::span<T, X> l, OIIO::span<U, Y> r) -> bool;

template <class T, class Extent> struct span_strided {
    using BoundType = OIIO::span_strided<T, Extent>;

    span_strided<T, Extent>();
    span_strided<T, Extent>(const OIIO::span_strided<T, Extent>& copy);
    span_strided<T, Extent>(T* data, long size, long stride);
    span_strided<T, Extent>(T& data);
    template <typename N> auto span_strided<T, Extent>(UNKNOWN& data) -> void;
    template <typename Allocator>
    auto span_strided<T, Extent>(vector<_Tp, _Alloc>& v) -> void;
    template <typename Allocator>
    auto span_strided<T, Extent>(const vector<_Tp, _Alloc>& v) -> void;
    span_strided<T, Extent>(UNKNOWN il);
    span_strided<T, Extent>(OIIO::span<T, Extent> av);
    auto operator=(const OIIO::span_strided<T, Extent>& copy)
        -> OIIO::span_strided<T, Extent>&;
    auto size() const -> long;
    auto stride() const -> long;
    auto operator[](long idx) const -> T&;
    auto operator()(long idx) const -> T&;
    auto at(long idx) const -> T&;
    auto front() const -> T&;
    auto back() const -> T&;
    auto data() const -> T*;
} CPPMM_OPAQUEBYTES; // struct span_strided

// TODO: fill in explicit instantiations, e.g.:
// template class span_strided<int, int>;
// using span_stridedInt = OIIO::span_strided<int, int>;

template <typename T, typename X, typename U, typename Y>
auto operator==(OIIO::span_strided<T, Extent> l,
                OIIO::span_strided<T, Extent> r) -> bool;

template <typename T, typename X, typename U, typename Y>
auto operator!=(OIIO::span_strided<T, Extent> l,
                OIIO::span_strided<T, Extent> r) -> bool;
*/

} // namespace OIIO_NAMESPACE

} // namespace cppmm_bind

// TODO: fill in explicit instantiations
// template class OIIO::span<int, int>;
// template class OIIO::span_strided<int, int>;
//
// template class OIIO::span<const float>;
// template class OIIO::span<const int>;
// template class OIIO::span<const unsigned int>;
// template class OIIO::span<const char>;
// template class OIIO::span<const unsigned char>;
// template class OIIO::span<const std::string>;

OIIO::span<const OIIO::TypeDesc> dummy0;
extern template OIIO::span<const OIIO::TypeDesc>::span(
    const OIIO::TypeDesc* data, long size);

OIIO::span<const float> dummy1;
extern template OIIO::span<const float>::span(const float* data, long size);

OIIO::span<float> dummy2;
extern template OIIO::span<float>::span(float* data, long size);

OIIO::span<const int> dummy3;
extern template OIIO::span<const int>::span(const int* data, long size);

OIIO::span<const unsigned int> dummy4;
extern template OIIO::span<const unsigned int>::span(const unsigned int* data,
                                                     long size);
OIIO::span<const char> dummy5;
extern template OIIO::span<const char>::span(const char* data, long size);

OIIO::span<const unsigned char> dummy6;
extern template OIIO::span<const unsigned char>::span(const unsigned char* data,
                                                      long size);

OIIO::span<const std::string> dummy7;
extern template OIIO::span<const std::string>::span(const std::string* data,
                                                    long size);
