#ifndef COUNTER_BUILDER_H
#define COUNTER_BUILDER_H

#include <memory>

#include "checksum-counter.h"
#include "counter.h"
#include "word-counter.h"

class CounterBuilder {
    enum class ProgramModes {
        noMode,
        checksum,
        words
    };

public:
    CounterBuilder& countAWord(std::string word)
    {
        mode_ = ProgramModes::words;
        wordToCount = word;
        return *this;
    }
    CounterBuilder& countChecksumm()
    {
        mode_ = ProgramModes::checksum;
        return *this;
    }

    Counter* build()
    {
        switch (mode_) {
        case ProgramModes::words: {
            return new WordCounter(wordToCount);
        }
        case ProgramModes::checksum: {
            return new ChecksumCounter();
        }
        case ProgramModes::noMode: {
            return nullptr;
        }
        }
        return nullptr;
    }

private:
    std::string wordToCount = "";
    ProgramModes mode_ = ProgramModes::noMode;
};

#endif /* COUNTER-BUILDER_H */
