#ifndef BANK_H_
#define BANK_H_


#include "money.h"


Money *bank_reduce( Expression *source, Currency to );
void add_rate( Currency x, Currency y, double rate );


#endif
