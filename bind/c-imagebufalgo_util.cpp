#include <OpenImageIO/imagebufalgo_util.h>
#include <cppmm_bind.hpp>

namespace cppmm_bind {

namespace OIIO_NAMESPACE {

namespace OIIO = ::OIIO_NAMESPACE;

namespace ImageBufAlgo {

template <typename Func>
void parallel_image(Func f, OIIO::ROI roi, int nthreads,
                    OIIO::SplitDir splitdir) CPPMM_IGNORE;

CPPMM_IGNORE
auto IBAprep(OIIO::ROI& roi, OIIO::ImageBuf* dst, const OIIO::ImageBuf* A,
             const OIIO::ImageBuf* B, const OIIO::ImageBuf* C,
             OIIO::ImageSpec* force_spec, int prepflags) -> bool;

CPPMM_IGNORE
auto IBAprep(OIIO::ROI& roi, OIIO::ImageBuf* dst, const OIIO::ImageBuf* A,
             const OIIO::ImageBuf* B, OIIO::ImageSpec* force_spec,
             int prepflags) -> bool;

CPPMM_IGNORE
auto IBAprep(OIIO::ROI& roi, OIIO::ImageBuf* dst, const OIIO::ImageBuf* A,
             const OIIO::ImageBuf* B, int prepflags) -> bool;

CPPMM_IGNORE
auto IBAprep(OIIO::ROI& roi, OIIO::ImageBuf* dst, const OIIO::ImageBuf* A,
             int prepflags) -> bool;

enum IBAprep_flags {
    IBAprep_DEFAULT = 0,
    IBAprep_REQUIRE_ALPHA = 1,
    IBAprep_REQUIRE_Z = 2,
    IBAprep_REQUIRE_SAME_NCHANNELS = 4,
    IBAprep_NO_COPY_ROI_FULL = 8,
    IBAprep_NO_SUPPORT_VOLUME = 16,
    IBAprep_NO_COPY_METADATA = 256,
    IBAprep_COPY_ALL_METADATA = 512,
    IBAprep_CLAMP_MUTUAL_NCHANNELS = 1024,
    IBAprep_SUPPORT_DEEP = 2048,
    IBAprep_DEEP_MIXED = 4096,
    IBAprep_DST_FLOAT_PIXELS = 8192,
    IBAprep_MINIMIZE_NCHANNELS = 16384,
    IBAprep_REQUIRE_MATCHING_CHANNELS = 32768,
    IBAprep_MERGE_METADATA = 65536,
};

CPPMM_IGNORE
auto type_merge(OIIO::TypeDesc::BASETYPE a, OIIO::TypeDesc::BASETYPE b)
    -> OIIO::TypeDesc::BASETYPE;

CPPMM_IGNORE
auto type_merge(OIIO::TypeDesc a, OIIO::TypeDesc b) -> OIIO::TypeDesc;

CPPMM_IGNORE
auto type_merge(OIIO::TypeDesc a, OIIO::TypeDesc b, OIIO::TypeDesc c)
    -> OIIO::TypeDesc;

} // namespace ImageBufAlgo

} // namespace OIIO_NAMESPACE

} // namespace cppmm_bind
