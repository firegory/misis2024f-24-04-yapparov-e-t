# ImageApp

ImageApp is a C# Windows Forms project for experimenting with a custom lossless image format and data integrity checks.

The application can read common image files, convert them to an internal pixel representation, save them in a custom binary format, open saved files, and build comparison graphs for compression and transmission experiments.

Russian version: [README.ru.md](README.ru.md)

## Features

- Windows Forms interface for saving and opening images.
- Custom palette-based image encoding:
  - stores the list of unique RGB colours once;
  - writes each pixel as an index in that palette;
  - uses the minimum number of bits needed for the palette size.
- Improved encoder with run-length encoding (RLE) for consecutive pixels of the same colour.
- Comparison graphs for PNG, the standard encoder, and the improved encoder.
- Transmission error simulation by randomly flipping bits.
- Integrity-check experiments:
  - parity bit blocks;
  - MD5 hashes for fixed-size data blocks.

## Repository layout

```text
ВычМач/ImageApp/
├── ImageApp.sln          # Visual Studio solution
├── ImageApp/             # C# Windows Forms project
│   ├── Form1.cs          # Main UI, image format, compression and integrity logic
│   ├── Form2.cs          # Compression comparison chart
│   ├── Form3.cs          # Integrity-check comparison chart
│   └── ImageApp.csproj
├── images/               # Test screenshots used for statistics
└── a.bin                 # Example binary image file
```

## Requirements

- Windows with .NET Framework 4.7.2 or newer.
- Visual Studio with .NET desktop development tools.

The project is a classic Windows Forms application and is intended to be built and run on Windows.

## How to run

1. Open `ВычМач/ImageApp/ImageApp.sln` in Visual Studio.
2. Restore/build the solution.
3. Run the `ImageApp` project.

## Main actions in the app

- **Save Image** — open an image and save it in the custom binary format.
- **See Image** — open a previously saved `.bin` file and display the decoded image.
- **Show graph** — compare the custom encoders with PNG using the test image set.
- **Show graph 2** — run integrity-check experiments and display the resulting graph.

## Format overview

The basic image format stores:

1. 24 bits — number of unique colours.
2. 16 bits — image width.
3. 16 bits — image height.
4. 24 bits per colour — RGB palette entries.
5. Pixel data — each pixel is stored as a palette index using `ceil(log2(colourCount))` bits.

The improved format keeps the same header and palette, but stores repeated consecutive pixels as `(run length, colour index)` pairs. The run length is stored in 8 bits.

## Integrity-check experiments

The second part of the project tests how bit sequences survive transmission with random errors.

- The parity-bit method inserts one check bit for every 8 data bits.
- The MD5 method splits data into 952-bit blocks and appends a 128-bit MD5 hash to each block.

Both methods are tested by repeatedly flipping random bits with a chosen probability and comparing the received data with the original.

## Notes

Some file dialogs in the current code use absolute Windows paths from the original development machine. If you run the project on another PC, update these paths or choose files manually through the dialog when possible.

Build artifacts and Visual Studio local files are ignored by `.gitignore`, but older generated files may still exist in the repository history.
