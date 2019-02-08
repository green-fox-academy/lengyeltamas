#include <iostream>

void oneArgument (){

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


int main(int argc, char *argv[])
{
    if (argc == 1) {
        oneArgument();
    }




    return 0;
}