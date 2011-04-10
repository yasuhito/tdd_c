#ifndef MONEY_H
#define MONEY_H
#include "money.h"
#endif


typedef struct {
} Dollar;


Dollar *create_dollar( unsigned int amount );
Dollar *multiply( const Dollar *dollar, unsigned int multiplier );
