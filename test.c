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


ull __load_index() {
  ull n;
  scanf("generate Fibonacci number %llu", &n);
  return n;
}

int test_fib() {
  ull result = fib(__load_index());
  printf("calls: %llu\n", fib_calls);
  printf("result: %llu\n", result);
  return 0;
}

int test_fib_fast() {
  ull result = fib_fast(__load_index());
  printf("calls: %llu\n", fib_fast_calls);
  printf("result: %llu\n", result);
  return 0;
}

const char *test_names[] = {
  "test_fib",
  "test_fib_fast",
};

int (*tests[])() = {
  &test_fib,
  &test_fib_fast,
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
