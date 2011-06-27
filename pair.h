#ifndef PAIR_H
#define PAIR_H


#include <stdbool.h>
#include "money.h"


typedef struct {
  Currency from;
  Currency to;
} Pair;


Pair * create_pair( Currency from, Currency to );
unsigned int hash_pair( const void *key );
bool compare_pair( const void *x, const void *y );


#endif // PAIR_H
