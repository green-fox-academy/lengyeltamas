#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // diamond like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //  *****
    //   ***
    //    *
    //
    // The diamond should have as many lines as the number was

    double num;

    std::cout << "How big diamonds do you like, Bae?" << std::endl;
    std::cin >> num;

    for (double i = 0; i > num; i++) {
        if (i < (num / 2)) {
            for (double j = i; j <= num; j++) {
                std::cout << " ";
            }
            for (double k = 0; )

        } else {


        } std::cout << "\n";
    }

    return 0;
}