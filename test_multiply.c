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
  assert_int_equal( 10, product->amount );
  free( product );

  product = multiply( five, 3 );
  assert_int_equal( 15, product->amount );
  free( product );

  free( five );
}


int
main() {
  const UnitTest tests[] = {
    unit_test( test_multiply ),
  };
  return run_tests( tests );
}
