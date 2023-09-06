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


#pragma region Support methods for testing

Person __load_person(void) {
  int year;
  char nameLoaded[100];
  char *nameAllocated;
  scanf("%d, %99[^\n]", &year, (char *)&nameLoaded);
  nameAllocated = malloc(strlen(nameLoaded) + 1);
  strcpy(nameAllocated, nameLoaded);

  Person p = {.birthYear=year, .name=nameAllocated};
  return p;
}

void __dispose_person(Person *p) {
  if (p && p->name) {
    free(p->name);
    p->name = NULL;
  }
  p->birthYear = 0;
}

void __print_person(const char *prefix, Person *p) {
  printf("%s", prefix);
  person_print(p);
  putchar('\n');
}

void __print_person_array(const char *prefix, PersonArray *array) {
  printf("%s", prefix);
  printf("PersonArray(%u): ", array->length);
  array_print(array);
}

PersonArray __load_person_array(void) {
  unsigned count;
  scanf("load %u people:", &count);

  PersonArray array = {.items=malloc(count * sizeof(Person)), .length=count};
  for (size_t i = 0; i < array.length; i++) {
    array.items[i] = __load_person();
  }
  //__print_array("loeaded: ", &array);
  return array;
}

void __dispose_array(PersonArray *array) {
  if (array && array->items != NULL) {
    for (size_t i = 0; i < array->length; i++) {
      __dispose_person(&array->items[i]);
    }
    free(array->items);
    array->items = NULL;
  }
  array->length = 0;
}

#pragma endregion

int test_person_copy(int argc, char **argv)
{
  Person person1 = __load_person();
  Person person2;
  person_copy(&person1, &person2);

  char newName[100];
  scanf(" copy and rename to %99[^\n]", newName);
  strcpy(person2.name, newName);
  __print_person("source: ", &person1);
  __print_person("result: ", &person2);

  __dispose_person(&person1);
  __dispose_person(&person2);
  return 0;
}

int test_person_dtor(int argc, char **argv)
{
  Person person = __load_person();
  person_dtor(&person);
  __print_person("result: ", &person);
  return 0;
}

int test_array_dtor(int argc, char **argv)
{
  PersonArray array = __load_person_array();
  array_dtor(&array);
  __print_person_array("result: ", &array);
  return 0;
}

int test_find_min(int argc, char **argv)
{
  PersonArray array = __load_person_array();
  int minItemIndex = array_find_min(&array, 0);
  printf("found min item index: %d\n", minItemIndex);
  if (minItemIndex >= 0) {
    __print_person("result: ", &array.items[minItemIndex]);
  }
  __dispose_array(&array);
  return 0;
}

int test_sort(int argc, char **argv)
{
  PersonArray array = __load_person_array();
  array_sort(&array);
  __print_person_array("result: ", &array);
  __dispose_array(&array);
  return 0;
}

const char *test_names[] = {
  "test_person_copy",
  "test_person_dtor",
  "test_array_dtor",
  "test_find_min",
  "test_sort",
};

int (*tests[])(int, char **) = {
  &test_person_copy,
  &test_person_dtor,
  &test_array_dtor,
  &test_find_min,
  &test_sort,
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
