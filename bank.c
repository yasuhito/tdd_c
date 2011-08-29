#include <assert.h>
#include <stdint.h>
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


static void
maybe_init_rates() {
  if ( rates == NULL ) {
    rates = create_hash( compare_pair, hash_pair );
  }
}


unsigned int
rate( Currency from, Currency to ) {
  maybe_init_rates();
  if ( from == to ) {
    return 1;
  }
  Pair *pair = create_pair( from, to );
  void *rate = lookup_hash_entry( rates, pair );
  assert( rate != NULL );
  free( pair );
  return ( unsigned int ) ( uintptr_t ) rate;
}


void
add_rate( Currency from, Currency to, unsigned int rate ) {
  maybe_init_rates();
  Pair *pair = create_pair( from, to );
  insert_hash_entry( rates, pair, ( void * ) ( uintptr_t ) rate );
}


void
delete_all_rates() {
  if ( rates != NULL ) {
    delete_hash(rates);
    rates = NULL;
  }
}

/*
 * Local variables:
 * c-basic-offset: 2
 * indent-tabs-mode: nil
 * End:
 */
