use oiio_sys as sys;

#[repr(transparent)]
pub struct StringView(pub(crate) sys::OIIO_string_view_t);

impl StringView {
    pub fn as_str(&self) -> &str {
        unsafe {
            let mut len = 0;
            let mut ptr = std::ptr::null();
            sys::OIIO_string_view_c_str(&self.0, &mut ptr);
            sys::OIIO_string_view_length(&self.0, &mut len);

            std::str::from_utf8_unchecked(std::slice::from_raw_parts(
                ptr as *const u8,
                len as usize,
            ))
        }
    }
}

impl From<&str> for StringView {
    fn from(s: &str) -> StringView {
        unsafe {
            let mut sv = sys::OIIO_string_view_t::default();
            sys::OIIO_string_view_from_char_array(
                &mut sv,
                s.as_ptr() as *const i8,
                s.len() as u64,
            );

            StringView(sv)
        }
    }

}

impl From<StringView> for sys::OIIO_string_view_t {
    fn from(s: StringView) -> Self {
        s.0
    }
}
