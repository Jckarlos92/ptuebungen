SHELL=/bin/sh
CC=/usr/bin/gcc

CLFAGS = -Wall
#CFLAGS += -DMY_ATOI

CAPREV_SRC = cap_rev.c
CAPREV_OBJ = $(CAPREV_SRC:%.c=%.o)

ATOI_HDR = atoi.h
ATOI_SRC = $(ATOI_HDR:%h=%c) test_atoi.c
ATOI_OBJ = $(ATOI_SRC:%.c=%.o)

WC_SRC = wc.c
WC_OBJ = $(WC_SRC:%.c=%.o)

TARGETS=cap_rev test_atoi wc

all: $(TARGETS)

debug: CFLAGS += -g
debug: $(TARGETS)

cap_rev: $(CAPREV_OBJ)
	$(CC) $(CAPREV_OBJ) -o cap_rev

test_atoi: $(ATOI_OBJ)
	$(CC) $(ATOI_OBJ) -o test_atoi 

wc: $(WC_OBJ)
	$(CC) $(WC_OBJ) -o wc 

clean:
	rm -f $(CAPREV_OBJ) $(ATOI_OBJ) $(WC_OBJ) $(TARGETS)
