#include <iostream>

int main(int argc, char* args[]) {

    // Crate a program that draws a chess table like this
    //
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %

    std::cout << "Give me the dimension of your chess table: " << std::endl;
    int dimension;
    std::cin >> dimension;

    for (int i = 1; i <= dimension; ++i) {
        for (int j = 1; j <= dimension; ++j) {
            if ((i % 2 == 0) && (j % 2 == 0) || (i % 2 != 0) && (j % 2 != 0)) {
                std::cout << "%";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}