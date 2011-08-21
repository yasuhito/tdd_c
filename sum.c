#include <stdlib.h>
#include "sum.h"
#include "money.h"
#include "money_protected.h"
#include "bank.h"


static Money *
reduce_sum( const Expression *exp, Currency to ){
  Sum *sum = exp->value;
  Expression *augend_exp = ( Expression * ) sum->augend ;
  Expression *addend_exp = ( Expression * ) sum->addend;
  unsigned int augend = ( ( MoneyProtected * ) reduce ( augend_exp, to ) )->amount;
  unsigned int addend = ( ( MoneyProtected * ) reduce ( addend_exp, to ) )->amount;

  return create_money( augend + addend, to );
}


Expression *
create_sum( const Expression *augend, const Expression *addend ) {
  Sum *sum = malloc( sizeof( Sum ) );
  sum->augend = augend;
  sum->addend = addend;

  Expression *result = malloc( sizeof( Expression ) );
  result->value = sum;
  result->reduce = reduce_sum;

  return result;
}
