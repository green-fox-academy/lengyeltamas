#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them
int cmpfunc(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);
}

int main()
{
    int* even_pointer = NULL;
    int length_of_even_pointer = 10;
    even_pointer = (int*)malloc(length_of_even_pointer * sizeof(int));
    for (int i = 0; i < length_of_even_pointer; ++i) {
        even_pointer[i] = (i + 1) * 2;
    }

    int* odd_pointer = NULL;
    int length_of_odd_pointer = 10;
    odd_pointer = (int*)malloc(length_of_odd_pointer * sizeof(int));
    for (int j = 0; j < length_of_odd_pointer; ++j) {
        odd_pointer[j] = ((j + 1) * 2) - 1;
    }

    int * result_pointer = NULL;
    int length_of_result_pointer = (length_of_odd_pointer + length_of_even_pointer);
    result_pointer = (int*)malloc(length_of_result_pointer * sizeof(int));

    for (int k = 0; k < length_of_result_pointer; ++k) {
        if(k < 10){
            result_pointer[k] = even_pointer[k];
        } else {
            result_pointer[k] = odd_pointer[k-10];
        }
    }

    qsort(result_pointer, 20 , sizeof(int), cmpfunc);
    int temp = 0;
    int end = 19;
    for (int l = 0; l < length_of_result_pointer / 2; ++l) {
         temp = result_pointer[l];
         result_pointer[l] = result_pointer[end];
         result_pointer[end] = temp;
         end--;
    }

    for (int n = 0; n < length_of_result_pointer; ++n) {
        printf("%d\t", result_pointer[n]);
    }

    return 0;
}