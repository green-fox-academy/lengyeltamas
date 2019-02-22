#include <iostream>

int main()
{
    std::cout << "Give me a number: " << std::endl;
    int num;
    std::cin >> num;

    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < (num - i); ++j) {
            std::cout << " ";
        }
        for (int k = 0; k < ((2 * i) -1); ++k) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}