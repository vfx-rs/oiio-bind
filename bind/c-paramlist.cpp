#include <OpenImageIO/paramlist.h>
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OIIO_NAMESPACE {

namespace OIIO = ::OIIO_NAMESPACE;

struct ParamValue {
    using BoundType = OIIO::ParamValue;

    CPPMM_RENAME(default)
    ParamValue();

    CPPMM_RENAME(ctor_ustring)
    ParamValue(const OIIO::ustring& _name, OIIO::TypeDesc _type, int _nvalues,
               const void* _value, bool _copy);

    CPPMM_RENAME(with_interp_ustring)
    ParamValue(const OIIO::ustring& _name, OIIO::TypeDesc _type, int _nvalues,
               OIIO::ParamValue::Interp _interp, const void* _value,
               bool _copy);

    ParamValue(OIIO::string_view _name, OIIO::TypeDesc _type, int _nvalues,
               const void* _value, bool _copy);

    CPPMM_RENAME(with_interp)
    ParamValue(OIIO::string_view _name, OIIO::TypeDesc _type, int _nvalues,
               OIIO::ParamValue::Interp _interp, const void* _value,
               bool _copy);

    CPPMM_RENAME(from_int)
    ParamValue(OIIO::string_view _name, int value);

    CPPMM_RENAME(from_float)
    ParamValue(OIIO::string_view _name, float value);

    CPPMM_RENAME(from_ustring)
    ParamValue(OIIO::string_view _name, OIIO::ustring value);

    CPPMM_RENAME(from_string)
    ParamValue(OIIO::string_view _name, OIIO::string_view value);

    CPPMM_RENAME(parse)
    ParamValue(OIIO::string_view _name, OIIO::TypeDesc type,
               OIIO::string_view value);

    ParamValue(const OIIO::ParamValue& p);

    CPPMM_IGNORE
    ParamValue(const OIIO::ParamValue& p, bool _copy);

    CPPMM_IGNORE
    ParamValue(OIIO::ParamValue&& p);

    ~ParamValue();

    CPPMM_RENAME(init_with_interp_ustring)
    auto init(OIIO::ustring _name, OIIO::TypeDesc _type, int _nvalues,
              OIIO::ParamValue::Interp _interp, const void* _value, bool _copy)
        -> void;

    CPPMM_RENAME(init_ustring)
    auto init(OIIO::ustring _name, OIIO::TypeDesc _type, int _nvalues,
              const void* _value, bool _copy) -> void;

    auto init(OIIO::string_view _name, OIIO::TypeDesc _type, int _nvalues,
              const void* _value, bool _copy) -> void;

    CPPMM_RENAME(init_with_interp)
    auto init(OIIO::string_view _name, OIIO::TypeDesc _type, int _nvalues,
              OIIO::ParamValue::Interp _interp, const void* _value, bool _copy)
        -> void;

    auto operator=(const OIIO::ParamValue& p) -> const OIIO::ParamValue&;

    auto name() const -> const OIIO::ustring&;
    auto uname() const -> const OIIO::ustring&;
    auto type() const -> OIIO::TypeDesc;
    auto nvalues() const -> int;
    auto data() const -> const void*;
    auto datasize() const -> int;

    CPPMM_RENAME(interp_const)
    auto interp() const -> OIIO::ParamValue::Interp;

    auto interp(OIIO::ParamValue::Interp i) -> void;

    auto is_nonlocal() const -> bool;

    template <typename T> const T& get(int i) const CPPMM_IGNORE;

    auto get_int(int defaultval) const -> int;
    auto get_int_indexed(int index, int defaultval) const -> int;
    auto get_float(float defaultval) const -> float;
    auto get_float_indexed(int index, float defaultval) const -> float;
    auto get_string(int maxsize) const -> std::string;
    auto get_string_indexed(int index) const -> std::string;
    auto get_ustring(int maxsize) const -> OIIO::ustring;
    auto get_ustring_indexed(int index) const -> OIIO::ustring;

    enum Interp {
        INTERP_CONSTANT = 0,
        INTERP_PERPIECE = 1,
        INTERP_LINEAR = 2,
        INTERP_VERTEX = 3,
    };

} CPPMM_OPAQUEBYTES; // struct ParamValue

struct ParamValueList {
    using BoundType = OIIO::ParamValueList;

    auto data() -> OIIO::ParamValue*;

    CPPMM_RENAME(data_const)
    auto data() const -> const OIIO::ParamValue*;
    auto push_back(const OIIO::ParamValue& __x) -> void;

    CPPMM_IGNORE
    auto push_back(OIIO::ParamValue&& __x) -> void;

    template <typename... Args> void emplace_back(Args... __args) CPPMM_IGNORE;

    auto pop_back() -> void;

    auto clear() -> void;

    ParamValueList();
    auto grow() -> OIIO::ParamValue&;

    auto find_pv(OIIO::string_view name, OIIO::TypeDesc type,
                 bool casesensitive) -> OIIO::ParamValue*;

    CPPMM_RENAME(find_pv_const)
    auto find_pv(OIIO::string_view name, OIIO::TypeDesc type,
                 bool casesensitive) const -> const OIIO::ParamValue*;

    auto get_int(OIIO::string_view name, int defaultval, bool casesensitive,
                 bool convert) const -> int;

    auto get_float(OIIO::string_view name, float defaultval, bool casesensitive,
                   bool convert) const -> float;

    auto get_string(OIIO::string_view name, OIIO::string_view defaultval,
                    bool casesensitive, bool convert) const
        -> OIIO::string_view;

    auto get_ustring(OIIO::string_view name, OIIO::string_view defaultval,
                     bool casesensitive, bool convert) const -> OIIO::ustring;

    auto remove(OIIO::string_view name, OIIO::TypeDesc type, bool casesensitive)
        -> void;

    auto contains(OIIO::string_view name, OIIO::TypeDesc type,
                  bool casesensitive) const -> bool;

    auto add_or_replace(const OIIO::ParamValue& pv, bool casesensitive) -> void;

    CPPMM_IGNORE
    auto add_or_replace(OIIO::ParamValue&& pv, bool casesensitive) -> void;

    auto attribute(OIIO::string_view name, OIIO::TypeDesc type, int nvalues,
                   const void* value) -> void;

    CPPMM_IGNORE
    auto attribute(OIIO::string_view name, OIIO::TypeDesc type,
                   const void* value) -> void;

    CPPMM_RENAME(attribute_parse_from_string)
    auto attribute(OIIO::string_view name, OIIO::TypeDesc type,
                   OIIO::string_view value) -> void;

    CPPMM_RENAME(attribute_int)
    auto attribute(OIIO::string_view name, int value) -> void;

    CPPMM_RENAME(attribute_uint)
    auto attribute(OIIO::string_view name, unsigned int value) -> void;

    CPPMM_RENAME(attribute_float)
    auto attribute(OIIO::string_view name, float value) -> void;

    CPPMM_RENAME(attribute_string)
    auto attribute(OIIO::string_view name, OIIO::string_view value) -> void;

    auto getattributetype(OIIO::string_view name, bool casesensitive) const
        -> OIIO::TypeDesc;

    auto getattribute(OIIO::string_view name, OIIO::TypeDesc type, void* value,
                      bool casesensitive) const -> bool;

    CPPMM_RENAME(getattribute_as_string)
    auto getattribute(OIIO::string_view name, std::string& value,
                      bool casesensitive) const -> bool;

    auto getattribute_indexed(OIIO::string_view name, int index,
                              OIIO::TypeDesc type, void* value,
                              bool casesensitive) const -> bool;

    CPPMM_RENAME(getattribute_indexed_as_string)
    auto getattribute_indexed(OIIO::string_view name, int index,
                              std::string& value, bool casesensitive) const
        -> bool;

    auto sort(bool casesensitive) -> void;

    auto merge(const OIIO::ParamValueList& other, bool override) -> void;
    auto free() -> void;

    CPPMM_IGNORE
    auto operator[](int index) -> OIIO::ParamValue&;
    CPPMM_IGNORE
    auto operator[](int index) const -> const OIIO::ParamValue&;
    CPPMM_IGNORE
    auto operator[](OIIO::string_view name) const
        -> OIIO::AttrDelegate<const OIIO::ParamValueList>;
    CPPMM_IGNORE
    auto operator[](OIIO::string_view name)
        -> OIIO::AttrDelegate<OIIO::ParamValueList>;
    ParamValueList(const OIIO::ParamValueList& rhs);

    CPPMM_IGNORE
    ParamValueList(OIIO::ParamValueList&&);

    ~ParamValueList();
} CPPMM_OPAQUEPTR CPPMM_IGNORE_UNBOUND; // struct ParamValueList

} // namespace OIIO_NAMESPACE

} // namespace cppmm_bind
