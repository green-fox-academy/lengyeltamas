//
// Created by Tomi on 2019. 01. 30..
//

#include "car.h"

Car::Car(int gasAmount, int capacity){
    _gasAmount = gasAmount;
    _capacity = capacity;
}

void Car::fill() {
    _gasAmount++;
}

bool Car::isFull() {
    return (get_gasAmount() != get_capacity());
};

int Car::get_gasAmount() const {
    return _gasAmount;
}

void Car::set_gasAmount(int _gasAmount) {
    Car::_gasAmount = _gasAmount;
}

int Car::get_capacity() const {
    return _capacity;
}

void Car::set_capacity(int _capacity) {
    Car::_capacity = _capacity;
}