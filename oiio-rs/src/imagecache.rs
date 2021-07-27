use crate::cppstd::CppString;
use crate::error::Error;
use crate::imageio::{ImageSpec, ImageSpecRef, Roi, Stride};
use crate::string_view::StringView;
use crate::traits::{AttributeMetadata, Pixel};
use crate::typedesc::TypeDesc;
use crate::ustring::UString;

use oiio_sys as sys;
use std::marker::PhantomData;
use std::os::raw::c_void;
use std::path::Path;

type Result<T, E = Error> = std::result::Result<T, E>;

#[repr(transparent)]
pub struct ImageCache(pub(crate) *mut sys::OIIO_ImageCache_t);

// ImageCache is explicitly thread-safe
unsafe impl Send for ImageCache {}
unsafe impl Sync for ImageCache {}

impl ImageCache {
    pub fn create(shared: bool) -> Self {
        let mut inner = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageCache_create(&mut inner, shared);
        }
        ImageCache(inner)
    }

    /// Setting options and limits for the image cache
    ///
    /// These are the list of attributes that can be set or queried by
    /// set_attribute/attribute:
    ///
    /// - `int max_open_files` :
    ///           The maximum number of file handles that the image cache
    ///           will hold open simultaneously.  (Default = 100)
    /// - `float max_memory_MB` :
    ///           The maximum amount of memory (measured in MB) used for the
    ///           internal "tile cache." (Default: 256.0 MB)
    /// - `string searchpath` :
    ///           The search path for images: a colon-separated list of
    ///           directories that will be searched in order for any image
    ///           filename that is not specified as an absolute path.
    ///           (Default: "")
    /// - `string plugin_searchpath` :
    ///           The search path for plugins: a colon-separated list of
    ///           directories that will be searched in order for any OIIO
    ///           plugins, if not found in OIIO's `lib` directory.
    ///           (Default: "")
    /// - `int autotile` ,
    ///   `int autoscanline` :
    /// These attributes control how the image cache deals with
    /// images that are not "tiled" (i.e., are stored as
    /// scanlines).
    ///
    /// If `autotile` is set to 0 (the default), an untiled image
    /// will be treated as if it were a single tile of the
    /// resolution of the whole image.  This is simple and fast,
    /// but can lead to poor cache behavior if you are
    /// simultaneously accessing many large untiled images.
    ///
    /// If `autotile` is nonzero (e.g., 64 is a good recommended
    /// value), any untiled images will be read and cached as if
    /// they were constructed in tiles of size:
    ///
    /// -- `autotile * autotile` - if `autoscanline` is 0
    /// --- `width * autotile` - if `autoscanline` is nonzero.
    ///
    /// In both cases, this should lead more efficient caching.
    /// The `autoscanline` determines whether the "virtual tiles"
    /// in the cache are square (if `autoscanline` is 0, the
    /// default) or if they will be as wide as the image (but only
    /// `autotile` scanlines high).  You should try in your
    /// application to see which leads to higher performance.
    /// - `int autoscanline` :
    ///           autotile using full width tiles
    /// - `int automip` :
    ///           If 0 (the default), an untiled single-subimage file will
    ///           only be able to utilize that single subimage.
    ///           If nonzero, any untiled, single-subimage (un-MIP-mapped)
    ///           images will have lower-resolution MIP-map levels generated
    ///           on-demand if pixels are requested from the lower-res
    ///           subimages (that don't really exist). Essentially this
    ///           makes the ImageCache pretend that the file is MIP-mapped
    ///           even if it isn't.
    /// - `int accept_untiled` :
    ///           When nonzero, ImageCache accepts untiled images as usual.
    ///           When zero, ImageCache will reject untiled images with an
    ///           error condition, as if the file could not be properly
    ///           read. This is sometimes helpful for applications that want
    ///           to enforce use of tiled images only. (default=1)
    /// - `int accept_unmipped` :
    ///           When nonzero, ImageCache accepts un-MIPmapped images as
    ///           usual.  When set to zero, ImageCache will reject
    ///           un-MIPmapped images with an error condition, as if the
    ///           file could not be properly read. This is sometimes helpful
    ///           for applications that want to enforce use of MIP-mapped
    ///           images only. (Default: 1)
    /// - `int statistics:level` :
    ///           verbosity of statistics auto-printed.
    /// - `int forcefloat` :
    ///           If set to nonzero, all image tiles will be converted to
    ///           `float` type when stored in the image cache.  This can be
    ///           helpful especially for users of ImageBuf who want to
    ///           simplify their image manipulations to only need to
    ///           consider `float` data. The default is zero, meaning that
    ///           image pixels are not forced to be `float` when in cache.
    /// - `int failure_retries` :
    ///           When nonzero (the default), ImageCache accepts
    ///           un-MIPmapped images as usual.  When set to zero,
    ///           ImageCache will reject un-MIPmapped images with an error
    ///           condition, as if the file could not be properly read. This
    ///           is sometimes helpful for applications that want to enforce
    ///           use of MIP-mapped images only. (Default: 1)
    /// - `int deduplicate` :
    ///           When nonzero, the ImageCache will notice duplicate images
    ///           under different names if their headers contain a SHA-1
    ///           fingerprint (as is done with `maketx`-produced textures)
    ///           and handle them more efficiently by avoiding redundant
    ///           reads.  The default is 1 (de-duplication turned on). The
    ///           only reason to set it to 0 is if you specifically want to
    ///           disable the de-duplication optimization.
    /// - `string substitute_image` :
    ///           When set to anything other than the empty string, the
    ///           ImageCache will use the named image in place of *all*
    ///           other images.  This allows you to run an app using OIIO
    ///           and (if you can manage to get this option set)
    ///           automagically substitute a grid, zone plate, or other
    ///           special debugging image for all image/texture use.
    /// - `int unassociatedalpha` :
    ///           When nonzero, will request that image format readers try
    ///           to leave input images with unassociated alpha as they are,
    ///           rather than automatically converting to associated alpha
    ///           upon reading the pixels.  The default is 0, meaning that
    ///           the automatic conversion will take place.
    /// - `int max_errors_per_file` :
    ///           The maximum number of errors that will be printed for each
    ///           file. The default is 100. If your output is cluttered with
    ///           error messages and after the first few for each file you
    ///           aren't getting any helpful additional information, this
    ///           can cut down on the clutter and the runtime. (default:
    ///           100)
    /// - `int trust_file_extensions` :
    ///           When nonzero, assume that the file extensions of any
    ///           texture requests correctly indicates the file format (when
    ///           enabled, this reduces the number of file opens, at the
    ///           expense of not being able to open files if their format do
    ///           not actually match their filename extension). Default: 0
    ///
    /// - `string options`
    /// This catch-all is simply a comma-separated list of
    /// `name=value` settings of named options, which will be
    /// parsed and individually set. Example:
    ///
    /// // ic->attribute ("options", "max_memory_MB=512.0,autotile=1");
    ///
    /// Note that if an option takes a string value that must
    /// itself contain a comma, it is permissible to enclose the
    /// value in either single (` ' ' `) or double (` " " `) quotes.
    ///
    /// **Read-only attributes**
    ///
    /// Additionally, there are some read-only attributes that can be
    /// queried with [`attribute()`] even though they cannot be set via
    /// [`set_attribute()`]:
    ///
    /// - `int total_files` :
    ///           The total number of unique file names referenced by calls
    ///           to the ImageCache.
    ///
    /// - `string[] all_filenames` :
    ///           An array that will be filled with the list of the names of
    ///           all files referenced by calls to the ImageCache. (The
    ///           array is of `ustring` or `char*`.)
    ///
    /// - `int64 stat:cache_memory_used` :
    ///           Total bytes used by tile cache.
    ///
    /// - `int stat:tiles_created` ,
    ///   `int stat:tiles_current` ,
    ///   `int stat:tiles_peak` :
    ///           Total times created, still allocated (at the time of the
    ///           query), and the peak number of tiles in memory at any
    ///           time.
    ///
    /// - `int stat:open_files_created` ,
    ///   `int stat:open_files_current` ,
    ///   `int stat:open_files_peak` :
    ///           Total number of times a file was opened, number still
    ///           opened (at the time of the query), and the peak number of
    ///           files opened at any time.
    ///
    /// - `int stat:find_tile_calls` :
    ///           Number of times a filename was looked up in the file cache.
    ///
    /// - `int64 stat:image_size` :
    ///           Total size (uncompressed bytes of pixel data) of all
    ///           images referenced by the ImageCache. (Note: Prior to 1.7,
    ///           this was called `stat:files_totalsize`.)
    ///
    /// - `int64 stat:file_size` :
    ///           Total size of all files (as on disk, possibly compressed)
    ///           of all images referenced by the ImageCache.
    ///
    /// - `int64 stat:bytes_read` :
    ///           Total size (uncompressed bytes of pixel data) read.
    ///
    /// - `int stat:unique_files` :
    ///           Number of unique files opened.
    ///
    /// - `float stat:fileio_time` :
    ///           Total I/O-related time (seconds).
    ///
    /// - `float stat:fileopen_time` :
    ///           I/O time related to opening and reading headers (but not
    ///           pixel I/O).
    ///
    /// - `float stat:file_locking_time` :
    ///           Total time (across all threads) that threads blocked
    ///           waiting for access to the file data structures.
    ///
    /// - `float stat:tile_locking_time` :
    ///           Total time (across all threads) that threads blocked
    ///           waiting for access to the tile cache data structures.
    ///
    /// - `float stat:find_file_time` :
    ///           Total time (across all threads) that threads spent looking
    ///           up files by name.
    ///
    /// - `float stat:find_tile_time` :
    ///           Total time (across all threads) that threads spent looking
    ///           up individual tiles.
    ///
    /// The following member functions of ImageCache allow you to set (and
    /// in some cases retrieve) options that control the overall behavior of
    /// the image cache:
    ///
    /// Set a named attribute (i.e., a property or option) of the
    /// ImageCache.
    ///
    /// Note: When passing a string, you need to pass a pointer to the
    /// `char*`, not a pointer to the first character.  (Rationale: for an
    /// `int` attribute, you pass the address of the `int`.  So for a
    /// string, which is a `char*`, you need to pass the address of the
    /// string, i.e., a `char**`).
    ///
    /// # Errors
    /// * [`Error::InvalidAttribute`] - if the name of the attribute was
    /// not recognized, or if the attribute is of the wrong type.
    ///
    pub fn set_attribute<S: AsRef<str>, A: AttributeMetadata>(
        &self,
        name: S,
        attribute: &A,
    ) -> Result<()> {
        let mut result = false;
        unsafe {
            let sv = StringView::from(name.as_ref());
            sys::OIIO_ImageCache_attribute(
                self.0,
                &mut result,
                sv.0,
                A::TYPE.into(),
                attribute.ptr(),
            );
        }

        if result {
            Ok(())
        } else {
            Err(Error::InvalidAttribute)
        }
    }
}

impl ImageCache {
    //! Opaque handle management for high-performance lookups

    pub fn get_thread_info_user(&self, perthread: Perthread) -> Perthread {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageCache_get_perthread_info(
                self.0,
                &mut ptr,
                perthread.0,
            );
        }
        Perthread(ptr)
    }

    /// Retrieve a Perthread, unique to the calling thread. This is a
    /// thread-specific pointer that will always return the Perthread for a
    /// thread, which will also be automatically destroyed when the thread
    /// terminates.
    ///
    /// Applications that want to manage their own Perthread pointers (with
    /// [`create_thread_info()`](ImageCache::create_thread_info) and [`destroy_thread_info()`](ImageCache::destroy_thread_info)) should
    /// call [`get_thread_info_user()`](ImageCache::get_thread_info_user) instead.
    ///
    pub fn get_thread_info(&self) -> Perthread {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageCache_get_perthread_info(
                self.0,
                &mut ptr,
                std::ptr::null_mut(),
            );
        }
        Perthread(ptr)
    }

    /// Create a new Perthread. It is the caller's responsibility to
    /// eventually destroy it using [`destroy_thread_info()`](ImageCache::destroy_thread_info).
    ///
    pub fn create_thread_info(&self) -> Perthread {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageCache_create_thread_info(self.0, &mut ptr);
        }
        Perthread(ptr)
    }

    /// Destroy a Perthread that was allocated by
    /// [`create_thread_info()`](ImageCache::create_thread_info).
    ///
    pub fn destroy_thread_info(&self, perthread: Perthread) {
        unsafe {
            sys::OIIO_ImageCache_destroy_thread_info(self.0, perthread.0);
        }
    }

    /// Retrieve an opaque handle for fast image lookups.  
    ///
    /// The opaque `pointer thread_info` is thread-specific information returned by
    /// [`get_perthread_info()`](ImageCache::get_perthread_info).  
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if something goes horribly wrong
    ///
    pub fn get_image_handle(
        &self,
        filename: UString,
        per_thread_info: Option<&Perthread>,
    ) -> Result<ImageHandle> {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageCache_get_image_handle(
                self.0,
                &mut ptr,
                filename.0.clone(),
                if let Some(p) = per_thread_info {
                    p.0
                } else {
                    std::ptr::null_mut()
                },
            );
        }

        if ptr.is_null() {
            Err(Error::Oiio(self.get_error(true)))
        } else {
            Ok(ImageHandle {
                ptr,
                filename,
                marker: PhantomData,
            })
        }
    }

    /// Return true if the image handle (previously returned by
    /// [`get_image_handle()`](ImageCache::get_image_handle)) is a valid image that can be subsequently read.
    pub fn good(&self, handle: &ImageHandle) -> bool {
        let mut result = false;
        unsafe {
            sys::OIIO_ImageCache_good(self.0, &mut result, handle.ptr);
        }
        result
    }
}

impl ImageCache {
    //! Getting information about images

    /// Given possibly-relative `filename`, resolve it and use the true path
    /// to the file, with searchpath logic applied.
    ///
    pub fn resolve_filename<P: AsRef<Path>>(&self, filename: P) -> String {
        let c_filename = CppString::new(
            filename
                .as_ref()
                .to_str()
                .expect("Could not convert filename path to string"),
        );
        let mut result = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageCache_resolve_filename(
                self.0,
                &mut result,
                c_filename.0,
            );
        }
        let result = CppString(result);
        result.as_str().to_string()
    }

    /// Get information or metadata about the named image and store it in
    /// `*data`.
    ///
    /// Data names may include any of the following:
    ///
    /// - `"exists"` : Stores the value 1 (as an `int`) if the file exists and
    ///   is an image format that OpenImageIO can read, or 0 if the file
    ///   does not exist, or could not be properly read as an image. Note
    ///   that unlike all other queries, this query will "succeed" (return
    ///   `true`) even if the file does not exist.
    ///
    /// - `"udim"` : Stores the value 1 (as an `int`) if the file is a
    ///   "virtual UDIM" or texture atlas file (as described in
    ///   :ref:`sec-texturesys-udim`) or 0 otherwise.
    ///
    /// - `"subimages"` : The number of subimages in the file, as an `int`.
    ///
    /// - `"resolution"` : The resolution of the image file, which is an
    ///   array of 2 integers (described as `TypeDesc(INT,2)`).
    ///
    /// - `"miplevels"` : The number of MIPmap levels for the specified
    ///   subimage (an integer).
    ///
    /// - `"texturetype"` : A string describing the type of texture of the
    ///   given file, which describes how the texture may be used (also
    ///   which texture API call is probably the right one for it). This
    ///   currently may return one of: `"unknown"`, `"Plain Texture"`,
    ///   `"Volume Texture"`, `"Shadow"`, or `"Environment"`.
    ///
    /// - `"textureformat"` : A string describing the format of the given
    ///   file, which describes the kind of texture stored in the file. This
    ///   currently may return one of: `"unknown"`, `"Plain Texture"`,
    ///   `"Volume Texture"`, `"Shadow"`, `"CubeFace Shadow"`,
    ///   `"Volume Shadow"`, `"LatLong Environment"`, or
    ///   `"CubeFace Environment"`. Note that there are several kinds of
    ///   shadows and environment maps, all accessible through the same API
    ///   calls.
    ///
    /// - `"channels"` : The number of color channels in the file (an
    ///   `int`).
    ///
    /// - `"format"` : The native data format of the pixels in the file (an
    ///   integer, giving the `TypeDesc::BASETYPE` of the data). Note that
    ///   this is not necessarily the same as the data format stored in the
    ///   image cache.
    ///
    /// - `"cachedformat"` : The native data format of the pixels as stored
    ///   in the image cache (an integer, giving the `TypeDesc::BASETYPE` of
    ///   the data).  Note that this is not necessarily the same as the
    ///   native data format of the file.
    ///
    /// - `"datawindow"` : Returns the pixel data window of the image, which
    ///   is either an array of 4 integers (returning xmin, ymin, xmax,
    ///   ymax) or an array of 6 integers (returning xmin, ymin, zmin, xmax,
    ///   ymax, zmax). The z values may be useful for 3D/volumetric images;
    ///   for 2D images they will be 0).
    ///
    /// - `"displaywindow"` : Returns the display (a.k.a. "full") window of
    ///   the image, which is either an array of 4 integers (returning xmin,
    ///   ymin, xmax, ymax) or an array of 6 integers (returning xmin, ymin,
    ///   zmin, xmax, ymax, zmax). The z values may be useful for
    ///   3D/volumetric images; for 2D images they will be 0).
    ///
    /// - `"worldtocamera"` : The viewing matrix, which is a 4x4 matrix (an
    ///   `Imath::M44f`, described as `TypeDesc(FLOAT,MATRIX)`), giving the
    ///   world-to-camera 3D transformation matrix that was used when  the
    ///   image was created. Generally, only rendered images will have this.
    ///
    /// - `"worldtoscreen"` : The projection matrix, which is a 4x4 matrix
    ///   (an `Imath::M44f`, described as `TypeDesc(FLOAT,MATRIX)`), giving
    ///   the matrix that projected points from world space into a 2D screen
    ///   coordinate system where $x$ and $y$ range from -1 to +1.
    ///   Generally, only rendered images will have this.
    ///
    /// - `"worldtoNDC"` : The projection matrix, which is a 4x4 matrix
    ///   (an `Imath::M44f`, described as `TypeDesc(FLOAT,MATRIX)`), giving
    ///   the matrix that projected points from world space into a 2D NDC
    ///   coordinate system where $x$ and $y$ range from 0 to +1. Generally,
    ///   only rendered images will have this.
    ///
    /// - `"averagecolor"` : If available in the metadata (generally only
    ///   for files that have been processed by `maketx`), this will return
    ///   the average color of the texture (into an array of `float`).
    ///
    /// - `"averagealpha"` : If available in the metadata (generally only
    ///   for files that have been processed by `maketx`), this will return
    ///   the average alpha value of the texture (into a `float`).
    ///
    /// - `"constantcolor"` : If the metadata (generally only for files that
    ///   have been processed by `maketx`) indicates that the texture has
    ///   the same values for all pixels in the texture, this will retrieve
    ///   the constant color of the texture (into an array of floats). A
    ///   non-constant image (or one that does not have the special metadata
    ///   tag identifying it as a constant texture) will fail this query
    ///   (return `false`).
    ///
    /// - `"constantalpha"` : If the metadata indicates that the texture has
    ///   the same values for all pixels in the texture, this will retrieve
    ///   the constant alpha value of the texture (into a float). A
    ///   non-constant image (or one that does not have the special metadata
    ///   tag identifying it as a constant texture) will fail this query
    ///   (return `false`).
    ///
    /// - `"stat:tilesread"` : Number of tiles read from this file
    ///   (`int64`).
    ///
    /// - `"stat:bytesread"` : Number of bytes of uncompressed pixel data
    ///   read from this file (`int64`).
    ///
    /// - `"stat:redundant_tiles"` : Number of times a tile was read, where
    ///   the same tile had been rad before. (`int64`).
    ///
    /// - `"stat:redundant_bytesread"` : Number of bytes (of uncompressed
    ///   pixel data) in tiles that were read redundantly. (`int64`).
    ///
    /// - `"stat:redundant_bytesread"` : Number of tiles read from this file (`int`).
    ///
    /// - `"stat:image_size"` : Size of the uncompressed image pixel data
    /// of this image, in bytes (`int64`).
    ///
    /// - `"stat:file_size"` : Size of the disk file (possibly compressed)
    ///   for this image, in bytes (`int64`).
    ///
    /// - `"stat:timesopened"` : Number of times this file was opened
    ///   (`int`).
    ///
    /// - `"stat:iotime"` : Time (in seconds) spent on all I/O for this file
    ///   (`float`).
    ///
    /// - `"stat:mipsused"` : Stores 1 if any MIP levels beyond the highest
    ///   resolution were accessed, otherwise 0. (`int`)
    ///
    /// - `"stat:is_duplicate"` : Stores 1 if this file was a duplicate of
    ///   another image, otherwise 0. (`int`)
    ///
    /// - *Anything else*  : For all other data names, the the metadata of
    ///   the image file will be searched for an item that matches both the
    ///   name and data type.
    ///
    ///
    ///
    /// @param  filename
    ///             The name of the image.
    /// @param  subimage/miplevel
    ///             The subimage and MIP level to query.
    /// @param  dataname
    ///             The name of the metadata to retrieve.
    /// @param  datatype
    ///             TypeDesc describing the data type.
    /// @param  data
    ///             Pointer to the caller-owned memory where the values
    ///             should be stored. It is the caller's responsibility to
    ///             ensure that `data` points to a large enough storage area
    ///             to accommodate the `datatype` requested.
    ///
    /// @returns
    ///             `true` if `get_image_info()` is able to find the
    ///             requested `dataname` for the image and it matched the
    ///             requested `datatype`.  If the requested data was not
    ///             found or was not of the right data type, return `false`.
    ///             Except for the `"exists"` query, a file that does not
    ///             exist or could not be read properly as an image also
    ///             constitutes a query failure that will return `false`.
    ///
    pub fn get_image_info<A: AttributeMetadata>(
        &self,
        filename: UString,
        subimage: i32,
        miplevel: i32,
        dataname: UString,
        data: A,
    ) -> Result<A> {
        let mut ok = false;
        let mut data = data;
        unsafe {
            sys::OIIO_ImageCache_get_image_info(
                self.0,
                &mut ok,
                filename.0,
                subimage,
                miplevel,
                dataname.0,
                A::TYPE.into(),
                &mut data as *mut A as *mut c_void,
            );
        }
        if ok {
            Ok(data)
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }

    /// A more efficient variety of [`get_image_info()`](ImageCache::get_image_info) for cases where you
    /// can use an [`ImageHandle`] to specify the image and optionally have a
    /// [`Perthread`] for the calling thread.
    ///
    pub fn get_image_info_from_handle<A: AttributeMetadata>(
        &self,
        handle: &ImageHandle,
        thread_info: Option<&Perthread>,
        subimage: i32,
        miplevel: i32,
        dataname: UString,
        data: A,
    ) -> Result<A> {
        let mut ok = false;
        let mut data = data;
        unsafe {
            sys::OIIO_ImageCache_get_image_info_with_handle(
                self.0,
                &mut ok,
                handle.ptr,
                if let Some(p) = thread_info {
                    p.0
                } else {
                    std::ptr::null_mut()
                },
                subimage,
                miplevel,
                dataname.0,
                A::TYPE.into(),
                &mut data as *mut A as *mut c_void,
            );
        }
        if ok {
            Ok(data)
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }

    /// Return a reference to an ImageSpec associated with the given ImageHandle at the given
    /// subimage and miplevel.
    ///
    /// # Safety
    /// Although the returned Ref is tied to the lifetime of `handle`, it is
    /// still possible for that ImageHandle to be invalidated by getting another
    /// handle to the same file and calling invalidate on that. Therefore the
    /// user is responsible for makng sure this doesn't happen.
    ///
    /// # Errors
    /// * [`Error::InvalidHandle`] - if the combination of handle, subimage and miplevel does not
    /// refer to a valid image that can be read
    ///
    pub unsafe fn imagespec<'h>(
        &self,
        handle: &'h ImageHandle,
        thread_info: Option<&Perthread>,
        subimage: i32,
        miplevel: i32,
        native: bool,
    ) -> Result<ImageSpecRef<'h>> {
        let mut ptr = std::ptr::null();
        sys::OIIO_ImageCache_imagespec_with_handle(
            self.0,
            &mut ptr,
            handle.ptr,
            if let Some(p) = thread_info {
                p.0
            } else {
                std::ptr::null_mut()
            },
            subimage,
            miplevel,
            native,
        );

        if ptr.is_null() {
            Err(Error::InvalidHandle)
        } else {
            Ok(ImageSpecRef::new(ptr))
        }
    }

    /// Get a copy of the ImageSpec associated with the named image, subimage and miplevel.
    ///
    /// This method is obviously slower than [`imagespec`](ImageCache::imagespec)
    /// as it copies the spec, but it is safe.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if any error occurs
    ///
    pub fn imagespec_copy(
        &self,
        handle: &ImageHandle,
        thread_info: Option<&Perthread>,
        subimage: i32,
        miplevel: i32,
        native: bool,
    ) -> Result<ImageSpec> {
        let spec = ImageSpec::from_typedesc(TypeDesc::UNKNOWN);
        let mut result = false;
        unsafe {
            sys::OIIO_ImageCache_get_imagespec_with_handle(
                self.0,
                &mut result,
                handle.ptr,
                if let Some(p) = thread_info {
                    p.0
                } else {
                    std::ptr::null_mut()
                },
                spec.0,
                subimage,
                miplevel,
                native,
            );
        }

        if result {
            Ok(spec)
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }
}

impl ImageCache {
    //! Getting pixels.

    pub unsafe fn get_pixels<T: Pixel>(
        &self,
        handle: &ImageHandle,
        thread_info: Option<&Perthread>,
        xbegin: i32,
        xend: i32,
        ybegin: i32,
        yend: i32,
        zbegin: i32,
        zend: i32,
        data: &[T],
        opt: ReadOptions,
    ) -> Result<()> {
        let mut ok = false;

        sys::OIIO_ImageCache_get_pixels_with_channels_and_handle(
            self.0,
            &mut ok,
            handle.ptr,
            if let Some(p) = thread_info {
                p.0
            } else {
                std::ptr::null_mut()
            },
            opt.subimage,
            opt.miplevel,
            xbegin,
            xend,
            ybegin,
            yend,
            zbegin,
            zend,
            opt.chbegin,
            opt.chend,
            T::FORMAT.into(),
            data.as_ptr() as *mut c_void,
            opt.x_stride.0,
            opt.y_stride.0,
            opt.z_stride.0,
            opt.cache_chbegin,
            opt.cache_chend,
        );

        if ok {
            Ok(())
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }
}

pub struct ReadOptions {
    pub subimage: i32,
    pub miplevel: i32,
    pub chbegin: i32,
    pub chend: i32,
    pub x_stride: Stride,
    pub y_stride: Stride,
    pub z_stride: Stride,
    pub cache_chbegin: i32,
    pub cache_chend: i32,
}

impl Default for ReadOptions {
    fn default() -> Self {
        ReadOptions {
            subimage: 0,
            miplevel: 0,
            chbegin: 0,
            chend: 0,
            x_stride: Stride::AUTO,
            y_stride: Stride::AUTO,
            z_stride: Stride::AUTO,
            cache_chbegin: 0,
            cache_chend: -1,
        }
    }
}

impl ImageCache {
    //! Controlling the cache

    /// Invalidate any loaded tiles or open file handles associated with the
    /// filename, so that any subsequent queries will be forced to re-open
    /// the file or re-load any tiles (even those that were previously
    /// loaded and would ordinarily be reused).  A client might do this if,
    /// for example, they are aware that an image being held in the cache
    /// has been updated on disk.  This is safe to do even if other
    /// procedures are currently holding reference-counted tile pointers
    /// from the named image, but those procedures will not get updated
    /// pixels until they release the tiles they are holding.
    ///
    /// If `force` is true, this invalidation will happen unconditionally;
    /// if false, the file will only be invalidated if it has been changed
    /// since it was first opened by the ImageCache.
    ///
    pub fn invalidate(&self, handle: ImageHandle, force: bool) {
        unsafe {
            sys::OIIO_ImageCache_invalidate(self.0, handle.filename.0, force);
        }
    }

    /// Invalidate all loaded tiles and close open file handles.  This is
    /// safe to do even if other procedures are currently holding
    /// reference-counted tile pointers from the named image, but those
    /// procedures will not get updated pixels (if the images change) until
    /// they release the tiles they are holding.
    ///
    /// If `force` is true, everything will be invalidated, no matter how
    /// wasteful it is, but if `force` is false, in actuality files will
    /// only be invalidated if their modification times have been changed
    /// since they were first opened.
    ///
    pub fn invalidate_all(&mut self, force: bool) {
        unsafe {
            sys::OIIO_ImageCache_invalidate_all(self.0, force);
        }
    }

    /// Find the tile specified by an image handle, subimage & miplevel,
    /// the coordinates of a pixel, and a channel range.   
    ///
    /// The tile will not be purged from the cache until after `release_tile()` is called
    /// on the tile pointer the same number of times that `get_tile()` was
    /// called (reference counting). If `chend <
    /// chbegin`, it will retrieve a tile containing all channels in the
    /// file.
    ///
    pub fn get_tile(
        &self,
        handle: &ImageHandle,
        thread_info: Option<&Perthread>,
        subimage: i32,
        miplevel: i32,
        x: i32,
        y: i32,
        z: i32,
        chbegin: i32,
        chend: i32,
    ) -> Result<Tile> {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageCache_get_tile_with_handle(
                self.0,
                &mut ptr,
                handle.ptr,
                if let Some(p) = thread_info {
                    p.0
                } else {
                    std::ptr::null_mut()
                },
                subimage,
                miplevel,
                x,
                y,
                z,
                chbegin,
                chend,
            );
        }

        if ptr.is_null() {
            Err(Error::Oiio(self.get_error(true)))
        } else {
            Ok(Tile { ptr, cache: self })
        }
    }

    // # Safety
    // This must only be called from Tile::drop
    //
    unsafe fn release_tile(&self, tile: &Tile) {
        sys::OIIO_ImageCache_release_tile(self.0, tile.ptr);
    }
}

impl ImageCache {
    //! Errors and statistics

    /// Return the text of all pending error messages issued against this
    /// ImageCache by the calling thread, and clear the pending error
    /// message unless `clear` is false. If no error message is pending, it
    /// will return an empty string.
    ///
    pub fn get_error(&self, clear: bool) -> String {
        let mut msg = CppString::new("");
        unsafe {
            sys::OIIO_ImageCache_geterror(self.0, &mut msg.0, clear);
            msg.as_str().to_string()
        }
    }

    /// Returns a big string containing useful statistics about the
    /// ImageCache operations, suitable for saving to a file or outputting
    /// to the terminal. The `level` indicates the amount of detail in
    /// the statistics, with higher numbers (up to a maximum of 5) yielding
    /// more and more esoteric information.
    ///
    pub fn getstats(&self, level: i32) -> String {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_ImageCache_getstats(self.0, &mut ptr, level);
        }
        CppString(ptr).as_str().to_string()
    }

    /// Reset most statistics to be as they were with a fresh ImageCache.
    /// Caveat emptor: this does not flush the cache itelf, so the resulting
    /// statistics from the next set of texture requests will not match the
    /// number of tile reads, etc., that would have resulted from a new
    /// ImageCache.
    ///
    pub fn reset_stats(&self) {
        unsafe {
            sys::OIIO_ImageCache_reset_stats(self.0);
        }
    }
}

impl Drop for ImageCache {
    fn drop(&mut self) {
        unsafe {
            // FIXME: do we want teardown to be true here?
            sys::OIIO_ImageCache_destroy(self.0, true);
        }
    }
}

pub struct Perthread(pub(crate) *mut sys::OIIO_pvt_ImageCachePerThreadInfo_t);

pub struct ImageHandle<'cache> {
    pub(crate) ptr: *mut sys::OIIO_pvt_ImageCacheFile_t,
    pub(crate) filename: UString,
    pub(crate) marker: PhantomData<&'cache ()>,
}

pub struct Tile<'cache> {
    pub(crate) ptr: *mut sys::OIIO_ImageCache_Tile_t,
    cache: &'cache ImageCache,
}

impl<'cache> Tile<'cache> {
    /// Retrieve the data type of the pixels stored in the tile, which may
    /// be different than the type of the pixels in the disk file.
    ///
    pub fn format(&self) -> TypeDesc {
        let mut td = TypeDesc::UNKNOWN;
        unsafe {
            sys::OIIO_ImageCache_tile_format(
                self.cache.0,
                &mut td as *mut TypeDesc as *mut sys::OIIO_TypeDesc_t,
                self.ptr,
            );
        }
        td
    }

    /// Retrieve the ROI describing the pixels and channels stored in the
    /// tile.
    ///
    pub fn roi(&self) -> Roi {
        let mut roi = Roi::default();
        unsafe {
            sys::OIIO_ImageCache_tile_roi(
                self.cache.0,
                &mut roi as *mut Roi as *mut sys::OIIO_ROI_t,
                self.ptr,
            );
        }
        roi
    }

    // TODO: get_pixels()
}

impl<'cache> Drop for Tile<'cache> {
    fn drop(&mut self) {
        unsafe {
            self.cache.release_tile(self);
        }
    }
}
