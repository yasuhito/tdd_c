#include <stdlib.h>
#include "dollar.h"


Dollar *
create_dollar( unsigned int amount ) {
  DollarPrivate *dollar = malloc( sizeof( DollarPrivate ) );
  dollar->amount = amount;
  return ( Dollar * ) dollar;
}


Dollar *
multiply( const Dollar *dollar, unsigned int multiplier ) {
  return create_dollar( ( ( DollarPrivate * ) dollar )->amount * multiplier );
}


bool
equal( const Dollar *dollar, const void *other ) {
  return ( ( DollarPrivate * ) dollar )->amount == ( ( DollarPrivate * ) other )->amount;
}
