#include <iostream>
#include <string>


class Animal {
public:
    Animal () {
        hunger = 50;
        thirst = 50;
    }

    void eat() {
        hunger -=1;
    };

    void drink() {
        thirst -=1;
    };

    void play() {
        hunger+=1;
        thirst+=1;
      };

    int getHunger () {
        return hunger;
    }

    int getDrink () {
        return thirst;
    }


private:
    int hunger;
    int thirst;
};

int main(int argc, char* args[]) {

    Animal lion;
    Animal elephant;
    Animal crocodile;


    lion.eat();
    elephant.drink();
    crocodile.play();

    std::cout << "Lion's hunger is: " << lion.getHunger() << "\n" << "Elephant's thirst is: " << elephant.getDrink() << "\n" << "Crocodile's hunger is: " << crocodile.getHunger() << " Crocodile's thirst is: " << crocodile.getDrink()<< std::endl;

}
