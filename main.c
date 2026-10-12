#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Constructor.
 * Set the person data from the parameters at the location referenced by p.
 *
 * @param p Pointer to an existing person instance.
 * @param birthYear Year of birth of the person.
 * @param name Name of the person.
 */
void person_ctor(Person *p, unsigned birthYear, const char *name) {
  p->birthYear = birthYear;
  p->name = malloc(strlen(name) + 1);
  strcpy(p->name, name);
}

/**
 * Destructor.
 * Destroy the person record.
 *
 * @param p Pointer to an existing person instance.
 */
void person_dtor(Person *p) {
  p->birthYear = 0;
  p->name = NULL;
}

/**
 * Move the person data from src to dst.
 *
 * @param src Pointer to an existing source instance.
 * @param dst Pointer to an existing destination instance.
 */
void person_move(Person *src, Person *dst) { *dst = *src; }

/**
 * Copy the person data from src to dst.
 *
 * Use: person_ctor
 *
 * @param src Pointer to an existing source instance.
 * @param dst Pointer to an existing destination instance.
 *
 * @return Pointer to the destination instance.
 */
void *person_copy(Person *src, Person *dst) {
  *dst = *src;
  return dst;
}

/**
 * Swap two existing person instances.
 *
 * @param a Pointer to an existing person instance.
 * @param b Pointer to an existing person instance.
 */
void person_swap(Person *a, Person *b) {
  Person tmp = *a;
  *a = *b;
  *b = tmp;
}

/**
 * Compare two person instances.
 *
 * @param a Pointer to an existing person instance.
 * @param b Pointer to an existing person instance.
 *
 * @return A value <0 if a < b, >0 if b < a,
 * or 0 otherwise (a == b).
 */
int person_cmp(Person *a, Person *b) {
  if (a->birthYear < b->birthYear) {
    return -1;
  }
  if (a->birthYear > b->birthYear) {
    return +1;
  }

  return strcmp(a->name, b->name);
}

/**
 * Print the contents of a person instance to standard output.
 *
 * @param p Pointer to an existing person instance.
 */
void person_print(Person *p) {
  if (p == NULL) {
    printf("(null)");
    return;
  }
  printf("Person { .birthYear=%d, .name=%s }", p->birthYear, p->name);
}

/**
 * Constructor.
 * Initialize a zero-size person array in already allocated memory.
 *
 * @param array Pointer to an existing person array instance.
 */
void array_ctor(PersonArray *array) {
  array->length = 0;
  array->items = NULL;
}

/**
 * Destructor.
 * Destroy and free the allocated array and all its existing items.
 *
 * @param array Pointer to an existing person array instance.
 */
void array_dtor(PersonArray *array) {
  // TODO: Implement this function.
}

/**
 * Increase the array size by one.
 * Do not modify the newly allocated item.
 *
 * @param array Pointer to an existing person array instance.
 *
 * @return Pointer to the allocated memory, `NULL` if allocation fails.
 */
void *array_expand(PersonArray *array) {
  void *p = realloc(array->items, (array->length + 1) * sizeof(Person));
  if (p == NULL) {
    return NULL;
  }

  array->length++;
  return array->items = p;
}

/**
 * Expand the existing array and insert a new element at its end.
 *
 * @param array Pointer to an existing person array instance.
 * @param p Pointer to an existing person instance.
 *
 * @return Pointer to the allocated memory, `NULL` if allocation fails.
 */
void *array_append(PersonArray *array, Person *p) {
  if (array_expand(array)) {
    return person_copy(p, &array->items[array->length - 1]);
  }

  return NULL;
}

/**
 * Remove the existing array element at the specified index.
 * Reduce the allocated array size after removal.
 *
 * @param array Pointer to an existing person array instance.
 * @param index Position of the element to remove.
 */
void array_remove(PersonArray *array, unsigned int index) {
  for (unsigned i = index + 1; i < array->length; i++) {
    person_move(&array->items[i - 1], &array->items[i]);
  }

  if (array->length) {
    array->items = realloc(array->items, (array->length - 1) * sizeof(Person));
    if (array->items) {
      array->length--;
    }
  }
}

/**
 * Find the person in the array with the smallest year of birth
 * (or whose name comes first alphabetically).
 * Search for the minimum only from the selected index
 * (use startIndex=0 to search the entire array).
 *
 * Use: person_cmp
 *
 * @param array Pointer to an existing person array instance.
 * @param startIndex Starting index for the search.
 *
 * @return Index of the smallest array element if found, -1 otherwise.
 */
int array_find_min(PersonArray *array, unsigned int startIndex) {
  // TODO: Implement this function.
  return -2;
}

/**
 * Sort the array elements by year of birth (or by name).
 * Implement the selection-sort algorithm.
 *
 * Use: array_find_min, person_swap
 *
 * @param array Pointer to an existing person array instance.
 */
void array_sort(PersonArray *array) {
  // TODO: Implement this function.
}

/**
 * Print the elements of the person array.
 *
 * @param array Pointer to an existing array.
 */
void array_print(PersonArray *array) {
  for (unsigned i = 0; i < array->length; i++) {
    if (i) {
      putchar('\n');
    }
    printf("- ");
    person_print(&array->items[i]);
  }
  putchar('\n');
}

#ifndef TEST_BUILD

/**
 * Program entry point.
 *
 * @param argc Number of command-line arguments.
 * @param argv Command-line arguments.
 *
 * @return Program exit status.
 */
int main(int argc, char *argv[]) {
  PersonArray a;
  array_ctor(&a);

  // Create several people.
  Person p1;
  person_ctor(&p1, 2000, "Bill");
  Person p2;
  person_ctor(&p2, 2010, "Amanda");
  Person p3;
  person_ctor(&p3, 1990, "Joe");

  // COPY the people into the array one by one (at the end, append).
  array_append(&a, &p1);
  array_append(&a, &p2);
  array_append(&a, &p3);

  // Create a fourth person whose year differs from the first person.
  p1.birthYear = 1990;
  array_append(&a, &p1);

  // Destroy the temporarily created person records.
  // All people should have a record in the array.
  person_dtor(&p1);
  person_dtor(&p2);
  person_dtor(&p3);

  array_print(&a);

  // Find the first element.
  unsigned int idx = array_find_min(&a, 0);
  printf("Minimalni prvek v poli je na indexu: %u\n", idx);

  // Sort the array.
  array_sort(&a);

  array_print(&a);
  array_dtor(&a);

  return 0;
}

#endif
