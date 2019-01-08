#ifndef COUNTER_H
#define COUNTER_H
#include <iostream>

class Counter {
public:
    virtual unsigned int getResult() = 0;
    virtual ~Counter() {}
    virtual void processOneWordFromStream(std::istream& is) = 0;
    friend std::istream& operator>>(std::istream& is, Counter& val);
};

#endif /* COUNTER_H */
