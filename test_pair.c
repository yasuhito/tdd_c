#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <google/cmockery.h>
#include "bank.h"
#include "pair.h"


static void
test_identity_rate() {
  assert_int_equal( 1, rate( USD, USD ) );
}


int
main() {
  const UnitTest tests[] = {
    unit_test( test_identity_rate ),
  };
  return run_tests( tests );
}


/*
 * Local variables:
 * c-basic-offset: 2
 * indent-tabs-mode: nil
 * End:
 */
