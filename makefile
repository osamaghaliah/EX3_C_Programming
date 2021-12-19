CC=gcc
FLAGS= -Wall -g

#target commands
all: stringProg
stringProg: main.c
	$(CC) $(FLAGS) -o stringProg main.c func.h -lm -I.

.PHONY: clean all
clean:
	rm -f *.o stringProg