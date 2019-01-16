#include <iostream>

int main(int argc, char* args[]) {

    int numberOfChickens;
    int numberOfPigs;
    int chickenLegs;
    int pigLegs;


    std::cout << "How many chickens do you have?" << std::endl;
    std::cin >> numberOfChickens;
    std::cout << "How many pigs do you have?" << std::endl;
    std::cin >> numberOfPigs;

    chickenLegs = numberOfChickens * 2;
    pigLegs = numberOfPigs * 4;

    std::cout << "You have " << ( chickenLegs + pigLegs ) << " leg in your farm, congrats, mate!";


    return 0;
}