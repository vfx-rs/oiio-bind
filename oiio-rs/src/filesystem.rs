use crate::error::Error;
use oiio_sys as sys;
use std::ffi::{CStr, CString};
use std::path::Path;

type Result<T, E = Error> = std::result::Result<T, E>;

#[repr(transparent)]
pub struct IOProxy(pub(crate) *mut sys::OIIO_Filesystem_IOProxy_t);
