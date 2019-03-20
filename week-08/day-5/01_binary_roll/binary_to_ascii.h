#ifndef INC_01_BINARY_ROLL_BINARY_TO_ASCII_H
#define INC_01_BINARY_ROLL_BINARY_TO_ASCII_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "binary_to_ascii.h"

char* binary_file_reader(char* input_file_path);

int binary_to_decimal(int binary_number);

int file_character_counter(char* file_path);

#endif //INC_01_BINARY_ROLL_BINARY_TO_ASCII_H