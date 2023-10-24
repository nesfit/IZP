all: main

CC = gcc
override CFLAGS += -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter -Wno-unused-result -Wno-unknown-pragmas -pedantic -lm

.PHONY: run test submit clean

main: main.c
	$(CC) $(CFLAGS) -O1 ./*.c -o "$@"

main-debug: main.c
	$(CC) $(CFLAGS) -O1 ./*.c -o "$@"

main-test: main.c
	$(CC) $(CFLAGS) -DTEST_BUILD=1 ./*.c -o "$@"

main-solution: main.c
	$(CC) $(CFLAGS) -DTEST_BUILD=1 -DSOLUTION_BUILD=1 test.c solution/*.c -o "$@"

test:
	@./.tests/scripts/run_tests.sh

submit:
	@PROJECT_SUBMIT_MODE=sources ECHO_QUIET=1 ./.tests/scripts/run_tests.sh

clean:
	rm -f main main-*
