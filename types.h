/**
 * @file types.h
 * Header file.
 *
 * Do not modify this file.
 */

#include <stdbool.h>

#ifndef TYPES_H
#define TYPES_H

// Do not change the declared function signatures.

/**
 * Get the largest value in the provided array.
 *
 * @note We assume the array is not empty!
 *
 * @param array Source integer array.
 * @param length Size of the array.
 *
 * @return The largest value in the provided array.
 */
int get_max(int array[], int length);

/**
 * Get the sum of all values in the provided array.
 *
 * @param array Source integer array.
 * @param length Size of the array.
 *
 * @return The sum of all values in the array.
 */
int get_sum(int array[], int length);

/**
 * Check that for all indices (plural of index), array1 has smaller values
 * than array2.
 *
 * Example:
 * arr1: [2, 4, 1, 10, -5]
 * arr2: [8, 9, 2, 99, -1]
 *        ^  ^  ^  ^^  ^^
 *
 * Example:
 * arr1: [2, 4, 9, 10, -5]
 * arr2: [8, 9, 2, 99, -1]
 *        ^  ^  x
 *
 * @note We assume the arrays are of the same length!
 *
 * @param array1 First integer array.
 * @param array2 Second integer array.
 * @param array_length Length of both arrays.
 *
 * @return `true` when all values at all indices of array1 are smaller than
 *    the corresponding values from array2; `false` otherwise.
 */
bool values_are_smaller_than(int array1[], int array2[], int array_length);

#endif
