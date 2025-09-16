#include <cassert>
#include <cstdio>
#include <stdio.h>

#include "pointer_array.h"
#include "sorter.h"


char* get_line_pointer_array(int index, void* pointer_array) {
    return ((pointer_array_t*) pointer_array)->text[index];
}

void sort_pointer_array(pointer_array_t* pointer_array, int (*my_strcmp) (const char*, const char*)) {
    sort_array(pointer_array, get_line_pointer_array, pointer_array->lines_count, my_strcmp, swap_pointers);
}

void swap_pointers(void* array, int i1, int i2) {
    assert(array);
    assert(i1 >= 0);
    assert(i2 >= 0);

    pointer_array_t* pointer_array = (pointer_array_t*) array;
    char* buf = pointer_array->text[i1];
    pointer_array->text[i1] = pointer_array->text[i2];
    pointer_array->text[i2] = buf;
}

void print_pointer_array(pointer_array_t* array, FILE* out_stream) {
    assert(array);
    assert(array->text);

    for (int i = 0; i < array->lines_count; i++) {
        fprintf(out_stream, "%s", array->text[i]);
    }
}