#ifndef U32WORD_H
#define U32WORD_H

#include <iostream>

const unsigned int word_size = 4;

typedef union {
    char bytes[word_size];
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

    u32word operator+(const u32word& other);
    bool operator==(const u32word& other) const;
    bool operator<(const u32word& other) const;
    friend std::istream& operator>>(std::istream& is, u32word& val);
    friend std::ostream& operator<<(std::ostream& os, const u32word& val);

    unsigned int asUnsignedInt();

private:
    DataHolder value_;
};

#endif /* U32WORD_H */
