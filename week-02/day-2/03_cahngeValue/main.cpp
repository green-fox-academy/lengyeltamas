#include <iostream>

int main ()
{
    // Change the value of the variable called 'temperature' using a pointer
    // (you have to create the pointer first)

    float temperature = 21.3;

    float *temperaturepointer = &temperature;

    *temperaturepointer = 39.4;

    std::cout << "The value of variable 'temperature' is: " << *temperaturepointer << std::endl;

    return 0;
}