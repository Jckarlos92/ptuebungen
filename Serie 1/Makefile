SHELL=/bin/sh
CC=/usr/bin/gcc
OBJ=arena.o
LIBARENA=.

all: libarena.a testapp

libarena.a: $(OBJ)
	ar rcs $@ $(OBJ)

arena.o: arena.h

testapp: libarena.a
	$(CC) --static -I. -L$(LIBARENA) -o testapp testapp.c -larena 

clean:
	rm -f arena.o allocate.o libarena.a testapp

