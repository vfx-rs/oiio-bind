#include <OpenImageIO/texture.h>
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OIIO_NAMESPACE {

namespace OIIO = ::OIIO_NAMESPACE;

namespace pvt {

enum TexFormat {
    TexFormatUnknown = 0,
    TexFormatTexture = 1,
    TexFormatTexture3d = 2,
    TexFormatShadow = 3,
    TexFormatCubeFaceShadow = 4,
    TexFormatVolumeShadow = 5,
    TexFormatLatLongEnv = 6,
    TexFormatCubeFaceEnv = 7,
    TexFormatLast = 8,
};

enum EnvLayout {
    LayoutTexture = 0,
    LayoutLatLong = 1,
    LayoutCubeThreeByTwo = 2,
    LayoutCubeOneBySix = 3,
    EnvLayoutLast = 4,
};

} // namespace pvt

namespace Tex {

enum class Wrap {
    Default = 0,
    Black = 1,
    Clamp = 2,
    Periodic = 3,
    Mirror = 4,
    PeriodicPow2 = 5,
    PeriodicSharedBorder = 6,
    Last = 7,
} CPPMM_RUSTIFY_ENUM;

auto decode_wrapmode(const char* name) -> OIIO::Tex::Wrap;

CPPMM_RENAME(decode_wrapmode_ustring)
auto decode_wrapmode(OIIO::ustring name) -> OIIO::Tex::Wrap;

auto parse_wrapmodes(const char* wrapmodes, OIIO::Tex::Wrap& swrapcode,
                     OIIO::Tex::Wrap& twrapcode) -> void;

enum class MipMode {
    Default = 0,
    NoMIP = 1,
    OneLevel = 2,
    Trilinear = 3,
    Aniso = 4,
} CPPMM_RUSTIFY_ENUM;

enum class InterpMode {
    Closest = 0,
    Bilinear = 1,
    Bicubic = 2,
    SmartBicubic = 3,
} CPPMM_RUSTIFY_ENUM;

} // namespace Tex

enum RunFlagVal {
    RunFlagOff = 0,
    RunFlagOn = 255,
} CPPMM_RUSTIFY_ENUM;

struct TextureOpt {
    using BoundType = OIIO::TextureOpt;

    TextureOpt();
    TextureOpt(const OIIO::TextureOptions& opt, int index) CPPMM_IGNORE;

    static auto decode_wrapmode(const char* name) -> OIIO::TextureOpt::Wrap;

    CPPMM_RENAME(decode_wrapmode_ustring)
    static auto decode_wrapmode(OIIO::ustring name) -> OIIO::TextureOpt::Wrap;

    static auto parse_wrapmodes(const char* wrapmodes,
                                OIIO::TextureOpt::Wrap& swrapcode,
                                OIIO::TextureOpt::Wrap& twrapcode) -> void;

    TextureOpt(const OIIO::TextureOpt& rhs);
    OIIO::TextureOpt& operator=(const OIIO::TextureOpt& rhs);

    CPPMM_IGNORE
    TextureOpt(OIIO::TextureOpt&&);

    ~TextureOpt();

    enum Wrap {
        WrapDefault = 0,
        WrapBlack = 1,
        WrapClamp = 2,
        WrapPeriodic = 3,
        WrapMirror = 4,
        WrapPeriodicPow2 = 5,
        WrapPeriodicSharedBorder = 6,
        WrapLast = 7,
    };

    enum MipMode {
        MipModeDefault = 0,
        MipModeNoMIP = 1,
        MipModeOneLevel = 2,
        MipModeTrilinear = 3,
        MipModeAniso = 4,
    };

    enum InterpMode {
        InterpClosest = 0,
        InterpBilinear = 1,
        InterpBicubic = 2,
        InterpSmartBicubic = 3,
    };
} CPPMM_VALUETYPE; // struct TextureOpt

struct TextureOptBatch {
    using BoundType = OIIO::TextureOptBatch;

    TextureOptBatch();
    TextureOptBatch(const OIIO::TextureOptBatch& rhs);
    OIIO::TextureOptBatch& operator=(const OIIO::TextureOptBatch& rhs);

    CPPMM_IGNORE
    TextureOptBatch(OIIO::TextureOptBatch&&);
    ~TextureOptBatch();
} CPPMM_VALUETYPE; // struct TextureOptBatch

struct TextureSystem {
    using BoundType = OIIO::TextureSystem;

    class Perthread {
        using BoundType = OIIO::TextureSystem::Perthread;
    } CPPMM_OPAQUETYPE;

    class TextureHandle {
        using BoundType = OIIO::TextureSystem::TextureHandle;
    } CPPMM_OPAQUETYPE;

    OIIO::TextureSystem& operator=(const OIIO::TextureSystem&);

    static auto create(bool shared, OIIO::ImageCache* imagecache)
        -> OIIO::TextureSystem*;
    static auto destroy(OIIO::TextureSystem* ts, bool teardown_imagecache)
        -> void;

    bool attribute(OIIO::string_view name, OIIO::TypeDesc type,
                   const void* val);

    bool attribute(OIIO::string_view name, int val) CPPMM_RENAME(attribute_int);
    bool attribute(OIIO::string_view name, float val)
        CPPMM_RENAME(attribute_float);
    bool attribute(OIIO::string_view name, double val)
        CPPMM_RENAME(attribute_double);
    bool attribute(OIIO::string_view name, OIIO::string_view val)
        CPPMM_RENAME(attribute_string);

    bool getattribute(OIIO::string_view name, OIIO::TypeDesc type,
                      void* val) const;
    bool getattribute(OIIO::string_view name, int& val) const
        CPPMM_RENAME(getattribute_int);
    bool getattribute(OIIO::string_view name, float& val) const
        CPPMM_RENAME(getattribute_float);
    bool getattribute(OIIO::string_view name, double& val) const
        CPPMM_RENAME(getattribute_double);
    bool getattribute(OIIO::string_view name, char** val) const
        CPPMM_RENAME(getattribute_cstr);
    bool getattribute(OIIO::string_view name, std::string& val) const
        CPPMM_RENAME(getattribute_string);

    auto get_perthread_info(OIIO::TextureSystem::Perthread* thread_info)
        -> OIIO::TextureSystem::Perthread*;

    auto create_thread_info() -> OIIO::TextureSystem::Perthread*;
    auto destroy_thread_info(OIIO::TextureSystem::Perthread* threadinfo)
        -> void;
    auto get_texture_handle(OIIO::ustring filename,
                            OIIO::TextureSystem::Perthread* thread_info)
        -> OIIO::TextureSystem::TextureHandle*;

    auto good(OIIO::TextureSystem::TextureHandle* texture_handle) -> bool;

    bool texture(OIIO::ustring filename, OIIO::TextureOpt& options, float s,
                 float t, float dsdx, float dtdx, float dsdy, float dtdy,
                 int nchannels, float* result, float* dresultds,
                 float* dresultdt);

    bool texture(OIIO::TextureSystem::TextureHandle* texture_handle,
                 OIIO::TextureSystem::Perthread* thread_info,
                 OIIO::TextureOpt& options, float s, float t, float dsdx,
                 float dtdx, float dsdy, float dtdy, int nchannels,
                 float* result, float* dresultds, float* dresultdt)
        CPPMM_RENAME(texture_with_handle);

    auto texture3d(OIIO::ustring filename, OIIO::TextureOpt& options,
                   const Imath::Vec3<float>& P, const Imath::Vec3<float>& dPdx,
                   const Imath::Vec3<float>& dPdy,
                   const Imath::Vec3<float>& dPdz, int nchannels, float* result,
                   float* dresultds, float* dresultdt, float* dresultdr)
        -> bool;

    bool texture3d(OIIO::TextureSystem::TextureHandle* texture_handle,
                   OIIO::TextureSystem::Perthread* thread_info,
                   OIIO::TextureOpt& options, const Imath::Vec3<float>& P,
                   const Imath::Vec3<float>& dPdx,
                   const Imath::Vec3<float>& dPdy,
                   const Imath::Vec3<float>& dPdz, int nchannels, float* result,
                   float* dresultds, float* dresultdt, float* dresultdr)
        CPPMM_RENAME(texture3d_with_handle);

    auto shadow(OIIO::ustring filename, OIIO::TextureOpt& options,
                const Imath::Vec3<float>& P, const Imath::Vec3<float>& dPdx,
                const Imath::Vec3<float>& dPdy, float* result, float* dresultds,
                float* dresultdt) -> bool;

    bool shadow(OIIO::TextureSystem::TextureHandle* texture_handle,
                OIIO::TextureSystem::Perthread* thread_info,
                OIIO::TextureOpt& options, const Imath::Vec3<float>& P,
                const Imath::Vec3<float>& dPdx, const Imath::Vec3<float>& dPdy,
                float* result, float* dresultds, float* dresultdt)
        CPPMM_RENAME(shadow_with_handle);

    auto environment(OIIO::ustring filename, OIIO::TextureOpt& options,
                     const Imath::Vec3<float>& R,
                     const Imath::Vec3<float>& dRdx,
                     const Imath::Vec3<float>& dRdy, int nchannels,
                     float* result, float* dresultds, float* dresultdt) -> bool;

    bool environment(OIIO::TextureSystem::TextureHandle* texture_handle,
                     OIIO::TextureSystem::Perthread* thread_info,
                     OIIO::TextureOpt& options, const Imath::Vec3<float>& R,
                     const Imath::Vec3<float>& dRdx,
                     const Imath::Vec3<float>& dRdy, int nchannels,
                     float* result, float* dresultds, float* dresultdt)
        CPPMM_RENAME(environment_with_handle);

    bool texture(OIIO::ustring filename, OIIO::TextureOptBatch& options,
                 OIIO::Tex::RunMask mask, const float* s, const float* t,
                 const float* dsdx, const float* dtdx, const float* dsdy,
                 const float* dtdy, int nchannels, float* result,
                 float* dresultds, float* dresultdt)
        CPPMM_RENAME(texture_batch);

    bool texture(OIIO::TextureSystem::TextureHandle* texture_handle,
                 OIIO::TextureSystem::Perthread* thread_info,
                 OIIO::TextureOptBatch& options, OIIO::Tex::RunMask mask,
                 const float* s, const float* t, const float* dsdx,
                 const float* dtdx, const float* dsdy, const float* dtdy,
                 int nchannels, float* result, float* dresultds,
                 float* dresultdt) CPPMM_RENAME(texture_batch_with_handle);

    bool texture(OIIO::ustring filename, OIIO::TextureOptions& options,
                 unsigned char* runflags, int beginactive, int endactive,
                 OIIO::VaryingRef<float> s, OIIO::VaryingRef<float> t,
                 OIIO::VaryingRef<float> dsdx, OIIO::VaryingRef<float> dtdx,
                 OIIO::VaryingRef<float> dsdy, OIIO::VaryingRef<float> dtdy,
                 int nchannels, float* result, float* dresultds,
                 float* dresultdt) CPPMM_IGNORE;

    bool texture(OIIO::TextureSystem::TextureHandle* texture_handle,
                 OIIO::TextureSystem::Perthread* thread_info,
                 OIIO::TextureOptions& options, unsigned char* runflags,
                 int beginactive, int endactive, OIIO::VaryingRef<float> s,
                 OIIO::VaryingRef<float> t, OIIO::VaryingRef<float> dsdx,
                 OIIO::VaryingRef<float> dtdx, OIIO::VaryingRef<float> dsdy,
                 OIIO::VaryingRef<float> dtdy, int nchannels, float* result,
                 float* dresultds, float* dresultdt) CPPMM_IGNORE;

    bool texture3d(OIIO::ustring filename, OIIO::TextureOptBatch& options,
                   OIIO::Tex::RunMask mask, const float* P, const float* dPdx,
                   const float* dPdy, const float* dPdz, int nchannels,
                   float* result, float* dresultds, float* dresultdt,
                   float* dresultdr) CPPMM_RENAME(texture3d_batch);

    bool texture3d(OIIO::TextureSystem::TextureHandle* texture_handle,
                   OIIO::TextureSystem::Perthread* thread_info,
                   OIIO::TextureOptBatch& options, OIIO::Tex::RunMask mask,
                   const float* P, const float* dPdx, const float* dPdy,
                   const float* dPdz, int nchannels, float* result,
                   float* dresultds, float* dresultdt, float* dresultdr)
        CPPMM_RENAME(texture3d_batch_with_handle);

    bool texture3d(OIIO::ustring filename, OIIO::TextureOptions& options,
                   unsigned char* runflags, int beginactive, int endactive,
                   OIIO::VaryingRef<Imath::Vec3<float>> P,
                   OIIO::VaryingRef<Imath::Vec3<float>> dPdx,
                   OIIO::VaryingRef<Imath::Vec3<float>> dPdy,
                   OIIO::VaryingRef<Imath::Vec3<float>> dPdz, int nchannels,
                   float* result, float* dresultds, float* dresultdt,
                   float* dresultdr) CPPMM_IGNORE;

    bool texture3d(OIIO::TextureSystem::TextureHandle* texture_handle,
                   OIIO::TextureSystem::Perthread* thread_info,
                   OIIO::TextureOptions& options, unsigned char* runflags,
                   int beginactive, int endactive,
                   OIIO::VaryingRef<Imath::Vec3<float>> P,
                   OIIO::VaryingRef<Imath::Vec3<float>> dPdx,
                   OIIO::VaryingRef<Imath::Vec3<float>> dPdy,
                   OIIO::VaryingRef<Imath::Vec3<float>> dPdz, int nchannels,
                   float* result, float* dresultds, float* dresultdt,
                   float* dresultdr) CPPMM_IGNORE;

    bool environment(OIIO::ustring filename, OIIO::TextureOptBatch& options,
                     OIIO::Tex::RunMask mask, const float* R, const float* dRdx,
                     const float* dRdy, int nchannels, float* result,
                     float* dresultds, float* dresultdt)
        CPPMM_RENAME(environment_batch);

    bool environment(OIIO::TextureSystem::TextureHandle* texture_handle,
                     OIIO::TextureSystem::Perthread* thread_info,
                     OIIO::TextureOptBatch& options, OIIO::Tex::RunMask mask,
                     const float* R, const float* dRdx, const float* dRdy,
                     int nchannels, float* result, float* dresultds,
                     float* dresultdt) CPPMM_RENAME(environment_batch_with_handle);

    bool environment(OIIO::ustring filename, OIIO::TextureOptions& options,
                     unsigned char* runflags, int beginactive, int endactive,
                     OIIO::VaryingRef<Imath::Vec3<float>> R,
                     OIIO::VaryingRef<Imath::Vec3<float>> dRdx,
                     OIIO::VaryingRef<Imath::Vec3<float>> dRdy, int nchannels,
                     float* result, float* dresultds,
                     float* dresultdt) CPPMM_IGNORE;

    bool environment(OIIO::TextureSystem::TextureHandle* texture_handle,
                     OIIO::TextureSystem::Perthread* thread_info,
                     OIIO::TextureOptions& options, unsigned char* runflags,
                     int beginactive, int endactive,
                     OIIO::VaryingRef<Imath::Vec3<float>> R,
                     OIIO::VaryingRef<Imath::Vec3<float>> dRdx,
                     OIIO::VaryingRef<Imath::Vec3<float>> dRdy, int nchannels,
                     float* result, float* dresultds,
                     float* dresultdt) CPPMM_IGNORE;

    bool shadow(OIIO::ustring filename, OIIO::TextureOptBatch& options,
                OIIO::Tex::RunMask mask, const float* P, const float* dPdx,
                const float* dPdy, float* result, float* dresultds,
                float* dresultdt) CPPMM_RENAME(shadow_batch);

    bool shadow(OIIO::TextureSystem::TextureHandle* texture_handle,
                OIIO::TextureSystem::Perthread* thread_info,
                OIIO::TextureOptBatch& options, OIIO::Tex::RunMask mask,
                const float* P, const float* dPdx, const float* dPdy,
                float* result, float* dresultds, float* dresultdt)
        CPPMM_RENAME(shadow_batch_with_handle);

    bool shadow(OIIO::ustring filename, OIIO::TextureOptions& options,
                unsigned char* runflags, int beginactive, int endactive,
                OIIO::VaryingRef<Imath::Vec3<float>> P,
                OIIO::VaryingRef<Imath::Vec3<float>> dPdx,
                OIIO::VaryingRef<Imath::Vec3<float>> dPdy, float* result,
                float* dresultds, float* dresultdt) CPPMM_IGNORE;

    bool shadow(OIIO::TextureSystem::TextureHandle* texture_handle,
                OIIO::TextureSystem::Perthread* thread_info,
                OIIO::TextureOptions& options, unsigned char* runflags,
                int beginactive, int endactive,
                OIIO::VaryingRef<Imath::Vec3<float>> P,
                OIIO::VaryingRef<Imath::Vec3<float>> dPdx,
                OIIO::VaryingRef<Imath::Vec3<float>> dPdy, float* result,
                float* dresultds, float* dresultdt) CPPMM_IGNORE;

    auto resolve_filename(const std::string& filename) const -> std::string;

    bool get_texture_info(OIIO::ustring filename, int subimage,
                          OIIO::ustring dataname, OIIO::TypeDesc datatype,
                          void* data);

    bool get_texture_info(OIIO::TextureSystem::TextureHandle* texture_handle,
                          OIIO::TextureSystem::Perthread* thread_info,
                          int subimage, OIIO::ustring dataname,
                          OIIO::TypeDesc datatype, void* data)
        CPPMM_RENAME(get_texture_info_with_handle);

    auto get_imagespec(OIIO::ustring filename, int subimage,
                       OIIO::ImageSpec& spec) -> bool;

    bool get_imagespec(OIIO::TextureSystem::TextureHandle* texture_handle,
                       OIIO::TextureSystem::Perthread* thread_info,
                       int subimage, OIIO::ImageSpec& spec)
        CPPMM_RENAME(get_imagespec_with_handle);

    const OIIO::ImageSpec* imagespec(OIIO::ustring filename, int subimage);

    const OIIO::ImageSpec*
    imagespec(OIIO::TextureSystem::TextureHandle* texture_handle,
              OIIO::TextureSystem::Perthread* thread_info, int subimage)
        CPPMM_RENAME(imagespec_with_handle);

    auto get_texels(OIIO::ustring filename, OIIO::TextureOpt& options,
                    int miplevel, int xbegin, int xend, int ybegin, int yend,
                    int zbegin, int zend, int chbegin, int chend,
                    OIIO::TypeDesc format, void* result) -> bool;

    bool get_texels(OIIO::TextureSystem::TextureHandle* texture_handle,
                    OIIO::TextureSystem::Perthread* thread_info,
                    OIIO::TextureOpt& options, int miplevel, int xbegin,
                    int xend, int ybegin, int yend, int zbegin, int zend,
                    int chbegin, int chend, OIIO::TypeDesc format, void* result)
        CPPMM_RENAME(get_texels_with_handle);

    auto invalidate(OIIO::ustring filename, bool force) -> void;
    auto invalidate_all(bool force) -> void;
    auto close(OIIO::ustring filename) -> void;
    auto close_all() -> void;

    virtual bool has_error() const = 0;
    auto geterror(bool clear) const -> std::string;
    auto getstats(int level, bool icstats) const -> std::string;
    auto reset_stats() -> void;
    auto imagecache() const -> OIIO::ImageCache*;
    ~TextureSystem() CPPMM_IGNORE;

    /// Given a handle, return the filename for that image.
    ///
    virtual OIIO::ustring filename_from_handle(OIIO::TextureSystem::TextureHandle* handle);

    /// @{
    /// @name Methods for UDIM patterns
    ///

    /// Is the filename a UDIM pattern?
    ///
    /// This method was added in OpenImageIO 2.3.
    virtual bool is_udim(OIIO::ustring filename) = 0;

    /// Does the handle refer to a file that's a UDIM pattern?
    ///
    /// This method was added in OpenImageIO 2.3.
    virtual bool is_udim(OIIO::TextureSystem::TextureHandle* udimfile) CPPMM_RENAME(is_udim_with_handle);

    /// For a UDIM filename pattern and texture coordinates, return the
    /// TextureHandle pointer for the concrete tile file it refers to, or
    /// nullptr if there is no corresponding tile (udim sets are allowed to
    /// be sparse).
    ///
    /// This method was added in OpenImageIO 2.3.
    virtual OIIO::TextureSystem::TextureHandle* resolve_udim(OIIO::ustring udimpattern,
                                        float s, float t) = 0;

    /// A more efficient variety of `resolve_udim()` for cases where you
    /// have the `TextureHandle*` that corresponds to the "virtual" UDIM
    /// file and optionally have a `Perthread*` for the calling thread.
    ///
    /// This method was added in OpenImageIO 2.3.
    virtual OIIO::TextureSystem::TextureHandle* resolve_udim(OIIO::TextureSystem::TextureHandle* udimfile,
                                        OIIO::TextureSystem::Perthread* thread_info,
                                        float s, float t) CPPMM_RENAME(resolve_udim_with_handle);

    /// Produce a full inventory of the set of concrete files comprising the
    /// UDIM set specified by `udimpattern`.  The apparent number of texture
    /// atlas tiles in the u and v directions will be written to `nutiles`
    /// and `nvtiles`, respectively. The vector `filenames` will be sized
    /// to `ntiles * nvtiles` and filled with the the names of the concrete
    /// files comprising the atlas, with an empty ustring corresponding to
    /// any unpopulated tiles (the UDIM set is allowed to be sparse). The
    /// filename list is indexed as `utile + vtile * nvtiles`.
    ///
    /// This method was added in OpenImageIO 2.3.
    virtual void inventory_udim(OIIO::ustring udimpattern,
                                std::vector<OIIO::ustring>& filenames,
                                int& nutiles, int& nvtiles) = 0;

    /// A more efficient variety of `inventory_udim()` for cases where you
    /// have the `TextureHandle*` that corresponds to the "virtual" UDIM
    /// file and optionally have a `Perthread*` for the calling thread.
    ///
    /// This method was added in OpenImageIO 2.3.
    virtual void inventory_udim(OIIO::TextureSystem::TextureHandle* udimfile,
                                OIIO::TextureSystem::Perthread* thread_info,
                                std::vector<OIIO::ustring>& filenames,
                                int& nutiles, int& nvtiles) CPPMM_RENAME(inventory_udim_with_handle);
    /// @}

} CPPMM_OPAQUEPTR; // struct TextureSystem

} // namespace OIIO_NAMESPACE

} // namespace cppmm_bind
