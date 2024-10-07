#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdint.h>

typedef struct
{
    uint32_t width;
    uint32_t heigth;
} rectangle_t;

rectangle_t* rectangle_create(const uint32_t width, const uint32_t height);
void rectangle_print(void* rect);
void rectangle_destroy(void* rect);

#endif