#include <iostream>
#include <fstream>
#include <map>

void fileContentAnalyzer (std::string inputFileName, std::string outputFileName)
{
    std::fstream inputFile;
    inputFile.open(inputFileName);

    if (!inputFile.is_open())
        throw "Can't open file!";

    std::string name;
    std::string type;
    std::string date;

    std::map<std::string, int> data;
    while (inputFile >> name >> type >> date) {
        data[type]++;
    }
    inputFile.close();


    std::ofstream outputFile;
    outputFile.open(outputFileName);
    outputFile << "Building usage" << std::endl << std::endl;

    for (std::map<std::string, int>::iterator it = data.begin(); it != data.end(); ++it) {
        outputFile << "The usage from type: " << it->first << " is: " << it->second << std::endl;
    }
}

int main()
{
    fileContentAnalyzer("../../usage.txt","../../result.txt");
    return 0;
}