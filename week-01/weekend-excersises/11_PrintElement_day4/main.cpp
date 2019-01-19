#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `numbers`
    //   with the following content: `[4, 5, 6, 7]`
    // - Print all the elements of `numbers`

    int numbers [4] = {4, 5, 6, 7};

    std::cout << "The elements of the 'numbers' array are: " << numbers[0] << ", "<< numbers[1] << ", " << numbers[2] << ", " << numbers[3] << std::endl;

    return 0;
}