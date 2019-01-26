#include <iostream>
#include <vector>
#include <algorithm>

std::string containsSeven(const std::vector<int>& numbers) {
    std::vector<int>::iterator findResult;
    std::string result;
    int key = 7;

    if(std::find(numbers.begin(), numbers.end(), key) == numbers.end()) {
        result = "Noooooo";
    } else {
        result = "Hoorray";
    }
    return result;
}

int main(int argc, char* args[])
{
    const std::vector<int> numbers = {1, 2, 3, 4, 5};
    const std::vector<int> numbers2 = {6, 7, 8, 9, 10};

    // Write a method that checks if the vector contains "7" if it contains return "Hoorray" otherwise return "Noooooo"

    // Expected output: "Noooooo"
    std::cout << containsSeven(numbers) << std::endl;

    // Expected output: "Hoorray"
    std::cout << containsSeven(numbers2) << std::endl;

    return 0;
}