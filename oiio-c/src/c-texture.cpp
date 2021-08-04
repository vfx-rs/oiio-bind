#include "c-texture_private.h"

#include "c-imagecache_private.h"
#include "c-imageio_private.h"
#include "c-std_string_private.h"
#include "c-string_view_private.h"
#include "c-typedesc_private.h"
#include "c-ustring_private.h"
#include "imath_vec_private.h"
#include <new>

#include <stdexcept>

unsigned int OpenImageIO_v2_3_6__TextureOpt_ctor(
    OIIO_TextureOpt_t * * this_)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::TextureOpt());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureOpt_decode_wrapmode(
    OIIO_TextureOpt_Wrap * return_
    , char const * name)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::TextureOpt::decode_wrapmode(name));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureOpt_decode_wrapmode_ustring(
    OIIO_TextureOpt_Wrap * return_
    , OIIO_ustring_t name)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::TextureOpt::decode_wrapmode(to_cpp_ref(&(name))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureOpt_parse_wrapmodes(
    char const * wrapmodes
    , OIIO_TextureOpt_Wrap * swrapcode
    , OIIO_TextureOpt_Wrap * twrapcode)
{
    try {
        OpenImageIO_v2_3_6::TextureOpt::parse_wrapmodes(wrapmodes, OIIO_TextureOpt_Wrap_to_cpp_ref(swrapcode), OIIO_TextureOpt_Wrap_to_cpp_ref(twrapcode));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureOpt_copy(
    OIIO_TextureOpt_t * * this_
    , OIIO_TextureOpt_t const * rhs)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::TextureOpt(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureOpt__assign(
    OIIO_TextureOpt_t * this_
    , OIIO_TextureOpt_t * * return_
    , OIIO_TextureOpt_t const * rhs)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureOpt_dtor(
    OIIO_TextureOpt_t * this_)
{
    try {
        delete to_cpp(this_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureOptBatch_ctor(
    OIIO_TextureOptBatch_t * * this_)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::TextureOptBatch());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureOptBatch_copy(
    OIIO_TextureOptBatch_t * * this_
    , OIIO_TextureOptBatch_t const * rhs)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::TextureOptBatch(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureOptBatch__assign(
    OIIO_TextureOptBatch_t * this_
    , OIIO_TextureOptBatch_t * * return_
    , OIIO_TextureOptBatch_t const * rhs)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureOptBatch_dtor(
    OIIO_TextureOptBatch_t * this_)
{
    try {
        delete to_cpp(this_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_create(
    OIIO_TextureSystem_t * * return_
    , _Bool shared
    , OIIO_ImageCache_t * imagecache)
{
    try {
        to_c(return_, OpenImageIO_v2_3_6::TextureSystem::create(shared, to_cpp(imagecache)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_destroy(
    OIIO_TextureSystem_t * ts
    , _Bool teardown_imagecache)
{
    try {
        OpenImageIO_v2_3_6::TextureSystem::destroy(to_cpp(ts), teardown_imagecache);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_attribute(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void const * val)
{
    try {
        *(return_) = (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), to_cpp_ref(&(type)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_attribute_int(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , int val)
{
    try {
        *(return_) = (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_attribute_float(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , float val)
{
    try {
        *(return_) = (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_attribute_double(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , double val)
{
    try {
        *(return_) = (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_attribute_string(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_string_view_t val)
{
    try {
        *(return_) = (to_cpp(this_)) -> attribute(to_cpp_ref(&(name)), to_cpp_ref(&(val)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_getattribute(
    OIIO_TextureSystem_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , OIIO_TypeDesc_t type
    , void * val)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute(to_cpp_ref(&(name)), to_cpp_ref(&(type)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_getattribute_int(
    OIIO_TextureSystem_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , int * val)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute(to_cpp_ref(&(name)), *(val));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_getattribute_float(
    OIIO_TextureSystem_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , float * val)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute(to_cpp_ref(&(name)), *(val));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_getattribute_double(
    OIIO_TextureSystem_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , double * val)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute(to_cpp_ref(&(name)), *(val));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_getattribute_cstr(
    OIIO_TextureSystem_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , char * * val)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute(to_cpp_ref(&(name)), val);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_getattribute_string(
    OIIO_TextureSystem_t const * this_
    , _Bool * return_
    , OIIO_string_view_t name
    , std_string_t * val)
{
    try {
        *(return_) = (to_cpp(this_)) -> getattribute(to_cpp_ref(&(name)), to_cpp_ref(val));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_get_perthread_info(
    OIIO_TextureSystem_t * this_
    , OIIO_TextureSystem_Perthread_t * * return_
    , OIIO_TextureSystem_Perthread_t * thread_info)
{
    try {
        to_c(return_, (to_cpp(this_)) -> get_perthread_info(to_cpp(thread_info)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_create_thread_info(
    OIIO_TextureSystem_t * this_
    , OIIO_TextureSystem_Perthread_t * * return_)
{
    try {
        to_c(return_, (to_cpp(this_)) -> create_thread_info());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_destroy_thread_info(
    OIIO_TextureSystem_t * this_
    , OIIO_TextureSystem_Perthread_t * threadinfo)
{
    try {
        (to_cpp(this_)) -> destroy_thread_info(to_cpp(threadinfo));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_get_texture_handle(
    OIIO_TextureSystem_t * this_
    , OIIO_TextureSystem_TextureHandle_t * * return_
    , OIIO_ustring_t filename
    , OIIO_TextureSystem_Perthread_t * thread_info)
{
    try {
        to_c(return_, (to_cpp(this_)) -> get_texture_handle(to_cpp_ref(&(filename)), to_cpp(thread_info)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_good(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle)
{
    try {
        *(return_) = (to_cpp(this_)) -> good(to_cpp(texture_handle));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_texture(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOpt_t * options
    , float s
    , float t
    , float dsdx
    , float dtdx
    , float dsdy
    , float dtdy
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt)
{
    try {
        *(return_) = (to_cpp(this_)) -> texture(to_cpp_ref(&(filename)), to_cpp_ref(options), s, t, dsdx, dtdx, dsdy, dtdy, nchannels, result, dresultds, dresultdt);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_texture_handle(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOpt_t * options
    , float s
    , float t
    , float dsdx
    , float dtdx
    , float dsdy
    , float dtdy
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt)
{
    try {
        *(return_) = (to_cpp(this_)) -> texture(to_cpp(texture_handle), to_cpp(thread_info), to_cpp_ref(options), s, t, dsdx, dtdx, dsdy, dtdy, nchannels, result, dresultds, dresultdt);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_texture3d(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOpt_t * options
    , Imath_V3f_t const * P
    , Imath_V3f_t const * dPdx
    , Imath_V3f_t const * dPdy
    , Imath_V3f_t const * dPdz
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt
    , float * dresultdr)
{
    try {
        *(return_) = (to_cpp(this_)) -> texture3d(to_cpp_ref(&(filename)), to_cpp_ref(options), to_cpp_ref(P), to_cpp_ref(dPdx), to_cpp_ref(dPdy), to_cpp_ref(dPdz), nchannels, result, dresultds, dresultdt, dresultdr);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_texture3d_handle(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOpt_t * options
    , Imath_V3f_t const * P
    , Imath_V3f_t const * dPdx
    , Imath_V3f_t const * dPdy
    , Imath_V3f_t const * dPdz
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt
    , float * dresultdr)
{
    try {
        *(return_) = (to_cpp(this_)) -> texture3d(to_cpp(texture_handle), to_cpp(thread_info), to_cpp_ref(options), to_cpp_ref(P), to_cpp_ref(dPdx), to_cpp_ref(dPdy), to_cpp_ref(dPdz), nchannels, result, dresultds, dresultdt, dresultdr);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_shadow(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOpt_t * options
    , Imath_V3f_t const * P
    , Imath_V3f_t const * dPdx
    , Imath_V3f_t const * dPdy
    , float * result
    , float * dresultds
    , float * dresultdt)
{
    try {
        *(return_) = (to_cpp(this_)) -> shadow(to_cpp_ref(&(filename)), to_cpp_ref(options), to_cpp_ref(P), to_cpp_ref(dPdx), to_cpp_ref(dPdy), result, dresultds, dresultdt);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_shadow_handle(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOpt_t * options
    , Imath_V3f_t const * P
    , Imath_V3f_t const * dPdx
    , Imath_V3f_t const * dPdy
    , float * result
    , float * dresultds
    , float * dresultdt)
{
    try {
        *(return_) = (to_cpp(this_)) -> shadow(to_cpp(texture_handle), to_cpp(thread_info), to_cpp_ref(options), to_cpp_ref(P), to_cpp_ref(dPdx), to_cpp_ref(dPdy), result, dresultds, dresultdt);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_environment(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOpt_t * options
    , Imath_V3f_t const * R
    , Imath_V3f_t const * dRdx
    , Imath_V3f_t const * dRdy
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt)
{
    try {
        *(return_) = (to_cpp(this_)) -> environment(to_cpp_ref(&(filename)), to_cpp_ref(options), to_cpp_ref(R), to_cpp_ref(dRdx), to_cpp_ref(dRdy), nchannels, result, dresultds, dresultdt);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_environment_handle(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOpt_t * options
    , Imath_V3f_t const * R
    , Imath_V3f_t const * dRdx
    , Imath_V3f_t const * dRdy
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt)
{
    try {
        *(return_) = (to_cpp(this_)) -> environment(to_cpp(texture_handle), to_cpp(thread_info), to_cpp_ref(options), to_cpp_ref(R), to_cpp_ref(dRdx), to_cpp_ref(dRdy), nchannels, result, dresultds, dresultdt);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_texture_batch(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOptBatch_t * options
    , unsigned long mask
    , float const * s
    , float const * t
    , float const * dsdx
    , float const * dtdx
    , float const * dsdy
    , float const * dtdy
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt)
{
    try {
        *(return_) = (to_cpp(this_)) -> texture(to_cpp_ref(&(filename)), to_cpp_ref(options), mask, s, t, dsdx, dtdx, dsdy, dtdy, nchannels, result, dresultds, dresultdt);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_texture_handle_batch(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOptBatch_t * options
    , unsigned long mask
    , float const * s
    , float const * t
    , float const * dsdx
    , float const * dtdx
    , float const * dsdy
    , float const * dtdy
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt)
{
    try {
        *(return_) = (to_cpp(this_)) -> texture(to_cpp(texture_handle), to_cpp(thread_info), to_cpp_ref(options), mask, s, t, dsdx, dtdx, dsdy, dtdy, nchannels, result, dresultds, dresultdt);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_texture3d_batch(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOptBatch_t * options
    , unsigned long mask
    , float const * P
    , float const * dPdx
    , float const * dPdy
    , float const * dPdz
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt
    , float * dresultdr)
{
    try {
        *(return_) = (to_cpp(this_)) -> texture3d(to_cpp_ref(&(filename)), to_cpp_ref(options), mask, P, dPdx, dPdy, dPdz, nchannels, result, dresultds, dresultdt, dresultdr);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_texture3d_handle_batch(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOptBatch_t * options
    , unsigned long mask
    , float const * P
    , float const * dPdx
    , float const * dPdy
    , float const * dPdz
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt
    , float * dresultdr)
{
    try {
        *(return_) = (to_cpp(this_)) -> texture3d(to_cpp(texture_handle), to_cpp(thread_info), to_cpp_ref(options), mask, P, dPdx, dPdy, dPdz, nchannels, result, dresultds, dresultdt, dresultdr);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_environment_batch(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOptBatch_t * options
    , unsigned long mask
    , float const * R
    , float const * dRdx
    , float const * dRdy
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt)
{
    try {
        *(return_) = (to_cpp(this_)) -> environment(to_cpp_ref(&(filename)), to_cpp_ref(options), mask, R, dRdx, dRdy, nchannels, result, dresultds, dresultdt);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_environment_handle_batch(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOptBatch_t * options
    , unsigned long mask
    , float const * R
    , float const * dRdx
    , float const * dRdy
    , int nchannels
    , float * result
    , float * dresultds
    , float * dresultdt)
{
    try {
        *(return_) = (to_cpp(this_)) -> environment(to_cpp(texture_handle), to_cpp(thread_info), to_cpp_ref(options), mask, R, dRdx, dRdy, nchannels, result, dresultds, dresultdt);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_shadow_batch(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOptBatch_t * options
    , unsigned long mask
    , float const * P
    , float const * dPdx
    , float const * dPdy
    , float * result
    , float * dresultds
    , float * dresultdt)
{
    try {
        *(return_) = (to_cpp(this_)) -> shadow(to_cpp_ref(&(filename)), to_cpp_ref(options), mask, P, dPdx, dPdy, result, dresultds, dresultdt);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_shadow_handle_batch(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOptBatch_t * options
    , unsigned long mask
    , float const * P
    , float const * dPdx
    , float const * dPdy
    , float * result
    , float * dresultds
    , float * dresultdt)
{
    try {
        *(return_) = (to_cpp(this_)) -> shadow(to_cpp(texture_handle), to_cpp(thread_info), to_cpp_ref(options), mask, P, dPdx, dPdy, result, dresultds, dresultdt);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_resolve_filename(
    OIIO_TextureSystem_t const * this_
    , std_string_t * * return_
    , std_string_t const * filename)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> resolve_filename(to_cpp_ref(filename)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_get_texture_info(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , int subimage
    , OIIO_ustring_t dataname
    , OIIO_TypeDesc_t datatype
    , void * data)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_texture_info(to_cpp_ref(&(filename)), subimage, to_cpp_ref(&(dataname)), to_cpp_ref(&(datatype)), data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_get_texture_info_from_handle(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , int subimage
    , OIIO_ustring_t dataname
    , OIIO_TypeDesc_t datatype
    , void * data)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_texture_info(to_cpp(texture_handle), to_cpp(thread_info), subimage, to_cpp_ref(&(dataname)), to_cpp_ref(&(datatype)), data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_get_imagespec(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , int subimage
    , OIIO_ImageSpec_t * spec)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_imagespec(to_cpp_ref(&(filename)), subimage, to_cpp_ref(spec));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_get_imagespec_from_handle(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , int subimage
    , OIIO_ImageSpec_t * spec)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_imagespec(to_cpp(texture_handle), to_cpp(thread_info), subimage, to_cpp_ref(spec));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_imagespec(
    OIIO_TextureSystem_t * this_
    , OIIO_ImageSpec_t const * * return_
    , OIIO_ustring_t filename
    , int subimage)
{
    try {
        to_c(return_, (to_cpp(this_)) -> imagespec(to_cpp_ref(&(filename)), subimage));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_imagespace_from_handle(
    OIIO_TextureSystem_t * this_
    , OIIO_ImageSpec_t const * * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , int subimage)
{
    try {
        to_c(return_, (to_cpp(this_)) -> imagespec(to_cpp(texture_handle), to_cpp(thread_info), subimage));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_get_texels(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_ustring_t filename
    , OIIO_TextureOpt_t * options
    , int miplevel
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend
    , int chbegin
    , int chend
    , OIIO_TypeDesc_t format
    , void * result)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_texels(to_cpp_ref(&(filename)), to_cpp_ref(options), miplevel, xbegin, xend, ybegin, yend, zbegin, zend, chbegin, chend, to_cpp_ref(&(format)), result);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_get_texels_from_handle(
    OIIO_TextureSystem_t * this_
    , _Bool * return_
    , OIIO_TextureSystem_TextureHandle_t * texture_handle
    , OIIO_TextureSystem_Perthread_t * thread_info
    , OIIO_TextureOpt_t * options
    , int miplevel
    , int xbegin
    , int xend
    , int ybegin
    , int yend
    , int zbegin
    , int zend
    , int chbegin
    , int chend
    , OIIO_TypeDesc_t format
    , void * result)
{
    try {
        *(return_) = (to_cpp(this_)) -> get_texels(to_cpp(texture_handle), to_cpp(thread_info), to_cpp_ref(options), miplevel, xbegin, xend, ybegin, yend, zbegin, zend, chbegin, chend, to_cpp_ref(&(format)), result);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_invalidate(
    OIIO_TextureSystem_t * this_
    , OIIO_ustring_t filename
    , _Bool force)
{
    try {
        (to_cpp(this_)) -> invalidate(to_cpp_ref(&(filename)), force);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_invalidate_all(
    OIIO_TextureSystem_t * this_
    , _Bool force)
{
    try {
        (to_cpp(this_)) -> invalidate_all(force);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_close(
    OIIO_TextureSystem_t * this_
    , OIIO_ustring_t filename)
{
    try {
        (to_cpp(this_)) -> close(to_cpp_ref(&(filename)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_close_all(
    OIIO_TextureSystem_t * this_)
{
    try {
        (to_cpp(this_)) -> close_all();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_has_error(
    OIIO_TextureSystem_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> has_error();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_geterror(
    OIIO_TextureSystem_t const * this_
    , std_string_t * * return_
    , _Bool clear)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> geterror(clear));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_getstats(
    OIIO_TextureSystem_t const * this_
    , std_string_t * * return_
    , int level
    , _Bool icstats)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> getstats(level, icstats));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_reset_stats(
    OIIO_TextureSystem_t * this_)
{
    try {
        (to_cpp(this_)) -> reset_stats();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem_imagecache(
    OIIO_TextureSystem_t const * this_
    , OIIO_ImageCache_t * * return_)
{
    try {
        to_c(return_, (to_cpp(this_)) -> imagecache());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__TextureSystem__assign(
    OIIO_TextureSystem_t * this_
    , OIIO_TextureSystem_t * * return_
    , OIIO_TextureSystem_t const * rhs)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Tex_decode_wrapmode(
    OIIO_Tex_Wrap * return_
    , char const * name)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::Tex::decode_wrapmode(name));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Tex_decode_wrapmode_ustring(
    OIIO_Tex_Wrap * return_
    , OIIO_ustring_t name)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::Tex::decode_wrapmode(to_cpp_ref(&(name))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Tex_parse_wrapmodes(
    char const * wrapmodes
    , OIIO_Tex_Wrap * swrapcode
    , OIIO_Tex_Wrap * twrapcode)
{
    try {
        OpenImageIO_v2_3_6::Tex::parse_wrapmodes(wrapmodes, OIIO_Tex_Wrap_to_cpp_ref(swrapcode), OIIO_Tex_Wrap_to_cpp_ref(twrapcode));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

