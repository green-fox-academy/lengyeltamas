#include <iostream>

// Create a recursive function called `refactorio`
// that returns it's input's factorial

int refactorio (int input) {
    if (input >= 1) {
        return input * refactorio(input - 1);
    } else {
        return 1;
    }
}

int main() {
    int number;
    std::cout << "Give me a positive number and i'll give you the factorial of it: " << std::endl;
    std::cin >> number;
    std::cout << "Your number's factorial is: " << refactorio(number) << std::endl;

    return 0;
}