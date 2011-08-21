#ifndef MUL_H
#define MUL_H


#include "money.h"


typedef struct {
  const Expression *multiplicand;
  unsigned int multiplier;
} Mul;


Expression *create_mul( const Expression *multiplicand, unsigned int multiplier );

#endif // MUL_H
