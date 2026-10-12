#include "types.h"
#include <stdio.h>

/**
 * Calculate `dividend / divisor`.
 * Return the result through the `quotient` pointer.
 *
 * The function must not print anything!
 *
 * @param dividend Dividend.
 * @param divisor Divisor.
 * @param quotient Pointer to the quotient (result).
 *
 * @return `true` on successful division, `false` otherwise.
 */
bool divide(int dividend, int divisor, double *quotient) {
  // TODO: Implement correct floating-point division
  // TODO: Return the result through the quotient parameter
  return false;
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
  int dividend, divisor;
  double quotient;

  // Read the dividend and divisor from stdin
  scanf("%d", &dividend);
  scanf("%d", &divisor);

  // TODO: Call divide with the appropriate parameters

  // TODO: Handle any processing error;
  //   on error, print "divide: error" to stdout

  // Print the division result
  printf("%.3f\n", quotient);

  return 0;
}

#endif
