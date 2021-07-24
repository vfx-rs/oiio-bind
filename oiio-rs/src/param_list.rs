use crate::traits::AttributeMetadata;
use crate::typedesc::TypeDesc;
use crate::ustring::UString;
use oiio_sys as sys;

#[repr(transparent)]
pub struct ParamValue(pub(crate) sys::OIIO_ParamValue_t);

impl ParamValue {
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

    pub fn nvalues(&self) -> i32 {
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
        if self.nvalues() != 1 {
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
                self.nvalues() as usize,
            ))
        }
    }
}

/// Interpolation types
///
#[repr(C)]
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
