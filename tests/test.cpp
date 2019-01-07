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

TEST_CASE("Read bytes if input is not aligned to 4 bytes", "[is unchanged]") {
    std::stringstream input("aaaab"); // 5 bytes
    u32word e;
    u32word previous;
    while(input >> e) {
        REQUIRE(!(e == previous));
        previous = e;
    }

}
