#include "c-imagebufalgo_private.h"

#include "c-color_private.h"
#include "c-filter_private.h"
#include "c-imagebuf_private.h"
#include "c-imageio_private.h"
#include "c-span_private.h"
#include "c-std_string_private.h"
#include "c-std_vector_private.h"
#include "c-string_view_private.h"
#include "c-typedesc_private.h"
#include "imath_matrix_private.h"
#include <new>

#include <stdexcept>

unsigned int OpenImageIO_v2_3_6__Image_or_Const_none(
    OIIO_Image_or_Const_t * * this_
    , OIIO_Image_or_Const_None_t n)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::Image_or_Const(to_cpp_ref(&(n))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Image_or_Const_from_imagebuf(
    OIIO_Image_or_Const_t * * this_
    , OIIO_ImageBuf_t const * img)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::Image_or_Const(to_cpp(img)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Image_or_Const_from_float(
    OIIO_Image_or_Const_t * * this_
    , float const * val)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::Image_or_Const(*(val)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Image_or_Const_from_float_vector(
    OIIO_Image_or_Const_t * * this_
    , std_vector_float_t const * val)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::Image_or_Const(to_cpp_ref(val)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Image_or_Const_from_float_array(
    OIIO_Image_or_Const_t * * this_
    , float const * v
    , unsigned long s)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::Image_or_Const(v, s));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Image_or_Const_is_img(
    OIIO_Image_or_Const_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> is_img();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Image_or_Const_is_val(
    OIIO_Image_or_Const_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> is_val();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Image_or_Const_is_empty(
    OIIO_Image_or_Const_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> is_empty();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Image_or_Const_imgptr(
    OIIO_Image_or_Const_t const * this_
    , OIIO_ImageBuf_t const * * return_)
{
    try {
        to_c(return_, (to_cpp(this_)) -> imgptr());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Image_or_Const_val(
    OIIO_Image_or_Const_t const * this_
    , OIIO_cspan_float_t * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> val());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Image_or_Const_swap(
    OIIO_Image_or_Const_t * this_
    , OIIO_Image_or_Const_t * other)
{
    try {
        (to_cpp(this_)) -> swap(to_cpp_ref(other));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Image_or_Const_copy(
    OIIO_Image_or_Const_t * * this_
    , OIIO_Image_or_Const_t const * rhs)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::Image_or_Const(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Image_or_Const_dtor(
    OIIO_Image_or_Const_t * this_)
{
        delete to_cpp(this_);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__Image_or_Const__None_sizeof()
{
        return sizeof(OpenImageIO_v2_3_6::Image_or_Const::None);
}

unsigned int OpenImageIO_v2_3_6__Image_or_Const__None_alignof()
{
        return alignof(OpenImageIO_v2_3_6::Image_or_Const::None);
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_zero(
    OIIO_ImageBuf_t * * return_
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::zero(to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_zero_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::zero(to_cpp_ref(dst), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fill(
    OIIO_ImageBuf_t * * return_
    , OIIO_cspan_float_t values
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::fill(to_cpp_ref(&(values)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fill_grad2(
    OIIO_ImageBuf_t * * return_
    , OIIO_cspan_float_t top
    , OIIO_cspan_float_t bottom
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::fill(to_cpp_ref(&(top)), to_cpp_ref(&(bottom)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fill_grad4(
    OIIO_ImageBuf_t * * return_
    , OIIO_cspan_float_t topleft
    , OIIO_cspan_float_t topright
    , OIIO_cspan_float_t bottomleft
    , OIIO_cspan_float_t bottomright
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::fill(to_cpp_ref(&(topleft)), to_cpp_ref(&(topright)), to_cpp_ref(&(bottomleft)), to_cpp_ref(&(bottomright)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fill_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_cspan_float_t values
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::fill(to_cpp_ref(dst), to_cpp_ref(&(values)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fill_grad2_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_cspan_float_t top
    , OIIO_cspan_float_t bottom
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::fill(to_cpp_ref(dst), to_cpp_ref(&(top)), to_cpp_ref(&(bottom)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fill_grad4_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_cspan_float_t topleft
    , OIIO_cspan_float_t topright
    , OIIO_cspan_float_t bottomleft
    , OIIO_cspan_float_t bottomright
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::fill(to_cpp_ref(dst), to_cpp_ref(&(topleft)), to_cpp_ref(&(topright)), to_cpp_ref(&(bottomleft)), to_cpp_ref(&(bottomright)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_checker(
    OIIO_ImageBuf_t * * return_
    , int width
    , int height
    , int depth
    , OIIO_cspan_float_t color1
    , OIIO_cspan_float_t color2
    , int xoffset
    , int yoffset
    , int zoffset
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::checker(width, height, depth, to_cpp_ref(&(color1)), to_cpp_ref(&(color2)), xoffset, yoffset, zoffset, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_checker_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , int width
    , int height
    , int depth
    , OIIO_cspan_float_t color1
    , OIIO_cspan_float_t color2
    , int xoffset
    , int yoffset
    , int zoffset
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::checker(to_cpp_ref(dst), width, height, depth, to_cpp_ref(&(color1)), to_cpp_ref(&(color2)), xoffset, yoffset, zoffset, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_noise(
    OIIO_ImageBuf_t * * return_
    , OIIO_string_view_t noisetype
    , float A
    , float B
    , _Bool mono
    , int seed
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::noise(to_cpp_ref(&(noisetype)), A, B, mono, seed, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_noise_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_string_view_t noisetype
    , float A
    , float B
    , _Bool mono
    , int seed
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::noise(to_cpp_ref(dst), to_cpp_ref(&(noisetype)), A, B, mono, seed, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_render_point(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , int x
    , int y
    , OIIO_cspan_float_t color
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::render_point(to_cpp_ref(dst), x, y, to_cpp_ref(&(color)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_render_line(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , int x1
    , int y1
    , int x2
    , int y2
    , OIIO_cspan_float_t color
    , _Bool skip_first_point
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::render_line(to_cpp_ref(dst), x1, y1, x2, y2, to_cpp_ref(&(color)), skip_first_point, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_render_box(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , int x1
    , int y1
    , int x2
    , int y2
    , OIIO_cspan_float_t color
    , _Bool fill
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::render_box(to_cpp_ref(dst), x1, y1, x2, y2, to_cpp_ref(&(color)), fill, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_render_text(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , int x
    , int y
    , OIIO_string_view_t text
    , int fontsize
    , OIIO_string_view_t fontname
    , OIIO_cspan_float_t textcolor
    , OIIO_ImageBufAlgo_TextAlignX alignx
    , OIIO_ImageBufAlgo_TextAlignY aligny
    , int shadow
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::render_text(to_cpp_ref(dst), x, y, to_cpp_ref(&(text)), fontsize, to_cpp_ref(&(fontname)), to_cpp_ref(&(textcolor)), OIIO_ImageBufAlgo_TextAlignX_to_cpp_ref(&(alignx)), OIIO_ImageBufAlgo_TextAlignY_to_cpp_ref(&(aligny)), shadow, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_text_size(
    OIIO_ROI_t * return_
    , OIIO_string_view_t text
    , int fontsize
    , OIIO_string_view_t fontname)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::text_size(to_cpp_ref(&(text)), fontsize, to_cpp_ref(&(fontname))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_channels(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , int nchannels
    , OIIO_cspan_int_t channelorder
    , OIIO_cspan_float_t channelvalues
    , OIIO_cspan_string_t newchannelnames
    , _Bool shuffle_channel_names
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::channels(to_cpp_ref(src), nchannels, to_cpp_ref(&(channelorder)), to_cpp_ref(&(channelvalues)), to_cpp_ref(&(newchannelnames)), shuffle_channel_names, nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_channels_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , int nchannels
    , OIIO_cspan_int_t channelorder
    , OIIO_cspan_float_t channelvalues
    , OIIO_cspan_string_t newchannelnames
    , _Bool shuffle_channel_names
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::channels(to_cpp_ref(dst), to_cpp_ref(src), nchannels, to_cpp_ref(&(channelorder)), to_cpp_ref(&(channelvalues)), to_cpp_ref(&(newchannelnames)), shuffle_channel_names, nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_channel_append(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::channel_append(to_cpp_ref(A), to_cpp_ref(B), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_channel_append_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::channel_append(to_cpp_ref(dst), to_cpp_ref(A), to_cpp_ref(B), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_copy(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_TypeDesc_t convert
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::copy(to_cpp_ref(src), to_cpp_ref(&(convert)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_copy_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_TypeDesc_t convert
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::copy(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(convert)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_crop(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::crop(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_crop_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::crop(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_cut(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::cut(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_cut_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::cut(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_paste(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , int xbegin
    , int ybegin
    , int zbegin
    , int chbegin
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t srcroi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::paste(to_cpp_ref(dst), xbegin, ybegin, zbegin, chbegin, to_cpp_ref(src), to_cpp_ref(&(srcroi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate90(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::rotate90(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate180(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::rotate180(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate270(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::rotate270(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate90_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::rotate90(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate180_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::rotate180(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate270_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::rotate270(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_flip(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::flip(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_flop(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::flop(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_transpose(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::transpose(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_flip_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::flip(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_flop_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::flop(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_transpose_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::transpose(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_reorient(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::reorient(to_cpp_ref(src), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_reorient_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::reorient(to_cpp_ref(dst), to_cpp_ref(src), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_circular_shift(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , int xshift
    , int yshift
    , int zshift
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::circular_shift(to_cpp_ref(src), xshift, yshift, zshift, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_circular_shift_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , int xshift
    , int yshift
    , int zshift
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::circular_shift(to_cpp_ref(dst), to_cpp_ref(src), xshift, yshift, zshift, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , float angle
    , OIIO_string_view_t filtername
    , float filterwidth
    , _Bool recompute_roi
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::rotate(to_cpp_ref(src), angle, to_cpp_ref(&(filtername)), filterwidth, recompute_roi, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_filter(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , float angle
    , OIIO_Filter2D_t * filter
    , _Bool recompute_roi
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::rotate(to_cpp_ref(src), angle, to_cpp(filter), recompute_roi, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_center(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , float angle
    , float center_x
    , float center_y
    , OIIO_string_view_t filtername
    , float filterwidth
    , _Bool recompute_roi
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::rotate(to_cpp_ref(src), angle, center_x, center_y, to_cpp_ref(&(filtername)), filterwidth, recompute_roi, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_filter_and_center(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , float angle
    , float center_x
    , float center_y
    , OIIO_Filter2D_t * filter
    , _Bool recompute_roi
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::rotate(to_cpp_ref(src), angle, center_x, center_y, to_cpp(filter), recompute_roi, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , float angle
    , OIIO_string_view_t filtername
    , float filterwidth
    , _Bool recompute_roi
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::rotate(to_cpp_ref(dst), to_cpp_ref(src), angle, to_cpp_ref(&(filtername)), filterwidth, recompute_roi, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_filter_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , float angle
    , OIIO_Filter2D_t * filter
    , _Bool recompute_roi
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::rotate(to_cpp_ref(dst), to_cpp_ref(src), angle, to_cpp(filter), recompute_roi, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_center_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , float angle
    , float center_x
    , float center_y
    , OIIO_string_view_t filtername
    , float filterwidth
    , _Bool recompute_roi
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::rotate(to_cpp_ref(dst), to_cpp_ref(src), angle, center_x, center_y, to_cpp_ref(&(filtername)), filterwidth, recompute_roi, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rotate_with_filter_and_center_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , float angle
    , float center_x
    , float center_y
    , OIIO_Filter2D_t * filter
    , _Bool recompute_roi
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::rotate(to_cpp_ref(dst), to_cpp_ref(src), angle, center_x, center_y, to_cpp(filter), recompute_roi, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_resize(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t filtername
    , float filterwidth
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::resize(to_cpp_ref(src), to_cpp_ref(&(filtername)), filterwidth, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_resize_with_filter(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_Filter2D_t * filter
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::resize(to_cpp_ref(src), to_cpp(filter), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_resize_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t filtername
    , float filterwidth
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::resize(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(filtername)), filterwidth, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_resize_with_filter_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_Filter2D_t * filter
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::resize(to_cpp_ref(dst), to_cpp_ref(src), to_cpp(filter), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_resample(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , _Bool interpolate
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::resample(to_cpp_ref(src), interpolate, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_resample_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , _Bool interpolate
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::resample(to_cpp_ref(dst), to_cpp_ref(src), interpolate, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fit(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t filtername
    , float filterwidth
    , _Bool exact
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::fit(to_cpp_ref(src), to_cpp_ref(&(filtername)), filterwidth, exact, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fit_with_filter(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_Filter2D_t * filter
    , _Bool exact
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::fit(to_cpp_ref(src), to_cpp(filter), exact, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fit_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t filtername
    , float filterwidth
    , _Bool exact
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::fit(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(filtername)), filterwidth, exact, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fit_with_filter_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_Filter2D_t * filter
    , _Bool exact
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::fit(to_cpp_ref(dst), to_cpp_ref(src), to_cpp(filter), exact, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_warp(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , Imath_M33f_t const * M
    , OIIO_string_view_t filtername
    , float filterwidth
    , _Bool recompute_roi
    , OIIO_ImageBuf_WrapMode wrap
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::warp(to_cpp_ref(src), to_cpp_ref(M), to_cpp_ref(&(filtername)), filterwidth, recompute_roi, OIIO_ImageBuf_WrapMode_to_cpp_ref(&(wrap)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_warp_with_filter(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , Imath_M33f_t const * M
    , OIIO_Filter2D_t const * filter
    , _Bool recompute_roi
    , OIIO_ImageBuf_WrapMode wrap
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::warp(to_cpp_ref(src), to_cpp_ref(M), to_cpp(filter), recompute_roi, OIIO_ImageBuf_WrapMode_to_cpp_ref(&(wrap)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_warp_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , Imath_M33f_t const * M
    , OIIO_string_view_t filtername
    , float filterwidth
    , _Bool recompute_roi
    , OIIO_ImageBuf_WrapMode wrap
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::warp(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(M), to_cpp_ref(&(filtername)), filterwidth, recompute_roi, OIIO_ImageBuf_WrapMode_to_cpp_ref(&(wrap)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_warp_with_filter_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , Imath_M33f_t const * M
    , OIIO_Filter2D_t const * filter
    , _Bool recompute_roi
    , OIIO_ImageBuf_WrapMode wrap
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::warp(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(M), to_cpp(filter), recompute_roi, OIIO_ImageBuf_WrapMode_to_cpp_ref(&(wrap)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_add(
    OIIO_ImageBuf_t * * return_
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::add(to_cpp_ref(&(A)), to_cpp_ref(&(B)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_add_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::add(to_cpp_ref(dst), to_cpp_ref(&(A)), to_cpp_ref(&(B)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_sub(
    OIIO_ImageBuf_t * * return_
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::sub(to_cpp_ref(&(A)), to_cpp_ref(&(B)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_sub_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::sub(to_cpp_ref(dst), to_cpp_ref(&(A)), to_cpp_ref(&(B)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_absdiff(
    OIIO_ImageBuf_t * * return_
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::absdiff(to_cpp_ref(&(A)), to_cpp_ref(&(B)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_absdiff_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::absdiff(to_cpp_ref(dst), to_cpp_ref(&(A)), to_cpp_ref(&(B)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_abs(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::abs(to_cpp_ref(A), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_abs_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * A
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::abs(to_cpp_ref(dst), to_cpp_ref(A), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_mul(
    OIIO_ImageBuf_t * * return_
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::mul(to_cpp_ref(&(A)), to_cpp_ref(&(B)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_mul_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::mul(to_cpp_ref(dst), to_cpp_ref(&(A)), to_cpp_ref(&(B)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_div(
    OIIO_ImageBuf_t * * return_
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::div(to_cpp_ref(&(A)), to_cpp_ref(&(B)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_div_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::div(to_cpp_ref(dst), to_cpp_ref(&(A)), to_cpp_ref(&(B)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_mad(
    OIIO_ImageBuf_t * * return_
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_Image_or_Const_t C
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::mad(to_cpp_ref(&(A)), to_cpp_ref(&(B)), to_cpp_ref(&(C)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_mad_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_Image_or_Const_t C
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::mad(to_cpp_ref(dst), to_cpp_ref(&(A)), to_cpp_ref(&(B)), to_cpp_ref(&(C)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_over(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::over(to_cpp_ref(A), to_cpp_ref(B), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_over_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::over(to_cpp_ref(dst), to_cpp_ref(A), to_cpp_ref(B), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_zover(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , _Bool z_zeroisinf
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::zover(to_cpp_ref(A), to_cpp_ref(B), z_zeroisinf, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_zover_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , _Bool z_zeroisinf
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::zover(to_cpp_ref(dst), to_cpp_ref(A), to_cpp_ref(B), z_zeroisinf, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_invert(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::invert(to_cpp_ref(A), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_invert_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * A
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::invert(to_cpp_ref(dst), to_cpp_ref(A), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_pow(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_cspan_float_t B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::pow(to_cpp_ref(A), to_cpp_ref(&(B)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_pow_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * A
    , OIIO_cspan_float_t B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::pow(to_cpp_ref(dst), to_cpp_ref(A), to_cpp_ref(&(B)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_channel_sum(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_cspan_float_t weights
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::channel_sum(to_cpp_ref(src), to_cpp_ref(&(weights)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_channel_sum_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_cspan_float_t weights
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::channel_sum(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(weights)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_max(
    OIIO_ImageBuf_t * * return_
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::max(to_cpp_ref(&(A)), to_cpp_ref(&(B)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_max_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::max(to_cpp_ref(dst), to_cpp_ref(&(A)), to_cpp_ref(&(B)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_min(
    OIIO_ImageBuf_t * * return_
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::min(to_cpp_ref(&(A)), to_cpp_ref(&(B)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_min_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_Image_or_Const_t A
    , OIIO_Image_or_Const_t B
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::min(to_cpp_ref(dst), to_cpp_ref(&(A)), to_cpp_ref(&(B)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_clamp(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_cspan_float_t min
    , OIIO_cspan_float_t max
    , _Bool clampalpha01
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::clamp(to_cpp_ref(src), to_cpp_ref(&(min)), to_cpp_ref(&(max)), clampalpha01, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_clamp_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_cspan_float_t min
    , OIIO_cspan_float_t max
    , _Bool clampalpha01
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::clamp(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(min)), to_cpp_ref(&(max)), clampalpha01, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_contrast_remap(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_cspan_float_t black
    , OIIO_cspan_float_t white
    , OIIO_cspan_float_t min
    , OIIO_cspan_float_t max
    , OIIO_cspan_float_t scontrast
    , OIIO_cspan_float_t sthresh
    , OIIO_ROI_t _param7
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::contrast_remap(to_cpp_ref(src), to_cpp_ref(&(black)), to_cpp_ref(&(white)), to_cpp_ref(&(min)), to_cpp_ref(&(max)), to_cpp_ref(&(scontrast)), to_cpp_ref(&(sthresh)), to_cpp_ref(&(_param7)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_contrast_remap_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_cspan_float_t black
    , OIIO_cspan_float_t white
    , OIIO_cspan_float_t min
    , OIIO_cspan_float_t max
    , OIIO_cspan_float_t scontrast
    , OIIO_cspan_float_t sthresh
    , OIIO_ROI_t _param8
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::contrast_remap(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(black)), to_cpp_ref(&(white)), to_cpp_ref(&(min)), to_cpp_ref(&(max)), to_cpp_ref(&(scontrast)), to_cpp_ref(&(sthresh)), to_cpp_ref(&(_param8)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_color_map(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , int srcchannel
    , int nknots
    , int channels
    , OIIO_cspan_float_t knots
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::color_map(to_cpp_ref(src), srcchannel, nknots, channels, to_cpp_ref(&(knots)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_color_map_named(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , int srcchannel
    , OIIO_string_view_t mapname
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::color_map(to_cpp_ref(src), srcchannel, to_cpp_ref(&(mapname)), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_color_map_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , int srcchannel
    , int nknots
    , int channels
    , OIIO_cspan_float_t knots
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::color_map(to_cpp_ref(dst), to_cpp_ref(src), srcchannel, nknots, channels, to_cpp_ref(&(knots)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_color_map_named_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , int srcchannel
    , OIIO_string_view_t mapname
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::color_map(to_cpp_ref(dst), to_cpp_ref(src), srcchannel, to_cpp_ref(&(mapname)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rangecompress(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , _Bool useluma
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::rangecompress(to_cpp_ref(src), useluma, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rangeexpand(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , _Bool useluma
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::rangeexpand(to_cpp_ref(src), useluma, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rangecompress_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , _Bool useluma
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::rangecompress(to_cpp_ref(dst), to_cpp_ref(src), useluma, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_rangeexpand_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , _Bool useluma
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::rangeexpand(to_cpp_ref(dst), to_cpp_ref(src), useluma, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_compare(
    OIIO_ImageBufAlgo_CompareResults_t * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , float failthresh
    , float warnthresh
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::compare(to_cpp_ref(A), to_cpp_ref(B), failthresh, warnthresh, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_compare_Yee(
    int * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , OIIO_ImageBufAlgo_CompareResults_t * result
    , float luminance
    , float fov
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::compare_Yee(to_cpp_ref(A), to_cpp_ref(B), to_cpp_ref(result), luminance, fov, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_isConstantColor(
    _Bool * return_
    , OIIO_ImageBuf_t const * src
    , float threshold
    , OIIO_span_float_t color
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::isConstantColor(to_cpp_ref(src), threshold, to_cpp_ref(&(color)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_isConstantChannel(
    _Bool * return_
    , OIIO_ImageBuf_t const * src
    , int channel
    , float val
    , float threshold
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::isConstantChannel(to_cpp_ref(src), channel, val, threshold, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_isMonochrome(
    _Bool * return_
    , OIIO_ImageBuf_t const * src
    , float threshold
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::isMonochrome(to_cpp_ref(src), threshold, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_color_count(
    _Bool * return_
    , OIIO_ImageBuf_t const * src
    , unsigned long * count
    , int ncolors
    , OIIO_cspan_float_t color
    , OIIO_cspan_float_t eps
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::color_count(to_cpp_ref(src), count, ncolors, to_cpp_ref(&(color)), to_cpp_ref(&(eps)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_color_range_check(
    _Bool * return_
    , OIIO_ImageBuf_t const * src
    , unsigned long * lowcount
    , unsigned long * highcount
    , unsigned long * inrangecount
    , OIIO_cspan_float_t low
    , OIIO_cspan_float_t high
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::color_range_check(to_cpp_ref(src), lowcount, highcount, inrangecount, to_cpp_ref(&(low)), to_cpp_ref(&(high)), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_nonzero_region(
    OIIO_ROI_t * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::nonzero_region(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_computePixelHashSHA1(
    std_string_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t extrainfo
    , OIIO_ROI_t roi
    , int blocksize
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::computePixelHashSHA1(to_cpp_ref(src), to_cpp_ref(&(extrainfo)), to_cpp_ref(&(roi)), blocksize, nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_histogram(
    std_vector_ulong_t * * return_
    , OIIO_ImageBuf_t const * src
    , int channel
    , int bins
    , float min
    , float max
    , _Bool ignore_empty
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::histogram(to_cpp_ref(src), channel, bins, min, max, ignore_empty, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_make_kernel(
    OIIO_ImageBuf_t * * return_
    , OIIO_string_view_t name
    , float width
    , float height
    , float depth
    , _Bool normalize)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::make_kernel(to_cpp_ref(&(name)), width, height, depth, normalize));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_convolve(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ImageBuf_t const * kernel
    , _Bool normalize
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::convolve(to_cpp_ref(src), to_cpp_ref(kernel), normalize, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_convolve_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ImageBuf_t const * kernel
    , _Bool normalize
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::convolve(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(kernel), normalize, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_laplacian(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::laplacian(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_laplacian_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::laplacian(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fft(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::fft(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_ifft(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::ifft(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fft_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::fft(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_ifft_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::ifft(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_complex_to_polar(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::complex_to_polar(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_complex_to_polar_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::complex_to_polar(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_polar_to_complex(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::polar_to_complex(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_polar_to_complex_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::polar_to_complex(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fixNonFinite(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ImageBufAlgo_NonFiniteFixMode mode
    , int * pixelsFixed
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::fixNonFinite(to_cpp_ref(src), OIIO_ImageBufAlgo_NonFiniteFixMode_to_cpp_ref(&(mode)), pixelsFixed, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fixNonFinite_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ImageBufAlgo_NonFiniteFixMode mode
    , int * pixelsFixed
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::fixNonFinite(to_cpp_ref(dst), to_cpp_ref(src), OIIO_ImageBufAlgo_NonFiniteFixMode_to_cpp_ref(&(mode)), pixelsFixed, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fillholes_pushpull(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::fillholes_pushpull(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_fillholes_pushpull_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::fillholes_pushpull(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_median_filter(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , int width
    , int height
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::median_filter(to_cpp_ref(src), width, height, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_median_filter_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , int width
    , int height
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::median_filter(to_cpp_ref(dst), to_cpp_ref(src), width, height, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_unsharp_mask(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t kernel
    , float width
    , float contrast
    , float threshold
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::unsharp_mask(to_cpp_ref(src), to_cpp_ref(&(kernel)), width, contrast, threshold, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_unsharp_mask_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t kernel
    , float width
    , float contrast
    , float threshold
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::unsharp_mask(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(kernel)), width, contrast, threshold, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_dilate(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , int width
    , int height
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::dilate(to_cpp_ref(src), width, height, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_dilate_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , int width
    , int height
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::dilate(to_cpp_ref(dst), to_cpp_ref(src), width, height, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_erode(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , int width
    , int height
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::erode(to_cpp_ref(src), width, height, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_erode_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , int width
    , int height
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::erode(to_cpp_ref(dst), to_cpp_ref(src), width, height, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_colorconvert(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t fromspace
    , OIIO_string_view_t tospace
    , _Bool unpremult
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value
    , OIIO_ColorConfig_t * colorconfig
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::colorconvert(to_cpp_ref(src), to_cpp_ref(&(fromspace)), to_cpp_ref(&(tospace)), unpremult, to_cpp_ref(&(context_key)), to_cpp_ref(&(context_value)), to_cpp(colorconfig), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_colorconvert_with_processor(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ColorProcessor_t const * processor
    , _Bool unpremult
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::colorconvert(to_cpp_ref(src), to_cpp(processor), unpremult, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_colorconvert_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t fromspace
    , OIIO_string_view_t tospace
    , _Bool unpremult
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value
    , OIIO_ColorConfig_t * colorconfig
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::colorconvert(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(fromspace)), to_cpp_ref(&(tospace)), unpremult, to_cpp_ref(&(context_key)), to_cpp_ref(&(context_value)), to_cpp(colorconfig), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_colorconvert_with_processor_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ColorProcessor_t const * processor
    , _Bool unpremult
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::colorconvert(to_cpp_ref(dst), to_cpp_ref(src), to_cpp(processor), unpremult, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_colorconvert_span(
    _Bool * return_
    , OIIO_span_float_t color
    , OIIO_ColorProcessor_t const * processor
    , _Bool unpremult)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::colorconvert(to_cpp_ref(&(color)), to_cpp(processor), unpremult);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_colormatrixtransform(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , Imath_M44f_t const * M
    , _Bool unpremult
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::colormatrixtransform(to_cpp_ref(src), to_cpp_ref(M), unpremult, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_colormatrixtransform_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , Imath_M44f_t const * M
    , _Bool unpremult
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::colormatrixtransform(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(M), unpremult, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_ociolook(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t looks
    , OIIO_string_view_t fromspace
    , OIIO_string_view_t tospace
    , _Bool unpremult
    , _Bool inverse
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value
    , OIIO_ColorConfig_t * colorconfig
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::ociolook(to_cpp_ref(src), to_cpp_ref(&(looks)), to_cpp_ref(&(fromspace)), to_cpp_ref(&(tospace)), unpremult, inverse, to_cpp_ref(&(context_key)), to_cpp_ref(&(context_value)), to_cpp(colorconfig), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_ociolook_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t looks
    , OIIO_string_view_t fromspace
    , OIIO_string_view_t tospace
    , _Bool unpremult
    , _Bool inverse
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value
    , OIIO_ColorConfig_t * colorconfig
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::ociolook(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(looks)), to_cpp_ref(&(fromspace)), to_cpp_ref(&(tospace)), unpremult, inverse, to_cpp_ref(&(context_key)), to_cpp_ref(&(context_value)), to_cpp(colorconfig), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_ociodisplay(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t display
    , OIIO_string_view_t view
    , OIIO_string_view_t fromspace
    , OIIO_string_view_t looks
    , _Bool unpremult
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value
    , OIIO_ColorConfig_t * colorconfig
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::ociodisplay(to_cpp_ref(src), to_cpp_ref(&(display)), to_cpp_ref(&(view)), to_cpp_ref(&(fromspace)), to_cpp_ref(&(looks)), unpremult, to_cpp_ref(&(context_key)), to_cpp_ref(&(context_value)), to_cpp(colorconfig), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_ociodisplay_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t display
    , OIIO_string_view_t view
    , OIIO_string_view_t fromspace
    , OIIO_string_view_t looks
    , _Bool unpremult
    , OIIO_string_view_t context_key
    , OIIO_string_view_t context_value
    , OIIO_ColorConfig_t * colorconfig
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::ociodisplay(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(display)), to_cpp_ref(&(view)), to_cpp_ref(&(fromspace)), to_cpp_ref(&(looks)), unpremult, to_cpp_ref(&(context_key)), to_cpp_ref(&(context_value)), to_cpp(colorconfig), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_ociofiletransform(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t name
    , _Bool unpremult
    , _Bool inverse
    , OIIO_ColorConfig_t * colorconfig
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::ociofiletransform(to_cpp_ref(src), to_cpp_ref(&(name)), unpremult, inverse, to_cpp(colorconfig), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_ociofiletransform_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_string_view_t name
    , _Bool unpremult
    , _Bool inverse
    , OIIO_ColorConfig_t * colorconfig
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::ociofiletransform(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(name)), unpremult, inverse, to_cpp(colorconfig), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_unpremult(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::unpremult(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_unpremult_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::unpremult(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_premult(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::premult(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_premult_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::premult(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_repremult(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::repremult(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_repremult_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::repremult(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_deepen(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , float zvalue
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::deepen(to_cpp_ref(src), zvalue, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_deepen_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , float zvalue
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::deepen(to_cpp_ref(dst), to_cpp_ref(src), zvalue, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_flatten(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::flatten(to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_flatten_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::flatten(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_deep_merge(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , _Bool occlusion_cull
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::deep_merge(to_cpp_ref(A), to_cpp_ref(B), occlusion_cull, to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_deep_merge_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * A
    , OIIO_ImageBuf_t const * B
    , _Bool occlusion_cull
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::deep_merge(to_cpp_ref(dst), to_cpp_ref(A), to_cpp_ref(B), occlusion_cull, to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_deep_holdout(
    OIIO_ImageBuf_t * * return_
    , OIIO_ImageBuf_t const * src
    , OIIO_ImageBuf_t const * holdout
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::ImageBufAlgo::deep_holdout(to_cpp_ref(src), to_cpp_ref(holdout), to_cpp_ref(&(roi)), nthreads));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_ImageBufAlgo_deep_holdout_in(
    _Bool * return_
    , OIIO_ImageBuf_t * dst
    , OIIO_ImageBuf_t const * src
    , OIIO_ImageBuf_t const * holdout
    , OIIO_ROI_t roi
    , int nthreads)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::ImageBufAlgo::deep_holdout(to_cpp_ref(dst), to_cpp_ref(src), to_cpp_ref(holdout), to_cpp_ref(&(roi)), nthreads);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

