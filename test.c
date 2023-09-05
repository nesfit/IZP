/**
 * Zdrojový soubor test.c
 *  Obsahuje logiku pro automatické testování.
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */

#include "test.h"
#include <stdio.h>


int test_example_success() {
  return 0;
}

int test_example_failure() {
  return 1;
}

const char *test_names[] = {
  "test_example_success",
  "test_example_failure",
};

int (*tests[])() = {
  &test_example_success,
  &test_example_failure,
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
