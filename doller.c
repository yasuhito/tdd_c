#include <stdlib.h>
#include "doller.h"


Doller *
create_doller( unsigned int amount ) {
  Doller *doller = malloc( sizeof( Doller ) );
  doller->amount = 10;
  return doller;
}


void
multiply( Doller **doller, unsigned int multiplier ) {
}
