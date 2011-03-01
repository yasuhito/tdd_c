#include <stdlib.h>
#include <stdbool.h>
#include "dollar.h"


Dollar *
create_dollar( unsigned int amount ) {
  Dollar *dollar = malloc( sizeof( Dollar ) );
  dollar->amount = amount;
  return dollar;
}


Dollar *
multiply( const Dollar *dollar, unsigned int multiplier ) {
  return create_dollar( dollar->amount * multiplier );
}


bool
equal( Doller *doller_1, Doller *doller_2 ) {
  return true;
}
