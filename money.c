#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include "money.h"
#include "money_protected.h"
#include "sum.h"


Money *
franc( unsigned int amount ) {
  return ( Money * ) create_money( amount, CHF );
}


Money *
dollar( unsigned int amount ) {
  return ( Money * ) create_money( amount, USD );
}


Money *
create_money( unsigned int amount, Currency currency ) {
  MoneyProtected *money = malloc( sizeof( MoneyProtected ) );
  money->amount = amount;
  money->currency = currency;
  return ( Money * ) money;
}


Expression *
plus( const Money *money, const Money *addend ) {
  return create_sum( money, addend );
}


Money *
multiply( const Money *money, unsigned int multiplier ) {
  MoneyProtected *moneyp = ( MoneyProtected * ) money;
  return create_money( moneyp->amount * multiplier, moneyp->currency );
}


Currency
currency_of( const Money *money ) {
  return ( ( MoneyProtected * ) money )->currency;
}


bool
equal( const void *money, const void *other ) {
  MoneyProtected *moneyp = ( MoneyProtected * ) money;
  MoneyProtected *otherp = ( MoneyProtected * ) other;
  return ( moneyp->amount == otherp->amount ) && ( moneyp->currency == otherp->currency );
}


static Money *
reduce_money( const struct Expression *exp, Currency to ) {
  MoneyProtected *money = exp->value;
  int rate = money->currency == CHF && to == USD ? 2 : 1;
  return create_money( money->amount / rate, to );
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
  Expression *result = ( Expression * ) malloc( sizeof( Expression ) );
  result->value = ( void * ) money;
  result->reduce = reduce_money;
  return result;
}
