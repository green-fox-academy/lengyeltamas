#ifndef INC_03_ANIMALS_H
#define INC_03_ANIMALS_H


class animals {
public:
    animals();

    void eat();

    void drink();

    void play();

    int getHunger() const;

    int getThirst() const;

private:
    int _hunger = 50;
    int _thirst = 50;
};


#endif //INC_03_ANIMALS_H
