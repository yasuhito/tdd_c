#ifndef SUM_H_
#define SUM_H_

#include "money.h"

typedef struct {
  const Money *augend;
  const Money *addend;
} Sum;

Expression *create_sum( const Money *augend, const Money *addend);
#endif
