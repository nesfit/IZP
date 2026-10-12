#include "types.h"
#include <stdio.h>

// fixed array size
#define ARR_SIZE 10

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
  // TODO: 0. Statically initialize the allocated array
  int array[ARR_SIZE];

  // TODO: 1b. Print the array by calling array_print

  // TODO: 2b. Multiply the array values by any number
  // TODO: 2c. Print the updated array

  // TODO: 3b. Insert any value at indices 3 and 7
  // TODO: 3c. Inform the user on error
  // TODO: 3d. Print the updated array

  return 0;
}

#endif

/**
 * Print the array contents to standard output.
 * Print all elements on one line; no particular separator is required.
 *
 * Do not change any function signatures!
 *
 * @param array Array to print.
 * @param size Array size.
 */
void array_print(int array[], int size) {
  // TODO: 1a. Implement this function.
}

/**
 * Multiply all elements of the given array by the chosen value.
 *
 * Do not change any function signatures!
 *
 * @param array Array whose values will be multiplied.
 * @param size Array size.
 * @param multiplier Multiplier.
 */
void array_multiply(int *array, int size, int multiplier) {
  // TODO: 2a. Implement this function.
}

/**
 * Insert an element into the given array at the chosen index.
 * Shift the other elements to the right, towards the end of the array.
 * Discard the excess element.
 *
 * Handle the values of relevant input parameters appropriately.
 *
 * Do not change any function signatures!
 *
 * @param array Array into which the new element will be inserted.
 * @param size Array size.
 * @param value Value to insert.
 * @param position Index at which to insert the value.
 *
 * @return 1 if insertion succeeds, 0 otherwise.
 */
int array_insert(int array[], int size, int value, int position) {
  // TODO: 3a. Implement this function.
  return -1;
}
