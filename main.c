#include "test.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TEST_BUILD

int main(int argc, char *argv[]) {
  // TODO: volejte vámi implementované funkce
  return 0;
}

#endif


/**
 * Zjistí délku řetězce ukončeného znakem '\0'
 * 
 * @param str pointer řetězec, který je ukončen znakem '\0'
 * 
 * @returns délku řetězce ve znacích BEZ započítání '\0'
 * 
 */
size_t str_len(char *str) {
  // TODO: volejte vámi implementované funkce
  return 420;
}

/**
 * Kopíruje data po bytech v paměti o dane velikosti
 * 
 * @param dest pointer na paměť do které se kopíruje
 * @param src pointer na paměť ze které se kopíruje
 * @param n velikost kopírované paměti v bytech
 * 
 * Zdroj dat ke kopírování není změněn.
 * 
 * hint: (char *) k pretypovani z void*
 */
void mem_cpy(void *dest, void *src, size_t n)
{
  // TODO: volejte vámi implementované funkce
}

/**
 * Najde první výskyt podřetězce v řetězci
 * 
 * @param str pointer na řetězec ve kterém se vyhledává
 * @param substr pointer na vyhledávaný podřetězec 
 * 
 * @returns index na kterém v řetězci začíná podřetězec,
 *  nebo -1 pokud se podřetězec v řetězci nenachází.
 * 
 * Ani jeden z řetězců není změněn.
 */
int find_substr(char *str, char *substr) {
  // TODO: volejte vámi implementované funkce
  return -2;
}

/**
 * Nahradí nahrazovaný podřetězec za nahrazující podřetězec v řetězci,
 * kde oba podřetězce jsou o stejné délce.
 * 
 * @param str pointer na řetězec ve kterém se vyhledává
 * @param substr pointer na vyhledávaný nahrazovaný podřetězec 
 * @param new_substr pointer na nahrazující podřetězec
 * 
 * Podřetězce nejsou změněny. Pokud nejsou podřetězce stejně dlouhé,
 * funkce substituci neprovede, stejně tak pokud není 
 * podřetězec v řetězci nalezen.
 * 
 * hint: mem_cpy, find_substr, str_len
 */
void replace_same_length(char *str, char *substr, char *new_substr) {
  // TODO: volejte vámi implementované funkce
  (*str) = NULL;
}


/**
 * Nahradí nahrazovaný podřetězec za nahrazující podřetězec v řetězci,
 * kde každý podřetězec může mít jinou velikost. Původní řetězec je uvolněn.
 * 
 * @param str pointer na řetězec ve kterém se vyhledává
 * @param substr pointer na vyhledávaný nahrazovaný podřetězec 
 * @param new_substr pointer na nahrazující podřetězec
 * 
 * @returns pointer na nový řetězec vytvořený v nově alokované paměti v
 * případě úspěchu, pointer na původní řetězec v případě že podřetězec
 *  se v řetězci nenachází, NULL jinak. 
 * 
 * Podřetězce nejsou změněny. V případě chyby není řetězec uvolněn a zůstává
 * nezměněn.
 * 
 * hint: mem_cpy, find_substr, str_len, malloc, free
 */
char *replace(char *str, char *substr, char *new_substr) {
  // TODO: volejte vámi implementované funkce
  return NULL;
}