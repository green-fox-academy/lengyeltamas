#include <iostream>
#include <string>

void swap(int& x, int& y) {
    int z;

    z = x;
    x = y;
    y = z;

}

int main(int argc, char* args[]) {
    // Create two integer variables: a=15, b=23
    // Create a function named swap that gets the 2 integers as parameters and swaps its values.
    // Print the values before and after the function call and make sure the values are printed in reversed order.

    int a;
    int b;

    a = 15;
    b = 23;

    std::cout << "Original a: " << a << " Original b: " << b << std::endl;

    swap(a, b);

    std::cout << "Swapped a: " << a << " Swapped b: " << b << std::endl;



    return 9;
}