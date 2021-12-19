CC=gcc
FLAGS= -Wall -g
EXE = stringProg
OBJECTS_MAIN=main.o

#target commands
all: $(EXE)
$(EXE): $(OBJECTS_MAIN) 
	$(CC) $(OBJECTS_MAIN) -o $(EXE)
main.o: main.c func.h  
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all
clean:
	rm -f *.o stringProg