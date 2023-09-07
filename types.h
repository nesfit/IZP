/**
 * Hlavičkový soubor types.h
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */

#include <stdbool.h>

#ifndef TYPES_H
#define TYPES_H

// DEKLAROVANÉ HLAVIČKY FUNKCÍ NIJAK NEMĚŇTE

bool is_in_set(int set[], int length, int value);

bool is_set(int set[], int length);

bool is_sorted_set(int set[], int length);

void print_intersection(int set1[], int set2[], int set1_length, int set2_length);

void print_union(int set1[], int set2[], int set1_length, int set2_length);

void print_product(int set1[], int set2[], int set1_length, int set2_length);

#endif
