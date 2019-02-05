#include <iostream>
#include "sharpie.h"
#include "Sharpieset.h"

int main() {

    sharpie pen1;
    pen1.set_color("yellow");
    pen1.set_width(5.5);

    sharpie pen2;
    pen2.set_color("green");
    pen2.set_width(6.5);

    sharpie pen3;
    pen3.set_color("pink");
    pen3.set_width(7.5);

    for (int i = 0; i < 10; ++i) {
        pen1.use();
        pen2.use();
        pen3.use();
    }

    std::cout << pen1.get_color() << std::endl;
    std::cout << pen1.get_inkAmount() << std::endl;
    std::cout << pen2.get_color() << std::endl;
    std::cout << pen2.get_inkAmount() << std::endl;
    std::cout << pen3.get_color() << std::endl;
    std::cout << pen3.get_inkAmount() << std::endl;
    return 0;
}