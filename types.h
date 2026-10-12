/**
 * @file types.h
 * Header file.
 *
 * Do not modify this file.
 */

#include <stdbool.h>

#ifndef TYPES_H
#define TYPES_H

static const char *usage =
    "syntax: program [-x|-y] [-n COUNT] -s STR\n"
    "    -x and -y are optional and mutually exclusive\n"
    "    -s STR - mandatory, STR is a string\n"
    "    -n COUNT - optional, COUNT is non-negative integer (default: 10)\n";

typedef struct {
  /**
   * Indicates whether the -x option was used.
   */
  bool xFlag;
  /**
   * Indicates whether the -y option was used.
   */
  bool yFlag;
  /**
   * Stores the string specified by the -s option.
   */
  char *sValue;
  /**
   * Stores the non-negative integer specified by the -n option.
   */
  unsigned nValue;
} Config;

// Do not change the declared function signatures.

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
bool parse_args(char **arguments, int argumentCount, Config *config);

#endif
