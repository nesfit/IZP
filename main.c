#include "types.h"
#include <stdio.h>

/**
 * Determine whether the provided date is valid. Respect leap years with extra
 * days, different month lengths and assume that the only valid years are above
 * 1500 and below 3000.
 *
 * @param date Datová struktura reprezentující datum
 *
 * @return `true` v případě validního data, `false` jinak
 */
bool is_valid_date(struct date_t date) {
  // TODO: implementujte funkci dle zadání
  return false;
}

/**
 * Find the earlier date by comparing years, months and days.
 *
 * @param date1 Datová struktura reprezentující první datum
 * @param date2 Datová struktura reprezentující druhé datum
 *
 * @return `DATE1_IS_EARLIER` v případě že date1 je dřívější,
 *     `DATE1_IS_LATER` když date2 je dřívější,
 *     `DATES_ARE_EQUAL` jinak (data jsou stejná)
 */
int earlier_date(struct date_t date1, struct date_t date2) {
  // TODO: implementujte funkci dle zadání
  return -2;
}

#ifndef TEST_BUILD

int main(void) {
  struct date_t date1, date2;

  // Load two dates from the user
  printf("Provide the first date (format yyyy-mm-dd): ");
  scanf("%d-%d-%d", &date1.year, &date1.month, &date1.day);

  printf("Provide the second date (format yyyy-mm-dd): ");
  scanf("%d-%d-%d", &date2.year, &date2.month, &date2.day);

  // Check that the dates are valid
  if (!is_valid_date(date1) || !is_valid_date(date2)) {
    printf("Invalid date!\n");
    return 1;
  }

  // Compare the dates and find the earlier one
  int earlier_result = earlier_date(date1, date2);
  if (earlier_result == DATE1_IS_EARLIER) {
    printf("The date %d-%d-%d is earlier.\n", date1.year, date1.month,
           date1.day);
  } else if (earlier_result == DATE1_IS_LATER) {
    printf("The date %d-%d-%d is earlier.\n", date2.year, date2.month,
           date2.day);
  } else {
    printf("The dates are the same.\n");
  }

  return 0;
}

#endif
