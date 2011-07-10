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

  assert_true( equal( product, ten ) );

  free( five );
  free( product );
  free( ten );
}


static void
test_multiply_dollar_5x3() {
  Expression *five = dollar( 5 );
  Expression *product = multiply( five, 3 );
  Expression *fifteen = dollar( 15 );

  assert_true( equal( product, fifteen ) );

  free( five );
  free( product );
  free( fifteen );
}


static void
test_equal() {
  Expression *five_dollar1 = dollar( 5 );
  Expression *five_dollar2 = dollar( 5 );
  Expression *six_dollar = dollar( 6 );
  Expression *five_franc = franc( 5 );

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
  Expression *reduced = reduce( sum, USD );
  assert_true( equal( ten, reduced ) );

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
    unit_test( test_equal ),
    unit_test( test_simple_addition ),
  };
  return run_tests( tests );
}
