#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free


int main()
{
    int* pointer = NULL;
    const int size_of_array = 10;
    pointer = (int*)malloc(size_of_array * sizeof(int));

    for (int i = 0; i < size_of_array; ++i) {
        pointer[i] = (i+1)*2;
    }
    for (int j = 0; j < size_of_array; ++j) {
        printf("The nr. %d. element is: %d\n", j+1, pointer[j]);
    }

    realloc(pointer, 0);

    return 0;
}