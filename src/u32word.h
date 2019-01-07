#ifndef U32WORD_H
#define U32WORD_H

#include <iostream>

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

    u32word operator+(const u32word& other);
    friend std::istream& operator>>(std::istream& is, u32word& val);
    friend std::ostream& operator<<(std::ostream& os, const u32word& val);

protected:
private:
    DataHolder value_;
};


#endif /* U32WORD_H */
