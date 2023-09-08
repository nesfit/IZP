#include "types.h"
#include <stdio.h>


void print_helloworld() {
  //TODO 1. Print 'Hello World' to stdout.
  return;
}

#define A -4
#define B 2
#define C 3
void print_discriminant() {
  //TODO 1. Calculate and print discriminant with values defined above to stdout.
  return;
}

void read_print_is_even() {
  //TODO 1. Read a number from stdin and output to stdout whether the read number is even or not.
  return;
}

void read_print_is_in_interval() {
  //TODO 1. Read 2 numbers from stdin. These two numbers represent a interval.

  //TODO 2. Read third number from stdin. Output to stdout whether the third number is contained in the previously read interval.
  return;
}

void read_print_is_leap_year() {
  //TODO 1. Read a number representing a year from stdin.

  //TODO 2. Determine whether the year is a leap year or not.
  return; 
}

void read_print_maximum() {
  //TODO 1. Read 3 numbers from stdin.

  //TODO 2. Output the largest of read numbers to stdout.
  return;
}


#ifndef TEST_BUILD

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
