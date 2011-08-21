#include <stdlib.h>
#include "mul.h"
#include "money.h"
#include "money_protected.h"
#include "bank.h"


static Money *
reduce_mul( const Expression *exp, Currency to ){
  Mul *mul = exp->value;
  Expression *multiplicand_exp = ( Expression * ) mul->multiplicand ;
  unsigned int multiplicand = ( ( MoneyProtected * ) reduce ( multiplicand_exp, to ) )->amount;
  unsigned int multiplier  = mul->multiplier;

  return create_money( multiplicand * multiplier, to );
}


Expression *
create_mul( const Expression *multiplicand, unsigned int multiplier ) {
  Mul *mul = malloc( sizeof( Mul ) );
  mul->multiplicand = multiplicand;
  mul->multiplier = multiplier;

  Expression *result = malloc( sizeof( Expression ) );
  result->value = mul;
  result->reduce = reduce_mul;

  return result;
}
