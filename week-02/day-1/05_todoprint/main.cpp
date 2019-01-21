#include <iostream>
#include <string>

int main(int argc, char* args[])
{
    std::string todoText = "\n - Buy milk";
    todoText.insert(0, "My todo:");
    std::string download = "\n - Download games";
    todoText.append (download);
    std::string diablo = "\n     - Diablo";
    todoText.append (diablo);


    // Add "My todo:" to the beginning of the todoText
    // Add " - Download games" to the end of the todoText
    // Add " - Diablo" to the end of the todoText but with indentation

    // Expected outpt:

    // My todo:
    //  - Buy milk
    //  - Download games
    //      - Diablo

    std::cout << todoText << std::endl;

    return 0;
}