#pragma once
#include <c-std_string.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct std__string_t_s std__string_t;
typedef std__string_t std_string_t;

/** A `string_view` is a non-owning, non-copying, non-allocating reference
to a sequence of characters.  It encapsulates both a character pointer
and a length.

A function that takes a string input (but does not need to alter the
string in place) may use a string_view parameter and accept input that
is any of char* (C string), string literal (constant char array), a
std::string (C++ string), or OIIO ustring.  For all of these cases, no
extra allocations are performed, and no extra copies of the string
contents are performed (as they would be, for example, if the function
took a const std::string& argument but was passed a char* or string
literal).

Furthermore, a function that returns a copy or a substring of one of its
inputs (for example, a substr()-like function) may return a string_view
rather than a std::string, and thus generate its return value without
any allocation or copying. Upon assignment to a std::string or ustring,
it will properly auto-convert.

There are two important caveats to using this class:
1. The string_view merely refers to characters owned by another string,
   so the string_view may not be used outside the lifetime of the string
   it refers to. Thus, string_view is great for parameter passing, but
   it's not a good idea to use a string_view to store strings in a data
   structure (unless you are really sure you know what you're doing).
2. Because the run of characters that the string_view refers to may not
   be 0-terminated, it is important to distinguish between the data()
   method, which returns the pointer to the characters, and the c_str()
   method, which is guaranteed to return a valid C string that is
   0-terminated. Thus, if you want to pass the contents of a string_view
   to a function that expects a 0-terminated string (say, fopen), you
   must call fopen(my_string_view.c_str()).  Note that the usual case
   is that the string_view does refer to a 0-terminated string, and in
   that case c_str() returns the same thing as data() without any extra
   expense; but in the rare case that it is not 0-terminated, c_str()
   will incur extra expense to internally allocate a valid C string. */
typedef struct OpenImageIO_v2_3_6__string_view_t_s {
    char data[16];
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__string_view_t;
typedef OpenImageIO_v2_3_6__string_view_t OIIO_string_view_t;


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__string_view_sizeof();
#define OIIO_string_view_sizeof OpenImageIO_v2_3_6__string_view_sizeof


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__string_view_alignof();
#define OIIO_string_view_alignof OpenImageIO_v2_3_6__string_view_alignof


/** Default ctr */
unsigned int OpenImageIO_v2_3_6__string_view_ctor(
    OIIO_string_view_t * this_);
#define OIIO_string_view_ctor OpenImageIO_v2_3_6__string_view_ctor


/** Copy ctr */
unsigned int OpenImageIO_v2_3_6__string_view_copy(
    OIIO_string_view_t * this_
    , OIIO_string_view_t const * copy);
#define OIIO_string_view_copy OpenImageIO_v2_3_6__string_view_copy


/** Construct from char* and length. */
unsigned int OpenImageIO_v2_3_6__string_view_from_char_array(
    OIIO_string_view_t * this_
    , char const * chars
    , unsigned long len);
#define OIIO_string_view_from_char_array OpenImageIO_v2_3_6__string_view_from_char_array


/** Construct from char*, use strlen to determine length. */
unsigned int OpenImageIO_v2_3_6__string_view_from_c_str(
    OIIO_string_view_t * this_
    , char const * chars);
#define OIIO_string_view_from_c_str OpenImageIO_v2_3_6__string_view_from_c_str


/** Construct from std::string. Remember that a string_view doesn't have
its own copy of the characters, so don't use the `string_view` after
the original string has been destroyed or altered. */
unsigned int OpenImageIO_v2_3_6__string_view_from_string(
    OIIO_string_view_t * this_
    , std_string_t const * str);
#define OIIO_string_view_from_string OpenImageIO_v2_3_6__string_view_from_string


/** Convert a string_view to a `std::string`. */
unsigned int OpenImageIO_v2_3_6__string_view_str(
    OIIO_string_view_t const * this_
    , std_string_t * * return_);
#define OIIO_string_view_str OpenImageIO_v2_3_6__string_view_str


/** Explicitly request a 0-terminated string. USUALLY, this turns out to
be just data(), with no significant added expense (because most uses
of string_view are simple wrappers of C strings, C++ std::string, or
ustring -- all of which are 0-terminated). But in the more rare case
that the string_view represents a non-0-terminated substring, it
will force an allocation and copy underneath.

Caveats:
1. This is NOT going to be part of the C++17 std::string_view, so
   it's probably best to avoid this method if you want to have 100%
   drop-in compatibility with std::string_view.
2. It is NOT SAFE to use c_str() on a string_view whose last char
   is the end of an allocation -- because that next char may only
   *coincidentally* be a '\0', which will cause c_str() to return
   the string start (thinking it's a valid C string, so why not just
   return its address?), if there's any chance that the subsequent
   char could change from 0 to non-zero during the use of the result
   of c_str(), and thus break the assumption that it's a valid C str. */
unsigned int OpenImageIO_v2_3_6__string_view_c_str(
    OIIO_string_view_t const * this_
    , char const * * return_);
#define OIIO_string_view_c_str OpenImageIO_v2_3_6__string_view_c_str


unsigned int OpenImageIO_v2_3_6__string_view__assign(
    OIIO_string_view_t * this_
    , OIIO_string_view_t * * return_
    , OIIO_string_view_t const * copy);
#define OIIO_string_view__assign OpenImageIO_v2_3_6__string_view__assign


unsigned int OpenImageIO_v2_3_6__string_view_begin(
    OIIO_string_view_t const * this_
    , char const * * return_);
#define OIIO_string_view_begin OpenImageIO_v2_3_6__string_view_begin


unsigned int OpenImageIO_v2_3_6__string_view_end(
    OIIO_string_view_t const * this_
    , char const * * return_);
#define OIIO_string_view_end OpenImageIO_v2_3_6__string_view_end


unsigned int OpenImageIO_v2_3_6__string_view_cbegin(
    OIIO_string_view_t const * this_
    , char const * * return_);
#define OIIO_string_view_cbegin OpenImageIO_v2_3_6__string_view_cbegin


unsigned int OpenImageIO_v2_3_6__string_view_cend(
    OIIO_string_view_t const * this_
    , char const * * return_);
#define OIIO_string_view_cend OpenImageIO_v2_3_6__string_view_cend


unsigned int OpenImageIO_v2_3_6__string_view_size(
    OIIO_string_view_t const * this_
    , unsigned long * return_);
#define OIIO_string_view_size OpenImageIO_v2_3_6__string_view_size


unsigned int OpenImageIO_v2_3_6__string_view_length(
    OIIO_string_view_t const * this_
    , unsigned long * return_);
#define OIIO_string_view_length OpenImageIO_v2_3_6__string_view_length


unsigned int OpenImageIO_v2_3_6__string_view_max_size(
    OIIO_string_view_t const * this_
    , unsigned long * return_);
#define OIIO_string_view_max_size OpenImageIO_v2_3_6__string_view_max_size


/** Is the string_view empty, containing no characters? */
unsigned int OpenImageIO_v2_3_6__string_view_empty(
    OIIO_string_view_t const * this_
    , _Bool * return_);
#define OIIO_string_view_empty OpenImageIO_v2_3_6__string_view_empty


/** Element access of an individual character (beware: no bounds
checking!). */
unsigned int OpenImageIO_v2_3_6__string_view__index(
    OIIO_string_view_t const * this_
    , char const * * return_
    , unsigned long pos);
#define OIIO_string_view__index OpenImageIO_v2_3_6__string_view__index


/** Element access with bounds checking and exception if out of bounds. */
unsigned int OpenImageIO_v2_3_6__string_view_at(
    OIIO_string_view_t const * this_
    , char const * * return_
    , unsigned long pos);
#define OIIO_string_view_at OpenImageIO_v2_3_6__string_view_at


unsigned int OpenImageIO_v2_3_6__string_view_data(
    OIIO_string_view_t const * this_
    , char const * * return_);
#define OIIO_string_view_data OpenImageIO_v2_3_6__string_view_data


unsigned int OpenImageIO_v2_3_6__string_view_clear(
    OIIO_string_view_t * this_);
#define OIIO_string_view_clear OpenImageIO_v2_3_6__string_view_clear


unsigned int OpenImageIO_v2_3_6__string_view_dtor(
    OIIO_string_view_t * this_);
#define OIIO_string_view_dtor OpenImageIO_v2_3_6__string_view_dtor


#ifdef __cplusplus
}
#endif
