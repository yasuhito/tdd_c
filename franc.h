#include "money.h"


typedef struct {
} Franc;


Franc *create_franc( unsigned int amount, Currency currency );
Money *multiply_franc( const Franc *franc, unsigned int multiplier );
