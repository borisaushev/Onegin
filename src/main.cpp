#include "common.h"
#include "line_reader.h"
#include "sorter.h"
#include "tests.h"

int main() {
    #ifdef DEBUG
        //runTests();
    #endif //DEBUG

    // SAFE_CALL(read_from_file());
    // SAFE_CALL(sort());
    // SAFE_CALL(output_in_fie());
    // SAFE_CALL(read_from_file);
    // SAFE_CALL(read_from_file);
    //TODO target unclude for .h files

    dprintf("\n\n-------TESTS RUN SUCCESSFULLY-------\n\n");

    FILE* output = fopen(OUTPUT_FILE_PATH, "w");

    dprintf("\nopened file\n");

    fprintf(output,"\n\n-------BUFFERED POINTER ARRAY START-------\n\n");
    dprintf("\n\n-------BUFFERED POINTER ARRAY START-------\n\n");

    pointer_array_buf_t ptr_array = {};
    parse_text(SOURCE_FILE_PATH, &ptr_array);
    print_ptr_array_buf(&ptr_array);

    qsort(ptr_array.pointer_arr, ptr_array.lines_count, sizeof(ptr_wrap_t), my_strcmp_start);
    dprintf("\n\n-----SORTED POINTER ARRAY BY START-------\n\n");
    print_ptr_array_buf(&ptr_array);

    qsort(ptr_array.pointer_arr, ptr_array.lines_count, sizeof(ptr_wrap_t), my_strcmp_end);
    dprintf("\n\n-----SORTED POINTER ARRAY BY END-------\n\n");
    print_ptr_array_buf(&ptr_array);

    fclose(output);
}
