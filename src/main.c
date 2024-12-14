#include "main.h"
#include "brute_force.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

config_t config = {0};

static void print_help() {
    printf("usage: brute_force -c PASSWD [-h]\n");
    printf("\tCRACKING MODE: crack the password you enter and tell you the time spent\n");
    printf("       brute_force [-h|-t|-zSIZE]\n");
    printf("\tGENERATING MODE: generate all the possibilities\n");
    printf("-h, --help              display this help and exit\n");
    printf("-c, --crack [passwd]    crack your password input\n");
    printf("-t, --time              displays the runtime\n");
    printf("-z[N], --size[=N]       set the gen's max size (default:no_max_size)\n");
}

// option managing and error detection
static void option_parser(int argc, char *argv[]) {
    config.mode = GENERATOR;
    config.size = -1;
    struct option long_options[] = {{"help", no_argument, 0, 'h'},
                                    {"crack", required_argument, 0, 'c'},
                                    {"time", no_argument, 0, 't'},
                                    {"size", optional_argument, 0, 'z'},
                                    {0, 0, 0, 0}};

    int opt = 0;
    while ((opt = getopt_long(argc, argv, "hc:tz::", long_options, NULL)) != -1) {
        switch (opt) {
        case 'h':
            print_help();
            exit(EXIT_SUCCESS);
            break;
        case 'c':
            config.mode = CRACKER;
            config.passwd = optarg;
            int i = 0;
            char iter = config.passwd[i];
            while (iter != '\0') {
                i++;
                iter = config.passwd[i];
            }
            config.size = i;
            break;
        case 't':
            config.time = true;
            break;
        case 'z':
            config.size_is_choosen = true;
            if (optarg) {
                config.size = atoi(optarg);
            }
            break;
        default:
            break;
        }
    }

    // verif mismatch options:
    if (config.mode == CRACKER && config.size_is_choosen) {
        fprintf(stderr, "error: option '-z[N] --size[=N]' conflicts with CRACKER MODE\n");
        print_help();
        exit(EXIT_FAILURE);
    }
    if (config.mode == CRACKER && config.time) {
        fprintf(stderr, "error: option '-t --time' conflicts with CRACKER MODE\n");
        print_help();
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {

    // options managing:
    option_parser(argc, argv);

    // CRACKER MODE:
    if (config.mode == CRACKER) {
        printf("%s\n", config.passwd);
        clock_t begin = time(NULL);
        int res = brute_force_crack(config.size, config.passwd);
        clock_t end = time(NULL);
        switch (res) {
        case 0:
            printf("\npassword found! :)\n");
            break;
        case 1:
            printf("\npassword unfound! :(\n");
            break;
        default:
            fprintf(stderr, "error: wrong return value for 'brute_force_2' function\n");
            exit(EXIT_FAILURE);
            break;
        }
        double time_spent = (double) (end - begin) / CLOCKS_PER_SEC * 1000000;
        printf("----- END -----\n");
        printf("CRACKER MODE\n");
        printf("password size :\t%d\n", config.size);
        printf("alphabet size :\t%d\n", LAST_CHAR - INIT_CHAR + 1);
        printf("runtime :\t%f sec\n", time_spent);
    }
    // GENERATOR MODE:
    else {
        clock_t begin = time(NULL);
        int size = 0;
        while (size != config.size) {
            brute_force_print(size + 1);
            size++;
        }
        printf("----- END -----\n");
        printf("GENERATOR MODE\n");
        if (config.time) {
            clock_t end = time(NULL);
            double time_spent = (double) (end - begin) / CLOCKS_PER_SEC * 1000000;
            printf("password size :\t%d\n", config.size);
            printf("alphabet size :\t%d\n", LAST_CHAR - INIT_CHAR + 1);
            printf("runtime :\t%f sec\n", time_spent);
        }
    }

    return EXIT_SUCCESS;
}
