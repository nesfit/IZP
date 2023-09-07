/**
 * Zdrojový soubor test.c
 *  Obsahuje logiku pro automatické testování.
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */

#include "test.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#pragma region Support methods for testing purposes

void __load_matrix(int matrix[MAT_ROWS][MAT_COLUMNS]) {
  for (int row = 0; row < MAT_ROWS; row++) {
    for (int col = 0; col < MAT_COLUMNS; col++) {
      scanf("%d", &matrix[row][col]);
    }
  }
}

#pragma endregion

int test_print_2d(int argc, char **argv) {
  int matrix[MAT_ROWS][MAT_COLUMNS]; __load_matrix(matrix);
  print_2d(matrix);
  return 0;
}

int test_contains_value(int argc, char **argv) {
  int matrix[MAT_ROWS][MAT_COLUMNS], __value; __load_matrix(matrix);
  scanf(" contains value %d", &__value);
  int __status = contains_value(matrix, __value);
  printf("contains_value returned %d\n", __status);
  return 0;
}

int test_find_value(int argc, char **argv) {
  int matrix[MAT_ROWS][MAT_COLUMNS], __value; __load_matrix(matrix);
  scanf(" find value %d", &__value);
  MatCoords __coords = find_value(matrix, __value);
  printf("find_value returned [%d, %d]\n", __coords.row, __coords.column);
  return 0;
}

const char *test_names[] = {
  "test_print_2d",
  "test_contains_value",
  "test_find_value",
};

int (*tests[])(int, char**) = {
  &test_print_2d,
  &test_contains_value,
  &test_find_value,
};

#define TEST_COUNT (sizeof(tests) / sizeof(*tests))

int run_test_by_name(const char *test_name, int argc, char **argv) {
    if (test_name != NULL) {
        for (size_t testId = 0; testId < TEST_COUNT; testId++)
        {
            if (strcmp(test_names[testId], test_name) == 0) {
                return tests[testId](argc, argv);
            }
        }
    }
    
    fprintf(stderr, "could not find test '%s'\n", test_name);
    fprintf(stderr, "supported tets:\n");
    for (size_t testId = 0; testId < TEST_COUNT; testId++)
    {
        fprintf(stderr, "    - %s\n", test_names[testId]);
    }

    return TEST_ERR_NOT_FOUND;
}

#pragma region Base support methods for testing purposes

void __print_array(FILE *target, int *array, int length) {
  fprintf(target, "[");
  for (int i = 0; i < length - 1; i++)
  {
    fprintf(target, "%2d, ", array[i]);
  }
  if (length > 0) {
    fprintf(target, "%2d", array[length - 1]);
  }
  fprintf(target, "]");
}

int __load_array(int **array) {
  int __length;
  scanf(" load %d items: ", &__length);
  *array = (int *) malloc(__length * sizeof(int));
  if (*array == NULL) exit(TEST_ERR_SYSTEM_FAILURE);
  for (int i = 0; i < __length; i++) {
    if (scanf("%d", (*array) + i) != 1) {
      free(*array);
      fprintf(stderr, "failed reading value for index %d\n", i);
      exit(TEST_ERR_WRONG_INVOCATION);
    }
  }
  fprintf(stderr, "loaded: "); __print_array(stderr, *array, __length); fprintf(stderr, "\n");
  return __length;
}

#pragma endregion

#ifdef TEST_BUILD

int main(int argc, char **argv) {
  const char *test_name = getenv("TEST_NAME");
  return run_test_by_name(test_name, argc, argv);
}

#endif
