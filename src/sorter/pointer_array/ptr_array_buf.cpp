#include "ptr_array_buf.h"

#include "common.h"


void my_printf(FILE* output, const ptr_wrap_t ptr_wrap) {
    fprintf(output, "%.*s\n", ptr_wrap.len, ptr_wrap.ptr);
}

void print_ptr_array(FILE* output, ptr_array_buf* ptr_array) {
    DPRINTF("PRINTING POINTER ARRAY\n");
    for (int i = 0; i < ptr_array->lines_count; i++) {
        my_printf(output, ptr_array->pointer_arr[i]);
    }
}

void print_buf(FILE* output, ptr_array_buf* ptr_array) {
    DPRINTF("PRINTING BUFFER\n");
    fputs(ptr_array->buf, output);
}