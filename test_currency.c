#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <google/cmockery.h>
#include "money.h"


static void
test_currency() {
  assert_int_equal( USD, currency_of( money_from( dollar( 1 ) ) ) );
  assert_int_equal( CHF, currency_of( money_from( franc( 1 ) ) ) );
}


int
main() {
  const UnitTest tests[] = {
    unit_test( test_currency ),
  };
  return run_tests( tests );
}
