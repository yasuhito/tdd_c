#include "money.h"

typedef struct {
} Franc;


Franc *create_franc( unsigned int amount );
Franc *multiply( const Franc *franc, unsigned int multiplier );
