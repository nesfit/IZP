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

#define BUFFER_SIZE 100

char __buffer[BUFFER_SIZE];

char *date_to_string(struct date_t *date) {
  int __print_len = snprintf(__buffer, BUFFER_SIZE, "struct date_t {\n  .year = %d,\n  .month = %d,\n  .day = %d\n}", date->year, date->month, date->day);
  char *__result = malloc(__print_len + 1); strcpy(__result, __buffer);
  return __result;
}

int test_is_valid_date(int argc, char **argv) {
  struct date_t __date;
  if (argc == 2) {
    sscanf(argv[1], "%d-%d-%d", &__date.year, &__date.month, &__date.day);
  } else {
    scanf("%d-%d-%d", &__date.year, &__date.month, &__date.day);
  }
  char *__date_str = date_to_string(&__date); fprintf(stderr, "date = %s;\n", __date_str);
  bool __status = is_valid_date(__date);
  printf("is_valid_date(date) == %s\n", __status ? "true" : "false");
  free(__date_str);
  return 0;
}

int test_earlier_date(int argc, char **argv) {
  struct date_t __date1, __date2;
  if (argc == 3) {
    sscanf(argv[1], "%d-%d-%d", &__date1.year, &__date1.month, &__date1.day);
    sscanf(argv[2], "%d-%d-%d", &__date2.year, &__date2.month, &__date2.day);
  } else {
    scanf("%d-%d-%d", &__date1.year, &__date1.month, &__date1.day);
    scanf("%d-%d-%d", &__date2.year, &__date2.month, &__date2.day);
  }
  char *__date1_str = date_to_string(&__date1), *__date2_str = date_to_string(&__date2);
  fprintf(stderr, "date1 = %s;\n", __date1_str); fprintf(stderr, "date2 = %s;\n", __date2_str);
  free(__date1_str); free(__date2_str);
  int __status = earlier_date(__date1, __date2);
  printf("earlier_date(date1, date2) == %d\n", __status);
  return 0;
}

const char *test_names[] = {
  "test_is_valid_date",
  "test_earlier_date",
};

int (*tests[])(int, char**) = {
  &test_is_valid_date,
  &test_earlier_date,
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
