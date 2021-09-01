use oiio_sys as sys;
use crate::cppstd::CppString;

#[derive(Debug, Clone, thiserror::Error)]
pub enum Error {
    #[error("OIIO error: {0}")]
    Oiio(String),
    #[error("The provided buffer was too small for the data")]
    BufferTooSmall,
    #[error("The requested stride does not match the requested channel layout")]
    BadStride,
    #[error("The attribute was either not found, or had the wrong type")]
    InvalidAttribute,
    #[error("The provided ImageHandle did not refer to a valid image")]
    InvalidHandle,
    #[error("The provided ImageSpec did not specify a valid image")]
    InvalidSpec,
    #[error("The provided TypeDesc format is not supported")]
    InvalidFormat(crate::typedesc::TypeDesc),
}

pub fn get_error(clear: bool) -> String {
    unsafe {
        let mut error_string = CppString::new("");
        sys::OIIO_geterror(&mut error_string.0, clear);
        error_string.as_str().to_string()
    }
}
