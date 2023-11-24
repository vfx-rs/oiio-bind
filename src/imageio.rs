use crate::sys;

#[derive(Debug, thiserror::Error)]
#[error("{0}")]
pub struct ImageInputIoError(String);

pub struct ImageInput(cxx::UniquePtr<sys::imageio::ImageInput>);

/// Call close() at the end of the object's lifetime.
impl Drop for ImageInput {
    fn drop(&mut self) {
        if let Some(sys_image_input) = self.0.as_mut() {
            let _ = sys::imageio::imageinput_close(sys_image_input);
        }
    }
}

impl ImageInput {
    /// Open an image file.
    pub fn from_path(image_path: &std::path::Path) -> Result<Self, ImageInputIoError> {
        let image_path_str = match image_path.to_str() {
            Some(image_path_str) => image_path_str,
            None => {
                return Err(ImageInputIoError(format!(
                    "Could not open file {image_path:?} (invalid unicode)"
                )));
            }
        };

        match sys::imageio::imageinput_open_without_config(image_path_str) {
            Ok(imageinput_ptr) => {
                if !imageinput_ptr.is_null() {
                    Ok(ImageInput(imageinput_ptr))
                } else {
                    let error_message = if sys::imageio::has_error() {
                        sys::imageio::get_error(true)
                    } else {
                        format!("Could not open file {image_path:?}")
                    };
                    Err(ImageInputIoError(error_message))
                }
            }
            Err(err) => Err(ImageInputIoError(err.to_string())),
        }
    }

    /// Return the format name for this ImageInput
    pub fn format_name(&self) -> &str {
        if let Some(sys_image_input) = self.0.as_ref() {
            sys::imageio::imageinput_format_name(sys_image_input)
        } else {
            "unknown(null)"
        }
    }

    /// Get the current thread count.
    pub fn threads(&self) -> i32 {
        if let Some(sys_image_input) = self.0.as_ref() {
            sys::imageio::imageinput_threads(sys_image_input)
        } else {
            1
        }
    }

    /// Set the thread count.
    pub fn set_threads(&mut self, threads: i32) {
        if let Some(sys_image_input) = self.0.as_mut() {
            sys::imageio::imageinput_set_threads(sys_image_input, threads)
        }
    }
}
