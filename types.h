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
int *resize(int *arr, unsigned int new_size);
void vector_print(Vector *v);
Vector *vector_ctor();
void vector_dtor(Vector *vector);
int vector_add(Vector *vec, int value);

#endif
