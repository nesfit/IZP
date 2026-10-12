#include "types.h"
#include <stdio.h>

#define ARRAY_LENGTH 5
#define MERGED_ARRAY_LENGTH 2 * ARRAY_LENGTH

/**
 * Read an array and print it in reverse order.
 */
void read_print_array_reverse(void) {
  // TODO: 1. Read an array of numbers of length ARRAY_LENGTH from stdin.

  // TODO: 2. Print the read array in reverse order to stdout.
  return;
}

/**
 * Read an array and print its maximum value.
 */
void read_print_array_max(void) {
  // TODO: 1. Read an array of numbers of length ARRAY_LENGTH from stdin.

  // TODO: 2. Find the maximum value and print it to stdout.
  return;
}

/**
 * Read an array and print its average value.
 */
void read_print_array_avg(void) {
  // TODO: 1. Read an array of numbers of length ARRAY_LENGTH from stdin.

  // TODO: 2. Calculate the average value and print it to stdout.
  return;
}

/**
 * Read two arrays and print their merged contents.
 */
void read_print_array_merge(void) {
  // TODO: 1. Read 2 arrays of numbers, each of length ARRAY_LENGTH from stdin.

  // TODO: 2. Copy the first and second arrays, respectively, to a third array
  // of length MERGED_ARRAY_LENGTH, and print the resulting third array to
  // stdout.
  return;
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
int main(int argc, char *argv[]) {
  printf("\n--read_print_array_reverse--\n");
  read_print_array_reverse();

  printf("\n--read_print_array_max--\n");
  read_print_array_max();

  printf("\n--read_print_array_avg--\n");
  read_print_array_avg();

  printf("\n--read_print_array_merge--\n");
  read_print_array_merge();

  return 0;
}

#endif
