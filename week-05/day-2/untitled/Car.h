#ifndef UNTITLED_CAR_H
#define UNTITLED_CAR_H


class Car
{
public:
    Car();
    Car(int gasAmount, int capacity);
    bool isFull();
    void fill();

protected:
    int _gasAmount;
    int _capacity;
};

#endif //UNTITLED_CAR_H