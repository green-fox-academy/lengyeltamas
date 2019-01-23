#include <iostream>
#include <fstream>
#include <string>

int linecounter (std::string file) {
    std::ifstream myfile (file);
    std::string line;

        if (myfile.is_open()) {
         int numberoflines =0;
         while (getline(myfile, line)) {
             numberoflines +=1;
         } return numberoflines;
         } else {
            return 0;
        }
     }


int main () {
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file


    std::cout << linecounter("my-file.txt");

    return 0;
}