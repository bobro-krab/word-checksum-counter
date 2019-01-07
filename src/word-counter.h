#ifndef WORD_COUNTER_H
#define WORD_COUNTER_H

#include <iostream>
#include <string>

class WordCounter
{
public:
    WordCounter(std::string word_to_count);
    virtual ~WordCounter() noexcept = default;

    friend std::istream& operator>>(std::istream& is, WordCounter& val);

    size_t getCount() const {
        return count_;
    }
protected:
private:
    size_t count_ = 0;
    std::string word_;
};

#endif /* WORD_COUNTER_H */
