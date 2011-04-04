#include <stdlib.h>
#include "franc.h"


Franc *
create_franc( unsigned int amount ) {
  MoneyPrivate *franc = malloc( sizeof( MoneyPrivate ) );
  franc->amount = amount;
  return ( Franc * ) franc;
}


Franc *
multiply( const Franc *franc, unsigned int multiplier ) {
  return create_franc( ( ( MoneyPrivate * ) franc )->amount * multiplier );
}
