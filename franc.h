#include "money.h"


typedef struct {
} Franc;


Franc *create_franc( unsigned int amount );
Franc *multiply_franc( const Franc *franc, unsigned int multiplier );
