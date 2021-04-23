# oiio-bind
cppmm bindings for OpenImageIO 2.2.x

# Generating bindings
First you must have `astgen` and `asttoc` in your PATH. 

run `bind.sh`, passing the path to your OpenImageIO and OpenEXR installations as environment variables:
```bash
env OIIO_ROOT=/path/to/oiio OPENEXR_ROOT=/path/to/openexr ./bind.sh
```

The resulting bindings will be create in `build/oiio-c` and `build/oiio-sys` for the C and Rust bindings, respectively

# Versions
There is a branch for each supported minor version of the target library. Other versions may or may not bind successfully.
