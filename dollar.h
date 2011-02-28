typedef struct {
  unsigned int amount;
} Dollar;


Dollar *create_dollar( unsigned int amount );
Dollar *multiply( const Dollar *dollar, unsigned int multiplier );
