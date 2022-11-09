#include "test.h"
#include "types.h"
#include <stdio.h>


const char *usage = "syntax: program [-x|-y] [-n COUNT] -s STR\n"
  "    -x and -y are optional and mutually exclusive\n"
  "    -s STR - mandatory, STR is a string\n"
  "    -n COUNT - optional, COUNT is non-negative integer (default: 10)\n";


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

  // spouštění automatizovaných testů neměňte
  run_automated_tests(argv, argc);
  return 0;
}

/**
 * Zpracuje argumenty příkazové řádky programu.
 *   Výsledky ukládá do struktury Config z parametrů metody.
 * 
 * Duplicity žádných přepínačů nejsou dovoleny.
 * 
 * @param arguments      pole argumentů z CLI
 * @param argumentCount  velikost pole argumentů
 * @param config         ukazatel na výstupní konfiguraci
 * 
 * @returns hodnotu 1 při úspěšném zpracování, 0 jinak
 * 
 * Hlavičky žádných funkcí NEMĚŇTE!
 */
int parse_args(char **arguments, int argumentCount, Config *config) {
  // TODO: 1. implementujte funkci dle specifikace zadání
  //   a chování jednotlivých přepínačů

  return -1;
}
