#include "test.h"
#include "types.h"
#include <stdio.h>

// fixed array size
#define ARR_SIZE 10


int main(int argc, char *argv[]) {
  // TODO: 0. Inicializujte staticky alokované pole
  int array[ARR_SIZE];

  // TODO: 1b. Vytiskněte pole voláním funkce array_print
  
  // TODO: 2b. Pronásobte hodnoty pole libovolným číslem
  // TODO: 2c. V případě chyby informujte uživatele
  // TODO: 2d. Vytiskněte aktualizované pole
  
  // TODO: 3b. Vložte libovolnou hodnotu na indexy 3 a 7
  // TODO: 3c. V případě chyby informujte uživatele
  // TODO: 3d. Vytiskněte aktualizované pole

  // spouštění automatizovaných testů neměňte
  run_automated_tests();
  return 0;
}

/**
 * Vytiskne obsah pole na standardní výstup programu.
 * 
 * @param array       pole, do kterého bude nový prvek vložen
 * @param size        velikost pole
 * @param multiplier  násobitel
 * 
 * Hlavičky žádných funkcí NEMĚŇTE!
 */
void array_print(int array[], int size) {
  // TODO: 1a. implementujte funkci dle zadání
}

/**
 * Vynásobí všechny prvky zadaného pole zvolenou hodnotou.
 * 
 * @param array       pole, jehož hodnoty budou násobeny
 * @param size        velikost pole
 * @param multiplier  násobitel
 * 
 * Hlavičky žádných funkcí NEMĚŇTE!
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
 * @param array     pole, do kterého bude nový prvek vložen
 * @param size      velikost pole
 * @param value     hodnota k vložení
 * @param position  index na který bude hodnota vložena
 * 
 * @returns hodnotu 1 pokud vložení proběhlo úspšně, 0 jinak
 * 
 * Hlavičky žádných funkcí NEMĚŇTE!
 */
int array_insert(int array[], int size, int value, int position) {
  // TODO: 3a. implementujte funkci dle zadání
  return -1;
}
