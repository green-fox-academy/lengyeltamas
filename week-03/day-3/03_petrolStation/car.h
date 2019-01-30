//
// Created by Tomi on 2019. 01. 30..
//

#ifndef INC_03_PETROLSTATION_CAR_H
#define INC_03_PETROLSTATION_CAR_H

class Car {
public:
    Car(int gasAmount, int capacity);
    void fill();

    bool isFull();

    int get_gasAmount() const;

    void set_gasAmount(int _gasAmount);

    int get_capacity() const;

    void set_capacity(int _capacity);

private:
    int _capacity;
    int _gasAmount;
};

#endif //INC_03_PETROLSTATION_CAR_H