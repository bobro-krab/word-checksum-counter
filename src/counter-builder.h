#include <memory>

#include "counter.h"
#include "checksum-counter.h"
#include "word-counter.h"

class CounterBuilder {
    enum class ProgramModes {no_mode, checksum, words};
public:
    CounterBuilder& countAWord(std::string word) {
        mode_ = ProgramModes::words;
        wordToCount = word;
        return *this;
    }
    CounterBuilder& countChecksumm() {
        mode_ = ProgramModes::checksum;
        return *this;
    }

    Counter* build() {
        switch(mode_) {
        case ProgramModes::words: {
            return new WordCounter(wordToCount);
            break;
        }
        case ProgramModes::checksum: {
            return new ChecksumCounter();
            break;
        }
        case ProgramModes::no_mode: {
            return nullptr;
        }
        }
        return nullptr;
    }
private:
    std::string wordToCount = "";
    ProgramModes mode_ = ProgramModes::no_mode;
};
