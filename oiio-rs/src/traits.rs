use crate::string_view::StringView;
use crate::typedesc::{Aggregate, BaseType, TypeDesc, VecSemantics};
use crate::ustring::UString;
use oiio_sys as sys;

use half::f16;
use std::ffi::CString;
use std::os::raw::c_void;

pub trait Pixel: Clone {
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
    const FORMAT: TypeDesc = TypeDesc::INT32;
}

impl Pixel for f16 {
    const FORMAT: TypeDesc = TypeDesc::HALF;
}

impl Pixel for f32 {
    const FORMAT: TypeDesc = TypeDesc::FLOAT;
}

pub trait AttributeMetadata: Default {
    const TYPE: TypeDesc;
    unsafe fn ptr(&self) -> *const c_void;
    unsafe fn ptr_mut(&mut self) -> *mut c_void;
}

impl AttributeMetadata for i32 {
    const TYPE: TypeDesc = TypeDesc::INT32;
    unsafe fn ptr(&self) -> *const c_void {
        self as *const Self as *const c_void
    }
    unsafe fn ptr_mut(&mut self) -> *mut c_void {
        self as *mut Self as *mut c_void
    }
}

impl AttributeMetadata for f32 {
    const TYPE: TypeDesc = TypeDesc::FLOAT;
    unsafe fn ptr(&self) -> *const c_void {
        self as *const Self as *const c_void
    }
    unsafe fn ptr_mut(&mut self) -> *mut c_void {
        self as *mut Self as *mut c_void
    }
}

impl<const N: usize> AttributeMetadata for [f32; N] where [f32; N]: Default {
    const TYPE: TypeDesc = TypeDesc::new(
        BaseType::Float,
        Aggregate::Scalar,
        VecSemantics::NoSemantics,
        N as i32,
    );

    unsafe fn ptr(&self) -> *const c_void {
        self.as_ptr() as *const c_void
    }
    unsafe fn ptr_mut(&mut self) -> *mut c_void {
        self.as_mut_ptr() as *mut c_void
    }
}

impl<const N: usize> AttributeMetadata for [i32; N] where [i32; N]: Default {
    const TYPE: TypeDesc = TypeDesc::new(
        BaseType::Int32,
        Aggregate::Scalar,
        VecSemantics::NoSemantics,
        N as i32,
    );

    unsafe fn ptr(&self) -> *const c_void {
        self.as_ptr() as *const c_void
    }
    unsafe fn ptr_mut(&mut self) -> *mut c_void {
        self.as_mut_ptr() as *mut c_void
    }
}

impl AttributeMetadata for UString {
    const TYPE: TypeDesc = TypeDesc::STRING;
    unsafe fn ptr(&self) -> *const c_void {
        self as *const UString as *const c_void
    }
    unsafe fn ptr_mut(&mut self) -> *mut c_void {
        self as *mut UString as *mut c_void
    }
}

impl<const N: usize> AttributeMetadata for [UString; N] where [UString; N]: Default {
    const TYPE: TypeDesc = TypeDesc::new(
        BaseType::String,
        Aggregate::Scalar,
        VecSemantics::NoSemantics,
        N as i32,
    );

    unsafe fn ptr(&self) -> *const c_void {
        self.as_ptr() as  *const c_void
    }
    unsafe fn ptr_mut(&mut self) -> *mut c_void {
        self.as_mut_ptr() as *mut c_void
    }
}

// impl AttributeMetadata for CString {
//     const TYPE: TypeDesc = TypeDesc::STRING;
//     unsafe fn ptr(&self) -> *const c_void {
//         self.as_ptr() as *const c_void
//     }
// }
// 
// impl AttributeMetadata for StringView {
//     const TYPE: TypeDesc = TypeDesc::STRING;
//     unsafe fn ptr(&self) -> *const c_void {
//         &self.0 as *const sys::OIIO_string_view_t as *const c_void
//     }
// }
