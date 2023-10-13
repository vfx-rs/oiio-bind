# oiio-bind

High-level bindings for
[OpenImageIO](https://github.com/AcademySoftwareFoundation/OpenImageIO)

## Introduction

The `src` directory contains the [oiio](https://crates.io/crates/oiio) crate.
The `oiio` crate provides a high-level safe API over the low-level `oiio-sys` crate.

The `oiio-sys` directory contains the [oiio-sys](https://crates.io/crates/oiio-sys/) crate.
`oiio-sys` uses [cxx](https://cxx.rs) to wrap the C++ OpenImageIO API.

The `oiio-sys` crate should not be used directly.


## Usage

Building the `oiio-sys` crates requires you to install the C++
[OpenImageIO](https://github.com/AcademySoftwareFoundation/OpenImageIO)
library in order to build the `oiio` crate.

Add oiio to your `Cargo.toml`:

    [dependencies]
    oiio = "0.2.0"

The `oiio` crate is built using `cargo build` but you must ensure that
`pkg-config` is able to find your OpenImageIO installation.

If the C++ OpenImageIO library is installed to a non-system directory then
you must configure  the `PKG_CONFIG_PATH` environment variable to point to the
`lib*/pkgconfig` directory inside the OpenImageIO installtion.

`pkg-config` is used by `oiio-sys/build.rs` in order to locate the
`OpenImageIO` libraries and C++ headers. If OpenImageIO is installed to a
global system location such as `/usr/local` then `PKG_CONFIG_PATH` does not
need to be configured. `pkg-config` searches in the system locations by default.


### Development

Build `oiio` and `oiio-sys` using `cargo`.

```bash
cargo build --all
```


### Testing

The test suite in the `tests` directory is used to validate the `oiio` crate.

```bash
cargo test --all
```


## Links

- [source repository](https://github.com/vfx-rs/oiio-bind)
- [oiio on crates.io](https://crates.io/crates/oiio/latest)
- [oiio-sys on crates.io](https://crates.io/crates/oiio-sys/latest)
- [oiio documentation](https://docs.rs/crate/oiio/latest)
- [oiio-sys documentation](https://docs.rs/crate/oiio-sys/latest)
- [OpenImageIO C++ documentation](https://openimageio.readthedocs.io/en/latest/)
