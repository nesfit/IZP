/**
 * Hlavičkový soubor types.h
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */

#ifndef TYPES_H
#define TYPES_H

// DEKLAROVANÉ HLAVIČKY FUNKCÍ A STRUKTUR NIJAK NEMĚŇTE

typedef struct {
  unsigned birthYear;
  char *name;
} Person;

typedef struct {
  unsigned length;
  Person *items;
} PersonArray;

#pragma region Person methods

void person_ctor(Person *p, unsigned birthYear, const char *name);

void person_dtor(Person *p);

void person_move(Person *src, Person *dst);

void *person_copy(Person *src, Person *dst);

void person_swap(Person *a, Person *b);

int person_cmp(Person *a, Person *b);

void person_print(Person *p);

#pragma endregion

#pragma region Person array methods

void array_ctor(PersonArray *arrayrray);

void array_dtor(PersonArray *arrayrray);

void *array_expand(PersonArray *arrayrray);

void *array_append(PersonArray *arrayrray, Person *p);

void array_remove(PersonArray *arrayrray, unsigned int index);

int array_find_min(PersonArray *arrayrray, int startIndex);

void array_sort(PersonArray *arrayrray);

void array_print(PersonArray *arrayrray);

#pragma endregion

#endif
