#include <iostream>
#include <fstream>
#include <exception>

double divide (double a) {
    try {
        double b = 10;
        if (a == 0) {
            throw std::string("fail");
        } else {
            std::cout << b << " /" << a << " is: "<< b / a << std::endl;
        }
    }
    catch (std::string &f) {
        std::cout << f << std::endl;
    }
    return 0;
}

int main() {
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0

    double num;
    std::cout << "Give me a number" << std::endl;
    std::cin >> num;

    divide(num);

    return 0;
}