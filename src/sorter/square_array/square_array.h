#ifndef ONEGIN_SQUARE_ARRAY_H
#define ONEGIN_SQUARE_ARRAY_H

#include <stdio.h>
#include "common.h"

/**
 * @brief Fixed-width 2d character array structure
 */
typedef struct square_array {
    char (*text)[MAX_LINE_LENGTH];
    int lines_count;
    int line_length;
} square_array_t;

/**
 * @brief Swap two lines in square array by index
 * @param array Square array structure
 * @param i1 First index
 * @param i2 Second index
 */
void swap_square(void* array, int i1, int i2);

/**
 * @brief Get pointer to specific line
 * @param index Line index to retrieve
 * @param square_array Square array structure
 * @return Pointer to requested line
 */
char* get_line_square_array(int index, void* square_array);

/**
 * @brief Sort square array using comparator function
 * @param square_array Array to sort
 * @param my_strcmp comparator function
 */
void sort_square_array(square_array_t* square_array, int (*my_strcmp) (const char*, const char*));

/**
 * @brief Swap contents of two character arrays
 * @param str1 First string
 * @param str2 Second string
 */
void swap_lines(char* str1, char* str2);

/**
 * @brief Print square array to output stream
 * @param array Array to print
 * @param out_stream Output file stream
 */
void print_square_array(square_array_t* array, FILE *out_stream);

#endif //ONEGIN_SQUARE_ARRAY_H