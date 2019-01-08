#include "word-counter.h"

WordCounter::WordCounter(std::string word_to_count)
    : word_(word_to_count)
{
}

void WordCounter::processOneWordFromStream(std::istream& is)
{
    std::string word;
    is >> word;
    if (!is) {
        // sdf
    }
    if (word == word_)
        count_++;
}
