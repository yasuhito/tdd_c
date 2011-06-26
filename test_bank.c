#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <google/cmockery.h>
#include "bank.h"
#include "money.h"
#include "sum.h"


static void
test_plus_returns_sum() {
  Money *five = dollar( 5 );
  Money *addend_five = dollar( 5 );

  Expression *result = plus( five, addend_five );
  Sum *sum = ( Sum * ) result->value;
  assert_true( equal( five, sum->augend ) );
  assert_true( equal( addend_five, sum->addend ) );

  free( five );
  free( addend_five );
  free( result);
}


static void
test_reduce_sum() {
  Money *three_usd = dollar( 3 );
  Money *four_usd = dollar( 4 );
  Money *seven_usd = dollar( 7 );

  Expression *exp = plus( three_usd, four_usd );
  Money *result = reduce( exp , USD );
  assert_true( equal( result, seven_usd ) );

  free( three_usd );
  free( four_usd );
  free( seven_usd );
  free( exp );
  free( result );
}


static void
test_reduce_different_currency() {
  Money *two_franc = franc( 2 );
  Money *one_dollar = dollar( 1 );

  add_rate( CHF, USD, 2 );
  Expression *exp_two_franc = expression_from( two_franc );
  Money *result = reduce( exp_two_franc, USD );
  assert_true( equal( result, one_dollar ) );

  free( two_franc );
  free( one_dollar );
}


int
main() {
  const UnitTest tests[] = {
    unit_test( test_plus_returns_sum ),
    unit_test( test_reduce_sum ),
    unit_test( test_reduce_different_currency ),
  };
  return run_tests( tests );
}
