/**
 * Zdrojový soubor test.c
 *  Obsahuje logiku pro automatické testování.
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */

#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Person __load_person() {
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

void __print_array(const char *prefix, PersonArray *array) {
  printf("%s", prefix);
  printf("PersonArray(%u): ", array->length);
  array_print(array);
}

PersonArray __load_array() {
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

int test_person_copy()
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

int test_person_dtor()
{
  Person person = __load_person();
  person_dtor(&person);
  __print_person("result: ", &person);
  return 0;
}

int test_array_dtor()
{
  PersonArray array = __load_array();
  array_dtor(&array);
  __print_array("result: ", &array);
  return 0;
}

int test_find_min()
{
  PersonArray array = __load_array();
  int minItemIndex = array_find_min(&array, 0);
  printf("found min item index: %d\n", minItemIndex);
  if (minItemIndex >= 0) {
    __print_person("result: ", &array.items[minItemIndex]);
  }
  __dispose_array(&array);
  return 0;
}

int test_sort()
{
  PersonArray array = __load_array();
  array_sort(&array);
  __print_array("result: ", &array);
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

int (*tests[])() = {
  &test_person_copy,
  &test_person_dtor,
  &test_array_dtor,
  &test_find_min,
  &test_sort,
};

#define TEST_COUNT (sizeof(tests) / sizeof(*tests))

int run_test_by_name(const char *test_name) {
  if (test_name != NULL) {
    for (size_t testId = 0; testId < TEST_COUNT; testId++)
    {
      if (strcmp(test_names[testId], test_name) == 0) {
        return tests[testId]();
      }
    }
  }
  
  fprintf(stderr, "could not find test '%s'\n", test_name);
  fprintf(stderr, "supported tets:\n");
  for (size_t testId = 0; testId < TEST_COUNT; testId++)
  {
    fprintf(stderr, "    - %s\n", test_names[testId]);
  }

  return 99;
}

#ifdef TEST_BUILD

int main(int argc, char **args) {
  const char *test_name = getenv("TEST_NAME");
  return run_test_by_name(test_name);
}

#endif
