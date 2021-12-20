CC=gcc
FLAGS=-Wall -g
EXE=stringProg
OBJECTS_MAIN=main.o

#target commands
all: $(EXE)
$(EXE): $(OBJECTS_MAIN)
	$(CC) $(FLAGS) $(OBJECTS_MAIN) -o $(EXE)
$(OBJECTS_MAIN): main.c
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all
clean:
	rm -f *.o $(EXE)