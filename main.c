#include "types.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef TEST_BUILD

/**
 * Program entry point.
 *
 * @param argc Number of command-line arguments.
 * @param argv Command-line arguments.
 *
 * @return Program exit status.
 */
int main(int argc, char *argv[]) {
  // TODO: 1. Read nonzero integer values in an infinite loop and add each to
  // the vector.
  //   A zero value ends the input loop.

  // TODO: 2. Print the vector contents and its total size by calling
  // `vector_print`.

  // TODO: 3. Free the allocated memory.

  return 0;
}

#endif

/**
 * Dynamically allocate and initialize a new zero-size vector on the heap.
 *
 * Hint: malloc, sizeof
 *
 * @return Pointer to the allocated memory on success, `NULL` otherwise.
 */
Vector *vector_ctor(void) {
  // TODO: Implement this function.
  return NULL;
}

/**
 * Destroy the given vector by freeing its allocated memory, including
 * its array of components.
 * Set the pointer to the original vector to `NULL` after freeing it.
 *
 * Hint: free
 *
 * @param v Pointer to a pointer to an existing vector.
 */
void vector_dtor(Vector **v) {
  // TODO: Implement this function.
}

/**
 * Print the vector (its size and all elements) to standard output.
 *
 * @param v Pointer to the vector.
 */
void vector_print(Vector *v) {
  // TODO: Implement this function.
}

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
bool vector_resize(Vector *v, int new_size) {
  // TODO: Implement this function.
  return -1;
}

/**
 * Increase the vector size by one and add one new component.
 * Update the array of components and the vector size accordingly.
 *
 * Hint: vector_resize
 *
 * @param v Pointer to an existing vector.
 * @param value Component to add to the vector.
 *
 * @return `true` if the component is added successfully, `false` otherwise.
 */
bool vector_expand(Vector *v, int value) {
  // TODO: Implement this function.
  return -1;
}
