#include <OpenImageIO/image_view.h>
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OIIO_NAMESPACE {

namespace OIIO = ::OIIO_NAMESPACE;

template <class T> struct image_view {
    using BoundType = OIIO::image_view<T>;

    image_view<T>();
    image_view<T>(const OIIO::image_view<T>& copy);
    image_view<T>(T* data, int nchannels, int width, int height, int depth,
                  long chanstride, long xstride, long ystride, long zstride);
    auto operator=(const OIIO::image_view<T>& copy) -> OIIO::image_view<T>&;
    auto operator()(int x, int y, int z) -> OIIO::strided_ptr<T, 1>;
    auto nchannels() const -> int;
    auto width() const -> int;
    auto height() const -> int;
    auto depth() const -> int;
    auto chanstride() const -> long;
    auto xstride() const -> long;
    auto ystride() const -> long;
    auto zstride() const -> long;
    auto data() const -> const T*;
    auto clear() -> void;
} CPPMM_OPAQUEBYTES; // struct image_view

// TODO: fill in explicit instantiations, e.g.:
// template class image_view<int>;
// using image_viewInt = OIIO::image_view<int>;

} // namespace OIIO_NAMESPACE

} // namespace cppmm_bind

// TODO: fill in explicit instantiations
// template class OIIO::image_view<int>;
