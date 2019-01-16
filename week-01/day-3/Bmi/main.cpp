#include <iostream>

int main(int argc, char* args[]) {

    double massInKg = 81.2;
    double heightInM = 1.78;

    std::cout << "Body Mass Index (BMI) is " << massInKg / (heightInM * heightInM) << std::endl;


    return 0;
}