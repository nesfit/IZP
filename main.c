#include "types.h"
#include <stdio.h>

/**
 * Print 'Hello World' to stdout.
 */
void print_helloworld(void) {
  // TODO: 1. Print 'Hello World' to stdout.
  return;
}

#define A -4
#define B 2
#define C 3
/**
 * Calculate and print the discriminant.
 */
void print_discriminant(void) {
  // TODO: 1. Calculate and print the discriminant with the values defined above
  // to stdout.
  return;
}

/**
 * Read a number and print whether it is even.
 */
void read_print_is_even(void) {
  // TODO: 1. Read a number from stdin and output to stdout whether the read
  // number is even or not.
  return;
}

/**
 * Read an interval and a number, and print whether the number is in the
 * interval.
 */
void read_print_is_in_interval(void) {
  // TODO: 1. Read 2 numbers from stdin. These two numbers represent an
  // interval.

  // TODO: 2. Read a third number from stdin. Output to stdout whether the third
  // number is contained in the previously read interval.
  return;
}

/**
 * Read a year and determine whether it is a leap year.
 */
void read_print_is_leap_year(void) {
  // TODO: 1. Read a number representing a year from stdin.

  // TODO: 2. Determine whether the year is a leap year or not.
  return;
}

/**
 * Read three numbers and print the largest.
 */
void read_print_maximum(void) {
  // TODO: 1. Read 3 numbers from stdin.

  // TODO: 2. Output the largest of the read numbers to stdout.
  return;
}

#ifndef TEST_BUILD

/**
 * Program entry point.
 *
 * @return Program exit status.
 */
int main() {
  printf("\n--print_helloworld--\n");
  print_helloworld();

  printf("\n--print_discriminant--\n");
  print_discriminant();

  printf("\n--read_print_is_even--\n");
  read_print_is_even();

  printf("\n--read_print_is_in_interval--\n");
  read_print_is_in_interval();

  printf("\n--read_print_is_leap_year--\n");
  read_print_is_leap_year();

  printf("\n--read_print_maximum--\n");
  read_print_maximum();

  return 0;
}

#endif
