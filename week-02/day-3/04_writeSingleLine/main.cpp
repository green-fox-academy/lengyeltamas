#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open a file called "my-file.txt"
    // Write your name in it as a single line

    std::ofstream tomifile ("my-file.txt");

    tomifile << "My name is Tamas Lengyel!";
    tomifile.close();

    return 0;
}