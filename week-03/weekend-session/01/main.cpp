#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for a number.
    // It would ask this many times to enter an integer,
    // if all the integers are entered, it should print the sum and average of these
    // integers like:
    //
    // Sum: 22, Average: 4.4

    double loops;
    std::cout << "Give me a number: " << std::endl;
    std::cin >> loops;

    double numberToSum = 0;
    double inputNumber;
    for (unsigned int i = 0; i < loops; i++) {
        std::cout << "Give me the number " << i + 1 << "'s value: " << std::endl;
        std::cin >> inputNumber;
        numberToSum +=inputNumber;
    }

    double sum = numberToSum / loops;
    std::cout << "Your given numbers sum is: " << numberToSum << ". Your given numbers average is: " << sum << std::endl;

    return 0;
}