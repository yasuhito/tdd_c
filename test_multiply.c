#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <google/cmockery.h>


static void
test_multiply() {
  Doller *five = create_doller( 5 );
  multiply( &five, 2 );
  assert_int_equal( 10, five->amount );
  free( five );
}


int
main() {
  const UnitTest tests[] = {
    unit_test( test_multiply ),
  };
  return run_tests( tests );
}
