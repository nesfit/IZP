#include "types.h"
#include <stdio.h>

const int UNIVERSUM[MAXITEMS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

#ifndef TEST_BUILD

int main(void) {
  Set set = {.items = {1, 2, 3, 4, 5}, .cardinality = 5};

  const int pairCount = 3;
  // TODO: 2. staticky inicializujte pole struktur Pair
  Pair pairs[pairCount];

  // TODO: 3., 4., 5. zavolejte implementované funkce a vypište své výsledky

  return 0;
}

#endif

/**
 * @param pairs      Prvky nějaké binární relace (pole dvojic)
 * @param pairCount  Počet položek (dvojic) v relaci
 * @param set        Množina nad kterou je relace definována
 * 
 * @returns hodnotu 1 pokud relace je funkcí, 0 jinak
 */
int rel_isFunction(Pair pairs[], int pairCount, Set set) {
  // TODO: 3. definujte a implementujte funkci rel_isFunction
  return -1;
}

/**
 * @param pairs      Prvky nějaké binární relace (pole dvojic)
 * @param pairCount  Počet položek (dvojic) v relaci
 * @param relMin     Ukazatel na proměnnou minimální hodnoty relace
 * @param relMax     Ukazatel na proměnnou maximální hodnoty relace
 *
 * @returns hodnotu 1 pokud bylo hledání úspěšné, 0 jinak
 */
int rel_minMax(Pair pairs[], int pairCount, int *relMin, int *relMax) {
  // TODO: 4. definujte a implementujte funkci rel_minMax
  return -1;
}

/**
 * @param pairs      Prvky nějaké binární relace (pole dvojic)
 * @param pairCount  Počet položek (dvojic) v relaci
 * @param set        Množina nad kterou je relace definována
 * 
 * @returns hodnotu 1 pokud relace je relací ekvivalence, 0 jinak
 */
int rel_isEquivalence(Pair pairs[], int pairCount, Set set) {
  // TODO: 5. definujte a implementujte funkci rel_isEquivalence
  return -1;
}
