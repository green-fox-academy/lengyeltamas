#include <iostream>

int main(int argc, char* args[]) {
    int a = 12;
    a += 4;
    std::cout << a << std::endl;

    int b = 12;
    b -= 4;
    std::cout << b << std::endl;

    int c = 12;
    std::cout << c++ << std::endl;
    std::cout << c << std::endl;

    int d = 12;
    std::cout << ++d << std::endl;
    std::cout << d << std::endl;

    int e = 12;
    std::cout << e-- << std::endl;
    std::cout << e << std::endl;

    int f = 12;
    std::cout << --f << std::endl;
    std::cout << f << std::endl;

    int g = 12;
    g *= 3;
    std::cout << g << std::endl;

    int h = 12;
    h /= 3;
    std::cout << h << std::endl;

    int i = 12;
    i %= 7;
    std::cout << i << std::endl;

    return 0;
}