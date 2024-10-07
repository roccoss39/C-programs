#include "Circle.h"
#include <stdlib.h>
#include <stdio.h>

circle_t *circle_create(const uint32_t radius)
{
    circle_t *circle = (circle_t *)malloc(sizeof(circle_t));
    if (circle == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory for circle.\n");
        return NULL;
    }

    circle->radius = radius;
    return circle;
}

void circle_print(void *circle)
{
    if (circle == NULL)
    {
        fprintf(stderr, "Error: Unable to print. Invalid circle.\n");
        return;
    }

    circle_t *_circle = (circle_t *)circle;
    printf("Circle radius: %d\n", _circle->radius);
}

void circle_destroy(void *circle)
{
    if (circle == NULL)
    {
        fprintf(stderr, "Error: Unable to destroy.\n");
        return;
    }
    free(circle);
}
