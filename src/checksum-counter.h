#include <iostream>
#include <fstream>
#include "u32word.h"

class ChecksumCounter
{
public:
    ChecksumCounter(std::string filename):filename(filename) {
    }
    unsigned int count_checksum() {
        u32word word, result;
        std::ifstream input(filename);
        if(!input) {
            std::cerr << "Can't open file: " << filename << std::endl;
        }

        while (input >> word) {
            result = result + word;
        }
        return result.asUnsignedInt();
    }
    virtual ~ChecksumCounter() {}
private:
    std::string filename;
};

