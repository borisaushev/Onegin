#ifndef ONEGIN_POINTER_ARRAY_H
#define ONEGIN_POINTER_ARRAY_H

#include <stdio.h>
#include "common.h"

/**
 * @brief Array of string pointers with metadata
 */
typedef struct pointer_array {
    char** text;
    int lines_count;
    int line_length;
} pointer_array_t;

/**
 * @brief returns pointer to specific line
 * @param index Line index to retrieve
 * @param pointer_array Pointer array structure
 * @return Pointer to requested line
 */
char* get_line_pointer_array(int index, void* pointer_array);

/**
 * @brief Sort pointer array using comparator function
 * @param pointer_array Array to sort
 * @param my_strcmp Comparison function for sorting
 */
void sort_pointer_array(pointer_array_t* pointer_array, int (*my_strcmp) (const char*, const char*));

/**
 * @brief Swap two pointers in array
 * @param array Pointer array structure (casts to pointer_array_t)
 * @param i1 First index to swap
 * @param i2 Second index to swap
 */
void swap_pointers(void* array, int i1, int i2);

/**
 * @brief Print pointer array to output stream
 * @param array Array to print
 * @param out_stream Output file stream
 */
void print_pointer_array(pointer_array_t* array, FILE* out_stream);

#endif //ONEGIN_POINTER_ARRAY_H