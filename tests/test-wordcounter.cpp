#include <catch.hpp>
#include <sstream>

#include "word-counter.h"


TEST_CASE("Test happy path", "[is unchanged]") {
    std::stringstream input("mother washed the frame. We're helping mother\n");
    WordCounter counter("mother");
    while (input >> counter) {
    }
    REQUIRE(counter.getResult() == 2);
}

TEST_CASE("Test unicode support", "[is unchanged]") {
    std::stringstream input("раз раз раз два три");
    WordCounter counter("раз");
    while (input >> counter) {
    }
    REQUIRE(counter.getResult() == 3);
}

TEST_CASE("Test whitespace separators", "[separators]") {
    std::stringstream input("mother mother\nmother\tmother\rmother");
    WordCounter counter("mother");
    while (input >> counter) {
    }
    REQUIRE(counter.getResult() == 5);
}

TEST_CASE("Test punctuation separators", "[separators]") {
    std::stringstream input("mother,mother! mother;mother? ");
    WordCounter counter("mother");
    while (input >> counter) {
    }
    REQUIRE(counter.getResult() == 4);
}

TEST_CASE("Count only words with separators, not substrings", "[separators]") {
    std::stringstream input("mother of mother is grandmother");
    WordCounter counter("mother");
    while (input >> counter) {
    }
    REQUIRE(counter.getResult() == 2);
}
