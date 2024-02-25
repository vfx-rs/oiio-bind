pub use ffi::*;

#[cxx::bridge(namespace = oiio)]
mod ffi {
    unsafe extern "C++" {
        include!("oiio-sys/src/ffi_imagecache.h");

        pub type ImageCache;
    }
}
