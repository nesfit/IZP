#include "types.h"
#include <stdio.h>

#define ARRAY_LENGTH 5
#define MERGED_ARRAY_LENGTH 2 * ARRAY_LENGTH

void read_print_array_reverse() {
  //TODO 1. Read an array of numbers of length ARRAY_LENGTH from stdin.

  //TODO 2. Print read array in reversed order to stdout.
  return;
}

void read_print_array_max() {
  //TODO 1. Read an array of numbers of length ARRAY_LENGTH from stdin.

  //TODO 2. Find maximum value and print it to stdout.
  return;
}

void read_print_array_avg() {
  //TODO 1. Read an array of numbers of length ARRAY_LENGTH from stdin.

  //TODO 2. Calculate average value and print it to stdout.
  return;
}


void read_print_array_merge() {
  //TODO 1. Read 2 arrays of numbers, each of length ARRAY_LENGTH from stdin.

  //TODO 2. To 3rd array of length MERGED_ARRAY_LENGTH copy first and 
  //second arrays respectively and resulting third array print to stdout.
  return;
}


#ifndef TEST_BUILD

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
