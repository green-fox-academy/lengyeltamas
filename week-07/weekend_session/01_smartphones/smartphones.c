#include "smartphones.h"

int get_number_of_smartphones(char* input_path)
{
    FILE *input_file_pointer;
    input_file_pointer = fopen(input_path, "r");
    int counter = 1;
    while (!feof(input_file_pointer)) {
        char c = fgetc(input_file_pointer);
        if(c == '\n') {
            counter++;
        }
    }
    fclose(input_file_pointer);
    return counter;
}

smartphone_t* get_datas_of_smartphones(char* input_path, int number_of_smartphones, smartphone_t* smartphone)
{
    FILE *input_file_pointer;
    input_file_pointer = fopen(input_path, "r");
    char buffer[50];

    for (unsigned int i = 0; i < number_of_smartphones; i++){
        char* name;
        char* release_year;
        char* screen_size;

        strcpy(smartphone[i].name, name);
        smartphone[i].release_year = atoi(release_year);


    }
}