#include <OpenImageIO/string_view.h>
#include <string>
#include <utility>

// CPPMM_ macro definitions etc automatically inserted in this virtual header
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace std {

template <class First, class Second> class pair {
public:
    // This allows us to see through to the type in Imath
    using BoundType = ::std::pair<First, Second>;

    pair();
    pair(const ::std::pair<First, Second>& rhs);
    ~pair();

} CPPMM_OPAQUEBYTES CPPMM_IGNORE_UNBOUND;

// explicit instantiation
template class pair<OIIO::string_view, int>;

using pair_string_int = ::std::pair<OIIO::string_view, int>;

} // namespace std

} // namespace cppmm_bind

template class std::pair<OIIO::string_view, int>;
