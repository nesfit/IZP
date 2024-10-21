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


#pragma region Helper functions for set operations

void __load_set(Set *set) {
  scanf(" load set with %d items:", &set->cardinality);
  for (int i = 0; i < set->cardinality; i++) {
    scanf(" %d", &set->items[i]);
  }
}

Pair *__load_pairs(int *size) {
  scanf(" load %d pairs:", size);
  Pair *pairs = malloc((*size) * sizeof(Pair));
  for (int i = 0; i < *size; i++) {
    scanf(" (%d, %d)", &pairs[i].first, &pairs[i].second);
  }

  return pairs;
}

void __dispose(Pair *pairs) {
  free(pairs);
}

void __print_set(Set *set) {
  fprintf(stdout, "set = {");
  for (int i = 0; i < set->cardinality; i++) {
    fprintf(stdout, "  %d", set->items[i]);
  }
  fprintf(stdout, "  };\n");
}

void __print_relations(Pair *pairs, int count) {
  fprintf(stdout, "relations = [ ");
  for (int i = 0; i < count; i++) {
    fprintf(stdout, "\n  (%d, %d)", pairs[i].first, pairs[i].second);
  }
  if (count > 0) {
    fprintf(stdout, "\n");
  }
  fprintf(stdout, "];\n");
}

#pragma endregion

int test_is_function(int argc, char **argv) {
  int __relSize;
  Set __set;
  __load_set(&__set);
  Pair *__rel = __load_pairs(&__relSize);

  __print_set(&__set);
  __print_relations(__rel, __relSize);
  bool __result = rel_isFunction(__rel, __relSize, &__set);
  printf("\nrel_isFunction(relations, %d, set) == %s\n", __relSize, __result ? "true" : "false");
  if (__result == false) {
    return 1;
  }

  __dispose(__rel);
  return 0;
}

int test_min_max(int argc, char **argv) {
  int __relSize;
  Set __set;
  __load_set(&__set);
  Pair *__rel = __load_pairs(&__relSize);

  __print_relations(__rel, __relSize);
  int __relMin, __relMax, __result = rel_minMax(__rel, __relSize, &__relMin, &__relMax);
  printf("\nrel_minMax(relations, %d, &min, &max) == %s\n", __relSize, __result ? "true" : "false");
  if (__result == false){
    return 1;
  }

  printf("min == %d\n", __relMin);
  printf("max == %d\n", __relMax);
  __dispose(__rel);
  return 0;
}

int test_is_equivalence(int argc, char **argv) {
  int __relSize;
  Set __set;
  __load_set(&__set);
  Pair *__rel = __load_pairs(&__relSize);

  __print_set(&__set);
  __print_relations(__rel, __relSize);
  bool __result = rel_isEquivalence(__rel, __relSize, &__set);
  printf("\nrel_isEquivalence(relations, %d, set) == %s\n", __relSize, __result ? "true" : "false");
  if (__result == false) {
    return 1;
  }

  __dispose(__rel);
  return 0;
}

const char *test_names[] = {
  "test_is_function",
  "test_min_max",
  "test_is_equivalence",
};

int (*tests[])(int, char**) = {
  &test_is_function,
  &test_min_max,
  &test_is_equivalence,
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
