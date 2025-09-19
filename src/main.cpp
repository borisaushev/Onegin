#include "common.h"
#include "line_reader.h"
#include "sorter.h"
#include "tests.h"

//TODO state struct
//TODO safe call
int main() {
    #ifdef DEBUG
        runTests();
    #endif //DEBUG

    DPRINTF("\n-------TESTS RUN SUCCESSFULLY-------\n\n");

    //parsing
    FILE* output = fopen(OUTPUT_FILE_PATH, "w");
    pointer_array_buf_t ptr_array = {};
    parse_text(SOURCE_FILE_PATH, &ptr_array);

    //sorting by start
    qsort(ptr_array.pointer_arr, ptr_array.lines_count, sizeof(ptr_wrap_t), my_strcmp_start);
    fprintf(output, "-----SORTED POINTER ARRAY BY START-------\n\n");
    DPRINTF("\n\n-----SORTED POINTER ARRAY BY START-------\n\n");
    print_ptr_array(output, &ptr_array);

    //sorting by end
    qsort(ptr_array.pointer_arr, ptr_array.lines_count, sizeof(ptr_wrap_t), my_strcmp_end);
    fprintf(output, "\n\n-----SORTED POINTER ARRAY BY END-------\n\n");
    DPRINTF("\n\n-----SORTED POINTER ARRAY BY END-------\n\n");
    print_ptr_array(output, &ptr_array);

    //printing source text
    fprintf(output,"\n\n-------SOURCE TEXT-------\n\n");
    DPRINTF("\n\n-----PRINTING SOURCE TEXT-------\n\n");
    print_buf(output, &ptr_array);

    printf("TEXT PRINTED TO FILE: %s\n", OUTPUT_FILE_PATH);
    DPRINTF("\n\n-----COMMIT RN-------\n\n");

    fclose(output);
    free(ptr_array.pointer_arr);
    free(ptr_array.buf);
}
