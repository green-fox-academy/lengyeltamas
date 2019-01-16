#include <iostream>

int main(int argc, char* args[]) {

    int num1, num2, num3, num4, num5, sum;

    double average;

    std::cout << "Yo, tell me 5 numbers, and I'll tell you their SUM and average! " << std::endl;
    std::cin >> num1;
    std::cin >> num2;
    std::cin >> num3;
    std::cin >> num4;
    std::cin >> num5;
    sum = num1 + num2 + num3 + num4 + num5;
    average = sum / 5;

    std::cout << "SUM: " << sum << ", Average: " << average;

    return 9;
}