/**
 * Zdrojový soubor test.c
 *  Obsahuje logiku pro automatické testování.
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */

#include "test.h"
#include <stdio.h>
#include <stdlib.h>

void run_automated_tests() {
  printf("\n\n=== AUTOMATED TESTS ===\n");

  int __relSize;
  Set __set;
  __load_set(&__set);
  Pair *__rel = __load_pairs(&__relSize);

  printf("isFunction: %d\n", rel_isFunction(__rel, __relSize, __set));

  int __relMin, __relMax, __minMaxResult;
  __minMaxResult = rel_minMax(__rel, __relSize, &__relMin, &__relMax);
  printf("minMax: %d, min=%d, max=%d\n", __minMaxResult, __relMin, __relMax);

  printf("isEquivalence: %d\n", rel_isEquivalence(__rel, __relSize));

  __dispose(__rel);
}

void __load_set(Set *set) {
  scanf("%d", &set->cardinality);
  for (int i = 0; i < set->cardinality; i++) {
    scanf("%d", &set->items[i]);
  }
}

Pair *__load_pairs(int *size) {
  scanf("%d", size);
  Pair *pairs = malloc((*size) * sizeof(Pair));
  for (int i = 0; i < *size; i++) {
    scanf("%d %d", &pairs[i].first, &pairs[i].second);
  }

  return pairs;
}

void __dispose(Pair *pairs) { free(pairs); }
