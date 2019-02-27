#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
// please delete the array before the program exits


int main()
{
    int* pointer = NULL;
    pointer = (int*)malloc(10 * (sizeof(int)));

    for (int i = 0; i < 10; ++i) {
        if(i < 5) {
            pointer[i] = i;
        }
        else {
            pointer[i] = i - 5;
        }
    }

    for (int j = 0; j < 10; ++j) {
        printf("The %d. element of the array is: %d\n",j+1 , pointer[j]);
    }

    return 0;
}