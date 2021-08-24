use regex::Regex;
use std::path::Path;

const PRJ_NAME: &str = "PROJECT_NAME";
const MJR_VERSION: u32 = MAJOR_VERSION;
const MNR_VERSION: u32 = MINOR_VERSION;

fn build_oiio(target_dir: &Path) -> std::string::String {
    // We need to set this to Release or else the openexr symlinks will be incorrect.
    // Fixed by
    let cmake_prefix_path = target_dir.join("lib").join("cmake");
    cmake::Config::new("thirdparty/oiio")
        .profile("Release")
        .define("CMAKE_INSTALL_PREFIX", target_dir.to_str().unwrap())
        .define("CMAKE_PREFIX_PATH", cmake_prefix_path.to_str().unwrap())
        .define("BUILD_TOOLS", "OFF")
        .define("BUILD_TESTS", "OFF")
        .define("BUILD_DOCS", "OFF")
        .define("USE_PYTHON", "OFF")
        .build()
        .to_str()
        .expect("Unable to convert oiio_root to str")
        .to_string()
}

use std::process::Command;

fn build_deps(manifest_dir: &str, target_dir: &Path) {
    let oiio_root = Path::new(manifest_dir).join("thirdparty").join("oiio");
    let dep_install_dir = oiio_root.join("ext").join("dist");

    // we need to build each of the oiio deps using the provided build scripts
    // and we want them to all install into our shared build directory
    // std::env::set_var("GIFLIB_INSTALL_DIR", &target_dir);
    // std::env::set_var("LIBJPEGTURBO_INSTALL_DIR", &target_dir);
    // std::env::set_var("LIBPNG_INSTALL_DIR", &target_dir);
    // std::env::set_var("LIBRAW_INSTALL_DIR", &target_dir);
    // std::env::set_var("LIBTIFF_INSTALL_DIR", &target_dir);
    // std::env::set_var("OPENJPEG_INSTALL_DIR", &target_dir);
    std::env::set_var("PUGIXML_INSTALL_DIR", &target_dir);
    std::env::set_var("PYBIND11_INSTALL_DIR", &target_dir);
    // std::env::set_var("WEBP_INSTALL_DIR", &target_dir);
    // std::env::set_var("ZLIB_INSTALL_DIR", &target_dir);

    let build_scripts_rel = Path::new("src").join("build-scripts");

    for script in [
        // "build_gif.bash",
        // "build_libjpeg-turbo.bash",
        // "build_libpng.bash",
        // "build_libraw.bash",
        // "build_libtiff.bash",
        // "build_OpenJPEG.bash",
        "build_pugixml.bash",
        "build_pybind11.bash",
        // "build_webp.bash",
        // "build_zlib.bash",
    ] {
        let script_path = build_scripts_rel.join(script);
        Command::new(&script_path)
            .current_dir(&oiio_root)
            .output()
            .expect(&format!("Failed to run '{}' script", script));
    }

    // set the environment variables the main build will use to find the deps
    // std::env::set_var("GIF_ROOT", &dep_install_dir);
    // std::env::set_var("JPEGTurbo_ROOT", &dep_install_dir);
    // std::env::set_var("PNG_ROOT", &dep_install_dir);
    // std::env::set_var("LibRaw_ROOT", &dep_install_dir);
    // std::env::set_var("LibRaw_LIBRARY_DIR", &dep_install_dir.join("lib"));
    // std::env::set_var("LIBTIFF_ROOT", &dep_install_dir);
    // std::env::set_var("OpenJPEG_ROOT", &dep_install_dir);
    std::env::set_var("pugixml_ROOT", &dep_install_dir);
    std::env::set_var("pybind11_ROOT", &dep_install_dir);
    // std::env::set_var("WebP_ROOT", &dep_install_dir);
    // std::env::set_var("ZLIB_ROOT", &dep_install_dir);
}

#[derive(Debug)]
struct DylibPathInfo {
    path: String,
    basename: String,
    libname: String,
}

fn is_dylib_path(s: &str, re: &Regex) -> Option<DylibPathInfo> {
    if let Some(m) = re.captures_iter(s).next() {
        if let Some(c0) = m.get(0) {
            if let Some(c1) = m.get(1) {
                return Some(DylibPathInfo {
                    path: s.to_string(),
                    basename: c0.as_str().to_string(),
                    libname: c1.as_str().to_string(),
                });
            }
        }
    }

    None
}

fn get_linking_from_cmake(link_txt_path: &Path) -> Vec<DylibPathInfo> {
    let link_txt = std::fs::read_to_string(link_txt_path).expect(&format!(
        "Could not read link_txt_path: {}",
        link_txt_path.display()
    ));

    let re = Regex::new(
        r"lib([^/]+?)(?:\.dylib|\.so|\.so.\d+|\.so.\d+.\d+|\.so.\d+.\d+.\d+)$",
    )
    .unwrap();

    // Try and figure out what are libraries we want to copy to target.
    // Libraries will end with `.so` or `.so.28.1.0` or `.dylib`
    // God knows for Windows...

    // First, strip off everything up to and including the initial "-o whatever.so"
    let mut link_txt = link_txt.split(' ');
    while let Some(s) = link_txt.next() {
        if s == "-o" {
            // pop off the output lib as well
            let _ = link_txt.next();
            break;
        }
    }

    // Now match all the remaining arguments against a regex looking for
    // shared library paths.
    link_txt.filter_map(|s| is_dylib_path(s, &re)).collect()
}

fn main() {
    // If the user has set CMAKE_PREFIX_PATH then we don't want to build the
    // bundled libraries, *unless* they have also set OPENEXR_BUILD_LIBRARIES=1
    let build_libraries = if std::env::var("CMAKE_PREFIX_PATH").is_ok() {
        if let Ok(obl) = std::env::var("OIIO_BUILD_LIBRARIES") {
            obl == "1"
        } else {
            false
        }
    } else {
        true
    };

    let out_dir = std::env::var("OUT_DIR").unwrap();
    let manifest_dir = std::env::var("CARGO_MANIFEST_DIR").unwrap();
    println!("cargo:warning=out dir is {}", out_dir);
    let target_dir = Path::new(&out_dir).ancestors().skip(3).next().unwrap();
    println!("cargo:warning=target dir is {}", target_dir.display());


    let clib_name = format!("{}-c", PRJ_NAME);
    let clib_versioned_name =
        format!("{}-c-{}_{}", PRJ_NAME, MJR_VERSION, MNR_VERSION);

    let lib_path = target_dir.join("lib");
    let cmake_prefix_path = lib_path.join("cmake");
    let dst = if build_libraries {
        build_deps(&manifest_dir, &target_dir);
        let _ = build_oiio(&target_dir);
        cmake::Config::new(clib_name)
            .define("CMAKE_EXPORT_COMPILE_COMMANDS", "ON")
            .define("CMAKE_PREFIX_PATH", cmake_prefix_path.to_str().unwrap())
            .build()
    } else {
        cmake::Config::new(clib_name)
            .define("CMAKE_EXPORT_COMPILE_COMMANDS", "ON")
            .build()
    };

    let link_txt_path = Path::new(&dst)
        .join("build")
        .join("CMakeFiles")
        .join(format!("{}-shared.dir", clib_versioned_name))
        .join("link.txt");

    let dylibs = get_linking_from_cmake(&link_txt_path);
    println!("cargo:warning=linklibs: {:?}", dylibs);

    // link our wrapper library
    println!("cargo:rustc-link-search=native={}", dst.display());
    println!("cargo:rustc-link-lib=static={}", clib_versioned_name);

    if build_libraries {
        // now copy the build dylibs to the top-level target directory and link from
        // there
        println!("cargo:rustc-link-search=native={}", lib_path.display());
        println!("cargo:warning=adding link path {}", lib_path.display());

        for d in dylibs {
            println!("cargo:rustc-link-lib=dylib={}", &d.libname);
            println!("cargo:warning=linking to {}", &d.libname);
        }

        // finally, set LD_LIBRARY_PATH to the target directory when running things
        // from cargo. If you want to install somewhere, you're on your own for now...
        #[cfg(target_os = "linux")]
        println!("cargo:rustc-env=LD_LIBRARY_PATH={}", lib_path.display());
        #[cfg(target_os = "macos")]
        println!("cargo:rustc-env=DYLD_LIBRARY_PATH={}", lib_path.display());
    } else {
        // If we're not building the libraries we don't want to go copying them
        // around, so just link to where CMake found them
        for d in dylibs {
            let libdir = Path::new(&d.path).parent().unwrap();
            println!("cargo:rustc-link-search=native={}", libdir.display());
            println!("cargo:rustc-link-lib=dylib={}", &d.libname);
        }
    }

    #[cfg(target_os = "linux")]
    println!("cargo:rustc-link-lib=dylib=stdc++");
    #[cfg(target_os = "macos")]
    println!("cargo:rustc-link-lib=dylib=c++");

    // Insert the C++ ABI info
    let output = std::process::Command::new("python")
        .args(&[&format!("{}-c/abigen/insert_abi.py", PRJ_NAME), 
              "src", 
              "src", 
              &format!("{}/build/abigen.txt", std::env::var("OUT_DIR").unwrap())])
        .output()
        .expect("Could not launch python insert_abi.py");

    if !output.status.success() {{
        panic!("python insert_abi failed");
    }}

}
