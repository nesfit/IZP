/**
 * @file types.h
 * Header file.
 *
 * Do not modify this file.
 */

#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>

// Do not change the declared function signatures or structures.

// Structures allow us to "bundle" number of variables that are related together
// e.g., date consists of year, month and day
//
// To access specific elements of our date structure, we use the "dot" notation:
// date.year, date.month, date.day, etc.

#define DATE1_IS_EARLIER -1
#define DATE1_IS_LATER 1
#define DATES_ARE_EQUAL 0

/**
 * Date structure.
 */
struct date_t {
  int year;
  int month;
  int day;
};

/**
 * Time structure.
 */
struct time_t {
  int hour;
  int min;
  int sec;
};

/**
 * Determine whether the provided date is valid. Respect leap years with extra
 * days, different month lengths and assume that the only valid years are above
 * 1500 and below 3000.
 *
 * @param date Data structure representing a date.
 *
 * @return `true` for a valid date, `false` otherwise.
 */
bool is_valid_date(struct date_t date);

/**
 * Find the earlier date by comparing years, months and days.
 *
 * @param date1 Data structure representing the first date.
 * @param date2 Data structure representing the second date.
 *
 * @return `DATE1_IS_EARLIER` if date1 is earlier,
 *   `DATE1_IS_LATER` if date2 is earlier,
 *   `DATES_ARE_EQUAL` otherwise (the dates are equal).
 */
int earlier_date(struct date_t date1, struct date_t date2);

#endif
