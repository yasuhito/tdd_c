#include "money.h"


bool
equal( const void *money, Currency currency, const void *other, Currency other_currency ) {
  return ( ( ( MoneyPrivate * ) money )->amount == ( ( MoneyPrivate * ) other )->amount ) 
    && ( currency == other_currency );
}
