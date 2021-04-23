#include <memory>

#include <OpenImageIO/imageio.h>

// CPPMM_ macro definitions etc automatically inserted in this virtual header
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace std {

template <class T> class unique_ptr {
public:
    // This allows us to see through to the type in Imath
    using BoundType = ::std::unique_ptr<T>;

    T* get();

    ~unique_ptr() CPPMM_RENAME(dtor);

} CPPMM_OPAQUEBYTES CPPMM_IGNORE_UNBOUND;

// explicit instantiation
template class unique_ptr<OIIO::ImageInput>;
using ImageInputPtr = ::std::unique_ptr<OIIO::ImageInput>;

template class unique_ptr<OIIO::ImageOutput>;
using ImageOutputPtr = ::std::unique_ptr<OIIO::ImageOutput>;

} // namespace std

} // namespace cppmm_bind

template class std::unique_ptr<OIIO::ImageInput>;
template class std::unique_ptr<OIIO::ImageOutput>;
