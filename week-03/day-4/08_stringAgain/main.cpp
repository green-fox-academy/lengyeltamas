#include <iostream>

// Given a string, compute recursively a new string where all the 'x' chars have been removed.

std::string stringXRemover (std::string ToChange, int size) {
    if (size == 0) {
        return ToChange;
    } else if (ToChange[size - 1] == 'x') {
        ToChange.erase(size - 1, 1);
        return stringXRemover(ToChange, (size - 1));
    } else {
        return stringXRemover(ToChange, (size - 1));
    }
}


int main() {

    std::string stringToChange = "xIxlxlxuxmx xSxpxhxexrxex x-x xTxhxex xJxoxuxrxnxexyx";
    int stringsize = stringToChange.size();

    std::cout << stringXRemover (stringToChange, stringsize) << std::endl;



    return 0;
}