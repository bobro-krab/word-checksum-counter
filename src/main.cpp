#include <bits/stdc++.h>

#include "u32word.h"
#include "word-counter.h"

int main(int argc, char** argv)
{
    using namespace std;
    u32word e;
    u32word result;
    while (cin >> e) {
        std::cout << std::hex << "0x" << setfill('0') << setw(8) << e << std::endl;
        result = e + result;
    }
    std::cout << "Checksumm is " << result << std::endl;
    std::cout << std::dec;
    return 0;
}
