# include "arena.h"
# include <limits.h>
# include <stdlib.h>

unsigned char arena[BLOCKSIZE*NUM_BLOCKS]; 
unsigned short allocated_map[NUM_BLOCKS/16];

void* allocate(void) {
    /* freies Bit suchen */
    int fbitIndex;
    int block;

    for (block=0; block < NUM_BLOCKS; ++block) {
        if (allocated_map[block] == USHRT_MAX) continue;

        for (fbitIndex=0; fbitIndex < 16; ++fbitIndex) {
            unsigned short test = allocated_map[block] & ((unsigned short)1 << fbitIndex);

            if (test == 0) {
                allocated_map[block] = allocated_map[block] | ((unsigned short)1 << fbitIndex);
                printf("Debug from allocate():\n");
                dprint(block*16+fbitIndex);
                dprint(allocated_map[block]);
                printf("\n");
                return arena + (block*16 + fbitIndex)*BLOCKSIZE;
            }
        }
    }

    return NULL;
}

void deallocate(void *data) {
    /* obige Formel rückgängig machen und Block (also index für allocated_map suchen)
     * Wenn Block gefunden, Index des gewählten Bits finden */
    int block = ((unsigned char*)data - arena)/(BLOCKSIZE*16);
    int fbitIndex = (((unsigned char*)data - arena)/BLOCKSIZE) - block * 16;

    unsigned short mask = 1;
    mask = mask << fbitIndex;

    allocated_map[block] &= ~mask;
}

void* newArena(int blocksize, int numblocks) {}

void freeArena(void* arena) {}

void allocateEx(void* arena) {}

void deallocateEx(void* arena, void* data) {}
