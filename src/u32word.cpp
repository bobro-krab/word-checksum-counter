#include "u32word.h"
u32word u32word::operator+(const u32word& other)
{
    u32word result = *this;
    result.value_.num += other.value_.num;
    return result;
}

bool u32word::operator ==(const u32word& other) const {
    return value_.num == other.value_.num;
}

bool u32word::operator <(const u32word& other) const {
    return value_.num < other.value_.num;
}

std::istream& operator>>(std::istream& is, u32word& val)
{
    unsigned int old_value = val.value_.num;
    val.value_.num = 0;
    for (auto i = 0; i < 4; ++i) {
        is.read(&val.value_.bytes[i], 1);
        if (!is) {
            if (is.fail() && i != 0) {
                // restore stream only if
                // can read at least one byte from stream
                is.clear();
            }
            val.value_.num = old_value;
            return is;
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const u32word& val)
{
    os << val.value_.num;
    return os;
}
