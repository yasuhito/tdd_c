#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
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


static Money *
reduce_money( struct Expression *exp, Currency to ) {
  MoneyProtected *money = exp->exp;
  int rate = money->currency == CHF && to == USD ? 2 : 1;
  return create_money( money->amount / rate, to );
}


Expression *
expression_from( const Money *money ) {
  Expression *result = ( Expression * ) malloc( sizeof( Expression ) );
  result->exp = ( void * ) money;
  result->reduce = reduce_money;
  return result;
}


Expression *
plus( const Money *money, const Money *addend_money ) {
  Expression *sum = create_sum( money, addend_money );
  return sum;
}

Money *
multiply( Money * money, int multiplier ) {
  return create_money( ( ( MoneyProtected * ) money )->amount * multiplier, ( ( MoneyProtected * ) money )->currency );
}


Currency
currency_of( const Money *money ) {
  return ( ( MoneyProtected * ) money )->currency;
}


bool
equal( const void *money, const void *other ) {
  return ( ( ( MoneyProtected * ) money )->amount == ( ( MoneyProtected * ) other )->amount ) 
    && ( ( ( MoneyProtected * ) money )->currency == ( ( MoneyProtected * ) other )->currency );
}


Expression *
create_money_expression( Money *money ){
  Expression *result;
  result = ( Expression * ) malloc( sizeof( Expression ) );
  result->exp = money;
  result->reduce = reduce_money;

  return result;
}
