#ifndef BRUTE_FORCE_H
#define BRUTE_FORCE_H
#define INIT_CHAR 32  // ' '
#define LAST_CHAR 126 // '~'
// http://www.conseil-creation.com/informatique/bureautique/ascii_hexadecimal.php

/**
 * GENERATOR MODE
 * given a size, generates and prints all characters combinations
 *
 * @param mdp_size the size of the words we are generating
 */
void brute_force_print(int mdp_size);

/**
 * CRACKER MODE
 * try to crack the given password by testing every possibilites
 *
 * @param mdp_size the size of the words we are generating
 * @param passwd string containing the password we want to crack
 *
 * @return  0 (EXIT_SUCCESS) if password found
 *          1 (EXIT_FAILURE) if password unfound
 */
int brute_force_crack(int mdp_size, char *passwd);

#endif /* BRUTE_FORCE_H */