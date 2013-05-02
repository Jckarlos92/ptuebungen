# include "arena.h"
# include <limits.h>
# include <stdlib.h>

struct ArenaElem {
    unsigned char* memory;
    unsigned short* allocated_map;
    int blocksize;
    int numblocks;
    struct ArenaElem* next;
} *arenaListBegin = NULL;

unsigned char arena[BLOCKSIZE*NUM_BLOCKS]; 
unsigned short allocated_map[NUM_BLOCKS/16];

/* hilfsfunktion fürs aufrunden
 * damit sparen wir die Abhängigkeit von der C-Mathebibliothek */
static int nexthigher(float c) {
    int ci = (int) c;

    return ((float)ci == c)?ci:ci+1;
}

static void* allocateByArgs(unsigned char* arenamem, int bsize, unsigned short* allocated_map, int nblocks) {
    int fbitIndex;
    int block;

    for (block=0; block < nblocks; ++block) {
        if (allocated_map[block] == USHRT_MAX) continue;

        /* freies Bit suchen */
        for (fbitIndex=0; fbitIndex < 16; ++fbitIndex) {
            unsigned short test = allocated_map[block] & ((unsigned short)1 << fbitIndex);

            if (test == 0) {
                allocated_map[block] = allocated_map[block] | ((unsigned short)1 << fbitIndex);
                return arenamem + (block*16 + fbitIndex)*bsize;
            }
        }
    }

    return NULL;
}

static void deallocateByArgs(unsigned char* data, unsigned char* arenamem, int bsize, unsigned short* amap) {
    /* obige Formel rückgängig machen und Block (also index für allocated_map suchen)
     * Wenn Block gefunden, Index des gewählten Bits finden */
    int block = (data - arenamem)/(bsize*16);
    int fbitIndex = ((data - arenamem)/bsize) - block * 16;

    unsigned short mask = 1;
    mask = mask << fbitIndex;

    amap[block] &= ~mask;
}

void* allocate(void) {
    return allocateByArgs(arena, BLOCKSIZE, allocated_map, NUM_BLOCKS);
}

void deallocate(void* data) {
    deallocateByArgs((unsigned char*)data, arena, BLOCKSIZE, allocated_map);
}

void* newArena(int blocksize, int numblocks) {
    struct ArenaElem* arena = arenaListBegin;

    if (arena) {
        /* letztes Listenelement finden */
        while (arena->next) arena = arena->next;
        /* letztes Listenelement mit Speicher versehen */
        arena->next = (struct ArenaElem*)malloc(sizeof(struct ArenaElem));
        arena = arena->next;
    } else {
        arena = (struct ArenaElem*)malloc(sizeof(struct ArenaElem));
    }

    if (!arena) return NULL;

    arena->memory = (unsigned char*)malloc(numblocks);
    if (!arena->memory) return NULL;

    arena->allocated_map = (unsigned short*)malloc(sizeof(unsigned short) * (nexthigher(numblocks/16)));
    if (!arena->allocated_map) return NULL;

    arena->next      = NULL;
    arena->numblocks = numblocks;
    arena->blocksize = blocksize;

    return (void*)arena;
}

void freeArena(void* arena) {
    struct ArenaElem* prevToArgArena = arenaListBegin;
    struct ArenaElem* argArena = (struct ArenaElem*) arena;

    /* Arena, die in der Liste vor der Arena aus dem Argument liegt, finden */
    while (prevToArgArena && prevToArgArena->next != argArena) prevToArgArena = prevToArgArena->next;

    if (!prevToArgArena) return;

    /* selbst wenn argArena die letzte Arena in der Liste sein sollte, ist das kein Problem
     * weil deren next-Pointer auch auf NULL gesetzt wurde */
    prevToArgArena->next = argArena->next;

    free(argArena->allocated_map);
    free(argArena->memory);
    free(argArena);
}

void* allocateEx(void* arena) {
    struct ArenaElem* a = (struct ArenaElem*)arena;
    return allocateByArgs(a->memory, a->blocksize, a->allocated_map, a->numblocks);
}

void deallocateEx(void* arena, void* data) {
    struct ArenaElem* a = (struct ArenaElem*)arena;
    deallocateByArgs((unsigned char*) data, a->memory, a->blocksize, a->allocated_map);
}
