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


#pragma region Helper methods for testing

char* __load_string(void) {
  size_t size;
  scanf("%lu", &size);
  if (size == 0)
  {
    char *new_string = malloc(1 * sizeof(char));
    new_string[0] = '\0';
    return new_string;
  }
  char *new_string = malloc(size * sizeof(char)+1);
  new_string[size-1] = '\0';
  scanf("%s", new_string);
  return new_string;
}

void __dispose_string(char *str) {
    if(str == NULL)
      return;
    free(str);
}

#pragma endregion

int test_str_len(int argc, char **argv)
{
  char *testString = __load_string();
  printf("%lu\n",str_len(testString));
  __dispose_string(testString);
  return 0;
}

int test_mem_cpy(int argc, char **argv)
{
  char *a = __load_string();
  char *b = __load_string();

  mem_cpy(b,a,strlen(a));

  printf("%s\n",a);
  printf("%s\n",b);

  __dispose_string(a);
  __dispose_string(b);
  return 0;
}

int test_find_substr(int argc, char **argv)
{
  char *a = __load_string();
  char *b = __load_string();
  printf("%d\n",find_substr(a,b));
  __dispose_string(a);
  __dispose_string(b);
  return 0;
}

int test_replace_same_length(int argc, char **argv)
{
  char *a = __load_string();
  char *b = __load_string();
  char *c = __load_string();
  replace_same_length(a,b,c);
  printf("%s\n",a);
  printf("%s\n",b);
  printf("%s\n",c);
  __dispose_string(a);
  __dispose_string(b);
  __dispose_string(c);
  return 0;
}

int test_replace(int argc, char **argv)
{
  char *a = __load_string();
  char *b = __load_string();
  char *c = __load_string();
  a = replace(a,b,c);
  printf("%s\n",a);
  printf("%s\n",b);
  printf("%s\n",c);
  __dispose_string(a);
  __dispose_string(b);
  __dispose_string(c);
  return 0;
}

const char *test_names[] = {
  "test_str_len",
  "test_mem_cpy",
  "test_find_substr",
  "test_replace_same_length",
  "test_replace",
};

int (*tests[])(int, char **) = {
  &test_str_len,
  &test_mem_cpy,
  &test_find_substr,
  &test_replace_same_length,
  &test_replace,
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
