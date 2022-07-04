/*
## Lib for MyMalloc
*/

#include <unistd.h>
#include <string.h>

typedef struct block_s block_t;

struct block_s {
    int sizeleft;
    void *start;
};

/*  block.c */
block_t **get_block(void);
void init_block(block_t **block);