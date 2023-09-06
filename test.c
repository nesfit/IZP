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

void __vector_fprint(FILE *file, char *prefix, Vector *v) {
    fprintf(file, "%sVector(%d) = ", prefix, v->size);
    if (v->items == NULL) {
        fprintf(file, "(null)\n");
        return;
    }

    fprintf(file, "[");
    for (int i = 0; i < v->size - 1; i++) {
        fprintf(file, "%d, ", v->items[i]);
    }

    if (v->size > 0) {
        fprintf(file, "%d", v->items[v->size - 1]);
    }
    fprintf(file, "]\n");
}

Vector __load_vector(void) {
    Vector v;
    scanf("%d", &v.size);
    v.items = v.size ? malloc(v.size * sizeof(*v.items)) : NULL;
    for (int i = 0; i < v.size; i++) {
        scanf("%d", &v.items[i]);
    }

    __vector_fprint(stderr, "loaded: ", &v);
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

#pragma endregion

int test_vector_print(int argc, char **argv) {
  Vector v1 = __load_vector();
  printf("");
  vector_print(&v1);

  __dispose_vector(&v1);
  return 0;
}

int test_vector_ctor(int argc, char **argv) {
  Vector v1;
  int size;
  scanf("%d", &size);

  int status = vector_ctor(&v1, size);
  printf("vector_ctor returned: %d\n", status);
  __vector_fprint(stdout, "", &v1);

  __dispose_vector(&v1);
  return 0;
}

int test_vector_init(int argc, char **argv) {
  Vector v1 = __load_vector();

  vector_init(&v1);
  __vector_fprint(stdout, "", &v1);

  __dispose_vector(&v1);
  return 0;
}

int test_vector_dtor(int argc, char **argv) {
  Vector v1 = __load_vector();

  vector_dtor(&v1);
  __vector_fprint(stdout, "", &v1);

  __dispose_vector(&v1);
  return 0;
}

int test_vector_scalar_multiply(int argc, char **argv) {
  Vector v1 = __load_vector();
  int multiplier;
  scanf("%d", &multiplier);
  
  vector_scalar_multiply(&v1, multiplier);
  __vector_fprint(stdout, "", &v1);

  __dispose_vector(&v1);
  return 0;
}

int test_vector_add(int argc, char **argv) {
  Vector v1 = __load_vector();
  Vector v2 = __load_vector();
  
  int status = vector_add(&v1, &v2);
  printf("vector_add returned: %d\n", status);
  __vector_fprint(stdout, "", &v1);

  __dispose_vector(&v1);
  __dispose_vector(&v2);
  return 0;
}

int test_vector_sub(int argc, char **argv) {
  Vector v1 = __load_vector();
  Vector v2 = __load_vector();
  
  int status = vector_sub(&v1, &v2);
  printf("vector_sub returned: %d\n", status);
  __vector_fprint(stdout, "", &v1);

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

int (*tests[])(int, char **) = {
    &test_vector_print,
    &test_vector_ctor,
    &test_vector_init,
    &test_vector_dtor,
    &test_vector_scalar_multiply,
    &test_vector_add,
    &test_vector_sub,
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
