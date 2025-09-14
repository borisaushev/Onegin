#ifndef ONEGIN_COMMON_H
#define ONEGIN_COMMON_H

#ifdef DEBUG
    #define dprintf(...) printf(__VA_ARGS__)
#else
    #define dprintf(...) ;
#endif //DEBUG


const int MAX_LINE_LENGTH = 45;

const int LINES_COUNT = 5134;

const char* const FILE_PATH = "C:\\Users\\bossb\\CLionProjects\\Onegin\\src\\onegintext.txt";

#endif //ONEGIN_COMMON_H