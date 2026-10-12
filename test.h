/**
 * @file test.h
 * Declarations of helper functions for automated testing.
 *
 * Do not modify this file.
 */

#include <stdio.h>

#ifndef TEST_H
#define TEST_H

#define TEST_ERR_NOT_FOUND 99
#define TEST_ERR_WRONG_INVOCATION 98
#define TEST_ERR_SYSTEM_FAILURE 97

void __print_array(FILE *target, int *array, int length);

int __load_array(int **array);

#endif
