use cppmm_build::{build, Dependency};

fn main() {
    build(
        "PROJECT_NAME",
        MAJOR_VERSION,
        MINOR_VERSION,
        &vec![
            Dependency {
                name: "oiio",
                definitions: vec![
                    ("OIIO_BUILD_TOOLS", "OFF"),
                    ("OIIO_BUILD_TESTS", "OFF"),
                    ("BUILD_DOCS", "OFF"),
                    ("USE_PYTHON", "OFF"),
                ],
            },
        ],
    );
}


