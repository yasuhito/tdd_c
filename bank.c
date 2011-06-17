#include "bank.h"
#include "money.h"

Money *
bank_reduce( Expression *source, Currency to ) {
  return source->reduce(source, to);
}


