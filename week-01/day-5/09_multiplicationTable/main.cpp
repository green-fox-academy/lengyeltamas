#include <iostream>

int main(int argc, char* args[]) {

    // Create a program that asks for a number and prints the multiplication table with that number
    //
    // Example:
    // The number 15 should print:
    //
    // 1 * 15 = 15
    // 2 * 15 = 30
    // 3 * 15 = 45
    // 4 * 15 = 60
    // 5 * 15 = 75
    // 6 * 15 = 90
    // 7 * 15 = 105
    // 8 * 15 = 120
    // 9 * 15 = 135
    // 10 * 15 = 150

    int num;

    std::cout << "Give me a number and i'll tell you the multiplication table with it! " << std::endl;
    std::cin >> num;

    for (int i = 1; i <= 10; i = i+1) {
        std::cout << i << " * " << num * i << std::endl;
    }

    return 9;
}