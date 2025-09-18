#ifndef ONEGIN_COMMON_H
#define ONEGIN_COMMON_H

#ifdef DEBUG
//TODO move to include folder
    #define dprintf(...) printf(__VA_ARGS__)
#else
    #define DPRINTF(...) ;
#endif //DEBUG

const char* const SOURCE_FILE_PATH = "C:\\Users\\bossb\\CLionProjects\\Onegin\\src\\onegintext_mini.txt";

const char* const OUTPUT_FILE_PATH = "C:\\Users\\bossb\\CLionProjects\\Onegin\\src\\output.txt";

#include <math.h>
#include <cassert>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <string.h>

#endif //ONEGIN_COMMON_H