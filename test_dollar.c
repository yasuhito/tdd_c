#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <google/cmockery.h>
#include "bank.h"
#include "money.h"


static void
test_multiply_dollar_5x2() {
  Expression *five = dollar( 5 );
  Expression *product = multiply( five, 2 );
  Expression *ten = dollar( 10 );

  assert_true( equal( reduce( product, USD ), money_from( ten ) ) );

  free_expression( five );
  //free( product );
  free_expression( ten );
}


static void
test_multiply_dollar_5x3() {
  Expression *five = dollar( 5 );
  Expression *product = multiply( five, 3 );
  Expression *fifteen = dollar( 15 );

  assert_true( equal( reduce( product, USD ), money_from( fifteen ) ) );

  free_expression( five );
  //free( product );
  free_expression( fifteen );
}


static void
test_multiply_dollar_5x3x3() {
  Expression *five = dollar( 5 );
  Expression *product = multiply( multiply( five, 3 ), 3 );
  Expression *fortyfive = dollar( 45 );

  assert_true( equal( reduce( product, USD ), money_from( fortyfive ) ) );

  free_expression( five );
  //free( product );
  free_expression( fortyfive );
}


static void
test_equal() {
  Expression *five_dollar1 = dollar( 5 );
  Expression *five_dollar2 = dollar( 5 );
  Expression *six_dollar = dollar( 6 );
  Expression *five_franc = franc( 5 );

  assert_true( equal( money_from( five_dollar1 ), money_from( five_dollar2 ) ) );
  assert_false( equal( money_from( five_dollar1 ), money_from( six_dollar ) ) );
  assert_false( equal( money_from( five_dollar1 ), money_from( five_franc ) ) );

  free_expression( five_dollar1 );
  free_expression( five_dollar2 );
  free_expression( six_dollar );
  free_expression( five_franc );
}


static void
test_simple_addition() {
  Expression *five = dollar( 5 );
  Expression *addend_five = dollar( 5 );
  Expression *ten = dollar( 10 );

  Expression *sum = plus( five, addend_five );
  Money *reduced = reduce( sum, USD );
  assert_true( equal( money_from( ten ), reduced ) );

  free_expression( five );
  free_expression( addend_five );
  //free( sum );
  //free( reduced );
  free_expression( ten );
}


int
main() {
  const UnitTest tests[] = {
    unit_test( test_multiply_dollar_5x2 ),
    unit_test( test_multiply_dollar_5x3 ),
    unit_test( test_multiply_dollar_5x3x3 ),
    unit_test( test_equal ),
    unit_test( test_simple_addition ),
  };
  return run_tests( tests );
}


/*
 * Local variables:
 * c-basic-offset: 2
 * indent-tabs-mode: nil
 * End:
 */
