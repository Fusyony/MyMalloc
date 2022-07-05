/*
    Main file
*/

#include "../include/malloc_lib.h"

void *malloc(size_t size)
{
    block_t *block = get_block();
    check_space(block, size);

    my_putnbr(block->sizeleft);

    (void) size;

    return (NULL);
}