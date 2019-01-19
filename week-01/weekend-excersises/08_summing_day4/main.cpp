#include <iostream>
#include <string>

int sum (int a) {
    int b = 0;
    for (int i = 0; i <= a; i++)
        b += i;
    return b;
}

int main(int argc, char* args[]) {

    // - Write a function called `sum` that sum all the numbers
    //   until the given parameter and returns with an integer

    int num;

    std::cout << "Please give me a number to sum: " << std::endl;
    std::cin >> num;

    std::cout << "The sum of your number is: " << sum(num) << " Cheers, mate!" << std::endl;

    return 0;
}