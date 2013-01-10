SHELL=/bin/sh
CC=/usr/bin/gcc -g

#CFLAGS = -DMY_ATOI

CAPREV_SRC = cap_rev.c
CAPREV_OBJ = $(CAPREV_SRC:%.c=%.o)

ATOI_HDR = atoi.h
ATOI_SRC = $(ATOI_HDR:%h=%c) test_atoi.c
ATOI_OBJ = $(ATOI_SRC:%.c=%.o)

TARGETS=cap_rev test_atoi

all: $(TARGETS)

debug: CFLAGS += -g
debug:
	for i in $(TARGETS) ; do touch $$i.c ; done

cap_rev: $(CAPREV_OBJ)
	$(CC) -o cap_rev $(CAPREV_OBJ)

test_atoi: $(ATOI_OBJ)
	$(CC) -o test_atoi $(ATOI_OBJ)

clean:
	rm -f $(CAPREV_OBJ) $(ATOI_OBJ) $(TARGETS)
