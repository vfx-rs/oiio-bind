#include <string>
#include <vector>

#include <OpenImageIO/string_view.h>
#include <OpenImageIO/typedesc.h>

// CPPMM_ macro definitions etc automatically inserted in this virtual header
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace std {

template <class T> class vector {
public:
    // This allows us to see through to the type in Imath
    using BoundType = ::std::vector<T>;

    size_t size() const;
    const T& operator[](size_t i) const CPPMM_IGNORE;
    T* data();

    vector() CPPMM_RENAME(ctor);
    ~vector() CPPMM_RENAME(dtor);

} CPPMM_OPAQUEBYTES CPPMM_IGNORE_UNBOUND;

// explicit instantiation
template class vector<::std::string>;
using vector_string = ::std::vector<::std::string>;

template class vector<OIIO::string_view>;
using vector_string_view = ::std::vector<OIIO::string_view>;

template class vector<char>;
using vector_char = ::std::vector<char>;

template class vector<unsigned char>;
using vector_uchar = ::std::vector<unsigned char>;

template class vector<float>;
using vector_float = ::std::vector<float>;

template class vector<unsigned long>;
using vector_ulong = ::std::vector<unsigned long>;

template class vector<int>;
using vector_int = ::std::vector<int>;

// can't do this yet
// template class vector<void*>;
// using vector_voidptr = ::std::vector<void*>;

template class vector<OIIO::TypeDesc>;
using vector_typedesc = ::std::vector<OIIO::TypeDesc>;

} // namespace std

} // namespace cppmm_bind

template class std::vector<std::string>;
template class std::vector<OIIO::string_view>;
template class std::vector<char>;
template class std::vector<unsigned char>;
template class std::vector<float>;
template class std::vector<unsigned long>;
template class std::vector<int>;
// template class std::vector<void*>;
template class std::vector<OIIO::TypeDesc>;
