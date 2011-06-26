#include <stdlib.h>
#include "sum.h"
#include "money.h"
#include "money_protected.h"


static Money *
reduce_sum( const struct Expression *exp, Currency to ){
  Sum *sum = exp->value;
  unsigned int augend = ( ( MoneyProtected * ) sum->augend )->amount;
  unsigned int addend = ( ( MoneyProtected * ) sum->addend )->amount;
  return create_money( augend + addend, to );
}


Expression *
create_sum( const Money *augend, const Money *addend ) {
  Sum *sum = malloc( sizeof( Sum ) );
  sum->augend = augend;
  sum->addend = addend;

  Expression *result = malloc( sizeof( Expression ) );
  result->value = sum;
  result->reduce = reduce_sum;

  return result;
}
