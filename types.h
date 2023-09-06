/**
 * Hlavičkový soubor types.h
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */
#include <stdbool.h>
#include <stddef.h>

#ifndef TYPES_H
#define TYPES_H

// DEKLAROVANÉ HLAVIČKY FUNKCÍ NIJAK NEMĚŇTE

void mem_cpy(void *dest, void *src, size_t n);

size_t str_len(char *str);

int find_substr(char *str, char *substr);

void replace_same_length(char *str, char *substr, char *new_substr);

char *replace(char *str, char *substr, char *new_substr);

#endif
