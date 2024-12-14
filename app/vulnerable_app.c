#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[16];
    char passwd[] = "mdp";
    bool access = false;

    while (!access) {
        printf("Enter your input: \n> ");
        if (fgets(input, sizeof(input), stdin)) {
            printf("You entered: %s", input);
        } else {
            printf("Error reading input.\n");
            return EXIT_FAILURE;
        }

        int i = 0;
        while (i != sizeof(passwd) - 1) {
            if (passwd[i] != input[i]) {
                printf("passwd incorrect\n");
                break;
            }
            i++;
            if (i == sizeof(passwd) - 1) {
                printf("passwd valid\n");
                access = true;
            }
        }
    }

    if (access) {
        printf("welcome :)\n");
    }

    return EXIT_SUCCESS;
}