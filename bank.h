#ifndef BANK_H
#define BANK_H


#include "money.h"


Money *reduce( Expression *source, Currency to );
unsigned int rate( Currency from, Currency to );
void add_rate( Currency x, Currency y, unsigned int rate );


#endif // BANK_H
