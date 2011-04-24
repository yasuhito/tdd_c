#include <stdlib.h>
#include "franc.h"


Money *
multiply_franc( const Franc *franc, unsigned int multiplier ) {
  return ( Money * ) create_franc( ( ( MoneyPrivate * ) franc )->amount * multiplier );
}
