/// imageio tests
use anyhow::Result;

/// oiio_sys::imageio tests for basic functionality
#[test]
fn test_imageinput_open_without_config() -> Result<()> {
    assert!(!oiio_sys::imageio::has_error()); // Initial state must contains no errors.

    let bad_filename = "tests/images/does-not-exist.png";
    let imageio = oiio_sys::imageio::imageinput_open_without_config(bad_filename)?;
    assert!(imageio.is_null());
    assert!(oiio_sys::imageio::has_error());

    println!("error: {}", oiio_sys::imageio::get_error(true)); // Clear and print the error.
    assert!(!oiio_sys::imageio::has_error()); // State must be error-free after get_error(true).

    let filename = "tests/images/test16.png";
    let imageio = oiio_sys::imageio::imageinput_open_without_config(filename)?;
    assert!(!imageio.is_null());

    Ok(())
}
