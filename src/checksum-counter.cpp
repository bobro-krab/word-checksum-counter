#include "checksum-counter.h"

std::istream& operator>>(std::istream& is, ChecksumCounter& val)
{
    u32word e;
    is >> e;
    if (is) {
        val.result = val.result + e;
    }
    return is;
}

void ChecksumCounter::processOneWordFromStream(std::istream& is)
{
    u32word e;
    is >> e;
    if (is) {
        result = result + e;
    }
}
