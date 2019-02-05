#include "sharpie.h"

sharpie::sharpie()
{}

void sharpie::use(){
    _inkAmount -= _width;
}

const std::string &sharpie::get_color() const {
    return _color;
}

void sharpie::set_color(const std::string &_color) {
    sharpie::_color = _color;
}

void sharpie::set_width(float _width) {
    sharpie::_width = _width;
}

float sharpie::get_inkAmount() const {
    return _inkAmount;
}