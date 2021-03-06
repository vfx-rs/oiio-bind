#include <map>
#include <string>

// CPPMM_ macro definitions etc automatically inserted in this virtual header
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace std {

#if defined(_LIBCPP_VERSION)
namespace std = ::std::_LIBCPP_ABI_NAMESPACE;
#else
namespace std = ::std;
#endif

template <class K, class V> class map {
public:
    // This allows us to see through to the type in Imath
    using BoundType = std::map<K, V>;

    map();
    ~map();

} CPPMM_OPAQUEPTR CPPMM_IGNORE_UNBOUND;

// explicit instantiation
template class map<std::string, std::string>;

using map_string_string CPPMM_FORCE_NAME("std::map<std::string, std::string>") =
    std::map<std::string, std::string>;

} // namespace std

} // namespace cppmm_bind

template class std::map<std::string, std::string>;
