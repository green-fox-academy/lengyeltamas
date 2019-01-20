#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `abc`
    //   with the following content: `["first", "second", "third"]`
    // - Swap the first and the third element of `abc`

    std::string abc[3] = {"first", "second", "third"};
    std::string temp;

    std::cout << std::endl;
    std::cout << "The array before the swapping is: " << abc[0] << ", " << abc[1] <<  ", " << abc[2] << std::endl;

    temp = abc [0];
    abc [0] = abc [2];
    abc [2] = temp;

    std::cout << std::endl;
    std::cout << "The array after the swapping is: " << abc[0] << ", " << abc[1] <<  ", " << abc[2] << std::endl;

    return 0;
}