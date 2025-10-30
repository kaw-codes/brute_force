## Synopsis
A cybersecurity-related project about brute-force attack.

Here is 3 way to use this project:

### 1. GENERATOR MODE: 

    ./brute_force [-h|-t|-zSIZE]`

`to generate and print all the possible combinations of characters`
- `-h --help` : displays help and exit
- `-t --time` : gives you the time spent to generate
- `-z[N] --size[=N]` : set the generation's max size (default : will automaticaly increment the size without ending)

### 2. CRACKER MODE: 

    ./brute_force -c PASSWD [-h]

`to crack the password you enter and to tell you the time spent`

`-h --help` : displays help and exit

### 3. SIMULATE AN ATTACK MODE: 

    ./brute_force [-zSIZE] | ./vulnerable_app

OR

    make attack [SIZE=N]

`to simulate an attack on a vulnarable program 'vulnarable_app' by trying to find the secret password by testing every possibilites`

## Files

- `src/brute_force.c`: contains brute_force algorithms
- `src/main.c`: contains options parsing and main code

## Skills acquired
- options parsing
- usage of .clangformat
- usage of Makefile

## Notes

### 1. The speed problem
In the brute_force algorithm, i did not understand at first why my generator mode was twice slower than my cracker mode.

I finally noticed than the problem was related to the fact that I was printing a '\n' after every combination. As my vulnerable_app is asking for a prompt to the user, I had no choice to keep every '\n'.

But removing it, using a 95 letters alphabet and a 4 characters max size, let us wait for only ~60sec instead of ~174sec, which is significant.

### 2. ChatGPT bio label

Project guaranteed without any use of ChatGPT.
