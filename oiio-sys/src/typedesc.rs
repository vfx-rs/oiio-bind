pub use ffi::*;

#[derive(Debug, Clone, Copy)]
pub enum BaseType {
    Unknown,
    None,
    UInt8,
    Int8,
    Uint16,
    Int16,
    UInt32,
    Int32,
    UInt64,
    Int64,
    Float16,
    Float32,
    Float64,
    String,
    Ptr,
    LastBase,
}

unsafe impl cxx::ExternType for BaseType {
    type Id = cxx::type_id!("oiio::BaseType");
    type Kind = cxx::kind::Trivial;
}

#[derive(Debug, Clone, Copy)]
pub enum Aggregate {
    Scalar = 1,
    Vec2 = 2,
    Vec3 = 3,
    Vec4 = 4,
    Matrix33 = 9,
    Matrix44 = 16,
}

unsafe impl cxx::ExternType for Aggregate {
    type Id = cxx::type_id!("oiio::Aggregate");
    type Kind = cxx::kind::Trivial;
}

#[derive(Debug, Clone, Copy)]
pub enum VecSemantics {
    NoSemantics = 0,
    Color,
    Point,
    Vector,
    Normal,
    Timecode,
    Keycode,
    Rational,
}

unsafe impl cxx::ExternType for VecSemantics {
    type Id = cxx::type_id!("oiio::VecSemantics");
    type Kind = cxx::kind::Trivial;
}

#[derive(Debug, Clone, Copy)]
pub struct TypeDesc {
    pub basetype: u8,
    pub aggregate: u8,
    pub vecsemantics: u8,
    _reserved: u8,
    pub arraylen: i32,
}

unsafe impl cxx::ExternType for TypeDesc {
    type Id = cxx::type_id!("oiio::TypeDesc");
    type Kind = cxx::kind::Trivial;
}

#[cxx::bridge(namespace = oiio)]
mod ffi {

    unsafe extern "C++" {
        include!("oiio-sys/src/ffi_typedesc.h");

        // TypeDesc
        type BaseType = crate::typedesc::BaseType;
        type Aggregate = crate::typedesc::Aggregate;
        type VecSemantics = crate::typedesc::VecSemantics;
        type TypeDesc = crate::typedesc::TypeDesc;

        pub fn typedesc_new(
            basetype: BaseType,
            aggregate: Aggregate,
            vecsemantics: VecSemantics,
            arraylen: i32,
        ) -> TypeDesc;
        pub fn typedesc_from_basetype_arraylen(basetype: BaseType, arraylen: i32) -> TypeDesc;
        pub fn typedesc_from_basetype_aggregate_arraylen(
            basetype: BaseType,
            aggregate: Aggregate,
            arraylen: i32,
        ) -> TypeDesc;
        pub fn typedesc_from_typestring(typestring: &str) -> TypeDesc;
        pub fn typedesc_clone(typedesc: &TypeDesc) -> TypeDesc;
        pub fn typedesc_basetype(typedesc: &TypeDesc) -> BaseType;
        pub fn typedesc_aggregate(typedesc: &TypeDesc) -> Aggregate;
        pub fn typedesc_vecsemantics(typedesc: &TypeDesc) -> VecSemantics;
        pub fn typedesc_arraylen(typedesc: &TypeDesc) -> i32;
        pub fn typedesc_to_str(typedesc: &TypeDesc) -> &str;
        pub fn typedesc_numelements(typedesc: &TypeDesc) -> usize;
        pub fn typedesc_basevalues(typedesc: &TypeDesc) -> usize;
        pub fn typedesc_is_array(typedesc: &TypeDesc) -> bool;
        pub fn typedesc_is_unsized_array(typedesc: &TypeDesc) -> bool;
        pub fn typedesc_is_sized_array(typedesc: &TypeDesc) -> bool;
        pub fn typedesc_size(typedesc: &TypeDesc) -> usize;
        pub fn typedesc_elementtype(typedesc: &TypeDesc) -> TypeDesc;
        pub fn typedesc_elementsize(typedesc: &TypeDesc) -> usize;
        pub fn typedesc_basesize(typedesc: &TypeDesc) -> usize;
        pub fn typedesc_is_floating_point(typedesc: &TypeDesc) -> bool;
        pub fn typedesc_is_signed(typedesc: &TypeDesc) -> bool;
        pub fn typedesc_is_unknown(typedesc: &TypeDesc) -> bool;
        pub fn typedesc_from_str(typedesc: Pin<&mut TypeDesc>, typestring: &str) -> usize;
        pub fn typedesc_eq_typedesc(typedesc: &TypeDesc, other: &TypeDesc) -> bool;
        pub fn typedesc_ne_typedesc(typedesc: &TypeDesc, other: &TypeDesc) -> bool;
        pub fn typedesc_eq_basetype(typedesc: &TypeDesc, other: &BaseType) -> bool;
        pub fn typedesc_ne_basetype(typedesc: &TypeDesc, other: &BaseType) -> bool;
        pub fn typedesc_equivalent(typedesc: &TypeDesc, other: &TypeDesc) -> bool;
        pub fn typedesc_is_vec3(typedesc: &TypeDesc, basetype: &BaseType) -> bool;
        pub fn typedesc_is_vec4(typedesc: &TypeDesc, basetype: &BaseType) -> bool;
        pub fn typedesc_unarray(typedesc: Pin<&mut TypeDesc>);
        pub fn typedesc_lt(typedesc: &TypeDesc, other: &TypeDesc) -> bool;
    }
}
