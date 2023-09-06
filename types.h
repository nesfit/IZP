/**
 * Hlavičkový soubor types.h
 *
 *     OBSAH V TOMTO SOUBROU NEUPRAVUJTE!
 */

#ifndef TYPES_H
#define TYPES_H

// DEKLAROVANÉ HLAVIČKY FUNKCÍ A STRUKTUR NIJAK NEMĚŇTE

// Structures allow us to "bundle" number of variables that are related together
// e.g., date consists of year, month and day
//
// To access specific elements of our date structure, we use the "dot" notation:
// date.year, date.month, date.day, etc.

// Date structure
struct date_t
{
    int year;
    int month;
    int day;
};

// Time structure
struct time_t
{
    int hour;
    int min;
    int sec;
};

int is_valid_date(struct date_t date);

int earlier_date(struct date_t date1, struct date_t date2);

#endif
