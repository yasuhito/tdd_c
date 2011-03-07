#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <google/cmockery.h>
#include "franc.h"


static void
test_multiply_5x2() {
  Franc *five = create_franc( 5 );
  Franc *product = multiply( five, 2 );
  Franc *ten = create_franc( 10 );

  assert_true( equal( product, ten ) );

  free( five );
  free( product );
  free( ten );
}


static void
test_multiply_5x3() {
  Franc *five = create_franc( 5 );
  Franc *product = multiply( five, 3 );
  Franc *fifteen = create_franc( 15 );

  assert_true( equal( product, fifteen ) );

  free( five );
  free( product );
  free( fifteen );
}


static void
test_equal() {
  Franc *five1 = create_franc( 5 );
  Franc *five2 = create_franc( 5 );
  Franc *six = create_franc( 6 );

  assert_true( equal( five1, five2 ) );
  assert_false( equal( five1, six ) );

  free( five1 );
  free( five2 );
  free( six );
}


int
main() {
  const UnitTest tests[] = {
    unit_test( test_multiply_5x2 ),
    unit_test( test_multiply_5x3 ),
    unit_test( test_equal ),
  };
  return run_tests( tests );
}
