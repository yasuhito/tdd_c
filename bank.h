#ifndef BANK_H
#define BANK_H


#include "money.h"


Money *reduce( Expression *source, Currency to );
int rate( Currency from, Currency to );
void add_rate( Currency x, Currency y, double rate );


#endif // BANK_H
