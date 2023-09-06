#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "sll.h"

/*
 * Inicializace dat pro jeden uzel, pro name je vyrobena 'deepcopy' na heapu.
 */
Object object_ctor(int id, char* name) {

}

/**
 * Inicializace polozky seznamu. Z objektu vytvori polozku bez naslednika. 
 */
Item *item_ctor(Object data) {

}

/**
 * Inicializace seznamu. Vytvori prazdny seznam.
 */
List list_ctor(void) {

}

/**
 * Vlozi polozku na zacatek seznamu.
 */
void list_insert_first(List *list, Item *i) {

}
 
/**
 * Vrati true, pokud je seznam prazdny.
 */
bool list_empty(List *list) {

}
 
/**
 * Odstrani prvni prvek seznamu, pokud je.
 */
void list_delete_first(List *list) {
    
}
 
/**
 * Vrati pocet polozek seznamu.
 */
unsigned list_count(List *list) {

}
 
 
/**
 * Najde polozku seznamu s nejmensim identifikatorem. Vraci NULL, pokud je
 * seznam prazdny.
 */
Item *list_find_minid(List *list) {

}
 
/**
 * Najde polozku seznamu s odpovidajicim jmenem objektu. Vraci NULL, pokud
 * takova polozka v seznamu neni.
 */
Item *list_find_name(List *list, char *name) {
    
}

 
/**
 * Uvolneni seznamu.
 */
void list_dtor(List *list) {
    
}