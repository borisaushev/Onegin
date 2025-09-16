#include <stdio.h>
#include <cassert>
#include <cstdlib>
#include <cstring>



#include "tests.h"
#include "common.h"
#include "sorter.h"
#include "square_array.h"


void runTests() {
    const char* test_data[] = {"string3\n", "string2\n", "string1\n", "zS2\n", "zs1\n", "zz2\n", "zz 1\n"};

    size_t num_of_elements = sizeof(test_data)/sizeof(char*);
    dprintf("sizeof test_data: %llu\n", num_of_elements);
    char (*text) [MAX_LINE_LENGTH] = (char (*) [MAX_LINE_LENGTH]) calloc(num_of_elements, sizeof(char[MAX_LINE_LENGTH]));

    char (*start) [MAX_LINE_LENGTH] = text;
    for (size_t i = 0; i < num_of_elements; i++, start++) {
        for (int ch = 0; ch <= my_strlen(test_data[i]); ch++) {
            (*start)[ch] = test_data[i][ch];
        }
    }

    square_array_t square_array = {
        text,
        (int) num_of_elements
    };
    dprintf("test square array:\n");
    print_square_array(&square_array, stdout);

    test_sorter(&square_array);
    dprintf("------sorter tests successfull------\n");

    test_swap_lines(square_array.text[0], square_array.text[2]);
    dprintf("\n------lines swap tests successfull------\n");

    test_compare_lines();
    dprintf("------lines compare tests successfull------\n");

    free(text);
}

void test_sorter(square_array_t* square_array) {
    sort_square_array(square_array, my_strcmp_start);

    assert(!strcmp("string1\n", square_array->text[0]));
    assert(!strcmp("string2\n", square_array->text[1]));
    assert(!strcmp("string3\n", square_array->text[2]));
    assert(!strcmp("zs1\n", square_array->text[3]));
    assert(!strcmp("zS2\n", square_array->text[4]));
    assert(!strcmp("zz 1\n", square_array->text[5]));
    assert(!strcmp("zz2\n", square_array->text[6]));
}

void test_swap_lines(char* s1, char* s2) {
    const char* scopy1 = strdup(s1);
    const char* scopy2 = strdup(s2);
    swap_lines(s1, s2);

    assert(strcmp(s2, scopy1) == 0);
    assert(strcmp(s1, scopy2) == 0);
}

void test_compare_lines() {
    const char* s1 = strdup("string1\n");
    const char* s2 = strdup("string1\n");
    const char* s3 = strdup("string2\n");
    const char* s4 = strdup("ab c\n");
    const char* s5 = strdup("abd\n");

    assert(my_strcmp_start(s1, s1) == 0);
    assert(my_strcmp_start(s1, s2) == 0);
    assert(my_strcmp_start(s2, s1) == 0);
    assert(my_strcmp_start(s1, s3) == -1);
    assert(my_strcmp_start(s3, s1) == 1);
    assert(my_strcmp_start(s1, s4) == 1);
    assert(my_strcmp_start(s4, s1) == -1);
    assert(my_strcmp_start(s4, s5) == -1);
}