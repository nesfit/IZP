/**
 * Zdrojový soubor test.c
 *  Obsahuje logiku pro automatické testování.
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */

#include "test.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void run_automated_tests(char **args, int argc) {
  printf("\n\n=== AUTOMATED TESTS ===\n");

  Config __config = {
    .xFlag = false,
    .yFlag = false,
    .sValue = NULL,
    .nValue = 10
  };

  int __status = parse_args(args, argc, &__config);
  printf("parse success: %s\n", __status == 0 ? "Yes" : "No");
  printf("xFlag: %s\n", __config.xFlag ? "True" : "False");
  printf("yFlag: %s\n", __config.yFlag ? "True" : "False");
  printf("sValue: %s\n", __config.sValue ? __config.sValue : "#null#");
  printf("nValue: %u\n", __config.nValue);
}