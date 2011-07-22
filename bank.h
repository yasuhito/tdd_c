#ifndef BANK_H
#define BANK_H


#include "money.h"


Expression * reduce( Expression *source, Currency to );
unsigned int rate( Currency from, Currency to );
void add_rate( Currency from, Currency to, unsigned int rate );


#endif // BANK_H
