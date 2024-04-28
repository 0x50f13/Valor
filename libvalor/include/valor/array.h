#ifndef array_h
#define array_h

#include <sys/types.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    size_t sz;
    size_t capacity;
    void **base;
} array_t;

array_t *array_create(size_t capacity);

void array_add(array_t *_array, void *object);

void array_free(array_t *_array);

bool in_array(array_t *_array, void *object);

#endif /* array_h */
