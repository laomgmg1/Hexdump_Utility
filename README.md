# My Hexdump_utility

A simple command-line hex dump utility written in C. It reads a file in binary mode and displays its contents as hexadecimal byte values, organized into rows of 16 bytes with their corresponding file offsets.

This project is part of my journey learning C programming, binary file I/O, and systems programming.

## Features

- **Binary file reading:** Opens files in binary mode using `fopen()`.
- **Hexadecimal output:** Displays each byte in hexadecimal notation.
- **File offsets:** Shows the offset of the first byte in each row.
- **16-byte rows:** Organizes the output into rows of up to 16 bytes.
- **Basic error handling:** Reports file-opening errors and validates command-line arguments.

## Requirements

- A C compiler, such as GCC or Clang.
- A terminal or command-line environment.

## Compilation

Compile the source file using GCC:

```bash
gcc -Wall -Wextra -std=c11 myhexdump.c -o myhexdump
```

## Usage

Run the program with a filename as its argument:

```bash
./myhexdump <filename>
```

For example:

```bash
./myhexdump text.txt
```

## Example

Suppose `text.txt` contains:

```text
Hello, world!
```

The output will resemble:

```text
offset          byte
00000000        0x48 0x65 0x6C 0x6C 0x6F 0x2C 0x20 0x77 0x6F 0x72 0x6C 0x64 0x21 0x0A
```

The exact output depends on the contents of the input file. The `0x0A` byte represents the newline character at the end of this example file.

## How It Works

1. **Argument validation:** Checks that the user provides exactly one filename.
2. **File opening:** Opens the specified file in binary mode (`"rb"`).
3. **Byte reading:** Uses `fgetc()` to read one byte at a time. The return value is stored in an `int` so it can represent both byte values and `EOF`.
4. **Hexadecimal conversion:** Uses `printf()` with `%02X` to display each byte as two hexadecimal digits.
5. **Offset tracking:** Maintains a byte offset, starting at zero, and increments it after each byte.
6. **Row formatting:** Tracks the number of bytes processed and starts a new row after every 16 bytes.
7. **Resource cleanup:** Closes the input file before exiting.

## Current Limitations

- Displays hexadecimal bytes only; an ASCII interpretation column is not yet implemented.
- Reads one byte at a time rather than using buffered reads.
- Does not yet support command-line options or multiple input files.
- Does not yet report file-reading errors separately from end-of-file.
- Does not yet include advanced formatting options.

## Planned Improvements

- Add an ASCII representation alongside the hexadecimal output.
- Improve column alignment and formatting.
- Handle file-reading errors using `ferror()`.
- Explore buffered reading with `fread()`.
- Add tests for empty files, binary files, and files whose sizes are not multiples of 16.

## Learning Objectives

This project explores:

- C command-line arguments (`argc` and `argv`).
- File handling with `fopen()`, `fgetc()`, and `fclose()`.
- End-of-file handling with `EOF`.
- Formatted output using `printf()`.
- Hexadecimal representation of bytes.
- Counters, offsets, and row-based formatting.
- Basic error handling in C.

## License

No license has been specified yet.
