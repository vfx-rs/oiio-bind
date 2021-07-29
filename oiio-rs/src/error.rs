#[derive(Debug, Clone, thiserror::Error)]
pub enum Error {
    #[error("OIIO error: {0}")]
    Oiio(String),
    #[error("The provided buffer was too small for the data")]
    BufferTooSmall,
    #[error("The attribute was either not found, or had the wrong type")]
    InvalidAttribute,
    #[error("The provided ImageHandle did not refer to a valid image")]
    InvalidHandle,
    #[error("The provided ImageSpec did not specify a valid image")]
    InvalidSpec,
    #[error("The provided TypeDesc format is not supported")]
    InvalidFormat(crate::typedesc::TypeDesc),
}
