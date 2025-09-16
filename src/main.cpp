#include "TXLib.h"
#include "line_reader.h"
#include "pointer_array.h"
#include "sorter.h"
#include "square_array.h"
#include "tests.h"

int main() {
    #ifdef DEBUG
        runTests();
    #endif //DEBUG

    dprintf("\n-------TESTS RUN SUCCESSFULLY-------\n");

    FILE* output = fopen(OUTPUT_FILE_PATH, "w");

    fprintf(output, "\n-------SQUARE ARRAY START-------\n");

    square_array_t square_array = parse_square_array(SOURCE_FILE_PATH);
    print_square_array(&square_array, output);

    fprintf(output,"\n--------------------\nSORTED BY START\n--------------------\n");
    sort_square_array(&square_array, my_strcmp_start);
    print_square_array(&square_array, output);

    fprintf(output,"\n--------------------\nSORTED BY END\n--------------------\n");
    sort_square_array(&square_array, my_strcmp_end);
    print_square_array(&square_array, output);

    dprintf("freeing data\n");
    free(square_array.text);

    fprintf(output,"\n-------SQUARE ARRAY END-------\n");


    fprintf(output,"\n-------POINTER ARRAY START-------\n");

    pointer_array_t pointer_array = parse_pointer_array(SOURCE_FILE_PATH);
    print_pointer_array(&pointer_array, output);

    fprintf(output,"\n--------------------\nSORTED BY START\n--------------------\n");
    sort_pointer_array(&pointer_array, my_strcmp_start);
    print_pointer_array(&pointer_array, output);

    fprintf(output,"\n--------------------\nSORTED BY END\n--------------------\n");
    sort_pointer_array(&pointer_array, my_strcmp_end);
    print_pointer_array(&pointer_array, output);

    dprintf("freeing data\n");
    free(pointer_array.text);

    fprintf(output,"\n-------POINTER ARRAY END-------\n");
}
