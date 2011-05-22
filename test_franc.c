#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <google/cmockery.h>
#include "franc.h"


static void
test_multiply_franc_5x2() {
  Money *five = franc( 5 );
  Money *product = multiply( five, 2 );
  Money *ten = franc( 10 );

  assert_true( equal( product, ten ) );

  free( five );
  free( product );
  free( ten );
}


static void
test_multiply_franc_5x3() {
  Money *five = franc( 5 );
  Money *product = multiply( five, 3 );
  Money *fifteen = franc( 15 );

  assert_true( equal( product, fifteen ) );

  free( five );
  free( product );
  free( fifteen );
}


int
main() {
  const UnitTest tests[] = {
    unit_test( test_multiply_franc_5x2 ),
    unit_test( test_multiply_franc_5x3 ),
  };
  return run_tests( tests );
}
