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
 * Zjistí délku řetězce.
 * Všechny řetězce v C jsou ukončeny nulovým bytem.
 * 
 * @param str  vstupní řetězec
 * 
 * @returns délku řetězce (počet znaků řetězce)
 */
size_t str_len(char *str) {
  // TODO: volejte vámi implementované funkce
  return -1;
}

/**
 * Kopíruje data po bytech v paměti o dane velikosti.
 * 
 * Zdroj dat ke kopírování není změněn.
 * Předpokládejte, že v cíli je k dispozici dostatek volné paměti.
 * 
 * hint: (char *) k pretypovani z void*
 * 
 * @param dest  ukazatel na paměť do které se kopíruje
 * @param src   ukazatel na paměť ze které se kopíruje
 * @param n     velikost kopírované paměti v bytech
 */
void mem_cpy(void *dest, void *src, size_t n) {
  // TODO: volejte vámi implementované funkce
}

/**
 * Najde první výskyt podřetězce v řetězci.
 * 
 * Ani jeden z řetězců není změněn.
 * 
 * hint: str_len
 * 
 * @param str     řetězec ve kterém se vyhledává
 * @param substr  vyhledávaný podřetězec 
 * 
 * @returns index na kterém v řetězci začíná podřetězec,
 *  nebo -1 pokud se podřetězec v řetězci nenachází.
 */
int find_substr(char *str, char *substr) {
  // TODO: volejte vámi implementované funkce
  return -2;
}

/**
 * Nahradí podřetězec substr za nahrazující podřetězec v řetězci,
 * kde oba podřetězce jsou o stejné délce.
 * 
 * Podřetězce nejsou změněny.
 * Pokud nejsou podřetězce stejně dlouhé, funkce substituci neprovede,
 * stejně tak pokud podřetězec není v řetězci nalezen.
 * 
 * hint: mem_cpy, find_substr, str_len
 * 
 * @param str         řetězec ve kterém se vyhledává
 * @param substr      vyhledávaný nahrazovaný podřetězec 
 * @param new_substr  nahrazující podřetězec
 */
void replace_same_length(char *str, char *substr, char *new_substr) {
  // TODO: volejte vámi implementované funkce
}


/**
 * Nahradí nahrazovaný podřetězec za nahrazující podřetězec v řetězci,
 * kde každý podřetězec může mít jinou velikost.
 * Původní řetězec je uvolněn.
 * 
 * Podřetězce nejsou změněny.
 * V případě chyby není původní řetězec uvolněn a zůstává nezměněn.
 * 
 * hint: mem_cpy, find_substr, str_len, malloc, free
 * 
 * @param str         dynamicky řetězec ve kterém se vyhledává
 * @param substr      vyhledávaný nahrazovaný podřetězec 
 * @param new_substr  nahrazující podřetězec
 * 
 * @returns nový řetězec vytvořený v nově alokované paměti v případě úspěchu,
 *   pointer na původní řetězec v případě že podřetězec se v řetězci nenachází,
 *   NULL jinak.
 */
char *replace(char *str, char *substr, char *new_substr) {
  // TODO: volejte vámi implementované funkce
  return NULL;
}
