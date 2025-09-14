#include "line_reader.h"

#include <math.h>
#include <cassert>
#include <stdio.h>
#include <string.h>

#include "common.h"
#include "square_array.h"


square_array_t parse_square_array(const char *file_path) {
    assert(file_path);

    FILE *stream = fopen(file_path, "r");

    if (!stream) {
        printf("Could not open file %s\n", file_path);
        assert(0);
    }

    char (*text)[MAX_LINE_LENGTH] = (char (*)[MAX_LINE_LENGTH]) calloc(LINES_COUNT, sizeof(char[MAX_LINE_LENGTH]));

    char (*start)[MAX_LINE_LENGTH] = text;
    int count = 0;
    char *result = NULL;
    while (!feof(stream)) {
        result = fgets(*start, MAX_LINE_LENGTH, stream);
        start++;
        count++;
    }

    assert(result);
    for (int i = 0; i < MAX_LINE_LENGTH; i++) {
        assert(i < MAX_LINE_LENGTH);
        if (result[i] == '\0') {
            result[i] = '\n';
            break;
        }
    }

    text = (char (*)[MAX_LINE_LENGTH]) realloc(text, sizeof(char[MAX_LINE_LENGTH]) * count);

    dprintf("read %d lines from file %s\n", count, file_path);

    square_array_t square_array = {.text = text, .lines_count = count};

    fclose(stream);
    return square_array;
}

pointer_array_t parse_pointer_array(const char *file_path) {
    assert(file_path);

    FILE *stream = fopen(file_path, "r");

    if (!stream) {
        printf("Could not open file %s\n", file_path);
        assert(0);
    }

    char** text = (char **) calloc(LINES_COUNT, sizeof(char *));
    int count = 0;
    char buffer[MAX_LINE_LENGTH];
    char *result = NULL;
    while (!feof(stream)) {
        fgets(buffer, MAX_LINE_LENGTH, stream);
        text[count] = strdup(buffer);
        result = text[count];
        count++;
    }

    assert(result);
    for (int i = 0; i < MAX_LINE_LENGTH; i++) {
        assert(i < MAX_LINE_LENGTH);
        if (result[i] == '\0') {
            result[i] = '\n';
            break;
        }
    }

    text = (char **) realloc(text, sizeof(char *) * count);

    dprintf("read %d lines from file %s\n", count, file_path);

    fclose(stream);
    return {text, count};
}
