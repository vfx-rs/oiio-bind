#pragma once

#ifdef __cplusplus
extern "C" {
#endif

enum OpenImageIO_v2_3_6__ImageBufAlgo__IBAprep_flags_e {
    OIIO_ImageBufAlgo_IBAprep_flags_IBAprep_DEFAULT = 0,
    OIIO_ImageBufAlgo_IBAprep_flags_IBAprep_REQUIRE_ALPHA = 1,
    OIIO_ImageBufAlgo_IBAprep_flags_IBAprep_REQUIRE_Z = 2,
    OIIO_ImageBufAlgo_IBAprep_flags_IBAprep_REQUIRE_SAME_NCHANNELS = 4,
    OIIO_ImageBufAlgo_IBAprep_flags_IBAprep_NO_COPY_ROI_FULL = 8,
    OIIO_ImageBufAlgo_IBAprep_flags_IBAprep_NO_SUPPORT_VOLUME = 16,
    OIIO_ImageBufAlgo_IBAprep_flags_IBAprep_NO_COPY_METADATA = 256,
    OIIO_ImageBufAlgo_IBAprep_flags_IBAprep_COPY_ALL_METADATA = 512,
    OIIO_ImageBufAlgo_IBAprep_flags_IBAprep_CLAMP_MUTUAL_NCHANNELS = 1024,
    OIIO_ImageBufAlgo_IBAprep_flags_IBAprep_SUPPORT_DEEP = 2048,
    OIIO_ImageBufAlgo_IBAprep_flags_IBAprep_DEEP_MIXED = 4096,
    OIIO_ImageBufAlgo_IBAprep_flags_IBAprep_DST_FLOAT_PIXELS = 8192,
    OIIO_ImageBufAlgo_IBAprep_flags_IBAprep_MINIMIZE_NCHANNELS = 16384,
    OIIO_ImageBufAlgo_IBAprep_flags_IBAprep_REQUIRE_MATCHING_CHANNELS = 32768,
    OIIO_ImageBufAlgo_IBAprep_flags_IBAprep_MERGE_METADATA = 65536,
};
typedef unsigned int OIIO_ImageBufAlgo_IBAprep_flags;

#ifdef __cplusplus
}
#endif
