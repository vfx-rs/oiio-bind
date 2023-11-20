pub use ffi::*;

// ROI
pub struct ROI {
    pub xbegin: i32,
    pub xend: i32,
    pub ybegin: i32,
    pub yend: i32,
    pub zbegin: i32,
    pub zend: i32,
    pub chbegin: i32,
    pub chend: i32,
}

unsafe impl cxx::ExternType for ROI {
    type Id = cxx::type_id!("oiio::ROI");
    type Kind = cxx::kind::Trivial;
}

#[cxx::bridge(namespace = oiio)]
mod ffi {
    unsafe extern "C++" {
        include!("oiio-sys/src/ffi_imageio.h");

        type DeepData = crate::deepdata::DeepData;
        type IOProxy = crate::filesystem::IOProxy;
        type ROI = crate::imageio::ROI;
        type TypeDesc = crate::typedesc::TypeDesc;

        /// Utility
        pub fn has_error() -> bool;
        pub fn get_error(clear: bool) -> String;

        // ROI
        pub fn roi_default() -> ROI;
        #[allow(clippy::too_many_arguments)]
        pub fn roi_new(
            xbegin: i32,
            xend: i32,
            ybegin: i32,
            yend: i32,
            zbegin: i32,
            zend: i32,
            chbegin: i32,
            chend: i32,
        ) -> ROI;
        pub fn roi_new_all() -> ROI;
        pub fn roi_defined(rpo: &ROI) -> bool;
        pub fn roi_width(rpo: &ROI) -> i32;
        pub fn roi_height(rpo: &ROI) -> i32;
        pub fn roi_depth(rpo: &ROI) -> i32;
        pub fn roi_nchannels(rpo: &ROI) -> i32;
        pub fn roi_npixels(rpo: &ROI) -> u64;
        pub fn roi_eq_roi(rpo: &ROI, other: &ROI) -> bool;
        pub fn roi_ne_roi(rpo: &ROI, other: &ROI) -> bool;
        pub fn roi_contains(rpo: &ROI, x: i32, y: i32, z: i32, ch: i32) -> bool;
        pub fn roi_contains_roi(rpo: &ROI, other: &ROI) -> bool;
        pub fn roi_union(rpo: &ROI, other: &ROI) -> ROI;
        pub fn roi_intersection(rpo: &ROI, other: &ROI) -> ROI;

        // ImageSpec
        pub type ImageSpec;

        pub fn imagespec_from_resolution(xres: i32, yres: i32, nchans: i32)
            -> UniquePtr<ImageSpec>;
        pub fn imagespec_x(spec: &ImageSpec) -> i32;
        pub fn imagespec_y(spec: &ImageSpec) -> i32;
        pub fn imagespec_z(spec: &ImageSpec) -> i32;
        pub fn imagespec_width(spec: &ImageSpec) -> i32;
        pub fn imagespec_height(spec: &ImageSpec) -> i32;
        pub fn imagespec_depth(spec: &ImageSpec) -> i32;
        pub fn imagespec_full_x(spec: &ImageSpec) -> i32;
        pub fn imagespec_full_y(spec: &ImageSpec) -> i32;
        pub fn imagespec_full_z(spec: &ImageSpec) -> i32;
        pub fn imagespec_full_width(spec: &ImageSpec) -> i32;
        pub fn imagespec_full_height(spec: &ImageSpec) -> i32;
        pub fn imagespec_full_depth(spec: &ImageSpec) -> i32;
        pub fn imagespec_tile_width(spec: &ImageSpec) -> i32;
        pub fn imagespec_tile_height(spec: &ImageSpec) -> i32;
        pub fn imagespec_tile_depth(spec: &ImageSpec) -> i32;
        pub fn imagespec_nchannels(spec: &ImageSpec) -> i32;
        pub fn imagespec_alpha_channel(spec: &ImageSpec) -> i32;
        pub fn imagespec_z_channel(spec: &ImageSpec) -> i32;
        pub fn imagespec_deep(spec: &ImageSpec) -> bool;
        pub fn imagespec_channel_names(spec: &ImageSpec) -> UniquePtr<CxxVector<CxxString>>;

        // ImageInput
        pub type ImageInput;

        pub fn imageinput_open_with_config(
            filename: &str,
            config: &ImageSpec,
        ) -> Result<UniquePtr<ImageInput>>;
        pub fn imageinput_open_without_config(filename: &str) -> Result<UniquePtr<ImageInput>>;
        pub fn imageinput_open_newspec_with_config(
            imageinput: Pin<&mut ImageInput>,
            filename: &str,
            config: &ImageSpec,
        ) -> Result<UniquePtr<ImageSpec>>;
        pub fn imageinput_open_newspec_without_config(
            imageinput: Pin<&mut ImageInput>,
            filename: &str,
        ) -> Result<UniquePtr<ImageSpec>>;
        pub fn imageinput_create_with_config(
            filename: &str,
            do_open: bool,
            config: &ImageSpec,
            plugin_searchpath: &str,
        ) -> Result<UniquePtr<ImageInput>>;
        pub fn imageinput_create_without_config(
            filename: &str,
            do_open: bool,
            plugin_searchpath: &str,
        ) -> Result<UniquePtr<ImageInput>>;
        pub fn imageinput_format_name(imageinput: &ImageInput) -> &str;
        pub fn imageinput_supports(imageinput: &ImageInput, feature: &str) -> bool;
        pub fn imageinput_valid_file(imageinput: &ImageInput, filename: &str) -> bool;
        pub fn imageinput_geterror(imageinput: Pin<&mut ImageInput>) -> String;
        pub fn imageinput_spec(imageinput: &ImageInput) -> UniquePtr<ImageSpec>;
        pub fn imageinput_spec_subimage_miplevel(
            imageinput: Pin<&mut ImageInput>,
            subimage: i32,
            miplevel: i32,
        ) -> UniquePtr<ImageSpec>;
        pub fn imageinput_spec_dimensions(
            imageinput: Pin<&mut ImageInput>,
            subimage: i32,
            miplevel: i32,
        ) -> UniquePtr<ImageSpec>;
        pub fn imageinput_close(imageinput: Pin<&mut ImageInput>) -> Result<()>;
        pub fn imageinput_current_subimage(imageinput: &ImageInput) -> i32;
        pub fn imageinput_current_miplevel(imageinput: &ImageInput) -> i32;
        pub fn imageinput_seek_subimage(
            imageinput: Pin<&mut ImageInput>,
            subimage: i32,
            miplevel: i32,
        ) -> bool;
        pub fn imageinput_read_scanline(
            imageinput: Pin<&mut ImageInput>,
            y: i32,
            z: i32,
            format: &TypeDesc,
            data: &mut [u8],
            xstride: i64,
        ) -> bool;
        #[allow(clippy::too_many_arguments)]
        pub fn imageinput_read_scanlines(
            imageinput: Pin<&mut ImageInput>,
            subimage: i32,
            miplevel: i32,
            ybegin: i32,
            yend: i32,
            z: i32,
            chbegin: i32,
            chend: i32,
            format: &TypeDesc,
            data: &mut [u8],
            xstride: i64,
            ystride: i64,
        ) -> bool;
        #[allow(clippy::too_many_arguments)]
        pub fn imageinput_read_image(
            imageinput: Pin<&mut ImageInput>,
            subimage: i32,
            miplevel: i32,
            chbegin: i32,
            chend: i32,
            format: &TypeDesc,
            data: &mut [u8],
            xstride: i64,
            ystride: i64,
            zstride: i64,
        ) -> bool;
        #[allow(clippy::too_many_arguments)]
        pub fn imageinput_read_native_deep_scanlines(
            imageinput: Pin<&mut ImageInput>,
            subimage: i32,
            miplevel: i32,
            ybegin: i32,
            yend: i32,
            z: i32,
            chbegin: i32,
            chend: i32,
            data: Pin<&mut DeepData>,
        ) -> bool;
        #[allow(clippy::too_many_arguments)]
        pub fn imageinput_read_native_deep_tiles(
            imageinput: Pin<&mut ImageInput>,
            subimage: i32,
            miplevel: i32,
            xbegin: i32,
            xend: i32,
            ybegin: i32,
            yend: i32,
            zbegin: i32,
            zend: i32,
            chbegin: i32,
            chend: i32,
            data: Pin<&mut DeepData>,
        ) -> bool;
        pub fn imageinput_read_native_deep_image(
            imageinput: Pin<&mut ImageInput>,
            subimage: i32,
            miplevel: i32,
            data: Pin<&mut DeepData>,
        ) -> bool;
        pub fn imageinput_read_native_scanline(
            imageinput: Pin<&mut ImageInput>,
            subimage: i32,
            miplevel: i32,
            y: i32,
            z: i32,
            data: &mut [u8],
        ) -> bool;

        #[allow(clippy::too_many_arguments)]
        pub fn imageinput_read_native_scanlines(
            imageinput: Pin<&mut ImageInput>,
            subimage: i32,
            miplevel: i32,
            ybegin: i32,
            yend: i32,
            z: i32,
            chbegin: i32,
            chend: i32,
            data: &mut [u8],
        ) -> bool;

        pub fn imageinput_read_native_tile(
            imageinput: Pin<&mut ImageInput>,
            subimage: i32,
            miplevel: i32,
            x: i32,
            y: i32,
            z: i32,
            data: &mut [u8],
        ) -> bool;

        #[allow(clippy::too_many_arguments)]
        pub fn imageinput_read_native_tiles(
            imageinput: Pin<&mut ImageInput>,
            xbegin: i32,
            xend: i32,
            ybegin: i32,
            yend: i32,
            zbegin: i32,
            zend: i32,
            chbegin: i32,
            chend: i32,
            data: &mut [u8],
        ) -> bool;

        /// Safety: must be called with a valid ioproxy pointer.
        pub unsafe fn imageinput_set_ioproxy(
            imageinput: Pin<&mut ImageInput>,
            ioproxy: *mut IOProxy,
        ) -> bool;

        pub fn imageinput_has_error(imageinput: &ImageInput) -> bool;

        pub fn imageinput_set_threads(imageinput: Pin<&mut ImageInput>, n: i32);

        pub fn imageinput_threads(imageinput: &ImageInput) -> i32;
    }
}
