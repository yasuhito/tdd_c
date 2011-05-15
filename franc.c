#include <stdlib.h>
#include "money.h"
#include "franc.h"
#include "money_private.h"



Franc *
create_franc( unsigned int amount, Currency currency ) {
  return ( Franc * ) create_money( amount, currency );
}

