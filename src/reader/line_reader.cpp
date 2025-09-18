#include "line_reader.h"

#include "common.h"
#include "ptr_array_buf.h"

static long get_file_size(const char* filename) {
    struct stat st;
    if (stat(filename, &st) == 0) {
        return st.st_size;
    }
    else {
        perror("Error getting file status");
        return -1;
    }
}

static void parse_pointers(char *text, int ptr_count, ptr_wrap_t** ptr_array) {
    char* curptr = &text[0];
    char* nextLine = strchr(curptr, '\n');
    for (int i = 0; i < ptr_count; i++) {
        nextLine = strchr(curptr, '\n');
        assert(nextLine);

        int len = nextLine - curptr;
        (*ptr_array)[i] = {.ptr=curptr, .len=len};
        curptr = nextLine + 1;
    }
}

static void read_file(const char *file_path, char** text, int* bytes_read) {
    int stream = open(file_path, O_RDONLY);

    int file_size = get_file_size(file_path);
    DPRINTF("file size: %d\n", file_size);

    if (file_size == -1) {
        printf("Could not open file %s\n", file_path);
        exit(1);
    }
    *text = (char *) calloc(file_size + 2, sizeof(char));
    *bytes_read = read(stream, *text, file_size);

    if (*bytes_read == -1) {
        printf("Could not read file %s\n", file_path);
        DPRINTF("error: %s\n", strerror(errno));
    }
    DPRINTF("Read %d bytes\n", *bytes_read);

    close(stream);
}

static void count_lines(char *text, int bytes_read, int* ptr_count) {
    for (int i = 0; i < bytes_read+1; i++) {
        if (text[i] == '\n') {
            (*ptr_count)++;
        }
    }
}

int parse_text(const char *file_path, pointer_array_buf_t *arr_ptr) {
    assert(file_path);

    char *text;
    int bytes_read;
    read_file(file_path, &text, &bytes_read);

    text = (char *) realloc(text,  bytes_read + 2);
    text[bytes_read] = (text[bytes_read-1] == '\n' ? '\0' : '\n');
    text[bytes_read + 1] = '\0';

    int ptr_count = 0;
    count_lines(text, bytes_read, &ptr_count);

    ptr_wrap_t* ptr_array = (ptr_wrap_t*) calloc(ptr_count, sizeof(ptr_wrap_t));
    parse_pointers(text, ptr_count, &ptr_array);

    assert(text[bytes_read + 1] == '\0');
    DPRINTF("read %d lines from file %s\n", ptr_count, file_path);

    arr_ptr->pointer_arr = ptr_array;
    arr_ptr->buf = text;
    arr_ptr->lines_count = ptr_count;

    return 0;
}
