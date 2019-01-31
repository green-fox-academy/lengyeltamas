#include <iostream>

// Given base and n that are both 1 or more, compute recursively (no loops)
// the value of base to the n power, so powerN(3, 2) is 9 (3 squared).

int exponentation (int basenum, int powernum) {

    if (powernum >= 1){
        return (basenum * exponentation(basenum, (powernum - 1)));
    } else {
        return 1;
    }
}

int main() {
    int base;
    int power;

    std::cout << "Give me the base: " << std::endl;
    std::cin >> base;
    std::cout << "Give me the power: " << std::endl;
    std::cin >> power;

    std::cout << "The result of exponentation is: " << exponentation(base, power) << std::endl;

    return 0;
}