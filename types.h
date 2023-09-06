/**
 * Hlavičkový soubor types.h
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */
#include <stdbool.h>

#ifndef TYPES_H
#define TYPES_H


typedef struct {
    int *items;
    int size;
} Vector;


// DEKLAROVANÉ HLAVIČKY FUNKCÍ NIJAK NEMĚŇTE

void vector_print(Vector *v);

Vector *vector_ctor(void);

void vector_dtor(Vector **vector);

int vector_resize(Vector *v, int new_size);

int vector_expand(Vector *vec, int value);

#endif
