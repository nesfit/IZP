#include "types.h"
#include <stdio.h>

/**
 * Print the contents of the matrix.
 *
 * @param matrix Matrix to print.
 */
void print_2d(int matrix[MAT_ROWS][MAT_COLUMNS]) {
  for (int row = 0; row < MAT_ROWS; row++) {
    for (int column = 0; column < MAT_COLUMNS; column++) {
      printf("%d ", matrix[row][column]);
    }
    printf("\n");
  }
}

/**
 * Write the matrix items to the output file.
 *
 * @param output Output file stream.
 * @param matrix Matrix to save.
 *
 * @return `true` on success, `false` otherwise.
 */
bool save_to(FILE *output, int matrix[MAT_ROWS][MAT_COLUMNS]) {
  // TODO: Write the matrix items into the file

  // TODO: Return true when successful
  return false;
}

/**
 * Save the matrix to a file.
 *
 * @param filename Destination filename.
 * @param matrix Matrix to save.
 *
 * @return `true` on success, `false` otherwise.
 */
bool save_to_file(const char *filename, int matrix[MAT_ROWS][MAT_COLUMNS]) {
  // FILE * is the type used to represent files and data streams
  FILE *output;

  // TODO: 1. Open the destination file
  // TODO: 2. Validate that the stream has opened correctly

  bool result = save_to(output, matrix);

  // TODO: 4. Don't forget to close the file!
  return result;
}

/**
 * Read matrix items from the input file into the matrix.
 *
 * @param input Input file stream.
 * @param matrix Matrix to fill.
 *
 * @return `true` on success, `false` otherwise.
 */
bool load_from(FILE *input, int matrix[MAT_ROWS][MAT_COLUMNS]) {
  // TODO: Read the matrix items from the file into the matrix

  // TODO: Return true when successful
  return false;
}

/**
 * Load the matrix from a file.
 *
 * @param filename Source filename.
 * @param matrix Matrix to fill.
 *
 * @return `true` on success, `false` otherwise.
 */
bool load_from_file(const char *filename, int matrix[MAT_ROWS][MAT_COLUMNS]) {
  FILE *input;

  // TODO: 1. Open the source file
  // TODO: 2. Validate that the stream has opened correctly

  bool result = load_from(input, matrix);

  // TODO: 4. Don't forget to close the file!
  return result;
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
  // Create and initialize a matrix
  int matrix[MAT_ROWS][MAT_COLUMNS];
  for (int row = 0; row < MAT_ROWS; row++) {
    for (int column = 0; column < MAT_COLUMNS; column++) {
      matrix[row][column] = (row + 1) * (column + 1);
    }
  }

  // Save the matrix to a file
  if (save_to_file(MAT_FILE_PATH, matrix) == false) {
    printf("Error during saving matrix to file!\n");
    return 1;
  }

  // Load matrix contents from a file
  int matrix_loaded[MAT_ROWS][MAT_COLUMNS];
  if (load_from_file(MAT_FILE_PATH, matrix_loaded) == false) {
    printf("Error during loading matrix from file!\n");
    return 1;
  }

  // Print the matrix contents
  print_2d(matrix_loaded);

  return 0;
}

#endif
