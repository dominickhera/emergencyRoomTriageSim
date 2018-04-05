cc = gcc
FILE = src/
OBJFILE = bin/
CFLAGS = -std=c99 -Wall -g -pedantic
EXE = run

all: $(EXE)

$(EXE): BIN OBJ main.o heap.o functions.o
	gcc ./obj/main.o ./obj/heap.o ./obj/functions.o -lncurses -o $(OBJFILE)$(EXE)

BIN:
	if [ ! -d "bin" ]; then mkdir bin; fi;

OBJ:
	if [ ! -d "obj" ]; then mkdir obj; fi;

cppcheck:
	cppcheck --enable=all --language=c --std=c99 --inconclusive --suppress=missingInclude src/*.c -i ./include

main.o: ./src/main.c
	$(CC) -c $(CFLAGS) ./src/main.c -I./include -o ./obj/main.o

heap.o: ./src/heap.c
	$(CC) -c $(CFLAGS) ./src/heap.c -I./include -o ./obj/heap.o

functions.o: ./src/functions.c
	$(CC) -c $(CFLAGS) ./src/functions.c -I./include -o ./obj/functions.o

doxy: Doxyfile
	doxygen

clean:
	rm -rf bin obj
