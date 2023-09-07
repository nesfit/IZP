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


int test_get_max(int argc, char **argv) {
  int *__array, __length = __load_array(&__array);
  int __result = get_max(__array, __length);
  printf("get_max("); __print_array(stdout, __array, __length); printf(", %2d) = %2d\n", __length, __result);
  free(__array);
  return 0;
}

int test_get_sum(int argc, char **argv) {
  int *__array, __length = __load_array(&__array);
  int __result = get_sum(__array, __length);
  printf("get_sum("); __print_array(stdout, __array, __length); printf(", %2d) = %2d\n", __length, __result);
  free(__array);
  return 0;
}

int test_values_are_smaller_than(int argc, char **argv) {
  int *__array1, __length1 = __load_array(&__array1);
  int *__array2, __length2 = __load_array(&__array2);
  if (__length1 != __length2) {
    fprintf(stderr, "lengths of both arrays are expected to be the same");
    exit(TEST_ERR_WRONG_INVOCATION);
  }
  int __result = values_are_smaller_than(__array1, __array2, __length1);
  printf("values_are_smaller_than(\n\t"); __print_array(stdout, __array1, __length1);
  printf(", %2d,\n\t", __length1); __print_array(stdout, __array2, __length2);
  printf(", %2d) = %s\n", __length2, __result ? "true" : "false");
  free(__array1);
  return 0;
}

const char *test_names[] = {
  "test_get_max",
  "test_get_sum",
  "test_values_are_smaller_than",
};

int (*tests[])(int, char**) = {
  &test_get_max,
  &test_get_sum,
  &test_values_are_smaller_than,
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
