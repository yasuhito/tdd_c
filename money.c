#include <stdlib.h>
#include <stddef.h>
#include <assert.h>
#include "dollar.h"
#include "franc.h"
#include "money.h"


Money *
create_dollar( unsigned int amount ) {
  MoneyPrivate *dollar = malloc( sizeof( MoneyPrivate ) );
  dollar->amount = amount;
  return ( Money * ) dollar;
}


Money *
create_franc( unsigned int amount ) {
  MoneyPrivate *franc = malloc( sizeof( MoneyPrivate ) );
  franc->amount = amount;
  return ( Money * ) franc;
}


Money *
multiply_money( Money * money, Currency currency, int multiplier ){
  switch( currency ){
    case USD:
      return multiply_dollar( ( Dollar * ) money, multiplier );
    case CHF:
      return multiply_franc( ( Franc * ) money, multiplier );
    default:
      // We should not reach here.
      assert( false );
  }
}


bool
equal( const void *money, Currency currency, const void *other, Currency other_currency ) {
  return ( ( ( MoneyPrivate * ) money )->amount == ( ( MoneyPrivate * ) other )->amount ) 
    && ( currency == other_currency );
}
