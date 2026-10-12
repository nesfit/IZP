/**
 * @file types.h
 * Header file.
 *
 * Do not modify this file.
 */

#ifndef TYPES_H
#define TYPES_H

// Do not change the declared function signatures.

/**
 * Print the array contents to standard output.
 * Print all elements on one line; no particular separator is required.
 *
 * Do not change any function signatures!
 *
 * @param array Array to print.
 * @param size Array size.
 */
void array_print(int array[], int size);

/**
 * Multiply all elements of the given array by the chosen value.
 *
 * Do not change any function signatures!
 *
 * @param array Array whose values will be multiplied.
 * @param size Array size.
 * @param multiplier Multiplier.
 */
void array_multiply(int *array, int size, int multiplier);

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
int array_insert(int array[], int size, int value, int position);

#endif
