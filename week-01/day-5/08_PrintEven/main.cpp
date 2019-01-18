#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // Create a program that prints all the even numbers between 0 and 500

    int a = 2;

    while (a < 500) {
        std::cout << a << std::endl;
        a += 2;
    }

    return 0;
}