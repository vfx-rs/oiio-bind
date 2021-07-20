use crate::typedesc::TypeDesc;
use half::f16;

pub trait Pixel {
    const FORMAT: TypeDesc;
}

impl Pixel for u8 {
    const FORMAT: TypeDesc = TypeDesc::UINT8;
}

impl Pixel for u16 {
    const FORMAT: TypeDesc = TypeDesc::UINT16;
}

impl Pixel for u32 {
    const FORMAT: TypeDesc = TypeDesc::UINT32;
}

impl Pixel for i8 {
    const FORMAT: TypeDesc = TypeDesc::INT8;
}

impl Pixel for i16 {
    const FORMAT: TypeDesc = TypeDesc::INT16;
}

impl Pixel for i32 {
    const FORMAT: TypeDesc = TypeDesc::UINT32;
}

impl Pixel for f16 {
    const FORMAT: TypeDesc = TypeDesc::HALF;
}

impl Pixel for f32 {
    const FORMAT: TypeDesc = TypeDesc::FLOAT;
}
