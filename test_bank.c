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
  Expression *five = dollar( 5 );
  Expression *addend_five = dollar( 5 );

  Expression *result = plus( five, addend_five );
  Sum *sum = ( Sum * ) result->value;
  assert_true( equal( money_from( five ), money_from( sum->augend ) ) );
  assert_true( equal( money_from( addend_five ), money_from( sum->addend ) ) );

  free_expression( five );
  free_expression( addend_five );
  free_expression( result );
}


static void
test_reduce_sum() {
  Expression *three_usd = dollar( 3 );
  Expression *four_usd = dollar( 4 );
  Expression *seven_usd = dollar( 7 );

  Expression *exp = plus( three_usd, four_usd );
  Money *result = reduce( exp , USD );
  assert_true( equal( result , money_from( seven_usd ) ) );

  free_expression( three_usd );
  free_expression( four_usd );
  free_expression( seven_usd );
  free_expression( exp );
  free_money( result );
}


static void
test_reduce_different_currency() {
  Expression *two_franc = franc( 2 );
  Expression *one_dollar = dollar( 1 );

  add_rate( CHF, USD, 2 );
  Money *result = reduce( two_franc, USD );
  assert_true( equal( result, money_from( one_dollar ) ) );

  free_expression( two_franc );
  free_expression( one_dollar );
  free_money( result );
}


static void
test_mixed_addition() {
  Expression *five_bucks = dollar( 5 );
  Expression *ten_francs = franc( 10 );
  Expression *ten_usd = dollar( 10 );

  add_rate( CHF, USD, 2 );
  Expression *exp = plus( five_bucks, ten_francs );
  Money *result = reduce( exp, USD );
  assert_true( equal( money_from( ten_usd ), result ) );

  free_expression( five_bucks );
  free_expression( ten_francs );
  free_expression( ten_usd );
  free_expression( exp );
  free_money( result );
}


static void
test_multiple_addition() {
  Expression *five_bucks = dollar( 5 );
  Expression *ten_francs = franc( 10 );
  Expression *fifteen_bucks = dollar( 15 );

  add_rate( CHF, USD, 2 );
  Expression *exp1 = plus( five_bucks, ten_francs );
  Expression *exp2 = plus( exp1, five_bucks );
  Money *result = reduce( exp2, USD );
  assert_true( equal( money_from( fifteen_bucks ), result ) );

  free_expression( five_bucks );
  free_expression( ten_francs );
  free_expression( fifteen_bucks );
  free_expression( exp1 );
  free_expression( exp2 );
  free_money( result );
}


static void
test_addition_multiply() {
  Expression *five_bucks = dollar( 5 );
  Expression *ten_francs = franc( 10 );
  Expression *twenty_bucks = dollar( 20 );

  add_rate( CHF, USD, 2 );

  Expression *exp1 = plus( five_bucks, ten_francs );
  Expression *exp2 = multiply( exp1, 2 );
  Money *result = reduce( exp2, USD );
  assert_true( equal( money_from( twenty_bucks ), result ) );

  free_expression( five_bucks );
  free_expression( ten_francs );
  free_expression( twenty_bucks );
  free_expression( exp1 );
  free_expression( exp2 );
  free_money( result );
}


int
main() {
  const UnitTest tests[] = {
    unit_test( test_plus_returns_sum ),
    unit_test( test_reduce_sum ),
    unit_test( test_reduce_different_currency ),
    unit_test( test_mixed_addition ),
    unit_test( test_multiple_addition ),
    unit_test( test_addition_multiply ),
  };
  return run_tests( tests );
}


/*
 * Local variables:
 * c-basic-offset: 2
 * indent-tabs-mode: nil
 * End:
 */
