#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <google/cmockery.h>
#include "bank.h"
#include "money.h"
#include "sum.h"


static void
test_plus_returns_sum() {
<<<<<<< HEAD
  Expression *five = ( Expression * ) dollar( 5 );
  Expression *addend_five = ( Expression * ) dollar( 5 );
=======
  Expression *five = dollar( 5 );
  Expression *addend_five = dollar( 5 );
>>>>>>> ab1085c90492617eb52d37994101a25139acba5b

  Expression *result = plus( five, addend_five );
  Sum *sum = ( Sum * ) result->value;
  assert_true( equal( five, sum->augend ) );
  assert_true( equal( addend_five, sum->addend ) );

  free( five );
  free( addend_five );
  free( result);
}


static void
test_reduce_sum() {
<<<<<<< HEAD
  Expression *three_usd = ( Expression * ) dollar( 3 );
  Expression *four_usd = ( Expression * ) dollar( 4 );
  Expression *seven_usd = ( Expression * ) dollar( 7 );

  Expression *exp = plus( three_usd, four_usd );
  Expression *result = ( Expression * ) reduce( exp , USD );
  assert_true( equal( result , seven_usd ) );
=======
  Expression *three_usd = dollar( 3 );
  Expression *four_usd = dollar( 4 );
  Expression *seven_usd = dollar( 7 );

  Expression *exp = plus( three_usd, four_usd );
  Expression *result = reduce( exp , USD );
  assert_true( equal( result, seven_usd ) );
>>>>>>> ab1085c90492617eb52d37994101a25139acba5b

  free( three_usd );
  free( four_usd );
  free( seven_usd );
  free( exp );
  free( result );
}


static void
test_reduce_different_currency() {
  Expression *two_franc = franc( 2 );
  Expression *one_dollar = dollar( 1 );

  add_rate( CHF, USD, 2 );
<<<<<<< HEAD
  Expression *exp_two_franc = expression_from ( two_franc );
  Money *result = reduce( exp_two_franc, USD );
=======
  Expression *result = reduce( two_franc, USD );
>>>>>>> ab1085c90492617eb52d37994101a25139acba5b
  assert_true( equal( result, one_dollar ) );

  free( two_franc );
  free( one_dollar );
  free( result );
}

static void
test_mixed_addition(){
<<<<<<< HEAD
  Expression *five_bucks = ( Expression * ) dollar( 5 );
  Expression *ten_francs = ( Expression * ) franc( 10 );
  Expression *ten_usd = ( Expression * ) dollar( 10 );

  add_rate( CHF, USD, 2 );
  Expression *result = ( Expression * ) reduce( plus( five_bucks, ten_francs ), USD );
=======
  Expression *five_bucks = dollar( 5 );
  Expression *ten_francs = franc( 10 );
  Expression *ten_usd = dollar( 10 );

  add_rate( CHF, USD, 2 );
  Expression *result = reduce( plus( five_bucks, ten_francs ), USD );
>>>>>>> ab1085c90492617eb52d37994101a25139acba5b
  assert_true( equal( ten_usd, result ) );

  free( five_bucks );
  free( ten_francs );
  free( ten_usd );
  free( result );
<<<<<<< HEAD
}

=======

}
>>>>>>> ab1085c90492617eb52d37994101a25139acba5b

int
main() {
  const UnitTest tests[] = {
    unit_test( test_plus_returns_sum ),
    unit_test( test_reduce_sum ),
    unit_test( test_reduce_different_currency ),
<<<<<<< HEAD
    unit_test( test_mixed_addition ), 
=======
    unit_test( test_mixed_addition ),
>>>>>>> ab1085c90492617eb52d37994101a25139acba5b
  };
  return run_tests( tests );
}
