#include <catch.hpp>
#include <sstream>

#include "word-counter.h"


TEST_CASE("Test happy path", "[is unchanged]") {
    std::stringstream input("mother washed the frame. We're helping mother\n");
    WordCounter counter("mother");
    while (input >> counter) {
    }
    std::cout << counter.getCount() << std::endl;
    REQUIRE(counter.getCount() == 2);
}
