fn main() -> anyhow::Result<()> {
    let path = std::path::PathBuf::from("tests/images/test16.png");
    let mut image_input = oiio::ImageInput::from_path(&path)?;

    let format_name = image_input.format_name();
    println!("format: {format_name}");

    image_input.set_threads(4);
    let threads = image_input.threads();
    println!("threads: {threads}");

    Ok(())
}
