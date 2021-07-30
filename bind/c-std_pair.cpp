#include <OpenImageIO/string_view.h>
#include <string>
#include <utility>

// CPPMM_ macro definitions etc automatically inserted in this virtual header
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace std {

#if defined(_LIBCPP_VERSION)
namespace std = ::std::_LIBCPP_ABI_NAMESPACE;
#else
namespace std = ::std;
#endif

template <class First, class Second> class pair {
public:
    // This allows us to see through to the type in Imath
    using BoundType = ::std::pair<First, Second>;

    pair();
    pair(const ::std::pair<First, Second>& rhs);
    ~pair();

} CPPMM_OPAQUEPTR CPPMM_IGNORE_UNBOUND CPPMM_PROPERTIES(first; second);

// explicit instantiation
template class pair<OIIO::string_view, int>;

using pair_string_int = ::std::pair<OIIO::string_view, int>;

} // namespace std

} // namespace cppmm_bind

template class std::pair<OIIO::string_view, int>;
