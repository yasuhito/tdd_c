#include <stdlib.h>
#include "dollar.h"


Money *
multiply_dollar( const Dollar *dollar, unsigned int multiplier ) {
  return (Money *) create_dollar( ( ( MoneyPrivate * ) dollar )->amount * multiplier );
}
