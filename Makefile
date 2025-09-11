all: main

CC = clang
override CFLAGS += -std=c11 -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter -Wno-unused-result -Wno-unknown-pragmas -pedantic -lm

.PHONY: run clean

main: main.c
	$(CC) $(CFLAGS) -O0 ./*.c -o "$@"

main-debug: main.c
	$(CC) $(CFLAGS) -O0 -g ./*.c -o "$@"

run: main
	./main $(ARGS)

clean:
	rm -f main main-*
