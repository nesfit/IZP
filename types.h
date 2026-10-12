/**
 * @file types.h
 * Header file.
 *
 * Do not modify this file.
 */

#include <stdbool.h>
#include <stdio.h>

#ifndef TYPES_H
#define TYPES_H

// Do not change the declared function signatures.

#define MAT_ROWS 3
#define MAT_COLUMNS 3

#define MAT_FILE_PATH "matrix.txt"

/**
 * Print the contents of the matrix.
 *
 * @param matrix Matrix to print.
 */
void print_2d(int matrix[MAT_ROWS][MAT_COLUMNS]);

/**
 * Save the matrix to a file.
 *
 * @param filename Destination filename.
 * @param matrix Matrix to save.
 *
 * @return `true` on success, `false` otherwise.
 */
bool save_to_file(const char *filename, int matrix[MAT_ROWS][MAT_COLUMNS]);

/**
 * Write the matrix items to the output file.
 *
 * @param output Output file stream.
 * @param matrix Matrix to save.
 *
 * @return `true` on success, `false` otherwise.
 */
bool save_to(FILE *output, int matrix[MAT_ROWS][MAT_COLUMNS]);

/**
 * Load the matrix from a file.
 *
 * @param filename Source filename.
 * @param matrix Matrix to fill.
 *
 * @return `true` on success, `false` otherwise.
 */
bool load_from_file(const char *filename, int matrix[MAT_ROWS][MAT_COLUMNS]);

/**
 * Read matrix items from the input file into the matrix.
 *
 * @param input Input file stream.
 * @param matrix Matrix to fill.
 *
 * @return `true` on success, `false` otherwise.
 */
bool load_from(FILE *input, int matrix[MAT_ROWS][MAT_COLUMNS]);

#endif
