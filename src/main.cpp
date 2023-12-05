#include <iostream>
#include <bitset>

int main() {
    std::cout << "hi from assembler" << std::endl;
    std::bitset<3> x(19);
    std::cout << x << std::endl;
    return 0;
}
