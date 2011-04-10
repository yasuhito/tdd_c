#include "money.h"


bool
equal( const void *money, CurrencyType money_type, const void *other, CurrencyType other_type ) {
  return ( ( ( MoneyPrivate * ) money )->amount == ( ( MoneyPrivate * ) other )->amount ) 
    && ( money_type == other_type );
}
