#include <stdlib.h>
#include "sum.h"
#include "money.h"
#include "money_protected.h"
#include "bank.h"

static Money *
reduce_sum( const struct Expression *exp, Currency to ){
  Sum *sum = exp->value;
<<<<<<< HEAD

  Expression *augend_exp = expression_from ( (Money * ) sum->augend );
  unsigned int augend = ( ( MoneyProtected * ) reduce ( augend_exp, to ) )->amount;
  Expression *addend_exp = expression_from ( (Money * ) sum->addend );
  unsigned int addend = ( ( MoneyProtected * ) reduce ( addend_exp, to ) )->amount;

  free( augend_exp );
  free( addend_exp );

=======
  //Expression *augend_exp = expression_from ( (Money * ) sum->augend );
  //Expression *augend_exp = sum->augend;
  unsigned int augend = ( ( MoneyProtected * ) reduce ( ( Expression * ) sum->augend, to ) )->amount;
  //Expression *addend_exp = expression_from ( (Money * ) sum->addend );
  //  Expression *addend_exp = sum->addend;
  unsigned int addend = ( ( MoneyProtected * ) reduce ( ( Expression * ) sum->addend, to )  )->amount;
  //  free( augend_exp );
  //  free( addend_exp );
>>>>>>> ab1085c90492617eb52d37994101a25139acba5b
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
