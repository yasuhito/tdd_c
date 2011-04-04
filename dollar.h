#include "money.h"


typedef struct {
} Dollar;


Dollar *create_dollar( unsigned int amount );
Dollar *multiply( const Dollar *dollar, unsigned int multiplier );
