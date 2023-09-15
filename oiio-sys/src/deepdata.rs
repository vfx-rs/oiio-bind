pub use ffi::*;

#[cxx::bridge(namespace = oiio)]
mod ffi {
    unsafe extern "C++" {
        include!("oiio-sys/include/ffi_deepdata.h");

        pub type DeepData;
    }
}
