#include "test.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>


#ifndef TEST_BUILD

int main(int argc, char *argv[]) {
  
  // TODO: volejte vámi implementované funkce
  return 0;
}

#endif


/**
 * Na haldě dynamicky alokuje a inicializuje nový vektor o nulovém rozměru.
 * 
 * @returns ukazatel na alokovanou paměť v případě úspěšné alokace, NULL jinak
 * 
 * hint: malloc, sizeof
 */
Vector *vector_ctor()
{
  // TODO: implementujte funkci dle zadání
  return NULL;
}


/**
 * Provede zrušení (uvolnění alokované paměti) daného vektoru.
 * A to jak jeho prvků, tak vektoru samotného.
 * 
 * @param v  ukazatel na existující vektor
 * 
 * hint: free
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
 * Přidá do vektoru jednu novou složku (komponenetu) a vektor automaticky rozšíří.
 * 
 * @param v       ukazatel na existující vektor
 * @param value   hodnota, která má být přidána do vektoru
 * 
 * @returns hodnotu 1 v případě úspěšného přidání složky do vektoru, 0 jinak
 * 
 * hint: realloc, sizeof
 */
int vector_add(Vector *v, int value)
{
  // TODO: implementujte funkci dle zadání
  return -1;
}
