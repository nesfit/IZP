/**
 * @file types.h
 * Header file.
 *
 * Do not modify this file.
 */

#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>

// Do not change the declared function signatures.

/**
 * Calculate `dividend / divisor`.
 * Return the result through the `quotient` pointer.
 *
 * The function must not print anything!
 *
 * @param dividend Dividend.
 * @param divisor Divisor.
 * @param quotient Pointer to the quotient (result).
 *
 * @return `true` on successful division, `false` otherwise.
 */
bool divide(int dividend, int divisor, double *quotient);

#endif
