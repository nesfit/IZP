/**
 * @file types.h
 * Header file.
 *
 * Do not modify this file.
 */

#include <stdbool.h>

#ifndef TYPES_H
#define TYPES_H

// Do not change the declared function signatures or structures.

#define MAT_ROWS 3
#define MAT_COLUMNS 3

/**
 * Structure representing coordinates in a generic 2D matrix.
 */
struct mat_coords_t {
  /**
   * Row index in the matrix
   */
  int row;
  /**
   * Column index in the matrix row
   */
  int column;
};

// Create `MatCoords` as an alias for `struct mat_coords_t`
typedef struct mat_coords_t MatCoords;

/**
 * Print the contents of the provided 2D matrix.
 *
 * @param matrix 2D matrix.
 */
void print_2d(int matrix[MAT_ROWS][MAT_COLUMNS]);

/**
 * Search for a value in the provided 2D matrix.
 *
 * @param matrix 2D matrix.
 * @param value Value to find in the matrix.
 *
 * @return `true` when found, `false` otherwise.
 */
bool contains_value(int matrix[MAT_ROWS][MAT_COLUMNS], int value);

/**
 * Search for a value in the provided 2D matrix.
 *
 * @param matrix 2D matrix.
 * @param value Value to find in the matrix.
 *
 * @return Coordinates of the value in the matrix when found;
 *   coordinates {-1, -1} otherwise.
 */
MatCoords find_value(int matrix[MAT_ROWS][MAT_COLUMNS], int value);

#endif
