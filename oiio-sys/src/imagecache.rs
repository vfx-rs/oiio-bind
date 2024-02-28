pub use ffi::*;

#[cxx::bridge(namespace = oiio)]
mod ffi {
    unsafe extern "C++" {
        include!("oiio-sys/src/ffi_imagecache.h");

        pub type ImageCache;
        pub type ImageHandle;
        pub type Perthread;
        pub type TextureOpt;
        pub type Tile;
        pub type ImageBuf = crate::imageio::ImageBuf;
        pub type ImageSpec = crate::imageio::ImageSpec;
        pub type ROI = crate::imageio::ROI;
        pub type TypeDesc = crate::typedesc::TypeDesc;

        pub unsafe fn imagecache_create(shared: bool) -> *mut ImageCache;

        pub unsafe fn imagecache_destroy(imagecache: *mut ImageCache, teardown: bool);

        pub unsafe fn imagecache_attribute(
            imagecache: Pin<&mut ImageCache>,
            name: &str,
            type_: TypeDesc,
            val: *const u8,
        ) -> bool;

        pub unsafe fn imagecache_attribute_int(
            imagecache: Pin<&mut ImageCache>,
            name: &str,
            val: i32,
        ) -> bool;

        pub fn imagecache_attribute_float(
            imagecache: Pin<&mut ImageCache>,
            name: &str,
            val: f32,
        ) -> bool;

        pub fn imagecache_attribute_double(
            imagecache: Pin<&mut ImageCache>,
            name: &str,
            val: f64,
        ) -> bool;

        pub fn imagecache_attribute_str(
            imagecache: Pin<&mut ImageCache>,
            name: &str,
            val: &str,
        ) -> bool;

        pub unsafe fn imagecache_getattribute(
            imagecache: Pin<&mut ImageCache>,
            name: &str,
            type_: TypeDesc,
            val: *const u8,
        ) -> bool;

        pub fn imagecache_getattribute_int(
            imagecache: Pin<&mut ImageCache>,
            name: &str,
            val: &mut i32,
        ) -> bool;

        pub fn imagecache_getattribute_float(
            imagecache: Pin<&mut ImageCache>,
            name: &str,
            val: &mut f32,
        ) -> bool;

        pub fn imagecache_getattribute_double(
            imagecache: Pin<&mut ImageCache>,
            name: &str,
            val: &mut f64,
        ) -> bool;

        pub fn imagecache_getattribute_string(
            imagecache: Pin<&mut ImageCache>,
            name: &str,
            val: Pin<&mut CxxString>,
        ) -> bool;

        pub fn imagecache_getattributetype(
            imagecache: Pin<&mut ImageCache>,
            name: &str,
        ) -> TypeDesc;

        pub unsafe fn imagecache_get_perthread_info(
            imagecache: Pin<&mut ImageCache>,
            thread_info: *mut Perthread,
        ) -> *mut Perthread;

        pub unsafe fn imagecache_create_thread_info(
            imagecache: Pin<&mut ImageCache>,
        ) -> *mut Perthread;

        pub unsafe fn imagecache_destroy_thread_info(
            imagecache: Pin<&mut ImageCache>,
            thread_info: *mut Perthread,
        );

        pub unsafe fn imagecache_get_image_handle(
            imagecache: Pin<&mut ImageCache>,
            filename: &str,
            thread_info: *mut Perthread,
            options: *const TextureOpt,
        ) -> *mut ImageHandle;

        pub unsafe fn imagecache_good(
            imagecache: Pin<&mut ImageCache>,
            file: *mut ImageHandle,
        ) -> bool;

        pub unsafe fn imagecache_filename_from_handle(
            imagecache: Pin<&mut ImageCache>,
            handle: *mut ImageHandle,
        ) -> String;

        pub unsafe fn imagecache_get_image_info(
            imagecache: Pin<&mut ImageCache>,
            filename: &str,
            subimage: i32,
            miplevel: i32,
            dataname: &str,
            datatype: TypeDesc,
            data: *const u8,
        ) -> bool;

        pub unsafe fn imagecache_get_image_info_with_handle(
            imagecache: Pin<&mut ImageCache>,
            file: *mut ImageHandle,
            thread_info: *mut Perthread,
            subimage: i32,
            miplevel: i32,
            dataname: &str,
            datatype: TypeDesc,
            data: *const u8,
        ) -> bool;

        pub fn imagecache_get_imagespec(
            imagecache: Pin<&mut ImageCache>,
            filename: &str,
            spec: Pin<&mut ImageSpec>,
            subimage: i32,
            miplevel: i32,
            native: bool,
        ) -> bool;

        pub unsafe fn imagecache_get_imagespec_with_handle(
            imagecache: Pin<&mut ImageCache>,
            file: *mut ImageHandle,
            thread_info: *mut Perthread,
            spec: Pin<&mut ImageSpec>,
            subimage: i32,
            miplevel: i32,
            native: bool,
        ) -> bool;

        pub unsafe fn imagecache_imagespec(
            imagecache: Pin<&mut ImageCache>,
            filename: &str,
            subimage: i32,
            miplevel: i32,
            native: bool,
        ) -> *const ImageSpec;

        pub unsafe fn imagecache_imagespec_with_handle(
            imagecache: Pin<&mut ImageCache>,
            file: *mut ImageHandle,
            thread_info: *mut Perthread,
            subimage: i32,
            miplevel: i32,
            native: bool,
        ) -> *const ImageSpec;

        pub fn imagecache_get_thumbnail(
            imagecache: Pin<&mut ImageCache>,
            filename: &str,
            thumbnail: Pin<&mut ImageBuf>,
            subimage: i32,
        ) -> bool;

        pub unsafe fn imagecache_get_thumbnail_with_handle(
            imagecache: Pin<&mut ImageCache>,
            file: *mut ImageHandle,
            thread_info: *mut Perthread,
            thumbnail: Pin<&mut ImageBuf>,
            subimage: i32,
        ) -> bool;

        pub unsafe fn imagecache_get_pixels(
            imagecache: Pin<&mut ImageCache>,
            filename: &str,
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
            format: TypeDesc,
            result: *const u8,
            xstride: i64,
            ystride: i64,
            zstride: i64,
            cache_chbegin: i32,
            cache_chend: i32,
        ) -> bool;

        pub unsafe fn imagecache_get_pixels_with_handle(
            imagecache: Pin<&mut ImageCache>,
            file: *mut ImageHandle,
            thread_info: *mut Perthread,
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
            format: TypeDesc,
            result: *const u8,
            xstride: i64,
            ystride: i64,
            zstride: i64,
            cache_chbegin: i32,
            cache_chend: i32,
        ) -> bool;

        pub unsafe fn imagecache_get_pixels_all_channels(
            imagecache: Pin<&mut ImageCache>,
            filename: &str,
            subimage: i32,
            miplevel: i32,
            xbegin: i32,
            xend: i32,
            ybegin: i32,
            yend: i32,
            zbegin: i32,
            zend: i32,
            format: TypeDesc,
            result: *const u8,
        ) -> bool;

        pub unsafe fn imagecache_get_pixels_all_channels_with_handle(
            imagecache: Pin<&mut ImageCache>,
            file: *mut ImageHandle,
            thread_info: *mut Perthread,
            subimage: i32,
            miplevel: i32,
            xbegin: i32,
            xend: i32,
            ybegin: i32,
            yend: i32,
            zbegin: i32,
            zend: i32,
            format: TypeDesc,
            result: *const u8,
        ) -> bool;

        pub fn imagecache_invalidate(imagecache: Pin<&mut ImageCache>, filename: &str, force: bool);

        pub unsafe fn imagecache_invalidate_with_handle(
            imagecache: Pin<&mut ImageCache>,
            file: *mut ImageHandle,
            force: bool,
        );

        pub fn imagecache_invalidate_all(imagecache: Pin<&mut ImageCache>, force: bool);

        pub fn imagecache_close(imagecache: Pin<&mut ImageCache>, filename: &str);

        pub fn imagecache_close_all(imagecache: Pin<&mut ImageCache>);

        pub unsafe fn imagecache_get_tile(
            imagecache: Pin<&mut ImageCache>,
            filename: &str,
            subimage: i32,
            miplevel: i32,
            x: i32,
            y: i32,
            z: i32,
            chbegin: i32,
            chend: i32,
        ) -> *mut Tile;

        pub unsafe fn imagecache_get_tile_with_handle(
            imagecache: Pin<&mut ImageCache>,
            file: *mut ImageHandle,
            thread_info: *mut Perthread,
            subimage: i32,
            miplevel: i32,
            x: i32,
            y: i32,
            z: i32,
            chbegin: i32,
            chend: i32,
        ) -> *mut Tile;

        pub unsafe fn imagecache_release_tile(imagecache: Pin<&mut ImageCache>, tile: *mut Tile);

        pub unsafe fn imagecache_tile_format(
            imagecache: Pin<&mut ImageCache>,
            tile: *const Tile,
        ) -> TypeDesc;

        pub unsafe fn imagecache_tile_roi(
            imagecache: Pin<&mut ImageCache>,
            tile: *const Tile,
        ) -> ROI;

        pub unsafe fn imagecache_tile_pixels(
            imagecache: Pin<&mut ImageCache>,
            tile: *mut Tile,
            format: &mut TypeDesc,
        ) -> *const u8;

        // TODO: Add support for the ImageInput::Creator
        // pub unsafe fn imagecache_add_file(
        //     imagecache: Pin<&mut ImageCache>,
        //     filename: &str,
        //     creator: *const ImageInputCreator,
        //     config: *const ImageSpec,
        //     replace: bool,
        // ) -> bool;

        pub unsafe fn imagecache_add_tile_from_coordinates(
            imagecache: Pin<&mut ImageCache>,
            filename: &str,
            subimage: i32,
            miplevel: i32,
            x: i32,
            y: i32,
            z: i32,
            chbegin: i32,
            chend: i32,
            format: TypeDesc,
            buffer: *const u8,
            xstride: i64,
            ystride: i64,
            zstride: i64,
            copy: bool,
        ) -> bool;

        pub fn imagecache_has_error(imagecache: Pin<&mut ImageCache>) -> bool;

        pub fn imagecache_geterror(imagecache: Pin<&mut ImageCache>, clear: bool) -> String;

        pub fn imagecache_getstats(imagecache: Pin<&mut ImageCache>, level: i32) -> String;

        pub fn imagecache_reset_stats(imagecache: Pin<&mut ImageCache>);
    }
}
