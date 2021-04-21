#include <OpenImageIO/filter.h>
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OIIO_NAMESPACE {

namespace OIIO = ::OIIO_NAMESPACE;

struct FilterDesc {
    using BoundType = OIIO::FilterDesc;

} CPPMM_OPAQUEBYTES; // struct FilterDesc

struct Filter1D {
    using BoundType = OIIO::Filter1D;

    Filter1D(float width);
    ~Filter1D();
    auto width() const -> float;
    auto operator()(float x) const -> float;
    auto name() const -> OIIO::string_view;
    static auto create(OIIO::string_view filtername, float width)
        -> OIIO::Filter1D*;
    static auto destroy(OIIO::Filter1D* filt) -> void;
    static auto num_filters() -> int;
    static auto get_filterdesc(int filternum, OIIO::FilterDesc* filterdesc)
        -> void;

    CPPMM_IGNORE
    static auto get_filterdesc(int filternum) -> const OIIO::FilterDesc&;
    auto operator=(const OIIO::Filter1D& rhs) -> OIIO::Filter1D&;
} CPPMM_OPAQUEPTR; // struct Filter1D

struct Filter2D {
    using BoundType = OIIO::Filter2D;

    Filter2D(float width, float height);
    ~Filter2D();
    auto width() const -> float;
    auto height() const -> float;
    auto separable() const -> bool;

    CPPMM_RENAME(eval)
    auto operator()(float x, float y) const -> float;
    auto xfilt(float x) const -> float;
    auto yfilt(float y) const -> float;
    auto name() const -> OIIO::string_view;
    static auto create(OIIO::string_view filtername, float width, float height)
        -> OIIO::Filter2D*;
    static auto destroy(OIIO::Filter2D* filt) -> void;
    static auto num_filters() -> int;
    static auto get_filterdesc(int filternum, OIIO::FilterDesc* filterdesc)
        -> void;

    CPPMM_IGNORE
    static auto get_filterdesc(int filternum) -> const OIIO::FilterDesc&;
    auto operator=(const OIIO::Filter2D& rhs) -> OIIO::Filter2D&;
} CPPMM_OPAQUEPTR; // struct Filter2D

} // namespace OIIO_NAMESPACE

} // namespace cppmm_bind
