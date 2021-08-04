# Reading and Writing Image Files

[`ImageInput`]: crate::imageio::ImageInput
[`Imageoutput`]: crate::imageio::ImageOutputBase
[`ImageSpec`]: crate::imageio::ImageSpec
[`Roi`]: crate::imageio::Roi
[`TypeDesc`]: crate::imageio::TypeDesc

The imageio module contains structs to made reading and writing image files of
any supported format easy and consistent. The main interfaces are [`ImageInput`]
and [`ImageOutput`], for reading and writing, respectively.

Helper structs are provided to ease manipulating image metadata, dimensions and
layout. These are 
* [`TypeDesc`] which describes the type of image channels and metadata
* [`Roi`] which describes a Region Of Interest, i.e. a particular section of the
image
* [`ImageSpec`] which abstracts the image header, holding details on the dimensions,
metadata, etc.

# ImageOutput: writing images

Here is the simplest sequence required to write the pixels of a 2D image to a file:

```no_run
# use oiio::Error;
# fn write_ex1() -> Result<(), Error> {
    use oiio::prelude::*;

    let width = 640;
    let height = 480;
    let num_channels = 3; // RGB
    let pixels = vec![0u8; width * height * num_channels];
    let spec = ImageSpec::from_dimensions(
        width,
        height,
        num_channels,
        TypeDesc::UINT8,
    );

    // Search for an ImageIO plugin that is capable of writing the file
    // `foo.jpg`), deducing the format from the file extension.  When it
    // finds such a plugin, it creates a subclass instance of `ImageOutput`
    // that writes the right kind of file format.
    //
    // Then, open the file, write the correct headers, and in all other important ways
    // prepare a file with the given dimensions (640 x 480), number of color
    // channels (3), and data format (unsigned 8-bit integer).
    let mut out =
        ImageOutput::new("foo.jpg", &spec, OpenMode::Create, None, None)?;

    // Write the entire image, hiding all details of the encoding of image data
    // in the file, whether the file is scanline- or tile-based, or what is the
    // native format of data in the file (in this case, our in-memory data is
    // unsigned 8-bit and we've requested the same format for disk storage, but
    // if they had been different, `write_image()` would do all the conversions
    // for us).
    out.write_image(&pixels, Strides::default())?;

#    Ok(())
# }
```

This little bit of code does a surprising amount of useful work:

  


## What happens when the file format doesn't support the spec?

The `new()` call will return an error if the output format cannot accommodate what is
requested by the [`ImageSpec`]. This includes:

* Dimensions (width, height, or number of channels) exceeding the limits
  supported by the file format.
* Volumetric (depth > 1) if the format does not support volumetric data.
* Tile size >1 if the format does not support tiles.
* Multiple subimages or MIP levels if not supported by the format.

> 🛈 One exception to the rule about number of channels is that a file format 
that supports only RGB, but not alpha, is permitted to silently drop the 
alpha channel without considering that to be an error.

However, several other mismatches between requested `ImageSpec` and file
format capabilities will be silently ignored, allowing `new()` to
succeed:

* If the pixel data format is not supported (for example, a request for
  `half` pixels when writing a JPEG/JFIF file), the format writer
  may substitute another data format (generally, whichever commonly-used
  data format supported by the file type will result in the least reduction
  of precision or range).
* If the `ImageSpec` requests different per-channel data formats, but
  the format supports only a single format for all channels, it may just
  choose the most precise format requested and use it for all channels.
* If the file format does not support arbitrarily-named channels, the
  channel names may be lost when saving the file.
* Any other metadata in the `ImageSpec` may be summarily dropped if not
  supported by the file format.

# Advanced image output

Let's walk through many of the most common things you might want to do, but
that are more complex than the simple example above.

## Writing individual scanlines, tiles, and rectangles

The simple example above wrote an entire image with one call.  But sometimes you 
are generating output a little at a time and do not wish to retain the entire 
image in memory until it is time to write the file.  OpenImageIO allows you to 
write images one scanline at a time, one tile at a time, or by individual rectangles.

### Writing individual scanlines

Individual scanlines may be written using [`write_scanline()`](crate::imageio::ImageOutputBase::write_scanline):

```
# use oiio::Error;
# fn write_ex1() -> Result<(), Error> {
    use oiio::prelude::*;

    # let width = 640;
    # let height = 480;
    # let num_channels = 3; // RGB
    # let spec = ImageSpec::from_dimensions(
    #    width,
    #    height,
    #    num_channels,
    #    TypeDesc::UINT8,
    # );

    let mut scanline = vec![0u8; width * num_channels];
    let mut out =
        ImageOutput::new("foo.jpg", &spec, OpenMode::Create, None, None)?;

    for y in 0..height {
        // generate scanline data
        // ...

        // write generated scanline to output
        out.write_scanline(y as i32, 0, &scanline, Stride::AUTO)?;
    }


#    Ok(())
# }
```

The first two arguments to [`write_scanline()`](crate::imageio::ImageOutputBase::write_scanline) specify which scanline is
being written by its vertical `y` scanline number (beginning with 0)
and, for volume images, its slice `z` number (the slice number should
be 0 for 2D non-volume images).  This is followed by the slice of pixel data
itself.  Finally, we pass the data stride, which should be `Stride::AUTO`
for contiguous data.

All [`ImageOutput`] implementations will accept scanlines in strict order
(starting with scanline 0, then 1, up to `height-1`, without skipping
any).  

