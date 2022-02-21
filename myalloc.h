#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define PTR_OFFSET(p, offset) ((void*)((char *)(p) + (offset)))
#define ALIGNMENT 16   // Must be power of 2
#define GET_PAD(x) ((ALIGNMENT - 1) - (((x) - 1) & (ALIGNMENT - 1)))
#define PADDED_SIZE(x) ((x) + GET_PAD(x))
#define PADDED_BLOCK_SIZE ( (int) PADDED_SIZE(sizeof(block)) )

#define TOTAL_PADDING (PADDED_BLOCK_SIZE + PADDED_SIZE())

typedef struct block {
    struct block *next;
    int size;     // Bytes
    int in_use;   // Boolean
} block;

void *myalloc(int);
void print_data(void);


