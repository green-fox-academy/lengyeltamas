#include <iostream>

int main()
{

    std::cout << "Give me a number:" <<std::endl;
    int num;
    std::cin >> num;

    for (int i = 1; i <= num; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "*";}
        std::cout << std::endl;
    }

    return 0;
}