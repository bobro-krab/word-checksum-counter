#include <getopt.h>
#include <cstring>
#include <string>
#include <iostream>

#include "counter-builder.h"

void printHelp(std::string programm_name) {
    std::cout << "Usage: " << programm_name << " <-m words|checksum> <-f filename_to_work_with> [-v]" << std::endl;
    std::cout << "This program can work in 2 modes:\n";
    std::cout << "1) -m words - Count words in selected file.\n";
    std::cout << "\tExample: " << programm_name << " -m words -v <word_you_want_to_count>" << "\n";
    std::cout << "2) -m checksum - Calculate checksum for specified file\n";
}

void countFile(std::string filename, Counter& counter) {
    std::ifstream input(filename);
    if (!input) {
        std::cerr << "Error open file " << filename << ": [" << errno << "] " << strerror(errno) << std::endl;
        return;
    }
    while (input >> counter) {
    }
    std::cout << "calculated result " << counter.getResult() << std::endl;
}

int main(int argc, char** argv)
{
    using namespace std;

    if (argc == 1) {
        printHelp(argv[0]);
        return 0;
    }

    string filename;
    CounterBuilder builder;

    int opt;
    while ((opt = getopt(argc, argv, "m:f:v:h")) != -1) {
        switch (opt) {
        case 'm': {
            if (string(optarg) == "words") {
            }
            if (string(optarg) == "checksum") {
                builder.countChecksumm();
            }
            break;
        }
        case 'f': {
            filename = string(optarg);
            break;
        }

        case 'v': {
            builder.countAWord(optarg);
            break;
        }

        case 'h': {
            printHelp(argv[0]);
            break;
        }
        }
    }

    std::unique_ptr<Counter> counter(builder.build());
    if (!counter) {
        std::cerr << "Some flags are missed or misused" << std::endl;
        printHelp(argv[0]);
        return EXIT_FAILURE;
    }
    countFile(filename, (*counter));

    return EXIT_SUCCESS;
}
