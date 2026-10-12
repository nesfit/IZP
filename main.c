#include "types.h"
#include <stdio.h>
#include <stdlib.h>

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
  // TODO: Call the implemented functions.
  return 0;
}

#endif

/**
 * Determine the length of a string.
 * All strings in C end with a null byte.
 *
 * @param str Input string.
 *
 * @return String length (number of characters).
 */
size_t str_len(char *str) {
  // TODO: Implement this function.
  return -1;
}

/**
 * Copy the specified amount of memory byte by byte.
 *
 * The source data is not modified.
 * Assume that enough memory is available at the destination.
 *
 * Hint: (char *) to cast from void*
 *
 * @param dest Pointer to the memory to copy to.
 * @param src Pointer to the memory to copy from.
 * @param n Amount of memory to copy in bytes.
 */
void mem_cpy(void *dest, void *src, size_t n) {
  // TODO: Implement this function.
}

/**
 * Find the first occurrence of a substring in a string.
 *
 * Neither string is modified.
 *
 * Hint: str_len
 *
 * @param str String to search.
 * @param substr Substring to find.
 *
 * @return Index where the substring starts in the string,
 * or -1 if the substring is not found.
 */
int find_substr(char *str, char *substr) {
  // TODO: Implement this function.
  return -2;
}

/**
 * Replace substr in the string with a replacement substring,
 * where both substrings have the same length.
 *
 * The substrings are not modified.
 * If the substrings have different lengths, no substitution is performed.
 * The same applies if the substring is not found in the string.
 *
 * Hint: mem_cpy, find_substr, str_len
 *
 * @param str String to search.
 * @param substr Substring to find and replace.
 * @param new_substr Replacement substring.
 */
void replace_same_length(char *str, char *substr, char *new_substr) {
  // TODO: Implement this function.
}

/**
 * Replace a substring in the string with a replacement substring,
 * where each substring may have a different length.
 * The original string is freed.
 *
 * The substrings are not modified.
 * On error, the original string is not freed and remains unchanged.
 *
 * Hint: mem_cpy, find_substr, str_len, malloc, free
 *
 * @param str Dynamically allocated string to search.
 * @param substr Substring to find and replace.
 * @param new_substr Replacement substring.
 *
 * @return New string in newly allocated memory on success,
 * a pointer to the original string if the substring is not found,
 * `NULL` otherwise.
 */
char *replace(char *str, char *substr, char *new_substr) {
  // TODO: Implement this function.
  return NULL;
}
