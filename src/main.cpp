#include <bits/stdc++.h>

typedef union {
    char bytes[4];
    unsigned int num = 0;
} DataHolder;

/*
  This class is represents 4 byte word.
  It can be used with input and output;
 */
class u32word {
public:
    u32word() {}
    virtual ~u32word() noexcept {}

    friend std::istream& operator>>(std::istream& is, u32word& val);
    friend std::ostream& operator<<(std::ostream& os, const u32word& val);
    u32word operator+(const u32word& other)
    {
        u32word result = *this;
        result.value_.num += other.value_.num;
        return result;
    }

protected:
private:
    DataHolder value_;
};

std::istream& operator>>(std::istream& is, u32word& val)
{
    is.read(val.value_.bytes, 4);
    if (is) {
    } else {
        // TODO: implement reading last bytes
        // TODO: to read EOF or not?
        if (is.eof()) {
            std::cout << "File ends" << std::endl;
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const u32word& val)
{
    os << val.value_.num;
    return os;
}

int main(int argc, char** argv)
{
    using namespace std;
    std::stringstream input("aaaaa");
    u32word e;
    u32word result;
    while (input >> e) {
        std::cout << std::hex << "0x" << e << std::endl;
        result = e + result;
    }
    std::cout << "Checksumm is " << result << std::endl;
    std::cout << std::dec;
    return 0;
}
