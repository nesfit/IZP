all: main

CC = gcc
override CFLAGS += -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter -Wno-unused-result -pedantic -lm

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

.PHONY: run test submit clean

main: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -O0 $(SRCS) -o "$@"

test:
	@./.tests/run_tests.sh

submit:
	@PROJECT_SUBMIT_MODE=sources ./.tests/run_tests.sh

clean:
	rm -f main main-debug
