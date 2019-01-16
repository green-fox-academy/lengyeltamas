#include <iostream>
#include <string>

int main(int argc, char* args []) {

    int numberOfWindows;
    std::cout << "Please enter how many windows do you see (integer): ";
    std::cin >> numberOfWindows;

    std::string colorOfCurtain;
    std::cout << "Please enter the color of the curtain (string): ";
    std::cin >> colorOfCurtain;

    std::cout << "You can see " << numberOfWindows << " windows from your place with beautiful " << colorOfCurtain << " curtain." << std::endl;

    return 0;
}