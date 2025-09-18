#include "line_reader.h"

#include <math.h>
#include <cassert>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#include "common.h"
#include "pointer_array/buffer_version/pointer_array_buf.h"

long get_file_size(const char* filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;
    }
    else {
        perror("Error getting file status");
        return -1;
    }
}

int parse_text(const char *file_path, pointer_array_buf_t *arr_ptr) {
    assert(file_path);

    int stream = open(file_path, O_RDONLY);

    int file_size = get_file_size(file_path);
    dprintf("file size: %d\n", file_size);

    if (file_size == -1) {
        printf("Could not open file %s\n", file_path);
        exit(1);
    }

    char* text = (char *) calloc(file_size, sizeof(char));
    int bytes_read = read(stream, text, file_size);

    if (bytes_read == -1) {
        printf("Could not read file %s\n", file_path);
        dprintf("error: %s\n", strerror(errno));
    }
    dprintf("Read %d bytes\n", bytes_read);

    text = (char *) realloc(text,  (bytes_read + 2));
    file_size = bytes_read;
    text[bytes_read] = (text[bytes_read-1] == '\n' ? '\0' : '\n');
    text[bytes_read + 1] = '\0';
    close(stream);

    int ptr_count = 0;
    for (int i = 0; i < bytes_read+1; i++) {
        if (text[i] == '\n') {
            ptr_count++;
        }
    }

    ptr_wrap_t* ptr_array = (ptr_wrap_t*) calloc(ptr_count, sizeof(ptr_wrap_t));

    char* curptr = &text[0];
    char* nextLine = strchr(curptr, '\n');
    //while (() != NULL) {
    for (int i = 0; i < ptr_count; i++) {
        nextLine = strchr(curptr, '\n');
        assert(nextLine);

        int len = nextLine - curptr;
        ptr_array[i] = {.ptr=curptr, .len=len};
        curptr = nextLine + 1;
    }

    //printf("count: %d - ptr_count: %d\n", count, ptr_count);
    //assert(count == ptr_count);
    assert(text[file_size + 1] == '\0');

    dprintf("read %d lines from file %s\n", ptr_count, file_path);

    arr_ptr->pointer_arr = ptr_array;
    arr_ptr->buf = text;
    arr_ptr->lines_count = ptr_count;

    return 0;
}