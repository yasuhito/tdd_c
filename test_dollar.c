#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <google/cmockery.h>
#include "dollar.h"


static void
test_multiply_5x2() {
  Dollar *five = create_dollar( 5 );
  Dollar *product = multiply( five, 2 );
  Dollar *ten = create_dollar( 10 );

  assert_true( equal( product, ten ) );

  free( five );
  free( product );
  free( ten );
}


static void
test_multiply_5x3() {
  Dollar *five = create_dollar( 5 );
  Dollar *product = multiply( five, 3 );
  Dollar *fifteen = create_dollar( 15 );

  assert_true( equal( product, fifteen ) );

  free( five );
  free( product );
  free( fifteen );
}


static void
test_equal() {
  Dollar *five1 = create_dollar( 5 );
  Dollar *five2 = create_dollar( 5 );
  Dollar *six = create_dollar( 6 );

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
