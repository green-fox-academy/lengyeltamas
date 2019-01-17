#include <iostream>
#include <string>

void doubling (int& a) {
    a*=2;
};

int main(int argc, char* args[]) {

    // - Create an integer variable named `baseNum` and assign the value `123` to it
    // - Create a function called `doubling` that doubles it's input parameter and returns with an integer
    // - Print the result of `doubling(baseNum)`

    int baseNum = 123;
    doubling(baseNum);
    std::cout << baseNum << std::endl;






    return 0;
}