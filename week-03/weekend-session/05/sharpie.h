#ifndef INC_04_SHARPIE_H
#define INC_04_SHARPIE_H
#include <iostream>

class sharpie {
public:
    sharpie ();
    void use();

private:
    std::string _color;
    float _width;
    float _inkAmount = 100;
public:
    const std::string &get_color() const;

    void set_color(const std::string &_color);

    void set_width(float _width);

    float get_inkAmount() const;

};

#endif //INC_04_SHARPIE_H