# AP 30-Aug-2012 Makefile
#
SHELL=/bin/sh
CC=/usr/bin/gcc -g

DEPENDFILE=.depend

HDR = fib.h fac.h sqr.h
SRC = $(HDR:%h=%c) numbers.c
OBJ = $(SRC:%.c=%.o)

TARGETS=numbers fib fac sqr

all: $(TARGETS)

numbers: $(OBJ)
	make dep
	$(CC) -o numbers $(OBJ)

fac: numbers
	ln -f numbers fac

fib: numbers
	ln -f numbers fib

sqr: numbers
	ln -f numbers sqr

dep: $(SRC) $(HDR) 
	$(CC) -MM $(SRC) > $(DEPENDFILE)

clean:
	rm -f $(OBJ) numbers fac fib sqr $(DEPENDFILE)

-include $(DEPENDFILE)
