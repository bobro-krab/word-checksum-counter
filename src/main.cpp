#include <cstring>
#include <getopt.h>
#include <iostream>
#include <string>

#include "counter-builder.h"

void printHelp(std::string programm_name)
{
    std::cout << "Usage: " << programm_name << " <-m words|checksum> <-f filename_to_work_with> [-v]" << std::endl;
    std::cout << "This program can work in 2 modes:\n";
    std::cout << "1) -m words - Count words in selected file.\n";
    std::cout << "\tExample: " << programm_name << " -m words -v <word_you_want_to_count>"
              << "\n";
    std::cout << "2) -m checksum - Calculate checksum for specified file\n";
}

void countFile(std::string filename, Counter& counter)
{
    std::ifstream input(filename);
    if (!input) {
        std::cerr << "Error open file " << filename << ": [" << errno << "] " << strerror(errno) << std::endl;
        return;
    }
    while (input >> counter) {
    }
    std::cout << "calculated result " << counter.getResult() << std::endl;
}

struct ProgOptions {
    bool correct = true;
    std::string filename;
    std::string word_to_find;
    std::string mode;
};

ProgOptions processArgs(int argc, char** argv)
{
    ProgOptions result;
    const char* short_options = "m:f:v:h";
    // clang-format off
    struct option long_options[] = {
        { "mode",     required_argument, nullptr, 'm' },
        { "filename", required_argument, nullptr, 'f' },
        { "findword", required_argument, nullptr, 'v' },
        { "help",     no_argument,       nullptr, 'h' },
        { nullptr,    no_argument,       nullptr, 0 }
    };
    // clang-format on

    while (true) {
        const auto opt = getopt_long(argc, argv, short_options, long_options, nullptr);

        if (-1 == opt)
            break;

        switch (opt) {
        case 'm': {
            result.mode = std::string(optarg);
            break;
        }

        case 'v': {
            result.word_to_find = std::string(optarg);
            break;
        }

        case 'f': {
            result.filename = std::string(optarg);
            break;
        }

        case 'h':
            printHelp(argv[0]);
            result.correct = false;
            return result;

        case '?': // Unrecognized option
            break;
        }
    }

    if (result.mode.empty()) {
        std::cerr << "-m mode option is required" << std::endl;
        result.correct = false;
    }

    if (result.filename.empty()) {
        std::cerr << "-f filename option is required" << std::endl;
        result.correct = false;
    }

    if ("words" == result.mode && result.word_to_find.empty()) {
        std::cerr << "-v option shoud be specified for 'words' mode" << std::endl;
        result.correct = false;
    }

    if ("words" != result.mode && "checksum" == result.mode) {
        std::cerr << "-m should be 'words' or 'checksum'" << std::endl;
        result.correct = false;
    }

    return result;
}

int main(int argc, char** argv)
{
    using namespace std;

    auto options = processArgs(argc, argv);
    if (!options.correct) {
        return EXIT_FAILURE;
    }

    CounterBuilder builder;
    if (options.mode == "words") {
        builder.countAWord(options.word_to_find);
    }

    if (options.mode == "checksum") {
        builder.countChecksumm();
    }

    std::unique_ptr<Counter> counter(builder.build());
    if (!counter) {
        std::cerr << "Some flags are missed or misused" << std::endl;
        return EXIT_FAILURE;
    }

    countFile(options.filename, (*counter));
    return EXIT_SUCCESS;
}
