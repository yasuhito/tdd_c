#ifndef BANK_H
#define BANK_H


#include "money.h"


Money * reduce( Expression *source, Currency to );
unsigned int rate( Currency from, Currency to );
void add_rate( Currency from, Currency to, unsigned int rate );
void delete_all_rates();

#endif // BANK_H


/*
 * Local variables:
 * c-basic-offset: 2
 * indent-tabs-mode: nil
 * End:
 */
