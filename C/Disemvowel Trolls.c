#include <stdio.h>

#include <stdlib.h>

// solution must allocate all required memory
// and return a free-able buffer to the caller.

char *disemvowel(const char *str)
{
    int strMemory = 0;
    switch (*str++)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        strMemory++;
        break;

    default:
        break;
    }
    return calloc(1, 1);
}