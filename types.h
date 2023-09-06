/**
 * Hlavičkový soubor types.h
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */

#ifndef TYPES_H
#define TYPES_H

// maximální počet prvků v množině
// (za použití všech dostupných prvků)
#define MAXITEMS 10

// zcela všechny prvky, které nám jsou ve všech množinách k dispozici
extern const int UNIVERSUM[MAXITEMS];

// TODO: 1. seznamte se s definovanými datovými typy

typedef struct {
  // prvky množiny, MAXITEMS určuje maximální počet,
  //  ne ovšem ten skutečný
  int items[MAXITEMS];
  // skutečný počet prvků v množině, vždy platí:
  //  0 <= cardinality <= MAXITEMS
  int cardinality;
} Set;

typedef struct {
  int first;  // první prvek dvojice
  int second; // druhý prvek dvojice
} Pair;

// DEKLAROVANÉ HLAVIČKY FUNKCÍ NIJAK NEMĚŇTE

int rel_isFunction(Pair pairs[], int pairCount, Set set);

int rel_minMax(Pair pairs[], int pairCount, int *relMin, int *relMax);

int rel_isEquivalence(Pair pairs[], int pairCount, Set set);

#endif
