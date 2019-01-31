#include <iostream>

// We have bunnies standing in a line, numbered 1, 2, ... The odd bunnies
// (1, 3, ..) have the normal 2 ears. The even bunnies (2, 4, ..) we'll say
// have 3 ears, because they each have a raised foot. Recursively return the
// number of "ears" in the bunny line 1, 2, ... n (without loops or multiplication).

int bunnyEarCounterMaschine (int bunnies, int evenEars, int oddEars) {
    int ears;
    if (bunnies % 2 == 0) {
        ears = evenEars;
    } else {
        ears = oddEars;
    }
    return ears + bunnyEarCounterMaschine((bunnies - 1), evenEars, oddEars);

}

/// NOT READY YET!!//


int main() {

    int bunniesNumber;
    int evenBunnyEars = 3;
    int oddBunnyEars = 2;
    std::cout << "Give me the number of bunnies standing in the lane: " << std::endl;
    std::cin >> bunniesNumber;
    std::cout << "Your lane of bunnies has " << bunnyEarCounterMaschine(bunniesNumber, evenBunnyEars, oddBunnyEars) << " ears! Splendid!" << std::endl;

    return 0;
}