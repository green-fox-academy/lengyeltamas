#include <stdio.h>
#include <string.h>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

void fileWriter(char * file_name, char * test_word, int test_num);

int main()
{
    char word[7] = "apple";
    int number_of_lines = 15;
    fileWriter("../my-file.txt", word, number_of_lines);
    return 0;
}

void fileWriter(char * file_name, char * test_word, int test_num)
{
    char * pause = "\n";
    strcat(test_word, pause);
    FILE *my_file = fopen(file_name, "w");
    if (file_name == NULL) {
        printf("Cannot open file!");
    }
    for (int i = 0; i < test_num; ++i) {
        fputs(test_word, my_file);
    }
}