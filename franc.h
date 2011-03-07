#include <stdbool.h>

typedef struct {
} Franc;


Franc *create_franc( unsigned int amount );
bool equal( const Franc *franc, const void *other );
Franc *multiply( const Franc *franc, unsigned int multiplier );
