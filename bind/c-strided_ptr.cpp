#include <OpenImageIO/strided_ptr.h>
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OIIO_NAMESPACE {

namespace OIIO = ::OIIO_NAMESPACE;

template <class T, int StrideUnits> struct strided_ptr {
    using BoundType = OIIO::strided_ptr<T, StrideUnits>;

    strided_ptr<T, StrideUnits>(T* ptr, long stride);
    ~strided_ptr();

    CPPMM_RENAME(copy)
    strided_ptr<T, StrideUnits>(const OIIO::strided_ptr<T, StrideUnits>& p);

    auto operator=(const OIIO::strided_ptr<T, StrideUnits>& p)
        -> const OIIO::strided_ptr<T, StrideUnits>&;

    CPPMM_IGNORE
    auto operator=(T* p) -> const OIIO::strided_ptr<T, StrideUnits>&;

    CPPMM_IGNORE
    auto operator*() const -> T&;

    auto operator[](long pos) const -> T&;

    auto data() const -> T*;

    auto stride() const -> long;

    CPPMM_IGNORE
    auto operator==(const T* p) const -> bool;

    CPPMM_IGNORE
    auto operator!=(const T* p) const -> bool;

    CPPMM_IGNORE
    auto operator++() -> const OIIO::strided_ptr<T, StrideUnits>&;

    CPPMM_IGNORE
    auto operator++(int) -> const OIIO::strided_ptr<T, StrideUnits>;

    CPPMM_IGNORE
    auto operator--() -> const OIIO::strided_ptr<T, StrideUnits>&;

    CPPMM_IGNORE
    auto operator--(int) -> const OIIO::strided_ptr<T, StrideUnits>;

    CPPMM_IGNORE
    auto operator+(long d) const -> OIIO::strided_ptr<T, StrideUnits>;

    CPPMM_IGNORE
    auto operator-(long d) const -> OIIO::strided_ptr<T, StrideUnits>;

    CPPMM_IGNORE
    auto operator+=(long d) -> const OIIO::strided_ptr<T, StrideUnits>&;

    CPPMM_IGNORE
    auto operator-=(long d) -> const OIIO::strided_ptr<T, StrideUnits>&;
} CPPMM_OPAQUEBYTES CPPMM_TRIVIALLY_MOVABLE
    CPPMM_TRIVIALLY_COPYABLE; // struct strided_ptr

// TODO: fill in explicit instantiations, e.g.:
template class strided_ptr<float, 1>;
using strided_ptr_float = OIIO::strided_ptr<float, 1>;

} // namespace OIIO_NAMESPACE

} // namespace cppmm_bind

// TODO: fill in explicit instantiations
template class OIIO::strided_ptr<float, 1>;
