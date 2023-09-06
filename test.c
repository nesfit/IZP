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


void __array_fprint(FILE *file, int arr[], int size) {
    fprintf(file, "[");
    for (int i = 0; i < size - 1; i++) {
        fprintf(file, "%d, ", arr[i]);
    }
    if (size > 0) {
        fprintf(file, "%d]\n", arr[size - 1]);
    } else {
        fprintf(file, "]\n");
    }
}

int *__load(int *size) {
  scanf("%d", size);
  int *array = malloc((*size) * sizeof(int));
  for (int i = 0; i < *size; i++) {
    scanf("%d", &array[i]);
  }

  return array;
}

void __dispose(int *array) { free(array); }

void __array_print_loaded(int array[], int size) {
  fprintf(stderr, "loaded: ");
  __array_fprint(stderr, array, size);
  fprintf(stderr, "\n");
}

int test_array_print(int argc, char **argv) {
  int __size, *__array = __load(&__size);
  __array_print_loaded(__array, __size);

  array_print(__array, __size);
  __dispose(__array);
  return 0;
}

int test_array_multiply(int argc, char **argv) {
  int __size, *__array = __load(&__size);
  __array_print_loaded(__array, __size);

  int __multiplier;
  scanf("%d", &__multiplier);

  array_multiply(__array, __size, __multiplier);

  __array_fprint(stdout, __array, __size);
  __dispose(__array);
  return 0;
}

int test_array_insert(int argc, char **argv) {
  int __size, *__array = __load(&__size);
  __array_print_loaded(__array, __size);

  int __insertPairCount;
  scanf("%d", &__insertPairCount);

  for (int i = 0; i < __insertPairCount; i++) {
    int __value, __position;
    scanf("%d %d", &__value, &__position);
    fprintf(stderr, "inserting %d at position %d\n", __value, __position);
    int __insertResult = array_insert(__array, __size, __value, __position);
    if (__insertResult != 1) {
      fprintf(stderr, "inserting failed\n");
      __dispose(__array);
      return __insertResult == 0 ? 1 : __insertResult;
    }
  }

  __array_fprint(stdout, __array, __size);
  __dispose(__array);
  return 0;
}

const char *test_names[] = {
  "test_array_print",
  "test_array_multiply",
  "test_array_insert",
};

int (*tests[])(int, char**) = {
  &test_array_print,
  &test_array_multiply,
  &test_array_insert,
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
