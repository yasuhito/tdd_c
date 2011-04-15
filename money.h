#ifndef MONEY_H
#define MONEY_H


#include <stdbool.h>


typedef struct {
} Money;


typedef struct {
  unsigned int amount;
} MoneyPrivate;


typedef enum {
  USD,
  CHF,
} Currency;


bool equal( const void *money, Currency currency, const void *other, Currency other_currency );


#endif // MONEY_H
