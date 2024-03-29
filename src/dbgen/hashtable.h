#ifndef hashtable_h
#define hashtable_h

#include <sys/types.h>
#include <stdbool.h>

#include "array.h"

//string hashtable implementation

typedef struct __hashtable_node {
    char *key;
    void *value;
    struct __hashtable_node *next;
} _hashtable_node;

typedef struct {
    size_t sz;
    size_t capacity;
    _hashtable_node **base;
    array_t *keys;
    array_t *values;
} hashtable;

hashtable *hashtbl_create(size_t capacity);

void hashtbl_add(hashtable *tbl, char *key, void *data);

void *hashtbl_get(hashtable *tbl, char *key);

bool hashtbl_check_key(hashtable *tbl, char *key);

void hashtbl_destroy(hashtable *tbl);

#endif /* hashtable_h */
