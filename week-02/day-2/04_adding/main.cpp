#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int b = 17;

    int *apointer = &a;
    int *bpointer = &b;

    int sum = *apointer + *bpointer;

    std::cout << "The sum of variable 'a' 'b' is: " << sum << std::endl;

    return 0;
}