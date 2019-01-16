#include <iostream>

int main(int argc, char* args[]) {

    int km;
    double mile;

    std::cout << "Tell me how many Km do you wish to convert?" << std::endl;
    std::cin >> km;
    mile = km * 0.621371192;
    std::cout << "This is equal to " << mile << " miles!" << std::endl;

    return 9;
}