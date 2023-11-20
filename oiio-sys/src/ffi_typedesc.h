#pragma once

#include "rust/cxx.h"
#include <OpenImageIO/imageio.h>
#include <memory>
#include <string>
#include <vector>

namespace oiio {
using TypeDesc = OIIO::TypeDesc;
enum class BaseType : uint8_t;
enum class Aggregate : uint8_t;
enum class VecSemantics : uint8_t;

// TypeDesc

std::unique_ptr<TypeDesc>
typedesc_new(BaseType basetype, Aggregate aggregate, VecSemantics vecsemantics,
             int arraylen);

std::unique_ptr<TypeDesc>
typedesc_from_basetype_arraylen(BaseType basetype, int arraylen);

std::unique_ptr<TypeDesc>
typedesc_from_basetype_aggregate_arraylen(BaseType basetype,
                                          Aggregate aggregate, int arraylen);

std::unique_ptr<TypeDesc>
typedesc_from_typestring(rust::Str typestring);

std::unique_ptr<TypeDesc>
typedesc_clone(const TypeDesc& typedesc);

rust::Str
typedesc_to_str(const TypeDesc& typedesc);

BaseType
typedesc_basetype(const TypeDesc& typedesc);

Aggregate
typedesc_aggregate(const TypeDesc& typedesc);

VecSemantics
typedesc_vecsemantics(const TypeDesc& typedesc);

int
typedesc_arraylen(const TypeDesc& typedesc);

size_t
typedesc_numelements(const TypeDesc& typedesc);

size_t
typedesc_basevalues(const TypeDesc& typedesc);

bool
typedesc_is_array(const TypeDesc& typedesc);

bool
typedesc_is_unsized_array(const TypeDesc& typedesc);

bool
typedesc_is_sized_array(const TypeDesc& typedesc);

size_t
typedesc_size(const TypeDesc& typedesc);

std::unique_ptr<TypeDesc>
typedesc_elementtype(const TypeDesc& typedesc);

size_t
typedesc_elementsize(const TypeDesc& typedesc);

size_t
typedesc_basesize(const TypeDesc& typedesc);

bool
typedesc_is_floating_point(const TypeDesc& typedesc);

bool
typedesc_is_signed(const TypeDesc& typedesc);

bool
typedesc_is_unknown(const TypeDesc& typedesc);

size_t
typedesc_from_str(TypeDesc& typedesc, const rust::Str typestring);

bool
typedesc_eq_typedesc(const TypeDesc& typedesc, const TypeDesc& other);

bool
typedesc_ne_typedesc(const TypeDesc& typedesc, const TypeDesc& other);

bool
typedesc_eq_basetype(const TypeDesc& typedesc, const BaseType& other);

bool
typedesc_ne_basetype(const TypeDesc& typedesc, const BaseType& other);

bool
typedesc_equivalent(const TypeDesc& typedesc, const TypeDesc& other);

bool
typedesc_is_vec3(const TypeDesc& typedesc, const BaseType& basetype);

bool
typedesc_is_vec4(const TypeDesc& typedesc, const BaseType& basetype);

void
typedesc_unarray(TypeDesc& typedesc);

bool
typedesc_lt(const TypeDesc& typedesc, const TypeDesc& other);
}  // namespace oiio
