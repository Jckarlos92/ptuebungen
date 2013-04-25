# include "arena.h"
# include <limits.h>
# include <stdlib.h>

unsigned char arena[BLOCKSIZE*NUM_BLOCKS]; 
unsigned short allocated_map[NUM_BLOCKS/16];

static int map_index = 0;

void* allocate(void) {
    /* ersten freien 16er Block finden */
/*    int i;
    for (i = 0; i < NUM_BLOCKS; ++i) {
        if (allocated_map[i] < USHRT_MAX) break;
    }*/

    if (map_index == NUM_BLOCKS) return NULL;

    void* block = malloc(BLOCKSIZE);

    /* prüfen ob Allokation erfolgreich */
    if (block) {
        allocated_map[map_index] << 1;
        allocated_map[map_index] & (short)1;

        if (allocated_map[map_index] == USHRT_MAX)
            ++map_index;
    }

    return block;
}

void deallocate(void *data) {
    if (!data) return;

    free(data);

    /* bit zurücksetzen in allocated_map */
    allocated_map[map_index] >> 1;

    if (allocated_map[map_index] == 0) --map_index;
}

