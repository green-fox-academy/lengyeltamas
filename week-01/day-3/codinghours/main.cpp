#include <iostream>

int main(int argc, char* args[]) {
    std::cout << "Hours spent by coding in a semester by an attendee: " << 6 * 17 * 5 << std::endl;

    std::cout << "Hours spent by coding in a semester by an attendee with average 52 workhours: " << (6 * 17 * 5) / (17 * 52.) * 100 << " %" << std::endl;

    return 9;
}