#include <iostream>

int main()
{
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it

    int num;
    std::cout << "Give me a number" << std::endl;
    std::cin >> num;

    int array[num];

    for (int i = 0; i < num; i++) {
        std::cout << "Give me numbers for the array" << std::endl;
        std::cin >> array[i];
    }


    int temp = 0;
    for (int i = 0; i < num; i++) {
        if (array[i] > temp) {
            temp = array[i];
        }
    }

    std::cout << std::endl;
    std::cout << "The largest element value in this array is: " << temp <<std::endl;

    return 0;
}