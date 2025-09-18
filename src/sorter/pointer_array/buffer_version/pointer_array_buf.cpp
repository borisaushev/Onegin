#include "pointer_array_buf.h"

#include <stdio.h>

#include "common.h"


void my_printf(const ptr_wrap_t ptr_wrap) {
    printf("%.*s\n", ptr_wrap.len, ptr_wrap.ptr);
}

void print_ptr_array_buf(pointer_array_buf* ptr_array) {
    dprintf("PRINTING POINTER ARRAY BUFFER\n");
    for (int i = 0; i < ptr_array->lines_count; i++) {
        my_printf(ptr_array->pointer_arr[i]);
    }
    //TODO: puts()
}
/*
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
*/
