#include "sorter.h"

#include "common.h"
#include "ptr_array_buf.h"


int my_strcmp_start(const void* vpstr1, const void* vpstr2) {
    assert(vpstr1);
    assert(vpstr2);

    ptr_wrap* wstr1 = (ptr_wrap_t*)vpstr1;
    ptr_wrap* wstr2 = (ptr_wrap_t*)vpstr2;
    assert(wstr1);
    assert(wstr2);

    const char* str1 = wstr1->ptr;
    const char* str2 = wstr2->ptr;
    assert(str1);
    assert(str2);

    const int l1 = wstr1->len;
    const int l2 = wstr2->len;

    int i1 = 0, i2 = 0;
    for (; i1 < l1 && i2 < l2; i1++, i2++) {
        assert(i1 < l1);
        assert(i2 < l2);
        while ((ispunct(str1[i1]) || str1[i1] == ' ') && i1 < l1) {
            i1++;
        }
        while ((ispunct(str2[i2]) || str2[i2] == ' ') && i2 < l2) {
            i2++;
        }

        if (i1 == l1 && i2 == l2) {
            return 0;
        }
        if (i1 == l1) {
            return -1;
        }
        if (i2 == l2) {
            return 1;
        }

        assert(i1 < l1);
        assert(i2 < l2);
        char c1 = (char) tolower(str1[i1]);
        char c2 = (char) tolower(str2[i2]);
        if (c1 < c2) {
            return -1;
        }
        if (c1 > c2) {
            return 1;
        }
    }

    if (i1 == l1 && i2 == l2) {
        return 0;
    }
    if (i1 == l1) {
        return -1;
    }
    if (i2 == l2) {
        return 1;
    }

    return 0;
}

int my_strcmp_end(const void* vpstr1, const void* vpstr2) {
    assert(vpstr1);
    assert(vpstr2);

    ptr_wrap* wstr1 = (ptr_wrap_t*)vpstr1;
    ptr_wrap* wstr2 = (ptr_wrap_t*)vpstr2;
    assert(wstr1);
    assert(wstr2);

    const char* str1 = wstr1->ptr;
    const char* str2 = wstr2->ptr;

    assert(str1);
    assert(str2);
    //dprintf("comparing str1: %s, str2: %s\n", str1, str2);

    int i1 = wstr1->len - 1, i2 = wstr2->len - 1;

    assert(i1 >= 0);
    assert(i2 >= 0);
    for (; i1 >= 0 && i2 >= 0; i1--, i2--) {
        assert(i1 >= 0);
        assert(i2 >= 0);
        for (; (ispunct(str1[i1]) || str1[i1] == ' ') && i1 >= 0; i1--) {
        }
        for (; (ispunct(str2[i2]) || str2[i2] == ' ') && i2 >= 0; i2--) {
        }

        assert(i1 >= 0);
        assert(i2 >= 0);
        char c1 = (char) tolower(str1[i1]);
        char c2 = (char) tolower(str2[i2]);
        if (c1 < c2) {
            return -1;
        }
        if (c1 > c2) {
            return 1;
        }

        if (i1 == 0 && i2 == 0) {
            return 0;
        }
        if (i1 == 0) {
            return -1;
        }
        if (i2 == 0) {
            return 1;
        }
    }

    if (i1 == 0 && i2 == 0) {
        return 0;
    }
    if (i1 == 0) {
        return -1;
    }
    if (i2 == 0) {
        return 1;
    }

    return 0;
}

