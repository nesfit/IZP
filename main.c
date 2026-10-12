#include "types.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Safely print the first argument provided to the program. Determine its
 * meaning.
 *
 * @param argc Number of command-line arguments.
 * @param argv Command-line arguments.
 */
void print_first_argument(int argc, char *argv[]) {
  // TODO: Implement this function.
  return;
}

/**
 * Safely print the first 4 arguments provided to the program while converting
 * them to their corresponding data types.
 *
 * ./main <int> <double> <string>
 *
 * To convert <string> to <int>, use the function atoi()
 * (https://cplusplus.com/reference/cstdlib/atoi/).
 *
 * To convert <string> to <double>, use the function atof()
 * (https://cplusplus.com/reference/cstdlib/atof/).
 *
 * Use the following command to execute your program with a set of arguments:
 *
 *     ./main 42 13.37 hello_program
 *
 * @param argc Number of command-line arguments.
 * @param argv Command-line arguments.
 */
void print_parse_arguments(int argc, char *argv[]) {
  // TODO: Implement this function.
  return;
}

/**
 * Safely print ALL arguments provided to the program without any conversion.
 *
 * ./main <int> <double> <string>
 *
 * @param argc Number of command-line arguments.
 * @param argv Command-line arguments.
 */
void print_all_arguments(int argc, char *argv[]) {
  // TODO: Implement this function.
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

  // TODO: 1. Call the implemented functions and pass argc and argv.
  return 0;
}

#endif
