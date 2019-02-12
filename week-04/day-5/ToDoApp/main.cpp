#include <iostream>
#include <fstream>
#include <vector>

void oneArgument ()
{
    std::cout << "Command Line Todo application\n"
                 "=============================\n"
                 "\n"
                 "Command line arguments:\n"
                 " -l   Lists all the tasks\n"
                 " -a   Adds a new task\n"
                 " -r   Removes a task\n"
                 " -c   Completes a task"
              << std::endl;
};

void secondArgumentIsLWithTask ()
{
    std::ifstream todofile;
    todofile.open("todo2.txt"); // modify filename to "todo2.txt" here, to test the third task!
    std::string line;
    std::vector<std::string> filecontent;
    while (getline(todofile, line)) {
        filecontent.push_back(line);
    }
    if (todofile.is_open()) {
        if (filecontent.size() < 1) {
            std::cout << "No todos for today! :)" << std::endl;
        } else {
            for (unsigned int i = 0; i < filecontent.size(); ++i) {
                std::cout << i + 1 << " - " << filecontent[i] << std::endl;
            }
        }
    } else {
        std::cout << "File is not open." << std::endl;
    }
};

void secondArgumentIsA(){
    std::ofstream todofile;
    todofile.open("todo.txt");
    todofile << "\nFeed the monkey";
    todofile.close();

};

int main(int argc, char *argv[])
{
    if (argc == 1) {
        oneArgument();
    }

    if (argc == 2) {
        std::string firstArgument (argv[1]);
        if (firstArgument == "-l")
            secondArgumentIsLWithTask();
    }

    if (argc == 3) {
        std::string firstArgument (argv[1]);
        std::string secondArgument (argv[2]);
        if (firstArgument == "-a") {
            secondArgumentIsA(secondArgument);
        } else if (firstArgument == "-r") {

        } else if (firstArgument == "-c") {

        } else {
            std::cout << "Wrong argument!" << std::endl;
        }
    }

    return 0;
}