#include <memory>

#include <OpenImageIO/color.h>
#include <OpenImageIO/imagebuf.h>

// CPPMM_ macro definitions etc automatically inserted in this virtual header
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace std {

#if defined(_LIBCPP_VERSION)
namespace std = ::std::_LIBCPP_ABI_NAMESPACE;
#else
namespace std = ::std;
#endif

template <class T> class shared_ptr {
public:
    // This allows us to see through to the type in Imath
    using BoundType = ::std::shared_ptr<T>;

    shared_ptr(const std::shared_ptr<T>& rhs);

    T* get() const;

    ~shared_ptr() CPPMM_RENAME(dtor);

} CPPMM_OPAQUEPTR CPPMM_IGNORE_UNBOUND;

// explicit instantiation
template class shared_ptr<OIIO::ColorProcessor>;
using ColorProcessorHandle = ::std::shared_ptr<OIIO::ColorProcessor>;

template class shared_ptr<OIIO::ImageBuf>;
using ImageBufPtr = ::std::shared_ptr<OIIO::ImageBuf>;

} // namespace std

} // namespace cppmm_bind

template class std::shared_ptr<OIIO::ColorProcessor>;
template class std::shared_ptr<OIIO::ImageBuf>;
