#include <iostream>

int lookforvalue (int array[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (array[i] == num) {
            return i;
        }
    }
    return 0;
}

int main()
{
    // Create a function which takes an array (and it's length) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return 0


    //there was a typo up there ^ (lenght)

    int num;
    std::cout << " Give me a number! " << std::endl;
    std::cin >> num;

    int array[5] = {10, 11, 12, 13, 14};
    int size = (sizeof(array)/sizeof(array[0]));
    lookforvalue(array, size, num);

    std::cout << lookforvalue(array, size, num) << std::endl;
    return 0;
}