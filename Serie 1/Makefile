SHELL=/bin/sh
CC=/usr/bin/gcc
OBJ=arena.o
LIBARENA=.
LDFLAGS=--static -L$(LIBARENA) -larena

all: libarena.a testapp

libarena.a: $(OBJ)
	ar rcs $@ $(OBJ)

arena.o: arena.h

testapp: libarena.a
testapp: testapp.o

clean:
	rm -f arena.o allocate.o libarena.a testapp

