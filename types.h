/**
 * @file types.h
 * Header file.
 *
 * Do not modify this file.
 */

#include <stdbool.h>

#ifndef TYPES_H
#define TYPES_H

typedef struct {
  int *items;
  int size;
} Vector;

// Do not change the declared function signatures.

/**
 * Dynamically allocate and initialize a new zero-size vector on the heap.
 *
 * Hint: malloc, sizeof
 *
 * @return Pointer to the allocated memory on success, `NULL` otherwise.
 */
Vector *vector_ctor(void);

/**
 * Destroy the given vector by freeing its allocated memory, including
 * its array of components.
 * Set the pointer to the original vector to `NULL` after freeing it.
 *
 * Hint: free
 *
 * @param vector Pointer to a pointer to an existing vector.
 */
void vector_dtor(Vector **vector);

/**
 * Change the vector size to the newly specified size.
 * Update the array of components and the vector size accordingly.
 *
 * Hint: realloc, sizeof
 *
 * @param v Pointer to an existing vector.
 * @param new_size New vector size (number of components).
 *
 * @return `true` if resizing succeeds, `false` otherwise.
 */
bool vector_resize(Vector *v, int new_size);

/**
 * Increase the vector size by one and add one new component.
 * Update the array of components and the vector size accordingly.
 *
 * Hint: vector_resize
 *
 * @param vec Pointer to an existing vector.
 * @param value Component to add to the vector.
 *
 * @return `true` if the component is added successfully, `false` otherwise.
 */
bool vector_expand(Vector *vec, int value);

#endif
