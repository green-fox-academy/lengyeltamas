#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stored number is lower
    // You found the number: 8

    int guess = 13;
    int num = 0;
    while (num != guess) {
        std::cout << "Guess which number I was thinking about: "<< std::endl;
        std::cin >> num;
        if (num < guess) {
            std::cout << "The stored number is higher\n" << std::endl;
        }
        else if (num > guess) {
            std::cout << "The stored number is lower\n" << std::endl;
        }
        else {
            std::cout << "You found the number: " << guess << std::endl;
        }
    }

    return 0;
}