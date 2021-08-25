use crate::cppstd::CppString;
use crate::error::Error;
use crate::filesystem::IOProxy;
use crate::imagecache::ImageCache;
use crate::imageio::{
    get_trampoline, ImageOutputOpened, ImageSpec, ImageSpecRef, Roi, Stride,
    Strides,
};
use crate::traits::AttributeMetadata;
use crate::typedesc::TypeDesc;

use crate::string_view::StringView;
use crate::traits::Pixel;
use crate::ustring::UString;
use imath_traits::Vec3;

use oiio_sys as sys;

use std::convert::TryInto;
use std::marker::PhantomData;
use std::os::raw::c_void;
use std::path::Path;

type Result<T, E = Error> = std::result::Result<T, E>;

pub use sys::OIIO_RunFlagVal as RunFlagVal;
pub use sys::OIIO_Tex_InterpMode as InterpMode;
pub use sys::OIIO_Tex_MipMode as MipMode;

/// TextureOpt is a structure that holds many options controlling
/// single-point texture lookups.
///
pub use sys::OIIO_TextureOpt_t as TextureOpt;

/// Texture options for a batch of Tex::BatchWidth points and run mask.
///
pub use sys::OIIO_TextureOptBatch_t as TextureOptBatch;

/// Define an API to an abstract class that that manages texture files,
/// caches of open file handles as well as tiles of texels so that truly
/// huge amounts of texture may be accessed by an application with low
/// memory footprint, and ways to perform antialiased texture, shadow
/// map, and environment map lookups.
///
pub struct TextureSystem(pub(crate) *mut sys::OIIO_TextureSystem_t);

impl TextureSystem {
    //! Creating and destroying a TextureSystem

    /// Create a TextureSystem
    ///
    /// # Parameters
    /// * `shared` -
    ///     If `shared` is `true`, the pointer returned will be a shared
    ///     TextureSystem, (so that multiple parts of an application that
    ///     request a TextureSystem will all end up with the same one, and
    ///     the same underlying ImageCache). If `shared` is `false`, a
    ///     completely unique TextureCache will be created and returned.
    ///
    /// * `imagecache`:
    ///     If `shared` is `false` and `imagecache` is not `None`, the
    ///     TextureSystem will use this as its underlying ImageCache. In
    ///     that case, it is the caller who is responsible for eventually
    ///     freeing the ImageCache after the TextureSystem is destroyed.  If
    ///     `shared` is `false` and `imagecache` is `nullptr`, then a custom
    ///     ImageCache will be created, owned by the TextureSystem, and
    ///     automatically freed when the TS destroys.
    ///
    pub fn create(
        shared: bool,
        imagecache: Option<&ImageCache>,
    ) -> TextureSystem {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_TextureSystem_create(
                &mut ptr,
                shared,
                if let Some(ic) = imagecache {
                    ic.0
                } else {
                    std::ptr::null_mut()
                },
            );
        }

        if ptr.is_null() {
            panic!("TextureSystem::create returned a null pointer");
        }

        TextureSystem(ptr)
    }

    /// Destroy a TextureSystem, including freeing all system
    /// resources that it holds.
    ///
    /// It is safe to destroy even a shared TextureSystem, as the
    /// implementation of `destroy()` will recognize a shared one and only
    /// truly release its resources if it has been requested to be destroyed
    /// as many times as shared TextureSystem's were created.
    ///
    /// # Parameters
    /// * `ts`:
    ///     TextureSystem to destroy.
    ///
    /// * `teardown_imagecache`
    ///     For a shared TextureSystem, if the `teardown_imagecache`
    ///     parameter is `true`, it will try to truly destroy the shared
    ///     cache if nobody else is still holding a reference (otherwise, it
    ///     will leave it intact). This parameter has no effect if `ts` was
    ///     not the single globally shared TextureSystem.
    ///
    pub fn destroy(ts: TextureSystem, teardown_imagecache: bool) {
        unsafe {
            sys::OIIO_TextureSystem_destroy(ts.0, teardown_imagecache);
        }
    }
}

impl TextureSystem {
    //! Setting options and limits for the TextureSystem
    //!
    //! These are the list of attributes that can bet set or queried by
    //! attribute/getattribute:
    //!
    //! All attributes ordinarily recognized by ImageCache are accepted and
    //! passed through to the underlying ImageCache. These include:
    //! - `i32 max_open_files` :
    //!             Maximum number of file handles held open.
    //! - `f32 max_memory_MB` :
    //!             Maximum tile cache size, in MB.
    //! - `string searchpath` :
    //!             Colon-separated search path for texture files.
    //! - `string plugin_searchpath` :
    //!             Colon-separated search path for plugins.
    //! - `i32 autotile` :
    //!             If >0, tile size to emulate for non-tiled images.
    //! - `i32 autoscanline` :
    //!             If nonzero, autotile using full width tiles.
    //! - `i32 automip` :
    //!             If nonzero, emulate mipmap on the fly.
    //! - `i32 accept_untiled` :
    //!             If nonzero, accept untiled images.
    //! - `i32 accept_unmipped` :
    //!             If nonzero, accept unmipped images.
    //! - `i32 failure_retries` :
    //!             How many times to retry a read failure.
    //! - `i32 deduplicate` :
    //!             If nonzero, detect duplicate textures (default=1).
    //! - `string substitute_image` :
    //!             If supplied, an image to substatute for all texture
    //!             references.
    //! - `i32 max_errors_per_file` :
    //!             Limits how many errors to issue for each file. (default:
    //!             100)
    //!
    //! Texture-specific settings:
    //! - `matrix44 worldtocommon` / `matrix44 commontoworld` :
    //!             The 4x4 matrices that provide the spatial transformation
    //!             from "world" to a "common" coordinate system and back.
    //!             This is mainly used for shadow map lookups, in which the
    //!             shadow map itself encodes the world coordinate system,
    //!             but positions passed to `shadow()` are expressed in
    //!             "common" coordinates. You do not need to set
    //!             `commontoworld` and `worldtocommon` separately; just
    //!             setting either one will implicitly set the other, since
    //!             each is the inverse of the other.
    //! - `i32 gray_to_rgb` :
    //!             If set to nonzero, texture lookups of single-channel
    //!             (grayscale) images will replicate the sole channel's
    //!             values into the next two channels, making it behave like
    //!             an RGB image that happens to have all three channels
    //!             with identical pixel values.  (Channels beyond the third
    //!             will get the "fill" value.) The default value of zero
    //!             means that all missing channels will get the "fill"
    //!             color.
    //! - `i32 max_tile_channels` :
    //!             The maximum number of color channels in a texture file
    //!             for which all channels will be loaded as a single cached
    //!             tile. Files with more than this number of color channels
    //!             will have only the requested subset loaded, in order to
    //!             save cache space (but at the possible wasted expense of
    //!             separate tiles that overlap their channel ranges). The
    //!             default is 5.
    //! - `i32 max_mip_res` :
    //!             **NEW 2.1** Sets the maximum MIP-map resolution for
    //!             filtered texture lookups. The MIP levels used will be
    //!             clamped to those having fewer than this number of pixels
    //!             in each dimension. This can be helpful as a way to limit
    //!             disk I/O when doing fast preview renders (with the
    //!             tradeoff that you may see some texture more blurry than
    //!             they would ideally be). The default is `1 << 30`, a
    //!             value so large that no such clamping will be performed.
    //! - `string latlong_up` :
    //!             The default "up" direction for latlong environment maps
    //!             (only applies if the map itself doesn't specify a format
    //!             or is in a format that explicitly requires a particular
    //!             orientation).  The default is `"y"`.  (Currently any
    //!             other value will result in *z* being "up.")
    //! - `i32 flip_t` :
    //!             If nonzero, `t` coordinates will be flipped `1-t` for
    //!             all texture lookups. The default is 0.
    //!
    //! - `string options`
    //!             This catch-all is simply a comma-separated list of
    //!             `name=value` settings of named options, which will be
    //!             parsed and individually set.
    //!
    //!                 ic->attribute ("options", "max_memory_MB=512.0,autotile=1");
    //!
    //!             Note that if an option takes a string value that must
    //!             itself contain a comma, it is permissible to enclose the
    //!             value in either single `\'` or double `"` quotes.
    //!

    /// Gets attribute `name`
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if no attribute with `name` exists, or if it is of
    /// a different type
    ///
    pub fn get_attribute<A: AttributeMetadata>(
        &self,
        name: &str,
        case_sensitive: bool,
    ) -> Option<A> {
        let mut ok = false;
        let mut result = A::default();
        let sv = StringView::from(name.as_ref());
        unsafe {
            sys::OIIO_TextureSystem_getattribute(
                self.0,
                &mut ok,
                sv.into(),
                A::TYPE.into(),
                result.ptr_mut(),
            );
        }

        if ok {
            Some(result)
        } else {
            None
        }
    }

    /// Sets the attribute `name`
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if no attribute with `name` exists, or if it is of
    /// a different type
    ///
    pub fn set_attribute<S: AsRef<str>, A: AttributeMetadata>(
        &mut self,
        name: S,
        attribute: &A,
    ) -> Result<()> {
        let sv = StringView::from(name.as_ref());
        let mut ok = false;

        unsafe {
            sys::OIIO_TextureSystem_attribute(
                self.0,
                &mut ok,
                sv.0,
                A::TYPE.into(),
                attribute.ptr(),
            );
        }

        if ok {
            Ok(())
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }
}

impl TextureSystem {
    //! Opaque handle management for high-performance lookups

    pub fn get_thread_info_user(&self, perthread: Perthread) -> Perthread {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_TextureSystem_get_perthread_info(
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
    /// [`create_thread_info()`](TextureSystem::create_thread_info) and [`destroy_thread_info()`](TextureSystem::destroy_thread_info)) should
    /// call [`get_thread_info_user()`](TextureSystem::get_thread_info_user) instead.
    ///
    pub fn get_thread_info(&self) -> Perthread {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_TextureSystem_get_perthread_info(
                self.0,
                &mut ptr,
                std::ptr::null_mut(),
            );
        }
        Perthread(ptr)
    }

    /// Create a new Perthread. It is the caller's responsibility to
    /// eventually destroy it using [`destroy_thread_info()`](TextureSystem::destroy_thread_info).
    ///
    pub fn create_thread_info(&self) -> Perthread {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_TextureSystem_create_thread_info(self.0, &mut ptr);
        }
        Perthread(ptr)
    }

    /// Destroy a Perthread that was allocated by
    /// [`create_thread_info()`](TextureSystem::create_thread_info).
    ///
    pub fn destroy_thread_info(&self, perthread: Perthread) {
        unsafe {
            sys::OIIO_TextureSystem_destroy_thread_info(self.0, perthread.0);
        }
    }

    /// Retrieve an opaque handle for fast image lookups.  
    ///
    /// The opaque `pointer thread_info` is thread-specific information returned by
    /// [`get_perthread_info()`](TextureSystem::get_perthread_info).  
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if something goes horribly wrong
    ///
    pub fn get_texture_handle(
        &self,
        filename: UString,
        per_thread_info: Option<&Perthread>,
    ) -> Result<TextureHandle> {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_TextureSystem_get_texture_handle(
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
            Ok(TextureHandle {
                ptr,
                marker: PhantomData,
            })
        }
    }

    /// Return true if the image handle (previously returned by
    /// [`get_image_handle()`](TextureSystem::get_image_handle)) is a valid image that can be subsequently read.
    ///
    pub fn good(&self, handle: &TextureHandle) -> bool {
        let mut result = false;
        unsafe {
            sys::OIIO_TextureSystem_good(self.0, &mut result, handle.ptr);
        }
        result
    }

    /// Given a handle, return the filename for that image.
    ///
    pub fn filename_from_handle(&self, handle: &TextureHandle) -> &'static str {
        let mut result = sys::OIIO_ustring_t::default();
        unsafe {
            sys::OIIO_TextureSystem_filename_from_handle(
                self.0,
                &mut result,
                handle.ptr,
            );
        }

        UString(result).as_str()
    }
}

impl TextureSystem {
    //! Texture lookups

    /// Perform a filtered 2D texture lookup on a position centered at 2D
    /// coordinates (`s`, `t`) from the texture identified by `filename`,
    /// and using relevant texture `options`.  The length of the `result` slice
    /// determines the number of channels to retrieve (e.g., 1 for a single
    /// value, 3 for an RGB triple, etc.). The filtered results will be
    /// stored in `result[0..nchannels-1]`.
    ///
    /// We assume that this lookup will be part of an image that has pixel
    /// coordinates `x` and `y`.  By knowing how `s` and `t` change from
    /// pixel to pixel in the final image, we can properly *filter* or
    /// antialias the texture lookups.  This information is given via
    /// derivatives `dsdx` and `dtdx` that define the change in `s` and `t`
    /// per unit of `x`, and `dsdy` and `dtdy` that define the change in `s`
    /// and `t` per unit of `y`.  If it is impossible to know the
    /// derivatives, you may pass 0 for them, but in that case you will not
    /// receive an antialiased texture lookup.
    ///
    /// # Parameters
    ///
    /// * filename
    ///             The name of the texture.
    /// * options
    ///     Fields within `options` that are honored for 2D texture lookups
    ///     include the following:
    ///     - `int firstchannel` :
    ///             The index of the first channel to look up from the texture.
    ///     - `int subimage / ustring subimagename` :
    ///             The subimage or face within the file, specified by
    ///             either by name (if non-empty) or index. This will be
    ///             ignored if the file does not have multiple subimages or
    ///             separate per-face textures.
    ///     - `Wrap swrap, twrap` :
    ///             Specify the *wrap mode* for each direction, one of:
    ///             `WrapBlack`, `WrapClamp`, `WrapPeriodic`, `WrapMirror`,
    ///             or `WrapDefault`.
    ///     - `float swidth, twidth` :
    ///             For each direction, gives a multiplier for the derivatives.
    ///     - `float sblur, tblur` :
    ///             For each direction, specifies an additional amount of
    ///             pre-blur to apply to the texture (*after* derivatives
    ///             are taken into account), expressed as a portion of the
    ///             width of the texture.
    ///     - `float fill` :
    ///             Specifies the value that will be used for any color
    ///             channels that are requested but not found in the file.
    ///             For example, if you perform a 4-channel lookup on a
    ///             3-channel texture, the last channel will get the fill
    ///             value.  (Note: this behavior is affected by the
    ///             `"gray_to_rgb"` TextureSystem attribute.
    ///     - `const float *missingcolor` :
    ///             If not `nullptr`, specifies the color that will be
    ///             returned for missing or broken textures (rather than
    ///             being an error).
    /// * s/t
    ///             The 2D texture coordinates.
    /// * dsdx,dtdx,dsdy,dtdy
    ///             The differentials of s and t relative to canonical
    ///             directions x and y.  The choice of x and y are not
    ///             important to the implementation; it can be any imposed
    ///             2D coordinates, such as pixels in screen space, adjacent
    ///             samples in parameter space on a surface, etc. The st
    ///             derivatives determine the size and shape of the
    ///             ellipsoid over which the texture lookup is filtered.
    /// * nchannels
    ///             The number of channels of data to retrieve into `result`
    ///             (e.g., 1 for a single value, 3 for an RGB triple, etc.).
    /// * result[]
    ///             The result of the filtered texture lookup will be placed
    ///             into `result[0..nchannels-1]`.
    /// * dresultds/dresultdt
    ///             If non-null, these designate storage locations for the
    ///             derivatives of result, i.e., the rate of change per unit
    ///             s and t, respectively, of the filtered texture. If
    ///             supplied, they must allow for `nchannels` of storage.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if the file was not found or could not be read
    ///
    /// # Panics
    /// * If the sizes of `result`, `dresultds` and `dresultdt` do not match
    /// * If the length of `result` is not representable as an i32
    ///
    pub fn texture(
        &mut self,
        filename: UString,
        options: &mut TextureOpt,
        s: f32,
        t: f32,
        dsdx: f32,
        dtdx: f32,
        dsdy: f32,
        dtdy: f32,
        result: &mut [f32],
        dresultds: Option<&mut [f32]>,
        dresultdt: Option<&mut [f32]>,
    ) -> Result<()> {
        let mut ok = false;
        unsafe {
            sys::OIIO_TextureSystem_texture(
                self.0,
                &mut ok,
                filename.0,
                options as *mut TextureOpt,
                s,
                t,
                dsdx,
                dtdx,
                dsdy,
                dtdy,
                result
                    .len()
                    .try_into()
                    .expect("result.len not representable as i32"),
                result.as_mut_ptr(),
                if let Some(sl) = dresultds {
                    sl.as_mut_ptr()
                } else {
                    std::ptr::null_mut()
                },
                if let Some(sl) = dresultdt {
                    sl.as_mut_ptr()
                } else {
                    std::ptr::null_mut()
                },
            );
        }

        if ok {
            Ok(())
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }

    /// Perform a filtered 2D texture lookup on a position centered at 2D
    /// coordinates (`s`, `t`) from the texture identified by `filename`,
    /// and using relevant texture `options`.  The length of the `result` slice
    /// determines the number of channels to retrieve (e.g., 1 for a single
    /// value, 3 for an RGB triple, etc.). The filtered results will be
    /// stored in `result[0..nchannels-1]`.
    ///
    /// We assume that this lookup will be part of an image that has pixel
    /// coordinates `x` and `y`.  By knowing how `s` and `t` change from
    /// pixel to pixel in the final image, we can properly *filter* or
    /// antialias the texture lookups.  This information is given via
    /// derivatives `dsdx` and `dtdx` that define the change in `s` and `t`
    /// per unit of `x`, and `dsdy` and `dtdy` that define the change in `s`
    /// and `t` per unit of `y`.  If it is impossible to know the
    /// derivatives, you may pass 0 for them, but in that case you will not
    /// receive an antialiased texture lookup.
    ///
    /// # Parameters
    ///
    /// * handle
    ///             The handle of the texture.
    /// * per_thread_info
    ///             Optional per-thread info
    /// * options
    ///     Fields within `options` that are honored for 2D texture lookups
    ///     include the following:
    ///     - `int firstchannel` :
    ///             The index of the first channel to look up from the texture.
    ///     - `int subimage / ustring subimagename` :
    ///             The subimage or face within the file, specified by
    ///             either by name (if non-empty) or index. This will be
    ///             ignored if the file does not have multiple subimages or
    ///             separate per-face textures.
    ///     - `Wrap swrap, twrap` :
    ///             Specify the *wrap mode* for each direction, one of:
    ///             `WrapBlack`, `WrapClamp`, `WrapPeriodic`, `WrapMirror`,
    ///             or `WrapDefault`.
    ///     - `float swidth, twidth` :
    ///             For each direction, gives a multiplier for the derivatives.
    ///     - `float sblur, tblur` :
    ///             For each direction, specifies an additional amount of
    ///             pre-blur to apply to the texture (*after* derivatives
    ///             are taken into account), expressed as a portion of the
    ///             width of the texture.
    ///     - `float fill` :
    ///             Specifies the value that will be used for any color
    ///             channels that are requested but not found in the file.
    ///             For example, if you perform a 4-channel lookup on a
    ///             3-channel texture, the last channel will get the fill
    ///             value.  (Note: this behavior is affected by the
    ///             `"gray_to_rgb"` TextureSystem attribute.
    ///     - `const float *missingcolor` :
    ///             If not `nullptr`, specifies the color that will be
    ///             returned for missing or broken textures (rather than
    ///             being an error).
    /// * s/t
    ///             The 2D texture coordinates.
    /// * dsdx,dtdx,dsdy,dtdy
    ///             The differentials of s and t relative to canonical
    ///             directions x and y.  The choice of x and y are not
    ///             important to the implementation; it can be any imposed
    ///             2D coordinates, such as pixels in screen space, adjacent
    ///             samples in parameter space on a surface, etc. The st
    ///             derivatives determine the size and shape of the
    ///             ellipsoid over which the texture lookup is filtered.
    /// * nchannels
    ///             The number of channels of data to retrieve into `result`
    ///             (e.g., 1 for a single value, 3 for an RGB triple, etc.).
    /// * result[]
    ///             The result of the filtered texture lookup will be placed
    ///             into `result[0..nchannels-1]`.
    /// * dresultds/dresultdt
    ///             If non-null, these designate storage locations for the
    ///             derivatives of result, i.e., the rate of change per unit
    ///             s and t, respectively, of the filtered texture. If
    ///             supplied, they must allow for `nchannels` of storage.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if the file was not found or could not be read
    ///
    /// # Panics
    /// * If the sizes of `result`, `dresultds` and `dresultdt` do not match
    /// * If the length of `result` is not representable as an i32
    ///
    pub fn texture_with_handle(
        &mut self,
        handle: &TextureHandle,
        per_thread_info: Option<&Perthread>,
        options: &mut TextureOpt,
        s: f32,
        t: f32,
        dsdx: f32,
        dtdx: f32,
        dsdy: f32,
        dtdy: f32,
        result: &mut [f32],
        dresultds: Option<&mut [f32]>,
        dresultdt: Option<&mut [f32]>,
    ) -> Result<()> {
        let mut ok = false;
        unsafe {
            sys::OIIO_TextureSystem_texture_with_handle(
                self.0,
                &mut ok,
                handle.ptr,
                if let Some(p) = per_thread_info {
                    p.0
                } else {
                    std::ptr::null_mut()
                },
                options as *mut TextureOpt,
                s,
                t,
                dsdx,
                dtdx,
                dsdy,
                dtdy,
                result
                    .len()
                    .try_into()
                    .expect("result.len not representable as i32"),
                result.as_mut_ptr(),
                if let Some(sl) = dresultds {
                    sl.as_mut_ptr()
                } else {
                    std::ptr::null_mut()
                },
                if let Some(sl) = dresultdt {
                    sl.as_mut_ptr()
                } else {
                    std::ptr::null_mut()
                },
            );
        }

        if ok {
            Ok(())
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }

    /// Perform a filtered 3D volumetric texture lookup on a position
    /// centered at 3D position `P` (with given differentials) from the
    /// texture identified by `filename`, and using relevant texture
    /// `options`.  The filtered results will be stored in
    /// `result`.
    ///
    /// The `P` coordinate and `dPdx`, `dPdy`, and `dPdz` derivatives are
    /// assumed to be in some kind of common global coordinate system
    /// (usually "world" space) and will be automatically transformed into
    /// volume local coordinates, if such a transformation is specified in
    /// the volume file itself.
    ///
    /// * filename
    ///             The name of the texture.
    /// * options
    ///     Fields within `options` that are honored for 3D texture lookups
    ///     include the following:
    ///     - `int firstchannel` :
    ///             The index of the first channel to look up from the texture.
    ///     - `int subimage / ustring subimagename` :
    ///             The subimage or field within the volume, specified by
    ///             either by name (if non-empty) or index. This will be
    ///             ignored if the file does not have multiple subimages or
    ///             separate per-face textures.
    ///     - `Wrap swrap, twrap, rwrap` :
    ///             Specify the *wrap mode* for each direction, one of:
    ///             `WrapBlack`, `WrapClamp`, `WrapPeriodic`, `WrapMirror`,
    ///             or `WrapDefault`.
    ///     - `float swidth, twidth, rwidth` :
    ///             For each direction, gives a multiplier for the derivatives.
    ///     - `float sblur, tblur, rblur` :
    ///             For each direction, specifies an additional amount of
    ///             pre-blur to apply to the texture (*after* derivatives
    ///             are taken into account), expressed as a portion of the
    ///             width of the texture.
    ///     - `float fill` :
    ///             Specifies the value that will be used for any color
    ///             channels that are requested but not found in the file.
    ///             For example, if you perform a 4-channel lookup on a
    ///             3-channel texture, the last channel will get the fill
    ///             value.  (Note: this behavior is affected by the
    ///             `"gray_to_rgb"` TextureSystem attribute.
    ///     - `const float *missingcolor` :
    ///             If not `nullptr`, specifies the color that will be
    ///             returned for missing or broken textures (rather than
    ///             being an error).
    ///     - `float time` :
    ///             A time value to use if the volume texture specifies a
    ///             time-varying local transformation (default: 0).
    /// * P
    ///             The 2D texture coordinates.
    /// * dPdx/dPdy/dPdz
    ///             The differentials of `P`. We assume that this lookup
    ///             will be part of an image that has pixel coordinates `x`
    ///             and `y` and depth `z`. By knowing how `P` changes from
    ///             pixel to pixel in the final image, and as we step in *z*
    ///             depth, we can properly *filter* or antialias the texture
    ///             lookups.  This information is given via derivatives
    ///             `dPdx`, `dPdy`, and `dPdz` that define the changes in
    ///             `P` per unit of `x`, `y`, and `z`, respectively.  If it
    ///             is impossible to know the derivatives, you may pass 0
    ///             for them, but in that case you will not receive an
    ///             antialiased texture lookup.
    /// * nchannels
    ///             The number of channels of data to retrieve into `result`
    ///             (e.g., 1 for a single value, 3 for an RGB triple, etc.).
    /// * result[]
    ///             The result of the filtered texture lookup will be placed
    ///             into `result[0..nchannels-1]`.
    /// * dresultds/dresultdt/dresultdr
    ///             If non-null, these designate storage locations for the
    ///             derivatives of result, i.e., the rate of change per unit
    ///             s, t, and r, respectively, of the filtered texture. If
    ///             supplied, they must allow for `nchannels` of storage.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if the file was not found or could not be read
    ///
    /// # Panics
    /// * If the sizes of `result`, `dresultds` and `dresultdt` do not match
    /// * If the length of `result` is not representable as an i32
    ///
    pub fn texture3d<V: Vec3<f32>>(
        &mut self,
        filename: UString,
        options: &mut TextureOpt,
        p: &V,
        dpdx: &V,
        dpdy: &V,
        dpdz: &V,
        result: &mut [f32],
        dresultds: Option<&mut [f32]>,
        dresultdt: Option<&mut [f32]>,
        dresultdr: Option<&mut [f32]>,
    ) -> Result<()> {
        let mut ok = false;

        unsafe {
            sys::OIIO_TextureSystem_texture3d(
                self.0,
                &mut ok,
                filename.0,
                options,
                p as *const V as *const sys::Imath_V3f_t,
                dpdx as *const V as *const sys::Imath_V3f_t,
                dpdy as *const V as *const sys::Imath_V3f_t,
                dpdz as *const V as *const sys::Imath_V3f_t,
                result
                    .len()
                    .try_into()
                    .expect("result.len is not representable as i32"),
                result.as_mut_ptr(),
                if let Some(s) = dresultds {
                    s.as_mut_ptr()
                } else {
                    std::ptr::null_mut()
                },
                if let Some(s) = dresultdt {
                    s.as_mut_ptr()
                } else {
                    std::ptr::null_mut()
                },
                if let Some(s) = dresultdr {
                    s.as_mut_ptr()
                } else {
                    std::ptr::null_mut()
                },
            );
        }

        if ok {
            Ok(())
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }

    /// Perform a filtered 3D volumetric texture lookup on a position
    /// centered at 3D position `P` (with given differentials) from the
    /// texture identified by `filename`, and using relevant texture
    /// `options`.  The filtered results will be stored in
    /// `result`.
    ///
    /// The `P` coordinate and `dPdx`, `dPdy`, and `dPdz` derivatives are
    /// assumed to be in some kind of common global coordinate system
    /// (usually "world" space) and will be automatically transformed into
    /// volume local coordinates, if such a transformation is specified in
    /// the volume file itself.
    ///
    /// * filename
    ///             The name of the texture.
    /// * options
    ///     Fields within `options` that are honored for 3D texture lookups
    ///     include the following:
    ///     - `int firstchannel` :
    ///             The index of the first channel to look up from the texture.
    ///     - `int subimage / ustring subimagename` :
    ///             The subimage or field within the volume, specified by
    ///             either by name (if non-empty) or index. This will be
    ///             ignored if the file does not have multiple subimages or
    ///             separate per-face textures.
    ///     - `Wrap swrap, twrap, rwrap` :
    ///             Specify the *wrap mode* for each direction, one of:
    ///             `WrapBlack`, `WrapClamp`, `WrapPeriodic`, `WrapMirror`,
    ///             or `WrapDefault`.
    ///     - `float swidth, twidth, rwidth` :
    ///             For each direction, gives a multiplier for the derivatives.
    ///     - `float sblur, tblur, rblur` :
    ///             For each direction, specifies an additional amount of
    ///             pre-blur to apply to the texture (*after* derivatives
    ///             are taken into account), expressed as a portion of the
    ///             width of the texture.
    ///     - `float fill` :
    ///             Specifies the value that will be used for any color
    ///             channels that are requested but not found in the file.
    ///             For example, if you perform a 4-channel lookup on a
    ///             3-channel texture, the last channel will get the fill
    ///             value.  (Note: this behavior is affected by the
    ///             `"gray_to_rgb"` TextureSystem attribute.
    ///     - `const float *missingcolor` :
    ///             If not `nullptr`, specifies the color that will be
    ///             returned for missing or broken textures (rather than
    ///             being an error).
    ///     - `float time` :
    ///             A time value to use if the volume texture specifies a
    ///             time-varying local transformation (default: 0).
    /// * P
    ///             The 2D texture coordinates.
    /// * dPdx/dPdy/dPdz
    ///             The differentials of `P`. We assume that this lookup
    ///             will be part of an image that has pixel coordinates `x`
    ///             and `y` and depth `z`. By knowing how `P` changes from
    ///             pixel to pixel in the final image, and as we step in *z*
    ///             depth, we can properly *filter* or antialias the texture
    ///             lookups.  This information is given via derivatives
    ///             `dPdx`, `dPdy`, and `dPdz` that define the changes in
    ///             `P` per unit of `x`, `y`, and `z`, respectively.  If it
    ///             is impossible to know the derivatives, you may pass 0
    ///             for them, but in that case you will not receive an
    ///             antialiased texture lookup.
    /// * nchannels
    ///             The number of channels of data to retrieve into `result`
    ///             (e.g., 1 for a single value, 3 for an RGB triple, etc.).
    /// * result[]
    ///             The result of the filtered texture lookup will be placed
    ///             into `result[0..nchannels-1]`.
    /// * dresultds/dresultdt/dresultdr
    ///             If non-null, these designate storage locations for the
    ///             derivatives of result, i.e., the rate of change per unit
    ///             s, t, and r, respectively, of the filtered texture. If
    ///             supplied, they must allow for `nchannels` of storage.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if the file was not found or could not be read
    ///
    /// # Panics
    /// * If the sizes of `result`, `dresultds` and `dresultdt` do not match
    /// * If the length of `result` is not representable as an i32
    ///
    pub fn texture3d_with_handle<V: Vec3<f32>>(
        &mut self,
        handle: &TextureHandle,
        per_thread_info: Option<&Perthread>,
        options: &mut TextureOpt,
        p: &V,
        dpdx: &V,
        dpdy: &V,
        dpdz: &V,
        result: &mut [f32],
        dresultds: Option<&mut [f32]>,
        dresultdt: Option<&mut [f32]>,
        dresultdr: Option<&mut [f32]>,
    ) -> Result<()> {
        let mut ok = false;

        unsafe {
            sys::OIIO_TextureSystem_texture3d_with_handle(
                self.0,
                &mut ok,
                handle.ptr,
                if let Some(p) = per_thread_info {
                    p.0
                } else {
                    std::ptr::null_mut()
                },
                options,
                p as *const V as *const sys::Imath_V3f_t,
                dpdx as *const V as *const sys::Imath_V3f_t,
                dpdy as *const V as *const sys::Imath_V3f_t,
                dpdz as *const V as *const sys::Imath_V3f_t,
                result
                    .len()
                    .try_into()
                    .expect("result.len is not representable as i32"),
                result.as_mut_ptr(),
                if let Some(s) = dresultds {
                    s.as_mut_ptr()
                } else {
                    std::ptr::null_mut()
                },
                if let Some(s) = dresultdt {
                    s.as_mut_ptr()
                } else {
                    std::ptr::null_mut()
                },
                if let Some(s) = dresultdr {
                    s.as_mut_ptr()
                } else {
                    std::ptr::null_mut()
                },
            );
        }

        if ok {
            Ok(())
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }

    /// Perform a shadow lookup for a single position `p`, returning a tuple of
    /// the result and its s and t derivatives.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if the file was not found or could not be read
    ///
    /// # Panics
    /// * If the sizes of `result`, `dresultds` and `dresultdt` do not match
    /// * If the length of `result` is not representable as an i32
    ///
    pub fn shadow<V: Vec3<f32>>(
        &mut self,
        filename: UString,
        options: &mut TextureOpt,
        p: &V,
        dpdx: &V,
        dpdy: &V,
    ) -> Result<(f32, f32, f32)> {
        let mut ok = false;

        let mut result = 0.0f32;
        let mut dresultds = 0.0f32;
        let mut dresultdt = 0.0f32;

        unsafe {
            sys::OIIO_TextureSystem_shadow(
                self.0,
                &mut ok,
                filename.0,
                options,
                p as *const V as *const sys::Imath_V3f_t,
                dpdx as *const V as *const sys::Imath_V3f_t,
                dpdy as *const V as *const sys::Imath_V3f_t,
                &mut result,
                &mut dresultds,
                &mut dresultdt,
            );
        }

        if ok {
            Ok((result, dresultds, dresultdt))
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }

    /// Perform a shadow lookup for a single position `p`, returning a tuple of
    /// the result and its s and t derivatives.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if the file was not found or could not be read
    ///
    /// # Panics
    /// * If the sizes of `result`, `dresultds` and `dresultdt` do not match
    /// * If the length of `result` is not representable as an i32
    ///
    pub fn shadow_with_handle<V: Vec3<f32>>(
        &mut self,
        handle: &TextureHandle,
        per_thread_info: Option<&Perthread>,
        options: &mut TextureOpt,
        p: &V,
        dpdx: &V,
        dpdy: &V,
    ) -> Result<(f32, f32, f32)> {
        let mut ok = false;

        let mut result = 0.0f32;
        let mut dresultds = 0.0f32;
        let mut dresultdt = 0.0f32;

        unsafe {
            sys::OIIO_TextureSystem_shadow_with_handle(
                self.0,
                &mut ok,
                handle.ptr,
                if let Some(p) = per_thread_info {
                    p.0
                } else {
                    std::ptr::null_mut()
                },
                options,
                p as *const V as *const sys::Imath_V3f_t,
                dpdx as *const V as *const sys::Imath_V3f_t,
                dpdy as *const V as *const sys::Imath_V3f_t,
                &mut result,
                &mut dresultds,
                &mut dresultdt,
            );
        }

        if ok {
            Ok((result, dresultds, dresultdt))
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }

    /// Perform a filtered directional environment map lookup in the
    /// direction of vector `R`, from the texture identified by `filename`,
    /// and using relevant texture `options`.  The filtered results will be
    /// stored in `result[]`.
    ///
    /// * filename
    ///             The name of the texture.
    /// * options
    ///     Fields within `options` that are honored for environment lookups
    ///     include the following:
    ///     - `int firstchannel` :
    ///             The index of the first channel to look up from the texture.
    ///     - `int subimage / ustring subimagename` :
    ///             The subimage or face within the file, specified by
    ///             either by name (if non-empty) or index. This will be
    ///             ignored if the file does not have multiple subimages or
    ///             separate per-face textures.
    ///     - `float swidth, twidth` :
    ///             For each direction, gives a multiplier for the
    ///             derivatives.
    ///     - `float sblur, tblur` :
    ///             For each direction, specifies an additional amount of
    ///             pre-blur to apply to the texture (*after* derivatives
    ///             are taken into account), expressed as a portion of the
    ///             width of the texture.
    ///     - `float fill` :
    ///             Specifies the value that will be used for any color
    ///             channels that are requested but not found in the file.
    ///             For example, if you perform a 4-channel lookup on a
    ///             3-channel texture, the last channel will get the fill
    ///             value.  (Note: this behavior is affected by the
    ///             `"gray_to_rgb"` TextureSystem attribute.
    ///     - `const float *missingcolor` :
    ///             If not `nullptr`, specifies the color that will be
    ///             returned for missing or broken textures (rather than
    ///             being an error).
    /// * R
    ///             The direction vector to look up.
    /// * dRdx/dRdy
    ///             The differentials of `R` with respect to image
    ///             coordinates x and y.
    /// * nchannels
    ///             The number of channels of data to retrieve into `result`
    ///             (e.g., 1 for a single value, 3 for an RGB triple, etc.).
    /// * result[]
    ///             The result of the filtered texture lookup will be placed
    ///             into `result[0..nchannels-1]`.
    /// * dresultds/dresultdt
    ///             If non-null, these designate storage locations for the
    ///             derivatives of result, i.e., the rate of change per unit
    ///             s and t, respectively, of the filtered texture. If
    ///             supplied, they must allow for `nchannels` of storage.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if the file was not found or could not be read
    ///
    /// # Panics
    /// * If the sizes of `result`, `dresultds` and `dresultdt` do not match
    /// * If the length of `result` is not representable as an i32
    ///
    pub fn environment<V: Vec3<f32>>(
        &mut self,
        filename: UString,
        options: &mut TextureOpt,
        r: &V,
        drdx: &V,
        drdy: &V,
        result: &mut [f32],
        dresultds: Option<&mut [f32]>,
        dresultdt: Option<&mut [f32]>,
    ) -> Result<()> {
        let mut ok = false;

        unsafe {
            sys::OIIO_TextureSystem_environment(
                self.0,
                &mut ok,
                filename.0,
                options,
                r as *const V as *const sys::Imath_V3f_t,
                drdx as *const V as *const sys::Imath_V3f_t,
                drdy as *const V as *const sys::Imath_V3f_t,
                result
                    .len()
                    .try_into()
                    .expect("result.len is not representable as i32"),
                result.as_mut_ptr(),
                if let Some(s) = dresultds {
                    s.as_mut_ptr()
                } else {
                    std::ptr::null_mut()
                },
                if let Some(s) = dresultdt {
                    s.as_mut_ptr()
                } else {
                    std::ptr::null_mut()
                },
            );
        }

        if ok {
            Ok(())
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }

    /// Perform a filtered directional environment map lookup in the
    /// direction of vector `R`, from the texture identified by `filename`,
    /// and using relevant texture `options`.  The filtered results will be
    /// stored in `result[]`.
    ///
    /// * filename
    ///             The name of the texture.
    /// * options
    ///     Fields within `options` that are honored for environment lookups
    ///     include the following:
    ///     - `int firstchannel` :
    ///             The index of the first channel to look up from the texture.
    ///     - `int subimage / ustring subimagename` :
    ///             The subimage or face within the file, specified by
    ///             either by name (if non-empty) or index. This will be
    ///             ignored if the file does not have multiple subimages or
    ///             separate per-face textures.
    ///     - `float swidth, twidth` :
    ///             For each direction, gives a multiplier for the
    ///             derivatives.
    ///     - `float sblur, tblur` :
    ///             For each direction, specifies an additional amount of
    ///             pre-blur to apply to the texture (*after* derivatives
    ///             are taken into account), expressed as a portion of the
    ///             width of the texture.
    ///     - `float fill` :
    ///             Specifies the value that will be used for any color
    ///             channels that are requested but not found in the file.
    ///             For example, if you perform a 4-channel lookup on a
    ///             3-channel texture, the last channel will get the fill
    ///             value.  (Note: this behavior is affected by the
    ///             `"gray_to_rgb"` TextureSystem attribute.
    ///     - `const float *missingcolor` :
    ///             If not `nullptr`, specifies the color that will be
    ///             returned for missing or broken textures (rather than
    ///             being an error).
    /// * R
    ///             The direction vector to look up.
    /// * dRdx/dRdy
    ///             The differentials of `R` with respect to image
    ///             coordinates x and y.
    /// * nchannels
    ///             The number of channels of data to retrieve into `result`
    ///             (e.g., 1 for a single value, 3 for an RGB triple, etc.).
    /// * result[]
    ///             The result of the filtered texture lookup will be placed
    ///             into `result[0..nchannels-1]`.
    /// * dresultds/dresultdt
    ///             If non-null, these designate storage locations for the
    ///             derivatives of result, i.e., the rate of change per unit
    ///             s and t, respectively, of the filtered texture. If
    ///             supplied, they must allow for `nchannels` of storage.
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if the file was not found or could not be read
    ///
    /// # Panics
    /// * If the sizes of `result`, `dresultds` and `dresultdt` do not match
    /// * If the length of `result` is not representable as an i32
    ///
    pub fn environment_with_handle<V: Vec3<f32>>(
        &mut self,
        handle: &TextureHandle,
        per_thread_info: Option<&Perthread>,
        options: &mut TextureOpt,
        r: &V,
        drdx: &V,
        drdy: &V,
        result: &mut [f32],
        dresultds: Option<&mut [f32]>,
        dresultdt: Option<&mut [f32]>,
    ) -> Result<()> {
        let mut ok = false;

        unsafe {
            sys::OIIO_TextureSystem_environment_with_handle(
                self.0,
                &mut ok,
                handle.ptr,
                if let Some(p) = per_thread_info {
                    p.0
                } else {
                    std::ptr::null_mut()
                },
                options,
                r as *const V as *const sys::Imath_V3f_t,
                drdx as *const V as *const sys::Imath_V3f_t,
                drdy as *const V as *const sys::Imath_V3f_t,
                result
                    .len()
                    .try_into()
                    .expect("result.len is not representable as i32"),
                result.as_mut_ptr(),
                if let Some(s) = dresultds {
                    s.as_mut_ptr()
                } else {
                    std::ptr::null_mut()
                },
                if let Some(s) = dresultdt {
                    s.as_mut_ptr()
                } else {
                    std::ptr::null_mut()
                },
            );
        }

        if ok {
            Ok(())
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }
}

pub const BATCH_WIDTH: usize = 16;
pub const BATCH_ALIGN: usize = BATCH_WIDTH * std::mem::size_of::<f32>();
pub const RUN_MASK_ALL: u64 = std::u64::MAX;

impl TextureSystem {
    //! Batched texture lookups

    /// Perform filtered 2D texture lookups on a batch of positions from the
    /// same texture, all at once.  The parameters `s`, `t`, `dsdx`, `dtdx`,
    /// and `dsdy`, `dtdy` are each a pointer to `[BatchWidth]` values.  The
    /// `mask` determines which of those array elements to actually compute.
    ///
    /// The float* results act like `float[nchannels][BatchWidth]`, so that
    /// effectively `result[0..BatchWidth-1]` are the "red" result for each
    /// lane, `result[BatchWidth..2*BatchWidth-1]` are the "green" results,
    /// etc. The `dresultds` and `dresultdt` should either both be provided,
    /// or else both be nullptr (meaning no derivative results are
    /// required).
    ///
    /// * filename
    ///             The name of the texture.
    /// * options
    ///             A TextureOptBatch containing texture lookup options.
    ///             This is conceptually the same as a TextureOpt, but the
    ///             following fields are arrays of `[BatchWidth]` elements:
    ///             sblur, tblur, swidth, twidth. The other fields are, as
    ///             with TextureOpt, ordinary scalar values.
    /// * mask
    ///             A bit-field designating which "lanes" should be
    ///             computed: if `mask & (1<<i)` is nonzero, then results
    ///             should be computed and stored for `result[...][i]`.
    /// * s/t
    ///             Pointers to the 2D texture coordinates, each as a
    ///             `float[BatchWidth]`.
    /// * dsdx/dtdx/dsdy/dtdy
    ///             The differentials of s and t relative to canonical
    ///             directions x and y, each as a `float[BatchWidth]`.
    /// * result[]
    ///             The result of the filtered texture lookup will be placed
    ///             here, as `float [nchannels][BatchWidth]`. (Note the
    ///             "SOA" data layout.)
    /// * dresultds/dresultdt
    ///             If non-null, these designate storage locations for the
    ///             derivatives of result, and like `result` are in SOA
    ///             layout: `float [nchannels][BatchWidth]`
    /// @returns
    ///             `true` upon success, or `false` if the file was not
    ///             found or could not be opened by any available ImageIO
    ///             plugin.
    ///
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if the file was not found or could not be read
    ///
    /// # Panics
    /// * If the sizes of `result`, `dresultds` and `dresultdt` do not match
    /// * If the length of `result` is not representable as an i32
    ///
    pub fn texture_batch(
        &mut self,
        filename: UString,
        options: &mut TextureOptBatch,
        s: &[f32],
        t: &[f32],
        dsdx: &[f32],
        dtdx: &[f32],
        dsdy: &[f32],
        dtdy: &[f32],
        result: &mut [f32],
        dresultds: Option<&mut [f32]>,
        dresultdt: Option<&mut [f32]>,
    ) -> Result<()> {
        let mut ok = false;

        let num_channels = result.len() / BATCH_WIDTH;

        if s.len() != BATCH_WIDTH
            || t.len() != BATCH_WIDTH
            || dsdx.len() != BATCH_WIDTH
            || dtdx != BATCH_WIDTH
            || dsdy != BATCH_WIDTH
            || dtdy != BATCH_WIDTH
        {
            panic!("input coordinates or their derivatives are not BATCH_WIDTH in length");
        }

        if let Some(dresultds) = dresultds {
            if result.len() != dresultds.len() {
                panic!("dresultds length  != result length");
            }
        }

        if let Some(dresultdt) = dresultdt {
            if result.len() != dresultdt.len() {
                panic!("dresultdt length  != result length");
            }
        }

        unsafe {
            sys::OIIO_TextureSystem_texture_batch(
                self.0,
                &mut ok,
                filename.0,
                options,
                mask,
                s.as_ptr(),
                t.as_ptr(),
                dsdx.as_ptr(),
                dtdx.as_ptr(),
                dsdy.as_ptr(),
                dtdy.as_ptr(),
                result
                    .len()
                    .try_into()
                    .expect("result.len not representable as i32"),
                result.as_mut_ptr(),
                if let Some(sl) = dresultds {
                    sl.as_mut_ptr()
                } else {
                    std::ptr::null_mut()
                },
                if let Some(sl) = dresultdt {
                    sl.as_mut_ptr()
                } else {
                    std::ptr::null_mut()
                },
            );
        }

        if ok {
            Ok(())
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }
}

impl TextureSystem {
    //! Errors and statistics

    /// Return the text of all pending error messages issued against this
    /// TextureSystem by the calling thread, and clear the pending error
    /// message unless `clear` is false. If no error message is pending, it
    /// will return an empty string.
    ///
    pub fn get_error(&self, clear: bool) -> String {
        let mut msg = CppString::new("");
        unsafe {
            sys::OIIO_TextureSystem_geterror(self.0, &mut msg.0, clear);
            msg.as_str().to_string()
        }
    }

    /// Returns a big string containing useful statistics about the
    /// TextureSystem operations, suitable for saving to a file or
    /// outputting to the terminal. The `level` indicates the amount of
    /// detail in the statistics, with higher numbers (up to a maximum of 5)
    /// yielding more and more esoteric information.  If `icstats` is true,
    /// the returned string will also contain all the statistics of the
    /// underlying ImageCache, but if false will only contain
    /// texture-specific statistics.
    ///
    pub fn getstats(&self, level: i32, icstats: bool) -> String {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_TextureSystem_getstats(self.0, &mut ptr, level, icstats);
        }
        CppString(ptr).as_str().to_string()
    }

    /// Reset most statistics to be as they were with a fresh TextureSystem.
    /// Caveat emptor: this does not flush the cache itelf, so the resulting
    /// statistics from the next set of texture requests will not match the
    /// number of tile reads, etc., that would have resulted from a new
    /// TextureSystem.
    ///
    pub fn reset_stats(&self) {
        unsafe {
            sys::OIIO_TextureSystem_reset_stats(self.0);
        }
    }
}

pub struct Perthread(pub(crate) *mut sys::OIIO_TextureSystem_Perthread_t);

pub struct TextureHandle<'cache> {
    pub(crate) ptr: *mut sys::OIIO_TextureSystem_TextureHandle_t,
    pub(crate) marker: PhantomData<&'cache ()>,
}
