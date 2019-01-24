#include <iostream>
#include <fstream>
#include <string>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

int copycat (std::string file) {

    std::fstream copy ("my-file-copy.txt");

    std::fstream tomifile (file);

    std::string line;

    int numberoflines =0;

    if (tomifile.is_open()) {
        while (getline(tomifile, line)) {
            numberoflines +=1;
        } return numberoflines;
    } else {
        return 0;
    }

    for ( )



}

int main() {

    std::ifstream tomifile ("my-file.txt");

    copycat(tomifile);

    return 0;
}