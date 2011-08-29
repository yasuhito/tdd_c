#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <google/cmockery.h>
#include "money.h"


static void
test_currency() {
  Expression *one_usd = dollar( 1 );
  Expression *one_franc = franc( 1 );
  assert_int_equal( USD, currency_of( money_from( one_usd ) ) );
  assert_int_equal( CHF, currency_of( money_from( one_franc ) ) );
  free_expression( one_usd );
  free_expression( one_franc );
}


int
main() {
  const UnitTest tests[] = {
    unit_test( test_currency ),
  };
  return run_tests( tests );
}


/*
 * Local variables:
 * c-basic-offset: 2
 * indent-tabs-mode: nil
 * End:
 */
