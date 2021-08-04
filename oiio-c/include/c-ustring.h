#pragma once
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct std__vector_OIIO__ustring__t_s std__vector_OIIO__ustring__t;
typedef std__vector_OIIO__ustring__t std_vector_ustring_t;

/** A ustring is an alternative to char* or std::string for storing
strings, in which the character sequence is unique (allowing many
speed advantages for assignment, equality testing, and inequality
testing).

The implementation is that behind the scenes there is a hash set of
allocated strings, so the characters of each string are unique.  A
ustring itself is a pointer to the characters of one of these canonical
strings.  Therefore, assignment and equality testing is just a single
32- or 64-bit int operation, the only mutex is when a ustring is
created from raw characters, and the only malloc is the first time
each canonical ustring is created.

The internal table also contains a std::string version and the length
of the string, so converting a ustring to a std::string (via
ustring::string()) or querying the number of characters (via
ustring::size() or ustring::length()) is extremely inexpensive, and does
not involve creation/allocation of a new std::string or a call to
strlen.

We try very hard to completely mimic the API of std::string,
including all the constructors, comparisons, iterations, etc.  Of
course, the charaters of a ustring are non-modifiable, so we do not
replicate any of the non-const methods of std::string.  But in most
other ways it looks and acts like a std::string and so most templated
algorthms that would work on a "const std::string &" will also work
on a ustring.

Usage guidelines:

Compared to standard strings, ustrings have several advantages:

  - Each individual ustring is very small -- in fact, we guarantee that
    a ustring is the same size and memory layout as an ordinary char*.
  - Storage is frugal, since there is only one allocated copy of each
    unique character sequence, throughout the lifetime of the program.
  - Assignment from one ustring to another is just copy of the pointer;
    no allocation, no character copying, no reference counting.
  - Equality testing (do the strings contain the same characters) is
    a single operation, the comparison of the pointer.
  - Memory allocation only occurs when a new ustring is constructed from
    raw characters the FIRST time -- subsequent constructions of the
    same string just finds it in the canonical string set, but doesn't
    need to allocate new storage.  Destruction of a ustring is trivial,
    there is no de-allocation because the canonical version stays in
    the set.  Also, therefore, no user code mistake can lead to
    memory leaks.

But there are some problems, too.  Canonical strings are never freed
from the table.  So in some sense all the strings "leak", but they
only leak one copy for each unique string that the program ever comes
across.  Also, creation of unique strings from raw characters is more
expensive than for standard strings, due to hashing, table queries,
and other overhead.

On the whole, ustrings are a really great string representation
  - if you tend to have (relatively) few unique strings, but many
    copies of those strings;
  - if the creation of strings from raw characters is relatively
    rare compared to copying or comparing to existing strings;
  - if you tend to make the same strings over and over again, and
    if it's relatively rare that a single unique character sequence
    is used only once in the entire lifetime of the program;
  - if your most common string operations are assignment and equality
    testing and you want them to be as fast as possible;
  - if you are doing relatively little character-by-character assembly
    of strings, string concatenation, or other "string manipulation"
    (other than equality testing).

ustrings are not so hot
  - if your program tends to have very few copies of each character
    sequence over the entire lifetime of the program;
  - if your program tends to generate a huge variety of unique
    strings over its lifetime, each of which is used only a short
    time and then discarded, never to be needed again;
  - if you don't need to do a lot of string assignment or equality
    testing, but lots of more complex string manipulation. */
typedef struct OpenImageIO_v2_3_6__ustring_t_s {
    char data[8];
} __attribute__((aligned(8))) OpenImageIO_v2_3_6__ustring_t;
typedef OpenImageIO_v2_3_6__ustring_t OIIO_ustring_t;


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__ustring_sizeof();
#define OIIO_ustring_sizeof OpenImageIO_v2_3_6__ustring_sizeof


/** returns the size of this type in bytes */
unsigned int OpenImageIO_v2_3_6__ustring_alignof();
#define OIIO_ustring_alignof OpenImageIO_v2_3_6__ustring_alignof


/** Construct a ustring from a null-terminated C string (char *). */
unsigned int OpenImageIO_v2_3_6__ustring_ctor(
    OIIO_ustring_t * this_
    , char const * str);
#define OIIO_ustring_ctor OpenImageIO_v2_3_6__ustring_ctor


/** Copy construct a ustring from another ustring. */
unsigned int OpenImageIO_v2_3_6__ustring_copy(
    OIIO_ustring_t * this_
    , OIIO_ustring_t const * str);
#define OIIO_ustring_copy OpenImageIO_v2_3_6__ustring_copy


/** ustring destructor. */
unsigned int OpenImageIO_v2_3_6__ustring_dtor(
    OIIO_ustring_t * this_);
#define OIIO_ustring_dtor OpenImageIO_v2_3_6__ustring_dtor


/** Assign a ustring to another ustring. */
unsigned int OpenImageIO_v2_3_6__ustring__assign(
    OIIO_ustring_t * this_
    , OIIO_ustring_t const * * return_
    , OIIO_ustring_t const * str);
#define OIIO_ustring__assign OpenImageIO_v2_3_6__ustring__assign


/** Return a C string representation of a ustring. */
unsigned int OpenImageIO_v2_3_6__ustring_c_str(
    OIIO_ustring_t const * this_
    , char const * * return_);
#define OIIO_ustring_c_str OpenImageIO_v2_3_6__ustring_c_str


/** Return a C string representation of a ustring. */
unsigned int OpenImageIO_v2_3_6__ustring_data(
    OIIO_ustring_t const * this_
    , char const * * return_);
#define OIIO_ustring_data OpenImageIO_v2_3_6__ustring_data


/** Reset to an empty string. */
unsigned int OpenImageIO_v2_3_6__ustring_clear(
    OIIO_ustring_t * this_);
#define OIIO_ustring_clear OpenImageIO_v2_3_6__ustring_clear


/** Return the number of characters in the string. */
unsigned int OpenImageIO_v2_3_6__ustring_length(
    OIIO_ustring_t const * this_
    , unsigned long * return_);
#define OIIO_ustring_length OpenImageIO_v2_3_6__ustring_length


/** Return a hashed version of the string */
unsigned int OpenImageIO_v2_3_6__ustring_hash(
    OIIO_ustring_t const * this_
    , unsigned long * return_);
#define OIIO_ustring_hash OpenImageIO_v2_3_6__ustring_hash


/** Return the number of characters in the string. */
unsigned int OpenImageIO_v2_3_6__ustring_size(
    OIIO_ustring_t const * this_
    , unsigned long * return_);
#define OIIO_ustring_size OpenImageIO_v2_3_6__ustring_size


/** Is the string empty -- i.e., is it nullptr or does it point to an
empty string? */
unsigned int OpenImageIO_v2_3_6__ustring_empty(
    OIIO_ustring_t const * this_
    , _Bool * return_);
#define OIIO_ustring_empty OpenImageIO_v2_3_6__ustring_empty


/** Test two ustrings for equality -- are they comprised of the same
sequence of characters.  Note that because ustrings are unique,
this is a trivial pointer comparison, not a char-by-char loop as
would be the case with a char* or a std::string. */
unsigned int OpenImageIO_v2_3_6__ustring__eq(
    OIIO_ustring_t const * this_
    , _Bool * return_
    , OIIO_ustring_t const * str);
#define OIIO_ustring__eq OpenImageIO_v2_3_6__ustring__eq


/** Test two ustrings for inequality -- are they comprised of different
sequences of characters.  Note that because ustrings are unique,
this is a trivial pointer comparison, not a char-by-char loop as
would be the case with a char* or a std::string. */
unsigned int OpenImageIO_v2_3_6__ustring__ne(
    OIIO_ustring_t const * this_
    , _Bool * return_
    , OIIO_ustring_t const * str);
#define OIIO_ustring__ne OpenImageIO_v2_3_6__ustring__ne


/** Return the total number of ustrings in the internal table. */
unsigned int OpenImageIO_v2_3_6__ustring_total_ustrings(
    unsigned long * return_);
#define OIIO_ustring_total_ustrings OpenImageIO_v2_3_6__ustring_total_ustrings


/** Return the total number ustrings that have the exact hash as another
ustring. If `collisions` is passed, store all the colliding ustrings
in the vector. */
unsigned int OpenImageIO_v2_3_6__ustring_hash_collisions(
    unsigned long * return_
    , std_vector_ustring_t * collisions);
#define OIIO_ustring_hash_collisions OpenImageIO_v2_3_6__ustring_hash_collisions


#ifdef __cplusplus
}
#endif
