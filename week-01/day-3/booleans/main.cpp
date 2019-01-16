#include <iostream>

int main(int argc, char const *argv[]) {
    std::cout << true << std::endl;
    std::cout << false << std::endl;

    std::cout << !false << std::endl;
    std::cout << !true << std::endl;

    std::cout << (true && true) << std::endl;
    std::cout << (true && false) << std::endl;
    std::cout << (false && true) << std::endl;
    std::cout << (false && false) << std::endl;

    std::cout << (true || true) << std::endl;
    std::cout << (true || false) << std::endl;
    std::cout << (false || true) << std::endl;
    std::cout << (false || false) << std::endl;
    return 0;
}