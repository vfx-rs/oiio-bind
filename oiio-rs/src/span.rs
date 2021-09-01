use oiio_sys as sys;
use crate::cppstd::CppString;

#[repr(transparent)]
pub struct SpanF32Mut(pub(crate) sys::OIIO_span_float_t);

#[repr(transparent)]
pub struct SpanF32(pub(crate) sys::OIIO_cspan_float_t);

impl From<&mut [f32]> for SpanF32Mut {
    fn from(s: &mut [f32]) -> SpanF32Mut {
        let mut sp = sys::OIIO_span_float_t::default();
        unsafe {
            sys::OIIO_span_float_from_ptr(
                &mut sp,
                s.as_mut_ptr(),
                s.len() as i64,
            );
        }

        SpanF32Mut(sp)
    }
}

impl From<&[f32]> for SpanF32 {
    fn from(s: &[f32]) -> SpanF32 {
        let mut sp = sys::OIIO_cspan_float_t::default();
        unsafe {
            sys::OIIO_cspan_float_from_ptr(
                &mut sp,
                s.as_ptr(),
                s.len() as i64,
            );
        }

        SpanF32(sp)
    }
}

#[repr(transparent)]
pub struct SpanI32Mut(pub(crate) sys::OIIO_span_int_t);

#[repr(transparent)]
pub struct SpanI32(pub(crate) sys::OIIO_cspan_int_t);

impl From<&mut [i32]> for SpanI32Mut {
    fn from(s: &mut [i32]) -> SpanI32Mut {
        let mut sp = sys::OIIO_span_int_t::default();
        unsafe {
            sys::OIIO_span_int_from_ptr(
                &mut sp,
                s.as_mut_ptr(),
                s.len() as i64,
            );
        }

        SpanI32Mut(sp)
    }
}

impl From<&[i32]> for SpanI32 {
    fn from(s: &[i32]) -> SpanI32 {
        let mut sp = sys::OIIO_cspan_int_t::default();
        unsafe {
            sys::OIIO_cspan_int_from_ptr(
                &mut sp,
                s.as_ptr(),
                s.len() as i64,
            );
        }

        SpanI32(sp)
    }
}

#[repr(transparent)]
pub struct SpanString(pub(crate) sys::OIIO_cspan_string_t);

impl From<&[CppString]> for SpanString {
    fn from(s: &[CppString]) -> SpanString {
        let mut sp = sys::OIIO_cspan_string_t::default();
        unsafe {
            sys::OIIO_cspan_string_from_ptr(
                &mut sp,
                s.as_ptr() as *const sys::std_string_t,
                s.len() as i64,
            );
        }

        SpanString(sp)
    }
}
