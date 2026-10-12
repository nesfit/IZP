#include "types.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * Read the coefficients of an equation and print its roots when it is quadratic
 * and roots exist.
 */
void read_print_quadratic(void) {
  // TODO: 1. Read 3 numbers: a, b and c which represent the coefficients of a
  // quadratic equation in standard form (ax^2 + bx + c = 0) from stdin.

  // TODO: 2. Check whether the equation is quadratic. If so, calculate its
  // discriminant and, if possible, print all roots to stdout.
  return;
}

/**
 * Read a character and print whether it is a letter.
 */
void read_print_is_character(void) {
  // TODO: 1. Read one character from stdin.

  // TODO: 2. Determine whether the character represents a letter (a-z, A-Z) or
  // not and print the result to stdout.
  return;
}

/**
 * Read a number and print its factorial.
 */
void read_print_factorial(void) {
  // TODO: 1. Read one number from stdin.

  // TODO: 2. Print its factorial (!) to stdout.
  return;
}

/**
 * Read two numbers and print their greatest common divisor.
 */
void read_print_gcd(void) {
  // TODO: 1. Read two numbers from stdin.

  // TODO: 2. Calculate the greatest common divisor (gcd) of the two read
  // numbers and print it to stdout.
  return;
}

#ifndef TEST_BUILD

/**
 * Program entry point.
 *
 * @return Program exit status.
 */
int main(void) {
  printf("\n--read_print_quadratic--\n");
  read_print_quadratic();

  printf("\n--read_print_is_character--\n");
  read_print_is_character();

  printf("\n--read_print_factorial--\n");
  read_print_factorial();

  printf("\n--read_print_gcd--\n");
  read_print_gcd();

  return 0;
}

#endif
