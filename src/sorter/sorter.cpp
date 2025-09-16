#include "sorter.h"

#include <cassert>

#include "pointer_array.h"

#include <filesystem>

void sort_array(
    void* array,
    char* (*get_line) (int, void*),
    int lines_count,
    int (*my_strcmp) (const char*, const char*),
    void (*swap) (void* array, int i1, int i2)
) {
    assert(array);
    assert(get_line);
    assert(my_strcmp);

    dprintf("sorting started\n");

    for (int i = 0; i < lines_count; i++) {
        assert(i < lines_count);
        dprintf("finding min at %d\n", i);
        char* min_line = get_line(i, array);
        int minI = i;

        for (int j = i; j < lines_count; j++) {
            //dprintf("trying string %d\n", j);

            assert(j < lines_count);
            if ((*my_strcmp)(get_line(j, array), min_line) < 0) {
                dprintf("line: %s is less than: %s", get_line(j, array), min_line);
                min_line = get_line(j, array);
                minI = j;
            }
        }

        assert(i < lines_count);
        dprintf("min string is %s\n", min_line);
        dprintf("before swap: %s, %s\n", get_line(minI, array), get_line(i, array));
        swap(array, i, minI);

        dprintf("swapped lines: %s, %s\n", get_line(minI, array), get_line(i, array));

    }

    dprintf("sorting finished\n");
}

int my_strlen(const char* str) {
    assert(str);
    int len = 0;
    for (; str[len] != '\n'; len++){}
    return len;
}


int my_strcmp_start(const char* str1, const char* str2) {
    assert(str1);
    assert(str2);
    //dprintf("comparing str1: %s, str2: %s\n", str1, str2);
    const int l1 = my_strlen(str1);
    const int l2 = my_strlen(str2);

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


int my_strcmp_end(const char* str1, const char* str2) {
    assert(str1);
    assert(str2);
    //dprintf("comparing str1: %s, str2: %s\n", str1, str2);

    int i1 = my_strlen(str1) - 1, i2 = my_strlen(str2) - 1;
    assert(i1 >= 0);
    assert(i2 >= 0);
    for (; i1 >= 0 && i2 >= 0; i1--, i2--) {
        assert(i1 >= 0);
        assert(i2 >= 0);
        while ((ispunct(str1[i1]) || str1[i1] == ' ') && i1 >= 0) {
            i1--;
        }
        while ((ispunct(str2[i2]) || str2[i2] == ' ') && i2 >= 0) {
            i2--;
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

