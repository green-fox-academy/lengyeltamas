#include <iostream>
#include <vector>

int main()
{

    /*std::vector<std::vector<int>> testmatrix1 = {{2, 1},
                                                 {0, 1}};

    std::vector<std::vector<int>> testmatrix2 = {{0, 3},
                                                 {-1, 1}};
*/
    std::vector<std::vector<int>> testmatrix1 = {{-1, 1, 0},
                                                 {0, 1, 0},
                                                 {0, 1, 0}};

    std::vector<std::vector<int>> testmatrix2 = {{0, 0, 0},
                                                 {0, 1, 0},
                                                 {0, 0, 0}};


    for (int k = 0; k < testmatrix1.size(); ++k) {
        for (int l = 0; l < testmatrix1.size(); ++l) {
            if (testmatrix1[k][l] >= testmatrix2[k][l]) {   //modify "testmatrix2" here to set the second matrix to compare +
                testmatrix1[k][l] = testmatrix1[k][l];
            } else {
                testmatrix1[k][l] = testmatrix2[k][l];      //modify "testmatrix2" here to set the second matrix to compare
            }
        }
    }

   for (int m = 0; m < testmatrix1.size(); ++m) {
        for (int n = 0; n < testmatrix1.size(); ++n) {
            std::cout << testmatrix1[m][n] << " ";
        }   std::cout << "\n";
    }

    return 0;
}