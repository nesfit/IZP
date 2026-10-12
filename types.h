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
 * Check whether the value is in the supplied set.
 *
 * @param set Integer array representing a set.
 * @param length Length of the provided array.
 * @param value Value to be looked up in the set.
 *
 * @return `true` when the provided `value` is in `set`; `false` otherwise.
 */
bool is_in_set(int set[], int length, int value);

/**
 * Check whether the supplied array represents a set, i.e., whether every value
 * is unique.
 *
 * @param set Integer array representing a set.
 * @param length Length of the provided array.
 *
 * @return `true` when the provided `set` is an actual set; `false` otherwise.
 */
bool is_set(int set[], int length);

/**
 * Check whether the supplied array is a more effective representation of a set,
 * i.e., every value is unique and the values are sorted.
 *
 * @param set Integer array representing a set.
 * @param length Length of the provided array.
 *
 * @return `true` when every value in the provided set is unique and the values
 * are sorted; `false` otherwise.
 */
bool is_sorted_set(int set[], int length);

/**
 * Print the intersection of set1 and set2.
 *
 * @param set1 First integer array representing a set.
 * @param set2 Second integer array representing a set.
 * @param set1_length Length of the first provided array.
 * @param set2_length Length of the second provided array.
 */
void print_intersection(int set1[], int set2[], int set1_length,
                        int set2_length);

/**
 * Print the union of set1 and set2.
 *
 * @param set1 First integer array representing a set.
 * @param set2 Second integer array representing a set.
 * @param set1_length Length of the first provided array.
 * @param set2_length Length of the second provided array.
 */
void print_union(int set1[], int set2[], int set1_length, int set2_length);

/**
 * Print the Cartesian product of set1 and set2.
 *
 * @param set1 First integer array representing a set.
 * @param set2 Second integer array representing a set.
 * @param set1_length Length of the first provided array.
 * @param set2_length Length of the second provided array.
 */
void print_product(int set1[], int set2[], int set1_length, int set2_length);

#endif
