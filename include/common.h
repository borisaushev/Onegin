#ifndef ONEGIN_COMMON_H
#define ONEGIN_COMMON_H

#ifdef DEBUG
    #define DPRINTF(...) printf(__VA_ARGS__)
#else
    #define DPRINTF(...) ;
#endif //DEBUG


const char* const SOURCE_FILE_PATH = "C:\\Users\\bossb\\CLionProjects\\Onegin\\text\\onegintext.txt";
const char* const OUTPUT_FILE_PATH = "C:\\Users\\bossb\\CLionProjects\\Onegin\\text\\output.txt";

#include <fcntl.h>
#include <io.h>
#include <math.h>
#include <cassert>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <filesystem>


#endif //ONEGIN_COMMON_H