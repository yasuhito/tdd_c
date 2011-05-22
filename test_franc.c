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


static void
test_equal() {
  Money *five1 = franc( 5 );
  Money *five2 = franc( 5 );
  Money *six = franc( 6 );

  assert_true( equal( five1, five2 ) );
  assert_false( equal( five1, six ) );

  free( five1 );
  free( five2 );
  free( six );
}

static void 
test_different_class_equality() {
  Money *tenmoney = create_money(10, CHF);
  Franc *tenfranc = create_franc(10, CHF);
  assert_true( equal( tenmoney, tenfranc ) );
}

int
main() {
  const UnitTest tests[] = {
    unit_test( test_multiply_franc_5x2 ),
    unit_test( test_multiply_franc_5x3 ),
    unit_test( test_equal ),
    unit_test( test_different_class_equality)
  };
  return run_tests( tests );
}
