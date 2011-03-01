typedef struct {
  unsigned int amount;
} Dollar;


Dollar *create_dollar( unsigned int amount );
bool equal( const Dollar *dollar_1, const void *dollar_2 );
Dollar *multiply( const Dollar *dollar, unsigned int multiplier );
