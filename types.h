/**
 * @file types.h
 * Header file.
 *
 * Do not modify this file.
 */

#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <stdbool.h>

// Maximum number of elements in a set
// (using all available elements)
#define MAXITEMS 10

// All elements available for use in any set
extern const int UNIVERSUM[MAXITEMS];

// TODO: 1. Familiarize yourself with the defined data types

typedef struct {
  /**
   * Set elements; MAXITEMS specifies the maximum count,
   * not the actual count.
   */
  int items[MAXITEMS];
  /**
   * Actual number of elements in the set; always satisfies:
   * 0 <= cardinality <= MAXITEMS
   */
  int cardinality;
} Set;

typedef struct {
  /**
   * First element of the pair.
   */
  int first;
  /**
   * Second element of the pair.
   */
  int second;
} Pair;

// Do not change the declared function signatures.

/**
 * Determine whether the relation is a function.
 *
 * @param pairs Elements of a binary relation (array of pairs).
 * @param pairCount Number of items (pairs) in the relation.
 * @param set Set over which the relation is defined.
 *
 * @return `true` if the relation is a function, `false` otherwise.
 */
bool rel_isFunction(Pair pairs[], int pairCount, Set *set);

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
bool rel_minMax(Pair pairs[], int pairCount, int *relMin, int *relMax);

/**
 * Determine whether the relation is an equivalence relation.
 *
 * @param pairs Elements of a binary relation (array of pairs).
 * @param pairCount Number of items (pairs) in the relation.
 * @param set Set over which the relation is defined.
 *
 * @return `true` if the relation is an equivalence relation, `false` otherwise.
 */
bool rel_isEquivalence(Pair pairs[], int pairCount, Set *set);

#endif
