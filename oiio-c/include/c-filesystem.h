#pragma once
#include <c-span.h>
#include <c-std_string.h>
#include <c-string_view.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct std__vector_int__t_s std__vector_int__t;
typedef std__vector_int__t std_vector_int_t;
typedef struct std__string_t_s std__string_t;
typedef std__string_t std_string_t;
typedef struct std__vector_unsignedchar__t_s std__vector_unsignedchar__t;
typedef std__vector_unsignedchar__t std_vector_uchar_t;
typedef struct std__vector_std__string__t_s std__vector_std__string__t;
typedef std__vector_std__string__t std_vector_string_t;
typedef struct std__vector_OIIO__string_view__t_s std__vector_OIIO__string_view__t;
typedef std__vector_OIIO__string_view__t std_vector_string_view_t;

enum OpenImageIO_v2_3_6__Filesystem__IOProxy__Mode_e {
    OIIO_Filesystem_IOProxy_Mode_Closed = 0,
    OIIO_Filesystem_IOProxy_Mode_Read = 114,
    OIIO_Filesystem_IOProxy_Mode_Write = 119,
};
typedef unsigned int OIIO_Filesystem_IOProxy_Mode;

/** Proxy class for I/O. This provides a simplified interface for file I/O
that can have custom overrides. */
typedef struct OpenImageIO_v2_3_6__Filesystem__IOProxy_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__Filesystem__IOProxy_t;
typedef OpenImageIO_v2_3_6__Filesystem__IOProxy_t OIIO_Filesystem_IOProxy_t;

/** IOProxy subclass for reading or writing (but not both) that wraps C
stdio 'FILE'. */
typedef struct OpenImageIO_v2_3_6__Filesystem__IOFile_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__Filesystem__IOFile_t;
typedef OpenImageIO_v2_3_6__Filesystem__IOFile_t OIIO_Filesystem_IOFile_t;

/** IOProxy subclass for writing that wraps a std::vector<char> that will
grow as we write. */
typedef struct OpenImageIO_v2_3_6__Filesystem__IOVecOutput_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__Filesystem__IOVecOutput_t;
typedef OpenImageIO_v2_3_6__Filesystem__IOVecOutput_t OIIO_Filesystem_IOVecOutput_t;

/** IOProxy subclass for reading that wraps an cspan<char>. */
typedef struct OpenImageIO_v2_3_6__Filesystem__IOMemReader_t_s {
    char _unused;
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__Filesystem__IOMemReader_t;
typedef OpenImageIO_v2_3_6__Filesystem__IOMemReader_t OIIO_Filesystem_IOMemReader_t;


unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_dtor(
    OIIO_Filesystem_IOProxy_t * this_);
#define OIIO_Filesystem_IOProxy_dtor OpenImageIO_v2_3_6__Filesystem__IOProxy_dtor


unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_proxytype(
    OIIO_Filesystem_IOProxy_t const * this_
    , char const * * return_);
#define OIIO_Filesystem_IOProxy_proxytype OpenImageIO_v2_3_6__Filesystem__IOProxy_proxytype


unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_close(
    OIIO_Filesystem_IOProxy_t * this_);
#define OIIO_Filesystem_IOProxy_close OpenImageIO_v2_3_6__Filesystem__IOProxy_close


unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_opened(
    OIIO_Filesystem_IOProxy_t const * this_
    , _Bool * return_);
#define OIIO_Filesystem_IOProxy_opened OpenImageIO_v2_3_6__Filesystem__IOProxy_opened


unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_tell(
    OIIO_Filesystem_IOProxy_t * this_
    , long * return_);
#define OIIO_Filesystem_IOProxy_tell OpenImageIO_v2_3_6__Filesystem__IOProxy_tell


unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_seek(
    OIIO_Filesystem_IOProxy_t * this_
    , _Bool * return_
    , long offset);
#define OIIO_Filesystem_IOProxy_seek OpenImageIO_v2_3_6__Filesystem__IOProxy_seek


unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_read(
    OIIO_Filesystem_IOProxy_t * this_
    , unsigned long * return_
    , void * buf
    , unsigned long size);
#define OIIO_Filesystem_IOProxy_read OpenImageIO_v2_3_6__Filesystem__IOProxy_read


unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_write(
    OIIO_Filesystem_IOProxy_t * this_
    , unsigned long * return_
    , void const * buf
    , unsigned long size);
#define OIIO_Filesystem_IOProxy_write OpenImageIO_v2_3_6__Filesystem__IOProxy_write


unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_pread(
    OIIO_Filesystem_IOProxy_t * this_
    , unsigned long * return_
    , void * buf
    , unsigned long size
    , long offset);
#define OIIO_Filesystem_IOProxy_pread OpenImageIO_v2_3_6__Filesystem__IOProxy_pread


unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_pwrite(
    OIIO_Filesystem_IOProxy_t * this_
    , unsigned long * return_
    , void const * buf
    , unsigned long size
    , long offset);
#define OIIO_Filesystem_IOProxy_pwrite OpenImageIO_v2_3_6__Filesystem__IOProxy_pwrite


unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_size(
    OIIO_Filesystem_IOProxy_t const * this_
    , unsigned long * return_);
#define OIIO_Filesystem_IOProxy_size OpenImageIO_v2_3_6__Filesystem__IOProxy_size


unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_flush(
    OIIO_Filesystem_IOProxy_t const * this_);
#define OIIO_Filesystem_IOProxy_flush OpenImageIO_v2_3_6__Filesystem__IOProxy_flush


unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_mode(
    OIIO_Filesystem_IOProxy_t const * this_
    , OIIO_Filesystem_IOProxy_Mode * return_);
#define OIIO_Filesystem_IOProxy_mode OpenImageIO_v2_3_6__Filesystem__IOProxy_mode


unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_filename(
    OIIO_Filesystem_IOProxy_t const * this_
    , std_string_t const * * return_);
#define OIIO_Filesystem_IOProxy_filename OpenImageIO_v2_3_6__Filesystem__IOProxy_filename


unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_error(
    OIIO_Filesystem_IOProxy_t const * this_
    , std_string_t * * return_);
#define OIIO_Filesystem_IOProxy_error OpenImageIO_v2_3_6__Filesystem__IOProxy_error


unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy__assign(
    OIIO_Filesystem_IOProxy_t * this_
    , OIIO_Filesystem_IOProxy_t * * return_
    , OIIO_Filesystem_IOProxy_t const * rhs);
#define OIIO_Filesystem_IOProxy__assign OpenImageIO_v2_3_6__Filesystem__IOProxy__assign


unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_proxytype(
    OIIO_Filesystem_IOFile_t const * this_
    , char const * * return_);
#define OIIO_Filesystem_IOFile_proxytype OpenImageIO_v2_3_6__Filesystem__IOFile_proxytype


unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_close(
    OIIO_Filesystem_IOFile_t * this_);
#define OIIO_Filesystem_IOFile_close OpenImageIO_v2_3_6__Filesystem__IOFile_close


unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_opened(
    OIIO_Filesystem_IOFile_t const * this_
    , _Bool * return_);
#define OIIO_Filesystem_IOFile_opened OpenImageIO_v2_3_6__Filesystem__IOFile_opened


unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_tell(
    OIIO_Filesystem_IOFile_t * this_
    , long * return_);
#define OIIO_Filesystem_IOFile_tell OpenImageIO_v2_3_6__Filesystem__IOFile_tell


unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_seek(
    OIIO_Filesystem_IOFile_t * this_
    , _Bool * return_
    , long offset);
#define OIIO_Filesystem_IOFile_seek OpenImageIO_v2_3_6__Filesystem__IOFile_seek


unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_read(
    OIIO_Filesystem_IOFile_t * this_
    , unsigned long * return_
    , void * buf
    , unsigned long size);
#define OIIO_Filesystem_IOFile_read OpenImageIO_v2_3_6__Filesystem__IOFile_read


unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_write(
    OIIO_Filesystem_IOFile_t * this_
    , unsigned long * return_
    , void const * buf
    , unsigned long size);
#define OIIO_Filesystem_IOFile_write OpenImageIO_v2_3_6__Filesystem__IOFile_write


unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_pread(
    OIIO_Filesystem_IOFile_t * this_
    , unsigned long * return_
    , void * buf
    , unsigned long size
    , long offset);
#define OIIO_Filesystem_IOFile_pread OpenImageIO_v2_3_6__Filesystem__IOFile_pread


unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_pwrite(
    OIIO_Filesystem_IOFile_t * this_
    , unsigned long * return_
    , void const * buf
    , unsigned long size
    , long offset);
#define OIIO_Filesystem_IOFile_pwrite OpenImageIO_v2_3_6__Filesystem__IOFile_pwrite


unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_size(
    OIIO_Filesystem_IOFile_t const * this_
    , unsigned long * return_);
#define OIIO_Filesystem_IOFile_size OpenImageIO_v2_3_6__Filesystem__IOFile_size


unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_flush(
    OIIO_Filesystem_IOFile_t const * this_);
#define OIIO_Filesystem_IOFile_flush OpenImageIO_v2_3_6__Filesystem__IOFile_flush


unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_mode(
    OIIO_Filesystem_IOFile_t const * this_
    , OIIO_Filesystem_IOProxy_Mode * return_);
#define OIIO_Filesystem_IOFile_mode OpenImageIO_v2_3_6__Filesystem__IOFile_mode


unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_filename(
    OIIO_Filesystem_IOFile_t const * this_
    , std_string_t const * * return_);
#define OIIO_Filesystem_IOFile_filename OpenImageIO_v2_3_6__Filesystem__IOFile_filename


unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_error(
    OIIO_Filesystem_IOFile_t const * this_
    , std_string_t * * return_);
#define OIIO_Filesystem_IOFile_error OpenImageIO_v2_3_6__Filesystem__IOFile_error


unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_new(
    OIIO_Filesystem_IOFile_t * * this_
    , OIIO_string_view_t filename
    , OIIO_Filesystem_IOProxy_Mode mode);
#define OIIO_Filesystem_IOFile_new OpenImageIO_v2_3_6__Filesystem__IOFile_new


unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_dtor(
    OIIO_Filesystem_IOFile_t * this_);
#define OIIO_Filesystem_IOFile_dtor OpenImageIO_v2_3_6__Filesystem__IOFile_dtor


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_proxytype(
    OIIO_Filesystem_IOVecOutput_t const * this_
    , char const * * return_);
#define OIIO_Filesystem_IOVecOutput_proxytype OpenImageIO_v2_3_6__Filesystem__IOVecOutput_proxytype


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_close(
    OIIO_Filesystem_IOVecOutput_t * this_);
#define OIIO_Filesystem_IOVecOutput_close OpenImageIO_v2_3_6__Filesystem__IOVecOutput_close


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_opened(
    OIIO_Filesystem_IOVecOutput_t const * this_
    , _Bool * return_);
#define OIIO_Filesystem_IOVecOutput_opened OpenImageIO_v2_3_6__Filesystem__IOVecOutput_opened


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_tell(
    OIIO_Filesystem_IOVecOutput_t * this_
    , long * return_);
#define OIIO_Filesystem_IOVecOutput_tell OpenImageIO_v2_3_6__Filesystem__IOVecOutput_tell


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_seek(
    OIIO_Filesystem_IOVecOutput_t * this_
    , _Bool * return_
    , long offset);
#define OIIO_Filesystem_IOVecOutput_seek OpenImageIO_v2_3_6__Filesystem__IOVecOutput_seek


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_read(
    OIIO_Filesystem_IOVecOutput_t * this_
    , unsigned long * return_
    , void * buf
    , unsigned long size);
#define OIIO_Filesystem_IOVecOutput_read OpenImageIO_v2_3_6__Filesystem__IOVecOutput_read


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_write(
    OIIO_Filesystem_IOVecOutput_t * this_
    , unsigned long * return_
    , void const * buf
    , unsigned long size);
#define OIIO_Filesystem_IOVecOutput_write OpenImageIO_v2_3_6__Filesystem__IOVecOutput_write


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_pread(
    OIIO_Filesystem_IOVecOutput_t * this_
    , unsigned long * return_
    , void * buf
    , unsigned long size
    , long offset);
#define OIIO_Filesystem_IOVecOutput_pread OpenImageIO_v2_3_6__Filesystem__IOVecOutput_pread


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_pwrite(
    OIIO_Filesystem_IOVecOutput_t * this_
    , unsigned long * return_
    , void const * buf
    , unsigned long size
    , long offset);
#define OIIO_Filesystem_IOVecOutput_pwrite OpenImageIO_v2_3_6__Filesystem__IOVecOutput_pwrite


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_size(
    OIIO_Filesystem_IOVecOutput_t const * this_
    , unsigned long * return_);
#define OIIO_Filesystem_IOVecOutput_size OpenImageIO_v2_3_6__Filesystem__IOVecOutput_size


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_flush(
    OIIO_Filesystem_IOVecOutput_t const * this_);
#define OIIO_Filesystem_IOVecOutput_flush OpenImageIO_v2_3_6__Filesystem__IOVecOutput_flush


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_mode(
    OIIO_Filesystem_IOVecOutput_t const * this_
    , OIIO_Filesystem_IOProxy_Mode * return_);
#define OIIO_Filesystem_IOVecOutput_mode OpenImageIO_v2_3_6__Filesystem__IOVecOutput_mode


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_filename(
    OIIO_Filesystem_IOVecOutput_t const * this_
    , std_string_t const * * return_);
#define OIIO_Filesystem_IOVecOutput_filename OpenImageIO_v2_3_6__Filesystem__IOVecOutput_filename


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_error_const(
    OIIO_Filesystem_IOVecOutput_t const * this_
    , std_string_t * * return_);
#define OIIO_Filesystem_IOVecOutput_error_const OpenImageIO_v2_3_6__Filesystem__IOVecOutput_error_const


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_error(
    OIIO_Filesystem_IOVecOutput_t * this_
    , OIIO_string_view_t e);
#define OIIO_Filesystem_IOVecOutput_error OpenImageIO_v2_3_6__Filesystem__IOVecOutput_error


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_ctor(
    OIIO_Filesystem_IOVecOutput_t * * this_);
#define OIIO_Filesystem_IOVecOutput_ctor OpenImageIO_v2_3_6__Filesystem__IOVecOutput_ctor


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_from_buf(
    OIIO_Filesystem_IOVecOutput_t * * this_
    , std_vector_uchar_t * buf);
#define OIIO_Filesystem_IOVecOutput_from_buf OpenImageIO_v2_3_6__Filesystem__IOVecOutput_from_buf


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_buffer(
    OIIO_Filesystem_IOVecOutput_t const * this_
    , std_vector_uchar_t * * return_);
#define OIIO_Filesystem_IOVecOutput_buffer OpenImageIO_v2_3_6__Filesystem__IOVecOutput_buffer


unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_dtor(
    OIIO_Filesystem_IOVecOutput_t * this_);
#define OIIO_Filesystem_IOVecOutput_dtor OpenImageIO_v2_3_6__Filesystem__IOVecOutput_dtor


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_proxytype(
    OIIO_Filesystem_IOMemReader_t const * this_
    , char const * * return_);
#define OIIO_Filesystem_IOMemReader_proxytype OpenImageIO_v2_3_6__Filesystem__IOMemReader_proxytype


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_close(
    OIIO_Filesystem_IOMemReader_t * this_);
#define OIIO_Filesystem_IOMemReader_close OpenImageIO_v2_3_6__Filesystem__IOMemReader_close


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_opened(
    OIIO_Filesystem_IOMemReader_t const * this_
    , _Bool * return_);
#define OIIO_Filesystem_IOMemReader_opened OpenImageIO_v2_3_6__Filesystem__IOMemReader_opened


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_tell(
    OIIO_Filesystem_IOMemReader_t * this_
    , long * return_);
#define OIIO_Filesystem_IOMemReader_tell OpenImageIO_v2_3_6__Filesystem__IOMemReader_tell


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_seek(
    OIIO_Filesystem_IOMemReader_t * this_
    , _Bool * return_
    , long offset);
#define OIIO_Filesystem_IOMemReader_seek OpenImageIO_v2_3_6__Filesystem__IOMemReader_seek


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_read(
    OIIO_Filesystem_IOMemReader_t * this_
    , unsigned long * return_
    , void * buf
    , unsigned long size);
#define OIIO_Filesystem_IOMemReader_read OpenImageIO_v2_3_6__Filesystem__IOMemReader_read


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_write(
    OIIO_Filesystem_IOMemReader_t * this_
    , unsigned long * return_
    , void const * buf
    , unsigned long size);
#define OIIO_Filesystem_IOMemReader_write OpenImageIO_v2_3_6__Filesystem__IOMemReader_write


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_pread(
    OIIO_Filesystem_IOMemReader_t * this_
    , unsigned long * return_
    , void * buf
    , unsigned long size
    , long offset);
#define OIIO_Filesystem_IOMemReader_pread OpenImageIO_v2_3_6__Filesystem__IOMemReader_pread


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_pwrite(
    OIIO_Filesystem_IOMemReader_t * this_
    , unsigned long * return_
    , void const * buf
    , unsigned long size
    , long offset);
#define OIIO_Filesystem_IOMemReader_pwrite OpenImageIO_v2_3_6__Filesystem__IOMemReader_pwrite


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_size(
    OIIO_Filesystem_IOMemReader_t const * this_
    , unsigned long * return_);
#define OIIO_Filesystem_IOMemReader_size OpenImageIO_v2_3_6__Filesystem__IOMemReader_size


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_flush(
    OIIO_Filesystem_IOMemReader_t const * this_);
#define OIIO_Filesystem_IOMemReader_flush OpenImageIO_v2_3_6__Filesystem__IOMemReader_flush


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_mode(
    OIIO_Filesystem_IOMemReader_t const * this_
    , OIIO_Filesystem_IOProxy_Mode * return_);
#define OIIO_Filesystem_IOMemReader_mode OpenImageIO_v2_3_6__Filesystem__IOMemReader_mode


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_filename(
    OIIO_Filesystem_IOMemReader_t const * this_
    , std_string_t const * * return_);
#define OIIO_Filesystem_IOMemReader_filename OpenImageIO_v2_3_6__Filesystem__IOMemReader_filename


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_error(
    OIIO_Filesystem_IOMemReader_t const * this_
    , std_string_t * * return_);
#define OIIO_Filesystem_IOMemReader_error OpenImageIO_v2_3_6__Filesystem__IOMemReader_error


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_from_buf(
    OIIO_Filesystem_IOMemReader_t * * this_
    , void * buf
    , unsigned long size);
#define OIIO_Filesystem_IOMemReader_from_buf OpenImageIO_v2_3_6__Filesystem__IOMemReader_from_buf


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_buffer(
    OIIO_Filesystem_IOMemReader_t const * this_
    , OIIO_cspan_uchar_t * return_);
#define OIIO_Filesystem_IOMemReader_buffer OpenImageIO_v2_3_6__Filesystem__IOMemReader_buffer


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_copy(
    OIIO_Filesystem_IOMemReader_t * * this_
    , OIIO_Filesystem_IOMemReader_t const * rhs);
#define OIIO_Filesystem_IOMemReader_copy OpenImageIO_v2_3_6__Filesystem__IOMemReader_copy


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader__assign(
    OIIO_Filesystem_IOMemReader_t * this_
    , OIIO_Filesystem_IOMemReader_t * * return_
    , OIIO_Filesystem_IOMemReader_t const * rhs);
#define OIIO_Filesystem_IOMemReader__assign OpenImageIO_v2_3_6__Filesystem__IOMemReader__assign


unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_dtor(
    OIIO_Filesystem_IOMemReader_t * this_);
#define OIIO_Filesystem_IOMemReader_dtor OpenImageIO_v2_3_6__Filesystem__IOMemReader_dtor


/** Return the filename (excluding any directories, but including the
file extension, if any) of a filepath. */
unsigned int OpenImageIO_v2_3_6_Filesystem_filename(
    std_string_t * * return_
    , std_string_t const * filepath);
#define OIIO_Filesystem_filename OpenImageIO_v2_3_6_Filesystem_filename


/** Return the file extension (including the last '.' if
include_dot=true) of a filename or filepath. */
unsigned int OpenImageIO_v2_3_6_Filesystem_extension(
    std_string_t * * return_
    , std_string_t const * filepath
    , _Bool include_dot);
#define OIIO_Filesystem_extension OpenImageIO_v2_3_6_Filesystem_extension


/** Return all but the last part of the path, for example,
parent_path("foo/bar") returns "foo", and parent_path("foo")
returns "". */
unsigned int OpenImageIO_v2_3_6_Filesystem_parent_path(
    std_string_t * * return_
    , std_string_t const * filepath);
#define OIIO_Filesystem_parent_path OpenImageIO_v2_3_6_Filesystem_parent_path


/** Replace the file extension of a filename or filepath. Does not alter
filepath, just returns a new string.  Note that the new_extension
should contain a leading '.' dot. */
unsigned int OpenImageIO_v2_3_6_Filesystem_replace_extension(
    std_string_t * * return_
    , std_string_t const * filepath
    , std_string_t const * new_extension);
#define OIIO_Filesystem_replace_extension OpenImageIO_v2_3_6_Filesystem_replace_extension


/** Turn a searchpath (multiple directory paths separated by ':' or ';')
into a vector<string> containing each individual directory.  If
validonly is true, only existing and readable directories will end
up in the list.  N.B., the directory names will not have trailing
slashes. */
unsigned int OpenImageIO_v2_3_6_Filesystem_searchpath_split(
    std_string_t const * searchpath
    , std_vector_string_t * dirs
    , _Bool validonly);
#define OIIO_Filesystem_searchpath_split OpenImageIO_v2_3_6_Filesystem_searchpath_split


/** Find the first instance of a filename existing in a vector of
directories, returning the full path as a string.  If the file is
not found in any of the listed directories, return an empty string.
If the filename is absolute, the directory list will not be used.
If testcwd is true, "." will be tested before the searchpath;
otherwise, "." will only be tested if it's explicitly in dirs.  If
recursive is true, the directories will be searched recursively,
finding a matching file in any subdirectory of the directories
listed in dirs; otherwise. */
unsigned int OpenImageIO_v2_3_6_Filesystem_searchpath_find(
    std_string_t * * return_
    , std_string_t const * filename
    , std_vector_string_t const * dirs
    , _Bool testcwd
    , _Bool recursive);
#define OIIO_Filesystem_searchpath_find OpenImageIO_v2_3_6_Filesystem_searchpath_find


/** Fill a vector-of-strings with the names of all files contained by
directory dirname.  If recursive is true, it will return all files
below the directory (even in subdirectories), but if recursive is
false (the default)If filter_regex is supplied and non-empty, only
filenames matching the regular expression will be returned.  Return
true if ok, false if there was an error (such as dirname not being
found or not actually being a directory). */
unsigned int OpenImageIO_v2_3_6_Filesystem_get_directory_entries(
    _Bool * return_
    , std_string_t const * dirname
    , std_vector_string_t * filenames
    , _Bool recursive
    , std_string_t const * filter_regex);
#define OIIO_Filesystem_get_directory_entries OpenImageIO_v2_3_6_Filesystem_get_directory_entries


/** Return true if the path is an "absolute" (not relative) path.
If 'dot_is_absolute' is true, consider "./foo" absolute. */
unsigned int OpenImageIO_v2_3_6_Filesystem_path_is_absolute(
    _Bool * return_
    , OIIO_string_view_t path
    , _Bool dot_is_absolute);
#define OIIO_Filesystem_path_is_absolute OpenImageIO_v2_3_6_Filesystem_path_is_absolute


/** Return true if the file exists. */
unsigned int OpenImageIO_v2_3_6_Filesystem_exists(
    _Bool * return_
    , OIIO_string_view_t path);
#define OIIO_Filesystem_exists OpenImageIO_v2_3_6_Filesystem_exists


/** Return true if the file exists and is a directory. */
unsigned int OpenImageIO_v2_3_6_Filesystem_is_directory(
    _Bool * return_
    , OIIO_string_view_t path);
#define OIIO_Filesystem_is_directory OpenImageIO_v2_3_6_Filesystem_is_directory


/** Return true if the file exists and is a regular file. */
unsigned int OpenImageIO_v2_3_6_Filesystem_is_regular(
    _Bool * return_
    , OIIO_string_view_t path);
#define OIIO_Filesystem_is_regular OpenImageIO_v2_3_6_Filesystem_is_regular


/** Create the directory. Return true for success, false for failure and
place an error message in err. */
unsigned int OpenImageIO_v2_3_6_Filesystem_create_directory(
    _Bool * return_
    , OIIO_string_view_t path
    , std_string_t * err);
#define OIIO_Filesystem_create_directory OpenImageIO_v2_3_6_Filesystem_create_directory


/** Copy a file, directory, or link. It is an error if 'to' already exists.
Return true upon success, false upon failure and place an error message
in err. */
unsigned int OpenImageIO_v2_3_6_Filesystem_copy(
    _Bool * return_
    , OIIO_string_view_t from
    , OIIO_string_view_t to
    , std_string_t * err);
#define OIIO_Filesystem_copy OpenImageIO_v2_3_6_Filesystem_copy


/** Rename (or move) a file, directory, or link.  Return true upon success,
false upon failure and place an error message in err. */
unsigned int OpenImageIO_v2_3_6_Filesystem_rename(
    _Bool * return_
    , OIIO_string_view_t from
    , OIIO_string_view_t to
    , std_string_t * err);
#define OIIO_Filesystem_rename OpenImageIO_v2_3_6_Filesystem_rename


/** Remove the file or directory. Return true for success, false for
failure and place an error message in err. */
unsigned int OpenImageIO_v2_3_6_Filesystem_remove(
    _Bool * return_
    , OIIO_string_view_t path
    , std_string_t * err);
#define OIIO_Filesystem_remove OpenImageIO_v2_3_6_Filesystem_remove


/** Remove the file or directory, including any children (recursively).
Return the number of files removed.  Place an error message (if
applicable in err. */
unsigned int OpenImageIO_v2_3_6_Filesystem_remove_all(
    unsigned long long * return_
    , OIIO_string_view_t path
    , std_string_t * err);
#define OIIO_Filesystem_remove_all OpenImageIO_v2_3_6_Filesystem_remove_all


/** Return a directory path where temporary files can be made. */
unsigned int OpenImageIO_v2_3_6_Filesystem_temp_directory_path(
    std_string_t * * return_);
#define OIIO_Filesystem_temp_directory_path OpenImageIO_v2_3_6_Filesystem_temp_directory_path


/** Return a unique filename suitable for making a temporary file or
directory. */
unsigned int OpenImageIO_v2_3_6_Filesystem_unique_path(
    std_string_t * * return_
    , OIIO_string_view_t model);
#define OIIO_Filesystem_unique_path OpenImageIO_v2_3_6_Filesystem_unique_path


/** Return the current (".") directory path. */
unsigned int OpenImageIO_v2_3_6_Filesystem_current_path(
    std_string_t * * return_);
#define OIIO_Filesystem_current_path OpenImageIO_v2_3_6_Filesystem_current_path


/** Read the entire contents of the named text file and place it in str,
returning true on success, false on failure. */
unsigned int OpenImageIO_v2_3_6_Filesystem_read_text_file(
    _Bool * return_
    , OIIO_string_view_t filename
    , std_string_t * str);
#define OIIO_Filesystem_read_text_file OpenImageIO_v2_3_6_Filesystem_read_text_file


/** Write the entire contents of the string `str` to the file, overwriting
any prior contents of the file (if it existed), returning true on
success, false on failure. */
unsigned int OpenImageIO_v2_3_6_Filesystem_write_text_file(
    _Bool * return_
    , OIIO_string_view_t filename
    , OIIO_string_view_t str);
#define OIIO_Filesystem_write_text_file OpenImageIO_v2_3_6_Filesystem_write_text_file


/** Read a maximum of n bytes from the named file, starting at position pos
(which defaults to the start of the file), storing results in
buffer[0..n-1]. Return the number of bytes read, which will be n for
full success, less than n if the file was fewer than n+pos bytes long,
or 0 if the file did not exist or could not be read. */
unsigned int OpenImageIO_v2_3_6_Filesystem_read_bytes(
    unsigned long * return_
    , OIIO_string_view_t path
    , void * buffer
    , unsigned long n
    , unsigned long pos);
#define OIIO_Filesystem_read_bytes OpenImageIO_v2_3_6_Filesystem_read_bytes


/** Get last modified time of file */
unsigned int OpenImageIO_v2_3_6_Filesystem_last_write_time(
    long * return_
    , OIIO_string_view_t path);
#define OIIO_Filesystem_last_write_time OpenImageIO_v2_3_6_Filesystem_last_write_time


/** Return the size of the file (in bytes), or uint64_t(-1) if there is any
error. */
unsigned int OpenImageIO_v2_3_6_Filesystem_file_size(
    unsigned long * return_
    , OIIO_string_view_t path);
#define OIIO_Filesystem_file_size OpenImageIO_v2_3_6_Filesystem_file_size


/** Ensure command line arguments are UTF-8 everywhere */
unsigned int OpenImageIO_v2_3_6_Filesystem_convert_native_arguments(
    int argc
    , char const * * argv);
#define OIIO_Filesystem_convert_native_arguments OpenImageIO_v2_3_6_Filesystem_convert_native_arguments


/** Turn a sequence description string into a vector of integers.
The sequence description can be any of the following
 * A value (e.g., "3")
 * A value range ("1-10", "10-1", "1-10x3", "1-10y3"):
    START-FINISH        A range, inclusive of start & finish
    START-FINISHxSTEP   A range with step size
    START-FINISHySTEP   The complement of a stepped range, that is,
                          all numbers within the range that would
                          NOT have been selected by 'x'.
    Note that START may be > FINISH, or STEP may be negative.
 * Multiple values or ranges, separated by a comma (e.g., "3,4,10-20x2")
Return true upon success, false if the description was too malformed
to generate a sequence. */
unsigned int OpenImageIO_v2_3_6_Filesystem_enumerate_sequence(
    _Bool * return_
    , OIIO_string_view_t desc
    , std_vector_int_t * numbers);
#define OIIO_Filesystem_enumerate_sequence OpenImageIO_v2_3_6_Filesystem_enumerate_sequence


/** Given a pattern (such as "foo.#.tif" or "bar.1-10#.exr"), return a
normalized pattern in printf format (such as "foo.%04d.tif") and a
framespec (such as "1-10").

If framepadding_override is > 0, it overrides any specific padding amount
in the original pattern.

Return true upon success, false if the description was too malformed
to generate a sequence. */
unsigned int OpenImageIO_v2_3_6_Filesystem_parse_pattern(
    _Bool * return_
    , char const * pattern
    , int framepadding_override
    , std_string_t * normalized_pattern
    , std_string_t * framespec);
#define OIIO_Filesystem_parse_pattern OpenImageIO_v2_3_6_Filesystem_parse_pattern


/** Given a normalized pattern (such as "foo.%04d.tif") and a list of frame
numbers, generate a list of filenames.

Return true upon success, false if the description was too malformed
to generate a sequence. */
unsigned int OpenImageIO_v2_3_6_Filesystem_enumerate_file_sequence(
    _Bool * return_
    , std_string_t const * pattern
    , std_vector_int_t const * numbers
    , std_vector_string_t * filenames);
#define OIIO_Filesystem_enumerate_file_sequence OpenImageIO_v2_3_6_Filesystem_enumerate_file_sequence


/** Given a normalized pattern (such as "foo_%V.%04d.tif") and a list of frame
numbers, generate a list of filenames. "views" is list of per-frame
views, or empty. In each frame filename, "%V" is replaced with the view,
and "%v" is replaced with the first character of the view.

Return true upon success, false if the description was too malformed
to generate a sequence. */
unsigned int OpenImageIO_v2_3_6_Filesystem_enumerate_file_sequence_with_views(
    _Bool * return_
    , std_string_t const * pattern
    , std_vector_int_t const * numbers
    , std_vector_string_view_t const * views
    , std_vector_string_t * filenames);
#define OIIO_Filesystem_enumerate_file_sequence_with_views OpenImageIO_v2_3_6_Filesystem_enumerate_file_sequence_with_views


/** Given a normalized pattern (such as "/path/to/foo.%04d.tif") scan the
containing directory (/path/to) for matching frame numbers, views and files.
"%V" in the pattern matches views, while "%v" matches the first character
of each entry in views.

Return true upon success, false if the directory doesn't exist or the
pattern can't be parsed. */
unsigned int OpenImageIO_v2_3_6_Filesystem_scan_for_matching_filenames_with_views(
    _Bool * return_
    , std_string_t const * pattern
    , std_vector_string_view_t const * views
    , std_vector_int_t * frame_numbers
    , std_vector_string_view_t * frame_views
    , std_vector_string_t * filenames);
#define OIIO_Filesystem_scan_for_matching_filenames_with_views OpenImageIO_v2_3_6_Filesystem_scan_for_matching_filenames_with_views


/** Given a normalized pattern (such as "/path/to/foo.%04d.tif") scan the
containing directory (/path/to) for matching frame numbers and files.

Return true upon success, false if the directory doesn't exist or the
pattern can't be parsed. */
unsigned int OpenImageIO_v2_3_6_Filesystem_scan_for_matching_filenames(
    _Bool * return_
    , std_string_t const * pattern
    , std_vector_int_t * numbers
    , std_vector_string_t * filenames);
#define OIIO_Filesystem_scan_for_matching_filenames OpenImageIO_v2_3_6_Filesystem_scan_for_matching_filenames


#ifdef __cplusplus
}
#endif
