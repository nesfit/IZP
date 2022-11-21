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

char* __load_string() {
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


int test_str_len()
{
  char *testString = __load_string();
  printf("%lu\n",str_len(testString));
  __dispose_string(testString);
  return 0;
}

int test_mem_cpy()
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

int test_find_substr()
{
  char *a = __load_string();
  char *b = __load_string();
  printf("%d\n",find_substr(a,b));
  __dispose_string(a);
  __dispose_string(b);
  return 0;
}

int test_replace_same_length()
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

int test_replace()
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

int (*tests[])() = {
  &test_str_len,
  &test_mem_cpy,
  &test_find_substr,
  &test_replace_same_length,
  &test_replace,
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
  printf("=== AUTOMATED TESTS ===\n");

  const char *test_name = getenv("TEST_NAME");
  return run_test_by_name(test_name);
}

#endif
