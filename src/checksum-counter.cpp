#include "checksum-counter.h"

void ChecksumCounter::processOneWordFromStream(std::istream& is)
{
    u32word e;
    is >> e;
    if (is) {
        result = result + e;
    }
}
