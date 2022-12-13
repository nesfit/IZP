/**
 * Zdrojový soubor test.c
 *  Obsahuje logiku pro automatické testování.
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */
#include "sll.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List __list_init() {
  List new_list;
  new_list.first = NULL;
  return new_list;
}

int __list_length(List *list)
{
  if (list == NULL) {
    return 0;
  }
  Item* currentItem = list->first;
  int length = 0;
  while(currentItem != NULL)
  {
    currentItem = currentItem->next;
    length++;
  }
  return length;
}

void __print_object(Object obj)
{
  printf("[%d, %s]",obj.id, obj.name); 
}

void __print_item(Item *item) 
{
  if (item == NULL) {
    printf("NULL");
    return;
  }
  __print_object(item->data);
}

void __print_list(List *list) 
{
  if (list == NULL) {
    printf("(NULL)\n");
    return;
  }
  printf("(%d)->",__list_length(list));
  Item* currentItem = list->first;
  while(currentItem != NULL)
  {
    __print_item(currentItem);
    printf("->");
    currentItem = currentItem->next;
  }
  printf("NULL\n");
}

Object __load_object()
{
  char nameLoaded[100];
  char *nameAllocated;
  int id;
  scanf(" id: %d, name: %99[^\n]", &id, (char *)&nameLoaded);
  nameAllocated = malloc(strlen(nameLoaded) + 1);
  strcpy(nameAllocated, nameLoaded);
  Object new_object = { .id = id, .name = nameAllocated };
  return new_object;
}

Item* __load_item()
{
  Item* new_item = malloc(sizeof(Item));
  new_item->data = __load_object();
  new_item->next = NULL;
  return new_item;
}

Item** __load_items(int *count)
{
  if (*count == 0) {
    scanf(" Load %d items:\n", count);
  }
  Item** new_items;
  new_items = malloc((*count) * sizeof(Item*));
  for (int i = 0; i < (*count); i++)
  {
    new_items[i] = __load_item();
  }
  return new_items;
}

void __load_list(List *list)
{
  int count = 0;
  Item **new_items = __load_items(&count);
  Item **next_item = &list->first;
  for (int i = 0; i < count; i++)
  {
    Item* new_item = new_items[i];
    *next_item = new_item;
    next_item = &new_item->next;
  }
  free(new_items);
}

void __dispose_list(List *list)
{
  if (list == NULL) {
    return;
  }
  Item* currentItem = list->first;
  while(currentItem != NULL)
  {
      Item* nextItem = currentItem->next;
      free(currentItem->data.name);
      free(currentItem);
      currentItem = nextItem;
  }
  list->first = NULL;
}

int test_object_ctor() {
  Object o = __load_object();
  Object userO = object_ctor(o.id, o.name);
  __print_object(userO);
  free(userO.name);
  free(o.name);
  return 0;
}

int test_item_ctor() {
  Item *item = item_ctor(__load_object());
  __print_item(item);
  printf("\n");
  free(item->data.name);
  free(item);
  return 0;
}

int test_list_ctor() {
  List list = list_ctor();
  __print_list(&list);
  __dispose_list(&list);
  return 0;
}

int test_insert_first() {
  List list = __list_init();
  __load_list(&list);
  int count;
  scanf(" Insert %d items:", &count);
  Item** items = __load_items(&count);
  for (int i = 0; i < count; i++)
  {
    list_insert_first(&list, items[i]);
    __print_list(&list);
  }
  free(items);
  __dispose_list(&list);
  return 0;
}

int test_list_empty() {
  List list = __list_init();
  __load_list(&list);
  __print_list(&list);
  printf("Is list empty? ");
  if (list_empty(&list))
    printf("Yes\n");
  else
    printf("No\n");
  __dispose_list(&list);
  return 0;
}

int test_list_remove_first() {
  List list = __list_init();
  __load_list(&list);
  __print_list(&list);
  printf("Deleting first item!\n");
  list_delete_first(&list);
  __print_list(&list);
  __dispose_list(&list);
  return 0;
}

int test_list_count() {
  List list = __list_init();
  __load_list(&list);
  __print_list(&list);
  printf("List length: %d\n",list_count(&list));
  __dispose_list(&list);
  return 0;
}

int test_list_find_minid() {
  List list = __list_init();
  __load_list(&list);
  __print_list(&list);
  printf("Looking for an item with lowest ID!\n");
  __print_item(list_find_minid(&list));
  printf("\n");
  __dispose_list(&list);
  return 0;
}

int test_list_find_name() {
  List list = __list_init();
  __load_list(&list);
  __print_list(&list);
  scanf(" Find by name:");
  Item *itemToLookFor = __load_item();
  printf("Looking for an item with name: %s!\n",itemToLookFor->data.name);
  __print_item(list_find_name(&list, itemToLookFor->data.name));
  printf("\n");
  __dispose_list(&list);
  free(itemToLookFor->data.name);
  free(itemToLookFor);
  return 0;
}

int test_list_dtor() {
  List list = __list_init();
  __load_list(&list);
  __print_list(&list);
  printf("Calling destructor!\n");
  list_dtor(&list);
  __print_list(&list);
  return 0;
}

int test_memory_leaks() {
  List list = list_ctor();
  int count = 0;
  Item** items = __load_items(&count);
  __print_list(&list);
  printf("Inserting elements!\n");
  for (int i = count-1; i >= 0; i--)
  {
    list_insert_first(&list, items[i]);
  }
  __print_list(&list);
  printf("Element with the lowest ID: ");
  __print_item(list_find_minid(&list));
  printf("\n");
  printf("Get element with name %s: ",items[0]->data.name);
  __print_item(list_find_name(&list, items[0]->data.name));
  printf("\n");
  printf("Get element with name %s: ",items[count-1]->data.name);
  __print_item(list_find_name(&list, items[count-1]->data.name));
  printf("\n");
  printf("Remove first element!\n");
  list_delete_first(&list);
  printf("Current state:\n");
  __print_list(&list);
  printf("Now call destructor!\n");
  free(items);
  list_dtor(&list);
  printf("Final state:\n");
  __print_list(&list);
  return 0;
}

const char *test_names[] = {
  "test_object_ctor",
  "test_item_ctor",
  "test_list_ctor",
  "test_insert_first",
  "test_list_empty",
  "test_list_remove_first",
  "test_list_count",
  "test_list_find_minid",
  "test_list_find_name",
  "test_list_dtor",
  "test_memory_leaks"
};

int (*tests[])() = {
  &test_object_ctor,
  &test_item_ctor,
  &test_list_ctor,
  &test_insert_first,
  &test_list_empty,
  &test_list_remove_first,
  &test_list_count,
  &test_list_find_minid,
  &test_list_find_name,
  &test_list_dtor,
  &test_memory_leaks
};

#define TEST_COUNT (sizeof(tests) / sizeof(*tests))

int run_test_by_name(const char *test_name) {
  if (test_name != NULL) {
    for (size_t testId = 0; testId < TEST_COUNT; testId++)
    {
      if (strcmp(test_names[testId], test_name) == 0) {
        return tests[testId]();
      }
    }
  }
  
  fprintf(stderr, "could not find test '%s'\n", test_name);
  fprintf(stderr, "supported tets:\n");
  for (size_t testId = 0; testId < TEST_COUNT; testId++)
  {
    fprintf(stderr, "    - %s\n", test_names[testId]);
  }

  return 99;
}

#ifdef TEST_BUILD

int main(int argc, char **args) {
  const char *test_name = getenv("TEST_NAME");
  return run_test_by_name(test_name);
}

#endif
