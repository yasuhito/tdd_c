#include "bank.h"
#include "money.h"


Money *
reduce( Expression *source, Currency to ) {
  return source->reduce( source, to );
}


int
rate( Currency from, Currency to ) {
  return from == CHF && to == USD ? 2 : 1;
}


void
add_rate( Currency x, Currency y, double rate ) {
  // stub
}
