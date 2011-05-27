#ifndef MONEY_H
#define MONEY_H


#include <stdbool.h>


typedef struct {
} Money;


typedef enum {
  USD,
  CHF,
} Currency;


Money *franc( unsigned int amount );
Money *dollar( unsigned int amount );
Money *create_money( unsigned int amount, Currency currency );
Money *multiply( Money *money, int multiplier );
Currency currency_of( const Money *money );
bool equal( const void *money, const void *other );
Money *plus( Money *money, Money *addend_money );


#endif // MONEY_H
