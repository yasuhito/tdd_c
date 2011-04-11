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

bool equal( const void *money, CurrencyType money_type, const void *other, CurrencyType other_type );

#endif
