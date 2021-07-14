#! /usr/bin/env bash

# exit when any command fails
set -e

# keep track of the last executed command
trap 'last_command=$current_command; current_command=$BASH_COMMAND' DEBUG
# echo an error message before exiting
trap 'echo "\"${last_command}\" exited with code $?."' ERR

rm -rf build

astgen bind -u -v 2 \
    -o build/ast \
    -- \
    -I${OIIO_ROOT}/include \
    -I${OPENEXR_ROOT}/include \
    -I${IMATH_ROOT}/include

asttoc build/ast -v 3 -o build -p oiio \
    -L $OIIO_ROOT/lib \
    -l OpenImageIO \
    -major 2 -minor 3 -patch 6
