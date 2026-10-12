#ifndef _SLL_H
#define _SLL_H

#include <stdbool.h>

/**
 * Object structure.
 */
typedef struct {
  int id;
  char *name;
} Object;

/**
 * List item.
 */
typedef struct item Item;
struct item {
  Object data;
  Item *next;
};

/**
 * List type.
 */
typedef struct {
  Item *first;
} List;

/**
 * Initialize the data for one node, making a deep copy of name on the heap.
 *
 * @param id Object identifier.
 * @param name Object name.
 *
 * @return Initialized object.
 */
Object object_ctor(int id, char *name);

/**
 * Initialize a list item. Create an item without a successor from the object.
 *
 * @param data Object data for the item.
 *
 * @return Pointer to the created list item.
 */
Item *item_ctor(Object data);

/**
 * Initialize a list. Create an empty list.
 *
 * @return Empty list.
 */
List list_ctor(void);

/**
 * Insert an item at the beginning of the list.
 *
 * @param list Pointer to the list.
 * @param i Item to insert.
 */
void list_insert_first(List *list, Item *i);

/**
 * Check whether the list is empty.
 *
 * @param list Pointer to the list.
 *
 * @return `true` if the list is empty, `false` otherwise.
 */
bool list_empty(List *list);

/**
 * Remove the first list element, if there is one.
 *
 * @param list Pointer to the list.
 */
void list_delete_first(List *list);

/**
 * Count the list items.
 *
 * @param list Pointer to the list.
 *
 * @return Number of list items.
 */
unsigned list_count(List *list);

/**
 * Find the list item with the smallest identifier.
 *
 * @param list Pointer to the list.
 *
 * @return Pointer to the item, `NULL` if the list is empty.
 */
Item *list_find_minid(List *list);

/**
 * Find the list item whose object has the specified name.
 *
 * @param list Pointer to the list.
 * @param name Object name to find.
 *
 * @return Pointer to the item, `NULL` if no such item exists in the list.
 */
Item *list_find_name(List *list, char *name);

/**
 * Free the list.
 *
 * @param list Pointer to the list.
 */
void list_dtor(List *list);

#endif
