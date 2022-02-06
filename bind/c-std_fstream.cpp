#include <fstream>
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

class ofstream {
public:
    // This allows us to see through to the type in Imath
    using BoundType = std::ofstream;

    ofstream(const char* filename, std::ios_base::open_mode mode);
    ~ofstream();

} CPPMM_OPAQUEPTR CPPMM_IGNORE_UNBOUND;

} // namespace std

} // namespace cppmm_bind

