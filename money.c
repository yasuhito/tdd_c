#include "money.h"


bool
equal( const void *money, const void *other ) {
  return ( ( MoneyPrivate * ) money )->amount == ( ( MoneyPrivate * ) other )->amount;
}
