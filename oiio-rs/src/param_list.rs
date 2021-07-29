use crate::traits::AttributeMetadata;
use crate::typedesc::TypeDesc;
use crate::ustring::UString;
use oiio_sys as sys;
use std::os::raw::c_void;

#[repr(transparent)]
pub struct ParamValue(pub(crate) sys::OIIO_ParamValue_t);

impl ParamValue {
    pub fn new<A: AttributeMetadata>(
        name: UString,
        interp: Interp,
        value: &A,
    ) -> ParamValue {
        let mut pv = sys::OIIO_ParamValue_t::default();
        unsafe {
            sys::OIIO_ParamValue_with_interp_ustring(
                &mut pv,
                &name.0,
                A::TYPE.into(),
                1,
                interp.into(),
                value.ptr(),
                true,
            );
        }

        ParamValue(pv)
    }

    pub fn from_slice<A: AttributeMetadata>(
        name: UString,
        interp: Interp,
        value: &[A],
    ) -> ParamValue {
        let mut pv = sys::OIIO_ParamValue_t::default();
        unsafe {
            sys::OIIO_ParamValue_with_interp_ustring(
                &mut pv,
                &name.0,
                A::TYPE.into(),
                value.len() as i32,
                interp.into(),
                value.as_ptr() as *const c_void,
                true,
            );
        }

        ParamValue(pv)
    }

    pub fn name(&self) -> &'static str {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ParamValue_name(&self.0, &mut ptr);
            UString((*ptr).clone()).as_str()
        }
    }

    pub fn param_type(&self) -> TypeDesc {
        let mut td = TypeDesc::UNKNOWN;
        unsafe {
            sys::OIIO_ParamValue_type(
                &self.0,
                &mut td as *mut TypeDesc as *mut sys::OIIO_TypeDesc_t,
            );
        }
        td
    }

    pub fn num_values(&self) -> i32 {
        let mut value = 0;
        unsafe {
            sys::OIIO_ParamValue_nvalues(&self.0, &mut value);
        }
        value
    }

    pub fn get<A: AttributeMetadata>(&self) -> Option<&A> {
        if self.param_type() != A::TYPE {
            return None;
        }
        if self.num_values() != 1 {
            return None;
        }

        unsafe {
            let mut ptr = std::ptr::null();
            sys::OIIO_ParamValue_data(&self.0, &mut ptr);
            Some(&*(ptr as *const A))
        }
    }

    pub fn get_slice<A: AttributeMetadata>(&self) -> Option<&[A]> {
        if self.param_type() != A::TYPE {
            return None;
        }

        unsafe {
            let mut ptr = std::ptr::null();
            sys::OIIO_ParamValue_data(&self.0, &mut ptr);
            Some(std::slice::from_raw_parts(
                ptr as *const A,
                self.num_values() as usize,
            ))
        }
    }
}

/// Interpolation types
///
#[derive(Debug, Copy, Clone, PartialEq, PartialOrd)]
pub enum Interp {
    /// Constant for all pieces/faces
    Constant = 0,
    /// Piecewise constant per face/piece
    PerPiece,
    /// Linearly interpolated across each face/piece
    Linear,
    /// Interpolated like vertices
    Vertex,
}

impl From<Interp> for sys::OIIO_ParamValue_Interp {
    fn from(i: Interp) -> Self {
        match i {
            Interp::Constant => sys::OIIO_ParamValue_Interp_INTERP_CONSTANT,
            Interp::PerPiece => sys::OIIO_ParamValue_Interp_INTERP_PERPIECE,
            Interp::Linear => sys::OIIO_ParamValue_Interp_INTERP_LINEAR,
            Interp::Vertex => sys::OIIO_ParamValue_Interp_INTERP_VERTEX,
        }
    }
}
