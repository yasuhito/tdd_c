#include <stdlib.h>
#include "dollar.h"
#include "money_private.h"


Dollar *
create_dollar( unsigned int amount, Currency currency ) {
  return ( Dollar * ) create_money( amount, currency );
}


Money *
multiply_dollar( const Dollar *_dollar, unsigned int multiplier ) {
  //  return dollar( ( ( MoneyPrivate * ) _dollar )->amount * multiplier );
  return ( Money * ) create_dollar( ( ( MoneyPrivate * ) _dollar )->amount * multiplier, USD);
}
