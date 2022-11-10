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


void __vector_print(char *prefix, Vector *v) {
    printf("%sVector(%d) = ", prefix, v->size);
    if (v->items == NULL) {
        printf("(null)\n");
        return;
    }

    printf("[");
    for (int i = 0; i < v->size - 1; i++) {
        printf("%d, ", v->items[i]);
    }

    if (v->size > 0) {
        printf("%d", v->items[v->size - 1]);
    }
    printf("]\n");
}

Vector __load_vector() {
    Vector v;
    scanf("%d", &v.size);
    v.items = v.size ? malloc(v.size * sizeof(*v.items)) : NULL;
    for (int i = 0; i < v.size; i++) {
        scanf("%d", &v.items[i]);
    }

    //__vector_print("loaded: ", &v);
    return v;
}

void __clone_vector(Vector *dest, Vector *src) {
    dest->size = src->size;
    int memsize = src->size * sizeof(*src->items);
    dest->items = malloc(memsize);
    memcpy(dest->items, src->items, memsize);
}

void __dispose_vector(Vector *v) {
    if (v->size > 0 && v->items != NULL) {
        free(v->items);
    }
    v->items = NULL;
    v->size = 0;
}

int test_vector_print() {
  Vector v1 = __load_vector();
  printf("result: ");
  vector_print(&v1);
  __dispose_vector(&v1);
  return 0;
}

int test_vector_ctor() {
  Vector v1;
  int size;
  scanf("%d", &size);

  int status = vector_ctor(&v1, size);
  printf("vector_ctor returned: %d\n", status);
  __vector_print("result: ", &v1);
  __dispose_vector(&v1);
  return 0;
}

int test_vector_init() {
  Vector v1 = __load_vector();

  vector_init(&v1);
  __vector_print("result: ", &v1);
  __dispose_vector(&v1);
  return 0;
}

int test_vector_dtor() {
  Vector v1 = __load_vector();

  vector_dtor(&v1);
  __vector_print("result: ", &v1);
  __dispose_vector(&v1);
  return 0;
}

int test_vector_scalar_multiply() {
  Vector v1 = __load_vector();
  int multiplier;
  scanf("%d", &multiplier);
  
  vector_scalar_multiply(&v1, multiplier);
  __vector_print("result: ", &v1);
  __dispose_vector(&v1);
  return 0;
}

int test_vector_add() {
  Vector v1 = __load_vector();
  Vector v2 = __load_vector();
  
  int status = vector_add(&v1, &v2);
  printf("vector_add returned: %d\n", status);
  __vector_print("result: ", &v1);
  __dispose_vector(&v1);
  __dispose_vector(&v2);
  return 0;
}

int test_vector_sub() {
  Vector v1 = __load_vector();
  Vector v2 = __load_vector();
  
  int status = vector_sub(&v1, &v2);
  printf("vector_sub returned: %d\n", status);
  __vector_print("result: ", &v1);

  __dispose_vector(&v1);
  __dispose_vector(&v2);
  return 0;
}

const char *test_names[] = {
    "test_vector_print",
    "test_vector_ctor",
    "test_vector_init",
    "test_vector_dtor",
    "test_vector_scalar_multiply",
    "test_vector_add",
    "test_vector_sub",
};

int (*tests[])() = {
    &test_vector_print,
    &test_vector_ctor,
    &test_vector_init,
    &test_vector_dtor,
    &test_vector_scalar_multiply,
    &test_vector_add,
    &test_vector_sub,
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
