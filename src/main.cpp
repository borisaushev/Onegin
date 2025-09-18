#include "common.h"
#include "line_reader.h"
#include "sorter.h"
#include "tests.h"

int main() {
    #ifdef DEBUG
        runTests();
    #endif //DEBUG

    DPRINTF("\n\n-------TESTS RUN SUCCESSFULLY-------\n\n");

    FILE* output = fopen(OUTPUT_FILE_PATH, "w");

    pointer_array_buf_t ptr_array = {};
    parse_text(SOURCE_FILE_PATH, &ptr_array);

    qsort(ptr_array.pointer_arr, ptr_array.lines_count, sizeof(ptr_wrap_t), my_strcmp_start);
    fprintf(output, "\n\n-----SORTED POINTER ARRAY BY START-------\n\n");
    print_ptr_array(output, &ptr_array);

    qsort(ptr_array.pointer_arr, ptr_array.lines_count, sizeof(ptr_wrap_t), my_strcmp_end);
    fprintf(output, "\n\n-----SORTED POINTER ARRAY BY END-------\n\n");
    print_ptr_array(output, &ptr_array);

    fprintf(output,"\n\n-------SOURCE TEXT-------\n\n");
    print_buf(output, &ptr_array);

    fclose(output);
    free(ptr_array.pointer_arr);
    free(ptr_array.buf);
}
