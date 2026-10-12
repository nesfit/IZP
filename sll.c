#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "sll.h"

/**
 * Initialize the data for one node, making a deep copy of name on the heap.
 *
 * @param id Object identifier.
 * @param name Object name.
 *
 * @return Initialized object.
 */
Object object_ctor(int id, char *name) {
  // TODO: Implement this function.
}

/**
 * Initialize a list item. Create an item without a successor from the object.
 *
 * @param data Object data for the item.
 *
 * @return Pointer to the created list item.
 */
Item *item_ctor(Object data) {
  // TODO: Implement this function.
}

/**
 * Initialize a list. Create an empty list.
 *
 * @return Empty list.
 */
List list_ctor(void) {
  // TODO: Implement this function.
}

/**
 * Insert an item at the beginning of the list.
 *
 * @param list Pointer to the list.
 * @param i Item to insert.
 */
void list_insert_first(List *list, Item *i) {
  // TODO: Implement this function.
}

/**
 * Check whether the list is empty.
 *
 * @param list Pointer to the list.
 *
 * @return `true` if the list is empty, `false` otherwise.
 */
bool list_empty(List *list) {
  // TODO: Implement this function.
}

/**
 * Remove the first list element, if there is one.
 *
 * @param list Pointer to the list.
 */
void list_delete_first(List *list) {
  // TODO: Implement this function.
}

/**
 * Count the list items.
 *
 * @param list Pointer to the list.
 *
 * @return Number of list items.
 */
unsigned list_count(List *list) {
  // TODO: Implement this function.
}

/**
 * Find the list item with the smallest identifier.
 *
 * @param list Pointer to the list.
 *
 * @return Pointer to the item, `NULL` if the list is empty.
 */
Item *list_find_minid(List *list) {
  // TODO: Implement this function.
}

/**
 * Find the list item whose object has the specified name.
 *
 * @param list Pointer to the list.
 * @param name Object name to find.
 *
 * @return Pointer to the item, `NULL` if no such item exists in the list.
 */
Item *list_find_name(List *list, char *name) {
  // TODO: Implement this function.
}

/**
 * Free the list.
 *
 * @param list Pointer to the list.
 */
void list_dtor(List *list) {
  // TODO: Implement this function.
}
