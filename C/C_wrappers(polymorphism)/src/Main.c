#include <stdio.h>
#include "Wrapper.h"
#include "Circle.h"
#include "Rectangle.h"

#define NUM_SHAPES 7

int main()
{
    shape_t *shapes[NUM_SHAPES];
    for (int i = 0; i < NUM_SHAPES; i++)
    {
        if (i % 2 == 0)
        {
            rectangle_t *rect = rectangle_create((i + 1) * 2, (i + 1) * 3);
            shapes[i] = shape_create(rect, rectangle_print, rectangle_destroy);
        }
        else
        {
            circle_t *circle = circle_create(i + 1);
            shapes[i] = shape_create(circle, circle_print, circle_destroy);
        }
    }

    for (int i = 0; i < NUM_SHAPES; i++)
    {
        shape_print(shapes[i]);
    }
    for (int i = 0; i < NUM_SHAPES; i++)
    {
        shape_destroy(shapes[i]);
    }
}