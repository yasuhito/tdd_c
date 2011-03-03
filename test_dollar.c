#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <google/cmockery.h>
#include "dollar.h"


static void
test_multiply() {
  Dollar *five = create_dollar( 5 );
  Dollar *product = multiply( five, 2 );
  Dollar *ten = create_dollar( 10 );
  assert_true( equal( product, ten ) );
  free( product );
  free( ten );

  product = multiply( five, 3 );
  assert_int_equal( 15, product->amount );
  free( product );

  free( five );
}


static void
test_equal() {
  Dollar *five_1 = create_dollar( 5 );
  Dollar *five_2 = create_dollar( 5 );
  Dollar *six = create_dollar( 6 );

  assert_true( equal( five_1, five_2 ) );
  assert_false( equal( five_1, six ) );

  free( five_1 );
  free( five_2 );
  free( six );
}


int
main() {
  const UnitTest tests[] = {
    unit_test( test_multiply ),
    unit_test( test_equal ),
  };
  return run_tests( tests );
}
