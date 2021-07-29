use oiio_sys as sys;
use std::ffi::CString;

#[repr(transparent)]
pub struct UString(pub(crate) sys::OIIO_ustring_t);

impl UString {
    pub fn new(s: &str) -> Self {
        unsafe {
            let cs = CString::new(s).unwrap();
            let mut u = sys::OIIO_ustring_t::default();
            sys::OIIO_ustring_ctor(&mut u, cs.as_ptr());
            UString(u)
        }
    }

    pub fn as_str(&self) -> &'static str {
        unsafe {
            let mut len = 0;
            let mut ptr = std::ptr::null();
            sys::OIIO_ustring_c_str(&self.0, &mut ptr);
            sys::OIIO_ustring_length(&self.0, &mut len);

            std::str::from_utf8_unchecked(std::slice::from_raw_parts(
                ptr as *const u8,
                len as usize,
            ))
        }
    }
}

impl PartialEq for UString {
    fn eq(&self, other: &Self) -> bool {
        unsafe {
            // # Safety
            // This is safe as the opaque internals is a pointer
            let a = *(&self.0 as *const _ as *const *const i8);
            let b = *(&other.0 as *const _ as *const *const i8);
            a == b
        }
    }
}

impl Eq for UString{}

impl Default for UString {
    fn default() -> Self {
        UString::new("")
    }
}

impl std::fmt::Debug for UString {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> Result<(), std::fmt::Error> {
        write!(f, "{}", self.as_str())
    }
}
