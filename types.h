/**
 * @file types.h
 * Header file.
 *
 * Do not modify this file.
 */

#ifndef TYPES_H
#define TYPES_H

// Do not change the declared function signatures or structures.

typedef struct {
  unsigned birthYear;
  char *name;
} Person;

typedef struct {
  unsigned length;
  Person *items;
} PersonArray;

// Person Methods
/**
 * Constructor.
 * Set the person data from the parameters at the location referenced by p.
 *
 * @param p Pointer to an existing person instance.
 * @param birthYear Year of birth of the person.
 * @param name Name of the person.
 */
void person_ctor(Person *p, unsigned birthYear, const char *name);

/**
 * Destructor.
 * Destroy the person record.
 *
 * @param p Pointer to an existing person instance.
 */
void person_dtor(Person *p);

/**
 * Move the person data from src to dst.
 *
 * @param src Pointer to an existing source instance.
 * @param dst Pointer to an existing destination instance.
 */
void person_move(Person *src, Person *dst);

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
void *person_copy(Person *src, Person *dst);

/**
 * Swap two existing person instances.
 *
 * @param a Pointer to an existing person instance.
 * @param b Pointer to an existing person instance.
 */
void person_swap(Person *a, Person *b);

/**
 * Compare two person instances.
 *
 * @param a Pointer to an existing person instance.
 * @param b Pointer to an existing person instance.
 *
 * @return A value <0 if a < b, >0 if b < a,
 * or 0 otherwise (a == b).
 */
int person_cmp(Person *a, Person *b);

/**
 * Print the contents of a person instance to standard output.
 *
 * @param p Pointer to an existing person instance.
 */
void person_print(Person *p);

// PersonArray Methods
/**
 * Constructor.
 * Initialize a zero-size person array in already allocated memory.
 *
 * @param array Pointer to an existing person array instance.
 */
void array_ctor(PersonArray *array);

/**
 * Destructor.
 * Destroy and free the allocated array and all its existing items.
 *
 * @param array Pointer to an existing person array instance.
 */
void array_dtor(PersonArray *array);

/**
 * Increase the array size by one.
 * Do not modify the newly allocated item.
 *
 * @param array Pointer to an existing person array instance.
 *
 * @return Pointer to the allocated memory, `NULL` if allocation fails.
 */
void *array_expand(PersonArray *array);

/**
 * Expand the existing array and insert a new element at its end.
 *
 * @param array Pointer to an existing person array instance.
 * @param p Pointer to an existing person instance.
 *
 * @return Pointer to the allocated memory, `NULL` if allocation fails.
 */
void *array_append(PersonArray *array, Person *p);

/**
 * Remove the existing array element at the specified index.
 * Reduce the allocated array size after removal.
 *
 * @param array Pointer to an existing person array instance.
 * @param index Position of the element to remove.
 */
void array_remove(PersonArray *array, unsigned int index);

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
int array_find_min(PersonArray *array, unsigned int startIndex);

/**
 * Sort the array elements by year of birth (or by name).
 * Implement the selection-sort algorithm.
 *
 * Use: array_find_min, person_swap
 *
 * @param array Pointer to an existing person array instance.
 */
void array_sort(PersonArray *array);

/**
 * Print the elements of the person array.
 *
 * @param array Pointer to an existing array.
 */
void array_print(PersonArray *array);

#endif
