#include <cassert>
#include <cstdio>
#include <stdio.h>

#include "square_array.h"
#include "sorter.h"


void swap_square(void* array, int i1, int i2) {
    assert(array);
    assert(i1 >= 0);
    assert(i2 >= 0);

    square_array_t* square_array = (square_array_t*) array;
    swap_lines(square_array->text[i1], square_array->text[i2]);
}

char* get_line_square_array(int index, void* square_array) {
    return ((square_array_t*) square_array)->text[index];
}

void sort_square_array(square_array_t* square_array, int (*my_strcmp) (const char*, const char*)) {
    sort_array(square_array, get_line_square_array, square_array->lines_count, my_strcmp, swap_square);
}

void swap_lines(char* str1, char* str2) {
    assert(str1);
    assert(str2);

    const int l1 = my_strlen(str1);
    const int l2 = my_strlen(str2);
    for (int i = 0; i < (l1 > l2 ? l1 : l2) + 1; i++) {
        char buf = str2[i];
        str2[i] = str1[i];
        str1[i] = buf;
    }
}


void print_square_array(square_array_t* array, FILE* out_stream) {
    assert(array);
    assert(array->text);

    // dprintf("printing array with size: %d\n", array->lines_count);

    for (int i = 0; i < array->lines_count; i++) {
        // dprintf("line %d\n", i);
        fprintf(out_stream, "%s", array->text[i]);
    }

    // dprintf("print finished\n");
}