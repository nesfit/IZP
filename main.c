#include "types.h"

const int UNIVERSUM[MAXITEMS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

#ifndef TEST_BUILD

/**
 * Program entry point.
 *
 * @return Program exit status.
 */
int main(void) {
  Set set = {.items = {1, 2, 3, 4, 5}, .cardinality = 5};

  const int pairCount = 3;
  // TODO: 2. Statically initialize the array of Pair structures
  Pair pairs[pairCount];

  // TODO: 3., 4., 5. Call the implemented functions and print their results

  return 0;
}

#endif

/**
 * Determine whether the relation is a function.
 *
 * @param pairs Elements of a binary relation (array of pairs).
 * @param pairCount Number of items (pairs) in the relation.
 * @param set Set over which the relation is defined.
 *
 * @return `true` if the relation is a function, `false` otherwise.
 */
bool rel_isFunction(Pair pairs[], int pairCount, Set *set) {
  // TODO: 3. Define and implement rel_isFunction
  return -1;
}

/**
 * Find the minimum and maximum values of the relation.
 *
 * @param pairs Elements of a binary relation (array of pairs).
 * @param pairCount Number of items (pairs) in the relation.
 * @param relMin Pointer to the minimum value of the relation.
 * @param relMax Pointer to the maximum value of the relation.
 *
 * @return `true` if the search succeeds, `false` otherwise.
 */
bool rel_minMax(Pair pairs[], int pairCount, int *relMin, int *relMax) {
  // TODO: 4. Define and implement rel_minMax
  return -1;
}

/**
 * Determine whether the relation is an equivalence relation.
 *
 * @param pairs Elements of a binary relation (array of pairs).
 * @param pairCount Number of items (pairs) in the relation.
 * @param set Set over which the relation is defined.
 *
 * @return `true` if the relation is an equivalence relation, `false` otherwise.
 */
bool rel_isEquivalence(Pair pairs[], int pairCount, Set *set) {
  // TODO: 5. Define and implement rel_isEquivalence
  return -1;
}
