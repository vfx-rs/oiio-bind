#[derive(Debug, Clone, thiserror::Error)]
pub enum Error {
    #[error("OIIO error: {0}")]
    Oiio(String),
    #[error("The provided buffer was too small for the data")]
    BufferTooSmall,
}
