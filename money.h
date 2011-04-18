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
  CHF
} CurrencyType;  

Money * multiply_money( Money *money, CurrencyType money_type, int multiplier);
Money *create_dollar( unsigned int amount );
Money *create_franc( unsigned int amount );
bool equal( const void *money, CurrencyType money_type, const void *other, CurrencyType other_type );

#endif
