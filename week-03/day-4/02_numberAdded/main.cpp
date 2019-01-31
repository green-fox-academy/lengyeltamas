#include <iostream>

// Write a recursive function that takes one parameter: n and adds numbers from 1 to n.

int sumto (int number) {
    if (number <= 1) {
        return 1;
    } else {
       return number + sumto(number - 1);
    }

}

int main() {

    int n;
    std::cout << "Give me a number to sum it from 1: " << std::endl;
    std::cin >> n;
    std::cout << sumto(n) << std::endl;

    sumto(n);

    return 0;
}