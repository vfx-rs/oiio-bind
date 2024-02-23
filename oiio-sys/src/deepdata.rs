pub use ffi::*;

#[cxx::bridge(namespace = oiio)]
mod ffi {
    unsafe extern "C++" {
        include!("oiio-sys/src/ffi_deepdata.h");

        pub type DeepData;
        type ImageSpec = crate::imageio::ImageSpec;
        type TypeDesc = crate::typedesc::TypeDesc;

        pub fn deepdata_default() -> UniquePtr<DeepData>;

        pub fn deepdata_new_from_spec(spec: &ImageSpec) -> UniquePtr<DeepData>;

        pub fn deepdata_clone(src: &DeepData) -> UniquePtr<DeepData>;

        pub fn deepdata_clone_with_channeltypes(
            src: &DeepData,
            channeltypes: &[TypeDesc],
        ) -> UniquePtr<DeepData>;

        pub fn deepdata_clear(deepdata: Pin<&mut DeepData>);

        pub fn deepdata_free(deepdata: Pin<&mut DeepData>);

        pub fn deepdata_init(
            deepdata: Pin<&mut DeepData>,
            npix: i64,
            nchan: i32,
            channeltypes: &[TypeDesc],
            channelnames: &[String],
        );

        pub fn deepdata_init_from_spec(deepdata: Pin<&mut DeepData>, spec: &ImageSpec);

        pub fn deepdata_initialized(deepdata: &DeepData) -> bool;

        pub fn deepdata_allocated(deepdata: &DeepData) -> bool;

        pub fn deepdata_pixels(deepdata: &DeepData) -> i64;

        pub fn deepdata_channels(deepdata: &DeepData) -> i32;

        pub fn deepdata_z_channel(deepdata: &DeepData) -> i32;

        pub fn deepdata_z_back_channel(deepdata: &DeepData) -> i32;

        pub fn deepdata_a_channel(deepdata: &DeepData) -> i32;

        pub fn deepdata_ar_channel(deepdata: &DeepData) -> i32;

        pub fn deepdata_ag_channel(deepdata: &DeepData) -> i32;

        pub fn deepdata_ab_channel(deepdata: &DeepData) -> i32;

        pub fn deepdata_channelname(deepdata: &DeepData, c: i32) -> &str;

        pub fn deepdata_channeltype(deepdata: &DeepData, c: i32) -> TypeDesc;

        pub fn deepdata_channelsize(deepdata: &DeepData, c: i32) -> usize;

        pub fn deepdata_samplesize(deepdata: &DeepData) -> usize;

        pub fn deepdata_same_channeltypes(deepdata: &DeepData, other: &DeepData) -> bool;

        pub fn deepdata_samples(deepdata: &DeepData, pixel: i64) -> i32;

        pub fn deepdata_set_samples(deepdata: Pin<&mut DeepData>, pixel: i64, samps: i32);

        pub fn deepdata_set_all_samples(deepdata: Pin<&mut DeepData>, samples: &[u32]);

        pub fn deepdata_set_capacity(deepdata: Pin<&mut DeepData>, pixel: i64, samps: i32);

        pub fn deepdata_capacity(deepdata: &DeepData, pixel: i64) -> i32;

        pub fn deepdata_insert_samples(
            deepdata: Pin<&mut DeepData>,
            pixel: i64,
            samplepos: i32,
            n: i32,
        );

        pub fn deepdata_erase_samples(
            deepdata: Pin<&mut DeepData>,
            pixel: i64,
            samplepos: i32,
            n: i32,
        );

        pub fn deepdata_deep_value(
            deepdata: &DeepData,
            pixel: i64,
            channel: i32,
            sample: i32,
        ) -> f32;

        pub fn deepdata_deep_value_uint(
            deepdata: &DeepData,
            pixel: i64,
            channel: i32,
            sample: i32,
        ) -> u32;

        pub fn deepdata_set_deep_value(
            deepdata: Pin<&mut DeepData>,
            pixel: i64,
            channel: i32,
            sample: i32,
            value: f32,
        );

        pub fn deepdata_set_deep_value_uint(
            deepdata: Pin<&mut DeepData>,
            pixel: i64,
            channel: i32,
            sample: i32,
            value: u32,
        );

        pub fn deepdata_mut_data_ptr(
            deepdata: Pin<&mut DeepData>,
            pixel: i64,
            channel: i32,
            sample: i32,
        ) -> *mut u8;

        pub fn deepdata_data_ptr(
            deepdata: &DeepData,
            pixel: i64,
            channel: i32,
            sample: i32,
        ) -> *const u8;

        pub fn deepdata_all_channeltypes(deepdata: &DeepData) -> &[TypeDesc];

        pub fn deepdata_all_samples(deepdata: &DeepData) -> &[u32];

        pub fn deepdata_all_data(deepdata: &DeepData) -> &[c_char];

        pub fn deepdata_get_pointers(deepdata: &DeepData, pointers: &mut [*mut u8]);

        pub fn deepdata_copy_deep_sample(
            deepdata: Pin<&mut DeepData>,
            pixel: i64,
            sample: i32,
            src: &DeepData,
            srcpixel: i64,
            srcsample: i32,
        ) -> bool;

        pub fn deepdata_copy_deep_pixel(
            deepdata: Pin<&mut DeepData>,
            pixel: i64,
            src: &DeepData,
            srcpixel: i64,
        ) -> bool;

        pub fn deepdata_split(deepdata: Pin<&mut DeepData>, pixel: i64, depth: f32) -> bool;

        pub fn deepdata_sort(deepdata: Pin<&mut DeepData>, pixel: i64);

        pub fn deepdata_merge_overlaps(deepdata: Pin<&mut DeepData>, pixel: i64);

        pub fn deepdata_merge_deep_pixels(
            deepdata: Pin<&mut DeepData>,
            pixel: i64,
            src: &DeepData,
            srcpixel: i32,
        );

        pub fn deepdata_opaque_z(deepdata: &DeepData, pixel: i64) -> f32;

        pub fn deepdata_occlusion_cull(deepdata: Pin<&mut DeepData>, pixel: i64);
    }
}
