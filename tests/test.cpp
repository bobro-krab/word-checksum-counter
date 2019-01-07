#include <catch.hpp>
#include <sstream>
#include "u32word.h"

TEST_CASE("Checksum of one word is equals to this word", "[is unchanged]") {
    std::stringstream input("asdf");
    u32word e;
    u32word checksum;
    while(input >> e) {
        checksum = checksum + e;
    }

    REQUIRE(e == checksum);
}
