#include <string>
#include <vector>

#include <OpenImageIO/string_view.h>
#include <OpenImageIO/typedesc.h>
#include <OpenImageIO/ustring.h>

// CPPMM_ macro definitions etc automatically inserted in this virtual header
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace std {

#if defined(_LIBCPP_VERSION)
namespace std = ::std::_LIBCPP_ABI_NAMESPACE;
#else
namespace std = ::std;
#endif

template <class T> class vector {
public:
    // This allows us to see through to the type in Imath
    using BoundType = std::vector<T>;

    vector() CPPMM_RENAME(ctor);
    vector(const std::vector<T>& rhs);
    ~vector();

    T* data();
    const T* data() const CPPMM_RENAME(data_const);

    size_t size() const;

    void push_back(const T& value);

    const T& operator[](size_t pos) const CPPMM_RENAME(index);

} CPPMM_OPAQUEPTR CPPMM_IGNORE_UNBOUND;

// explicit instantiation
template class vector<::std::string>;
using vector_string = ::std::vector<::std::string>;

template class vector<OIIO::string_view>;
using vector_string_view = ::std::vector<OIIO::string_view>;

template class vector<OIIO::ustring>;
using vector_ustring = ::std::vector<OIIO::ustring>;

template class vector<char>;
using vector_char = ::std::vector<char>;

template class vector<unsigned char>;
using vector_uchar = ::std::vector<unsigned char>;

template class vector<float>;
using vector_float = ::std::vector<float>;

template class vector<double>;
using vector_double = ::std::vector<double>;

/* template class vector<unsigned long>; */
/* using vector_ulong = ::std::vector<unsigned long>; */

template class vector<int>;
using vector_int = ::std::vector<int>;

template class vector<size_t>;
using vector_size_t = ::std::vector<size_t>;

// can't do this yet
// template class vector<void*>;
// using vector_voidptr = ::std::vector<void*>;

template class vector<OIIO::TypeDesc>;
using vector_typedesc = ::std::vector<OIIO::TypeDesc>;

} // namespace std

} // namespace cppmm_bind

template class std::vector<std::string>;
template class std::vector<OIIO::string_view>;
template class std::vector<OIIO::ustring>;
template class std::vector<char>;
template class std::vector<unsigned char>;
template class std::vector<float>;
template class std::vector<double>;
/* template class std::vector<unsigned long>; */
template class std::vector<int>;
template class std::vector<size_t>;
// template class std::vector<void*>;
template class std::vector<OIIO::TypeDesc>;
