#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include "bank.h"
#include "money.h"
#include "money_protected.h"
#include "sum.h"


Expression *
franc( unsigned int amount ) {
  return expression_from ( create_money( amount, CHF ) );
}


Expression *
dollar( unsigned int amount ) {
  return expression_from ( create_money( amount, USD ) );
}


Money *
create_money( unsigned int amount, Currency currency ) {
  MoneyProtected *money = malloc( sizeof( MoneyProtected ) );
  money->amount = amount;
  money->currency = currency;
  return ( Money * ) money;
}


Expression *
plus( const Expression *money, const Expression *addend ) {
  return create_sum( money, addend );
}


Expression *
multiply( const Expression *money, unsigned int multiplier ) {
  MoneyProtected *moneyp = ( MoneyProtected * ) money;
  return ( Expression * ) create_money( moneyp->amount * multiplier, moneyp->currency );
}


Currency
currency_of( const Expression *money ) {
  return ( ( MoneyProtected * ) money )->currency;
}


bool
equal( const void *money, const void *other ) {
  MoneyProtected *moneyp = ( MoneyProtected * ) money;
  MoneyProtected *otherp = ( MoneyProtected * ) other;
  return moneyp->amount == otherp->amount && moneyp->currency == otherp->currency;
}


static Money *
reduce_money( const struct Expression *exp, Currency to ) {
  MoneyProtected *money = exp->value;
  return create_money( money->amount / rate( money->currency, to ), to );
}


Expression *
create_money_expression( Money *money ){
  Expression *result = malloc( sizeof( Expression ) );
  result->value = money;
  result->reduce = reduce_money;
  return result;
}


Expression *
expression_from( const Money *money ) {
  Expression *result = malloc( sizeof( Expression ) );
  result->value = ( void * ) money;
  result->reduce = reduce_money;
  return result;
}
