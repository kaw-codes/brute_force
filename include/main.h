#include <stdbool.h>
#ifndef MAIN_H
#define MAIN_H

typedef enum { CRACKER, GENERATOR } mode;

typedef struct {
    mode mode;
    char *passwd;
    bool time;
    bool size_is_choosen;
    int size;
} config_t;

#endif /* MAIN_H */