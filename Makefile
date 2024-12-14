SRCDIR=src
INCLUDEDIR=include
CFLAGS=-std=c11 -Wall -Wextra -g
CPPFLAGS=-I$(INCLUDEDIR)
SIZE?=2

all: vulnerable_app brute_force 

vulnerable_app: app/vulnerable_app.o
	$(CC) $(CFLAGS) -o vulnerable_app $^

app.o: app/vulnerable_app.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^
	
brute_force: $(SRCDIR)/brute_force.o $(SRCDIR)/main.o
	$(CC) $(CFLAGS) -o brute_force $^

main.o: $(SRCDIR)/main.c $(INCLUDEDIR)/main.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^

brute_force.o: $(SRCDIR)/brute_force.c $(INCLUDEDIR)/brute_force.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^

clean:
	@rm brute_force $(SRCDIR)/*.o
	@rm vulnerable_app app/*.o

attack:
	@./brute_force -z$(SIZE) | ./vulnerable_app

help:
	@echo creates binary files \'brute_force\' and \'vulnerable_app\'
	@echo you can attack the vulnerable_app by running:
	@echo "	- make attack [SIZE=N]"
	@echo "	- ./brute_force -zN | ./vulnerable_app"
	@echo run \'./brute_fore -h\' for more information

.PHONY: all clean attack help