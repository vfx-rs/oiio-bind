use crate::cppstd::{CppString, CppVectorString};
use crate::error::Error;
use crate::typedesc::TypeDesc;

use crate::string_view::StringView;
use crate::ustring::UString;

use oiio_sys as sys;

use imath_traits::Matrix44;

use std::convert::TryInto;
use std::ffi::CStr;

type Result<T, E = Error> = std::result::Result<T, E>;

/// The ColorProcessor encapsulates a baked color transformation, suitable for
/// application to raw pixels, or ImageBuf(s). These are generated using
/// ColorConfig::createColorProcessor, and referenced in ImageBufAlgo
/// (amongst other places)
///
pub struct ColorProcessor(pub(crate) *mut sys::std_ColorProcessorHandle_t);

impl Drop for ColorProcessor {
    fn drop(&mut self) {
        unsafe {
            sys::std_ColorProcessorHandle_dtor(self.0);
        }
    }
}

pub struct ColorConfig(pub(crate) *mut sys::OIIO_ColorConfig_t);

impl ColorConfig {
    /// Construct a new ColorConfig using the give OCIO configuration file
    ///
    pub fn from_file(filename: &str) -> Self {
        let mut ptr = std::ptr::null_mut();
        let filename = StringView::from(filename);
        unsafe {
            sys::OIIO_ColorConfig_ctor(&mut ptr, filename.0);
        }

        Self(ptr)
    }

    /// Construct a new ColorConfig using the configuration speified by the
    /// `$OCIO` environment variable
    ///
    pub fn from_env() -> Self {
        let mut ptr = std::ptr::null_mut();
        let filename = StringView::from("");
        unsafe {
            sys::OIIO_ColorConfig_ctor(&mut ptr, filename.0);
        }

        Self(ptr)
    }

    /// Reset the config to the named OCIO configuration file, or if
    /// filename is empty, to the current color configuration specified
    /// by env variable `$OCIO`. Return true for success, false if there
    /// was an error.
    ///
    /// Multiple calls to this are potentially expensive. A ColorConfig
    /// should usually be shared by an app for its entire runtime.
    ///
    pub fn reset(&mut self, filename: StringView) -> Result<()> {
        let filename = StringView::from(filename);
        let mut result = false;
        unsafe {
            sys::OIIO_ColorConfig_reset(self.0, &mut result, filename.0);
        }

        if result {
            Ok(())
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }

    /// Has an error string occurred?
    /// (This will not affect the error state.)
    ///
    pub fn error(&self) -> bool {
        let mut result = false;
        unsafe {
            sys::OIIO_ColorConfig_error(self.0, &mut result);
        }

        result
    }

    /// Return the text of all pending error messages issued against this
    /// ColorConfig by the calling thread, and clear the pending error
    /// message unless `clear` is false. If no error message is pending, it
    /// will return an empty string.
    ///
    pub fn get_error(&self, clear: bool) -> String {
        let mut msg = CppString::new("");
        unsafe {
            sys::OIIO_ColorConfig_geterror(self.0, &mut msg.0, clear);
            msg.as_str().to_string()
        }
    }

    /// Get the number of ColorSpace(s) defined in this configuration
    ///
    pub fn num_color_spaces(&self) -> usize {
        let mut result = 0;
        unsafe {
            sys::OIIO_ColorConfig_getNumColorSpaces(self.0, &mut result);
        }

        result as usize
    }

    /// Query the name of the specified ColorSpace.
    ///
    pub fn get_color_space_name_by_index(&self, index: usize) -> &str {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ColorConfig_getColorSpaceNameByIndex(
                self.0,
                &mut ptr,
                index.try_into().expect("index is not representable as i32"),
            );
            CStr::from_ptr(ptr)
                .to_str()
                .expect("Color space name is not valid UTF-8")
        }
    }

    /// Get the name of the color space representing the named role, or `None`
    /// if it could not be identified
    ///
    pub fn get_color_space_name_by_role(&self, role: &str) -> Option<&str> {
        let mut ptr = std::ptr::null();
        let role = StringView::from(role);

        unsafe {
            sys::OIIO_ColorConfig_getColorSpaceNameByRole(
                self.0, &mut ptr, role.0,
            );

            if ptr.is_null() {
                None
            } else {
                Some(
                    CStr::from_ptr(ptr)
                        .to_str()
                        .expect("Color space name is not valid UTF-8"),
                )
            }
        }
    }

    /// Get the data type that OCIO thinks this color space is. The name
    /// may be either a color space name or a role.
    ///
    pub fn get_color_space_data_type(&self, name: &str) -> TypeDesc {
        let mut td = TypeDesc::UNKNOWN;
        let name = StringView::from(name);
        unsafe {
            sys::OIIO_ColorConfig_getColorSpaceDataType(
                self.0,
                &mut td as *mut _ as *mut sys::OIIO_TypeDesc_t,
                name.0,
                std::ptr::null_mut(),
            );
        }

        td
    }

    /// Get the full list of known colour space names
    ///
    pub fn color_space_names(&self) -> Vec<String> {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ColorConfig_getColorSpaceNames(self.0, &mut ptr);
        }

        CppVectorString(ptr).to_vec()
    }

    /// Get the name of the color space family of the named color space, or `None`
    /// if it could not be identified
    ///
    pub fn get_color_space_family_by_name(&self, name: &str) -> Option<&str> {
        let mut ptr = std::ptr::null();
        let name = StringView::from(name);

        unsafe {
            sys::OIIO_ColorConfig_getColorSpaceFamilyByName(
                self.0, &mut ptr, name.0,
            );

            if ptr.is_null() {
                None
            } else {
                Some(
                    CStr::from_ptr(ptr)
                        .to_str()
                        .expect("Color space name is not valid UTF-8"),
                )
            }
        }
    }

    /// Get the number of Roles defined in this configuration
    ///
    pub fn num_roles(&self) -> usize {
        let mut result = 0;
        unsafe {
            sys::OIIO_ColorConfig_getNumRoles(self.0, &mut result);
        }

        result as usize
    }

    /// Query the name of the specified Role.
    ///
    pub fn get_role_by_index(&self, index: usize) -> &str {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ColorConfig_getRoleByIndex(
                self.0,
                &mut ptr,
                index.try_into().expect("index is not representable as i32"),
            );
            CStr::from_ptr(ptr)
                .to_str()
                .expect("Color space name is not valid UTF-8")
        }
    }

    /// Get the full list of known Roles
    ///
    pub fn roles(&self) -> Vec<String> {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ColorConfig_getRoles(self.0, &mut ptr);
        }

        CppVectorString(ptr).to_vec()
    }

    /// Get the number of looks defined in this configuration
    ///
    pub fn num_looks(&self) -> usize {
        let mut result = 0;
        unsafe {
            sys::OIIO_ColorConfig_getNumLooks(self.0, &mut result);
        }

        result as usize
    }

    /// Query the name of the specified look.
    ///
    pub fn get_look_name_by_index(&self, index: usize) -> &str {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ColorConfig_getLookNameByIndex(
                self.0,
                &mut ptr,
                index.try_into().expect("index is not representable as i32"),
            );
            CStr::from_ptr(ptr)
                .to_str()
                .expect("Color space name is not valid UTF-8")
        }
    }

    /// Get the full list of known look names
    ///
    pub fn look_names(&self) -> Vec<String> {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ColorConfig_getLookNames(self.0, &mut ptr);
        }

        CppVectorString(ptr).to_vec()
    }

    /// Given the specified input and output ColorSpace, request a handle to
    /// a ColorProcessor, returning `None` if either color space does not exist
    /// or the transformation is illegal (for example if it requires the
    /// inversion of a 3D LUT).
    ///
    /// Created ColorProcessors are cached, so asking for the same color
    /// space transformation multiple times shouldn't be very expensive.
    ///
    pub fn create_color_processor(
        &self,
        input_color_space: &str,
        output_color_space: &str,
        context_key: &str,
        context_value: &str,
    ) -> Option<ColorProcessor> {
        let mut ptr = std::ptr::null_mut();
        let input_color_space = StringView::from(input_color_space);
        let output_color_space = StringView::from(output_color_space);
        let context_key = StringView::from(context_key);
        let context_value = StringView::from(context_value);
        unsafe {
            sys::OIIO_ColorConfig_createColorProcessor(
                self.0,
                &mut ptr,
                input_color_space.0,
                output_color_space.0,
                context_key.0,
                context_value.0,
            );

            let mut pointee = std::ptr::null_mut();
            sys::std_ColorProcessorHandle_get(ptr, &mut pointee);

            if pointee.is_null() {
                None
            } else {
                Some(ColorProcessor(ptr))
            }
        }
    }

    /// Given the specified input and output ColorSpace, request a handle to
    /// a ColorProcessor, returning `None` if either color space does not exist
    /// or the transformation is illegal (for example if it requires the
    /// inversion of a 3D LUT).
    ///
    /// Created ColorProcessors are cached, so asking for the same color
    /// space transformation multiple times shouldn't be very expensive.
    ///
    pub fn create_color_processor_ustring(
        &self,
        input_color_space: UString,
        output_color_space: UString,
        context_key: UString,
        context_value: UString,
    ) -> Option<ColorProcessor> {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ColorConfig_createColorProcessor_ustring(
                self.0,
                &mut ptr,
                input_color_space.0,
                output_color_space.0,
                context_key.0,
                context_value.0,
            );

            let mut pointee = std::ptr::null_mut();
            sys::std_ColorProcessorHandle_get(ptr, &mut pointee);

            if pointee.is_null() {
                None
            } else {
                Some(ColorProcessor(ptr))
            }
        }
    }

    /// Given the named look(s), input and output color spaces, request a
    /// color processor that applies an OCIO look transformation.  If
    /// inverse==true, request the inverse transformation.  The
    /// context_key and context_value can optionally be used to establish
    /// extra key/value pairs in the OCIO context if they are comma-
    /// separated lists of ontext keys and values, respectively.
    ///
    /// Created ColorProcessors are cached, so asking for the same color
    /// space transformation multiple times shouldn't be very expensive.
    ///
    pub fn create_look_transform(
        &self,
        looks: &str,
        input_color_space: &str,
        output_color_space: &str,
        inverse: bool,
        context_key: &str,
        context_value: &str,
    ) -> Option<ColorProcessor> {
        let mut ptr = std::ptr::null_mut();
        let looks = StringView::from(looks);
        let input_color_space = StringView::from(input_color_space);
        let output_color_space = StringView::from(output_color_space);
        let context_key = StringView::from(context_key);
        let context_value = StringView::from(context_value);
        unsafe {
            sys::OIIO_ColorConfig_createLookTransform(
                self.0,
                &mut ptr,
                looks.0,
                input_color_space.0,
                output_color_space.0,
                inverse,
                context_key.0,
                context_value.0,
            );

            let mut pointee = std::ptr::null_mut();
            sys::std_ColorProcessorHandle_get(ptr, &mut pointee);

            if pointee.is_null() {
                None
            } else {
                Some(ColorProcessor(ptr))
            }
        }
    }

    /// Given the named look(s), input and output color spaces, request a
    /// color processor that applies an OCIO look transformation.  If
    /// inverse==true, request the inverse transformation.  The
    /// context_key and context_value can optionally be used to establish
    /// extra key/value pairs in the OCIO context if they are comma-
    /// separated lists of ontext keys and values, respectively.
    ///
    /// Created ColorProcessors are cached, so asking for the same color
    /// space transformation multiple times shouldn't be very expensive.
    ///
    pub fn create_look_transform_ustring(
        &self,
        looks: UString,
        input_color_space: UString,
        output_color_space: UString,
        inverse: bool,
        context_key: UString,
        context_value: UString,
    ) -> Option<ColorProcessor> {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ColorConfig_createLookTransform_ustring(
                self.0,
                &mut ptr,
                looks.0,
                input_color_space.0,
                output_color_space.0,
                inverse,
                context_key.0,
                context_value.0,
            );

            let mut pointee = std::ptr::null_mut();
            sys::std_ColorProcessorHandle_get(ptr, &mut pointee);

            if pointee.is_null() {
                None
            } else {
                Some(ColorProcessor(ptr))
            }
        }
    }

    /// Get the number of displays defined in this configuration
    ///
    pub fn num_displays(&self) -> usize {
        let mut result = 0;
        unsafe {
            sys::OIIO_ColorConfig_getNumDisplays(self.0, &mut result);
        }

        result as usize
    }

    /// Query the name of the specified display.
    ///
    pub fn get_display_name_by_index(&self, index: usize) -> &str {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ColorConfig_getDisplayNameByIndex(
                self.0,
                &mut ptr,
                index.try_into().expect("index is not representable as i32"),
            );
            CStr::from_ptr(ptr)
                .to_str()
                .expect("Color space name is not valid UTF-8")
        }
    }

    /// Get the full list of known display names
    ///
    pub fn display_names(&self) -> Vec<String> {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ColorConfig_getDisplayNames(self.0, &mut ptr);
        }

        CppVectorString(ptr).to_vec()
    }

    /// Get the name of the default display.
    ///
    pub fn default_display_name(&self) -> &str {
        let mut ptr = std::ptr::null();
        unsafe {
            sys::OIIO_ColorConfig_getDefaultDisplayName(self.0, &mut ptr);
            CStr::from_ptr(ptr)
                .to_str()
                .expect("Color space name is not valid UTF-8")
        }
    }

    /// Get the number of views defined in this configuration
    ///
    pub fn num_views(&self, display: Option<&str>) -> usize {
        let mut result = 0;
        let display = if let Some(display) = display {
            StringView::from(display)
        } else {
            StringView::from("")
        };
        unsafe {
            sys::OIIO_ColorConfig_getNumViews(self.0, &mut result, display.0);
        }

        result as usize
    }

    /// Query the name of the specified view.
    ///
    pub fn get_view_name_by_index(
        &self,
        index: usize,
        display: Option<&str>,
    ) -> &str {
        let mut ptr = std::ptr::null();
        let display = if let Some(display) = display {
            StringView::from(display)
        } else {
            StringView::from("")
        };
        unsafe {
            sys::OIIO_ColorConfig_getViewNameByIndex(
                self.0,
                &mut ptr,
                display.0,
                index.try_into().expect("index is not representable as i32"),
            );
            CStr::from_ptr(ptr)
                .to_str()
                .expect("Color space name is not valid UTF-8")
        }
    }

    /// Get the full list of known view names
    ///
    pub fn view_names(&self, display: Option<&str>) -> Vec<String> {
        let mut ptr = std::ptr::null_mut();
        let display = if let Some(display) = display {
            StringView::from(display)
        } else {
            StringView::from("")
        };
        unsafe {
            sys::OIIO_ColorConfig_getViewNames(self.0, &mut ptr, display.0);
        }

        CppVectorString(ptr).to_vec()
    }

    /// Get the name of the default view.
    ///
    pub fn default_view_name(&self, display: Option<&str>) -> &str {
        let mut ptr = std::ptr::null();
        let display = if let Some(display) = display {
            StringView::from(display)
        } else {
            StringView::from("")
        };
        unsafe {
            sys::OIIO_ColorConfig_getDefaultViewName(
                self.0, &mut ptr, display.0,
            );
            CStr::from_ptr(ptr)
                .to_str()
                .expect("Color space name is not valid UTF-8")
        }
    }

    /// Construct a processor to transform from the given color space
    /// to the color space of the given display and view. You may optionally
    /// override the looks that are, by default, used with the display/view
    /// combination. Looks is a potentially comma (or colon) delimited list
    /// of lookNames, where +/- prefixes are optionally allowed to denote
    /// forward/inverse transformation (and forward is assumed in the
    /// absence of either). It is possible to remove all looks from the
    /// display by passing an empty string. The context_key and context_value
    /// can optionally be used to establish extra key/value pair in the OCIO
    /// context if they are comma-separated lists of context keys and
    /// values, respectively.
    ///
    /// Created ColorProcessors are cached, so asking for the same color
    /// space transformation multiple times shouldn't be very expensive.
    ///
    pub fn create_display_transform(
        &self,
        display: &str,
        view: &str,
        input_color_space: &str,
        looks: &str,
        context_key: &str,
        context_value: &str,
    ) -> Option<ColorProcessor> {
        let mut ptr = std::ptr::null_mut();
        let display = StringView::from(display);
        let view = StringView::from(view);
        let input_color_space = StringView::from(input_color_space);
        let looks = StringView::from(looks);
        let context_key = StringView::from(context_key);
        let context_value = StringView::from(context_value);
        unsafe {
            sys::OIIO_ColorConfig_createDisplayTransform(
                self.0,
                &mut ptr,
                display.0,
                view.0,
                input_color_space.0,
                looks.0,
                context_key.0,
                context_value.0,
            );

            let mut pointee = std::ptr::null_mut();
            sys::std_ColorProcessorHandle_get(ptr, &mut pointee);

            if pointee.is_null() {
                None
            } else {
                Some(ColorProcessor(ptr))
            }
        }
    }

    /// Construct a processor to transform from the given color space
    /// to the color space of the given display and view. You may optionally
    /// override the looks that are, by default, used with the display/view
    /// combination. Looks is a potentially comma (or colon) delimited list
    /// of lookNames, where +/- prefixes are optionally allowed to denote
    /// forward/inverse transformation (and forward is assumed in the
    /// absence of either). It is possible to remove all looks from the
    /// display by passing an empty string. The context_key and context_value
    /// can optionally be used to establish extra key/value pair in the OCIO
    /// context if they are comma-separated lists of context keys and
    /// values, respectively.
    ///
    /// Created ColorProcessors are cached, so asking for the same color
    /// space transformation multiple times shouldn't be very expensive.
    ///
    pub fn create_display_transform_ustring(
        &self,
        display: UString,
        view: UString,
        input_color_space: UString,
        looks: UString,
        context_key: UString,
        context_value: UString,
    ) -> Option<ColorProcessor> {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ColorConfig_createDisplayTransform_ustring(
                self.0,
                &mut ptr,
                display.0,
                view.0,
                input_color_space.0,
                looks.0,
                context_key.0,
                context_value.0,
            );

            let mut pointee = std::ptr::null_mut();
            sys::std_ColorProcessorHandle_get(ptr, &mut pointee);

            if pointee.is_null() {
                None
            } else {
                Some(ColorProcessor(ptr))
            }
        }
    }

    /// Construct a processor to perform color transforms determined by an
    /// OpenColorIO FileTransform. It is possible that this will return an
    /// empty handle if the FileTransform doesn't exist or is not allowed.
    ///
    /// Created ColorProcessors are cached, so asking for the same color
    /// space transformation multiple times shouldn't be very expensive.
    ///
    pub fn create_file_transform(
        &self,
        name: &str,
        inverse: bool,
    ) -> Option<ColorProcessor> {
        let mut ptr = std::ptr::null_mut();
        let name = StringView::from(name);
        unsafe {
            sys::OIIO_ColorConfig_createFileTransform(
                self.0,
                &mut ptr,
                name.0,
                inverse
            );

            let mut pointee = std::ptr::null_mut();
            sys::std_ColorProcessorHandle_get(ptr, &mut pointee);

            if pointee.is_null() {
                None
            } else {
                Some(ColorProcessor(ptr))
            }
        }
    }

    /// Construct a processor to perform color transforms determined by an
    /// OpenColorIO FileTransform. It is possible that this will return an
    /// empty handle if the FileTransform doesn't exist or is not allowed.
    ///
    /// Created ColorProcessors are cached, so asking for the same color
    /// space transformation multiple times shouldn't be very expensive.
    ///
    pub fn create_file_transform_ustring(
        &self,
        name: UString,
        inverse: bool,
    ) -> Option<ColorProcessor> {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ColorConfig_createFileTransform_ustring(
                self.0,
                &mut ptr,
                name.0,
                inverse
            );

            let mut pointee = std::ptr::null_mut();
            sys::std_ColorProcessorHandle_get(ptr, &mut pointee);

            if pointee.is_null() {
                None
            } else {
                Some(ColorProcessor(ptr))
            }
        }
    }

    /// Construct a processor to perform color transforms specified by a
    /// 4x4 matrix.
    ///
    /// Created ColorProcessors are cached, so asking for the same color
    /// space transformation multiple times shouldn't be very expensive.
    ///
    pub fn create_matrix_transform<M: Matrix44<f32>>(
        &self,
        matrix: &M,
        inverse: bool,
    ) -> Option<ColorProcessor> {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ColorConfig_createMatrixTransform(
                self.0,
                &mut ptr,
                matrix as *const M as *const sys::Imath_M44f_t,
                inverse
            );

            let mut pointee = std::ptr::null_mut();
            sys::std_ColorProcessorHandle_get(ptr, &mut pointee);

            if pointee.is_null() {
                None
            } else {
                Some(ColorProcessor(ptr))
            }
        }
    }

    /// Given a filepath, ask OCIO what color space it thinks the file
    /// should be, based on how the name matches file naming rules in the
    /// OCIO config.  (This is mostly a wrapper around OCIO's
    /// ColorConfig::getColorSpaceFromSFilepath.)
    ///
    pub fn get_color_space_from_file_path(&self, name: &str) -> &str {
        let mut result = Default::default();
        let name = StringView::from(name);

        unsafe {
            sys::OIIO_ColorConfig_getColorSpaceFromFilepath(
                self.0, &mut result, name.0,
            );
            
            let mut ptr = std::ptr::null();
            sys::OIIO_string_view_c_str(&result, &mut ptr);
            let mut len = 0;
            sys::OIIO_string_view_size(&result, &mut len);

            std::str::from_utf8(std::slice::from_raw_parts(ptr as *const u8, len)).expect("Could not convert result")
        }
    }


    /// Given a string (like a filename), look for the longest, right-most
    /// colorspace substring that appears. Returns "" if no such color space
    /// is found.
    ///
    pub fn parse_color_space_from_string(&self, name: &str) -> &str {
        let mut result = Default::default();
        let name = StringView::from(name);

        unsafe {
            sys::OIIO_ColorConfig_parseColorSpaceFromString(
                self.0, &mut result, name.0,
            );
            
            let mut ptr = std::ptr::null();
            sys::OIIO_string_view_c_str(&result, &mut ptr);
            let mut len = 0;
            sys::OIIO_string_view_size(&result, &mut len);

            std::str::from_utf8(std::slice::from_raw_parts(ptr as *const u8, len)).expect("Could not convert result")
        }
    }

    /// Return a filename or other identifier for the config we're using.
    ///
    pub fn config_name(&self) -> String {
        let mut result = CppString::new("");
        unsafe {
            sys::OIIO_ColorConfig_configname(self.0, &mut result.0);
        }

        result.as_str().to_string()
    }

    /// Return if OpenImageIO was built with OCIO support
    ///
    pub fn supports_opencolorio() -> bool {
        let mut result = false;
        unsafe {
            sys::OIIO_ColorConfig_supportsOpenColorIO(&mut result);
        }

        result
    }

    /// Return the hex OCIO version (maj<<24 + min<<16 + patch), or 0 if no
    /// OCIO support is available.
    ///
    pub fn opencolorio_version_hex() -> i32 {
        let mut result = 0;
        unsafe {
            sys::OIIO_ColorConfig_OpenColorIO_version_hex(&mut result);
        }

        result
    }
}

impl Drop for ColorConfig {
    fn drop(&mut self) {
        unsafe {
            sys::OIIO_ColorConfig_dtor(self.0);
        }
    }
}

#[cfg(test)]
mod test {
    use crate as oiio;

    #[test]
    fn test_supports_ocio() {
        let s = oiio::color::ColorConfig::supports_opencolorio();
        println!("Supports OCIO: {}", s);
    }

    #[test]
    fn test_known_color_spaces() {
        let color_config = oiio::color::ColorConfig::from_env();
        println!("Known colour spaces: {:?}", color_config.color_space_names());
    }
}
