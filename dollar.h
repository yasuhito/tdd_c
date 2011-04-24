#include "money.h"


typedef struct {
} Dollar;


Dollar *create_dollar( unsigned int amount, Currency currency );
Money *multiply_dollar( const Dollar *dollar, unsigned int multiplier );
