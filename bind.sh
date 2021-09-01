#! /usr/bin/env bash

# exit when any command fails
set -e

# keep track of the last executed command
trap 'last_command=$current_command; current_command=$BASH_COMMAND' DEBUG
# echo an error message before exiting
trap 'echo "\"${last_command}\" exited with code $?."' ERR

project_name="oiio"
major_version=0
minor_version=10
patch_version=0

rm -rf build

astgen bind -u -v 2 \
    -o build/ast \
    -- \
    -I${OIIO_ROOT}/include \
    -I${OPENEXR_ROOT}/include \
    -I${IMATH_ROOT}/include

asttoc build/ast -v 2 -o build -p oiio \
    -fp OpenImageIO \
    -tll OpenImageIO::OpenImageIO \
    -tll OpenImageIO::OpenImageIO_Util \
    -major ${major_version} -minor ${minor_version} -patch ${patch_version}


# # Move the actual oiio c++ library source into
# # oiio-sys so that it comes bundled with openexr-sys.
 mkdir -p build/${project_name}-sys/thirdparty
cp -r thirdparty/oiio build/${project_name}-sys/thirdparty/
# cp -r $HOME/code/oiio build/${project_name}-sys/thirdparty/

pushd build/${project_name}-sys/thirdparty/oiio
# we need to pull down the dependencies now so we can build offline
export DEP_DOWNLOAD_ONLY=1

src/build-scripts/build_gif.bash
src/build-scripts/build_libjpeg-turbo.bash
src/build-scripts/build_libpng.bash
src/build-scripts/build_libraw.bash
src/build-scripts/build_libtiff.bash
src/build-scripts/build_OpenJPEG.bash
src/build-scripts/build_pugixml.bash
src/build-scripts/build_pybind11.bash
src/build-scripts/build_webp.bash
src/build-scripts/build_zlib.bash

unset DEP_DOWNLOAD_ONLY

# Do a cmake configure to get cmake to pull down robinmap etc. Additional
# libraries will be built by the build scripts from build.rs
# The configure step will fail but we don't care about that
mkdir -p build && cd build && cmake .. || true
popd

sed \
    -e "s/PROJECT_NAME/${project_name}/g" \
    -e "s/MAJOR_VERSION/${major_version}/g" \
    -e "s/MINOR_VERSION/${minor_version}/g" \
    -e "s/PATCH_VERSION/${patch_version}/g" \
    scripts/build.rs > build/${project_name}-sys/build.rs

sed \
    -e "s/PROJECT_NAME/${project_name}/g" \
    -e "s/MAJOR_VERSION/${major_version}/g" \
    -e "s/MINOR_VERSION/${minor_version}/g" \
    -e "s/PATCH_VERSION/${patch_version}/g" \
    scripts/Cargo.toml > build/${project_name}-sys/Cargo.toml


