#include "SymetricEncriptor.hpp"
#include "TwoFish.hpp"
#include "BaseEncriptor.hpp"
#include <iostream>
#include <crypto/crypto.h>
using namespace TWOFISH;

int main (int argc, char** argv) {

   // std::string file = "/home/nareka/Desktop/Diploma/test/valodik";
   // BaseEncriptor ob(file);
   // ob.readDataFromFile();
   // auto input = ob.getData();
    const uint8_t *key = (const uint8_t*)"nareknareknarek";

    const uint8_t *text = (const uint8_t*)"valodik";
    TwoFish ob1(key, 16);

    uint8_t outbuffer[20];
    uint8_t outbuffer2[20];

    ob1.Encrypt(text, outbuffer);
    std::cout << outbuffer << std::endl;
    ob1.Decrypt(outbuffer, outbuffer2);
    std::cout << outbuffer2 << std::endl;


    return 0;
}
