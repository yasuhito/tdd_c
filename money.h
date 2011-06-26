#ifndef MONEY_H
#define MONEY_H

#include <stdbool.h>

typedef struct {
} Money;

typedef enum {
  USD,
  CHF,
} Currency;

typedef struct Expression {
  void *exp;
  Money* ( *reduce )( struct Expression *exp, Currency to );
} Expression;

Money *franc( unsigned int amount );
Money *dollar( unsigned int amount );
Money *create_money( unsigned int amount, Currency currency );
Expression *expression_from( const Money *money );
Expression *plus( const Money *money, const Money *addend_money );
Money *multiply( Money *money, int multiplier );
Currency currency_of( const Money *money );
bool equal( const void *money, const void *other );


#endif // MONEY_H
