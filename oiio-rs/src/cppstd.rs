use oiio_sys as sys;
use std::ffi::{CStr, CString};

use crate::refptr::{OpaquePtr, Ref, RefMut};
use crate::typedesc::TypeDesc;

#[repr(transparent)]
pub struct CppString(pub(crate) *mut sys::std_string_t);

unsafe impl OpaquePtr for CppString {
    type SysPointee = sys::std_string_t;
    type Pointee = CppString;
}

pub type CppStringRef<'a, P = CppString> = Ref<'a, P>;
pub type CppStringRefMut<'a, P = CppString> = RefMut<'a, P>;

impl CppString {
    pub fn new(string: &str) -> CppString {
        let cstring = CString::new(string).expect("Inner NUL bytes in string");
        unsafe {
            let mut ptr = std::ptr::null_mut();
            sys::std_string_ctor(&mut ptr);
            let mut dummy = std::ptr::null_mut();
            sys::std_string_assign(
                ptr,
                &mut dummy,
                cstring.as_ptr(),
                cstring.as_bytes().len(),
            );
            CppString(ptr)
        }
    }

    pub fn as_str(self: &CppString) -> &str {
        let mut cptr = std::ptr::null();
        unsafe {
            sys::std_string_c_str(self.0, &mut cptr);
            CStr::from_ptr(cptr).to_str().unwrap()
        }
    }
}

impl Drop for CppString {
    fn drop(&mut self) {
        unsafe {
            sys::std_string_dtor(self.0);
        }
    }
}

#[repr(transparent)]
pub struct CppVectorFloat(pub(crate) *mut sys::std_vector_float_t);

unsafe impl OpaquePtr for CppVectorFloat {
    type SysPointee = sys::std_vector_float_t;
    type Pointee = CppVectorFloat;
}

pub type CppVectorFloatRef<'a, P = CppVectorFloat> = Ref<'a, P>;
pub type CppVectorFloatRefMut<'a, P = CppVectorFloat> = RefMut<'a, P>;

impl CppVectorFloat {
    pub fn new() -> CppVectorFloat {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::std_vector_float_ctor(&mut ptr).into_result().unwrap();
        }
        CppVectorFloat(ptr)
    }

    pub fn from_slice(vec: &[f32]) -> CppVectorFloat {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::std_vector_float_ctor(&mut ptr).into_result().unwrap();

            for rs in vec {
                sys::std_vector_float_push_back(ptr, rs)
                    .into_result()
                    .unwrap();
            }
        }

        CppVectorFloat(ptr)
    }

    pub fn as_slice(&self) -> &[f32] {
        let mut size = 0;
        let mut ptr = std::ptr::null();
        unsafe {
            sys::std_vector_float_size(self.0, &mut size);
            sys::std_vector_float_data_const(self.0, &mut ptr);
            std::slice::from_raw_parts(ptr, size as usize)
        }
    }

    pub fn as_slice_mut(&mut self) -> &mut [f32] {
        let mut size = 0;
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::std_vector_float_size(self.0, &mut size);
            sys::std_vector_float_data(self.0, &mut ptr);
            std::slice::from_raw_parts_mut(ptr, size as usize)
        }
    }
}

impl Default for CppVectorFloat {
    fn default() -> Self {
        CppVectorFloat::new()
    }
}

#[repr(transparent)]
pub struct CppVectorDouble(pub(crate) *mut sys::std_vector_double_t);

unsafe impl OpaquePtr for CppVectorDouble {
    type SysPointee = sys::std_vector_double_t;
    type Pointee = CppVectorDouble;
}

pub type CppVectorDoubleRef<'a, P = CppVectorDouble> = Ref<'a, P>;
pub type CppVectorDoubleRefMut<'a, P = CppVectorDouble> = RefMut<'a, P>;

impl CppVectorDouble {
    pub fn new() -> CppVectorDouble {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::std_vector_double_ctor(&mut ptr).into_result().unwrap();
        }
        CppVectorDouble(ptr)
    }

    pub fn from_slice(vec: &[f64]) -> CppVectorDouble {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::std_vector_double_ctor(&mut ptr).into_result().unwrap();

            for rs in vec {
                sys::std_vector_double_push_back(ptr, rs)
                    .into_result()
                    .unwrap();
            }
        }

        CppVectorDouble(ptr)
    }

    pub fn as_slice(&self) -> &[f64] {
        let mut size = 0;
        let mut ptr = std::ptr::null();
        unsafe {
            sys::std_vector_double_size(self.0, &mut size);
            sys::std_vector_double_data_const(self.0, &mut ptr);
            std::slice::from_raw_parts(ptr, size as usize)
        }
    }

    pub fn as_slice_mut(&mut self) -> &mut [f64] {
        let mut size = 0;
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::std_vector_double_size(self.0, &mut size);
            sys::std_vector_double_data(self.0, &mut ptr);
            std::slice::from_raw_parts_mut(ptr, size as usize)
        }
    }
}

impl Default for CppVectorDouble {
    fn default() -> Self {
        CppVectorDouble::new()
    }
}

#[repr(transparent)]
pub struct CppVectorString(pub(crate) *mut sys::std_vector_string_t);

unsafe impl OpaquePtr for CppVectorString {
    type SysPointee = sys::std_vector_string_t;
    type Pointee = CppVectorString;
}

pub type CppVectorStringRef<'a, P = CppVectorString> = Ref<'a, P>;
pub type CppVectorStringRefMut<'a, P = CppVectorString> = RefMut<'a, P>;

impl CppVectorString {
    pub fn new() -> CppVectorString {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::std_vector_string_ctor(&mut ptr).into_result().unwrap();
        }
        CppVectorString(ptr)
    }

    pub fn from_slice<S: AsRef<str>>(vec: &[S]) -> CppVectorString {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::std_vector_string_ctor(&mut ptr).into_result().unwrap();

            for rs in vec {
                let s = CppString::new(rs.as_ref());
                sys::std_vector_string_push_back(ptr, s.0)
                    .into_result()
                    .unwrap();
            }
        }

        CppVectorString(ptr)
    }

    /// Get a reference to the string at index `pos` without bounds checking
    ///
    /// # Safety
    /// You must ensure that `pos` is less than the length of the vector
    ///
    pub unsafe fn get_unchecked(&self, pos: usize) -> CppStringRef {
        let mut ptr = std::ptr::null();
        sys::std_vector_string_index(self.0, &mut ptr, pos);
        CppStringRef::new(ptr)
    }

    pub fn to_vec(&self) -> Vec<String> {
        let mut size = 0;
        unsafe {
            sys::std_vector_string_size(self.0, &mut size);
            let mut result = Vec::with_capacity(size as usize);
            for i in 0..size {
                let mut sptr = std::ptr::null();
                sys::std_vector_string_index(self.0, &mut sptr, i);
                let mut cptr = std::ptr::null();
                sys::std_string_c_str(sptr, &mut cptr);
                result.push(CStr::from_ptr(cptr).to_string_lossy().to_string());
            }

            result
        }
    }
}

impl Default for CppVectorString {
    fn default() -> Self {
        CppVectorString::new()
    }
}

#[repr(transparent)]
pub struct CppVectorTypeDesc(pub(crate) *mut sys::std_vector_typedesc_t);

unsafe impl OpaquePtr for CppVectorTypeDesc {
    type SysPointee = sys::std_vector_typedesc_t;
    type Pointee = CppVectorTypeDesc;
}

pub type CppVectorTypeDescRef<'a, P = CppVectorTypeDesc> = Ref<'a, P>;
pub type CppVectorTypeDescRefMut<'a, P = CppVectorTypeDesc> = RefMut<'a, P>;

impl CppVectorTypeDesc {
    pub fn new() -> CppVectorTypeDesc {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::std_vector_typedesc_ctor(&mut ptr)
                .into_result()
                .unwrap();
        }
        CppVectorTypeDesc(ptr)
    }

    pub fn from_slice(vec: &[TypeDesc]) -> CppVectorTypeDesc {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::std_vector_typedesc_ctor(&mut ptr)
                .into_result()
                .unwrap();

            for rs in vec {
                sys::std_vector_typedesc_push_back(
                    ptr,
                    rs as *const TypeDesc as *const sys::OIIO_TypeDesc_t,
                )
                .into_result()
                .unwrap();
            }
        }

        CppVectorTypeDesc(ptr)
    }

    pub fn as_slice(&self) -> &[TypeDesc] {
        let mut size = 0;
        let mut ptr = std::ptr::null();
        unsafe {
            sys::std_vector_typedesc_size(self.0, &mut size);
            sys::std_vector_typedesc_data_const(self.0, &mut ptr);
            std::slice::from_raw_parts(ptr as *const TypeDesc, size as usize)
        }
    }

    pub fn as_slice_mut(&mut self) -> &mut [TypeDesc] {
        let mut size = 0;
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::std_vector_typedesc_size(self.0, &mut size);
            sys::std_vector_typedesc_data(self.0, &mut ptr);
            std::slice::from_raw_parts_mut(ptr as *mut TypeDesc, size as usize)
        }
    }
}

impl Default for CppVectorTypeDesc {
    fn default() -> Self {
        CppVectorTypeDesc::new()
    }
}

#[repr(transparent)]
pub struct CppVectorSize(pub(crate) *mut sys::std_vector_size_t_t);

unsafe impl OpaquePtr for CppVectorSize {
    type SysPointee = sys::std_vector_size_t_t;
    type Pointee = CppVectorSize;
}

pub type CppVectorSizeRef<'a, P = CppVectorSize> = Ref<'a, P>;
pub type CppVectorSizeRefMut<'a, P = CppVectorSize> = RefMut<'a, P>;

impl CppVectorSize {
    pub fn new() -> CppVectorSize {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::std_vector_size_t_ctor(&mut ptr).into_result().unwrap();
        }
        CppVectorSize(ptr)
    }

    pub fn from_slice(vec: &[usize]) -> CppVectorSize {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::std_vector_size_t_ctor(&mut ptr).into_result().unwrap();

            for rs in vec {
                sys::std_vector_size_t_push_back(
                    ptr,
                    rs as *const usize as *const u64,
                )
                .into_result()
                .unwrap();
            }
        }

        CppVectorSize(ptr)
    }

    pub fn as_slice(&self) -> &[usize] {
        let mut size = 0;
        let mut ptr = std::ptr::null();
        unsafe {
            sys::std_vector_size_t_size(self.0, &mut size);
            sys::std_vector_size_t_data_const(
                self.0,
                &mut ptr as *mut _ as *mut *const u64,
            );
            std::slice::from_raw_parts(ptr, size as usize)
        }
    }

    pub fn as_slice_mut(&mut self) -> &mut [usize] {
        let mut size = 0;
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::std_vector_size_t_size(self.0, &mut size);
            sys::std_vector_size_t_data(self.0, &mut ptr);
            std::slice::from_raw_parts_mut(ptr, size as usize)
        }
    }
}

impl Default for CppVectorSize {
    fn default() -> Self {
        CppVectorSize::new()
    }
}
