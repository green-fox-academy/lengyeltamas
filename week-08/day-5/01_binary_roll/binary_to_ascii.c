#include "binary_to_ascii.h"

char* binary_file_reader (char* input_file_path)
{
    int number;
    char word[10];
    int array_length = file_character_counter(input_file_path);
    char buffer_array[array_length];
    FILE *input_file_pointer = fopen(input_file_path, "r");
    while (!feof(input_file_pointer)){
        fgets(buffer_array, array_length, input_file_pointer);
    }
    fclose(input_file_pointer);
    char *text_array = (char*)malloc(sizeof(int) * array_length);
    input_file_pointer = fopen(input_file_path, "r");
    while(!feof(input_file_pointer)){
        fgets(text_array, array_length, input_file_pointer);
    }
    char* one_word = strtok(buffer_array, " ");
    while(one_word != NULL){
        strcpy(word, one_word);
        number = atoi(word);
        printf("%c", binary_to_decimal(number));
        one_word = strtok(NULL, " \0");
    }
    fclose(input_file_pointer);
    return text_array;
}

int binary_to_decimal(int binary_number)
{
   int decimal_value = 0;
   int base = 1;
   int temp = binary_number;
   while(temp){
       int last_digit = temp % 10;
       temp = temp / 10;
       decimal_value += last_digit * base;
       base = base * 2;
   }
   return decimal_value;
}

int file_character_counter(char* file_path)
{
    FILE *input_file_pointer;
    input_file_pointer = fopen(file_path, "r");
    int counter = 0;
    while(!feof(input_file_pointer)){
        fgetc(input_file_pointer);
        counter++;
    }
    char last_character = input_file_pointer->_ptr[strlen(input_file_pointer->_ptr) - 1];
    char second_last_character = input_file_pointer->_ptr[strlen(input_file_pointer->_ptr) - 2];
    if (last_character != '\n' && second_last_character != ' '){
        counter++;
    }
    fclose(input_file_pointer);
    return counter;
}