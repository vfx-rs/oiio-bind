use crate::cppstd::CppString;
use crate::error::Error;
use crate::imagecache::ImageCache;
use crate::imageio::{
    ImageSpec, ImageSpecRef, 
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
        mask: u64,
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
            || dtdx.len() != BATCH_WIDTH
            || dsdy.len() != BATCH_WIDTH
            || dtdy.len() != BATCH_WIDTH
        {
            panic!("input coordinates or their derivatives are not BATCH_WIDTH in length");
        }

        if let Some(ref dresultds) = dresultds {
            if result.len() != dresultds.len() {
                panic!("dresultds length  != result length");
            }
        }

        if let Some(ref dresultdt) = dresultdt {
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
                num_channels
                    .try_into()
                    .expect("num channels not representable as i32"),
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
    pub fn texture_batch_with_handle(
        &mut self,
        handle: &TextureHandle,
        per_thread_info: Option<&mut Perthread>,
        options: &mut TextureOptBatch,
        mask: u64,
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
            || dtdx.len() != BATCH_WIDTH
            || dsdy.len() != BATCH_WIDTH
            || dtdy.len() != BATCH_WIDTH
        {
            panic!("input coordinates or their derivatives are not BATCH_WIDTH in length");
        }

        if let Some(ref dresultds) = dresultds {
            if result.len() != dresultds.len() {
                panic!("dresultds length  != result length");
            }
        }

        if let Some(ref dresultdt) = dresultdt {
            if result.len() != dresultdt.len() {
                panic!("dresultdt length  != result length");
            }
        }

        unsafe {
            sys::OIIO_TextureSystem_texture_batch_with_handle(
                self.0,
                &mut ok,
                handle.ptr,
                if let Some(p) = per_thread_info {
                    p.0
                } else {
                    std::ptr::null_mut()
                },
                options,
                mask,
                s.as_ptr(),
                t.as_ptr(),
                dsdx.as_ptr(),
                dtdx.as_ptr(),
                dsdy.as_ptr(),
                dtdy.as_ptr(),
                num_channels
                    .try_into()
                    .expect("num channels not representable as i32"),
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

    /// Perform filtered 3D volumetric texture lookups on a batch of
    /// positions from the same texture, all at once. The "point-like"
    /// parameters `P`, `dPdx`, `dPdy`, and `dPdz` are each a pointers to
    /// arrays of `float value[3][BatchWidth]` (or alternately like
    /// `Imath::Vec3<FloatWide>`). That is, each one points to all the *x*
    /// values for the batch, immediately followed by all the *y* values,
    /// followed by the *z* values. The `mask` determines which of those
    /// array elements to actually compute.
    ///
    /// The various results arrays are also arranged as arrays that behave
    /// as if they were declared `float result[channels][BatchWidth]`, where
    /// all the batch values for channel 0 are adjacent, followed by all the
    /// batch values for channel 1, etc.
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
    /// * P
    ///             Pointers to the 3D texture coordinates, each as a
    ///             `float[3][BatchWidth]`.
    /// * dPdx/dPdy/dPdz
    ///             The differentials of P relative to canonical directions
    ///             x, y, and z, each as a `float[3][BatchWidth]`.
    /// * nchannels
    ///             The number of channels of data to retrieve into `result`
    ///             (e.g., 1 for a single value, 3 for an RGB triple, etc.).
    /// * result[]
    ///             The result of the filtered texture lookup will be placed
    ///             here, as `float [nchannels][BatchWidth]`. (Note the
    ///             "SOA" data layout.)
    /// * dresultds/dresultdt/dresultdr
    ///             If non-null, these designate storage locations for the
    ///             derivatives of result, and like `result` are in SOA
    ///             layout: `float [nchannels][BatchWidth]`
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if the file was not found or could not be read
    ///
    /// # Panics
    /// * If the sizes of `result`, `dresultds` and `dresultdt` do not match
    /// * If the length of `result` is not representable as an i32
    ///
    pub fn texture3d_batch<V: Vec3<f32>>(
        &mut self,
        filename: UString,
        options: &mut TextureOptBatch,
        mask: u64,
        p: &[V],
        dpdx: &[V],
        dpdy: &[V],
        dpdz: &[V],
        result: &mut [f32],
        dresultds: Option<&mut [f32]>,
        dresultdt: Option<&mut [f32]>,
        dresultdr: Option<&mut [f32]>,
    ) -> Result<()> {
        let mut ok = false;

        let num_channels = result.len() / BATCH_WIDTH;

        if p.len() != BATCH_WIDTH
            || dpdx.len() != BATCH_WIDTH
            || dpdy.len() != BATCH_WIDTH
            || dpdz.len() != BATCH_WIDTH
        {
            panic!("input coordinates or their derivatives are not BATCH_WIDTH in length");
        }

        if let Some(ref dresultds) = dresultds {
            if result.len() != dresultds.len() {
                panic!("dresultds length  != result length");
            }
        }

        if let Some(ref dresultdt) = dresultdt {
            if result.len() != dresultdt.len() {
                panic!("dresultdt length  != result length");
            }
        }

        if let Some(ref dresultdr) = dresultdr {
            if result.len() != dresultdr.len() {
                panic!("dresultdt length  != result length");
            }
        }

        unsafe {
            sys::OIIO_TextureSystem_texture3d_batch(
                self.0,
                &mut ok,
                filename.0,
                options,
                mask,
                p.as_ptr() as *const f32,
                dpdx.as_ptr() as *const f32,
                dpdy.as_ptr() as *const f32,
                dpdz.as_ptr() as *const f32,
                num_channels
                    .try_into()
                    .expect("num channels is not representable as i32"),
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

    /// Perform filtered 3D volumetric texture lookups on a batch of
    /// positions from the same texture, all at once. The "point-like"
    /// parameters `P`, `dPdx`, `dPdy`, and `dPdz` are each a pointers to
    /// arrays of `float value[3][BatchWidth]` (or alternately like
    /// `Imath::Vec3<FloatWide>`). That is, each one points to all the *x*
    /// values for the batch, immediately followed by all the *y* values,
    /// followed by the *z* values. The `mask` determines which of those
    /// array elements to actually compute.
    ///
    /// The various results arrays are also arranged as arrays that behave
    /// as if they were declared `float result[channels][BatchWidth]`, where
    /// all the batch values for channel 0 are adjacent, followed by all the
    /// batch values for channel 1, etc.
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
    /// * P
    ///             Pointers to the 3D texture coordinates, each as a
    ///             `float[3][BatchWidth]`.
    /// * dPdx/dPdy/dPdz
    ///             The differentials of P relative to canonical directions
    ///             x, y, and z, each as a `float[3][BatchWidth]`.
    /// * nchannels
    ///             The number of channels of data to retrieve into `result`
    ///             (e.g., 1 for a single value, 3 for an RGB triple, etc.).
    /// * result[]
    ///             The result of the filtered texture lookup will be placed
    ///             here, as `float [nchannels][BatchWidth]`. (Note the
    ///             "SOA" data layout.)
    /// * dresultds/dresultdt/dresultdr
    ///             If non-null, these designate storage locations for the
    ///             derivatives of result, and like `result` are in SOA
    ///             layout: `float [nchannels][BatchWidth]`
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if the file was not found or could not be read
    ///
    /// # Panics
    /// * If the sizes of `result`, `dresultds` and `dresultdt` do not match
    /// * If the length of `result` is not representable as an i32
    ///
    pub fn texture3d_batch_with_handle<V: Vec3<f32>>(
        &mut self,
        handle: &TextureHandle,
        per_thread_info: Option<&Perthread>,
        options: &mut TextureOptBatch,
        mask: u64,
        p: &[V],
        dpdx: &[V],
        dpdy: &[V],
        dpdz: &[V],
        result: &mut [f32],
        dresultds: Option<&mut [f32]>,
        dresultdt: Option<&mut [f32]>,
        dresultdr: Option<&mut [f32]>,
    ) -> Result<()> {
        let mut ok = false;

        let num_channels = result.len() / BATCH_WIDTH;

        if p.len() != BATCH_WIDTH
            || dpdx.len() != BATCH_WIDTH
            || dpdy.len() != BATCH_WIDTH
            || dpdz.len() != BATCH_WIDTH
        {
            panic!("input coordinates or their derivatives are not BATCH_WIDTH in length");
        }

        if let Some(ref dresultds) = dresultds {
            if result.len() != dresultds.len() {
                panic!("dresultds length  != result length");
            }
        }

        if let Some(ref dresultdt) = dresultdt {
            if result.len() != dresultdt.len() {
                panic!("dresultdt length  != result length");
            }
        }

        if let Some(ref dresultdr) = dresultdr {
            if result.len() != dresultdr.len() {
                panic!("dresultdt length  != result length");
            }
        }

        unsafe {
            sys::OIIO_TextureSystem_texture3d_batch_with_handle(
                self.0,
                &mut ok,
                handle.ptr,
                if let Some(p) = per_thread_info {
                    p.0
                } else {
                    std::ptr::null_mut()
                },
                options,
                mask,
                p.as_ptr() as *const f32,
                dpdx.as_ptr() as *const f32,
                dpdy.as_ptr() as *const f32,
                dpdz.as_ptr() as *const f32,
                num_channels
                    .try_into()
                    .expect("num channels is not representable as i32"),
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

    /// Batched shadow lookups
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if the file was not found or could not be read
    ///
    /// # Panics
    /// * If the sizes of `result`, `dresultds` and `dresultdt` do not match
    /// * If the length of `result` is not representable as an i32
    ///
    pub fn shadow_batch<V: Vec3<f32>>(
        &mut self,
        filename: UString,
        options: &mut TextureOptBatch,
        mask: u64,
        p: &[V],
        dpdx: &[V],
        dpdy: &[V],
        result: &mut [f32],
        dresultds: Option<&mut [f32]>,
        dresultdt: Option<&mut [f32]>,
    ) -> Result<()> {
        let mut ok = false;

        if p.len() != BATCH_WIDTH
            || result.len() != BATCH_WIDTH
            || dpdx.len() != BATCH_WIDTH
            || dpdy.len() != BATCH_WIDTH
        {
            panic!("input coordinates or their derivatives, or the result slice are not BATCH_WIDTH in length");
        }

        if let Some(ref dresultds) = dresultds {
            if result.len() != dresultds.len() {
                panic!("dresultds length  != result length");
            }
        }

        if let Some(ref dresultdt) = dresultdt {
            if result.len() != dresultdt.len() {
                panic!("dresultdt length  != result length");
            }
        }

        unsafe {
            sys::OIIO_TextureSystem_shadow_batch(
                self.0,
                &mut ok,
                filename.0,
                options,
                mask,
                p.as_ptr() as *const f32,
                dpdx.as_ptr() as *const f32,
                dpdy.as_ptr() as *const f32,
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

    /// Batched shadow lookups
    ///
    /// # Errors
    /// * [`Error::Oiio`] - if the file was not found or could not be read
    ///
    /// # Panics
    /// * If the sizes of `result`, `dresultds` and `dresultdt` do not match
    /// * If the length of `result` is not representable as an i32
    ///
    pub fn shadow_batch_with_handle<V: Vec3<f32>>(
        &mut self,
        handle: &TextureHandle,
        per_thread_info: Option<&Perthread>,
        options: &mut TextureOptBatch,
        mask: u64,
        p: &[V],
        dpdx: &[V],
        dpdy: &[V],
        result: &mut [f32],
        dresultds: Option<&mut [f32]>,
        dresultdt: Option<&mut [f32]>,
    ) -> Result<()> {
        let mut ok = false;

        if p.len() != BATCH_WIDTH
            || result.len() != BATCH_WIDTH
            || dpdx.len() != BATCH_WIDTH
            || dpdy.len() != BATCH_WIDTH
        {
            panic!("input coordinates or their derivatives, or the result slice are not BATCH_WIDTH in length");
        }

        if let Some(ref dresultds) = dresultds {
            if result.len() != dresultds.len() {
                panic!("dresultds length  != result length");
            }
        }

        if let Some(ref dresultdt) = dresultdt {
            if result.len() != dresultdt.len() {
                panic!("dresultdt length  != result length");
            }
        }

        unsafe {
            sys::OIIO_TextureSystem_shadow_batch_with_handle(
                self.0,
                &mut ok,
                handle.ptr,
                if let Some(p) = per_thread_info {
                    p.0
                } else {
                    std::ptr::null_mut()
                },
                options,
                mask,
                p.as_ptr() as *const f32,
                dpdx.as_ptr() as *const f32,
                dpdy.as_ptr() as *const f32,
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
    pub fn environment_batch<V: Vec3<f32>>(
        &mut self,
        filename: UString,
        options: &mut TextureOptBatch,
        mask: u64,
        r: &[V],
        drdx: &[V],
        drdy: &[V],
        result: &mut [f32],
        dresultds: Option<&mut [f32]>,
        dresultdt: Option<&mut [f32]>,
    ) -> Result<()> {
        let mut ok = false;

        let num_channels = result.len() / BATCH_WIDTH;

        if r.len() != BATCH_WIDTH
            || drdx.len() != BATCH_WIDTH
            || drdy.len() != BATCH_WIDTH
        {
            panic!("input coordinates or their derivatives, or the result slice are not BATCH_WIDTH in length");
        }

        if let Some(ref dresultds) = dresultds {
            if result.len() != dresultds.len() {
                panic!("dresultds length  != result length");
            }
        }

        if let Some(ref dresultdt) = dresultdt {
            if result.len() != dresultdt.len() {
                panic!("dresultdt length  != result length");
            }
        }

        unsafe {
            sys::OIIO_TextureSystem_environment_batch(
                self.0,
                &mut ok,
                filename.0,
                options,
                mask,
                r.as_ptr() as *const f32,
                drdx.as_ptr() as *const f32,
                drdy.as_ptr() as *const f32,
                num_channels
                    .try_into()
                    .expect("num_channels is not representable as i32"),
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
    pub fn environment_batch_with_handle<V: Vec3<f32>>(
        &mut self,
        handle: &TextureHandle,
        per_thread_info: Option<&Perthread>,
        options: &mut TextureOptBatch,
        mask: u64,
        r: &[V],
        drdx: &[V],
        drdy: &[V],
        result: &mut [f32],
        dresultds: Option<&mut [f32]>,
        dresultdt: Option<&mut [f32]>,
    ) -> Result<()> {
        let mut ok = false;

        let num_channels = result.len() / BATCH_WIDTH;

        if r.len() != BATCH_WIDTH
            || drdx.len() != BATCH_WIDTH
            || drdy.len() != BATCH_WIDTH
        {
            panic!("input coordinates or their derivatives, or the result slice are not BATCH_WIDTH in length");
        }

        if let Some(ref dresultds) = dresultds {
            if result.len() != dresultds.len() {
                panic!("dresultds length  != result length");
            }
        }

        if let Some(ref dresultdt) = dresultdt {
            if result.len() != dresultdt.len() {
                panic!("dresultdt length  != result length");
            }
        }

        unsafe {
            sys::OIIO_TextureSystem_environment_batch_with_handle(
                self.0,
                &mut ok,
                handle.ptr,
                if let Some(p) = per_thread_info {
                    p.0
                } else {
                    std::ptr::null_mut()
                },
                options,
                mask,
                r.as_ptr() as *const f32,
                drdx.as_ptr() as *const f32,
                drdy.as_ptr() as *const f32,
                num_channels
                    .try_into()
                    .expect("num_channels is not representable as i32"),
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

impl TextureSystem {
    //! Texture metadata and raw texels

    /// Given possibly-relative 'filename', resolve it using the search
    /// path rules and return the full resolved filename.
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
            sys::OIIO_TextureSystem_resolve_filename(
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
    /// # Parameters
    ///
    /// * filename
    ///             The name of the image.
    /// * subimage/miplevel
    ///             The subimage and MIP level to query.
    /// * dataname
    ///             The name of the metadata to retrieve.
    /// * data
    ///             Pointer to the caller-owned memory where the values
    ///             should be stored. It is the caller's responsibility to
    ///             ensure that `data` points to a large enough storage area
    ///             to accommodate the `datatype` requested.
    ///
    /// # Errors
    /// * [`Error::InvalidHandle`] - if the combination of handle, subimage and miplevel does not
    /// refer to a valid image that can be read
    ///
    pub fn get_texture_info<A: AttributeMetadata>(
        &self,
        filename: UString,
        subimage: i32,
        dataname: UString,
        data: A,
    ) -> Result<A> {
        let mut ok = false;
        let mut data = data;
        unsafe {
            sys::OIIO_TextureSystem_get_texture_info(
                self.0,
                &mut ok,
                filename.0,
                subimage,
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

    /// A more efficient variety of [`get_texture_info()`](ImageCache::get_image_info) for cases where you
    /// can use a [`TextureHandle`] to specify the image and optionally have a
    /// [`Perthread`] for the calling thread.
    ///
    /// # Errors
    /// * [`Error::InvalidHandle`] - if the combination of handle, subimage and miplevel does not
    /// refer to a valid image that can be read
    ///
    pub fn get_texture_info_with_handle<A: AttributeMetadata>(
        &self,
        handle: &TextureHandle,
        thread_info: Option<&Perthread>,
        subimage: i32,
        dataname: UString,
        data: A,
    ) -> Result<A> {
        let mut ok = false;
        let mut data = data;
        unsafe {
            sys::OIIO_TextureSystem_get_texture_info_with_handle(
                self.0,
                &mut ok,
                handle.ptr,
                if let Some(p) = thread_info {
                    p.0
                } else {
                    std::ptr::null_mut()
                },
                subimage,
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
        handle: &'h TextureHandle,
        thread_info: Option<&Perthread>,
        subimage: i32,
    ) -> Result<ImageSpecRef<'h>> {
        let mut ptr = std::ptr::null();
        sys::OIIO_TextureSystem_imagespec_with_handle(
            self.0,
            &mut ptr,
            handle.ptr,
            if let Some(p) = thread_info {
                p.0
            } else {
                std::ptr::null_mut()
            },
            subimage,
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
        handle: &TextureHandle,
        thread_info: Option<&Perthread>,
        subimage: i32,
    ) -> Result<ImageSpec> {
        let spec = ImageSpec::from_typedesc(TypeDesc::UNKNOWN);
        let mut result = false;
        unsafe {
            sys::OIIO_TextureSystem_get_imagespec_with_handle(
                self.0,
                &mut result,
                handle.ptr,
                if let Some(p) = thread_info {
                    p.0
                } else {
                    std::ptr::null_mut()
                },
                subimage,
                spec.0,
            );
        }

        if result {
            Ok(spec)
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }

    pub unsafe fn get_texels<T: Pixel>(
        &self,
        handle: &TextureHandle,
        thread_info: Option<&Perthread>,
        options: &mut TextureOpt,
        miplevel: usize,
        xbegin: i32,
        xend: i32,
        ybegin: i32,
        yend: i32,
        zbegin: i32,
        zend: i32,
        chbegin: usize,
        chend: usize,
        data: &[T],
    ) -> Result<()> {
        let mut ok = false;

        let len = ((xend - xbegin) * (yend - ybegin) * (zend - zbegin))
            as usize
            * (chend - chbegin);

        if data.len() < len {
            panic!("data slice is not beg enough to hold requested texels");
        }

        sys::OIIO_TextureSystem_get_texels_with_handle(
            self.0,
            &mut ok,
            handle.ptr,
            if let Some(p) = thread_info {
                p.0
            } else {
                std::ptr::null_mut()
            },
            options,
            miplevel
                .try_into()
                .expect("miplevel is not representable as i32"),
            xbegin,
            xend,
            ybegin,
            yend,
            zbegin,
            zend,
            chbegin
                .try_into()
                .expect("chbegin is not representable as i32"),
            chend.try_into().expect("chend is not representable as i32"),
            T::FORMAT.into(),
            data.as_ptr() as *mut c_void,
        );

        if ok {
            Ok(())
        } else {
            Err(Error::Oiio(self.get_error(true)))
        }
    }
}

impl TextureSystem {
    //! Methods for UDIM patterns

    /// Is the filename a UDIM pattern?
    ///
    pub fn is_udim(&self, filename: UString) -> bool {
        let mut result = false;
        unsafe {
            sys::OIIO_TextureSystem_is_udim(self.0, &mut result, filename.0);
        }

        result
    }

    /// Does the handle refer to a file that's a UDIM pattern?
    ///
    pub fn is_udim_with_handle(&self, handle: &TextureHandle) -> bool {
        let mut result = false;
        unsafe {
            sys::OIIO_TextureSystem_is_udim_with_handle(
                self.0,
                &mut result,
                handle.ptr,
            );
        }

        result
    }

    /// For a UDIM filename pattern and texture coordinates, return the
    /// TextureHandle pointer for the concrete tile file it refers to, or
    /// nullptr if there is no corresponding tile (udim sets are allowed to
    /// be sparse).
    ///
    pub fn resolve_udim(
        &self,
        udim_pattern: UString,
        s: f32,
        t: f32,
    ) -> TextureHandle {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_TextureSystem_resolve_udim(
                self.0,
                &mut ptr,
                udim_pattern.0,
                s,
                t,
            );
        }

        TextureHandle {
            ptr,
            marker: PhantomData,
        }
    }

    /// For a UDIM handle and texture coordinates, return the
    /// TextureHandle pointer for the concrete tile file it refers to, or
    /// nullptr if there is no corresponding tile (udim sets are allowed to
    /// be sparse).
    ///
    pub fn resolve_udim_with_handle(
        &self,
        handle: &TextureHandle,
        thread_info: Option<&mut Perthread>,
        s: f32,
        t: f32,
    ) -> TextureHandle {
        let mut ptr = std::ptr::null_mut();
        unsafe {
            sys::OIIO_TextureSystem_resolve_udim_with_handle(
                self.0,
                &mut ptr,
                handle.ptr,
                if let Some(p) = thread_info {
                    p.0
                } else {
                    std::ptr::null_mut()
                },
                s,
                t,
            );
        }

        TextureHandle {
            ptr,
            marker: PhantomData,
        }
    }

    /// Produce a full inventory of the set of concrete files comprising the
    /// UDIM set specified by `udimpattern`.  The apparent number of texture
    /// atlas tiles in the u and v directions will be written to `nutiles`
    /// and `nvtiles`, respectively. The vector `filenames` will be sized
    /// to `nutiles * nvtiles` and filled with the the names of the concrete
    /// files comprising the atlas, with an empty ustring corresponding to
    /// any unpopulated tiles (the UDIM set is allowed to be sparse). The
    /// filename list is indexed as `utile + vtile * nvtiles`.
    ///
    pub fn inventory_udim(
        &self,
        udim_pattern: UString,
    ) -> (Vec<UString>, usize, usize) {
        let mut v = std::ptr::null_mut();
        let mut nu = 0;
        let mut nv = 0;

        unsafe {
            sys::std_vector_ustring_ctor(&mut v);

            sys::OIIO_TextureSystem_inventory_udim(
                self.0,
                udim_pattern.0,
                v,
                &mut nu,
                &mut nv,
            );

            let mut len = 0;
            sys::std_vector_ustring_size(v, &mut len);
            let mut data = std::ptr::null();
            sys::std_vector_ustring_data_const(v, &mut data);

            let vec: Vec<UString> = std::slice::from_raw_parts(data, len)
                .iter()
                .map(|u| UString(*u))
                .collect();

            (vec, nu as usize, nv as usize)
        }
    }
}


impl TextureSystem {
    //! Controlling the cache
    /// Invalidate any cached information about the named file, including
    /// loaded texture tiles from that texture, and close any open file
    /// handle associated with the file. This calls
    /// `ImageCache::invalidate(filename,force)` on the underlying
    /// ImageCache.
    ///
    pub fn invalidate(&self, filename: UString, force: bool) {
        unsafe {
            sys::OIIO_TextureSystem_invalidate(
                self.0, filename.0, force,
            );
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
            sys::OIIO_TextureSystem_invalidate_all(self.0, force);
        }
    }

    /// Close any open file handles associated with a named file, but do not
    /// invalidate any image spec information or pixels associated with the
    /// files.  A client might do this in order to release OS file handle
    /// resources, or to make it safe for other processes to modify textures
    /// on disk.  This calls `ImageCache::close(force)` on the underlying
    /// ImageCache.
    ///
    pub fn close(&mut self, filename: UString) {
        unsafe {
            sys::OIIO_TextureSystem_close(
                self.0, filename.0, 
            );
        }
    }

    /// `close()` all files known to the cache.
    ///
    pub fn close_all(&mut self) {
        unsafe {
            sys::OIIO_TextureSystem_close_all(
                self.0,
            );
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
