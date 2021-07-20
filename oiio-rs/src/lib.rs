pub mod cppstd;
pub mod error;
pub mod filesystem;
pub mod imageio;
pub mod prelude;
pub mod refptr;
pub mod traits;
pub mod typedesc;

pub use error::Error;

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
