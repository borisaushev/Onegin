#ifndef ONEGIN_SORTER_H
#define ONEGIN_SORTER_H

/**
 * @brief Generic array sorting function
 * @param array Array to sort
 * @param get_line Function to retrieve line by index
 * @param lines_count Number of lines in array
 * @param my_strcmp String comparison function
 * @param swap Function to swap two elements
 */
void sort_array(
    void* array,
    char* (*get_line) (int, void*),
    int lines_count,
    int (*my_strcmp) (const char*, const char*),
    void (*swap) (void* array, int i1, int i2)
);

/**
 * @brief Compare strings from start (ignoring punctuation/whitespace)
 * @param str1 First string to compare
 * @param str2 Second string to compare
 * @return Comparison result (-1, 0, 1)
 */
int my_strcmp_start(const char* str1, const char* str2);

/**
 * @brief Compare strings from end (reverse order)
 * @param str1 First string to compare
 * @param str2 Second string to compare
 * @return Comparison result (-1, 0, 1)
 */
int my_strcmp_end(const char* str1, const char* str2);

/**
 * @brief Calculate string length until newline
 * @param str String to measure
 * @return Length of string until newline character
 */
int my_strlen(const char* str);

#endif //ONEGIN_SORTER_H