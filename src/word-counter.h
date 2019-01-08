#ifndef WORD_COUNTER_H
#define WORD_COUNTER_H

#include <iostream>
#include <string>

#include "counter.h"

class WordCounter : public Counter {
public:
    WordCounter(std::string word_to_count);
    virtual ~WordCounter() noexcept = default;

    friend std::istream& operator>>(std::istream& is, WordCounter& val);
    void processOneWordFromStream(std::istream& is);

    size_t getCount() const
    {
        return count_;
    }
    unsigned int getResult() final
    {
        return static_cast<unsigned int>(count_);
    }

private:
    size_t count_ = 0;
    std::string word_;
};

#endif /* WORD_COUNTER_H */
