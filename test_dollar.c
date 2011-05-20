#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <google/cmockery.h>
#include "dollar.h"
#include "franc.h"


static void
test_multiply_dollar_5x2() {
  Money *five = dollar( 5 );
  Money *product = multiply( five, 2 );
  Money *ten = dollar( 10 );

  assert_true( equal( product, ten ) );

  free( five );
  free( product );
  free( ten );
}


static void
test_multiply_dollar_5x3() {
  Money *five = dollar( 5 );
  Money *product = multiply( five, 3 );
  Money *fifteen = dollar( 15 );

  assert_true( equal( product, fifteen ) );

  free( five );
  free( product );
  free( fifteen );
}


static void
test_equal() {
  Money *five_dollar1 = dollar( 5 );
  Money *five_dollar2 = dollar( 5 );
  Money *six_dollar = dollar( 6 );
  Franc *five_franc = ( Franc * ) franc( 5 );

  assert_true( equal( five_dollar1, five_dollar2 ) );
  assert_false( equal( five_dollar1, six_dollar ) );
  assert_false( equal( five_dollar1, five_franc ) );

  free( five_dollar1 );
  free( five_dollar2 );
  free( six_dollar );
  free( five_franc );
}


int
main() {
  const UnitTest tests[] = {
    unit_test( test_multiply_dollar_5x2 ),
    unit_test( test_multiply_dollar_5x3 ),
    unit_test( test_equal ),
  };
  return run_tests( tests );
}
