#include <stdlib.h>
#include "dollar.h"


Dollar *
create_dollar( unsigned int amount ) {
  MoneyPrivate *dollar = malloc( sizeof( MoneyPrivate ) );
  dollar->amount = amount;
  return ( Dollar * ) dollar;
}


Dollar *
multiply( const Dollar *dollar, unsigned int multiplier ) {
  return create_dollar( ( ( MoneyPrivate * ) dollar )->amount * multiplier );
}


bool
equal( const Dollar *dollar, const void *other ) {
  return ( ( MoneyPrivate * ) dollar )->amount == ( ( MoneyPrivate * ) other )->amount;
}
