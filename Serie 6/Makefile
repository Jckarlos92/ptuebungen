# AP 15-sep-12 Examples for Unit 9
#
#
SHELL=/bin/sh

TARGETS=getint.o strlen.o textstore strcpy.o lensort strsort textstore2

all: $(TARGETS)

textstore.c: alloc.h
alloc.c: alloc.h


textstore: textstore.o alloc.o
	$(CC) -o textstore textstore.o alloc.o

clean: 
	rm -f $(TARGETS)
	rm -f *.o
	rm -f *.s
	rm -rf *.dSYM

debug:
	make CFLAGS=-g all

