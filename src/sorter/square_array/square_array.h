#ifndef ONEGIN_SQUARE_ARRAY_H
#define ONEGIN_SQUARE_ARRAY_H

#include "common.h"

typedef struct square_array {
    char (*text) [MAX_LINE_LENGTH];
    int lines_count = LINES_COUNT;
    int line_length = MAX_LINE_LENGTH;
} square_array_t;

void swap_square(void* array, int i1, int i2);

char* get_line_square_array(int index, void* square_array);

void sort_square_array(square_array_t* square_array, int (*my_strcmp) (const char*, const char*));

void swap_lines(char* str1, char* str2);

void print_square_array(square_array_t* array);

#endif //ONEGIN_SQUARE_ARRAY_H