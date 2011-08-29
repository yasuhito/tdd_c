#include <stdlib.h>
#include "mul.h"
#include "money.h"
#include "money_protected.h"
#include "bank.h"


static Money *
reduce_mul( const Expression *exp, Currency to ){
  Mul *mul = exp->value;
  Expression *multiplicand_exp = ( Expression * ) mul->multiplicand ;
  MoneyProtected *reduced_multiplicand = ( MoneyProtected * ) reduce( multiplicand_exp, to ); 
  unsigned int multiplicand = reduced_multiplicand->amount;
  unsigned int multiplier = mul->multiplier;
  
  free_money( (Money * ) reduced_multiplicand );
  
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


/*
 * Local variables:
 * c-basic-offset: 2
 * indent-tabs-mode: nil
 * End:
 */
