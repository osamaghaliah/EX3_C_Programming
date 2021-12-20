CC=gcc
FLAGS=-Wall -g
EXE=stringProg
OBJECTS_MAIN=main.c

all: $(EXE)
$(EXE): $(OBJECTS_MAIN)
	$(CC) $(OBJECTS_MAIN) -o $(EXE)

.PHONY: clean all
clean:
	rm -f *.o stringProg $(EXE)