/**
 * Hlavičkový soubor types.h
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */
#include <stdbool.h>

#ifndef TYPES_H
#define TYPES_H

static const char *usage = "syntax: program [-x|-y] [-n COUNT] -s STR\n"
  "    -x and -y are optional and mutually exclusive\n"
  "    -s STR - mandatory, STR is a string\n"
  "    -n COUNT - optional, COUNT is non-negative integer (default: 10)\n";

typedef struct {
    // indikuje, že přepínač -x byl/nebyl použit
    bool xFlag;
    // indikuje, že přepínač -y byl/nebyl použit
    bool yFlag;
    // uchovává znakový řetězec specifikovaný parametrem -s
    char *sValue;
    // uchovává kladnou celočíselnou hodnotu specifikovanou parametrem -n
    unsigned nValue;
} Config;


// DEKLAROVANÉ HLAVIČKY FUNKCÍ NIJAK NEMĚŇTE

int parse_args(char **arguments, int argumentCount, Config *config);

#endif
