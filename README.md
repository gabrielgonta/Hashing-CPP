# 🔐 Portable C++ Hashing Library

## Description

Welcome to the Portable C++ Hashing Library! 🎉

This library provides efficient, fast, and portable hashing algorithms, including CRC32, MD5, SHA1, SHA256 (SHA2), and Keccak (with its SHA3 variant). It’s designed to be lightweight, dependency-free, and compatible across various platforms like Windows and Linux. Whether you're hashing strings, files, or using the library in streaming fashion, this library is a robust choice for your hashing needs.

## Features

Supports common hash algorithms: CRC32, MD5, SHA1, SHA256, Keccak, and SHA3

Optional HMAC (Keyed-Hash Message Authentication Code)

No external dependencies, ensuring a small code footprint

Works in a chunk-wise or streaming mode (ideal for large data or reading streams block-by-block)

Portable: tested on both Little Endian and Big Endian CPUs, supporting Windows and Linux

Performs at speeds comparable to Linux core hashing functions

Open source with the zlib license

## How to use

Here’s an example that computes SHA256 hashes, though the API is quite similar for all supported algorithms:

```
// SHA2 Test Program
#include "sha256.h"
#include <iostream> // Only needed for displaying the result

int main(int, char**)
{
  // Create a new hashing object
  SHA256 sha256;

  // Hashing an std::string
  std::cout << sha256("Hello World") << std::endl;
  // Output: a591a6d40bf420404a011733cfb7b190d62c65bf0bcda32b57b277d9ad9f146e

  // Hashing a buffer of bytes
  const char* buffer = "How are you";
  std::cout << sha256(buffer, 11) << std::endl;
  // Output: 9c7d5b046878838da72e40ceb3179580958df544b240869b80d0275cc07209cc

  // Streaming mode (re-use "How are you")
  SHA256 sha256stream;
  const char* url = "create.stephan-brumme.com"; // 25 bytes
  int step = 5;
  for (int i = 0; i < 25; i += step)
    sha256stream.add(url + i, step); // Add five bytes at a time
  std::cout << sha256stream.getHash() << std::endl;
  // Output: 82aa771f1183c52f973c798c9243a1c73833ea40961c73e55e12430ec77b69f6

  return 0;
}
```

## Installation

1. To integrate this hashing library into your project, follow these steps:

Clone the repository:

```
git clone https://github.com/gabrielgonta/Hashing-CPP.git
```

2. Navigate to your project directory and include the hashing library headers into your project.
3. Compile your project as usual. Since this is a header-only library, no additional linking is required.

## How I try to stand out

    ✔️ No external dependencies: The library is entirely self-contained, ensuring minimal bloat.
    ✔️ Cross-platform support: Fully compatible with both Windows and Linux systems.
    ✔️ Stream processing: Hash data incrementally, ideal for large files or streaming inputs.
    ✔️ Fast and reliable: Similar speed to native hashing implementations in Linux.

## Authors

* **Gabriel Gonta** - *Initial work* - [Hashing-CPP](https://github.com/gabrielgonta/Hashing-CPP.git)