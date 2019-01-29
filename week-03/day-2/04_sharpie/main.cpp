#include <iostream>
#include <string>


class Sharpie {
public:
    Sharpie (std::string c, float w) {
        inkAmount = 100;
        color = c;
        width = w;
    }

    void use () {
        inkAmount -= (1*width);
    }

std::string tostring() {
    std::string data = {"Sharpie's color is: " + color + " it's width is: " + std::to_string (width) + " and when it's used, it's Ink level decreases to: " + std::to_string (inkAmount)};
    return data;
    }


private:
    std::string color;
    float width;
    float inkAmount;
};

int main(int argc, char* args[]) {

    Sharpie pen1 ("orange", 5.4);
    Sharpie pen2 ("yellow", 2.5);
    Sharpie pen3 ("green", 7.2);

    pen1.use();
    std::cout << pen1.tostring() << std::endl;
    pen2.use();
    std::cout << pen2.tostring() << std::endl;
    pen3.use();
    std::cout << pen3.tostring() << std::endl;
}