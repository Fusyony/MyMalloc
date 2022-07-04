/*
## Block manangement file
*/

#include "../include/malloc_lib.h"

block_t **get_block(void)
{
    static block_t *block = NULL;

    return (&block);
}

void init_block(block_t **block)
{
    if (*block == NULL) {
        sbrk(sizeof(block_t));
        (*block)->sizeleft = 0;
        (*block)->start = NULL;
    }
}