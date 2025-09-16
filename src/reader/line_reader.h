#ifndef ONEGIN_LINEREADER_H
#define ONEGIN_LINEREADER_H

#include "pointer_array.h"
#include "square_array.h"

/**
 * @brief Read file into fixed 2d array
 * @param file_path Input file path
 * @return Square array structure with file contents
 */
square_array_t parse_square_array(const char* file_path);

/**
 * @brief Read file into array of string pointers
 * @param file_path Input file path
 * @return Pointer array structure with file contents
 */
pointer_array_t parse_pointer_array(const char* file_path);

#endif //ONEGIN_LINEREADER_H