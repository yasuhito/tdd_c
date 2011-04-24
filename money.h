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


Money *create_dollar( unsigned int amount );
Money *create_franc( unsigned int amount );
Money * multiply_money( Money *money, Currency currency, int multiplier );
bool equal( const void *money, Currency currency, const void *other, Currency other_currency );


#endif // MONEY_H
