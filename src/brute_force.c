#include "brute_force.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void brute_force_print(int mdp_size) {
    int i = 0;
    char code[mdp_size + 1];
    for (int i = 0; i < mdp_size; i++) {
        code[i] = INIT_CHAR;
    }
    code[mdp_size] = '\0';
    int nb_char = LAST_CHAR - INIT_CHAR + 1;

    while (i != mdp_size) {
        for (int j = 0; j < nb_char; j++) {
            printf("%s\n", code);
            code[i] += 1;
        }
        i++;
        while (code[i] == LAST_CHAR) {
            code[i] = INIT_CHAR;
            i++;
        }
        if (i != mdp_size) {
            code[i] += 1;
            i = 0;
            code[i] = INIT_CHAR;
        }
        printf("\n");
    }
}

int brute_force_crack(int mdp_size, char *passwd) {
    int i = 0;
    char code[mdp_size + 1];
    for (int i = 0; i < mdp_size; i++) {
        code[i] = INIT_CHAR;
    }
    code[mdp_size] = '\0';
    int nb_char = LAST_CHAR - INIT_CHAR + 1;

    while (i != mdp_size) {
        for (int j = 0; j < nb_char; j++) {
            printf("%s ", code);
            if (strcmp(code, passwd) == 0) {
                return EXIT_SUCCESS;
            }
            code[i] += 1;
        }
        i++;
        while (code[i] == LAST_CHAR) {
            code[i] = INIT_CHAR;
            i++;
        }
        if (i != mdp_size) {
            code[i] += 1;
            i = 0;
            code[i] = INIT_CHAR;
        }
        printf("\n");
    }

    return EXIT_FAILURE;
}