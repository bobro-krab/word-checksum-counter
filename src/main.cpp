#include <getopt.h>
#include <string>

#include "u32word.h"
#include "word-counter.h"

void printHelp(std::string programm_name) {
    std::cout << "Usage: " << programm_name << " <-m words|checksum> <-f filename_to_work_with> [-v]" << std::endl;
    std::cout << "This program can work in 2 modes:\n";
    std::cout << "1) -m words - Count words in selected file.\n";
    std::cout << "\tExample: " << programm_name << " -m words -v <word_you_want_to_count>" << "\n";
    std::cout << "2) -m checksum - Calculate checksum for specified file\n";
}

enum class ProgramModes {no_mode, checksum, words};

int main(int argc, char** argv)
{
    using namespace std;

    if (argc == 1) {
        printHelp(argv[0]);
        return 0;
    }

    ProgramModes mode = ProgramModes::no_mode;
    string filename;
    string word_to_count;

    int opt;
    while ((opt = getopt(argc, argv, "m:f:v:h")) != -1) {
        switch (opt) {
        case 'm': {
            if (string(optarg) == "words") {
                mode = ProgramModes::words;
            }
            if (string(optarg) == "checksum") {
                mode = ProgramModes::checksum;
            }
            break;
        }
        case 'f': {
            filename = string(optarg);
            break;
        }

        case 'v': {
            word_to_count = string(optarg);
            break;
        }

        case 'h': {
            printHelp(argv[0]);
            break;
        }
        }
    }

    switch (mode) {
    case ProgramModes::no_mode: {
        printHelp(argv[0]);
        return 0;
    }
    case ProgramModes::words: {
        break;
    }
    case ProgramModes::checksum: {
        break;
    }
    }

    return 0;
}
