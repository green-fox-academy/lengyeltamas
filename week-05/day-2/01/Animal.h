#ifndef INC_01_ANIMAL_H
#define INC_01_ANIMAL_H


class Animal
{
public:
    Animal();
    void eat();
    void drink();
    void play();
    int get_hunger() const;
    int get_thirst() const;
private:
    int _hunger;
    int _thirst;
};

#endif //INC_01_ANIMAL_H