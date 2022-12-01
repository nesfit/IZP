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

// Person Methods
void person_ctor(Person *p, unsigned birthYear, const char *name);

void person_dtor(Person *p);

void person_move(Person *src, Person *dst);

void *person_copy(Person *src, Person *dst);

void person_swap(Person *a, Person *b);

int person_cmp(Person *a, Person *b);

void person_print(Person *p);

// PersonArray Methods
void array_ctor(PersonArray *array);

void array_dtor(PersonArray *array);

void *array_expand(PersonArray *array);

void *array_append(PersonArray *array, Person *p);

void array_remove(PersonArray *array, unsigned int index);

int array_find_min(PersonArray *array, unsigned int startIndex);

void array_sort(PersonArray *array);

void array_print(PersonArray *array);

#endif
