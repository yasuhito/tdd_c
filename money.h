#ifndef MONEY_H
#define MONEY_H


#include <stdbool.h>


typedef struct {
  // NOTE: Protected members are defined in money_protected.h
} Money;

typedef enum {
  USD,
  CHF,
} Currency;

typedef struct Expression {
  void *value;
  Money * ( *reduce )( const struct Expression *exp, Currency to );
} Expression;


// Constructors
Money *franc( unsigned int amount );
Money *dollar( unsigned int amount );
Money *create_money( unsigned int amount, Currency currency );

// Arithmetics
Expression *plus( const Expression *money, const Expression *addend );
Expression *multiply( const Expression *money, unsigned int multiplier );

// Misc.
Currency currency_of( const Money *money );
bool equal( const void *money, const void *other );
Expression *expression_from( const Money *money );


#endif // MONEY_H
