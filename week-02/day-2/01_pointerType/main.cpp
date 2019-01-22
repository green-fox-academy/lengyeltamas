#include <iostream>

int main ()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int *apointer = &a;
    double *bpointer = &b;
    std::string *namepointer = &name;

    std::cout << "The memory address of variable " << a << " is: " << apointer << std::endl;
    std::cout << "The memory address of variable " << b << " is: " << bpointer << std::endl;
    std::cout << "The memory address of variable " << name << " is: " << namepointer << std::endl;

    std::cout << "The value of pointer 'apointer' is: " << *apointer << std::endl;
    std::cout << "The value of pointer 'bpointer' is: " << *bpointer << std::endl;
    std::cout << "The value of pointer 'namepointer' is: " << *namepointer << std::endl;

    return 0;
}