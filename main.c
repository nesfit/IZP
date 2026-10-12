#include "types.h"
#include <stdio.h>

/**
 * Swap the values of two integer variables.
 *
 * @param variableA Pointer to the first variable.
 * @param variableB Pointer to the second variable.
 */
void swapInts(int *variableA, int *variableB) {
  // TODO: 1. Implement this function.
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
  int number1, number2;

  // Read numbers from stdin
  scanf("%d", &number1);
  scanf("%d", &number2);

  swapInts(&number1, &number2);
  printf("%d %d\n", number1, number2);

  return 0;
}

#endif
