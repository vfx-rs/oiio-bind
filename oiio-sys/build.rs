use anyhow::Result;

const NAMES: &[&str] = &["typedesc", "imageio", "deepdata", "filesystem"];

fn main() -> Result<()> {
    // Skip linking on docs.rs: https://docs.rs/about/builds#detecting-docsrs
    let building_docs = std::env::var("DOCS_RS").is_ok();
    if building_docs {
        println!("cargo:rustc-cfg=docsrs");
        return Ok(());
    }

    cxx_build::bridges(NAMES.iter().map(|s| format!("src/{}.rs", s)))
        .files(NAMES.iter().map(|s| format!("src/ffi_{}.cpp", s)))
        .flag_if_supported("-std=c++17")
        // TODO: This is a hack to get it to compile on my machine. Should
        // probably use CMake or something else.
        .includes(&["/home/scott/Projects/oiio/dist/include", "/usr/include"])
        .compile("oiio-sys");

    println!("cargo:rerun-if-changed=src/lib.rs");

    for name in NAMES {
        println!("cargo:rerun-if-changed=src/{}.rs", name);
        println!("cargo:rerun-if-changed=src/ffi_{}.cpp", name);
        println!("cargo:rerun-if-changed=include/ffi_{}.h", name);
    }

    Ok(())
}
