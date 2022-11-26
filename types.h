/**
 * Hlavičkový soubor types.h
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */

#ifndef TYPES_H
#define TYPES_H

// DEKLAROVANÉ HLAVIČKY FUNKCÍ NIJAK NEMĚŇTE

typedef unsigned long long int ull;

extern ull fib_calls;
extern ull fib_fast_calls;

ull fib(ull n);

ull fib_fast(ull n);

#endif
