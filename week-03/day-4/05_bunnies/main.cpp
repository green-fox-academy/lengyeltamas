#include <iostream>

// We have a number of bunnies and each bunny has two big floppy ears.
// We want to compute the total number of ears across all the bunnies recursively (without loops or multiplication).

int bunnymultiplicator (int earsnum, int bunnynum) {
     if (earsnum > 0) {
         return (bunnynum + bunnymultiplicator(earsnum-1, bunnynum));
     } else {
         return 0;
     }

}


int main() {
    int ears = 2;
    int bunny;
    std::cout << "Give me the number of bunnies you got: " << std::endl;
    std::cin >> bunny;

    std::cout << "Then your bunnies have " << bunnymultiplicator(ears, bunny) << " piece of ears! Congratulations!" << std::endl;


    return 0;
}