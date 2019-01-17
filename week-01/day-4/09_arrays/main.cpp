#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int myNumbers[] = {1, 2, 3, 6};

    // Print the second element of the array
    std::cout << "The second element is: " << myNumbers[1] << std::endl;

    // Print all the elements
    for(int i = 0; i < sizeof(myNumbers)/sizeof(myNumbers[0]); i++) {
        std::cout << myNumbers[i] << std::endl;
    }

    return 0;
}