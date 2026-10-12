/**
 * @file types.h
 * Header file.
 *
 * Do not modify this file.
 */

#ifndef TYPES_H
#define TYPES_H

// Do not change the declared function signatures.

/**
 * Safely print the first argument provided to the program. Determine its
 * meaning.
 *
 * @param argc Number of command-line arguments.
 * @param argv Command-line arguments.
 */
void print_first_argument(int argc, char *argv[]);

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
void print_parse_arguments(int argc, char *argv[]);

/**
 * Safely print ALL arguments provided to the program without any conversion.
 *
 * ./main <int> <double> <string>
 *
 * @param argc Number of command-line arguments.
 * @param argv Command-line arguments.
 */
void print_all_arguments(int argc, char *argv[]);
#endif
