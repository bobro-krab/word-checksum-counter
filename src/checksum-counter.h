#ifndef CHECKSUM_COUNTER_H
#define CHECKSUM_COUNTER_H

#include "counter.h"
#include "u32word.h"
#include <fstream>
#include <iostream>

class ChecksumCounter : public Counter {
public:
    ChecksumCounter()
    {
    }
    void processOneWordFromStream(std::istream& is);
    unsigned int getResult() final
    {
        return static_cast<unsigned int>(result.asUnsignedInt());
    }
    virtual ~ChecksumCounter() {}

private:
    u32word result;
};

#endif /* CHECKSUM_COUNTER_H */
