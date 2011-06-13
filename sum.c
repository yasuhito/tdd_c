#include <stdlib.h>
#include "sum.h"
#include "money.h"
#include "money_protected.h"

static Money *
sum_reduce(struct Expression *exp, Currency to){
  Sum *sum = exp->exp;
  int amount1, amount2, add_amount;
  amount1 = ( ( MoneyProtected * ) ( sum->augend ) )->amount;
  amount2 = ( ( MoneyProtected * ) ( sum->addend ) )->amount;
  add_amount = amount1 + amount2;
  return create_money( add_amount, to );
}

Expression *
create_sum( const Money *augend, const Money *addend) {
  Expression *result = ( Expression * ) malloc( sizeof ( Expression ) );
  Sum *sum = (Sum *) malloc ( sizeof ( Sum ) ) ;
  sum->augend = augend;
  sum->addend = addend;

  result->exp = sum;
  result->reduce = sum_reduce;

  return result;
}

