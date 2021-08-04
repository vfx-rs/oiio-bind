#include "c-color_private.h"

#include "c-std_shared_ptr_private.h"
#include "c-std_string_private.h"
#include "c-std_vector_private.h"
#include "c-string_view_private.h"
#include "c-typedesc_private.h"
#include "c-ustring_private.h"
#include "imath_matrix_private.h"
#include <new>

#include <stdexcept>

unsigned int OpenImageIO_v2_3_6__ColorProcessor_dtor(
    OIIO_ColorProcessor_t * this_)
{
    try {
        delete to_cpp(this_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorProcessor_isNoOp(
    OIIO_ColorProcessor_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> isNoOp();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorProcessor_hasChannelCrosstalk(
    OIIO_ColorProcessor_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> hasChannelCrosstalk();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorProcessor_apply(
    OIIO_ColorProcessor_t const * this_
    , float * data
    , int width
    , int height
    , int channels
    , long chanstride
    , long xstride
    , long ystride)
{
    try {
        (to_cpp(this_)) -> apply(data, width, height, channels, chanstride, xstride, ystride);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorProcessor_apply_single(
    OIIO_ColorProcessor_t * this_
    , float * data)
{
    try {
        (to_cpp(this_)) -> apply(data);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_ctor(
    OIIO_ColorConfig_t * * this_
    , OIIO_string_view_t filename)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::ColorConfig(to_cpp_ref(&(filename))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_dtor(
    OIIO_ColorConfig_t * this_)
{
    try {
        delete to_cpp(this_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_reset(
    OIIO_ColorConfig_t * this_
    , _Bool * return_
    , OIIO_string_view_t filename)
{
    try {
        *(return_) = (to_cpp(this_)) -> reset(to_cpp_ref(&(filename)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_error(
    OIIO_ColorConfig_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> error();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_geterror(
    OIIO_ColorConfig_t * this_
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

unsigned int OpenImageIO_v2_3_6__ColorConfig_getNumColorSpaces(
    OIIO_ColorConfig_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> getNumColorSpaces();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getColorSpaceNameByIndex(
    OIIO_ColorConfig_t const * this_
    , char const * * return_
    , int index)
{
    try {
        *(return_) = (to_cpp(this_)) -> getColorSpaceNameByIndex(index);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getColorSpaceNameByRole(
    OIIO_ColorConfig_t const * this_
    , char const * * return_
    , OIIO_string_view_t role)
{
    try {
        *(return_) = (to_cpp(this_)) -> getColorSpaceNameByRole(to_cpp_ref(&(role)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getColorSpaceDataType(
    OIIO_ColorConfig_t const * this_
    , OIIO_TypeDesc_t * return_
    , OIIO_string_view_t name
    , int * bits)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> getColorSpaceDataType(to_cpp_ref(&(name)), bits));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getColorSpaceNames(
    OIIO_ColorConfig_t const * this_
    , std_vector_string_t * * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> getColorSpaceNames());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getColorSpaceFamilyByName(
    OIIO_ColorConfig_t const * this_
    , char const * * return_
    , OIIO_string_view_t name)
{
    try {
        *(return_) = (to_cpp(this_)) -> getColorSpaceFamilyByName(to_cpp_ref(&(name)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getNumRoles(
    OIIO_ColorConfig_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> getNumRoles();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getRoleByIndex(
    OIIO_ColorConfig_t const * this_
    , char const * * return_
    , int index)
{
    try {
        *(return_) = (to_cpp(this_)) -> getRoleByIndex(index);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getRoles(
    OIIO_ColorConfig_t const * this_
    , std_vector_string_t * * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> getRoles());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getNumLooks(
    OIIO_ColorConfig_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> getNumLooks();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getLookNameByIndex(
    OIIO_ColorConfig_t const * this_
    , char const * * return_
    , int index)
{
    try {
        *(return_) = (to_cpp(this_)) -> getLookNameByIndex(index);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getLookNames(
    OIIO_ColorConfig_t const * this_
    , std_vector_string_t * * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> getLookNames());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_createColorProcessor(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , OIIO_string_view_t inputColorSpace
    , OIIO_string_view_t outputColorSpace
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> createColorProcessor(to_cpp_ref(&(inputColorSpace)), to_cpp_ref(&(outputColorSpace)), to_cpp_ref(&(context_key)), to_cpp_ref(&(context_value))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_createColorProcessor_ustring(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , OIIO_ustring_t inputColorSpace
    , OIIO_ustring_t outputColorSpace
    , OIIO_ustring_t context_key
    , OIIO_ustring_t context_value)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> createColorProcessor(to_cpp_ref(&(inputColorSpace)), to_cpp_ref(&(outputColorSpace)), to_cpp_ref(&(context_key)), to_cpp_ref(&(context_value))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_createLookTransform(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , OIIO_string_view_t looks
    , OIIO_string_view_t inputColorSpace
    , OIIO_string_view_t outputColorSpace
    , _Bool inverse
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> createLookTransform(to_cpp_ref(&(looks)), to_cpp_ref(&(inputColorSpace)), to_cpp_ref(&(outputColorSpace)), inverse, to_cpp_ref(&(context_key)), to_cpp_ref(&(context_value))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_createLookTransform_ustring(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , OIIO_ustring_t looks
    , OIIO_ustring_t inputColorSpace
    , OIIO_ustring_t outputColorSpace
    , _Bool inverse
    , OIIO_ustring_t context_key
    , OIIO_ustring_t context_value)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> createLookTransform(to_cpp_ref(&(looks)), to_cpp_ref(&(inputColorSpace)), to_cpp_ref(&(outputColorSpace)), inverse, to_cpp_ref(&(context_key)), to_cpp_ref(&(context_value))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getNumDisplays(
    OIIO_ColorConfig_t const * this_
    , int * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> getNumDisplays();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getDisplayNameByIndex(
    OIIO_ColorConfig_t const * this_
    , char const * * return_
    , int index)
{
    try {
        *(return_) = (to_cpp(this_)) -> getDisplayNameByIndex(index);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getDisplayNames(
    OIIO_ColorConfig_t const * this_
    , std_vector_string_t * * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> getDisplayNames());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getDefaultDisplayName(
    OIIO_ColorConfig_t const * this_
    , char const * * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> getDefaultDisplayName();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getNumViews(
    OIIO_ColorConfig_t const * this_
    , int * return_
    , OIIO_string_view_t display)
{
    try {
        *(return_) = (to_cpp(this_)) -> getNumViews(to_cpp_ref(&(display)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getViewNameByIndex(
    OIIO_ColorConfig_t const * this_
    , char const * * return_
    , OIIO_string_view_t display
    , int index)
{
    try {
        *(return_) = (to_cpp(this_)) -> getViewNameByIndex(to_cpp_ref(&(display)), index);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getViewNames(
    OIIO_ColorConfig_t const * this_
    , std_vector_string_t * * return_
    , OIIO_string_view_t display)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> getViewNames(to_cpp_ref(&(display))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getDefaultViewName(
    OIIO_ColorConfig_t const * this_
    , char const * * return_
    , OIIO_string_view_t display)
{
    try {
        *(return_) = (to_cpp(this_)) -> getDefaultViewName(to_cpp_ref(&(display)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_createDisplayTransform(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , OIIO_string_view_t display
    , OIIO_string_view_t view
    , OIIO_string_view_t inputColorSpace
    , OIIO_string_view_t looks
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> createDisplayTransform(to_cpp_ref(&(display)), to_cpp_ref(&(view)), to_cpp_ref(&(inputColorSpace)), to_cpp_ref(&(looks)), to_cpp_ref(&(context_key)), to_cpp_ref(&(context_value))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_createDisplayTransform_ustring(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , OIIO_ustring_t display
    , OIIO_ustring_t view
    , OIIO_ustring_t inputColorSpace
    , OIIO_ustring_t looks
    , OIIO_ustring_t context_key
    , OIIO_ustring_t context_value)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> createDisplayTransform(to_cpp_ref(&(display)), to_cpp_ref(&(view)), to_cpp_ref(&(inputColorSpace)), to_cpp_ref(&(looks)), to_cpp_ref(&(context_key)), to_cpp_ref(&(context_value))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_createFileTransform(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , OIIO_string_view_t name
    , _Bool inverse)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> createFileTransform(to_cpp_ref(&(name)), inverse));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_createFileTransform_ustring(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , OIIO_ustring_t name
    , _Bool inverse)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> createFileTransform(to_cpp_ref(&(name)), inverse));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_createMatrixTransform(
    OIIO_ColorConfig_t const * this_
    , std_ColorProcessorHandle_t * * return_
    , Imath_M44f_t const * M
    , _Bool inverse)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> createMatrixTransform(to_cpp_ref(M), inverse));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_getColorSpaceFromFilepath(
    OIIO_ColorConfig_t const * this_
    , OIIO_string_view_t * return_
    , OIIO_string_view_t str)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> getColorSpaceFromFilepath(to_cpp_ref(&(str))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_parseColorSpaceFromString(
    OIIO_ColorConfig_t const * this_
    , OIIO_string_view_t * return_
    , OIIO_string_view_t str)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> parseColorSpaceFromString(to_cpp_ref(&(str))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_configname(
    OIIO_ColorConfig_t const * this_
    , std_string_t * * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> configname());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_supportsOpenColorIO(
    _Bool * return_)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ColorConfig::supportsOpenColorIO();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__ColorConfig_OpenColorIO_version_hex(
    int * return_)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ColorConfig::OpenColorIO_version_hex();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

