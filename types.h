/**
 * Hlavičkový soubor types.h
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */
#include <stdbool.h>

#ifndef TYPES_H
#define TYPES_H

typedef struct {
    bool xFlag;
    bool yFlag;
    char *sValue;
    unsigned nValue;
} Config;


// DEKLAROVANÉ HLAVIČKY FUNKCÍ NIJAK NEMĚŇTE

int parse_args(char **arguments, int argumentCount, Config *config);

#endif
