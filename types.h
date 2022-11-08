/**
 * Hlavičkový soubor types.h
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */
#include <stdbool.h>

#ifndef TYPES_H
#define TYPES_H

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
