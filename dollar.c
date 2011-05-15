#include <stdlib.h>
#include "dollar.h"
#include "money_private.h"


Dollar *
create_dollar( unsigned int amount, Currency currency ) {
  return ( Dollar * ) create_money( amount, currency );
}


