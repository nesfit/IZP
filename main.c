#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Konstruktor.
 * Nastaví data o osobě z parametrů do odkazovaného místa p.
 * 
 * @param p          Ukazatel na existující instanci osoby
 * @param birthYear  Rok narození osoby
 * @param name       Jméno osoby
 */
void person_ctor(Person *p, unsigned birthYear, const char *name)
{
  p->birthYear = birthYear;
  p->name = malloc(strlen(name) + 1);
  strcpy(p->name, name);
}

/**
 * Destruktor.
 * Zruší záznam o osobě.
 * 
 * @param p  Ukazatel na existující instanci osoby
 */
void person_dtor(Person *p)
{
  p->birthYear = 0;
  p->name = NULL;
}

/**
 * Přesune data osoby ze src do dst.
 * 
 * @param src  Ukazatel na existující zdrojovou instanci
 * @param dst  Ukazatel na existující cílovou instanci
 */
void person_move(Person *src, Person *dst)
{
  *dst = *src;
}

/**
 * Zkopíruje data osoby ze src do dst.
 * 
 * @param src  Ukazatel na existující zdrojovou instanci
 * @param dst  Ukazatel na existující cílovou instanci
 * 
 * @returns Ukazatel na alokovanou paměť, NULL při neúspěšné alokaci
 * 
 * použijte: person_ctor
 */
void *person_copy(Person *src, Person *dst)
{
  *dst = *src;
  return dst;
}

/**
 * Zamění dvě existující instance osob.
 * 
 * @param a  Ukazatel na existující instanci osoby
 * @param b  Ukazatel na existující instanci osoby
 */
void person_swap(Person *a, Person *b)
{
  Person tmp = *a;
  *a = *b;
  *b = tmp;
}

/**
 * Porovná dvě instance osoby.
 * 
 * @param a  Ukazatel na existující instanci osoby
 * @param b  Ukazatel na existující instanci osoby
 * 
 * @returns
 *   <0 pokud a < b,
 *   >0 pokud b < a,
 *    0 jinak (tedy a == b).
 */
int person_cmp(Person *a, Person *b)
{
  if (a->birthYear < b->birthYear){
    return -1;
  }
  if (a->birthYear > b->birthYear) {
    return +1;
  }

  return strcmp(a->name, b->name);
}

/**
 * Vytiskne obsah instance osoby na standardní výstup.
 * 
 * @param p  Ukazatel na existující instanci osoby
 */
void person_print(Person *p) {
    printf("[%d, %s]", p->birthYear, p->name);
}

/**
 * Konstruktor.
 * Inicializuje pole osob o nulové velikosti v již alokované paměti.
 * 
 * @param array  Ukazatel na existující instanci pole osob
 */
void array_ctor(PersonArray *array)
{
  array->length = 0;
  array->items = NULL;
}

/**
 * Destruktor.
 * Zruší a uvolní alokované pole a všechny v něm existující položky.
 * 
 * @param array  Ukazatel na existující instanci pole osob
 */
void array_dtor(PersonArray *array)
{
  if (array->length) {
    free(array->items);
  }
}

/**
 * Zvětší velikost pole o 1.
 * S nově alokovanou položkou neprovádí žádné změny.
 * 
 * @param array  Ukazatel na existující instanci pole osob
 * 
 * @returns Ukazatel na alokovanou paměť, NULL při neúspěšné alokaci
 */
void *array_expand(PersonArray *array)
{
  void *p = realloc(array->items, (array->length + 1) * sizeof(Person));
  if (p == NULL) {
    return NULL;
  }

  array->length++;
  return array->items = p;
}

/**
 * Rozšíří existující pole a na jeho konec vloží nový prvek;
 * 
 * @param array  Ukazatel na existující instanci pole osob
 * @param p      Ukazatel na existující instanci osoby
 * 
 * @returns Ukazatel na alokovanou paměť, NULL při neúspěšné alokaci
 */
void *array_append(PersonArray *array, Person *p)
{
  if (array_expand(array)) {
    return person_copy(p, &array->items[array->length - 1]);
  }

  return NULL;
}

/**
 * Odstraní z pole existující prvek na zadaném indexu.
 * Po odstranění zmenší alokovanou velikost pole.
 * 
 * @param array  Ukazatel na existující instanci pole osob
 * @param index  Pozice ze které bude prvek odstraněn
 */
void array_remove(PersonArray *array, unsigned int index)
{
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
 * Najde v poli osoby, která má nejmenší rok narození (případně jejíž jméno je dříve v abecedě).
 * Minimum hledá pouze od zvoleného indexu (pro hledání v celém poli startIndex=0).
 * 
 * @param array       Ukazatel na existující instanci pole osob
 * @param startIndex  Počáteční index prohledávání
 * 
 * @returns Index nejmenšího prvku v poli v případě nalezení, -1 jinak
 * 
 * použijte: person_cmp
 */
int array_find_min(PersonArray *array, unsigned int startIndex)
{
  // TODO: implementujte funkci dle popisu
  return -2;
}

/**
 * Seřadí prvky v poli podle rok narození (případně podle jména).
 * Implementujte algoritmem selection-sort.
 * 
 * @param array  Ukazatel na existující instanci pole osob
 * 
 * použijte: array_find_min, person_swap
 */
void array_sort(PersonArray *array)
{
  // TODO: implementujte funkci dle popisu
}

/**
 * Vytiskne prvky pole osob.
 * 
 * @param array  Ukazatel na existující pole
 */
void array_print(PersonArray *array)
{
  for (unsigned i = 0; i < array->length; i++)
  {
    if (i) {
      printf(", ");
    }
    person_print(&array->items[i]);
  }
  putchar('\n');
}

#ifndef TEST_BUILD

int main(int argc, char *argv[])
{
  PersonArray a;
  array_ctor(&a);

  // Vytvorime nekolik osob
  Person p1;
  person_ctor(&p1, 2000, "Bill");
  Person p2;
  person_ctor(&p2, 2010, "Amanda");
  Person p3;
  person_ctor(&p3, 1990, "Joe");

  // Osoby postupne NAKOPIRUJEME do pole (na konec, append)
  array_append(&a, &p1);
  array_append(&a, &p2);
  array_append(&a, &p3);

  // jeste vytvorime ctvrtou osobu, oproti 1. se bude lisit rokem.
  p1.birthYear = 1990;
  array_append(&a, &p1);

  // Odstranime docasne vytvorene zaznamy o osobach
  // Vsechny osoby by mely mit zaznam v poli
  person_dtor(&p1);
  person_dtor(&p2);
  person_dtor(&p3);

  array_print(&a);

  // Najdeme první prvek
  unsigned int idx = array_find_min(&a, 0);
  printf("Minimalni prvek v poli je na indexu: %u\n", idx);

  // Pole seřadíme
  array_sort(&a);

  array_print(&a);
  array_dtor(&a);

  return 0;
}

#endif
