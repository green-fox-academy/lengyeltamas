#include <iostream>

int main(int argc, char* args[]) {
    int a = 123;
    int b = 526;
    int c;

    c=b;
    b=a;


   std::cout << c << std::endl;
   std::cout << b << std::endl;


    return 0;
}