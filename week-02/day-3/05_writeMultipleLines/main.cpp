#include <iostream>
#include <fstream>
#include <string>

// Create a function that takes 3 parameters: a path, a word and a number,
// than it should write to a file.
// The path parameter should describes the location of the file.
// The word parameter should be a string, that will be written to the file as lines
// The number parameter should describe how many lines the file should have.
// So if the word is "apple" and the number is 5, than it should write 5 lines
// to the file and each line should be "apple"

int filewriter (std::string p, std::string w, int n) {

    std::ofstream tomifile;

    std::string path = "C:\\Users\\Tomi\\Desktop\\greenfox\\lengyeltamas\\week-02\\day-3\\05_writeMultipleLines\\";
    std::string txt =".txt";
    tomifile.open ( path + p + txt);

    for (int i = 0; i < n; i++) {
        tomifile << w << std::endl;
    }
    tomifile.close();
    return 0;
}

int main() {

    std::string p;
    std::string w;
    int n;


    std::cout << "Tell me the file name: " << std::endl;
    std::cin >> p;
    std::cout << "Tell me a word: " << std::endl;
    std::cin >> w;
    std::cout << "Tell me a number" << std::endl;
    std::cin >> n;

    filewriter(p, w, n);

    return 0;
}