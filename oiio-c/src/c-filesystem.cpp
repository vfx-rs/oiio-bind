#include "c-filesystem_private.h"

#include "c-span_private.h"
#include "c-std_string_private.h"
#include "c-std_vector_private.h"
#include "c-string_view_private.h"
#include <new>

#include <stdexcept>

unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_dtor(
    OIIO_Filesystem_IOProxy_t * this_)
{
    try {
        delete to_cpp(this_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_proxytype(
    OIIO_Filesystem_IOProxy_t const * this_
    , char const * * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> proxytype();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_close(
    OIIO_Filesystem_IOProxy_t * this_)
{
    try {
        (to_cpp(this_)) -> close();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_opened(
    OIIO_Filesystem_IOProxy_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> opened();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_tell(
    OIIO_Filesystem_IOProxy_t * this_
    , long * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> tell();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_seek(
    OIIO_Filesystem_IOProxy_t * this_
    , _Bool * return_
    , long offset)
{
    try {
        *(return_) = (to_cpp(this_)) -> seek(offset);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_read(
    OIIO_Filesystem_IOProxy_t * this_
    , unsigned long * return_
    , void * buf
    , unsigned long size)
{
    try {
        *(return_) = (to_cpp(this_)) -> read(buf, size);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_write(
    OIIO_Filesystem_IOProxy_t * this_
    , unsigned long * return_
    , void const * buf
    , unsigned long size)
{
    try {
        *(return_) = (to_cpp(this_)) -> write(buf, size);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_pread(
    OIIO_Filesystem_IOProxy_t * this_
    , unsigned long * return_
    , void * buf
    , unsigned long size
    , long offset)
{
    try {
        *(return_) = (to_cpp(this_)) -> pread(buf, size, offset);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_pwrite(
    OIIO_Filesystem_IOProxy_t * this_
    , unsigned long * return_
    , void const * buf
    , unsigned long size
    , long offset)
{
    try {
        *(return_) = (to_cpp(this_)) -> pwrite(buf, size, offset);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_size(
    OIIO_Filesystem_IOProxy_t const * this_
    , unsigned long * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_flush(
    OIIO_Filesystem_IOProxy_t const * this_)
{
    try {
        (to_cpp(this_)) -> flush();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_mode(
    OIIO_Filesystem_IOProxy_t const * this_
    , OIIO_Filesystem_IOProxy_Mode * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> mode());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_filename(
    OIIO_Filesystem_IOProxy_t const * this_
    , std_string_t const * * return_)
{
    try {
        to_c(return_, (to_cpp(this_)) -> filename());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy_error(
    OIIO_Filesystem_IOProxy_t const * this_
    , std_string_t * * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> error());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOProxy__assign(
    OIIO_Filesystem_IOProxy_t * this_
    , OIIO_Filesystem_IOProxy_t * * return_
    , OIIO_Filesystem_IOProxy_t const * rhs)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_proxytype(
    OIIO_Filesystem_IOFile_t const * this_
    , char const * * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> proxytype();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_close(
    OIIO_Filesystem_IOFile_t * this_)
{
    try {
        (to_cpp(this_)) -> close();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_opened(
    OIIO_Filesystem_IOFile_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> opened();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_tell(
    OIIO_Filesystem_IOFile_t * this_
    , long * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> tell();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_seek(
    OIIO_Filesystem_IOFile_t * this_
    , _Bool * return_
    , long offset)
{
    try {
        *(return_) = (to_cpp(this_)) -> seek(offset);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_read(
    OIIO_Filesystem_IOFile_t * this_
    , unsigned long * return_
    , void * buf
    , unsigned long size)
{
    try {
        *(return_) = (to_cpp(this_)) -> read(buf, size);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_write(
    OIIO_Filesystem_IOFile_t * this_
    , unsigned long * return_
    , void const * buf
    , unsigned long size)
{
    try {
        *(return_) = (to_cpp(this_)) -> write(buf, size);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_pread(
    OIIO_Filesystem_IOFile_t * this_
    , unsigned long * return_
    , void * buf
    , unsigned long size
    , long offset)
{
    try {
        *(return_) = (to_cpp(this_)) -> pread(buf, size, offset);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_pwrite(
    OIIO_Filesystem_IOFile_t * this_
    , unsigned long * return_
    , void const * buf
    , unsigned long size
    , long offset)
{
    try {
        *(return_) = (to_cpp(this_)) -> pwrite(buf, size, offset);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_size(
    OIIO_Filesystem_IOFile_t const * this_
    , unsigned long * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_flush(
    OIIO_Filesystem_IOFile_t const * this_)
{
    try {
        (to_cpp(this_)) -> flush();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_mode(
    OIIO_Filesystem_IOFile_t const * this_
    , OIIO_Filesystem_IOProxy_Mode * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> mode());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_filename(
    OIIO_Filesystem_IOFile_t const * this_
    , std_string_t const * * return_)
{
    try {
        to_c(return_, (to_cpp(this_)) -> filename());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_error(
    OIIO_Filesystem_IOFile_t const * this_
    , std_string_t * * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> error());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_new(
    OIIO_Filesystem_IOFile_t * * this_
    , OIIO_string_view_t filename
    , OIIO_Filesystem_IOProxy_Mode mode)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::Filesystem::IOFile(to_cpp_ref(&(filename)), OIIO_Filesystem_IOProxy_Mode_to_cpp_ref(&(mode))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOFile_dtor(
    OIIO_Filesystem_IOFile_t * this_)
{
    try {
        delete to_cpp(this_);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_proxytype(
    OIIO_Filesystem_IOVecOutput_t const * this_
    , char const * * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> proxytype();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_close(
    OIIO_Filesystem_IOVecOutput_t * this_)
{
    try {
        (to_cpp(this_)) -> close();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_opened(
    OIIO_Filesystem_IOVecOutput_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> opened();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_tell(
    OIIO_Filesystem_IOVecOutput_t * this_
    , long * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> tell();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_seek(
    OIIO_Filesystem_IOVecOutput_t * this_
    , _Bool * return_
    , long offset)
{
    try {
        *(return_) = (to_cpp(this_)) -> seek(offset);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_read(
    OIIO_Filesystem_IOVecOutput_t * this_
    , unsigned long * return_
    , void * buf
    , unsigned long size)
{
    try {
        *(return_) = (to_cpp(this_)) -> read(buf, size);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_write(
    OIIO_Filesystem_IOVecOutput_t * this_
    , unsigned long * return_
    , void const * buf
    , unsigned long size)
{
    try {
        *(return_) = (to_cpp(this_)) -> write(buf, size);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_pread(
    OIIO_Filesystem_IOVecOutput_t * this_
    , unsigned long * return_
    , void * buf
    , unsigned long size
    , long offset)
{
    try {
        *(return_) = (to_cpp(this_)) -> pread(buf, size, offset);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_pwrite(
    OIIO_Filesystem_IOVecOutput_t * this_
    , unsigned long * return_
    , void const * buf
    , unsigned long size
    , long offset)
{
    try {
        *(return_) = (to_cpp(this_)) -> pwrite(buf, size, offset);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_size(
    OIIO_Filesystem_IOVecOutput_t const * this_
    , unsigned long * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_flush(
    OIIO_Filesystem_IOVecOutput_t const * this_)
{
    try {
        (to_cpp(this_)) -> flush();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_mode(
    OIIO_Filesystem_IOVecOutput_t const * this_
    , OIIO_Filesystem_IOProxy_Mode * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> mode());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_filename(
    OIIO_Filesystem_IOVecOutput_t const * this_
    , std_string_t const * * return_)
{
    try {
        to_c(return_, (to_cpp(this_)) -> filename());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_error_const(
    OIIO_Filesystem_IOVecOutput_t const * this_
    , std_string_t * * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> error());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_error(
    OIIO_Filesystem_IOVecOutput_t * this_
    , OIIO_string_view_t e)
{
    try {
        (to_cpp(this_)) -> error(to_cpp_ref(&(e)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_ctor(
    OIIO_Filesystem_IOVecOutput_t * * this_)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::Filesystem::IOVecOutput());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_from_buf(
    OIIO_Filesystem_IOVecOutput_t * * this_
    , std_vector_uchar_t * buf)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::Filesystem::IOVecOutput(to_cpp_ref(buf)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_buffer(
    OIIO_Filesystem_IOVecOutput_t const * this_
    , std_vector_uchar_t * * return_)
{
    try {
        to_c(return_, (to_cpp(this_)) -> buffer());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOVecOutput_dtor(
    OIIO_Filesystem_IOVecOutput_t * this_)
{
        delete to_cpp(this_);
        return 0;
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_proxytype(
    OIIO_Filesystem_IOMemReader_t const * this_
    , char const * * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> proxytype();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_close(
    OIIO_Filesystem_IOMemReader_t * this_)
{
    try {
        (to_cpp(this_)) -> close();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_opened(
    OIIO_Filesystem_IOMemReader_t const * this_
    , _Bool * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> opened();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_tell(
    OIIO_Filesystem_IOMemReader_t * this_
    , long * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> tell();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_seek(
    OIIO_Filesystem_IOMemReader_t * this_
    , _Bool * return_
    , long offset)
{
    try {
        *(return_) = (to_cpp(this_)) -> seek(offset);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_read(
    OIIO_Filesystem_IOMemReader_t * this_
    , unsigned long * return_
    , void * buf
    , unsigned long size)
{
    try {
        *(return_) = (to_cpp(this_)) -> read(buf, size);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_write(
    OIIO_Filesystem_IOMemReader_t * this_
    , unsigned long * return_
    , void const * buf
    , unsigned long size)
{
    try {
        *(return_) = (to_cpp(this_)) -> write(buf, size);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_pread(
    OIIO_Filesystem_IOMemReader_t * this_
    , unsigned long * return_
    , void * buf
    , unsigned long size
    , long offset)
{
    try {
        *(return_) = (to_cpp(this_)) -> pread(buf, size, offset);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_pwrite(
    OIIO_Filesystem_IOMemReader_t * this_
    , unsigned long * return_
    , void const * buf
    , unsigned long size
    , long offset)
{
    try {
        *(return_) = (to_cpp(this_)) -> pwrite(buf, size, offset);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_size(
    OIIO_Filesystem_IOMemReader_t const * this_
    , unsigned long * return_)
{
    try {
        *(return_) = (to_cpp(this_)) -> size();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_flush(
    OIIO_Filesystem_IOMemReader_t const * this_)
{
    try {
        (to_cpp(this_)) -> flush();
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_mode(
    OIIO_Filesystem_IOMemReader_t const * this_
    , OIIO_Filesystem_IOProxy_Mode * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> mode());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_filename(
    OIIO_Filesystem_IOMemReader_t const * this_
    , std_string_t const * * return_)
{
    try {
        to_c(return_, (to_cpp(this_)) -> filename());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_error(
    OIIO_Filesystem_IOMemReader_t const * this_
    , std_string_t * * return_)
{
    try {
        to_c_copy(return_, (to_cpp(this_)) -> error());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_from_buf(
    OIIO_Filesystem_IOMemReader_t * * this_
    , void * buf
    , unsigned long size)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::Filesystem::IOMemReader(buf, size));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_buffer(
    OIIO_Filesystem_IOMemReader_t const * this_
    , OIIO_cspan_uchar_t * return_)
{
        to_c_copy(return_, (to_cpp(this_)) -> buffer());
        return 0;
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_copy(
    OIIO_Filesystem_IOMemReader_t * * this_
    , OIIO_Filesystem_IOMemReader_t const * rhs)
{
    try {
        to_c(this_, new OpenImageIO_v2_3_6::Filesystem::IOMemReader(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader__assign(
    OIIO_Filesystem_IOMemReader_t * this_
    , OIIO_Filesystem_IOMemReader_t * * return_
    , OIIO_Filesystem_IOMemReader_t const * rhs)
{
    try {
        to_c(return_, (to_cpp(this_)) -> operator=(to_cpp_ref(rhs)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6__Filesystem__IOMemReader_dtor(
    OIIO_Filesystem_IOMemReader_t * this_)
{
        delete to_cpp(this_);
        return 0;
}

unsigned int OpenImageIO_v2_3_6_Filesystem_filename(
    std_string_t * * return_
    , std_string_t const * filepath)
{
        to_c_copy(return_, OpenImageIO_v2_3_6::Filesystem::filename(to_cpp_ref(filepath)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6_Filesystem_extension(
    std_string_t * * return_
    , std_string_t const * filepath
    , _Bool include_dot)
{
        to_c_copy(return_, OpenImageIO_v2_3_6::Filesystem::extension(to_cpp_ref(filepath), include_dot));
        return 0;
}

unsigned int OpenImageIO_v2_3_6_Filesystem_parent_path(
    std_string_t * * return_
    , std_string_t const * filepath)
{
        to_c_copy(return_, OpenImageIO_v2_3_6::Filesystem::parent_path(to_cpp_ref(filepath)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6_Filesystem_replace_extension(
    std_string_t * * return_
    , std_string_t const * filepath
    , std_string_t const * new_extension)
{
        to_c_copy(return_, OpenImageIO_v2_3_6::Filesystem::replace_extension(to_cpp_ref(filepath), to_cpp_ref(new_extension)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6_Filesystem_searchpath_split(
    std_string_t const * searchpath
    , std_vector_string_t * dirs
    , _Bool validonly)
{
    try {
        OpenImageIO_v2_3_6::Filesystem::searchpath_split(to_cpp_ref(searchpath), to_cpp_ref(dirs), validonly);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_searchpath_find(
    std_string_t * * return_
    , std_string_t const * filename
    , std_vector_string_t const * dirs
    , _Bool testcwd
    , _Bool recursive)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::Filesystem::searchpath_find(to_cpp_ref(filename), to_cpp_ref(dirs), testcwd, recursive));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_get_directory_entries(
    _Bool * return_
    , std_string_t const * dirname
    , std_vector_string_t * filenames
    , _Bool recursive
    , std_string_t const * filter_regex)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filesystem::get_directory_entries(to_cpp_ref(dirname), to_cpp_ref(filenames), recursive, to_cpp_ref(filter_regex));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_path_is_absolute(
    _Bool * return_
    , OIIO_string_view_t path
    , _Bool dot_is_absolute)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filesystem::path_is_absolute(to_cpp_ref(&(path)), dot_is_absolute);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_exists(
    _Bool * return_
    , OIIO_string_view_t path)
{
        *(return_) = OpenImageIO_v2_3_6::Filesystem::exists(to_cpp_ref(&(path)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6_Filesystem_is_directory(
    _Bool * return_
    , OIIO_string_view_t path)
{
        *(return_) = OpenImageIO_v2_3_6::Filesystem::is_directory(to_cpp_ref(&(path)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6_Filesystem_is_regular(
    _Bool * return_
    , OIIO_string_view_t path)
{
        *(return_) = OpenImageIO_v2_3_6::Filesystem::is_regular(to_cpp_ref(&(path)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6_Filesystem_create_directory(
    _Bool * return_
    , OIIO_string_view_t path
    , std_string_t * err)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filesystem::create_directory(to_cpp_ref(&(path)), to_cpp_ref(err));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_copy(
    _Bool * return_
    , OIIO_string_view_t from
    , OIIO_string_view_t to
    , std_string_t * err)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filesystem::copy(to_cpp_ref(&(from)), to_cpp_ref(&(to)), to_cpp_ref(err));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_rename(
    _Bool * return_
    , OIIO_string_view_t from
    , OIIO_string_view_t to
    , std_string_t * err)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filesystem::rename(to_cpp_ref(&(from)), to_cpp_ref(&(to)), to_cpp_ref(err));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_remove(
    _Bool * return_
    , OIIO_string_view_t path
    , std_string_t * err)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filesystem::remove(to_cpp_ref(&(path)), to_cpp_ref(err));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_remove_all(
    unsigned long long * return_
    , OIIO_string_view_t path
    , std_string_t * err)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filesystem::remove_all(to_cpp_ref(&(path)), to_cpp_ref(err));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_temp_directory_path(
    std_string_t * * return_)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::Filesystem::temp_directory_path());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_unique_path(
    std_string_t * * return_
    , OIIO_string_view_t model)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::Filesystem::unique_path(to_cpp_ref(&(model))));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_current_path(
    std_string_t * * return_)
{
    try {
        to_c_copy(return_, OpenImageIO_v2_3_6::Filesystem::current_path());
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_read_text_file(
    _Bool * return_
    , OIIO_string_view_t filename
    , std_string_t * str)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filesystem::read_text_file(to_cpp_ref(&(filename)), to_cpp_ref(str));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_write_text_file(
    _Bool * return_
    , OIIO_string_view_t filename
    , OIIO_string_view_t str)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filesystem::write_text_file(to_cpp_ref(&(filename)), to_cpp_ref(&(str)));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_read_bytes(
    unsigned long * return_
    , OIIO_string_view_t path
    , void * buffer
    , unsigned long n
    , unsigned long pos)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filesystem::read_bytes(to_cpp_ref(&(path)), buffer, n, pos);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_last_write_time(
    long * return_
    , OIIO_string_view_t path)
{
        *(return_) = OpenImageIO_v2_3_6::Filesystem::last_write_time(to_cpp_ref(&(path)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6_Filesystem_file_size(
    unsigned long * return_
    , OIIO_string_view_t path)
{
        *(return_) = OpenImageIO_v2_3_6::Filesystem::file_size(to_cpp_ref(&(path)));
        return 0;
}

unsigned int OpenImageIO_v2_3_6_Filesystem_convert_native_arguments(
    int argc
    , char const * * argv)
{
    try {
        OpenImageIO_v2_3_6::Filesystem::convert_native_arguments(argc, argv);
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_enumerate_sequence(
    _Bool * return_
    , OIIO_string_view_t desc
    , std_vector_int_t * numbers)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filesystem::enumerate_sequence(to_cpp_ref(&(desc)), to_cpp_ref(numbers));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_parse_pattern(
    _Bool * return_
    , char const * pattern
    , int framepadding_override
    , std_string_t * normalized_pattern
    , std_string_t * framespec)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filesystem::parse_pattern(pattern, framepadding_override, to_cpp_ref(normalized_pattern), to_cpp_ref(framespec));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_enumerate_file_sequence(
    _Bool * return_
    , std_string_t const * pattern
    , std_vector_int_t const * numbers
    , std_vector_string_t * filenames)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filesystem::enumerate_file_sequence(to_cpp_ref(pattern), to_cpp_ref(numbers), to_cpp_ref(filenames));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_enumerate_file_sequence_with_views(
    _Bool * return_
    , std_string_t const * pattern
    , std_vector_int_t const * numbers
    , std_vector_string_view_t const * views
    , std_vector_string_t * filenames)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filesystem::enumerate_file_sequence(to_cpp_ref(pattern), to_cpp_ref(numbers), to_cpp_ref(views), to_cpp_ref(filenames));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_scan_for_matching_filenames_with_views(
    _Bool * return_
    , std_string_t const * pattern
    , std_vector_string_view_t const * views
    , std_vector_int_t * frame_numbers
    , std_vector_string_view_t * frame_views
    , std_vector_string_t * filenames)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filesystem::scan_for_matching_filenames(to_cpp_ref(pattern), to_cpp_ref(views), to_cpp_ref(frame_numbers), to_cpp_ref(frame_views), to_cpp_ref(filenames));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

unsigned int OpenImageIO_v2_3_6_Filesystem_scan_for_matching_filenames(
    _Bool * return_
    , std_string_t const * pattern
    , std_vector_int_t * numbers
    , std_vector_string_t * filenames)
{
    try {
        *(return_) = OpenImageIO_v2_3_6::Filesystem::scan_for_matching_filenames(to_cpp_ref(pattern), to_cpp_ref(numbers), to_cpp_ref(filenames));
        return 0;
    } catch (std::exception& e) {
        TLG_EXCEPTION_STRING = e.what();
        return -1;
    }
}

