#include <iostream>

// Given a non-negative int n, return the sum of its digits recursively (no loops).
// Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), while
// divide (/) by 10 removes the rightmost digit (126 / 10 is 12).

int digitSum (int n) {

    if (n == 0) {
        return 0;
    }else {
        return (n % 10 + digitSum(n / 10));
    }
}

int main() {

    int number;
    std::cout << "Give me a number and i'll tell you the sum of its digits: " <<std::endl;
    std::cin >> number;
    std::cout << "The sum of your number's digits are: " << digitSum(number);

    return 0;
}