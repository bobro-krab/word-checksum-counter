#ifndef WORD_COUNTER_H
#define WORD_COUNTER_H

#include <iostream>
#include <string>

#include "counter.h"

class WordCounter : public Counter {
public:
    WordCounter(std::string word_to_count);
    virtual ~WordCounter() noexcept = default;

    void processOneWordFromStream(std::istream& is);

    unsigned int getResult()
    {
        return static_cast<unsigned int>(count_);
    }

private:
    size_t count_ = 0;
    std::string word_;
};

#endif /* WORD_COUNTER_H */
