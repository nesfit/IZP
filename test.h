/**
 * Hlavičkový soubor test.h
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */

#ifndef TEST_H
#define TEST_H

#include "types.h"

void run_automated_tests();

void __load_set(Set *set);
Pair *__load_pairs(int *size);
void __dispose(Pair *pairs);

#endif
