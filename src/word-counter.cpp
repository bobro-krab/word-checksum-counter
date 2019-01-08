#include "word-counter.h"

const char* punctuationSeparators = ",;.!?";

WordCounter::WordCounter(std::string word_to_count)
    : word_(word_to_count)
{
}

void WordCounter::processOneWordFromStream(std::istream& is)
{
    std::string word;
    is >> word;
    count_ += countWithSeparators(word);
}

size_t WordCounter::countWithSeparators(std::string& chunk) {
    size_t b = 0;
    std::string_view a(chunk);
    std::string_view wordToCount(word_);
    std::string_view separators(punctuationSeparators);
    size_t pos, prev = 0;

    while ((pos = a.find_first_of(separators, prev)) != std::string_view::npos) {
        if (pos > prev)
            if (a.substr(prev, pos - prev) == wordToCount) {
                b++;
            }
        prev = pos + 1;
    }

    if (a.substr(prev, a.size()) == wordToCount) {
        b++;
    }

    return b;
}
