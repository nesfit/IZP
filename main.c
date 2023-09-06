#include "types.h"
#include <stdio.h>
#include <stdlib.h>


#ifndef TEST_BUILD

int main(int argc, char *argv[]) {
  // TODO: 1. V nekonečném cyklu čtete nenulové celočíselné hodnoty a jednotlivě je přidávejte do vektoru.
  //   Nulová hodnota ukončuje čtecí cyklus. 
  
  // TODO: 2. Vypište uživateli obsah vektoru a jeho celkovou velikost voláním `vector_print`.

  // TODO: 3. Uvolněte alokovanou paměť.

  return 0;
}

#endif


/**
 * Na haldě dynamicky alokuje a inicializuje nový vektor o nulovém rozměru.
 * 
 * hint: malloc, sizeof
 * 
 * @returns ukazatel na alokovanou paměť v případě úspěšné alokace, NULL jinak
 */
Vector *vector_ctor(void)
{
  // TODO: implementujte funkci dle zadání
  return NULL;
}


/**
 * Provede zrušení (uvolnění alokované paměti) daného vektoru.
 * A to včetně pole jeho komponent.
 * Po uvolnění ukazatel na původní vektor vynulujte.
 * 
 * hint: free
 * 
 * @param v  ukazatel na ukazatel na existující vektor
 */
void vector_dtor(Vector **v)
{
  // TODO: implementujte funkci dle zadání
}


/**
 * Vytiskne vektor (rozměr a všechny jeho prvky) na standardní výstup.
 * 
 * @param v  ukazatel na vektor
 */
void vector_print(Vector *v)
{
  // TODO: implementujte funkci dle zadání
}


/**
 * Změní rozměr vektoru na nove definovaný rozměr.
 * Odpovídajícím způsobem aktualizuje pole komponent a rozměr vektoru.
 * 
 * hint: realloc, sizeof
 * 
 * @param v         ukazatel na existující vektor
 * @param new_size  nový rozměr vektoru (počet složek/komponent)
 * 
 * @returns hodnotu 1 v případě úspěšné změny, 0 jinak
 */
int vector_resize(Vector *v, int new_size)
{
  // TODO: implementujte funkci dle zadání
  return -1;
}


/**
 * Rozšíří rozměr vektoru o jedna a přidá do něj jednu novou složku (komponenetu).
 * Odpovídajícím způsobem aktualizuje pole komponent a rozměr vektoru.
 * 
 * hint: vector_resize
 * 
 * @param v       ukazatel na existující vektor
 * @param value   složka, která má být přidána do vektoru
 * 
 * @returns hodnotu 1 v případě úspěšného přidání složky do vektoru, 0 jinak
 */
int vector_expand(Vector *v, int value)
{
  // TODO: implementujte funkci dle zadání
  return -1;
}
