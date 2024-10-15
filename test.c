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

#define ERR_FILE_MISSING 97

void __read_dump(const char *filepath) {
  FILE *f = fopen(filepath, "r");
  if (f == NULL) {
    fprintf(stderr, "%s", "the target file does not exist!\n");
    exit(ERR_FILE_MISSING);
  }
  fprintf(stderr, "file contents:\n");
  char s[50]; int length = 0;
  while (fgets(s, 50, f) != NULL) {
    fprintf(stderr, "%s", s);
    if (++length >= 5) {
      fprintf(stderr, "** FILE CONTENT TRUNCATED **\n");
      break;
    }
  }
  fclose(f);
}

void __print(int matrix[MAT_ROWS][MAT_COLUMNS]) {
  for (int rowIndex = 0; rowIndex < MAT_ROWS; rowIndex++) {
    for (int columnIndex = 0; columnIndex < MAT_COLUMNS; columnIndex++) {
      printf("%d ", matrix[rowIndex][columnIndex]);
    }
    printf("\n");
  }
}

void __load(FILE *source, int matrix[MAT_ROWS][MAT_COLUMNS]) {
  for (int rowIndex = 0; rowIndex < MAT_ROWS; rowIndex++) {
    for (int columnIndex = 0; columnIndex < MAT_COLUMNS; columnIndex++) {
      fscanf(source, "%d", &matrix[rowIndex][columnIndex]);
    }
  }
}

void __load_from(const char *filepath, int matrix[MAT_ROWS][MAT_COLUMNS]) {
  FILE *f = fopen(filepath, "r");
  if (f == NULL) exit(ERR_FILE_MISSING);
  __load(f, matrix);
  fclose(f);
}

void __save(FILE *source, int matrix[MAT_ROWS][MAT_COLUMNS]) {
  for (int rowIndex = 0; rowIndex < MAT_ROWS; rowIndex++) {
    for (int columnIndex = 0; columnIndex < MAT_COLUMNS; columnIndex++) {
      fprintf(source, "%d ", matrix[rowIndex][columnIndex]);
    }
    fprintf(source, "\n");
  }
}

void __save_to(const char *filepath, int matrix[MAT_ROWS][MAT_COLUMNS]) {
  FILE *f = fopen(filepath, "w");
  if (f == NULL) exit(ERR_FILE_MISSING);
  __save(f, matrix);
  fclose(f);
}

#pragma endregion

static const char *__filename = ".tests/student/__mat.txt";

int test_save_to_file(int argc, char **argv) {
  int __mat[MAT_ROWS][MAT_COLUMNS], __mat_loaded[MAT_ROWS][MAT_COLUMNS]; __load(stdin, __mat);
  bool __result = save_to_file(__filename, __mat);
  fprintf(stdout, "save_to_file(filepath, matrix) == %s\n", __result ? "true" : "false");
  if (__result == false) {
    remove(__filename);
    return 1;
  }
  __load_from(__filename, __mat_loaded);
  __read_dump(__filename);
  remove(__filename);
  fprintf(stdout, "loaded from file:\n");
  __print(__mat_loaded);
  return 0;
}

int test_save_to(int argc, char **argv) {
  int __mat[MAT_ROWS][MAT_COLUMNS], __mat_loaded[MAT_ROWS][MAT_COLUMNS]; __load(stdin, __mat);
  FILE *f = fopen(__filename, "w");
  if (f == NULL) exit(ERR_FILE_MISSING);
  bool __result = save_to(f, __mat);
  fprintf(stdout, "save_to(file, matrix) == %s\n", __result ? "true" : "false");
  fclose(f);
  if (__result == false) {
    remove(__filename);
    return 1;
  }
  __load_from(__filename, __mat_loaded);
  __read_dump(__filename);
  remove(__filename);
  fprintf(stdout, "loaded from file:\n");
  __print(__mat_loaded);
  return 0;
}

int test_load_from_file(int argc, char **argv) {
  int __mat[MAT_ROWS][MAT_COLUMNS], __mat_loaded[MAT_ROWS][MAT_COLUMNS]; __load(stdin, __mat);
  __save_to(__filename, __mat);
  bool __result = load_from_file(__filename, __mat_loaded);
  fprintf(stdout, "load_from_file(filepath, &matrix) == %s\n", __result ? "true" : "false");
  if (__result == false) {
    remove(__filename);
    return 1;
  }
  __read_dump(__filename);
  remove(__filename);
  fprintf(stdout, "loaded from file:\n");
  __print(__mat_loaded);
  return 0;
}

int test_load_from(int argc, char **argv) {
  int __mat[MAT_ROWS][MAT_COLUMNS];
  bool __result = load_from(stdin, __mat);
  fprintf(stdout, "load_from(stdin, &matrix) == %s\n", __result ? "true" : "false");
  if (__result == false) {
    remove(__filename);
    return 1;
  }
  fprintf(stdout, "loaded from file:\n");
  __print(__mat);
  return 0;
}

const char *test_names[] = {
  "test_save_to_file",
  "test_save_to",
  "test_load_from_file",
  "test_load_from",
};

int (*tests[])(int, char**) = {
  &test_save_to_file,
  &test_save_to,
  &test_load_from_file,
  &test_load_from,
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
