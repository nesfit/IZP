#include "types.h"
#include <stdio.h>


void print_args(char **argv, int argc) {
  printf("argc=%d\n", argc);
  for (int argi = 1; argi < argc; argi++) {
    printf("argv[%d]=%s\n", argi, argv[argi]);
  }
}

#ifndef TEST_BUILD

int main(int argc, char *argv[]) {
  print_args(argv, argc);
  run_automated_tests();
  return 0;
}

#endif
