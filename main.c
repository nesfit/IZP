#include "types.h"
#include <stdio.h>

// fixed array size
#define ARR_SIZE 10


#ifndef TEST_BUILD

int main(int argc, char *argv[]) {
  // TODO: 0. Staticky inicializujte alokované pole
  int array[ARR_SIZE];

  // TODO: 1b. Vytiskněte pole voláním funkce array_print
  
  // TODO: 2b. Pronásobte hodnoty pole libovolným číslem
  // TODO: 2c. Vytiskněte aktualizované pole
  
  // TODO: 3b. Vložte libovolnou hodnotu na indexy 3 a 7
  // TODO: 3c. V případě chyby informujte uživatele
  // TODO: 3d. Vytiskněte aktualizované pole

  return 0;
}

#endif

/**
 * Vytiskne obsah pole na standardní výstup programu.
 *   Tisk musí proběhnout na jeden řádek, konkrétní
 *   oddělovač jednotlivých prvků není vynucován.
 * 
 * Hlavičky žádných funkcí NEMĚŇTE!
 * 
 * @param array  pole, které bude zobrazeno
 * @param size   velikost pole
 */
void array_print(int array[], int size) {
  // TODO: 1a. implementujte funkci dle zadání
}

/**
 * Vynásobí všechny prvky zadaného pole zvolenou hodnotou.
 * 
 * Hlavičky žádných funkcí NEMĚŇTE!
 * 
 * @param array       pole, jehož hodnoty budou násobeny
 * @param size        velikost pole
 * @param multiplier  násobitel
 */
void array_multiply(int *array, int size, int multiplier) {
  // TODO: 2a. implementujte funkci dle zadání
}

/**
 * Vloží prvek do zadaného pole na zvolený index.
 *   Ostatní prvky přesune směrem doprava, ke konci pole.
 *   Přebývající prvek je smazán.
 * 
 * Hodnoty relevantních vstupních parametrů odpovídajícím
 *   způsobem ošetřete.
 * 
 * Hlavičky žádných funkcí NEMĚŇTE!
 * 
 * @param array     pole, do kterého bude nový prvek vložen
 * @param size      velikost pole
 * @param value     hodnota k vložení
 * @param position  index na který bude hodnota vložena
 * 
 * @returns hodnotu 1 pokud vložení proběhlo úspšně, 0 jinak
 */
int array_insert(int array[], int size, int value, int position) {
  // TODO: 3a. implementujte funkci dle zadání
  return -1;
}
