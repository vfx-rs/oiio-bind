#include <OpenImageIO/imagebufalgo.h>
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OIIO_NAMESPACE {

namespace OIIO = ::OIIO_NAMESPACE;

struct Image_or_Const {
    using BoundType = OIIO::Image_or_Const;

    CPPMM_RENAME(none)
    Image_or_Const(OIIO::Image_or_Const::None n);

    CPPMM_IGNORE
    Image_or_Const(const OIIO::ImageBuf& img);

    CPPMM_RENAME(from_imagebuf)
    Image_or_Const(const OIIO::ImageBuf* img);

    CPPMM_IGNORE
    Image_or_Const(OIIO::span<const float, -1> val);

    CPPMM_RENAME(from_float)
    Image_or_Const(const float& val);

    CPPMM_RENAME(from_float_vector)
    Image_or_Const(const std::vector<float, std::allocator<float>>& val);

    CPPMM_RENAME(from_float_array)
    Image_or_Const(const float* v, unsigned long s);

    CPPMM_IGNORE
    Image_or_Const(const float* v, int s);

    auto is_img() const -> bool;
    auto is_val() const -> bool;
    auto is_empty() const -> bool;

    CPPMM_IGNORE
    auto img() const -> const OIIO::ImageBuf&;

    auto imgptr() const -> const OIIO::ImageBuf*;
    auto val() const -> OIIO::span<const float, -1>;
    auto swap(OIIO::Image_or_Const& other) -> void;

    CPPMM_RENAME(copy)
    Image_or_Const(const OIIO::Image_or_Const& rhs);

    CPPMM_IGNORE
    Image_or_Const(OIIO::Image_or_Const&&);

    CPPMM_IGNORE
    auto operator=(OIIO::Image_or_Const &&) -> OIIO::Image_or_Const&;
    ~Image_or_Const();

    struct None {
        using BoundType = OIIO::Image_or_Const::None;

    } CPPMM_OPAQUEBYTES; // struct None

} CPPMM_OPAQUEBYTES; // struct Image_or_Const

namespace ImageBufAlgo {

auto zero(OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto zero(OIIO::ImageBuf& dst, OIIO::ROI roi, int nthreads) -> bool;

auto fill(OIIO::span<const float, -1> values, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto fill(OIIO::span<const float, -1> top, OIIO::span<const float, -1> bottom,
          OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto fill(OIIO::span<const float, -1> topleft,
          OIIO::span<const float, -1> topright,
          OIIO::span<const float, -1> bottomleft,
          OIIO::span<const float, -1> bottomright, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto fill(OIIO::ImageBuf& dst, OIIO::span<const float, -1> values,
          OIIO::ROI roi, int nthreads) -> bool;

auto fill(OIIO::ImageBuf& dst, OIIO::span<const float, -1> top,
          OIIO::span<const float, -1> bottom, OIIO::ROI roi, int nthreads)
    -> bool;

auto fill(OIIO::ImageBuf& dst, OIIO::span<const float, -1> topleft,
          OIIO::span<const float, -1> topright,
          OIIO::span<const float, -1> bottomleft,
          OIIO::span<const float, -1> bottomright, OIIO::ROI roi, int nthreads)
    -> bool;

auto checker(int width, int height, int depth,
             OIIO::span<const float, -1> color1,
             OIIO::span<const float, -1> color2, int xoffset, int yoffset,
             int zoffset, OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto checker(OIIO::ImageBuf& dst, int width, int height, int depth,
             OIIO::span<const float, -1> color1,
             OIIO::span<const float, -1> color2, int xoffset, int yoffset,
             int zoffset, OIIO::ROI roi, int nthreads) -> bool;

auto noise(OIIO::string_view noisetype, float A, float B, bool mono, int seed,
           OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto noise(OIIO::ImageBuf& dst, OIIO::string_view noisetype, float A, float B,
           bool mono, int seed, OIIO::ROI roi, int nthreads) -> bool;

auto render_point(OIIO::ImageBuf& dst, int x, int y,
                  OIIO::span<const float, -1> color, OIIO::ROI roi,
                  int nthreads) -> bool;

auto render_line(OIIO::ImageBuf& dst, int x1, int y1, int x2, int y2,
                 OIIO::span<const float, -1> color, bool skip_first_point,
                 OIIO::ROI roi, int nthreads) -> bool;

auto render_box(OIIO::ImageBuf& dst, int x1, int y1, int x2, int y2,
                OIIO::span<const float, -1> color, bool fill, OIIO::ROI roi,
                int nthreads) -> bool;

enum class TextAlignX {
    Left = 0,
    Right = 1,
    Center = 2,
};

enum class TextAlignY {
    Baseline = 0,
    Top = 1,
    Bottom = 2,
    Center = 3,
};

auto render_text(OIIO::ImageBuf& dst, int x, int y, OIIO::string_view text,
                 int fontsize, OIIO::string_view fontname,
                 OIIO::span<const float, -1> textcolor,
                 OIIO::ImageBufAlgo::TextAlignX alignx,
                 OIIO::ImageBufAlgo::TextAlignY aligny, int shadow,
                 OIIO::ROI roi, int nthreads) -> bool;

auto text_size(OIIO::string_view text, int fontsize, OIIO::string_view fontname)
    -> OIIO::ROI;

auto channels(
    const OIIO::ImageBuf& src, int nchannels,
    OIIO::span<const int, -1> channelorder,
    OIIO::span<const float, -1> channelvalues,
    OIIO::span<const std::__cxx11::basic_string<char>, -1> newchannelnames,
    bool shuffle_channel_names, int nthreads) -> OIIO::ImageBuf;

auto channels(
    OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, int nchannels,
    OIIO::span<const int, -1> channelorder,
    OIIO::span<const float, -1> channelvalues,
    OIIO::span<const std::__cxx11::basic_string<char>, -1> newchannelnames,
    bool shuffle_channel_names, int nthreads) -> bool;

auto channel_append(const OIIO::ImageBuf& A, const OIIO::ImageBuf& B,
                    OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto channel_append(OIIO::ImageBuf& dst, const OIIO::ImageBuf& A,
                    const OIIO::ImageBuf& B, OIIO::ROI roi, int nthreads)
    -> bool;

auto copy(const OIIO::ImageBuf& src, OIIO::TypeDesc convert, OIIO::ROI roi,
          int nthreads) -> OIIO::ImageBuf;

auto copy(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
          OIIO::TypeDesc convert, OIIO::ROI roi, int nthreads) -> bool;

auto crop(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto crop(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, OIIO::ROI roi,
          int nthreads) -> bool;

auto cut(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto cut(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, OIIO::ROI roi,
         int nthreads) -> bool;

auto paste(OIIO::ImageBuf& dst, int xbegin, int ybegin, int zbegin, int chbegin,
           const OIIO::ImageBuf& src, OIIO::ROI srcroi, int nthreads) -> bool;

auto rotate90(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto rotate180(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto rotate270(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto rotate90(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, OIIO::ROI roi,
              int nthreads) -> bool;

auto rotate180(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, OIIO::ROI roi,
               int nthreads) -> bool;

auto rotate270(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, OIIO::ROI roi,
               int nthreads) -> bool;

auto flip(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto flop(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto transpose(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

CPPMM_RENAME(flip_in)
auto flip(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, OIIO::ROI roi,
          int nthreads) -> bool;

CPPMM_RENAME(flop_in)
auto flop(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, OIIO::ROI roi,
          int nthreads) -> bool;

auto transpose(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, OIIO::ROI roi,
               int nthreads) -> bool;

auto reorient(const OIIO::ImageBuf& src, int nthreads) -> OIIO::ImageBuf;

auto reorient(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, int nthreads)
    -> bool;

auto circular_shift(const OIIO::ImageBuf& src, int xshift, int yshift,
                    int zshift, OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto circular_shift(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, int xshift,
                    int yshift, int zshift, OIIO::ROI roi, int nthreads)
    -> bool;

auto rotate(const OIIO::ImageBuf& src, float angle,
            OIIO::string_view filtername, float filterwidth, bool recompute_roi,
            OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto rotate(const OIIO::ImageBuf& src, float angle, OIIO::Filter2D* filter,
            bool recompute_roi, OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto rotate(const OIIO::ImageBuf& src, float angle, float center_x,
            float center_y, OIIO::string_view filtername, float filterwidth,
            bool recompute_roi, OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto rotate(const OIIO::ImageBuf& src, float angle, float center_x,
            float center_y, OIIO::Filter2D* filter, bool recompute_roi,
            OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto rotate(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, float angle,
            OIIO::string_view filtername, float filterwidth, bool recompute_roi,
            OIIO::ROI roi, int nthreads) -> bool;

auto rotate(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, float angle,
            OIIO::Filter2D* filter, bool recompute_roi, OIIO::ROI roi,
            int nthreads) -> bool;

auto rotate(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, float angle,
            float center_x, float center_y, OIIO::string_view filtername,
            float filterwidth, bool recompute_roi, OIIO::ROI roi, int nthreads)
    -> bool;

auto rotate(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, float angle,
            float center_x, float center_y, OIIO::Filter2D* filter,
            bool recompute_roi, OIIO::ROI roi, int nthreads) -> bool;

auto resize(const OIIO::ImageBuf& src, OIIO::string_view filtername,
            float filterwidth, OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto resize(const OIIO::ImageBuf& src, OIIO::Filter2D* filter, OIIO::ROI roi,
            int nthreads) -> OIIO::ImageBuf;

auto resize(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
            OIIO::string_view filtername, float filterwidth, OIIO::ROI roi,
            int nthreads) -> bool;

auto resize(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
            OIIO::Filter2D* filter, OIIO::ROI roi, int nthreads) -> bool;

auto resample(const OIIO::ImageBuf& src, bool interpolate, OIIO::ROI roi,
              int nthreads) -> OIIO::ImageBuf;

auto resample(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, bool interpolate,
              OIIO::ROI roi, int nthreads) -> bool;

auto fit(const OIIO::ImageBuf& src, OIIO::string_view filtername,
         float filterwidth, bool exact, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto fit(const OIIO::ImageBuf& src, OIIO::Filter2D* filter, bool exact,
         OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto fit(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
         OIIO::string_view filtername, float filterwidth, bool exact,
         OIIO::ROI roi, int nthreads) -> bool;

auto fit(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, OIIO::Filter2D* filter,
         bool exact, OIIO::ROI roi, int nthreads) -> bool;

auto warp(const OIIO::ImageBuf& src, const Imath_2_5::Matrix33<float>& M,
          OIIO::string_view filtername, float filterwidth, bool recompute_roi,
          OIIO::ImageBuf::WrapMode wrap, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto warp(const OIIO::ImageBuf& src, const Imath_2_5::Matrix33<float>& M,
          const OIIO::Filter2D* filter, bool recompute_roi,
          OIIO::ImageBuf::WrapMode wrap, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto warp(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
          const Imath_2_5::Matrix33<float>& M, OIIO::string_view filtername,
          float filterwidth, bool recompute_roi, OIIO::ImageBuf::WrapMode wrap,
          OIIO::ROI roi, int nthreads) -> bool;

auto warp(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
          const Imath_2_5::Matrix33<float>& M, const OIIO::Filter2D* filter,
          bool recompute_roi, OIIO::ImageBuf::WrapMode wrap, OIIO::ROI roi,
          int nthreads) -> bool;

auto add(OIIO::Image_or_Const A, OIIO::Image_or_Const B, OIIO::ROI roi,
         int nthreads) -> OIIO::ImageBuf;

auto add(OIIO::ImageBuf& dst, OIIO::Image_or_Const A, OIIO::Image_or_Const B,
         OIIO::ROI roi, int nthreads) -> bool;

auto sub(OIIO::Image_or_Const A, OIIO::Image_or_Const B, OIIO::ROI roi,
         int nthreads) -> OIIO::ImageBuf;

auto sub(OIIO::ImageBuf& dst, OIIO::Image_or_Const A, OIIO::Image_or_Const B,
         OIIO::ROI roi, int nthreads) -> bool;

auto absdiff(OIIO::Image_or_Const A, OIIO::Image_or_Const B, OIIO::ROI roi,
             int nthreads) -> OIIO::ImageBuf;

auto absdiff(OIIO::ImageBuf& dst, OIIO::Image_or_Const A,
             OIIO::Image_or_Const B, OIIO::ROI roi, int nthreads) -> bool;

auto abs(const OIIO::ImageBuf& A, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto abs(OIIO::ImageBuf& dst, const OIIO::ImageBuf& A, OIIO::ROI roi,
         int nthreads) -> bool;

auto mul(OIIO::Image_or_Const A, OIIO::Image_or_Const B, OIIO::ROI roi,
         int nthreads) -> OIIO::ImageBuf;

auto mul(OIIO::ImageBuf& dst, OIIO::Image_or_Const A, OIIO::Image_or_Const B,
         OIIO::ROI roi, int nthreads) -> bool;

auto div(OIIO::Image_or_Const A, OIIO::Image_or_Const B, OIIO::ROI roi,
         int nthreads) -> OIIO::ImageBuf;

auto div(OIIO::ImageBuf& dst, OIIO::Image_or_Const A, OIIO::Image_or_Const B,
         OIIO::ROI roi, int nthreads) -> bool;

auto mad(OIIO::Image_or_Const A, OIIO::Image_or_Const B, OIIO::Image_or_Const C,
         OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto mad(OIIO::ImageBuf& dst, OIIO::Image_or_Const A, OIIO::Image_or_Const B,
         OIIO::Image_or_Const C, OIIO::ROI roi, int nthreads) -> bool;

auto over(const OIIO::ImageBuf& A, const OIIO::ImageBuf& B, OIIO::ROI roi,
          int nthreads) -> OIIO::ImageBuf;

auto over(OIIO::ImageBuf& dst, const OIIO::ImageBuf& A, const OIIO::ImageBuf& B,
          OIIO::ROI roi, int nthreads) -> bool;

auto zover(const OIIO::ImageBuf& A, const OIIO::ImageBuf& B, bool z_zeroisinf,
           OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto zover(OIIO::ImageBuf& dst, const OIIO::ImageBuf& A,
           const OIIO::ImageBuf& B, bool z_zeroisinf, OIIO::ROI roi,
           int nthreads) -> bool;

auto invert(const OIIO::ImageBuf& A, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto invert(OIIO::ImageBuf& dst, const OIIO::ImageBuf& A, OIIO::ROI roi,
            int nthreads) -> bool;

auto pow(const OIIO::ImageBuf& A, OIIO::span<const float, -1> B, OIIO::ROI roi,
         int nthreads) -> OIIO::ImageBuf;

auto pow(OIIO::ImageBuf& dst, const OIIO::ImageBuf& A,
         OIIO::span<const float, -1> B, OIIO::ROI roi, int nthreads) -> bool;

auto channel_sum(const OIIO::ImageBuf& src, OIIO::span<const float, -1> weights,
                 OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto channel_sum(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
                 OIIO::span<const float, -1> weights, OIIO::ROI roi,
                 int nthreads) -> bool;

auto max(OIIO::Image_or_Const A, OIIO::Image_or_Const B, OIIO::ROI roi,
         int nthreads) -> OIIO::ImageBuf;

auto max(OIIO::ImageBuf& dst, OIIO::Image_or_Const A, OIIO::Image_or_Const B,
         OIIO::ROI roi, int nthreads) -> bool;

auto min(OIIO::Image_or_Const A, OIIO::Image_or_Const B, OIIO::ROI roi,
         int nthreads) -> OIIO::ImageBuf;

auto min(OIIO::ImageBuf& dst, OIIO::Image_or_Const A, OIIO::Image_or_Const B,
         OIIO::ROI roi, int nthreads) -> bool;

auto clamp(const OIIO::ImageBuf& src, OIIO::span<const float, -1> min,
           OIIO::span<const float, -1> max, bool clampalpha01, OIIO::ROI roi,
           int nthreads) -> OIIO::ImageBuf;

auto clamp(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
           OIIO::span<const float, -1> min, OIIO::span<const float, -1> max,
           bool clampalpha01, OIIO::ROI roi, int nthreads) -> bool;

auto contrast_remap(const OIIO::ImageBuf& src,
                    OIIO::span<const float, -1> black,
                    OIIO::span<const float, -1> white,
                    OIIO::span<const float, -1> min,
                    OIIO::span<const float, -1> max,
                    OIIO::span<const float, -1> scontrast,
                    OIIO::span<const float, -1> sthresh, OIIO::ROI,
                    int nthreads) -> OIIO::ImageBuf;

auto contrast_remap(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
                    OIIO::span<const float, -1> black,
                    OIIO::span<const float, -1> white,
                    OIIO::span<const float, -1> min,
                    OIIO::span<const float, -1> max,
                    OIIO::span<const float, -1> scontrast,
                    OIIO::span<const float, -1> sthresh, OIIO::ROI,
                    int nthreads) -> bool;

auto color_map(const OIIO::ImageBuf& src, int srcchannel, int nknots,
               int channels, OIIO::span<const float, -1> knots, OIIO::ROI roi,
               int nthreads) -> OIIO::ImageBuf;

auto color_map(const OIIO::ImageBuf& src, int srcchannel,
               OIIO::string_view mapname, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto color_map(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, int srcchannel,
               int nknots, int channels, OIIO::span<const float, -1> knots,
               OIIO::ROI roi, int nthreads) -> bool;

auto color_map(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, int srcchannel,
               OIIO::string_view mapname, OIIO::ROI roi, int nthreads) -> bool;

auto rangecompress(const OIIO::ImageBuf& src, bool useluma, OIIO::ROI roi,
                   int nthreads) -> OIIO::ImageBuf;

auto rangeexpand(const OIIO::ImageBuf& src, bool useluma, OIIO::ROI roi,
                 int nthreads) -> OIIO::ImageBuf;

auto rangecompress(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, bool useluma,
                   OIIO::ROI roi, int nthreads) -> bool;

auto rangeexpand(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, bool useluma,
                 OIIO::ROI roi, int nthreads) -> bool;

/*
struct PixelStats {
    using BoundType = OIIO::ImageBufAlgo::PixelStats;

    PixelStats();

    CPPMM_IGNORE
    PixelStats(OIIO::ImageBufAlgo::PixelStats&& other);
    PixelStats(int nchannels);
    auto reset(int nchannels) -> void;

    auto merge(const OIIO::ImageBufAlgo::PixelStats& p) -> void;

    CPPMM_IGNORE
    auto operator=(OIIO::ImageBufAlgo::PixelStats&& other)
        -> const OIIO::ImageBufAlgo::PixelStats&;

    CPPMM_IGNORE
    PixelStats(const OIIO::ImageBufAlgo::PixelStats&);
    ~PixelStats();
} CPPMM_OPAQUEBYTES; // struct PixelStats

auto computePixelStats(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBufAlgo::PixelStats;

auto computePixelStats(OIIO::ImageBufAlgo::PixelStats& stats,
                       const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> bool;
    */

struct CompareResults {
    using BoundType = OIIO::ImageBufAlgo::CompareResults;

} CPPMM_OPAQUEBYTES; // struct CompareResults

auto compare(const OIIO::ImageBuf& A, const OIIO::ImageBuf& B, float failthresh,
             float warnthresh, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBufAlgo::CompareResults;

auto compare_Yee(const OIIO::ImageBuf& A, const OIIO::ImageBuf& B,
                 OIIO::ImageBufAlgo::CompareResults& result, float luminance,
                 float fov, OIIO::ROI roi, int nthreads) -> int;

auto compare(const OIIO::ImageBuf& A, const OIIO::ImageBuf& B, float failthresh,
             float warnthresh, OIIO::ImageBufAlgo::CompareResults& result,
             OIIO::ROI roi, int nthreads) -> bool;

auto isConstantColor(const OIIO::ImageBuf& src, float threshold,
                     OIIO::span<float, -1> color, OIIO::ROI roi, int nthreads)
    -> bool;

auto isConstantColor(const OIIO::ImageBuf& src, OIIO::span<float, -1> color,
                     OIIO::ROI roi, int nthreads) -> bool;

auto isConstantChannel(const OIIO::ImageBuf& src, int channel, float val,
                       float threshold, OIIO::ROI roi, int nthreads) -> bool;

auto isConstantChannel(const OIIO::ImageBuf& src, int channel, float val,
                       OIIO::ROI roi, int nthreads) -> bool;

auto isMonochrome(const OIIO::ImageBuf& src, float threshold, OIIO::ROI roi,
                  int nthreads) -> bool;

auto isMonochrome(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> bool;

auto color_count(const OIIO::ImageBuf& src, unsigned long* count, int ncolors,
                 OIIO::span<const float, -1> color,
                 OIIO::span<const float, -1> eps, OIIO::ROI roi, int nthreads)
    -> bool;

auto color_range_check(const OIIO::ImageBuf& src, unsigned long* lowcount,
                       unsigned long* highcount, unsigned long* inrangecount,
                       OIIO::span<const float, -1> low,
                       OIIO::span<const float, -1> high, OIIO::ROI roi,
                       int nthreads) -> bool;

auto nonzero_region(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ROI;

auto computePixelHashSHA1(const OIIO::ImageBuf& src,
                          OIIO::string_view extrainfo, OIIO::ROI roi,
                          int blocksize, int nthreads) -> std::string;

CPPMM_IGNORE
auto histogram(const OIIO::ImageBuf& src, int channel, int bins, float min,
               float max, bool ignore_empty, OIIO::ROI roi, int nthreads)
    -> std::vector<unsigned long, std::allocator<unsigned long>>;

auto histogram(
    const OIIO::ImageBuf& src, int channel,
    std::vector<unsigned long, std::allocator<unsigned long>>& histogram,
    int bins, float min, float max, unsigned long* submin,
    unsigned long* supermax, OIIO::ROI roi) -> bool;

auto histogram_draw(
    OIIO::ImageBuf& dst,
    const std::vector<unsigned long, std::allocator<unsigned long>>& histogram)
    -> bool;

auto make_kernel(OIIO::string_view name, float width, float height, float depth,
                 bool normalize) -> OIIO::ImageBuf;

auto make_kernel(OIIO::ImageBuf& dst, OIIO::string_view name, float width,
                 float height, float depth, bool normalize) -> bool;

auto convolve(const OIIO::ImageBuf& src, const OIIO::ImageBuf& kernel,
              bool normalize, OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto convolve(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
              const OIIO::ImageBuf& kernel, bool normalize, OIIO::ROI roi,
              int nthreads) -> bool;

auto laplacian(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto laplacian(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, OIIO::ROI roi,
               int nthreads) -> bool;

auto fft(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto ifft(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto fft(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, OIIO::ROI roi,
         int nthreads) -> bool;

auto ifft(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, OIIO::ROI roi,
          int nthreads) -> bool;

auto complex_to_polar(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto complex_to_polar(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
                      OIIO::ROI roi, int nthreads) -> bool;

auto polar_to_complex(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto polar_to_complex(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
                      OIIO::ROI roi, int nthreads) -> bool;

enum NonFiniteFixMode {
    NONFINITE_NONE = 0,
    NONFINITE_BLACK = 1,
    NONFINITE_BOX3 = 2,
    NONFINITE_ERROR = 100,
};

auto fixNonFinite(const OIIO::ImageBuf& src,
                  OIIO::ImageBufAlgo::NonFiniteFixMode mode, int* pixelsFixed,
                  OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto fixNonFinite(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
                  OIIO::ImageBufAlgo::NonFiniteFixMode mode, int* pixelsFixed,
                  OIIO::ROI roi, int nthreads) -> bool;

auto fillholes_pushpull(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto fillholes_pushpull(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
                        OIIO::ROI roi, int nthreads) -> bool;

auto median_filter(const OIIO::ImageBuf& src, int width, int height,
                   OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto median_filter(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, int width,
                   int height, OIIO::ROI roi, int nthreads) -> bool;

auto unsharp_mask(const OIIO::ImageBuf& src, OIIO::string_view kernel,
                  float width, float contrast, float threshold, OIIO::ROI roi,
                  int nthreads) -> OIIO::ImageBuf;

auto unsharp_mask(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
                  OIIO::string_view kernel, float width, float contrast,
                  float threshold, OIIO::ROI roi, int nthreads) -> bool;

auto dilate(const OIIO::ImageBuf& src, int width, int height, OIIO::ROI roi,
            int nthreads) -> OIIO::ImageBuf;

auto dilate(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, int width,
            int height, OIIO::ROI roi, int nthreads) -> bool;

auto erode(const OIIO::ImageBuf& src, int width, int height, OIIO::ROI roi,
           int nthreads) -> OIIO::ImageBuf;

auto erode(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, int width,
           int height, OIIO::ROI roi, int nthreads) -> bool;

auto colorconvert(const OIIO::ImageBuf& src, OIIO::string_view fromspace,
                  OIIO::string_view tospace, bool unpremult,
                  OIIO::string_view context_key,
                  OIIO::string_view context_value,
                  OIIO::ColorConfig* colorconfig, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto colorconvert(const OIIO::ImageBuf& src,
                  const OIIO::ColorProcessor* processor, bool unpremult,
                  OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto colorconvert(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
                  OIIO::string_view fromspace, OIIO::string_view tospace,
                  bool unpremult, OIIO::string_view context_key,
                  OIIO::string_view context_value,
                  OIIO::ColorConfig* colorconfig, OIIO::ROI roi, int nthreads)
    -> bool;

auto colorconvert(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
                  const OIIO::ColorProcessor* processor, bool unpremult,
                  OIIO::ROI roi, int nthreads) -> bool;

auto colorconvert(OIIO::span<float, -1> color,
                  const OIIO::ColorProcessor* processor, bool unpremult)
    -> bool;

auto colorconvert(float* color, int nchannels,
                  const OIIO::ColorProcessor* processor, bool unpremult)
    -> bool;

auto colormatrixtransform(const OIIO::ImageBuf& src,
                          const Imath_2_5::Matrix44<float>& M, bool unpremult,
                          OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto colormatrixtransform(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
                          const Imath_2_5::Matrix44<float>& M, bool unpremult,
                          OIIO::ROI roi, int nthreads) -> bool;

auto ociolook(const OIIO::ImageBuf& src, OIIO::string_view looks,
              OIIO::string_view fromspace, OIIO::string_view tospace,
              bool unpremult, bool inverse, OIIO::string_view context_key,
              OIIO::string_view context_value, OIIO::ColorConfig* colorconfig,
              OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto ociolook(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
              OIIO::string_view looks, OIIO::string_view fromspace,
              OIIO::string_view tospace, bool unpremult, bool inverse,
              OIIO::string_view context_key, OIIO::string_view context_value,
              OIIO::ColorConfig* colorconfig, OIIO::ROI roi, int nthreads)
    -> bool;

auto ociodisplay(const OIIO::ImageBuf& src, OIIO::string_view display,
                 OIIO::string_view view, OIIO::string_view fromspace,
                 OIIO::string_view looks, bool unpremult,
                 OIIO::string_view context_key, OIIO::string_view context_value,
                 OIIO::ColorConfig* colorconfig, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto ociodisplay(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
                 OIIO::string_view display, OIIO::string_view view,
                 OIIO::string_view fromspace, OIIO::string_view looks,
                 bool unpremult, OIIO::string_view context_key,
                 OIIO::string_view context_value,
                 OIIO::ColorConfig* colorconfig, OIIO::ROI roi, int nthreads)
    -> bool;

auto ociofiletransform(const OIIO::ImageBuf& src, OIIO::string_view name,
                       bool unpremult, bool inverse,
                       OIIO::ColorConfig* colorconfig, OIIO::ROI roi,
                       int nthreads) -> OIIO::ImageBuf;

auto ociofiletransform(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
                       OIIO::string_view name, bool unpremult, bool inverse,
                       OIIO::ColorConfig* colorconfig, OIIO::ROI roi,
                       int nthreads) -> bool;

auto unpremult(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto unpremult(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, OIIO::ROI roi,
               int nthreads) -> bool;

auto premult(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto premult(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, OIIO::ROI roi,
             int nthreads) -> bool;

auto repremult(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto repremult(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, OIIO::ROI roi,
               int nthreads) -> bool;

enum MakeTextureMode {
    MakeTxTexture = 0,
    MakeTxShadow = 1,
    MakeTxEnvLatl = 2,
    MakeTxEnvLatlFromLightProbe = 3,
    MakeTxBumpWithSlopes = 4,
    _MakeTxLast = 5,
};

auto make_texture(OIIO::ImageBufAlgo::MakeTextureMode mode,
                  const OIIO::ImageBuf& input, OIIO::string_view outputfilename,
                  const OIIO::ImageSpec& config,
                  std::basic_ostream<char>* outstream) -> bool;

auto make_texture(OIIO::ImageBufAlgo::MakeTextureMode mode,
                  OIIO::string_view filename, OIIO::string_view outputfilename,
                  const OIIO::ImageSpec& config,
                  std::basic_ostream<char>* outstream) -> bool;

auto make_texture(
    OIIO::ImageBufAlgo::MakeTextureMode mode,
    const std::vector<std::__cxx11::basic_string<char>,
                      std::allocator<std::__cxx11::basic_string<char>>>&
        filenames,
    OIIO::string_view outputfilename, const OIIO::ImageSpec& config,
    std::basic_ostream<char>* outstream) -> bool;

auto from_OpenCV(const cv::Mat& mat, OIIO::TypeDesc convert, OIIO::ROI roi,
                 int nthreads) -> OIIO::ImageBuf;

auto to_OpenCV(cv::Mat& dst, const OIIO::ImageBuf& src, OIIO::ROI roi,
               int nthreads) -> bool;

auto capture_image(int cameranum, OIIO::TypeDesc convert) -> OIIO::ImageBuf;

auto capture_image(OIIO::ImageBuf& dst, int cameranum, OIIO::TypeDesc convert)
    -> bool;

auto deepen(const OIIO::ImageBuf& src, float zvalue, OIIO::ROI roi,
            int nthreads) -> OIIO::ImageBuf;

auto deepen(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, float zvalue,
            OIIO::ROI roi, int nthreads) -> bool;

auto flatten(const OIIO::ImageBuf& src, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto flatten(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, OIIO::ROI roi,
             int nthreads) -> bool;

auto deep_merge(const OIIO::ImageBuf& A, const OIIO::ImageBuf& B,
                bool occlusion_cull, OIIO::ROI roi, int nthreads)
    -> OIIO::ImageBuf;

auto deep_merge(OIIO::ImageBuf& dst, const OIIO::ImageBuf& A,
                const OIIO::ImageBuf& B, bool occlusion_cull, OIIO::ROI roi,
                int nthreads) -> bool;

auto deep_holdout(const OIIO::ImageBuf& src, const OIIO::ImageBuf& holdout,
                  OIIO::ROI roi, int nthreads) -> OIIO::ImageBuf;

auto deep_holdout(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
                  const OIIO::ImageBuf& holdout, OIIO::ROI roi, int nthreads)
    -> bool;

auto fill(OIIO::ImageBuf& dst, const float* values, OIIO::ROI roi, int nthreads)
    -> bool;

auto fill(OIIO::ImageBuf& dst, const float* top, const float* bottom,
          OIIO::ROI roi, int nthreads) -> bool;

auto fill(OIIO::ImageBuf& dst, const float* topleft, const float* topright,
          const float* bottomleft, const float* bottomright, OIIO::ROI roi,
          int nthreads) -> bool;

auto checker(OIIO::ImageBuf& dst, int width, int height, int depth,
             const float* color1, const float* color2, int xoffset, int yoffset,
             int zoffset, OIIO::ROI roi, int nthreads) -> bool;

auto add(OIIO::ImageBuf& dst, const OIIO::ImageBuf& A, const float* B,
         OIIO::ROI roi, int nthreads) -> bool;

auto sub(OIIO::ImageBuf& dst, const OIIO::ImageBuf& A, const float* B,
         OIIO::ROI roi, int nthreads) -> bool;

auto absdiff(OIIO::ImageBuf& dst, const OIIO::ImageBuf& A, const float* B,
             OIIO::ROI roi, int nthreads) -> bool;

auto mul(OIIO::ImageBuf& dst, const OIIO::ImageBuf& A, const float* B,
         OIIO::ROI roi, int nthreads) -> bool;

auto div(OIIO::ImageBuf& dst, const OIIO::ImageBuf& A, const float* B,
         OIIO::ROI roi, int nthreads) -> bool;

auto mad(OIIO::ImageBuf& dst, const OIIO::ImageBuf& A, const float* B,
         const OIIO::ImageBuf& C, OIIO::ROI roi, int nthreads) -> bool;

auto mad(OIIO::ImageBuf& dst, const OIIO::ImageBuf& A, const OIIO::ImageBuf& B,
         const float* C, OIIO::ROI roi, int nthreads) -> bool;

auto mad(OIIO::ImageBuf& dst, const OIIO::ImageBuf& A, const float* B,
         const float* C, OIIO::ROI roi, int nthreads) -> bool;

auto pow(OIIO::ImageBuf& dst, const OIIO::ImageBuf& A, const float* B,
         OIIO::ROI roi, int nthreads) -> bool;

auto channel_sum(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src,
                 const float* weights, OIIO::ROI roi, int nthreads) -> bool;

auto channels(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, int nchannels,
              const int* channelorder, const float* channelvalues,
              const std::string* newchannelnames, bool shuffle_channel_names,
              int nthreads) -> bool;

auto clamp(OIIO::ImageBuf& dst, const OIIO::ImageBuf& src, const float* min,
           const float* max, bool clampalpha01, OIIO::ROI roi, int nthreads)
    -> bool;

auto isConstantColor(const OIIO::ImageBuf& src, float* color, OIIO::ROI roi,
                     int nthreads) -> bool;

auto color_count(const OIIO::ImageBuf& src, unsigned long* count, int ncolors,
                 const float* color, const float* eps, OIIO::ROI roi,
                 int nthreads) -> bool;

auto color_range_check(const OIIO::ImageBuf& src, unsigned long* lowcount,
                       unsigned long* highcount, unsigned long* inrangecount,
                       const float* low, const float* high, OIIO::ROI roi,
                       int nthreads) -> bool;

auto render_text(OIIO::ImageBuf& dst, int x, int y, OIIO::string_view text,
                 int fontsize, OIIO::string_view fontname,
                 const float* textcolor) -> bool;

} // namespace ImageBufAlgo

} // namespace OIIO_NAMESPACE

} // namespace cppmm_bind
