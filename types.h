/**
 * @file types.h
 * Header file.
 *
 * Do not modify this file.
 */

#ifndef TYPES_H
#define TYPES_H

// Do not change the declared function signatures.

typedef unsigned long long int ull;

extern ull fib_calls;
extern ull fib_fast_calls;

/**
 * Compute the nth number of the Fibonacci sequence.
 *
 * Fib(n) =
 *  0                     n = 0
 *  1                     n = 1
 *  fib(n-1) + fib(n-2)    n > 1
 *
 * @param n Index of the number in the Fibonacci sequence.
 *
 * @return nth number of the Fibonacci sequence.
 */
ull fib(ull n);

/**
 * Compute the nth number of the Fibonacci sequence.
 * Use a static/global array of intermediate results to speed up computation.
 *
 * @param n Index of the number in the Fibonacci sequence.
 *
 * @return nth number of the Fibonacci sequence.
 */
ull fib_fast(ull n);

#endif
