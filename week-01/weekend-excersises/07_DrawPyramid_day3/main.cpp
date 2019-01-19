#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // triangle like this:
    //
    // *
    // **
    // ***
    // ****
    //
    // The triangle should have as many lines as the number was

    int num;

    std::cout << "Dude, how tall pyramid should I bulid for ya? " << std::endl;
    std::cin >> num;

    for (int i = 0; i <= num; i++) {

        for (int j = i; j <= num; j++) {
            std::cout << " ";
        }

        for (int k = 0; k <= (i * 2); k++) {
            std::cout << "*";
        }

        std::cout << "\n";
    }

    std::cout << "\n     Sweeeeet" << std::endl;


    return 0;
}