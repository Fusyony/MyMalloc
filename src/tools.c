
#include "../include/malloc_lib.h"

void my_putchar(int c)
{
    write(1, &c, 1);
}

void printnbr(size_t nbr)
{
    if (nbr > 9) {
        printnbr(nbr / 10);
        printnbr(nbr % 10);
    }
    else {
        my_putchar((int) nbr + '0');
    }
}

void my_putnbr(size_t nbr)
{
    printnbr(nbr);
    my_putchar('\n');
}

void my_putstr(char *str)
{
    size_t len = 0;

    for (; str[len]; len++);
    write(1, str, len);
}

ssize_t write_ptr(void *p) 
{
    intptr_t x = (intptr_t)p;
    char buf[2 + sizeof(x) * 2];
    size_t i;
    ssize_t ret;

    buf[0] = '0';
    buf[1] = 'x';
    for (i = 0; i < sizeof(x) * 2; i++) {
        buf[i + 2] = "0123456789abcdef"[(x >> ((sizeof(x) * 2 - 1 - i) * 4)) & 0xf];
    }
    ret = write(1, buf, sizeof(buf));
    my_putchar('\n');
    return (ret);
}