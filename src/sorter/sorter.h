#ifndef ONEGIN_SORTER_H
#define ONEGIN_SORTER_H

void sort_array(
    void* array,
    char* (*get_line) (int, void*),
    int lines_count,
    int (*my_strcmp) (const char*, const char*),
    void (*swap) (void* array, int i1, int i2)
);

int my_strcmp_start(const char* str1, const char* str2);

int my_strcmp_end(const char* str1, const char* str2);

int my_strlen(const char* str);

#endif //ONEGIN_SORTER_H