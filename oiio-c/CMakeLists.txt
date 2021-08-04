cmake_minimum_required(VERSION 3.5)
project(oiio-c VERSION 2.3.6)
set(CMAKE_CXX_STANDARD 14 CACHE STRING "")
set(SOURCES
    src/c-std_map.cpp
    src/c-std_vector.cpp
    src/imath_matrix.cpp
    src/c-std_string.cpp
    src/c-deepdata.cpp
    src/c-ustring.cpp
    src/c-strided_ptr.cpp
    src/c-color.cpp
    src/c-std_unique_ptr.cpp
    src/c-filesystem.cpp
    src/c-span.cpp
    src/c-imagebufalgo.cpp
    src/c-std_set.cpp
    src/c-filter.cpp
    src/imath_vec.cpp
    src/c-imagebufalgo_util.cpp
    src/c-texture.cpp
    src/c-typedesc.cpp
    src/c-string_view.cpp
    src/c-std_pair.cpp
    src/c-imageio.cpp
    src/c-imagecache.cpp
    src/imath_box.cpp
    src/c-imagebuf.cpp
    src/c-std_shared_ptr.cpp
    src/c-paramlist.cpp
    src/oiio-errors.cpp
)
set(LIBNAME oiio-c-2_3)
add_library(${LIBNAME} STATIC ${SOURCES})
add_library(${LIBNAME}-shared SHARED ${SOURCES})
target_include_directories(${LIBNAME} PRIVATE /home/anders/packages/oiio/2.3.6/include)
target_include_directories(${LIBNAME}-shared PRIVATE /home/anders/packages/oiio/2.3.6/include)
target_include_directories(${LIBNAME} PRIVATE /home/anders/packages/openexr/3.1.0-kdt3rd/include)
target_include_directories(${LIBNAME}-shared PRIVATE /home/anders/packages/openexr/3.1.0-kdt3rd/include)
target_include_directories(${LIBNAME} PRIVATE /include)
target_include_directories(${LIBNAME}-shared PRIVATE /include)
target_include_directories(${LIBNAME} PRIVATE include)
target_include_directories(${LIBNAME}-shared PRIVATE include)
target_include_directories(${LIBNAME} PRIVATE src)
target_include_directories(${LIBNAME}-shared PRIVATE src)
find_library ( LIB_OPENIMAGEIO NAMES OpenImageIO PATHS /home/anders/packages/oiio/2.3.6/lib)
target_link_libraries (${LIBNAME} ${LIB_OPENIMAGEIO})
target_link_libraries (${LIBNAME}-shared ${LIB_OPENIMAGEIO})
find_library ( LIB_OPENIMAGEIO_UTIL NAMES OpenImageIO_Util PATHS /home/anders/packages/oiio/2.3.6/lib)
target_link_libraries (${LIBNAME} ${LIB_OPENIMAGEIO_UTIL})
target_link_libraries (${LIBNAME}-shared ${LIB_OPENIMAGEIO_UTIL})
install(TARGETS ${LIBNAME} DESTINATION ${CMAKE_INSTALL_PREFIX})