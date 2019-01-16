#include <iostream>

int main(int argc, char* args[]) {

    int currentHours = 17;
    int currentMinutes = 12;
    int currentSeconds = 10;

    int remainingSeconds = (60-currentSeconds)+((60-currentMinutes-1)*60)+((24-currentHours-1)*60*60);

    std::cout << "Number of remaining seconds from this day: " << remainingSeconds << std::endl;


    return 0;
}