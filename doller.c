#include <stdlib.h>
#include "doller.h"


Doller *
create_doller( unsigned int amount ) {
  Doller *doller = malloc( sizeof( Doller ) );
  doller->amount = amount;
  return doller;
}


Doller *
multiply( const Doller *doller, unsigned int multiplier ) {
  return create_doller( doller->amount * multiplier );
}
