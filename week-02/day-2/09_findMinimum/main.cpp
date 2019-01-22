#include <iostream>

int value (int *numbers, int length) {
    int *pointer = nullptr;
    int smallest = numbers[0];
    for (int i = 0; i < length; i++) {
        if (smallest > numbers[i]) {
            smallest = numbers[i];
        }
    }
    pointer = &smallest;
    return *pointer;
}

int main()
{
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};

    int length = sizeof(numbers)/sizeof(numbers[0]);

    value(numbers, length);
    std::cout << "The minimum value of this array is: " << value(numbers, length) << std::endl;

    return 0;
}