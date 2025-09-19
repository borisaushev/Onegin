#ifndef ONEGIN_COMMON_H
#define ONEGIN_COMMON_H

typedef enum errors{
    SUCCESS = 0,
    FILE_NOT_FOUND,
    FILE_NOT_READABLE,
    INVALID_ARGUMENT,
    UNKNOWN
} error_code_t;

typedef struct error_info {
    error_code_t err_code;
    const char* msg;
} error_info_t;

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

//call the function and exit on error with message
#define SAFE_CALL(func) \
do { \
    error_info_t result = (func); \
    if (result.err_code != SUCCESS) { \
        fprintf(stderr, "ERROR [%s:%d]: %s (code %d)\n", \
        __FILE__, __LINE__, result.msg, result.err_code); \
        exit(EXIT_FAILURE); \
    } \
} while(0)

//DEBUG printf with immediate flush
#ifdef DEBUG
    #define DPRINTF(...) \
    do { \
        printf(__VA_ARGS__); \
        fflush(stdout); \
    } while(0)
#else
    #define DPRINTF(...) ;
#endif //DEBUG

//define for printing in stderr
#define PRINTERR(...) fprintf(stderr, __VA_ARGS__)

#endif //ONEGIN_COMMON_H