#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::vector<std::string> filter (std::vector<std::string>& list, std::vector<std::string> sweets){
    for (unsigned int i = 0; i < list.size(); i++) {
        if (std::find(sweets.begin(), sweets.end(), list[i]) == sweets.end()) {
            list.erase(list.begin() +i);
            i-=1;
        }
    }
    return list;
    }

int main(int argc, char* args[])
{
    const std::vector<std::string> sweets = {"Cupcake", "Brownie"};
    std::vector<std::string> list = {"Cupcake", "Carrot", "Bread", "Brownie", "Lemon"};

    // Accidentally we added "Carrot", "Lemon" and "Bread" to the list.
    // Your task is to remove them from the list. "sweets" vector can help you with this
    // You should erase every element from "list" vector that is not in "sweets" vector.
    // No, don't just remove the lines
    // Create a method called filter() which takes the two lists as parameters.

    std::vector<std::string> filteredList = filter (list, sweets);

    // Expected output: Cupcake Brownie
    for (int i = 0; i < filteredList.size(); ++i) {
        std::cout << filteredList[i] << " ";
    }

    return 0;
}