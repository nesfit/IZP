#include "types.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void read_print_quadratic() {
  //TODO 1. Read 3 numbers: a, b and c which represent known numbers for quadratic equation in standard format (ax^2 + bx + c = 0) from stdin.

  //TODO 2. Check if equation is quadratic. If so, calculate its discriminant and, if possible, print all roots to stdout.
  return;
}

void read_print_is_character() {
  //TODO 1. Read one character from stdin.

  //TODO 2. Determine whether the character represents a letter (a-z, A-Z) or not and print the result to stdout.
  return;
}

void read_print_factorial() {
  //TODO 1. Read one number from stdin.

  //TODO 2. Print its factorial (!) to stdout.
  return;
}

void read_print_gcd(){
  //TODO 1. Read two numbers from stdin.

  //TODO 2. Calculate and print greatest common divisor (gcd) of the two read numbers and print it to stdout.
  return;
}


#ifndef TEST_BUILD

int main()
{
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
