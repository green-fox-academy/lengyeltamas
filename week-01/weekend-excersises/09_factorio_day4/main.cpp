#include <iostream>
#include <string>

int factorio (int a) {
    int b = 1;
    for (int i = 1; i <= a; i++) {
        b *= i;
    }
    return b;

}

int main(int argc, char* args[]) {

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.

    int num;
    std::cout << "Give me a number to find it's factorial, and you never see it again!" << std::endl;
    std::cin >> num;

    int additional = factorio(num);

    std::cout << "Just kidding, here's your number: " << additional << std::endl;


    return 0;
}