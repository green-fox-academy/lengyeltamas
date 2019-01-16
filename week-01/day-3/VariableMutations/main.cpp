#include <iostream>
#include <string>

int main(int argc, char* args[]) {


    int a = 3;

    a = 3 * a;

    std::cout << a << std::endl;



    int b = 100;

    b = b - 7;

    std::cout << b << std::endl;



    int c =44;

    c = c * 2;

    std::cout << c << std::endl;



    int d = 125;

    d = d / 5;

    std::cout << d << std::endl;



    int e = 8;

    e = e * e;

    std::cout << e << std::endl;



    int f1 = 123;
    int f2 = 345;

    if ( f1 > f2 ) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }


    int g1 = 350;
    int g2 = 200;

    g2 = g2 * 2;

    if ( g2 > g1 ) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }



    int h = 135798745;

    if ( h % 11 > 0 ) {
        std::cout << "false" << std::endl;
    } else {
        std::cout << "true" << std::endl;
    }


    int i1 = 10;
    int i2 = 3;

    if ( (i2 * i2 * i2) > i1 > (i2 * i2) ) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }



    int j = 1521;

    if ( (j % 3) > 0 < (j % 5)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }


    std::string k = "Apple";

   k = k += k += k;

   std::cout << k << std::endl;




    return 0;
}