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
 * Vytiskne vektor (velikost a jeho prvky) na standardní výstup.
 * 
 * @param v  ukazatel na vektor
 */
void vector_print(Vector *v)
{
  // TODO: implementujte funkci dle zadání
}

/**
 * Vytvoří (dynamicky alokuje) vektor o specifikovaném rozměru.
 *   Nově alokovaná paměť a korespondující počet prvků
 *   je do struktury uložen prostřednictvím ukazatele v.
 * 
 * @param v     ukazatel na strukturu vektoru
 * @param size  počet prvků vektoru (rozměr)
 * 
 * @returns hodnotu 1 v případě úspěšné alokace, 0 jinak
 */
int vector_ctor(Vector *v, unsigned int size)
{
  // TODO: implementujte funkci dle zadání
  return -1;
}

/**
 * Inicializuje prvky vektoru na číselnou posloupnost
 *   od 0 do velikosti vektoru - 1.
 * 
 * Příklad:
 *   Vector3 [0, 1, 2]
 *   Vector5 [0, 1, 2, 3, 4]
 * 
 * @param v  ukazatel na existující vektor
 */
void vector_init(Vector *v)
{
  // TODO: implementujte funkci dle zadání
}

/**
 * Provede zrušení (uvolnění alokované paměti) daného vektoru.
 *   Ukazatel na prvky zrušeného vektoru je NULL.
 *   Rozměr zrušeného vektoru je 0.
 * 
 * @param v  ukazatel na existující vektor
 */
void vector_dtor(Vector *v)
{
  // TODO: implementujte funkci dle zadání
}

/**
 * Provede výpočet skalárního součinu vektoru s daným číslem.
 *   Výpočet se provádí nad hodnotami poskytnutého vektoru v,
 *   změny probíhají tzv. in-place, bez alokace nového vektoru.
 * 
 * @param v       ukazatel na existující vektor
 * @param scalar  skalární hodnota
 */
void vector_scalar_multiply(Vector *v, int scalar)
{
  // TODO: implementujte funkci dle zadání
}

/**
 * Provede součet dvou vektorů v1 + v2.
 *   Výpočet se provádí nad hodnotami poskytnutého vektoru v1,
 *   změny probíhají tzv. in-place, bez alokace nového vektoru.
 * 
 * Vzájemně kontrolujte rozměry obou vektorů!
 *   Operaci nelze provádět nad vektory různých rozměrů.
 * 
 * @param v1  ukazatel na první vektor
 * @param v2  ukazatel na druhý vektor
 * 
 * @returns hodnotu 1 při úspěšném sečtení, 0 jinak
 */
int vector_add(Vector *v1, Vector *v2)
{
  // TODO: implementujte funkci dle zadání
  return -1;
}

/**
 * Provede odečtení dvou vektorů v1 + v2.
 *   Výpočet se provádí nad hodnotami poskytnutého vektoru v1,
 *   změny probíhají tzv. in-place, bez alokace nového vektoru.
 * 
 * Vzájemně kontrolujte rozměry obou vektorů!
 *   Operaci nelze provádět nad vektory různých rozměrů.
 * 
 * @param v1  ukazatel na první vektor
 * @param v2  ukazatel na druhý vektor
 * 
 * @returns hodnotu 1 při úspěšném odečtení, 0 jinak
 */
int vector_sub(Vector *v1, Vector *v2)
{
  // TODO: implementujte funkci dle zadání
  return -1;
}
