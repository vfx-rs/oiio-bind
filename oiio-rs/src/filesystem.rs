use oiio_sys as sys;

#[repr(transparent)]
pub struct IOProxy(pub(crate) *mut sys::OIIO_Filesystem_IOProxy_t);
