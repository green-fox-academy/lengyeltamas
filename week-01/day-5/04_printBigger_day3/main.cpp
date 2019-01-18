#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two numbers and prints the bigger one

    int num1;
    int num2;

    std::cout << "Give me 2 numbers to decide which is the bigger: " << std::endl;
    std::cin >> num1;
    std::cin >> num2;

    if (num1 <= num2) {
        std::cout << num2 << " is the bigger one!" << std::endl;
    } else {
        std::cout << num1 << " is the bigger one!" << std::endl;
    }

    return 0;
}