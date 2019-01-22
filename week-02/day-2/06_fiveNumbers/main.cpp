#include <iostream>

int main()
{
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again

    int num[5];
    std::cout << "Give me five numbers! " << std::endl;
    for (int i = 0; i < sizeof(num)/sizeof(num[0]); i++) {
        std::cin >> num[i];
    }

    std::cout << " The numbers and the values of the array 'num' are: ";
    for (int i = 0; i < sizeof(num)/sizeof(num[0]); i++) {
        std::cout << i+1 << ". = " << *(num + i) << ", ";
    }

    return 0;
}