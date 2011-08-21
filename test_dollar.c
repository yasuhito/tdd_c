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

  free( five );
  free( product );
  free( ten );
}


static void
test_multiply_dollar_5x3() {
  Expression *five = dollar( 5 );
  Expression *product = multiply( five, 3 );
  Expression *fifteen = dollar( 15 );

  assert_true( equal( reduce( product, USD ), money_from( fifteen ) ) );

  free( five );
  free( product );
  free( fifteen );
}


static void
test_multiple_multiply_dollar_5x3x3() {
  Expression *five = dollar( 5 );
  Expression *product = multiply( multiply( five, 3 ), 3 );
  Expression *fortyfive = dollar( 45 );

  assert_true( equal( reduce( product, USD ), money_from( fortyfive ) ) );

  free( five );
  free( product );
  free( fortyfive );
}


static void
test_equal() {
  Money *five_dollar1 = money_from( dollar( 5 ) );
  Money *five_dollar2 = money_from( dollar( 5 ) );
  Money *six_dollar = money_from( dollar( 6 ) );
  Money *five_franc = money_from( franc( 5 ) );

  assert_true( equal( five_dollar1, five_dollar2 ) );
  assert_false( equal( five_dollar1, six_dollar ) );
  assert_false( equal( five_dollar1, five_franc ) );

  free( five_dollar1 );
  free( five_dollar2 );
  free( six_dollar );
  free( five_franc );
}


static void
test_simple_addition() {
  Expression *five = dollar( 5 );
  Expression *addend_five = dollar( 5 );
  Expression *ten = dollar( 10 );

  Expression *sum = plus( five, addend_five );
  Money *reduced = reduce( sum, USD );
  assert_true( equal( money_from( ten ), reduced ) );

  free( five );
  free( addend_five );
  free( sum );
  free( reduced );
  free( ten );
}


int
main() {
  const UnitTest tests[] = {
    unit_test( test_multiply_dollar_5x2 ),
    unit_test( test_multiply_dollar_5x3 ),
    unit_test( test_multiple_multiply_dollar_5x3x3 ),
    unit_test( test_equal ),
    unit_test( test_simple_addition ),
  };
  return run_tests( tests );
}
