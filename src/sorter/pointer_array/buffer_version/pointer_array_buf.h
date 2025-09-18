#ifndef ONEGIN_POINTER_ARRAY_BUF_H
#define ONEGIN_POINTER_ARRAY_BUF_H

typedef struct ptr_wrap {
    char* ptr;
    int len;
} ptr_wrap_t;

typedef struct pointer_array_buf {
    ptr_wrap* pointer_arr;
    char* buf;
    int lines_count;
} pointer_array_buf_t;

void print_ptr_array_buf(pointer_array_buf* ptr_array);

#endif //ONEGIN_POINTER_ARRAY_BUF_H