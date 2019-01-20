#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`

    int aj [5] {3, 4, 5, 6, 7};
    int n = sizeof aj / sizeof aj[0];
    int temp[n];

    for (int i = 0; i <= n; i++) {
        temp [i] = aj[n-i];
    }
    for (int i = 0; i <= n; i++) {
        aj[i] = temp[i];
    }

    for (int i = 0; i <= n; i++) {
        std::cout << aj[i] << " ";
    }

    return 0;
}