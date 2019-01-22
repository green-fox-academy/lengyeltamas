#include <iostream>

int main()
{
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the memory addresses of the elements in the array


    int num[5];
    std::cout << " Give me five numbers! " << std::endl;
    for (int i = 0; i < sizeof(num)/ sizeof(num[0]); i++) {
        std::cin >> num[i];
    }

    std::cout << " The memory addresses of the 'num' array's elements are: ";
    for (int i = 0; i < sizeof(num)/ sizeof(num[0]); i++) {
        std::cout << (num + i) << ", ";
    }

    return 0;
}