#include <stdbool.h>


typedef struct {
  unsigned int amount;
} Dollar;


Dollar *create_dollar( unsigned int amount );
bool equal( const Dollar *dollar, const void *other );
Dollar *multiply( const Dollar *dollar, unsigned int multiplier );
