#ifndef __TWOFISH__
#define __TWOFISH__
#include "Fish.hpp"

namespace TWOFISH {

    #ifndef TWOFISH_SMALL
    struct twofish_key {
    uint32_t S[4][256], K[40];
    };
    #else
    struct twofish_key {
    uint32 K[40];
    unsigned char S[32], start;
    };
    #endif

    class TwoFish : public Fish
    {
    public:
    static constexpr uint32_t BLOCKSIZE = 16;
    TwoFish(const UBYTE* key, int keylen);
    ~TwoFish();
    void Encrypt(const UBYTE *in, UBYTE *out) const override;
    void Decrypt(const UBYTE *in, UBYTE *out) const override;
    uint32_t GetBlockSize() const override {return BLOCKSIZE;} 

    private:
    twofish_key key_schedule;
    };
}




#endif //__TWOFISH__