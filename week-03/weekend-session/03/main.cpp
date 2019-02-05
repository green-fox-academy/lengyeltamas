#include <iostream>
#include "animals.h"

int main() {

    animals elephant;
    animals sloth;
    animals doggo;


    elephant.eat();
    sloth.drink();
    doggo.play();

    std::cout << "Elephant's hunger is: " << elephant.getHunger() << " Sloth's thirst is: " << sloth.getThirst() << " Doggo's thirst is: " << doggo.getThirst() << " Doggo's hunger is: " << doggo.getHunger() << std::endl;
    
    return 0;
}