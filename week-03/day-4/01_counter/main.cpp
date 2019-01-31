#include <iostream>

// Write a recursive function that takes one parameter: n and counts down from n.

void counter (int countfrom) {
    if (countfrom >= 1) {
        std::cout << "Number: " << countfrom << std::endl;
        counter(countfrom - 1);
    }
}

int main() {

    int n;
    std::cout << "Give me a number to count down from: " << std::endl;
    std::cin >> n;

    counter(n);

    return 0;
}