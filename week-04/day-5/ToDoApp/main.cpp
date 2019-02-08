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

void twoArgument ()
{
    std::ifstream todofile;
    todofile.open("todo.txt");
    std::string line;
    std::vector<std::string> filecontent;
    while (getline(todofile, line)) {
        filecontent.push_back(line);
    }
    if (todofile.is_open()) {
        for (unsigned int i = 0; i < filecontent.size(); ++i) {
            std::cout << i+1 << " - " << filecontent[i] << std::endl;
        }
    } else {
        std::cout << "File is not open." << std::endl;
    }

}


int main(int argc, char *argv[])
{
    if (argc == 1) {
        oneArgument();
    }

    if (argc == 2) {
        std::string firstArgument (argv[1]);
        if (firstArgument == "-l")
        twoArgument();
    }


    return 0;
}