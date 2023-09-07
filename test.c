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


int test_is_in_set(int argc, char **argv) {
  int *__array, __length = __load_array(&__array), __value;
  if (scanf(" is %d in set", &__value) != 1) {
    fprintf(stderr, "load failed, expected an additional value\n");
    return TEST_ERR_WRONG_INVOCATION;
  }
  bool __result = is_in_set(__array, __length, __value);
  printf("is_in_set("); __print_array(stdout, __array, __length);
  printf(", %2d, %2d) = %s\n", __length, __value, __result ? "true" : "false");
  return 0;
}

int test_is_set(int argc, char **argv) {
  int *__array, __length = __load_array(&__array);
  bool __result = is_set(__array, __length);
  printf("is_set("); __print_array(stdout, __array, __length);
  printf(", %2d) = %s\n", __length, __result ? "true" : "false");
  return 0;
}

int test_is_sorted_set(int argc, char **argv) {
  int *__array, __length = __load_array(&__array);
  bool __result = is_sorted_set(__array, __length);
  printf("is_sorted_set("); __print_array(stdout, __array, __length);
  printf(", %2d) = %s\n", __length, __result ? "true" : "false");
  return 0;
}

int test_print_intersection(int argc, char **argv) {
  int *__array1, __length1 = __load_array(&__array1);
  int *__array2, __length2 = __load_array(&__array2);
  printf("print_intersection(\n\t");
  __print_array(stdout, __array1, __length1); printf(", %2d,\n\t", __length1);
  __print_array(stdout, __array2, __length2); printf(", %2d)\n", __length2);
  print_intersection(__array1, __array2, __length1, __length2);
  return 0;
}

int test_print_union(int argc, char **argv) {
  int *__array1, __length1 = __load_array(&__array1);
  int *__array2, __length2 = __load_array(&__array2);
  printf("print_union(\n\t");
  __print_array(stdout, __array1, __length1); printf(", %2d,\n\t", __length1);
  __print_array(stdout, __array2, __length2); printf(", %2d)\n", __length2);
  print_union(__array1, __array2, __length1, __length2);
  return 0;
}

int test_print_product(int argc, char **argv) {
  int *__array1, __length1 = __load_array(&__array1);
  int *__array2, __length2 = __load_array(&__array2);
  printf("print_product(\n\t");
  __print_array(stdout, __array1, __length1); printf(", %2d,\n\t", __length1);
  __print_array(stdout, __array2, __length2); printf(", %2d)\n", __length2);
  print_product(__array1, __array2, __length1, __length2);
  return 0;
}

const char *test_names[] = {
  "test_is_in_set",
  "test_is_set",
  "test_is_sorted_set",
  "test_print_intersection",
  "test_print_union",
  "test_print_product",
};

int (*tests[])(int, char**) = {
  &test_is_in_set,
  &test_is_set,
  &test_is_sorted_set,
  &test_print_intersection,
  &test_print_union,
  &test_print_product,
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
