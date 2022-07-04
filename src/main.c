/*
    Main file
*/

#include "../include/malloc_lib.h"

void *malloc(size_t size)
{
    block_t **block = get_block();

    init_block(block);
    return (NULL);
}