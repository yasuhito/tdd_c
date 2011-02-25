#include <stdlib.h>
#include "doller.h"


Doller *
create_doller( unsigned int amount ) {
  Doller *doller = malloc( sizeof( Doller ) );
  return doller;
}


void
multiply( Doller **doller, unsigned int multiplier ) {
  ( *doller )->amount = 5 * 2;
}
