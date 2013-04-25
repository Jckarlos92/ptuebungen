/* Header file for a well-known arena of memory. */
#ifndef _ARENA_H
#define _ARENA_H

#define BLOCKSIZE 40
#define NUM_BLOCKS 1024

/*extern unsigned char arena[BLOCKSIZE*NUM_BLOCKS];
extern unsigned short allocated_map[NUM_BLOCKS/16];*/

extern void* allocate(void);
extern void deallocate(void *data);

extern void* newArena(int blocksize, int numblocks);
extern void freeArena(void* arena);

extern void allocateEx(void* arena);
extern void deallocateEx(void* arena, void* data);

#endif
