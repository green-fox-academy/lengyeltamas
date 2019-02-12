#include <iostream>
#include <string>

void vowelPrint (std::string TEXT, std::string VOWELS, std::string TEMP)
{
    for (int i = 0; i < TEXT.size(); ++i) {
        for (int j = 0; j < VOWELS.size(); ++j) {
            if (TEXT[i] == VOWELS[j]) {
                TEMP += TEXT[i];
            }
        }
    }
    std::cout << TEMP << std::endl;
};

int main()
{
std::string text = "YOLO, swag";
std::string vowels = "aeiouAEIOU";
std::string temp = "";

vowelPrint(text, vowels, temp);
    return 0;
}