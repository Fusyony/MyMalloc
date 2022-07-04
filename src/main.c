/*
    Main file
*/

#include "unistd.h"
#include "string.h"

void *malloc(size_t size)
{
    char *str = "this is in developement\n";
    (void) size;

    write(1, str, strlen(str));
    return (0);
}