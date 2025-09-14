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

    printf("\n-------SQUARE ARRAY START-------\n");

    square_array_t square_array = parse_square_array(FILE_PATH);
    print_square_array(&square_array);

    printf("\n--------------------\nSORTED BY START\n--------------------\n");
    sort_square_array(&square_array, my_strcmp_start);
    print_square_array(&square_array);

    printf("\n--------------------\nSORTED BY END\n--------------------\n");
    sort_square_array(&square_array, my_strcmp_end);
    print_square_array(&square_array);

    dprintf("freeing data\n");
    free(square_array.text);

    printf("\n-------SQUARE ARRAY END-------\n");


    printf("\n-------POINTER ARRAY START-------\n");

    pointer_array_t pointer_array = parse_pointer_array(FILE_PATH);
    print_pointer_array(&pointer_array);

    printf("\n--------------------\nSORTED BY START\n--------------------\n");
    sort_pointer_array(&pointer_array, my_strcmp_start);
    print_pointer_array(&pointer_array);

    printf("\n--------------------\nSORTED BY END\n--------------------\n");
    sort_pointer_array(&pointer_array, my_strcmp_end);
    print_pointer_array(&pointer_array);

    dprintf("freeing data\n");
    free(pointer_array.text);

    printf("\n-------POINTER ARRAY END-------\n");
}
