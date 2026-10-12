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
 * Determine whether the provided character is alphabetic.
 *
 * @param c Character.
 *
 * @return `true` when the provided character `c` is alphabetic; `false`
 * otherwise.
 */
bool is_alpha(char c);

/**
 * Determine whether all characters of the provided `arr` (character array) are
 * alphabetic.
 *
 * @param arr Input string.
 *
 * @return `true` when all characters in the provided string are alphabetic;
 * `false` otherwise.
 */
bool is_name(char arr[]);

#endif
