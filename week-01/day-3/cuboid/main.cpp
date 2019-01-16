#include <iostream>

int main(int argc, char* args[]) {

    double a = 10;

    double b = 20;

    double c = 30;

    double surface = (a + b + c) * 2;

    double volume = (a * b * c);

    std::cout << "Surface Area: " << surface << std::endl;
    std::cout << "Volume: " << volume << std::endl;

    return 0;
}