# AP 15-sep-12 Examples for Unit 9
#
#
SHELL=/bin/sh

CC=/usr/bin/gcc
CFLAGS=-Wall

STACK_HDR=i2stack.h
STACK_SRC=$(STACK_HDR:%.h=%.c) test2stack.c
STACK_OBJ=$(STACK_SRC:%.c=%.o)

TARGETS = test2stack strsort

all: $(TARGETS)

test2stack: $(STACK_OBJ)
	$(CC) $(CFLAGS) $(STACK_OBJ) -o test2stack

clean: 
	rm -f $(TARGETS)
	rm -f *.o
	rm -f *.s
	rm -rf *.dSYM
