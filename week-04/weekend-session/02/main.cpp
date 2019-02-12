#include <vector>
#include <iostream>


int main()
{
    // Create a function named `rotateMatrix` that takes an n×n integer matrix (vector of vectors) as parameter
    // and returns a matrix which elements are rotated 90 degrees clockwise.
    // example input:
    // [[1, 2, 3],
    // [4, 5, 6],
    // [7, 8, 9]]

    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    std::vector<std::vector<int>> tempmatrix;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            tempmatrix[i][j] = matrix[i][j];
        }
    }

    int temp = 0;

    for (int k = 0; k < tempmatrix.size(); ++k) {
        for (int l = 0; l < tempmatrix.size(); ++l) {
            temp = tempmatrix[k][l];
            tempmatrix[k][l] = tempmatrix[tempmatrix.size() - l - 1][k];
        }
    }

    for (int m = 0; m < tempmatrix.size(); ++m) {
        for (int i = 0; i < tempmatrix.size(); ++i) {
            std::cout << tempmatrix[m][i] << " " << std::endl;
        }
    }

    // should print
    // 7 4 1
    // 8 5 2
    // 9 6 3

    return 0;
}