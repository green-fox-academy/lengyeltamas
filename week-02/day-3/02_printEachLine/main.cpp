#include <iostream>
#include <fstream>
#include <string>


int main () {
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming, although it is not mandatory

    std::ofstream tomifile ("my-file.txt");

    tomifile << "At \nthis \ntext \nfile \neach \nword \nis \nin \na \nnew \nline.";
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