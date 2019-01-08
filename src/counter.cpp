#include "counter.h"

std::istream& operator >>(std::istream& is, Counter& val) {
    val.processOneWordFromStream(is);
    return is;
}
