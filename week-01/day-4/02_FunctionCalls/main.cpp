#include <iostream>
#include <string>

void sayGreen();
void sayFox();

int main(int argc, char* args[]) {
    sayGreen();
    std::cout << "Hello from main()" << std::endl;
    return 0;
}

void sayGreen() {
    std::cout << "Green";
    sayFox();
    std::cout << "Hello from sayGreen()" << std::endl;
}

void sayFox() {
    std::cout << "Fox" << std::endl;
    std::cout << "Hello from sayFox()" << std::endl;
}