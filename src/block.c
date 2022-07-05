/*
## Block manangement file
*/

#include "../include/malloc_lib.h"

block_t *get_block(void)
{
    static block_t *block = NULL;

    write_ptr(block);

    if (block == NULL)
        init_block(&block);
    return (block);
}

void init_block(block_t **block)
{
    (*block) = sbrk(sizeof(block_t));
    (*block)->sizeleft = 0;
    (*block)->start = NULL;
}

void check_space(block_t *block, size_t size)
{
    if (block->sizeleft < (sizeof(node_t) + size)) {
        append_space(block, size);
    }
}

void append_space(block_t *block, size_t size)
{
    intptr_t append_size = 0;

    while (append_size < (intptr_t) size) {
        append_size += (intptr_t) getpagesize();
    }
    sbrk(append_size);
    block->sizeleft += (size_t) append_size;
    my_putstr("append space\n");
}