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
Expression *franc( unsigned int amount );
Expression *dollar( unsigned int amount );
Money *create_money( unsigned int amount, Currency currency );

// Arithmetics
Expression *plus( const Expression *augend, const Expression *addend );
Expression *multiply( const Expression *multiplicand, unsigned int multiplier );

// Misc.
Currency currency_of( const Expression *money );
bool equal( const void *money, const void *other );
Expression *expression_from( const Money *money );
Money *money_from( const Expression *exp );


#endif // MONEY_H


/*
 * Local variables:
 * c-basic-offset: 2
 * indent-tabs-mode: nil
 * End:
 */
