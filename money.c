#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include "money.h"
#include "money_private.h"


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
  MoneyPrivate *money = malloc( sizeof( MoneyPrivate ) );
  money->amount = amount;
  money->currency = currency;
  return ( Money * ) money;
}


Expression *
plus( const Money *money, const Money *addend_money ) {
  return ( Expression * ) create_money( ( ( MoneyPrivate * ) money )->amount + ( ( MoneyPrivate * ) addend_money )->amount, ( ( MoneyPrivate * ) money )->currency );
}


Money *
multiply( Money * money, int multiplier ) {
  return create_money( ( ( MoneyPrivate * ) money )->amount * multiplier, ( ( MoneyPrivate * ) money )->currency );
}


Currency
currency_of( const Money *money ) {
  return ( ( MoneyPrivate * ) money )->currency;
}


bool
equal( const void *money, const void *other ) {
  return ( ( ( MoneyPrivate * ) money )->amount == ( ( MoneyPrivate * ) other )->amount ) 
    && ( ( ( MoneyPrivate * ) money )->currency == ( ( MoneyPrivate * ) other )->currency );
}
