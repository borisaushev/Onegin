#ifndef ONEGIN_POINTER_ARRAY_H
#define ONEGIN_POINTER_ARRAY_H

#include <stdio.h>

#include "common.h"

typedef struct pointer_array {
    char** text;
    int lines_count = LINES_COUNT;
    int line_length = MAX_LINE_LENGTH;
} pointer_array_t;

char* get_line_pointer_array(int index, void* pointer_array);

void sort_pointer_array(pointer_array_t* pointer_array, int (*my_strcmp) (const char*, const char*));

void swap_pointers(void* array, int i1, int i2);

void print_pointer_array(pointer_array_t* array, FILE* out_stream);

#endif //ONEGIN_POINTER_ARRAY_H