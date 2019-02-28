#include <stdio.h>
#include <stdlib.h>

//Read the size of a matrix(don't have to be squared matrix) from the console.
//Allocate memory dynamically for the elements of the matrix, then read the elements.
//Create a function which can calculate the n-th percentile of the elements.
//Calculate the 80-th and the 90-th percentile.

int calculate_percentile(int input_percentile, int* input_matrix, int input_first_dimension, int inout_second_dimension);

int main()
{
    printf("Give me the first dimension of your matrix:\n");
    int first_dimension;
    scanf("%d", &first_dimension);
    printf("Give me the second dimension of your matrix:\n");
    int second_dimension;
    scanf("%d", &second_dimension);

    int ** matrix = (int **)malloc(first_dimension * sizeof(int));

    for (int i = 0; i < first_dimension; ++i) {
        matrix[i] = (int*)malloc((i * second_dimension) * sizeof(int));
    }

    for (int i = 0; i < first_dimension; ++i) {
        for (int j = 0; j < second_dimension; ++j) {
            printf("Give me the [%d][%d] element of your matrix!\n", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    int percentile = 80;
    calculate_percentile(percentile, *matrix, first_dimension, second_dimension);
    return 0;
}

int calculate_percentile(int input_percentile, int* input_matrix, int input_first_dimension, int input_second_dimension)
{
    int result;

    int temparray[input_first_dimension * input_second_dimension];

    for (int i = 0; i < input_first_dimension; ++i) {
        for (int j = 0; j < input_second_dimension; ++j) {

            temparray[i * j] = input_matrix[i][j];

        }
    }

    return result;
}