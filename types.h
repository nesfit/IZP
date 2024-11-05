/**
 * Hlavičkový soubor types.h
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef TYPES_H
#define TYPES_H


typedef struct {
    int *items;
    int size;
} Vector;


// DEKLAROVANÉ HLAVIČKY FUNKCÍ NIJAK NEMĚŇTE

void vector_print(Vector *v);

bool vector_ctor(Vector *v, unsigned int size);

void vector_init(Vector *v);

void vector_dtor(Vector *v);

void vector_scalar_multiply(Vector *v, int scalar);

bool vector_add(Vector *v1, Vector *v2);

bool vector_sub(Vector *v1, Vector *v2);

#endif
