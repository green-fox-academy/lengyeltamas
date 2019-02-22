#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // square like this:
    //
    //
    // %%%%%
    // %%  %
    // % % %
    // %  %%
    // %%%%%
    //
    // The square should have as many lines as the number was

    std::cout << "Give me a number: " << std::endl;
    int num;
    std::cin >> num;

    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            if(i == 0 || j == 0 || i == (num - 1) || j == (num - 1) || i == j){
                std::cout << "%";
            } else {
                std::cout << " ";
            }
        }
        std::cout<<std::endl;
    }

    return 0;
}