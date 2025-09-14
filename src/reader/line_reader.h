#ifndef ONEGIN_LINEREADER_H
#define ONEGIN_LINEREADER_H

#include "pointer_array.h"
#include "square_array.h"

square_array_t parse_square_array(const char* file_path);

void print_square_array(square_array_t* array);

pointer_array_t parse_pointer_array(const char* file_path);

#endif //ONEGIN_LINEREADER_H