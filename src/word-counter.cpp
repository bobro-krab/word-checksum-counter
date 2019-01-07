#include "word-counter.h"

WordCounter::WordCounter(std::string word_to_count)
    : word_(word_to_count)
{
}

std::istream& operator>>(std::istream& is, WordCounter& val)
{
    std::string word;
    is >> word;
    if (!is) {
        return is;
    }
    if (word == val.word_)
        val.count_++;
    return is;
}
