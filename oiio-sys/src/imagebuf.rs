pub use ffi::*;

pub enum IBStorage {
    UNINITIALIZED,
    LOCALBUFFER,
    APPBUFFER,
    IMAGECACHE,
}

unsafe impl cxx::ExternType for IBStorage {
    type Id = cxx::type_id!("oiio::IBStorage");
    type Kind = cxx::kind::Trivial;
}

pub enum WrapMode {
    WrapDefault,
    WrapBlack,
    WrapClamp,
    WrapPeriodic,
    WrapMirror,
    _WrapLast,
}

unsafe impl cxx::ExternType for WrapMode {
    type Id = cxx::type_id!("oiio::WrapMode");
    type Kind = cxx::kind::Trivial;
}

pub enum InitializePixels {
    No = 0,
    Yes = 1,
}

unsafe impl cxx::ExternType for InitializePixels {
    type Id = cxx::type_id!("oiio::InitializePixels");
    type Kind = cxx::kind::Trivial;
}

#[cxx::bridge(namespace = oiio)]
mod ffi {
    unsafe extern "C++" {
        include!("oiio-sys/src/ffi_imagebuf.h");

        pub type ImageBuf;
        pub type ImageBufIteratorBase;
        pub type DeepData = crate::imageio::DeepData;
        pub type IBStorage = crate::imagebuf::IBStorage;
        pub type ImageCache = crate::imagecache::ImageCache;
        pub type ImageOutput = crate::imageio::ImageOutput;
        pub type ImageSpec = crate::imageio::ImageSpec;
        pub type InitializePixels = crate::imagebuf::InitializePixels;
        pub type IOProxy = crate::filesystem::IOProxy;
        pub type ROI = crate::imageio::ROI;
        pub type TypeDesc = crate::typedesc::TypeDesc;
        pub type WrapMode = crate::imagebuf::WrapMode;

        // ImageBuf
        pub fn imagebuf_default() -> UniquePtr<ImageBuf>;

        pub unsafe fn imagebuf_new_from_file(
            name: &str,
            subimage: i32,
            miplevel: i32,
            imagecache: *mut ImageCache,
            config: *const ImageSpec,
            ioproxy: *mut IOProxy,
        ) -> UniquePtr<ImageBuf>;

        pub fn imagebuf_new_from_spec(
            spec: &ImageSpec,
            zero: InitializePixels,
        ) -> UniquePtr<ImageBuf>;

        pub unsafe fn imagebuf_new_from_buffer(
            spec: &ImageSpec,
            buffer: *mut u8,
            xstride: i64,
            ystride: i64,
            zstride: i64,
        ) -> UniquePtr<ImageBuf>;

        pub fn imagebuf_clone(imagebuf: &ImageBuf) -> UniquePtr<ImageBuf>;

        pub fn imagebuf_reset(imagebuf: Pin<&mut ImageBuf>);

        pub unsafe fn imagebuf_reset_from_file(
            imagebuf: Pin<&mut ImageBuf>,
            name: &str,
            subimage: i32,
            miplevel: i32,
            imagecache: *mut ImageCache,
            config: *const ImageSpec,
            ioproxy: *mut IOProxy,
        );

        pub fn imagebuf_reset_from_spec(
            imagebuf: Pin<&mut ImageBuf>,
            spec: &ImageSpec,
            zero: InitializePixels,
        );

        pub unsafe fn imagebuf_reset_from_buffer(
            imagebuf: Pin<&mut ImageBuf>,
            spec: &ImageSpec,
            buffer: *mut u8,
            xstride: i64,
            ystride: i64,
            zstride: i64,
        );

        pub fn imagebuf_make_writeable(imagebuf: Pin<&mut ImageBuf>, keep_cache_type: bool)
            -> bool;

        pub fn imagebuf_read(
            imagebuf: Pin<&mut ImageBuf>,
            subimage: i32,
            miplevel: i32,
            force: bool,
            convert: TypeDesc,
        ) -> bool;

        pub fn imagebuf_read_subset(
            imagebuf: Pin<&mut ImageBuf>,
            subimage: i32,
            miplevel: i32,
            chbegin: i32,
            chend: i32,
            force: bool,
            convert: TypeDesc,
        ) -> bool;

        pub fn imagebuf_init_spec(
            imagebuf: Pin<&mut ImageBuf>,
            filename: &str,
            subimage: i32,
            miplevel: i32,
        ) -> bool;

        pub fn imagebuf_write(
            imagebuf: Pin<&mut ImageBuf>,
            filename: &str,
            dtype: TypeDesc,
            fileformat: &str,
        ) -> bool;

        pub fn imagebuf_set_write_format(imagebuf: Pin<&mut ImageBuf>, format: TypeDesc);

        pub fn imagebuf_set_write_format_from_channel_names(
            imagebuf: Pin<&mut ImageBuf>,
            format: &[TypeDesc],
        );

        pub fn imagebuf_set_write_tiles(
            imagebuf: Pin<&mut ImageBuf>,
            width: i32,
            height: i32,
            depth: i32,
        );

        pub unsafe fn imagebuf_set_write_ioproxy(
            imagebuf: Pin<&mut ImageBuf>,
            ioproxy: *mut IOProxy,
        );

        pub unsafe fn imagebuf_write_to_imageoutput(
            imagebuf: Pin<&mut ImageBuf>,
            out: *mut ImageOutput,
        ) -> bool;

        pub fn imagebuf_copy_metadata(imagebuf: Pin<&mut ImageBuf>, src: &ImageBuf);

        pub fn imagebuf_copy_pixels(imagebuf: Pin<&mut ImageBuf>, src: &ImageBuf) -> bool;

        pub fn imagebuf_copy(
            imagebuf: Pin<&mut ImageBuf>,
            src: &ImageBuf,
            format: TypeDesc,
        ) -> bool;

        pub fn imagebuf_copy_to_imagebuf(
            imagebuf: &ImageBuf,
            format: TypeDesc,
        ) -> UniquePtr<ImageBuf>;

        pub fn imagebuf_swap(imagebuf: Pin<&mut ImageBuf>, other: Pin<&mut ImageBuf>);

        pub fn imagebuf_getchannel(
            imagebuf: &ImageBuf,
            x: i32,
            y: i32,
            z: i32,
            c: i32,
            wrap: WrapMode,
        ) -> f32;

        pub unsafe fn imagebuf_getpixel(
            imagebuf: &ImageBuf,
            x: i32,
            y: i32,
            z: i32,
            pixel: *mut f32,
            maxchannels: i32,
            wrap: WrapMode,
        );

        pub unsafe fn imagebuf_interppixel(
            imagebuf: &ImageBuf,
            x: f32,
            y: f32,
            pixel: *mut f32,
            wrap: WrapMode,
        );

        pub unsafe fn imagebuf_interppixel_NDC(
            imagebuf: &ImageBuf,
            s: f32,
            t: f32,
            pixel: *mut f32,
            wrap: WrapMode,
        );

        pub unsafe fn imagebuf_interppixel_bicubic(
            imagebuf: &ImageBuf,
            x: f32,
            y: f32,
            pixel: *mut f32,
            wrap: WrapMode,
        );

        pub unsafe fn imagebuf_interppixel_bicubic_NDC(
            imagebuf: &ImageBuf,
            s: f32,
            t: f32,
            pixel: *mut f32,
            wrap: WrapMode,
        );

        pub fn imagebuf_setpixel(
            imagebuf: Pin<&mut ImageBuf>,
            x: i32,
            y: i32,
            z: i32,
            pixel: &[f32],
        );

        pub fn imagebuf_setpixel_i(imagebuf: Pin<&mut ImageBuf>, i: i32, pixel: &[f32]);

        pub unsafe fn imagebuf_setpixel_with_coordinates(
            imagebuf: Pin<&mut ImageBuf>,
            x: i32,
            y: i32,
            z: i32,
            pixel: *const f32,
            maxchannels: i32,
        );

        pub unsafe fn imagebuf_get_pixels(
            imagebuf: &ImageBuf,
            roi: ROI,
            format: TypeDesc,
            result: *mut u8,
            xstride: i64,
            ystride: i64,
            zstride: i64,
        ) -> bool;

        pub unsafe fn imagebuf_set_pixels(
            imagebuf: Pin<&mut ImageBuf>,
            roi: ROI,
            format: TypeDesc,
            data: *const u8,
            xstride: i64,
            ystride: i64,
            zstride: i64,
        ) -> bool;

        pub fn imagebuf_initialized(imagebuf: &ImageBuf) -> bool;

        pub fn imagebuf_storage(imagebuf: &ImageBuf) -> IBStorage;

        pub fn imagebuf_spec(imagebuf: &ImageBuf) -> &ImageSpec;

        pub fn imagebuf_specmod(imagebuf: Pin<&mut ImageBuf>) -> Pin<&mut ImageSpec>;

        pub fn imagebuf_nativespec(imagebuf: &ImageBuf) -> &ImageSpec;

        pub fn imagebuf_has_thumbnail(imagebuf: &ImageBuf) -> bool;

        pub fn imagebuf_get_thumbnail(imagebuf: &ImageBuf) -> SharedPtr<ImageBuf>;

        pub fn imagebuf_set_thumbnail(imagebuf: Pin<&mut ImageBuf>, thumb: &ImageBuf);

        pub fn imagebuf_clear_thumbnail(imagebuf: Pin<&mut ImageBuf>);

        pub fn imagebuf_name(imagebuf: &ImageBuf) -> &str;

        pub fn imagebuf_file_format_name(imagebuf: &ImageBuf) -> &str;

        pub fn imagebuf_subimage(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_nsubimages(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_miplevel(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_nmiplevels(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_nchannels(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_xbegin(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_ybegin(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_zbegin(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_xend(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_yend(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_zend(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_xmin(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_ymin(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_zmin(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_xmax(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_ymax(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_zmax(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_orientation(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_set_orientation(imagebuf: Pin<&mut ImageBuf>, orient: i32);

        pub fn imagebuf_oriented_width(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_oriented_height(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_oriented_x(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_oriented_y(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_oriented_full_width(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_oriented_full_height(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_oriented_full_x(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_oriented_full_y(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_set_origin(imagebuf: Pin<&mut ImageBuf>, x: i32, y: i32, z: i32);

        pub fn imagebuf_set_full(
            imagebuf: Pin<&mut ImageBuf>,
            xbegin: i32,
            xend: i32,
            ybegin: i32,
            yend: i32,
            zbegin: i32,
            zend: i32,
        );

        pub fn imagebuf_roi(imagebuf: &ImageBuf) -> ROI;

        pub fn imagebuf_roi_full(imagebuf: &ImageBuf) -> ROI;

        pub fn imagebuf_set_roi_full(imagebuf: Pin<&mut ImageBuf>, newroi: &ROI);

        pub fn imagebuf_contains_roi(imagebuf: &ImageBuf, roi: ROI) -> bool;

        pub fn imagebuf_pixels_valid(imagebuf: &ImageBuf) -> bool;

        pub fn imagebuf_pixeltype(imagebuf: &ImageBuf) -> TypeDesc;

        pub unsafe fn imagebuf_localpixels_mut(imagebuf: Pin<&mut ImageBuf>) -> *mut u8;

        pub unsafe fn imagebuf_localpixels(imagebuf: &ImageBuf) -> *const u8;

        pub fn imagebuf_pixel_stride(imagebuf: &ImageBuf) -> i64;

        pub fn imagebuf_scanline_stride(imagebuf: &ImageBuf) -> i64;

        pub fn imagebuf_z_stride(imagebuf: &ImageBuf) -> i64;

        pub fn imagebuf_contiguous(imagebuf: &ImageBuf) -> bool;

        pub fn imagebuf_cachedpixels(imagebuf: &ImageBuf) -> bool;

        pub unsafe fn imagebuf_imagecache(imagebuf: &ImageBuf) -> *mut ImageCache;

        pub unsafe fn imagebuf_pixeladdr(
            imagebuf: &ImageBuf,
            x: i32,
            y: i32,
            z: i32,
            ch: i32,
        ) -> *const u8;

        pub unsafe fn imagebuf_pixeladdr_mut(
            imagebuf: &ImageBuf,
            x: i32,
            y: i32,
            z: i32,
            ch: i32,
        ) -> *mut u8;

        pub fn imagebuf_pixelindex(
            imagebuf: &ImageBuf,
            x: i32,
            y: i32,
            z: i32,
            check_range: bool,
        ) -> i32;

        pub fn imagebuf_set_threads(imagebuf: &ImageBuf, n: i32);

        pub fn imagebuf_threads(imagebuf: &ImageBuf) -> i32;

        pub fn imagebuf_error(imagebuf: &ImageBuf, message: &str);

        pub fn imagebuf_has_error(imagebuf: &ImageBuf) -> bool;

        pub fn imagebuf_geterror(imagebuf: &ImageBuf, clear: bool) -> String;

        pub fn imagebuf_deep(imagebuf: &ImageBuf) -> bool;

        pub fn imagebuf_deep_samples(imagebuf: &ImageBuf, x: i32, y: i32, z: i32) -> i32;

        pub unsafe fn imagebuf_deep_pixel_ptr(
            imagebuf: &ImageBuf,
            x: i32,
            y: i32,
            z: i32,
            c: i32,
            s: i32,
        ) -> *const u8;

        pub fn imagebuf_deep_value(
            imagebuf: &ImageBuf,
            x: i32,
            y: i32,
            z: i32,
            c: i32,
            s: i32,
        ) -> f32;

        pub fn imagebuf_deep_value_uint(
            imagebuf: &ImageBuf,
            x: i32,
            y: i32,
            z: i32,
            c: i32,
            s: i32,
        ) -> u32;

        pub fn imagebuf_set_deep_samples(
            imagebuf: Pin<&mut ImageBuf>,
            x: i32,
            y: i32,
            z: i32,
            nsamples: i32,
        );

        pub fn imagebuf_deep_insert_samples(
            imagebuf: Pin<&mut ImageBuf>,
            x: i32,
            y: i32,
            z: i32,
            samplepos: i32,
            nsamples: i32,
        );

        pub fn imagebuf_deep_erase_samples(
            imagebuf: Pin<&mut ImageBuf>,
            x: i32,
            y: i32,
            z: i32,
            samplepos: i32,
            nsamples: i32,
        );

        pub fn imagebuf_set_deep_value(
            imagebuf: Pin<&mut ImageBuf>,
            x: i32,
            y: i32,
            z: i32,
            c: i32,
            s: i32,
            value: f32,
        );

        pub fn imagebuf_set_deep_value_uint(
            imagebuf: Pin<&mut ImageBuf>,
            x: i32,
            y: i32,
            z: i32,
            c: i32,
            s: i32,
            value: u32,
        );

        pub fn imagebuf_copy_deep_pixel(
            imagebuf: Pin<&mut ImageBuf>,
            x: i32,
            y: i32,
            z: i32,
            src: &ImageBuf,
            srcx: i32,
            srcy: i32,
            srcz: i32,
        ) -> bool;

        pub unsafe fn imagebuf_deepdata_mut(imagebuf: Pin<&mut ImageBuf>) -> *mut DeepData;

        pub unsafe fn imagebuf_deepdata(imagebuf: &ImageBuf) -> *const DeepData;

        pub fn imagebuf_lock(imagebuf: &ImageBuf);

        pub fn imagebuf_unlock(imagebuf: &ImageBuf);

        pub fn wrapmode_from_string(name: &str) -> WrapMode;

        // ImageBuf::IteratorBase
        pub fn imagebuf_iterator_x(iterator: &ImageBufIteratorBase) -> i32;

        pub fn imagebuf_iterator_y(iterator: &ImageBufIteratorBase) -> i32;

        pub fn imagebuf_iterator_z(iterator: &ImageBufIteratorBase) -> i32;

        pub fn imagebuf_iterator_valid(iterator: &ImageBufIteratorBase) -> bool;

        pub fn imagebuf_iterator_valid_coordianates(
            iterator: &ImageBufIteratorBase,
            x: i32,
            y: i32,
            z: i32,
        ) -> bool;

        pub fn imagebuf_iterator_exists(iterator: &ImageBufIteratorBase) -> bool;

        pub fn imagebuf_iterator_done(iterator: &ImageBufIteratorBase) -> bool;

        pub fn imagebuf_iterator_deep_samples(iterator: &ImageBufIteratorBase) -> i32;

        pub fn imagebuf_iterator_wrap(iterator: &ImageBufIteratorBase) -> WrapMode;

        pub fn imagebuf_iterator_pos(
            iterator: Pin<&mut ImageBufIteratorBase>,
            x: i32,
            y: i32,
            z: i32,
        );

        pub fn imagebuf_iterator_next(iterator: Pin<&mut ImageBufIteratorBase>);

        pub fn imagebuf_iterator_range(iterator: &ImageBufIteratorBase) -> ROI;

        pub fn imagebuf_iterator_rerange(
            iterator: Pin<&mut ImageBufIteratorBase>,
            xbegin: i32,
            xend: i32,
            ybegin: i32,
            yend: i32,
            zbegin: i32,
            zend: i32,
            wrap: WrapMode,
        );

        pub unsafe fn imagebuf_iterator_rawptr(iterator: &ImageBufIteratorBase) -> *const u8;

        pub fn imagebuf_iterator_deep_value(iterator: &ImageBufIteratorBase, c: i32, s: i32)
            -> f32;

        pub fn imagebuf_iterator_deep_value_uint(
            iterator: &ImageBufIteratorBase,
            c: i32,
            s: i32,
        ) -> u32;

        pub fn imagebuf_iterator_localpixels(iterator: &ImageBufIteratorBase) -> bool;

        pub fn imagebuf_iterator_has_error(iterator: &ImageBufIteratorBase) -> bool;

        pub fn imagebuf_iterator_clear_error(iterator: Pin<&mut ImageBufIteratorBase>);
    }
}
