#include <iostream>

int main()
{
    std::cout << "Give me a number: " << std::endl;
    int num;
    std::cin >> num;

    if (num % 2 != 0) {
        for (int i = 1; i <= num; ++i) {
            if (i < ((num / 2) + 2)) {
                for (int j = 0; j < ((num / 2) - i + 1); ++j) {
                    std::cout << " ";
                }
                for (int k = 0; k < ((2 * i) - 1); ++k) {
                    std::cout << "*";
                }
            } else {
                for (int j = 0; j < (i - ((num / 2) + 1)); ++j) {
                    std::cout << " ";
                }
                for (int k = 0; k < (((num  - i + 1) * 2) - 1 ); ++k) {
                    std::cout << "*";
                }
            }
            std::cout << std::endl;
        }
    } else {
        for (int i = 1; i <= num; ++i) {
            if (i <= (num / 2)) {
                for (int j = 0; j < ((num / 2) - i); ++j) {
                    std::cout << " ";
                }
                for (int k = 0; k < ((2 * i) - 1); ++k) {
                    std::cout << "*";
                }
            } else {
                for (int j = 0; j < (i - ((num / 2) + 1)); ++j) {
                    std::cout << " ";
                }
                for (int k = 0; k < (((num  - i + 1) * 2) - 1 ); ++k) {
                    std::cout << "*";
                }
            }
            std::cout << std::endl;
        }


    }


    return 0;
}