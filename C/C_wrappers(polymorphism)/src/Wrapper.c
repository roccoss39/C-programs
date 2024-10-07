#include "Wrapper.h"
#include <stdlib.h>

shape_t *shape_create(void *_vp_shape, void (*_print)(void *), void (*_destroy)(void *))
{
    shape_t *shape = (shape_t *)malloc(sizeof(shape_t));
    if (shape != NULL)
    {
        shape->vp_shape = _vp_shape;
        shape->print = _print;
        shape->destroy = _destroy;
    }
    return shape;
}

void shape_print(shape_t *_shape)
{
    if (_shape != NULL && _shape->print != NULL)
    {
        _shape->print(_shape->vp_shape);
    }
}

void shape_destroy(shape_t *_shape)
{
    if (_shape != NULL && _shape->destroy != NULL)
    {
        _shape->destroy(_shape->vp_shape);
    }
    free(_shape);
}