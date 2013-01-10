# AP 30-Aug-2012 Makefile
#
SHELL=/bin/sh
CC=/usr/bin/gcc -g

DEPENDFILE=.depend

HDR = invert.h
SRC = $(HDR:%h=%c) cap_rev.c
OBJ = $(SRC:%.c=%.o)

TARGETS=cap_rev invert

all: $(TARGETS)

debug:
	for i in $(TARGETS) ; do touch $$i.c ; done
	make CFLAGS=-g all


cap_rev: $(OBJ)
	make dep
	$(CC) -o cap_rev $(OBJ)

invert: cap_rev
	ln -f cap_rev invert

dep: $(SRC) $(HDR) 
	$(CC) -MM $(SRC) > $(DEPENDFILE)

clean:
	rm -f $(OBJ) numbers fac fib $(DEPENDFILE)

-include $(DEPENDFILE)
