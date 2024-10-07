#include "Rectangle.h"
#include <stdlib.h>
#include <stdio.h>

rectangle_t *rectangle_create(const uint32_t width, const uint32_t heigth)
{
    rectangle_t *rect = (rectangle_t*)malloc(sizeof(rectangle_t));

    if (rect == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory for Rectangle.\n");
        return NULL;
    }
    rect->width = width;
    rect->heigth = heigth;

    return rect;
}

void rectangle_print(void *rect)
{
    if (rect == NULL)
    {
        fprintf(stderr, "Error: Unable to print. Invalid Rectangle.\n");
        return;
    }
    rectangle_t *rect_ = (rectangle_t*)rect;
    printf("Rectangle width: %d, height: %d\n", rect_->width, rect_->heigth);
}

void rectangle_destroy(void *rect)
{
    if (rect == NULL)
    {
        fprintf(stderr, "Error: Unable to destroy.\n");
        return;
    }
    free(rect);
}