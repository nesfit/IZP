#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("argc=%d\n", argc);
  for (int argi = 1; argi < argc; argi++) {
    printf("argv[%d]=%s\n", argi, argv[argi]);
  }

  return 0;
}
