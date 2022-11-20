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
    if(v == NULL)
    {
      printf("NULL\n");
      return;
    }
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

Vector* __load_vector() {
    Vector *v = malloc(sizeof(Vector));
    scanf("%d", &(v->size));
    v->items = v->size ? malloc(v->size * sizeof(int)) : NULL;
    for (int i = 0; i < v->size; i++) {
        scanf("%d", &v->items[i]);
    }
    //__vector_print("loaded: ", v);
    return v;
}

void __clone_vector(Vector *dest, Vector *src) {
    dest->size = src->size;
    int memsize = src->size * sizeof(*src->items);
    dest->items = malloc(memsize);
    memcpy(dest->items, src->items, memsize);
}

void __dispose_vector(Vector *v) {
    if(v == NULL)
      return;
    if (v->size > 0 && v->items != NULL) {
        free(v->items);
    }
    v->items = NULL;
    v->size = 0;
    free(v);
}

int test_resize() {
  Vector *v1 = __load_vector();
  int new_size;
  scanf("%d", &new_size);
  v1->items = resize(v1->items, new_size);
  v1->size = new_size;
  for(int i = 0; i < new_size; i++)
  {
    v1->items[i] = i;
  }
  if(new_size == 0)
  {
    v1->items[0] = 69;
  }
  if(new_size < 100)
  {
    __vector_print("result: ", v1);
  }
  __dispose_vector(v1);
  return 0;
}

int test_ctor() {
  Vector *v1 = vector_ctor();

  __vector_print("result: ", v1);
  __dispose_vector(v1);
  return 0;
}

int test_dtor() {
  Vector *v1 = __load_vector();
  vector_dtor(v1);
  printf("%d\n", v1->size != 5);
  v1 = NULL;
  __dispose_vector(v1);
  return 0;
}

int test_vector_add() {
  Vector *v1 = __load_vector();
  for (int i = 0; i < 10; i++)
  {
    vector_add(v1, 69);
  }
  __vector_print("result: ", v1);
  __dispose_vector(v1);
  return 0;
}

const char *test_names[] = {
    "test_resize",
    "test_ctor",
    "test_dtor",
    "test_vector_add",
};

int (*tests[])() = {
    &test_resize,
    &test_ctor,
    &test_dtor,
    &test_vector_add,
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
