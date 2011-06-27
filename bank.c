#include <assert.h>
#include <stdlib.h>
#include "bank.h"
#include "hash_table.h"
#include "money.h"
#include "pair.h"


static hash_table *rates = NULL;


Money *
reduce( Expression *source, Currency to ) {
  return source->reduce( source, to );
}


unsigned int
rate( Currency from, Currency to ) {
  if ( from == to ) {
    return 1;
  }
  Pair *pair = create_pair( from, to );
  void *rate = lookup_hash_entry( rates, pair );
  assert( rate != NULL );
  free( pair );
  return ( unsigned int ) rate;
}


void
add_rate( Currency from, Currency to, unsigned int rate ) {
  if ( rates == NULL ) {
    rates = create_hash( compare_pair, hash_pair );
  }
  insert_hash_entry( rates, create_pair( from, to ), ( void * ) rate );
}
