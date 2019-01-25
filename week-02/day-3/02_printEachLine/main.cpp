#include <iostream>
#include <fstream>
#include <string>


int main () {
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming, although it is not mandatory

    std::ofstream tomifile ("my-file.txt");

    tomifile << "How does it feel \nTo treat me like you do \nWhen you ve laid your hands upon me \nAnd told me who you are \nThought I was mistaken \nI thought I heard your words \nTell me, how do I feel \nTell me now how do I feel";
    tomifile.close();

    std::ifstream tomifile2 ("my-file.txt");
    std::string line;

    if (tomifile2.is_open()) {
        while (getline (tomifile2, line)) {
            std::cout << line;
        } tomifile2.close();
    }
    return 0;
}
