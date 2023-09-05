all: main

CC = gcc
override CFLAGS += -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter -Wno-unused-result -pedantic -lm

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

.PHONY: run test submit clean§

main: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -O0 $(SRCS) -o "$@"

main-test: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -DTEST_BUILD=1 $(SRCS) -o "$@"

main-solution: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -DTEST_BUILD=1 -DSOLUTION_BUILD=1 test.c solution/*.c -o "$@"

test:
	@./.tests/scripts/run_tests.sh

submit:
	@PROJECT_SUBMIT_MODE=sources ECHO_QUIET=1 ./.tests/scripts/run_tests.sh

clean:
	rm -f main main-*
