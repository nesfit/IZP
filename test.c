/**
 * Zdrojový soubor test.c
 *  Obsahuje logiku pro automatické testování.
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */

#include "test.h"
#include <stdio.h>


#ifdef TEST_BUILD

int main(int argc, char *argv[]) {
  print_args(argv, argc);
  run_automated_tests();
  return 0;
}

#endif

void run_automated_tests() {
  // TODO: add custom tests
}
