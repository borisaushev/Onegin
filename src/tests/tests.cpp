#include "tests.h"
#include "common.h"
#include "ptr_array_buf.h"
#include "sorter.h"


void runTests() {
    test_compare_lines_start();
    test_compare_lines_end();
}

void test_compare_lines_start() {
    const ptr_wrap s1 = {strdup("string1\n"), 7};
    const ptr_wrap s2 = {strdup("string1\n"), 7};
    const ptr_wrap s3 = {strdup("string2\n"), 7};
    const ptr_wrap s4 = {strdup("ab c\n"), 4};
    const ptr_wrap s5 = {strdup("abd\n"), 3};

    assert(my_strcmp_start(&s1, &s1) == 0);
    assert(my_strcmp_start(&s1, &s2) == 0);
    assert(my_strcmp_start(&s2, &s1) == 0);
    assert(my_strcmp_start(&s1, &s3) == -1);
    assert(my_strcmp_start(&s3, &s1) == 1);
    assert(my_strcmp_start(&s1, &s4) == 1);
    assert(my_strcmp_start(&s4, &s1) == -1);
    assert(my_strcmp_start(&s4, &s5) == -1);
}

void test_compare_lines_end() {
    const ptr_wrap s1 = {strdup("string1\n"), 7};
    const ptr_wrap s2 = {strdup("string1\n"), 7};
    const ptr_wrap s3 = {strdup("string2\n"), 7};
    const ptr_wrap s4 = {strdup("ab c\n"), 4};
    const ptr_wrap s5 = {strdup("abd\n"), 3};

    assert(my_strcmp_start(&s1, &s1) == 0);
    assert(my_strcmp_start(&s1, &s2) == 0);
    assert(my_strcmp_start(&s2, &s1) == 0);
    assert(my_strcmp_start(&s1, &s3) == -1);
    assert(my_strcmp_start(&s3, &s1) == 1);
    assert(my_strcmp_start(&s1, &s4) == 1);
    assert(my_strcmp_start(&s4, &s1) == -1);
    assert(my_strcmp_start(&s4, &s5) == -1);
}