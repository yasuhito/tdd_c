#include "bank.h"
#include "money.h"


Money *
reduce( Expression *source, Currency to ) {
  return source->reduce( source, to );
}


void
add_rate( Currency x, Currency y, double rate ) {
  // stub
}
