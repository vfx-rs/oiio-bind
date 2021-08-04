#pragma once
#include <c-string_view.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Quick structure that describes a filter. */
typedef struct OpenImageIO_v2_3_6__FilterDesc_t_s {
    char data[24];
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__FilterDesc_t;
typedef OpenImageIO_v2_3_6__FilterDesc_t OIIO_FilterDesc_t;

/** Filter1D is the abstract data type for a 1D filter.
The filters are NOT expected to have their results normalized. */
typedef struct OpenImageIO_v2_3_6__Filter1D_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__Filter1D_t;
typedef OpenImageIO_v2_3_6__Filter1D_t OIIO_Filter1D_t;

/** Filter2D is the abstract data type for a 2D filter.
The filters are NOT expected to have their results normalized. */
typedef struct OpenImageIO_v2_3_6__Filter2D_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__Filter2D_t;
typedef OpenImageIO_v2_3_6__Filter2D_t OIIO_Filter2D_t;


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__FilterDesc_sizeof();
#define OIIO_FilterDesc_sizeof OpenImageIO_v2_3_6__FilterDesc_sizeof


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__FilterDesc_alignof();
#define OIIO_FilterDesc_alignof OpenImageIO_v2_3_6__FilterDesc_alignof


unsigned int OpenImageIO_v2_3_6__Filter1D_dtor(
    OIIO_Filter1D_t * this_);
#define OIIO_Filter1D_dtor OpenImageIO_v2_3_6__Filter1D_dtor


/** Get the width of the filter */
unsigned int OpenImageIO_v2_3_6__Filter1D_width(
    OIIO_Filter1D_t const * this_
    , float * return_);
#define OIIO_Filter1D_width OpenImageIO_v2_3_6__Filter1D_width


/** Evaluate the filter at an x position (relative to filter center) */
unsigned int OpenImageIO_v2_3_6__Filter1D__op_call(
    OIIO_Filter1D_t const * this_
    , float * return_
    , float x);
#define OIIO_Filter1D__op_call OpenImageIO_v2_3_6__Filter1D__op_call


/** Return the name of the filter, e.g., "box", "gaussian" */
unsigned int OpenImageIO_v2_3_6__Filter1D_name(
    OIIO_Filter1D_t const * this_
    , OIIO_string_view_t * return_);
#define OIIO_Filter1D_name OpenImageIO_v2_3_6__Filter1D_name


/** This static function allocates and returns an instance of the
specific filter implementation for the name you provide.
Example use:
       Filter1D *myfilt = Filter1::create ("box", 1);
The caller is responsible for deleting it when it's done.
If the name is not recognized, return NULL. */
unsigned int OpenImageIO_v2_3_6__Filter1D_create(
    OIIO_Filter1D_t * * return_
    , OIIO_string_view_t filtername
    , float width);
#define OIIO_Filter1D_create OpenImageIO_v2_3_6__Filter1D_create


/** Destroy a filter that was created with create(). */
unsigned int OpenImageIO_v2_3_6__Filter1D_destroy(
    OIIO_Filter1D_t * filt);
#define OIIO_Filter1D_destroy OpenImageIO_v2_3_6__Filter1D_destroy


/** Get the number of filters supported. */
unsigned int OpenImageIO_v2_3_6__Filter1D_num_filters(
    int * return_);
#define OIIO_Filter1D_num_filters OpenImageIO_v2_3_6__Filter1D_num_filters


/** Get the info for a particular index (0..num_filters()-1). */
unsigned int OpenImageIO_v2_3_6__Filter1D_get_filterdesc(
    int filternum
    , OIIO_FilterDesc_t * filterdesc);
#define OIIO_Filter1D_get_filterdesc OpenImageIO_v2_3_6__Filter1D_get_filterdesc


unsigned int OpenImageIO_v2_3_6__Filter1D__assign(
    OIIO_Filter1D_t * this_
    , OIIO_Filter1D_t * * return_
    , OIIO_Filter1D_t const * rhs);
#define OIIO_Filter1D__assign OpenImageIO_v2_3_6__Filter1D__assign


unsigned int OpenImageIO_v2_3_6__Filter2D_dtor(
    OIIO_Filter2D_t * this_);
#define OIIO_Filter2D_dtor OpenImageIO_v2_3_6__Filter2D_dtor


/** Get the width of the filter */
unsigned int OpenImageIO_v2_3_6__Filter2D_width(
    OIIO_Filter2D_t const * this_
    , float * return_);
#define OIIO_Filter2D_width OpenImageIO_v2_3_6__Filter2D_width


/** Get the height of the filter */
unsigned int OpenImageIO_v2_3_6__Filter2D_height(
    OIIO_Filter2D_t const * this_
    , float * return_);
#define OIIO_Filter2D_height OpenImageIO_v2_3_6__Filter2D_height


/** Is the filter separable? */
unsigned int OpenImageIO_v2_3_6__Filter2D_separable(
    OIIO_Filter2D_t const * this_
    , _Bool * return_);
#define OIIO_Filter2D_separable OpenImageIO_v2_3_6__Filter2D_separable


/** Evaluate the filter at an x and y position (relative to filter
center). */
unsigned int OpenImageIO_v2_3_6__Filter2D_eval(
    OIIO_Filter2D_t const * this_
    , float * return_
    , float x
    , float y);
#define OIIO_Filter2D_eval OpenImageIO_v2_3_6__Filter2D_eval


/** Evaluate just the horizontal filter (if separable; for non-separable
it just evaluates at (x,0). */
unsigned int OpenImageIO_v2_3_6__Filter2D_xfilt(
    OIIO_Filter2D_t const * this_
    , float * return_
    , float x);
#define OIIO_Filter2D_xfilt OpenImageIO_v2_3_6__Filter2D_xfilt


/** Evaluate just the vertical filter (if separable; for non-separable
it just evaluates at (0,y). */
unsigned int OpenImageIO_v2_3_6__Filter2D_yfilt(
    OIIO_Filter2D_t const * this_
    , float * return_
    , float y);
#define OIIO_Filter2D_yfilt OpenImageIO_v2_3_6__Filter2D_yfilt


/** Return the name of the filter, e.g., "box", "gaussian" */
unsigned int OpenImageIO_v2_3_6__Filter2D_name(
    OIIO_Filter2D_t const * this_
    , OIIO_string_view_t * return_);
#define OIIO_Filter2D_name OpenImageIO_v2_3_6__Filter2D_name


/** This static function allocates and returns an instance of the
specific filter implementation for the name you provide.
Example use:
       Filter2D *myfilt = Filter2::create ("box", 1, 1);
The caller is responsible for deleting it when it's done.
If the name is not recognized, return NULL. */
unsigned int OpenImageIO_v2_3_6__Filter2D_create(
    OIIO_Filter2D_t * * return_
    , OIIO_string_view_t filtername
    , float width
    , float height);
#define OIIO_Filter2D_create OpenImageIO_v2_3_6__Filter2D_create


/** Destroy a filter that was created with create(). */
unsigned int OpenImageIO_v2_3_6__Filter2D_destroy(
    OIIO_Filter2D_t * filt);
#define OIIO_Filter2D_destroy OpenImageIO_v2_3_6__Filter2D_destroy


/** Get the number of filters supported. */
unsigned int OpenImageIO_v2_3_6__Filter2D_num_filters(
    int * return_);
#define OIIO_Filter2D_num_filters OpenImageIO_v2_3_6__Filter2D_num_filters


/** Get the info for a particular index (0..num_filters()-1). */
unsigned int OpenImageIO_v2_3_6__Filter2D_get_filterdesc(
    int filternum
    , OIIO_FilterDesc_t * filterdesc);
#define OIIO_Filter2D_get_filterdesc OpenImageIO_v2_3_6__Filter2D_get_filterdesc


unsigned int OpenImageIO_v2_3_6__Filter2D__assign(
    OIIO_Filter2D_t * this_
    , OIIO_Filter2D_t * * return_
    , OIIO_Filter2D_t const * rhs);
#define OIIO_Filter2D__assign OpenImageIO_v2_3_6__Filter2D__assign


#ifdef __cplusplus
}
#endif
