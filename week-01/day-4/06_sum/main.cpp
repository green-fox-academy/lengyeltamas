#include <iostream>
#include <string>

int sum (int a){
    int b = 0;
    for(int i = 0; i <= a; i++) {
        b += i;
    }
return b;}

int main(int argc, char* args[]) {

    // - Write a function called `sum` that sum all the numbers
    //   until the given parameter and returns with an integer

    int n;
    std::cout << "Tell me a number: " << std::endl;
    std::cin >> n;
    std::cout << "SUM is: " << sum(n) << std::endl;

    return 0;
}