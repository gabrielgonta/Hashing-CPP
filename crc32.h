#pragma once

//#include "hash.h"
#include <string>

// define fixed size integer types
#ifdef _MSC_VER
// Windows
typedef unsigned __int8  uint8_t;
typedef unsigned __int32 uint32_t;
#else
// GCC
#include <stdint.h>
#endif

class CRC32 //: public Hash
{
public:
  /// hash is 4 bytes long
  enum { HashBytes = 4 };

  /// same as reset()
  CRC32();

  /// compute CRC32 of a memory block
  std::string operator()(const void* data, size_t numBytes);
  /// compute CRC32 of a string, excluding final zero
  std::string operator()(const std::string& text);

  /// add arbitrary number of bytes
  void add(const void* data, size_t numBytes);

  /// return latest hash as 8 hex characters
  std::string getHash();
  /// return latest hash as bytes
  void        getHash(unsigned char buffer[HashBytes]);

  /// restart
  void reset();

private:
  /// hash
  uint32_t m_hash;
};
