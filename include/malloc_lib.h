/*
## Lib for MyMalloc
*/

#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct block_s block_t;
typedef struct node_s node_t;

struct block_s {
    size_t sizeleft;
    void *start;
};

struct node_s {
    size_t size;
    bool free;
};

/*  block.c */

block_t *get_block(void);
void init_block(block_t **block);
void check_space(block_t *block, size_t size);
void append_space(block_t *block, size_t size);

/* tools.c */

void my_putchar(int c);
void printnbr(size_t nbr);
void my_putnbr(size_t nbr);
void my_putstr(char *str);
ssize_t write_ptr(void *p);