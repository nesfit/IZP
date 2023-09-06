#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef TEST_BUILD

int main(int argc, char *argv[]) {
  // konfigurace programu
  Config config = { 
    .xFlag = false,
    .yFlag = false,
    .sValue = NULL,
    .nValue = 10
  };

  // TODO: 2. odpovídajícím způsobem zavolejte funkci parse_args
  // TODO: 3. v případě chyby zpracování vypište obsah
  //   globální proměnné usage na chybový výstup
  //   a ukončente program s chybovým kódem 1

  return 0;
}

#endif

/**
 * Zpracuje argumenty příkazové řádky programu.
 *   Výsledky ukládá do struktury Config z parametrů metody.
 * 
 * Duplicity žádných přepínačů nejsou dovoleny.
 * 
 * Hlavičky žádných funkcí NEMĚŇTE!
 * 
 * @param arguments      pole argumentů z CLI
 * @param argumentCount  velikost pole argumentů
 * @param config         ukazatel na výstupní konfiguraci
 * 
 * @returns hodnotu 1 při úspěšném zpracování, 0 jinak
 */
int parse_args(char **arguments, int argumentCount, Config *config) {
  // TODO: 1. implementujte funkci dle specifikace zadání
  //   a chování jednotlivých přepínačů

  return -1;
}
