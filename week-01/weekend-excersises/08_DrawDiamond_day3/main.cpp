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

    int num;

    std::cout << "How big diamond would you like, Bae?" << std::endl;
    std::cin >> num;

    int evennum;
    int oddnum;

    if (num % 2 == 0) {
        num = evennum;
    } else {
        num = oddnum;
    }

   for (int i = 0; i <= evennum; i++) {
       if (i <= ((evennum / 2) + 1) {

       }
   }

    return 0;
}