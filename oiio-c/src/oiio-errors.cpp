#include "oiio-errors.h"
#include "oiio-errors-private.h"

thread_local std::string TLG_EXCEPTION_STRING;

const char* oiio_get_exception_string() {
    return TLG_EXCEPTION_STRING.c_str();
}

