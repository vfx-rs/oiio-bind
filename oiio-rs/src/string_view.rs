use oiio_sys as sys;
use sys::OIIO_string_view_from_char_array;

#[repr(transparent)]
pub struct StringView(pub(crate) sys::OIIO_string_view_t);

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
