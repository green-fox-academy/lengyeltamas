#include <iostream>

// Given a string, compute recursively (no loops) a new string where all the
// lowercase 'x' chars have been changed to 'y' chars.

std::string changer(std::string stringtochange, int stringsize)
{
    if (stringsize - 1 == -1) {
        return stringtochange;
    } else if (stringtochange[stringsize - 1] == 'x') {
        stringtochange[stringsize - 1] = 'y';
        return changer(stringtochange, (stringsize - 1));
    } else {
        return changer(stringtochange, (stringsize - 1));
    }
}



int main() {

    std::string base = "XxXxXxXxXx";
    int sizeofstring = base.size();

    std::cout << changer(base, sizeofstring) << std::endl;
    return 0;
}