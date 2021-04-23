#! /usr/bin/env bash

# exit when any command fails
set -e

# keep track of the last executed command
trap 'last_command=$current_command; current_command=$BASH_COMMAND' DEBUG
# echo an error message before exiting
trap 'echo "\"${last_command}\" exited with code $?."' ERR

astgen bind -u -v 1 -o build/ast -- -I${OIIO_ROOT}/include -I${OPENEXR_ROOT}/include

asttoc build/ast -o build -p oiio -L $OIIO_ROOT/lib -l OpenImageIO -major 2 -minor 2 -patch 8
