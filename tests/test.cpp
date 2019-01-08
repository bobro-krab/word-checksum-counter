#include <catch.hpp>
#include <sstream>
#include "u32word.h"
#include "checksum-counter.h"
#include "counter.h"

TEST_CASE("Checksum of one word is equals to this word", "[is unchanged]") {
    std::stringstream input("abcd");
    u32word e;
    u32word checksum;
    while(input >> e) {
        checksum = checksum + e;
    }

    REQUIRE(e == checksum);
    REQUIRE(checksum.asUnsignedInt() == 0x64636261);
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

TEST_CASE("Direct call word and using checkusm counter interface give same results", "[interface]") {
    std::string inputString("aaaab");

    std::stringstream input(inputString);
    u32word e;
    u32word checksum;
    while(input >> e) {
        checksum = checksum + e;
    }

    std::stringstream counterInput(inputString);
    ChecksumCounter cc;
    Counter& counter(cc);
    while (counterInput >> counter) {}

    REQUIRE(cc.getResult() == checksum.asUnsignedInt());
}
