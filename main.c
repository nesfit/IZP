#include "types.h"
#include <stdio.h>
#include <stdlib.h>

ull fib_calls = 0;
ull fib_fast_calls = 0;

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
ull fib(ull n) {
  fib_calls++; // KEEP THIS LINE FIRST IN THIS FUNCTION.

  // TODO: Implement this function.
  return -1;
}

/**
 * Compute the nth number of the Fibonacci sequence.
 * Use a static/global array of intermediate results to speed up computation.
 *
 * @param n Index of the number in the Fibonacci sequence.
 *
 * @return nth number of the Fibonacci sequence.
 */
ull fib_fast(ull n) {
  fib_fast_calls++; // KEEP THIS LINE FIRST IN THIS FUNCTION.

  // TODO: Implement this function.
  return -1;
}

#ifndef TEST_BUILD

/**
 * Program entry point.
 *
 * @param argc Number of command-line arguments.
 * @param argv Command-line arguments.
 *
 * @return Program exit status.
 */
int main(int argc, char **argv) {
  ull n;
  printf("fibonacci number index: ");
  scanf("%llu", &n);
  putchar('\n');

  printf("fib_fast(%llu) = %llu\n", n, fib_fast(n));
  printf("number of calls = %llu\n", fib_fast_calls);
  putchar('\n');

  printf("fib(%llu) = %llu\n", n, fib(n));
  printf("number of calls = %llu\n", fib_calls);
  return 0;
}

#endif
