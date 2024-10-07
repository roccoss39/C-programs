#ifndef CIRCLE_H
#define CRICLE_H

#include <stdint.h>

typedef struct
{
    uint32_t radius;
} circle_t;

circle_t* circle_create(const uint32_t radius);
void circle_print(void* circle);
void circle_destroy(void* circle);

#endif 