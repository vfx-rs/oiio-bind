#include <OpenImageIO/typedesc.h>
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OIIO_NAMESPACE {

namespace OIIO = ::OIIO_NAMESPACE;

struct TypeDesc {
    using BoundType = OIIO::TypeDesc;

    TypeDesc(OIIO::TypeDesc::BASETYPE btype, OIIO::TypeDesc::AGGREGATE agg,
             OIIO::TypeDesc::VECSEMANTICS semantics, int arraylen);

    CPPMM_RENAME(from_basetype)
    TypeDesc(OIIO::TypeDesc::BASETYPE btype, int arraylen);

    CPPMM_IGNORE
    TypeDesc(OIIO::TypeDesc::BASETYPE btype, OIIO::TypeDesc::AGGREGATE agg,
             int arraylen);

    CPPMM_RENAME(from_string)
    TypeDesc(OIIO::string_view typestring);

    CPPMM_RENAME(copy)
    TypeDesc(const OIIO::TypeDesc& t);
    auto c_str() const -> const char*;
    auto numelements() const -> unsigned long;
    auto basevalues() const -> unsigned long;
    auto is_array() const -> bool;
    auto is_unsized_array() const -> bool;
    auto is_sized_array() const -> bool;
    auto size() const -> unsigned long;
    auto elementtype() const -> OIIO::TypeDesc;
    auto elementsize() const -> unsigned long;
    auto scalartype() const -> OIIO::TypeDesc;
    auto basesize() const -> unsigned long;
    auto is_floating_point() const -> bool;
    auto is_signed() const -> bool;
    auto is_unknown() const -> bool;

    CPPMM_IGNORE
    operator bool() const;
    auto fromstring(OIIO::string_view typestring) -> unsigned long;
    auto operator==(const OIIO::TypeDesc& t) const -> bool;
    auto operator!=(const OIIO::TypeDesc& t) const -> bool;
    auto equivalent(const OIIO::TypeDesc& b) const -> bool;
    auto is_vec2(OIIO::TypeDesc::BASETYPE b) const -> bool;
    auto is_vec3(OIIO::TypeDesc::BASETYPE b) const -> bool;
    auto is_vec4(OIIO::TypeDesc::BASETYPE b) const -> bool;
    auto unarray() -> void;
    auto operator<(const OIIO::TypeDesc& x) const -> bool;
    static auto basetype_merge(OIIO::TypeDesc a, OIIO::TypeDesc b)
        -> OIIO::TypeDesc::BASETYPE;
    ~TypeDesc();

    enum BASETYPE {
        UNKNOWN = 0,
        NONE = 1,
        UINT8 = 2,
        UCHAR = 2,
        INT8 = 3,
        CHAR = 3,
        UINT16 = 4,
        USHORT = 4,
        INT16 = 5,
        SHORT = 5,
        UINT32 = 6,
        UINT = 6,
        INT32 = 7,
        INT = 7,
        UINT64 = 8,
        ULONGLONG = 8,
        INT64 = 9,
        LONGLONG = 9,
        HALF = 10,
        FLOAT = 11,
        DOUBLE = 12,
        STRING = 13,
        PTR = 14,
        LASTBASE = 15,
    };

    enum AGGREGATE {
        SCALAR = 1,
        VEC2 = 2,
        VEC3 = 3,
        VEC4 = 4,
        MATRIX33 = 9,
        MATRIX44 = 16,
    };

    enum VECSEMANTICS {
        NOXFORM = 0,
        NOSEMANTICS = 0,
        COLOR = 1,
        POINT = 2,
        VECTOR = 3,
        NORMAL = 4,
        TIMECODE = 5,
        KEYCODE = 6,
        RATIONAL = 7,
    };
} CPPMM_OPAQUEBYTES; // struct TypeDesc

} // namespace OIIO_NAMESPACE

} // namespace cppmm_bind
