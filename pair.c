#include <stdlib.h>
#include "pair.h"


Pair *
create_pair( Currency from, Currency to ) {
  Pair *pair = malloc( sizeof( Pair ) );
  pair->from = from;
  pair->to = to;
  return pair;
}


unsigned int
hash_pair( const void *key ) {
  return 0;
}


bool
compare_pair( const void *x, const void *y ) {
  const Pair *px = x;
  const Pair *py = y;
  return px->from == py->from && px->to == py->to;
}


/*
 * Local variables:
 * c-basic-offset: 2
 * indent-tabs-mode: nil
 * End:
 */
