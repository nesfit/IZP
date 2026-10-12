/**
 * @file types.h
 * Header file.
 *
 * Do not modify this file.
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

// Do not change the declared function signatures.

/**
 * Print the vector (its size and elements) to standard output.
 *
 * @param v Pointer to the vector.
 */
void vector_print(Vector *v);

/**
 * Create (dynamically allocate) a vector of the specified dimension.
 * Store the newly allocated memory and corresponding number of elements
 * in the structure through the pointer v.
 *
 * @param v Pointer to the vector structure.
 * @param size Number of vector elements (dimension).
 *
 * @return `true` on successful allocation, `false` otherwise.
 */
bool vector_ctor(Vector *v, unsigned int size);

/**
 * Initialize the vector elements to a numeric sequence
 * from 0 to the vector size - 1.
 *
 * Example:
 *   Vector3 [0, 1, 2]
 *   Vector5 [0, 1, 2, 3, 4]
 *
 * @param v Pointer to an existing vector.
 */
void vector_init(Vector *v);

/**
 * Destroy the given vector (free its allocated memory).
 * The destroyed vector's element pointer is `NULL`.
 * The destroyed vector's dimension is 0.
 *
 * @param v Pointer to an existing vector.
 */
void vector_dtor(Vector *v);

/**
 * Multiply the vector by the given scalar.
 * Perform the calculation on the values of the provided vector v,
 * in place, without allocating a new vector.
 *
 * @param v Pointer to an existing vector.
 * @param scalar Scalar value.
 */
void vector_scalar_multiply(Vector *v, int scalar);

/**
 * Add two vectors: v1 + v2.
 * Perform the calculation on the values of the provided vector v1,
 * in place, without allocating a new vector.
 *
 * Check the dimensions of both vectors!
 * The operation cannot be performed on vectors of different dimensions.
 *
 * @param v1 Pointer to the first vector.
 * @param v2 Pointer to the second vector.
 *
 * @return `true` on successful addition, `false` otherwise.
 */
bool vector_add(Vector *v1, Vector *v2);

/**
 * Subtract two vectors: v1 - v2.
 * Perform the calculation on the values of the provided vector v1,
 * in place, without allocating a new vector.
 *
 * Check the dimensions of both vectors!
 * The operation cannot be performed on vectors of different dimensions.
 *
 * @param v1 Pointer to the first vector.
 * @param v2 Pointer to the second vector.
 *
 * @return `true` on successful subtraction, `false` otherwise.
 */
bool vector_sub(Vector *v1, Vector *v2);

#endif
