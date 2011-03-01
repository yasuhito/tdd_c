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
equal( Dollar *dollar_1, void *dollar_2 ) { 
  return dollar_1->amount == ( ( Dollar * ) dollar_2 )->amount;
}
