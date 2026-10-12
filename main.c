#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  // Program configuration
  Config config = {
      .xFlag = false, .yFlag = false, .sValue = NULL, .nValue = 10};

  // TODO: 2. Call parse_args appropriately
  // TODO: 3. On a processing error, print the contents
  //   of the global variable usage to standard error
  //   and exit the program with error code 1

  return 0;
}

#endif

/**
 * Process the program's command-line arguments.
 * Store the results in the Config structure passed as a parameter.
 *
 * Duplicate occurrences of any option are not allowed.
 *
 * Do not change any function signatures!
 *
 * @param arguments Array of command-line arguments.
 * @param argumentCount Size of the argument array.
 * @param config Pointer to the output configuration.
 *
 * @return `true` on successful processing, `false` otherwise.
 */
bool parse_args(char **arguments, int argumentCount, Config *config) {
  // TODO: 1. Implement this function according to the task specification
  //   and the behavior of the individual options

  return -1;
}
