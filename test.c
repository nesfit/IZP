/**
 * Zdrojový soubor test.c
 *  Obsahuje logiku pro automatické testování.
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */

#include "test.h"
#include <stdio.h>
#include <stdlib.h>


void __array_print(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", arr[i]);
    }
    if (size > 0) {
        printf("%d]\n", arr[size - 1]);
    } else {
        printf("]\n");
    }
}

void run_automated_tests() {
  printf("\n\n=== AUTOMATED TESTS ===\n");

  int __size, *__array = __load(&__size);

  printf("loaded: ");
  array_print(__array, __size);

  int __multiplier;
  scanf("%d", &__multiplier);
  printf("after multiply: ");
  array_multiply(__array, __size, __multiplier);
  __array_print(__array, __size);

  int __insertPairCount;
  scanf("%d", &__insertPairCount);
  for (int i = 0; i < __insertPairCount; i++) {
    int __value, __position;
    scanf("%d %d", &__value, &__position);
    printf("insert: %d\n", array_insert(__array, __size, __value, __position));
  }

  printf("after insert: ");
  __array_print(__array, __size);
  __dispose(__array);
}

int *__load(int *size) {
  scanf("%d", size);
  int *array = malloc((*size) * sizeof(int));
  for (int i = 0; i < *size; i++) {
    scanf("%d", &array[i]);
  }

  return array;
}

void __dispose(int *array) { free(array); }