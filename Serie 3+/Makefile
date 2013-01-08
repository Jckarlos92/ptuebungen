# AP 10-sep-12 Examples for Unit 8
#
#
SHELL=/bin/sh

TARGETS=nim2

all: $(TARGETS)

NIM2_HDR=nimIO.h nimData.h nimStrat.h
NIM2_SRC=nim2.c nimIO.c nimData.c nimStrat.c
NIM2_OBJ=$(NIM2_SRC:%.c=%.o)

DEPENDFILE=.depend
-include $(DEPENDFILE)

clean: 
	rm -f $(TARGETS)
	rm -f *.o
	rm -f *.s
	rm -rf *.dSYM
	rm -f $(DEPENDFILE)

dep: 
	$(CC) -MM $(NIM2_SRC) > $(DEPENDFILE)

nim2: $(NIM2_OBJ) 
	make dep
	make -s CFLAGS=$(CFLAGS) $(NIM2_OBJ)
	$(CC) -o $@ $(NIM2_OBJ)

debug:
	make CFLAGS=-g all

