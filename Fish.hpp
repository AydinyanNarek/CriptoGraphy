#ifndef __FISH__
#define __FISH__
#include <stdint.h>

class Fish
{
public:
    using UBYTE = uint8_t;
public:
  Fish() = default;
  virtual ~Fish() = default;
  virtual uint32_t GetBlockSize() const = 0;
  virtual void Encrypt(const UBYTE *plainText, UBYTE *cipherText) const = 0;
  virtual void Decrypt(const UBYTE *cipherText, UBYTE *plainText) const = 0;
};



#endif //__FISH__