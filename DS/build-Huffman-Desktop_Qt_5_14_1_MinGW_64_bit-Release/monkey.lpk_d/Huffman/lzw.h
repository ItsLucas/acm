#ifndef LZW_H
#define LZW_H

#include <vector>

class LZWCodec {
  public:
    void encode(const std::vector<unsigned char> &input,
                std::vector<unsigned char> &encoded);

    void decode(const std::vector<unsigned char> &encoded,
                std::vector<unsigned char> &decoded);

  private:
    bool verbose, printTime;
    unsigned maxBits1, maxBits2;
};

#endif
