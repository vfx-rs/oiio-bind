#! /usr/bin/env bash

set -e

rm -rf build

astgen bind -v 1 -o build/ast -- -I${OIIO_ROOT}/include -I${OPENEXR_ROOT}/include

asttoc build/ast -o build -p oiio -L $OIIO_ROOT/lib -l OpenImageIO -major 2 -minor 2 -patch 8
