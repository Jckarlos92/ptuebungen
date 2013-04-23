
OBJ=arena.o allocate.o

libarena.a: $(OBJ)
	ar rcs $@ $(OBJ)

arena.o:	arena.h
allocate.o:	allocate.h

clean:
	rm -f arena.o allocate.o libarena.a

