#ifndef ONEGIN_POINTER_ARRAY_BUF_H
#define ONEGIN_POINTER_ARRAY_BUF_H
#include <stdio.h>

/**
 * structure containing ptr to the first symbol of line and the length of the line
 */
typedef struct ptr_wrap {
    char* ptr;
    int len;
} ptr_wrap_t;

/**
 * structure containing array of ptr-wraps, a text as an array, and a number of lines in array
 */
typedef struct ptr_array_buf {
    ptr_wrap* pointer_arr;
    char* buf;
    int lines_count;
} pointer_array_buf_t;

/**
 * prints given pointer array line-by-line
 * @param output output stream
 * @param ptr_array ptr array to print
 */
void print_ptr_array(FILE* output, ptr_array_buf* ptr_array);

/**
 * prints the whole buffer at once
 * @param output output stream
 * @param ptr_array pointer array
 */
void print_buf(FILE* output, ptr_array_buf* ptr_array);


/**
 * prints all ptr->len symbols and a \n at the end
 * @param output output stream
 * @param ptr_wrap ptr wrap to print
 */
void my_printf(FILE* output, ptr_wrap_t ptr_wrap);

#endif //ONEGIN_POINTER_ARRAY_BUF_H