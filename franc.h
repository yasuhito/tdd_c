#ifndef MONEY_H
#define MONEY_H
#include "money.h"
#endif


typedef struct {
} Franc;


Franc *create_franc( unsigned int amount );
Franc *multiply_franc( const Franc *franc, unsigned int multiplier );
