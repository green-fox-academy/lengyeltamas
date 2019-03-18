#include "binary_roll.h"

char* file_to_result_string (char* file_name)
{
    FILE *file_pointer;
    file_pointer = fopen(file_name, "r");
    char file_content[3000];
    if (file_pointer == NULL) {
        return "Can't open file!";
    } else if (file_pointer != NULL) {
        fgets(file_content, 3000, file_pointer);
    }
    fclose(file_pointer);

    int counter = 0;
    char* temp = strtok(file_content, " ");
    char* binary[3000];
    int i = 0;
    while (temp!= NULL){
        binary[i++] = temp;
        temp = strtok(NULL, " ");
        counter++;
    }
    char result[3000];

}

char binary_to_ACII (int binary_number)
{
    char *ptr;
    long ret = strtol(&binary_number, &ptr, 2);
    char result = ret;
    return result;
}