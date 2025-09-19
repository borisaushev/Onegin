#ifndef ONEGIN_LINEREADER_H
#define ONEGIN_LINEREADER_H

#include "ptr_array_buf.h"


/**
 * parses text and sets pointers to each line start
 * @param file_path path to source file
 * @param arr_ptr pointer to pointer array struct
 * @return zero if all fine
 */
int parse_text(const char *file_path, pointer_array_buf_t *arr_ptr);

#endif //ONEGIN_LINEREADER_H