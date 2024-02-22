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

pub enum OpenMode {
    Create,
    AppendSubimage,
    AppendMIPLevel,
}

unsafe impl cxx::ExternType for OpenMode {
    type Id = cxx::type_id!("oiio::OpenMode");
    type Kind = cxx::kind::Trivial;
}

#[cxx::bridge(namespace = oiio)]
mod ffi {
    struct ExtensionMapItem {
        key: String,
        value: Vec<String>,
    }

    unsafe extern "C++" {
        include!("oiio-sys/src/ffi_imageio.h");

        type DeepData = crate::deepdata::DeepData;
        type IOProxy = crate::filesystem::IOProxy;
        type ROI = crate::imageio::ROI;
        type TypeDesc = crate::typedesc::TypeDesc;
        type ImageBuf = crate::imagebuf::ImageBuf;

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
        pub fn imageinput_spec(imageinput: &ImageInput) -> &ImageSpec;
        pub fn imageinput_spec_subimage_miplevel(
            imageinput: Pin<&mut ImageInput>,
            subimage: i32,
            miplevel: i32,
        ) -> &ImageSpec;
        pub fn imageinput_spec_dimensions(
            imageinput: Pin<&mut ImageInput>,
            subimage: i32,
            miplevel: i32,
        ) -> &ImageSpec;
        pub fn imageinput_close(imageinput: Pin<&mut ImageInput>) -> bool;
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
            format: TypeDesc,
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
            format: TypeDesc,
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
            format: TypeDesc,
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

        /// Set the IO proxy for this ImageInput.
        /// # Safety
        /// Must be called with a valid ioproxy pointer.
        pub unsafe fn imageinput_set_ioproxy(
            imageinput: Pin<&mut ImageInput>,
            ioproxy: *mut IOProxy,
        ) -> bool;

        pub fn imageinput_has_error(imageinput: &ImageInput) -> bool;

        pub fn imageinput_geterror(imageinput: Pin<&mut ImageInput>) -> String;

        pub fn imageinput_seterror(imageinput: Pin<&mut ImageInput>, message: &str);

        pub fn imageinput_set_threads(imageinput: Pin<&mut ImageInput>, n: i32);

        pub fn imageinput_threads(imageinput: &ImageInput) -> i32;

        // ImageOutput
        type OpenMode = crate::imageio::OpenMode;

        pub type ImageOutput;

        /// Safety: must be called with a valid ioproxy pointer.
        pub unsafe fn imageoutput_create(
            filename: &str,
            ioproxy: *mut IOProxy,
            plugin_searchpath: &str,
        ) -> UniquePtr<ImageOutput>;

        pub fn imageoutput_format_name(imageoutput: &ImageOutput) -> &str;

        pub fn imageoutput_supports(imageoutput: &ImageOutput, feature: &str) -> i32;

        pub fn imageoutput_open(
            imageoutput: Pin<&mut ImageOutput>,
            filename: &str,
            newspec: &ImageSpec,
            mode: OpenMode,
        ) -> bool;

        /// Safety: must be called with a valid specs pointer. The subimages
        /// must be less than or equal to the number of subimages in the specs.
        pub unsafe fn imageoutput_open_multi_subimage(
            imageoutput: Pin<&mut ImageOutput>,
            filename: &str,
            subimages: i32,
            specs: *const ImageSpec,
        ) -> bool;

        pub fn imageoutput_spec(imageoutput: &ImageOutput) -> &ImageSpec;

        pub fn imageoutput_close(imageoutput: Pin<&mut ImageOutput>) -> bool;

        pub fn imageoutput_write_scanline(
            imageoutput: Pin<&mut ImageOutput>,
            y: i32,
            z: i32,
            format: TypeDesc,
            data: &mut [u8],
            xstride: i64,
        ) -> bool;

        pub fn imageoutput_write_scanlines(
            imageoutput: Pin<&mut ImageOutput>,
            ybegin: i32,
            yend: i32,
            z: i32,
            format: TypeDesc,
            data: &mut [u8],
            xstride: i64,
            ystride: i64,
        ) -> bool;

        pub fn imageoutput_write_tile(
            imageoutput: Pin<&mut ImageOutput>,
            x: i32,
            y: i32,
            z: i32,
            format: TypeDesc,
            data: &mut [u8],
            xstride: i64,
            ystride: i64,
            zstride: i64,
        ) -> bool;

        pub fn imageoutput_write_tiles(
            imageoutput: Pin<&mut ImageOutput>,
            xbegin: i32,
            xend: i32,
            ybegin: i32,
            yend: i32,
            zbegin: i32,
            zend: i32,
            format: TypeDesc,
            data: &mut [u8],
            xstride: i64,
            ystride: i64,
            zstride: i64,
        ) -> bool;

        pub fn imageoutput_write_rectangle(
            imageoutput: Pin<&mut ImageOutput>,
            xbegin: i32,
            xend: i32,
            ybegin: i32,
            yend: i32,
            zbegin: i32,
            zend: i32,
            format: TypeDesc,
            data: &mut [u8],
            xstride: i64,
            ystride: i64,
            zstride: i64,
        ) -> bool;

        pub fn imageoutput_write_image(
            imageoutput: Pin<&mut ImageOutput>,
            format: TypeDesc,
            data: &mut [u8],
            xstride: i64,
            ystride: i64,
            zstride: i64,
        ) -> bool;

        pub fn imageoutput_write_deep_scanlines(
            imageoutput: Pin<&mut ImageOutput>,
            ybegin: i32,
            yend: i32,
            z: i32,
            data: &DeepData,
        ) -> bool;

        pub fn imageoutput_write_deep_tiles(
            imageoutput: Pin<&mut ImageOutput>,
            xbegin: i32,
            xend: i32,
            ybegin: i32,
            yend: i32,
            zbegin: i32,
            zend: i32,
            data: &DeepData,
        ) -> bool;

        pub fn imageoutput_write_deep_image(
            imageoutput: Pin<&mut ImageOutput>,
            data: &DeepData,
        ) -> bool;

        pub fn imageoutput_set_thumbnail(
            imageoutput: Pin<&mut ImageOutput>,
            thumb: &ImageBuf,
        ) -> bool;

        pub unsafe fn imageoutput_copy_image(
            imageoutput: Pin<&mut ImageOutput>,
            imageinput: *mut ImageInput,
        ) -> bool;

        pub unsafe fn imageoutput_set_ioproxy(
            imageoutput: Pin<&mut ImageOutput>,
            ioproxy: *mut IOProxy,
        ) -> bool;

        pub fn imageoutput_has_error(imageoutput: &ImageOutput) -> bool;

        pub fn imageoutput_geterror(imageoutput: &ImageOutput, clear: bool) -> String;

        pub fn imageoutput_seterror(imageoutput: Pin<&mut ImageOutput>, message: &str);

        pub fn imageoutput_set_threads(imageoutput: Pin<&mut ImageOutput>, n: i32);

        pub fn imageoutput_threads(imageoutput: &ImageOutput) -> i32;

        pub fn shutdown();

        pub fn openimageio_version() -> i32;

        pub fn has_error() -> bool;

        pub fn get_error(clear: bool) -> String;

        pub fn attribute(name: &str, type_: TypeDesc, value: &mut [u8]) -> bool;

        pub fn attribute_float(name: &str, value: f32) -> bool;

        pub fn attribute_int(name: &str, value: i32) -> bool;

        pub fn getattribute(name: &str, type_: TypeDesc, value: &mut [u8]) -> bool;

        pub fn getattribute_int(name: &str, value: &mut i32) -> bool;

        pub fn getattribute_float(name: &str, value: &mut f32) -> bool;

        pub fn getattribute_string(name: &str, value: &mut String) -> bool;

        pub fn get_int_attribute(name: &str, defaultval: i32) -> i32;

        pub fn get_float_attribute(name: &str, defaultval: f32) -> f32;

        pub fn get_string_attribute(name: &str, defaultval: &str) -> String;

        // pub unsafe fn declare_imageio_format(
        //     name: &str,
        //     input_creator: fn() -> *mut ImageInput,
        //     input_extensions: &[&str],
        //     output_creator: fn() -> *mut ImageOutput,
        //     output_extensions: &[&str],
        //     lib_version: &str,
        // );

        pub fn is_imageio_format_name(name: &str) -> bool;

        pub fn get_extension_map() -> Vec<ExtensionMapItem>;

        pub fn convert_pixel_values(
            src_type: TypeDesc,
            src: &[u8],
            dst_type: TypeDesc,
            dst: &mut [u8],
        ) -> bool;

        pub fn convert_image(
            nchannels: i32,
            width: i32,
            height: i32,
            depth: i32,
            src: &[u8],
            src_type: TypeDesc,
            src_xstride: i64,
            src_ystride: i64,
            src_zstride: i64,
            dst: &mut [u8],
            dst_type: TypeDesc,
            dst_xstride: i64,
            dst_ystride: i64,
            dst_zstride: i64,
        ) -> bool;

        pub fn parallel_convert_image(
            nchannels: i32,
            width: i32,
            height: i32,
            depth: i32,
            src: &[u8],
            src_type: TypeDesc,
            src_xstride: i64,
            src_ystride: i64,
            src_zstride: i64,
            dst: &mut [u8],
            dst_type: TypeDesc,
            dst_xstride: i64,
            dst_ystride: i64,
            dst_zstride: i64,
            nthreads: i32,
        ) -> bool;

        pub unsafe fn add_dither(
            nchannels: i32,
            width: i32,
            height: i32,
            depth: i32,
            data: *mut f32,
            xstride: i64,
            ystride: i64,
            zstride: i64,
            ditheramplitude: f32,
            alpha_channel: i32,
            z_channel: i32,
            ditherseed: u32,
            chorigin: i32,
            xorigin: i32,
            yorigin: i32,
            zorigin: i32,
        );

        pub fn premult(
            nchannels: i32,
            width: i32,
            height: i32,
            depth: i32,
            chbegin: i32,
            chend: i32,
            datatype: TypeDesc,
            data: &mut [u8],
            xstride: i64,
            ystride: i64,
            zstride: i64,
            alpha_channel: i32,
            z_channel: i32,
        );

        pub fn copy_image(
            nchannels: i32,
            width: i32,
            height: i32,
            depth: i32,
            src: &[u8],
            pixelsize: i64,
            src_xstride: i64,
            src_ystride: i64,
            src_zstride: i64,
            dst: &mut [u8],
            dst_xstride: i64,
            dst_ystride: i64,
            dst_zstride: i64,
        ) -> bool;

        pub fn wrap_black(coord: &mut i32, origin: i32, width: i32) -> bool;

        pub fn wrap_clamp(coord: &mut i32, origin: i32, width: i32) -> bool;

        pub fn wrap_periodic(coord: &mut i32, origin: i32, width: i32) -> bool;

        pub fn wrap_periodic_pow2(coord: &mut i32, origin: i32, width: i32) -> bool;

        pub fn wrap_mirror(coord: &mut i32, origin: i32, width: i32) -> bool;

        pub fn debug(message: &str);
    }
}
