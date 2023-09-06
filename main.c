#include "types.h"
#include <stdio.h>
#include <stdlib.h>


ull fib_calls = 0;
ull fib_fast_calls = 0;

/**
 * Vypočítá n-té číslo Fibonnacciho posloupnosti.
 * 
 * Fib(n) = 
 *  0                     n = 0
 *  1                     n = 1
 *  fib(n-1) + fib(n-2)   n > 1
 * 
 * @param n  Index čísla Fibonacciho posloupnosti
 * 
 * @returns n-té číslo Fibonacciho posloupnosti
 */
ull fib(ull n)
{
  fib_calls++;
  return -1;
}

/**
 * Vypočítá n-té číslo Fibonnacciho posloupnosti.
 * Využijte statického/globálního pole s mezivýsledky k urychlení výpočtů.
 * 
 * @param n  Index čísla Fibonacciho posloupnosti
 * 
 * @returns n-té číslo Fibonacciho posloupnosti
 */
ull fib_fast(ull n)
{
  fib_fast_calls++;
  return -1;
}

#ifndef TEST_BUILD

int main(int argc, char **argv)
{
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
