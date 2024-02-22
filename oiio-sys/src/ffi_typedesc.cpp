#include "ffi_typedesc.h"
#include "rust/cxx.h"
#include <OpenImageIO/string_view.h>
#include <OpenImageIO/typedesc.h>
#include <memory>
#include <stdexcept>
#include <stdio.h>

namespace oiio {
#pragma region TypeDesc
TypeDesc
typedesc_new(BaseType basetype, Aggregate aggregate, VecSemantics vecsemantics,
             int arraylen)
{
    return OIIO::TypeDesc(static_cast<TypeDesc::BASETYPE>(basetype),
                          static_cast<TypeDesc::AGGREGATE>(aggregate),
                          static_cast<TypeDesc::VECSEMANTICS>(vecsemantics),
                          arraylen);
}

TypeDesc
typedesc_from_basetype_arraylen(BaseType basetype, int arraylen)
{
    return OIIO::TypeDesc(static_cast<TypeDesc::BASETYPE>(basetype), arraylen);
}

TypeDesc
typedesc_from_basetype_aggregate_arraylen(BaseType basetype,
                                          Aggregate aggregate, int arraylen)
{
    return OIIO::TypeDesc(static_cast<TypeDesc::BASETYPE>(basetype),
                          static_cast<TypeDesc::AGGREGATE>(aggregate),
                          arraylen);
}

TypeDesc
typedesc_from_typestring(rust::Str typestring)
{
    OIIO::string_view typestring_view(typestring.data(), typestring.size());
    return OIIO::TypeDesc(typestring_view);
}

TypeDesc
typedesc_clone(const TypeDesc& typedesc)
{
    return OIIO::TypeDesc(typedesc);
}

rust::Str
typedesc_to_str(const TypeDesc& typedesc)
{
    return rust::Str(typedesc.c_str());
}

BaseType
typedesc_basetype(const TypeDesc& typedesc)
{
    return static_cast<BaseType>(typedesc.basetype);
}

Aggregate
typedesc_aggregate(const TypeDesc& typedesc)
{
    return static_cast<Aggregate>(typedesc.aggregate);
}

VecSemantics
typedesc_vecsemantics(const TypeDesc& typedesc)
{
    return static_cast<VecSemantics>(typedesc.vecsemantics);
}

int
typedesc_arraylen(const TypeDesc& typedesc)
{
    return typedesc.arraylen;
}

size_t
typedesc_numelements(const TypeDesc& typedesc)
{
    return typedesc.numelements();
}

size_t
typedesc_basevalues(const TypeDesc& typedesc)
{
    return typedesc.basevalues();
}

bool
typedesc_is_array(const TypeDesc& typedesc)
{
    return typedesc.is_array();
}

bool
typedesc_is_unsized_array(const TypeDesc& typedesc)
{
    return typedesc.is_unsized_array();
}

bool
typedesc_is_sized_array(const TypeDesc& typedesc)
{
    return typedesc.is_sized_array();
}

size_t
typedesc_size(const TypeDesc& typedesc)
{
    return typedesc.size();
}

TypeDesc
typedesc_elementtype(const TypeDesc& typedesc)
{
    return OIIO::TypeDesc(typedesc.elementtype());
}

size_t
typedesc_elementsize(const TypeDesc& typedesc)
{
    return typedesc.elementsize();
}

size_t
typedesc_basesize(const TypeDesc& typedesc)
{
    return typedesc.basesize();
}

bool
typedesc_is_floating_point(const TypeDesc& typedesc)
{
    return typedesc.is_floating_point();
}

bool
typedesc_is_signed(const TypeDesc& typedesc)
{
    return typedesc.is_signed();
}

bool
typedesc_is_unknown(const TypeDesc& typedesc)
{
    return typedesc.is_unknown();
}

size_t
typedesc_from_str(TypeDesc& typedesc, const rust::Str typestring)
{
    OIIO::string_view typestring_view(typestring.data(), typestring.size());
    return typedesc.fromstring(typestring_view);
}

bool
typedesc_eq_typedesc(const TypeDesc& typedesc, const TypeDesc& other)
{
    return typedesc == other;
}

bool
typedesc_ne_typedesc(const TypeDesc& typedesc, const TypeDesc& other)
{
    return typedesc != other;
}

bool
typedesc_eq_basetype(const TypeDesc& typedesc, const BaseType& other)
{
    return typedesc == static_cast<TypeDesc::BASETYPE>(other);
}

bool
typedesc_ne_basetype(const TypeDesc& typedesc, const BaseType& other)
{
    return typedesc != static_cast<TypeDesc::BASETYPE>(other);
}

bool
typedesc_equivalent(const TypeDesc& typedesc, const TypeDesc& other)
{
    return typedesc.equivalent(other);
}

bool
typedesc_is_vec3(const TypeDesc& typedesc, const BaseType& basetype)
{
    return typedesc.is_vec3(static_cast<TypeDesc::BASETYPE>(basetype));
}

bool
typedesc_is_vec4(const TypeDesc& typedesc, const BaseType& basetype)
{
    return typedesc.is_vec4(static_cast<TypeDesc::BASETYPE>(basetype));
}

void
typedesc_unarray(TypeDesc& typedesc)
{
    typedesc.unarray();
}

bool
typedesc_lt(const TypeDesc& typedesc, const TypeDesc& other)
{
    return typedesc < other;
}
#pragma endregion
}  // namespace oiio
