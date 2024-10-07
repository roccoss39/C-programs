
#ifndef WRAPPER_H
#define WRAPPER_H

typedef struct
{
    void *vp_shape;
    void (*print)(void *);
    void (*destroy)(void *);
} shape_t;

shape_t *shape_create(void *vp_shape, void (*print)(void *), void (*destroy)(void *));
void shape_print(shape_t *shape);
void shape_destroy(shape_t *shape);

#endif