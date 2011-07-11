#ifndef SUM_H
#define SUM_H


#include "money.h"


typedef struct {
  const Money *augend;
  const Money *addend;
} Sum;


Expression *create_sum( const Money *augend, const Money *addend );


#endif // SUM_H
