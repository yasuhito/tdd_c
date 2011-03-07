#include <stdlib.h>
#include "franc.h"


typedef struct {
  unsigned int amount;
} FrancPrivate;


Franc *
create_franc( unsigned int amount ) {
  FrancPrivate *franc = malloc( sizeof( FrancPrivate ) );
  franc->amount = amount;
  return ( Franc * ) franc;
}


Franc *
multiply( const Franc *franc, unsigned int multiplier ) {
  return create_franc( ( ( FrancPrivate * ) franc )->amount * multiplier );
}


bool
equal( const Franc *franc, const void *other ) {
  return ( ( FrancPrivate * ) franc )->amount == ( ( FrancPrivate * ) other )->amount;
}
