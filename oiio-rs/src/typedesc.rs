use crate::error::Error;
use oiio_sys as sys;

#[repr(u8)]
#[derive(Debug, Copy, Clone, PartialEq, PartialOrd)]
pub enum BaseType {
    Unknown,
    None,
    Uint8,
    Int8,
    Uint16,
    Int16,
    Uint32,
    Int32,
    Uint64,
    Int64,
    Half,
    Float,
    Double,
    String,
    Ptr,
}

impl From<u8> for BaseType {
    fn from(u: u8) -> Self {
        match u {
            0 => BaseType::Unknown,
            1 => BaseType::None,
            2 => BaseType::Uint8,
            3 => BaseType::Int8,
            4 => BaseType::Uint16,
            5 => BaseType::Int16,
            6 => BaseType::Uint32,
            7 => BaseType::Int32,
            8 => BaseType::Uint64,
            9 => BaseType::Int64,
            10 => BaseType::Half,
            11 => BaseType::Float,
            12 => BaseType::Double,
            13 => BaseType::String,
            14 => BaseType::Ptr,
            _ => panic!("Bad value for BaseType"),
        }
    }
}

#[repr(u8)]
#[derive(Debug, Copy, Clone, PartialEq, PartialOrd)]
pub enum Aggregate {
    Scalar = 1,
    Vec2 = 2,
    Vec3 = 3,
    Vec4 = 4,
    Matrix33 = 9,
    Matrix44 = 16,
}

impl From<u8> for Aggregate {
    fn from(u: u8) -> Self {
        match u {
            1 => Aggregate::Scalar,
            2 => Aggregate::Vec2,
            3 => Aggregate::Vec3,
            4 => Aggregate::Vec4,
            9 => Aggregate::Matrix33,
            16 => Aggregate::Matrix44,
            _ => panic!("Bad value for Aggregate"),
        }
    }
}

#[repr(u8)]
#[derive(Debug, Copy, Clone, PartialEq, PartialOrd)]
pub enum VecSemantics {
    NoSemantics = 0,
    Color,
    Point,
    Vector,
    Normal,
    Timecode,
    Keycode,
    Rational,
    Box,
}

impl From<u8> for VecSemantics {
    fn from(u: u8) -> Self {
        match u {
            0 => VecSemantics::NoSemantics,
            1 => VecSemantics::Color,
            2 => VecSemantics::Point,
            3 => VecSemantics::Vector,
            4 => VecSemantics::Normal,
            5 => VecSemantics::Timecode,
            6 => VecSemantics::Keycode,
            7 => VecSemantics::Rational,
            8 => VecSemantics::Box,
            _ => panic!("Bad value for VecSemantics"),
        }
    }
}

#[repr(C)]
#[derive(Debug, Copy, Clone, PartialEq, PartialOrd)]
pub struct TypeDesc {
    pub basetype: BaseType,
    pub aggregate: Aggregate,
    pub vecsemantics: VecSemantics,
    pub(crate) reserved: u8,
    pub arraylen: i32,
}

impl TypeDesc {
    pub const fn new(
        basetype: BaseType,
        aggregate: Aggregate,
        vecsemantics: VecSemantics,
        arraylen: i32,
    ) -> Self {
        TypeDesc {
            basetype,
            aggregate,
            vecsemantics,
            reserved: 0,
            arraylen,
        }
    }

    pub const UNKNOWN: TypeDesc = TypeDesc::new(
        BaseType::Unknown,
        Aggregate::Scalar,
        VecSemantics::NoSemantics,
        0,
    );

    pub const FLOAT: TypeDesc = TypeDesc::new(
        BaseType::Float,
        Aggregate::Scalar,
        VecSemantics::NoSemantics,
        0,
    );

    pub const COLOR: TypeDesc =
        TypeDesc::new(BaseType::Float, Aggregate::Vec3, VecSemantics::Color, 0);

    pub const POINT: TypeDesc =
        TypeDesc::new(BaseType::Float, Aggregate::Vec3, VecSemantics::Point, 0);

    pub const VECTOR: TypeDesc = TypeDesc::new(
        BaseType::Float,
        Aggregate::Vec3,
        VecSemantics::Vector,
        0,
    );

    pub const NORMAL: TypeDesc = TypeDesc::new(
        BaseType::Float,
        Aggregate::Vec3,
        VecSemantics::Normal,
        0,
    );

    pub const MATRIX33: TypeDesc = TypeDesc::new(
        BaseType::Float,
        Aggregate::Matrix33,
        VecSemantics::NoSemantics,
        0,
    );

    pub const MATRIX44: TypeDesc = TypeDesc::new(
        BaseType::Float,
        Aggregate::Matrix44,
        VecSemantics::NoSemantics,
        0,
    );

    pub const FLOAT2: TypeDesc = TypeDesc::new(
        BaseType::Float,
        Aggregate::Vec2,
        VecSemantics::NoSemantics,
        0,
    );

    pub const VECTOR2: TypeDesc = TypeDesc::new(
        BaseType::Float,
        Aggregate::Vec2,
        VecSemantics::Vector,
        0,
    );

    pub const FLOAT4: TypeDesc = TypeDesc::new(
        BaseType::Float,
        Aggregate::Vec4,
        VecSemantics::NoSemantics,
        0,
    );

    pub const VECTOR4: TypeDesc = TypeDesc::FLOAT4;

    pub const STRING: TypeDesc = TypeDesc::new(
        BaseType::String,
        Aggregate::Scalar,
        VecSemantics::NoSemantics,
        0,
    );

    pub const INT32: TypeDesc = TypeDesc::new(
        BaseType::Int32,
        Aggregate::Scalar,
        VecSemantics::NoSemantics,
        0,
    );

    pub const UINT32: TypeDesc = TypeDesc::new(
        BaseType::Uint32,
        Aggregate::Scalar,
        VecSemantics::NoSemantics,
        0,
    );

    pub const INT16: TypeDesc = TypeDesc::new(
        BaseType::Int16,
        Aggregate::Scalar,
        VecSemantics::NoSemantics,
        0,
    );

    pub const UINT16: TypeDesc = TypeDesc::new(
        BaseType::Uint16,
        Aggregate::Scalar,
        VecSemantics::NoSemantics,
        0,
    );

    pub const INT8: TypeDesc = TypeDesc::new(
        BaseType::Int8,
        Aggregate::Scalar,
        VecSemantics::NoSemantics,
        0,
    );

    pub const UINT8: TypeDesc = TypeDesc::new(
        BaseType::Uint8,
        Aggregate::Scalar,
        VecSemantics::NoSemantics,
        0,
    );

    pub const INT64: TypeDesc = TypeDesc::new(
        BaseType::Int64,
        Aggregate::Scalar,
        VecSemantics::NoSemantics,
        0,
    );

    pub const UINT64: TypeDesc = TypeDesc::new(
        BaseType::Uint64,
        Aggregate::Scalar,
        VecSemantics::NoSemantics,
        0,
    );

    pub const VECTOR2I: TypeDesc = TypeDesc::new(
        BaseType::Int32,
        Aggregate::Vec2,
        VecSemantics::NoSemantics,
        0,
    );

    pub const BOX2: TypeDesc =
        TypeDesc::new(BaseType::Float, Aggregate::Vec2, VecSemantics::Box, 2);

    pub const BOX3: TypeDesc =
        TypeDesc::new(BaseType::Float, Aggregate::Vec3, VecSemantics::Box, 2);

    pub const BOX2I: TypeDesc =
        TypeDesc::new(BaseType::Int32, Aggregate::Vec2, VecSemantics::Box, 2);

    pub const BOX3I: TypeDesc =
        TypeDesc::new(BaseType::Int32, Aggregate::Vec3, VecSemantics::Box, 2);

    pub const HALF: TypeDesc = TypeDesc::new(
        BaseType::Half,
        Aggregate::Scalar,
        VecSemantics::NoSemantics,
        0,
    );

    pub const TIMECODE: TypeDesc = TypeDesc::new(
        BaseType::Uint32,
        Aggregate::Scalar,
        VecSemantics::Timecode,
        2,
    );

    pub const KEYCODE: TypeDesc = TypeDesc::new(
        BaseType::Int32,
        Aggregate::Scalar,
        VecSemantics::Keycode,
        7,
    );

    pub const RATIONAL: TypeDesc = TypeDesc::new(
        BaseType::Int32,
        Aggregate::Vec2,
        VecSemantics::Rational,
        0,
    );

    pub const POINTER: TypeDesc = TypeDesc::new(
        BaseType::Ptr,
        Aggregate::Scalar,
        VecSemantics::NoSemantics,
        0,
    );
}

impl From<TypeDesc> for sys::OIIO_TypeDesc_t {
    fn from(t: TypeDesc) -> Self {
        Self {
            basetype: t.basetype as u8,
            aggregate: t.aggregate as u8,
            vecsemantics: t.vecsemantics as u8,
            reserved: t.reserved,
            arraylen: t.arraylen,
        }
    }
}

impl From<sys::OIIO_TypeDesc_t> for TypeDesc {
    fn from(t: sys::OIIO_TypeDesc_t) -> Self {
        Self {
            basetype: t.basetype.into(),
            aggregate: t.aggregate.into(),
            vecsemantics: t.vecsemantics.into(),
            reserved: t.reserved,
            arraylen: t.arraylen,
        }
    }
}
